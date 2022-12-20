#include "MyForm.h"

using namespace Arshin; //name of your project

[STAThreadAttribute]
int main(array<System::String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    Application::Run(gcnew MyForm());
    return 0;
}


std::string Arshin::Utf8_to_cp1251(const std::string_view& str) {
    const auto countW = ::MultiByteToWideChar(CP_UTF8, 0, str.data(), str.size(), 0, 0);
    std::wstring UTF16(countW, L'\0'); ::MultiByteToWideChar(CP_UTF8, 0, str.data(), str.size(), UTF16.data(), UTF16.size());

    const auto countA = ::WideCharToMultiByte(1251, 0, UTF16.data(), UTF16.size(), 0, 0, 0, 0);
    std::string cp1251(countA, '\0'); ::WideCharToMultiByte(1251, 0, UTF16.data(), UTF16.size(), cp1251.data(), cp1251.size(), 0, 0);

    return cp1251;
}

void Arshin::HttpParsRequest(std::string& request_str, const std::string& connect_adr, const std::string& connect_site) {
	std::wstring _connect_site(connect_site.begin(), connect_site.end());
	LPCWSTR connect_site_request = _connect_site.c_str();
	std::wstring _connect_adr(connect_adr.begin(), connect_adr.end());
	LPCWSTR _connect_adr_request = _connect_adr.c_str();
	// инициализируем WinInet
	HINTERNET hInternet = ::InternetOpen(TEXT("Arshin request"), INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
	if (hInternet != NULL) {
		// открываем HTTP сессию
		HINTERNET hConnect = ::InternetConnect(hInternet, connect_site_request, INTERNET_DEFAULT_HTTP_PORT, NULL, NULL, INTERNET_SERVICE_HTTP, 0, 1u);
		if (hConnect != NULL) {
			// открываем запрос
			HINTERNET hRequest = ::HttpOpenRequest(hConnect, TEXT("GET"), _connect_adr_request, NULL, NULL, 0, INTERNET_FLAG_KEEP_CONNECTION, 1);
			if (hRequest != NULL) {
				// посылаем запрос
				BOOL bSend = ::HttpSendRequest(hRequest, NULL, 0, NULL, 0);
				if (bSend) {
					while (true) {
						// читаем данные
						char szData[1024];
						DWORD dwBytesRead;
						BOOL bRead = ::InternetReadFile(hRequest, szData, sizeof(szData) - 1, &dwBytesRead);
						// выход из цикла при ошибке или завершении
						if (bRead == FALSE || dwBytesRead == 0)
							break;
						// сохраняем результат
						szData[dwBytesRead] = 0;
						request_str += szData;
					}
				}
				// закрываем запрос
				::InternetCloseHandle(hRequest);
			}
			// закрываем сессию
			::InternetCloseHandle(hConnect);
		}
		// закрываем WinInet
		::InternetCloseHandle(hInternet);
	}
}

System::Void Arshin::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	//очистка
	label13->Text = "Найдено записей:";
	listBox1->Items->Clear();
	vResponsesClear();
	button1->Enabled = false;
	button2->Enabled = false;
	//извлечение полей формы
	verification_year = comboBox1->SelectedItem->ToString();
	org_title = textBox2->Text->Trim()->ToString();
	mitnumber = textBox3->Text->Trim()->ToString();
	mititle = textBox4->Text->Trim()->ToString();
	mitype = textBox5->Text->Trim()->ToString();
	modification = textBox6->Text->Trim()->ToString();
	znumber = textBox7->Text->Trim()->ToString();
	result_docnum = textBox8->Text->Trim()->ToString();
	if (dateTimePicker1->CustomFormat == " ")
		verification_date1 = "";
	else
		verification_date1 = dateTimePicker1->Value.Date.ToString("yyyy-MM-dd");
	if (dateTimePicker2->CustomFormat == " ")
		verification_date2 = "";
	else
		verification_date2 = dateTimePicker2->Value.Date.ToString("yyyy-MM-dd");
	if (dateTimePicker3->CustomFormat == " ")
		valid_date1 = "";
	else
		valid_date1 = dateTimePicker3->Value.Date.ToString("yyyy-MM-dd");
	if (dateTimePicker4->CustomFormat == " ")
		valid_date2 = "";
	else
		valid_date2 = dateTimePicker4->Value.Date.ToString("yyyy-MM-dd");
	//подготовка строки запроса
	String^ select = "/fundmetrology/cm/xcdb/vri/select?fq=verification_year:";
	if (verification_year != "")
		select += verification_year;
	//не стандартное добавление организации-поверителя: поиск пробелов, добавление косых черт
	if (org_title != "") {
		std::string org_title_str = msclr::interop::marshal_as<std::string>(textBox2->Text->Trim()->ToString());
		size_t itf = 0;
		size_t its = 0;
		std::string tmp_str = "";
		if (org_title_str.find(' ', itf) != std::string::npos) {
			while (org_title_str.find(' ', itf) != std::string::npos) {
				its = org_title_str.find(' ', itf);
				tmp_str += "&fq=org_title:*" + backslash_add(org_title_str.substr(itf, its - itf)) + "*";
				itf = its + 1;
			}
			tmp_str += "&fq=org_title:*" + backslash_add(org_title_str.substr(itf, org_title_str.length() - itf)) + "*";
		}
		else
			tmp_str = "&fq=org_title:*" + backslash_add(org_title_str) + "*";
		select += msclr::interop::marshal_as<String^>(tmp_str);
	}
	if (mitnumber != "")
		select += "&fq=mi.mitnumber:*" + mitnumber + "*";
	if (mititle != "")
		select += "&fq=mi.mititle:*" + mititle + "*";
	if (mitype != "")
		select += "&fq=mi.mitype:*" + mitype + "*";
	if (modification != "")
		select += "&fq=mi.modification:*" + modification + "*";
	if (znumber != "")
		select += "&fq=mi.number:*" + znumber + "*";
	if (result_docnum != "")
		select += "&fq=result_docnum:*" + result_docnum + "*";
	if (verification_date1 != "") {
		select += "&fq=verification_date:[" + verification_date1 + "T00:00:00Z";
		if (verification_date2 != "")
			select += " TO " + verification_date2 + "T23:59:59Z]";
		else
			select += "]";
	}
	if (valid_date1 != "") {
		select += "&fq=valid_date:[" + valid_date1 + "T00:00:00Z";
		if (valid_date2 != "")
			select += " TO " + valid_date2 + "T23:59:59Z]";
		else
			select += "]";
	}
	select += "&q=*&fl=vri_id,org_title,mi.mitnumber,mi.mititle,mi.mitype,mi.modification,mi.number,verification_date,valid_date,applicability,result_docnum&sort=verification_date+desc,org_title+asc&rows=20&start=0";
	std::string adr_site = msclr::interop::marshal_as<std::string>(select);
	std::string str; //строка для ответа
	HttpParsRequest(str, adr_site);
	str = Utf8_to_cp1251(str);

	//количество найденных записей по фильтру
	std::string numFound = " Что-то пошло не так... Возможно не достаточно параметров для поиска.";
	if (!str.empty()) {
		size_t it_fst = str.find("numFound", 0);
		if (it_fst != std::string::npos) {
			it_fst += 10;
			size_t it_end = str.find(",", it_fst);
			if (it_end != std::string::npos)
				numFound = str.substr(it_fst, (it_end - it_fst));
		}
	}
	else
		numFound = " Сервис не доступен...";
	label13->Text += msclr::interop::marshal_as<String^>(numFound);
    //регулярка для вывода 11 разных участков повторяющегося фрагмента
	//ДЛЯ СВД     00:00:00Z\"     00:00:00Z
	std::regex rgx("\"mi.mitnumber\":\"(.*?)\",\\n        \"mi.modification\":\"(.*?)\",\\n        \"mi.number\":\"(.*?)\",\\n        \"valid_date\":\"(.*?)T..:00:00Z\",\\n\
        \"result_docnum\":\"(.*?)\",\\n        \"mi.mitype\":\"(.*?)\",\\n        \"mi.mititle\":\"(.*?)\",\\n        \"org_title\":\"(.*?)\",\\n        \"applicability\":(.*?),\\n\
        \"vri_id\":\"(.*?)\",\\n        \"verification_date\":\"(.*?)T..:00:00Z");
	//итераторы по строке
	std::regex_iterator<std::string::iterator> it_begin(str.begin(), str.end(), rgx); //начальный итератор
	std::regex_iterator<std::string::iterator> it_end;                                //конечный итератор
	std::string for_resp = " Что-то пошло не так...";					 //строка для ответа в листбокс
	size_t num = 1;
	while (it_begin != it_end) {
		std::smatch m;
		std::string ss = it_begin->str();
		std::regex_search(ss, m, rgx);    //запрос-поиск по шаблону rgx, кидается в m[]
		//удаляем лишние обратные слешы из модификации и типа
		std::string str_modific = (std::string)m[2];
		backslash_del(str_modific);
		std::string str_type = (std::string)m[6];
		backslash_del(str_type);
		std::string str_orgtitle = (std::string)m[8];
		backslash_del(str_orgtitle);
		//буферный вектор для дальнейшей работы
		Response* resp = new Response();
		resp->_result->setResult((std::string)m[1], str_modific, (std::string)m[3], (std::string)m[4], (std::string)m[5],
			str_type, (std::string)m[7], str_orgtitle, (std::string)m[9], (std::string)m[10], (std::string)m[11]);
		//добавляем начально заполненный экземпляр в вектор
		vResponses.push_back(resp);
		//строка на вывод в листбокс
		for_resp = std::to_string(num) + ". " + (std::string)m[7] + ", " + str_modific + ", ГР: " + (std::string)m[1] + ", тип: " +
			str_type + ", зав. № " + (std::string)m[3] + ", дата поверки: " + (std::string)m[11] + ", годно до: " + (std::string)m[4] +
			", СВД: " + (std::string)m[5] + ", " + str_orgtitle;
		listBox1->Items->Add(msclr::interop::marshal_as<String^>(for_resp));
		for_resp.clear();
		++it_begin;
		++num;
	}
	//ДЛЯ ИЗВ о непригодности (в строке нет valid_date)
	std::regex rgx_izv("\"mi.mitnumber\":\"(.*?)\",\\n        \"mi.modification\":\"(.*?)\",\\n        \"mi.number\":\"(.*?)\",\\n\
        \"result_docnum\":\"(.*?)\",\\n        \"mi.mitype\":\"(.*?)\",\\n        \"mi.mititle\":\"(.*?)\",\\n        \"org_title\":\"(.*?)\",\\n        \"applicability\":(.*?),\\n\
        \"vri_id\":\"(.*?)\",\\n        \"verification_date\":\"(.*?)T..:00:00Z");
	std::regex_iterator<std::string::iterator> it_begin2(str.begin(), str.end(), rgx_izv);
	std::regex_iterator<std::string::iterator> it_end2;
	while (it_begin2 != it_end2) {
		std::smatch m;
		std::string ss = it_begin2->str();
		std::regex_search(ss, m, rgx_izv);
		//
		std::string str_modific = (std::string)m[2];
		backslash_del(str_modific);
		std::string str_type = (std::string)m[5];
		backslash_del(str_type);
		std::string str_orgtitle = (std::string)m[7];
		backslash_del(str_orgtitle);
		//
		Response* resp = new Response();
		resp->_result->setResult((std::string)m[1], (std::string)m[2], (std::string)m[3], "0000-00-00", (std::string)m[4], (std::string)m[5],
			(std::string)m[6], (std::string)m[7], (std::string)m[8], (std::string)m[9], (std::string)m[10]);
		vResponses.push_back(resp);
		for_resp = std::to_string(num) + ". " + (std::string)m[6] + ", " + str_modific + ", ГР: " + (std::string)m[1] + ", тип: " +
			str_type + ", зав. № " + (std::string)m[3] + ", дата поверки: " + (std::string)m[10] +
			", ИЗВ: " + (std::string)m[4] + ", " + str_orgtitle;
		listBox1->Items->Add(msclr::interop::marshal_as<String^>(for_resp));
		for_resp.clear();
		++it_begin2;
		++num;
	}
	button1->Enabled = true;
	button2->Enabled = true;
	//вывод листбокса и прячем панель фильтра поиска
	panel1_filterSI->Visible = false;
	panel2_responses->Visible = true;
    return System::Void();
}

//кнопка очистить фильтр
System::Void Arshin::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	comboBox1->SelectedIndex = 0;
	textBox2->Text = "";
	textBox3->Text = "";
	textBox4->Text = "";
	textBox5->Text = "";
	textBox6->Text = "";
	textBox7->Text = "";
	textBox8->Text = "";
	dateTimePicker1->CustomFormat = " ";
	dateTimePicker2->CustomFormat = " ";
	dateTimePicker3->CustomFormat = " ";
	dateTimePicker4->CustomFormat = " ";
	comboBox1->SelectedIndex = 0;
	//очистка
	label13->Text = "Найдено записей:";
	listBox1->Items->Clear();
	vResponsesClear();
	return System::Void();
}

//кнопка отмены на панели2 - прячем список найденного и возврат на панель фильтра
System::Void Arshin::MyForm::button3_Click(System::Object^ sender, System::EventArgs^ e) {
	//очистка
	label13->Text = "Найдено записей:";
	listBox1->Items->Clear();
	vResponsesClear();
	panel1_filterSI->Visible = true;
	panel2_responses->Visible = false;
	return System::Void();
}

//клик по строке из найденных
System::Void Arshin::MyForm::listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (listBox1->SelectedIndex != -1) {
		int vri_id = listBox1->SelectedIndex;
		//вывод предварительных общих сведений на panel3_viewer
		linkLabel1->Text = msclr::interop::marshal_as<String^>(vResponses[vri_id]->_result->get_mitnumber()); //ГР
		textBox9->Text = msclr::interop::marshal_as<String^>(vResponses[vri_id]->_result->get_mitype());    //тип
		textBox10->Text = msclr::interop::marshal_as<String^>(vResponses[vri_id]->_result->get_mititle());   //имя
		textBox11->Text = msclr::interop::marshal_as<String^>(vResponses[vri_id]->_result->get_number());    //номер
		textBox12->Text = msclr::interop::marshal_as<String^>(vResponses[vri_id]->_result->get_modification()); //модификация
		textBox14->Text = msclr::interop::marshal_as<String^>(vResponses[vri_id]->_result->get_verification_date()); //дата поверки
		//годно до
		if (vResponses[vri_id]->_result->get_applicability_bool()) {
			textBox15->Text = msclr::interop::marshal_as<String^>(vResponses[vri_id]->_result->get_valid_date()); 
			textBox15->Visible = true;
			label23->Visible = true;
			print_form->setIzvVisible(true);
		}
		else {
			label23->Visible = false;
			textBox15->Visible = false;
			print_form->setIzvVisible(false);
		}
		textBox17->Text = msclr::interop::marshal_as<String^>(vResponses[vri_id]->_result->get_applicability()); //годно?
		textBox18->Text = msclr::interop::marshal_as<String^>(vResponses[vri_id]->_result->get_result_docnum()); //номер свидетельства

		//вывод предварительных общих сведений на print_form для печати
		//(скрытно копируем заполненные текстбоксы)
		//номер свидетельства или извещения
		if (textBox17->Text == "Да")
			print_form->setIzvOrSvd("СВИДЕТЕЛЬСТВО О ПОВЕРКЕ № " + textBox18->Text);
		else
			print_form->setIzvOrSvd("ИЗВЕЩЕНИЕ О НЕПРИГОДНОСТИ № " + textBox18->Text);
		print_form->setVrfDate(textBox14->Text); //дата поверки
		print_form->setValidDate(textBox15->Text + " г."); // действительно до
		//Наименование, тип, модификация, ГР
		print_form->setSI(textBox10->Text + ", тип " + textBox9->Text + ", модификация " + textBox12->Text + ", госреестр № " + linkLabel1->Text);
		//Заводской номер
		print_form->setZNum(textBox11->Text);

		//запрос полных сведений по конкретному СИ
		//(если это СИ ещё не выбиралось и в векторе дополнительные данные пустые)
		if (vResponses[vri_id]->_mitypeURL == "") {
			std::string adr_site = vResponses[vri_id]->_result->get_vri_id(); //соответствующий vri_id
			adr_site = "/fundmetrology/cm/iaux/vri/" + adr_site;
			std::string str; //строка для ответа
			HttpParsRequest(str, adr_site);
			str = Utf8_to_cp1251(str);

			if (!str.empty()) {
				//mitypeURL
				size_t it_fst = 0;
				bv_it = 0;
				vResponses[vri_id]->_mitypeURL = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
				//ЭТАЛОН
				it_fst = 0;
				if (str.find("etaMI", it_fst) != std::string::npos) {
					vResponses[vri_id]->_eta = new Eta();
					//_eta->_regNumber
					++bv_it;
					vResponses[vri_id]->_eta->_regNumber = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
					//_eta->_manufactureYear
					++bv_it;
					vResponses[vri_id]->_eta->_manufactureYear = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
					//_eta->_rankCode
					++bv_it;
					vResponses[vri_id]->_eta->_rankCode = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
					//_eta->_rankTitle
					++bv_it;
					vResponses[vri_id]->_eta->_rankTitle = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
					//_eta->_schemaTitle
					++bv_it;
					vResponses[vri_id]->_eta->_schemaTitle = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
				}
				//vri_info
				//_vri_info->_organization      полное название организации-поверителя
				bv_it = 6;
				vResponses[vri_id]->_vri_info->_organization = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
				backslash_del(vResponses[vri_id]->_vri_info->_organization); //удалятель обратной косой черты
				//_vri_info->_signCipher 7
				++bv_it;
				vResponses[vri_id]->_vri_info->_signCipher = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
				//_vri_info->_miOwner 8
				++bv_it;
				vResponses[vri_id]->_vri_info->_miOwner = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
				backslash_del(vResponses[vri_id]->_vri_info->_miOwner); //удалятель обратной косой черты
				//_vri_info->_docTitle 9
				++bv_it;
				vResponses[vri_id]->_vri_info->_docTitle = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
				//_vri_info->_vriType 10
				if (str.find("vriType", it_fst) != std::string::npos) {
					++bv_it;
					vResponses[vri_id]->_vri_info->_vriType = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
				}
				//_vri_info->_applic->_certNum 11
				bv_it = 11;
				vResponses[vri_id]->_vri_info->_applic->_certNum = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
				//_vri_info->_applic->_stickerNum   12   может быть, а может и не быть
				if (str.find("stickerNum", it_fst) != std::string::npos) {
					bv_it = 12;
					vResponses[vri_id]->_vri_info->_applic->_stickerNum = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
				}
				//_vri_info->_applic->_signPass 13
				bv_it = 13;
				if ("true" == pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst))
					vResponses[vri_id]->_vri_info->_applic->_signPass = true;
				else
					vResponses[vri_id]->_vri_info->_applic->_signPass = false;
				//_vri_info->_applic->_signMi 14
				bv_it = 14;
				if ("true" == pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst))
					vResponses[vri_id]->_vri_info->_applic->_signMi = true;
				else
					vResponses[vri_id]->_vri_info->_applic->_signMi = false;
				
				//means npe vector
				if (str.find("\"npe\":", 0) != std::string::npos) {
					it_fst = str.find("\"npe\":", 0);
					while (str.find(_border_values[17].first, it_fst) != std::string::npos) {
						bv_it = 15;
						MeansBase_mis* mb = new MeansBase_mis();
						mb->_number = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
						++bv_it;
						mb->_title = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
						++bv_it;
						mb->_url = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
						vResponses[vri_id]->_means->_npe.push_back(mb);
						bv_it = 15;
					}
				}
				//means uve vector
				if (str.find("\"uve\":", 0) != std::string::npos) {
					it_fst = str.find("\"uve\":", 0);
					while (str.find(_border_values[18].first, it_fst) != std::string::npos) {
						bv_it = 15;
						MeansBase_mis* mb = new MeansBase_mis();
						mb->_number = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
						++bv_it;
						mb->_title = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
						bv_it = 18;
						mb->_url = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
						vResponses[vri_id]->_means->_uve.push_back(mb);
					}
				}
				//means mis vector
				if (str.find("\"mis\":", 0) != std::string::npos) {
					it_fst = str.find("\"mis\":", 0);
					bv_it = 19;
					while (str.find(_border_values[bv_it].first, it_fst) != std::string::npos) {
						MeansBase_mis* mb = new MeansBase_mis();
						mb->_mitypeNumber = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
						bv_it = 22;
						mb->_title = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
						bv_it = 20;
						mb->_url = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
						bv_it = 15;
						mb->_number = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
						vResponses[vri_id]->_means->_mis.push_back(mb);
						bv_it = 19;
					}
				}
				//means ses vector
				if (str.find("\"ses\":", 0) != std::string::npos) {
					it_fst = str.find("\"ses\":", 0);
					while (str.find(_border_values[33].first, it_fst) != std::string::npos) {
						bv_it = 15;
						MeansBase_ses* mb = new MeansBase_ses();
						mb->_number = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
						++bv_it;
						mb->_title = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
						bv_it = 33;
						mb->_url = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
						bv_it = 2;
						mb->_manufactureYear = pars_str(str, _border_values[bv_it].first, "}", it_fst);
						vResponses[vri_id]->_means->_ses.push_back(mb);
					}
				}
				//means mieta vector
				if (str.find("\"mieta\":", 0) != std::string::npos) {
					it_fst = str.find("\"mieta\":", 0);
					bv_it = 1;
					while (str.find(_border_values[bv_it].first, it_fst) != std::string::npos) {
						Mieta* mi = new Mieta();
						mi->_regNumber = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
						bv_it = 21;
						mi->_mieta_url = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
						bv_it = 19;
						mi->_mitypeNumber = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
						bv_it = 20;
						mi->_mitypeURL = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
						bv_it = 22;
						mi->_mitypeTitle = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
						bv_it = 23;
						mi->_notation = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
						bv_it = 24;
						mi->_modification = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
						bv_it = 25;
						mi->_manufactureNum = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
						bv_it = 2;
						mi->_manufactureYear = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
						bv_it = 3;
						mi->_rankCode = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
						bv_it = 4;
						mi->_rankTitle = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
						bv_it = 5;
						mi->_schemaTitle = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
						vResponses[vri_id]->_means->_mieta.push_back(mi);
						bv_it = 1;
					}
				}
				//means reagent vector
				if (str.find("\"reagent\":", 0) != std::string::npos) {
					it_fst = str.find("\"reagent\":", 0);
					while (str.find(_border_values[34].first, it_fst) != std::string::npos) {
						bv_it = 15;
						Reagent* rgnt = new Reagent();
						rgnt->_number = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
						bv_it = 34;
						rgnt->_type = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
						bv_it = 16;
						rgnt->_title = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
						vResponses[vri_id]->_means->_reagents.push_back(rgnt);
					}
				}
				//_over_info->_structure каждый элемент может быть, а может и не быть
				if (str.find("structure", it_fst) != std::string::npos) {
					bv_it = 26;
					vResponses[vri_id]->_over_info->_structure = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
				}
				//_over_info->_briefIndicator
				bv_it = 27;
				if ("true" == pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst))
					vResponses[vri_id]->_over_info->_briefIndicator = true;
				else
					vResponses[vri_id]->_over_info->_briefIndicator = false;
				//_over_info->_briefCharacteristics должен быть когда поверка в сокращенном объёме 
				bv_it = 28;
				vResponses[vri_id]->_over_info->_briefCharacteristics = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
				//_over_info->_additional_info
				bv_it = 32;
				vResponses[vri_id]->_over_info->_additional_info = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
				//protocol
				size_t prot = str.find("protocol\":", 0);
				if (prot != std::string::npos) {
					vResponses[vri_id]->_over_info->_prt = new Protocol();
					bv_it = 16;
					it_fst = prot;
					vResponses[vri_id]->_over_info->_prt->_title = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
					bv_it = 29;
					vResponses[vri_id]->_over_info->_prt->_mimetype = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
					++bv_it;
					vResponses[vri_id]->_over_info->_prt->_filename = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
					++bv_it;
					vResponses[vri_id]->_over_info->_prt->_doc_id = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, it_fst);
				}
			}
			//конец парса str
			//textBox9->Text = msclr::interop::marshal_as<String^>(str);
		}

		//ВЫВОД на panel3_viewer и print_form
		//организация-поверитель полное название
		textBox13->Text = msclr::interop::marshal_as<String^>(vResponses[vri_id]->_vri_info->_organization);
		print_form->setOrg(textBox13->Text);
		//методика поверки
		textBox16->Text = msclr::interop::marshal_as<String^>(vResponses[vri_id]->_vri_info->_docTitle);
		print_form->setDocTitle(textBox16->Text);
		//знак поверки в паспорте
		textBox19->Text = msclr::interop::marshal_as<String^>(vResponses[vri_id]->_vri_info->get_signPass());
		//знак поверки на СИ
		textBox20->Text = msclr::interop::marshal_as<String^>(vResponses[vri_id]->_vri_info->get_signMi());
		//гиперссылка на ГР
		LinkLabel::Link^ data1 = gcnew LinkLabel::Link();
		data1->LinkData = msclr::interop::marshal_as<String^>(vResponses[vri_id]->_mitypeURL);
		linkLabel1->Links->Add(data1);
		//гиперссылка на адрес свидетельства в ФИФ ОЕИ
		LinkLabel::Link^ data2 = gcnew LinkLabel::Link();
		String^ vri_id_str = msclr::interop::marshal_as<String^>(vResponses[vri_id]->_result->get_vri_id());
		data2->LinkData = "https://fgis.gost.ru/fundmetrology/cm/results/" + vri_id_str;
		linkLabel2->Links->Add(data2);
		linkLabel2->Text = vri_id_str;
		print_form->setVriURL(data2->LinkData->ToString());

		//Листбокс со средствами поверки

		//Государственные первичные эталоны
		if (!vResponses[vri_id]->_means->_npe.empty()) {
			String^ lbl_npe = L"Государственные первичные эталоны:";
			_lb1->Items->Add(lbl_npe);
			std::string tmp;//для _lb1
			std::string tmp2 = "";//для print_form
			for (const auto &it : vResponses[vri_id]->_means->_npe) {
				tmp2 += it->_number + ", ";
				tmp = it->_number + ", " + it->_title;
				_lb1->Items->Add(msclr::interop::marshal_as<String^>(tmp));
			}
			tmp2.erase(tmp2.size() - 2);
			print_form->setEtalons(msclr::interop::marshal_as<String^>(tmp2));
			_lb1->Items->Add("");//пробел
			//через событие клик по строке прикрутить переход по гиперссылке, которая в it->_url
			//пока не знаю как
		}
		//Эталоны единицы величины
		if (!vResponses[vri_id]->_means->_uve.empty()) {
			String^ lbl_uve = L"Эталоны единицы величины:";
			_lb1->Items->Add(lbl_uve);
			std::string tmp;
			std::string tmp2 = "";//для print_form
			if (_lb1->Items->Count > 1) tmp2 = ", ";
			for (const auto &it : vResponses[vri_id]->_means->_uve) {
				tmp2 += it->_number + ", ";
				tmp = it->_number + ", " + it->_title;
				_lb1->Items->Add(msclr::interop::marshal_as<String^>(tmp));
			}
			tmp2.erase(tmp2.size() - 2);
			print_form->setEtalons(msclr::interop::marshal_as<String^>(tmp2));
			_lb1->Items->Add("");//пробел
		}
		//Средства измерений, применяемые в качестве эталона
		if (!vResponses[vri_id]->_means->_mieta.empty()) {
			String^ lbl_mieta = L"Средства измерений, применяемые в качестве эталона:";
			_lb1->Items->Add(lbl_mieta);
			std::string tmp;
			std::string tmp2 = "";//для print_form
			if (_lb1->Items->Count > 1) tmp2 = ", ";
			for (const auto &it : vResponses[vri_id]->_means->_mieta) {
				tmp2 += it->_regNumber + ", ";
				tmp = it->_regNumber + ", " + it->_mitypeNumber + ", " + it->_mitypeTitle + ", " + it->_mitypeNumber + ", " + it->_notation + ", " + it->_modification + ", "
					+ it->_manufactureNum + ", " + it->_manufactureYear + ", " + it->_rankCode + ", " + it->_rankTitle + ", " + it->_schemaTitle;
				_lb1->Items->Add(msclr::interop::marshal_as<String^>(tmp));
			}
			tmp2.erase(tmp2.size() - 2);
			print_form->setEtalons(msclr::interop::marshal_as<String^>(tmp2));
			_lb1->Items->Add("");//пробел
		}
		//Стандартные образцы
		if (!vResponses[vri_id]->_means->_ses.empty()) {
			String^ lbl_mis = L"Стандартные образцы:";
			_lb1->Items->Add(lbl_mis);
			std::string tmp;
			std::string tmp2 = "";//для print_form
			if (_lb1->Items->Count > 1) tmp2 = ", ";
			for (const auto &it : vResponses[vri_id]->_means->_ses) {
				tmp2 += it->_number + ", ";
				tmp = it->_number + ", " + it->_title + ", " + it->_manufactureYear;
				_lb1->Items->Add(msclr::interop::marshal_as<String^>(tmp));
			}
			tmp2.erase(tmp2.size() - 2);
			print_form->setEtalons(msclr::interop::marshal_as<String^>(tmp2));
			_lb1->Items->Add("");//пробел
		}
		//Средства измерений, применяемые при поверке
		if (!vResponses[vri_id]->_means->_mis.empty()) {
			String^ lbl_mis = L"Средства измерений, применяемые при поверке:";
			_lb1->Items->Add(lbl_mis);
			std::string tmp;
			for (const auto &it : vResponses[vri_id]->_means->_mis) {
				tmp = it->_mitypeNumber + ", " + it->_title + ", " + it->_number;
				_lb1->Items->Add(msclr::interop::marshal_as<String^>(tmp));
			}
			_lb1->Items->Add("");
		}
		//Вещество (материал), применяемый при поверке
		if (!vResponses[vri_id]->_means->_reagents.empty()) {
			String^ lbl_mis = L"Вещество (материал), применяемый при поверке:";
			_lb1->Items->Add(lbl_mis);
			std::string tmp;
			for (const auto& it : vResponses[vri_id]->_means->_reagents) {
				tmp = it->_number + ", " + it->_type + ", " + it->_title;
				_lb1->Items->Add(msclr::interop::marshal_as<String^>(tmp));
			}
			_lb1->Items->Add("");
		}
		//КОНЕЦ ЛИСТБОКСА СИ

		//INFO
		//structure
		if (!vResponses[vri_id]->_over_info->_structure.empty()) {
			String^ info_structure = L"Состав СИ, представленного на поверку: ";
			String^ tmp = msclr::interop::marshal_as<String^>(vResponses[vri_id]->_over_info->_structure);
			info_structure += tmp;
			_lb2->Items->Add(info_structure);
			print_form->setStructure(tmp); //на print_form
		}
		//briefIndicator (в объёме)
		if (vResponses[vri_id]->_over_info->_briefIndicator)
			_lb2->Items->Add(L"Поверка в сокращенном объеме: Да");
		else {
			_lb2->Items->Add(L"Поверка в сокращенном объеме: Нет");
			print_form->setBriefCharacter("в полном объёме");
		}
		//briefCharacteristics
		if (!vResponses[vri_id]->_over_info->_briefCharacteristics.empty()) {
			String^ info_bc = L"Краткая характеристика объема поверки: ";
			String^ tmp = msclr::interop::marshal_as<String^>(vResponses[vri_id]->_over_info->_briefCharacteristics);
			info_bc += tmp;
			_lb2->Items->Add(info_bc);
			print_form->setBriefCharacter(tmp);
		}
		//additional_info
		if (!vResponses[vri_id]->_over_info->_additional_info.empty()) {
			String^ info_add = L"Прочие сведения: ";
			info_add += msclr::interop::marshal_as<String^>(vResponses[vri_id]->_over_info->_additional_info);
			_lb2->Items->Add(info_add);
			print_form->setAddInfo(info_add);
		}
		//protocol
		if (vResponses[vri_id]->_over_info->_prt != nullptr) {
			String^ info_prt = L"Приложение: ";
			info_prt += msclr::interop::marshal_as<String^>(vResponses[vri_id]->_over_info->_prt->_title) + " от " + 
				textBox14->Text + " № " + msclr::interop::marshal_as<String^>(vResponses[vri_id]->_over_info->_prt->_filename);
			_lb2->Items->Add(info_prt);
			//на panel_PrintV
			if (_lb2->Items->Count > 0)
				print_form->setAddInfo("\r\n" + info_prt);
			else
				print_form->setAddInfo(info_prt);
		}
		//Владелец СИ
		if(vResponses[vri_id]->_vri_info->_miOwner != "")
			_lb2->Items->Add("Владелец СИ: " + msclr::interop::marshal_as<String^>(vResponses[vri_id]->_vri_info->_miOwner));
		//тип поверки на panel_PrintV
		(vResponses[vri_id]->_vri_info->_vriType == "2") ? print_form->setVriType("периодическая") : print_form->setVriType("первичная");
		//Заключение о поверке на panel_PrintV (разное у СИ и эталонов)
		if (vResponses[vri_id]->_eta != nullptr) {
			//сначала добавляем год выпуска эталона в сведения
			print_form->setSI(", " + msclr::interop::marshal_as<String^>(vResponses[vri_id]->_eta->_manufactureYear) + " г.в.");
			//далее добавляем разряд и приказ
			String^ zakl = "и на основании результатов "+ getVriType(vri_id) +" поверки признано " + getApplay(vri_id) + " к применению в качестве эталона "
				+ msclr::interop::marshal_as<String^>(vResponses[vri_id]->_eta->_rankCode) + " "
				+ msclr::interop::marshal_as<String^>(vResponses[vri_id]->_eta->_schemaTitle);
			print_form->setZakluchenie(zakl);
		}
		else
			print_form->setZakluchenie("и на основании результатов " + getVriType(vri_id) + " поверки признано " + getApplay(vri_id) + " к применению.");
		
		//видимость объектов
		panel1_filterSI->Visible = false;
		panel2_responses->Visible = false;
		panel3_viewer->Visible = true;
	}
	//return System::Void();
}

//закрыть просмотр сведений о конкретном СИ
System::Void Arshin::MyForm::button4_Click(System::Object^ sender, System::EventArgs^ e) {
	linkLabel1->Text = "";
	linkLabel1->Links->Clear();
	linkLabel2->Text = "";
	linkLabel2->Links->Clear();
	textBox9->Text = "";
	textBox10->Text = "";
	textBox11->Text = "";
	textBox12->Text = "";
	textBox13->Text = "";
	textBox14->Text = "";
	textBox15->Text = "";
	textBox16->Text = "";
	textBox17->Text = "";
	textBox18->Text = "";
	textBox19->Text = "";
	textBox20->Text = "";
	_lb1->Items->Clear();//средства поверки
	_lb2->Items->Clear();//доп инфа
	print_form->ClearPrintForm();//форма печати
	//
	bv_it = 0; //итератор для _border_values, нужен в парсе возвращаемой строки в запросе полных сведений по конкретному СИ
	//видимость объектов
	panel2_responses->Visible = true;
	panel3_viewer->Visible = false;

	return System::Void();
}

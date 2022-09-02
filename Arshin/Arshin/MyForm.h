#pragma once
//#include <cliext/vector>
#include <windows.h>
#include <wininet.h>
#include <string>
#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>
#pragma comment(lib,"wininet")

namespace ProjectCLR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	//using namespace cliext;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel1_filterSI;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker3;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker4;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker2;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	protected:


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
		//vector<String^>^ nameColumns = gcnew vector<String^>();
		String^ verification_year;
		String^ org_title;
		String^ mitnumber;
		String^ mititle;
		String^ mitype;
		String^ modification;
		String^ znumber;
		String^ result_docnum;
		String^ verification_date1;
		String^ verification_date2;
		String^ valid_date1;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::TextBox^ textBox9;
		   String^ valid_date2;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1_filterSI = (gcnew System::Windows::Forms::Panel());
			this->dateTimePicker3 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker4 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->panel1_filterSI->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(245, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(168, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Фильтр поиска СИ";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// panel1_filterSI
			// 
			this->panel1_filterSI->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1_filterSI->Controls->Add(this->dateTimePicker3);
			this->panel1_filterSI->Controls->Add(this->dateTimePicker4);
			this->panel1_filterSI->Controls->Add(this->dateTimePicker2);
			this->panel1_filterSI->Controls->Add(this->dateTimePicker1);
			this->panel1_filterSI->Controls->Add(this->textBox8);
			this->panel1_filterSI->Controls->Add(this->textBox7);
			this->panel1_filterSI->Controls->Add(this->textBox6);
			this->panel1_filterSI->Controls->Add(this->textBox5);
			this->panel1_filterSI->Controls->Add(this->textBox4);
			this->panel1_filterSI->Controls->Add(this->textBox3);
			this->panel1_filterSI->Controls->Add(this->textBox2);
			this->panel1_filterSI->Controls->Add(this->textBox1);
			this->panel1_filterSI->Controls->Add(this->button1);
			this->panel1_filterSI->Controls->Add(this->label11);
			this->panel1_filterSI->Controls->Add(this->label10);
			this->panel1_filterSI->Controls->Add(this->label9);
			this->panel1_filterSI->Controls->Add(this->label8);
			this->panel1_filterSI->Controls->Add(this->label7);
			this->panel1_filterSI->Controls->Add(this->label6);
			this->panel1_filterSI->Controls->Add(this->label5);
			this->panel1_filterSI->Controls->Add(this->label4);
			this->panel1_filterSI->Controls->Add(this->label3);
			this->panel1_filterSI->Controls->Add(this->label2);
			this->panel1_filterSI->Controls->Add(this->label1);
			this->panel1_filterSI->Location = System::Drawing::Point(12, 3);
			this->panel1_filterSI->Name = L"panel1_filterSI";
			this->panel1_filterSI->Size = System::Drawing::Size(651, 554);
			this->panel1_filterSI->TabIndex = 1;
			this->panel1_filterSI->Layout += gcnew System::Windows::Forms::LayoutEventHandler(this, &MyForm::panel1_filterSI_Layout);
			// 
			// dateTimePicker3
			// 
			this->dateTimePicker3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->dateTimePicker3->Location = System::Drawing::Point(479, 420);
			this->dateTimePicker3->Name = L"dateTimePicker3";
			this->dateTimePicker3->Size = System::Drawing::Size(144, 21);
			this->dateTimePicker3->TabIndex = 25;
			this->dateTimePicker3->ValueChanged += gcnew System::EventHandler(this, &MyForm::dateTimePicker3_ValueChanged);
			// 
			// dateTimePicker4
			// 
			this->dateTimePicker4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->dateTimePicker4->Location = System::Drawing::Point(313, 420);
			this->dateTimePicker4->Name = L"dateTimePicker4";
			this->dateTimePicker4->Size = System::Drawing::Size(144, 21);
			this->dateTimePicker4->TabIndex = 24;
			this->dateTimePicker4->ValueChanged += gcnew System::EventHandler(this, &MyForm::dateTimePicker4_ValueChanged);
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->dateTimePicker2->Location = System::Drawing::Point(479, 376);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(144, 21);
			this->dateTimePicker2->TabIndex = 23;
			this->dateTimePicker2->ValueChanged += gcnew System::EventHandler(this, &MyForm::dateTimePicker2_ValueChanged);
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Checked = false;
			this->dateTimePicker1->CustomFormat = L" ";
			this->dateTimePicker1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->dateTimePicker1->Location = System::Drawing::Point(313, 376);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(144, 21);
			this->dateTimePicker1->TabIndex = 22;
			this->dateTimePicker1->ValueChanged += gcnew System::EventHandler(this, &MyForm::dateTimePicker1_ValueChanged);
			// 
			// textBox8
			// 
			this->textBox8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox8->Location = System::Drawing::Point(313, 467);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(310, 22);
			this->textBox8->TabIndex = 19;
			// 
			// textBox7
			// 
			this->textBox7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox7->Location = System::Drawing::Point(313, 335);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(310, 22);
			this->textBox7->TabIndex = 18;
			// 
			// textBox6
			// 
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox6->Location = System::Drawing::Point(313, 291);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(310, 22);
			this->textBox6->TabIndex = 17;
			// 
			// textBox5
			// 
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox5->Location = System::Drawing::Point(313, 247);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(310, 22);
			this->textBox5->TabIndex = 16;
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox4->Location = System::Drawing::Point(313, 203);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(310, 22);
			this->textBox4->TabIndex = 15;
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(313, 159);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(310, 22);
			this->textBox3->TabIndex = 14;
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(313, 115);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(310, 22);
			this->textBox2->TabIndex = 13;
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(313, 71);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(310, 22);
			this->textBox1->TabIndex = 12;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(292, 513);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 11;
			this->button1->Text = L"Поиск";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label11->Location = System::Drawing::Point(25, 468);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(153, 16);
			this->label11->TabIndex = 10;
			this->label11->Text = L"Номер свидетельства";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->Location = System::Drawing::Point(25, 424);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(128, 16);
			this->label10->TabIndex = 9;
			this->label10->Text = L"Действительна до";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(25, 380);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(98, 16);
			this->label9->TabIndex = 8;
			this->label9->Text = L"Дата поверки";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(25, 336);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(123, 16);
			this->label8->TabIndex = 7;
			this->label8->Text = L"Заводской номер";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(25, 292);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(122, 16);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Модификация СИ";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(25, 248);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(55, 16);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Тип СИ";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(25, 204);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(163, 16);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Наименование типа СИ";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(25, 160);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(226, 16);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Регистрационный номер типа СИ";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(25, 116);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(177, 16);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Организация-поверитель";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(25, 72);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(171, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Год проведения поверки";
			// 
			// label12
			// 
			this->label12->Location = System::Drawing::Point(0, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(100, 23);
			this->label12->TabIndex = 0;
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(12, 563);
			this->textBox9->Multiline = true;
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(651, 40);
			this->textBox9->TabIndex = 2;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(675, 608);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->panel1_filterSI);
			this->Name = L"MyForm";
			this->Text = L"Аршин";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->panel1_filterSI->ResumeLayout(false);
			this->panel1_filterSI->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void dateTimePicker1_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	dateTimePicker1->CustomFormat = "dd-MM-yyyy";
}
private: System::Void dateTimePicker2_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	dateTimePicker2->CustomFormat = "dd-MM-yyyy";
}
private: System::Void dateTimePicker3_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	dateTimePicker3->CustomFormat = "dd-MM-yyyy";
}
private: System::Void dateTimePicker4_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	dateTimePicker4->CustomFormat = "dd-MM-yyyy";
}
private: System::Void panel1_filterSI_Layout(System::Object^ sender, System::Windows::Forms::LayoutEventArgs^ e) {
	dateTimePicker1->CustomFormat = " ";
	dateTimePicker1->Format = DateTimePickerFormat::Custom;
	dateTimePicker2->CustomFormat = " ";
	dateTimePicker2->Format = DateTimePickerFormat::Custom;
	dateTimePicker3->CustomFormat = " ";
	dateTimePicker3->Format = DateTimePickerFormat::Custom;
	dateTimePicker4->CustomFormat = " ";
	dateTimePicker4->Format = DateTimePickerFormat::Custom;
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	verification_year = textBox1->Text->Trim()->ToString();
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
	if(dateTimePicker2->CustomFormat == " ")
		verification_date2 = "";
	else
		verification_date2 = dateTimePicker2->Value.Date.ToString("yyyy-MM-dd");
	if(dateTimePicker3->CustomFormat == " ")
		valid_date1 = "";
	else
		valid_date1 = dateTimePicker3->Value.Date.ToString("yyyy-MM-dd");
	if (dateTimePicker4->CustomFormat == " ")
		valid_date2 = "";
	else
		valid_date2 = dateTimePicker4->Value.Date.ToString("yyyy-MM-dd");

	String^ select = "/fundmetrology/cm/xcdb/vri/select?fq=verification_year:";
	if (verification_year != "")
		select += verification_year;
	if (org_title != "")
		select += "&fq=org_title:*" + org_title + "*";
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
	//convert String^ to wstring to LPCWSTR
	std::wstring wstr = msclr::interop::marshal_as<std::wstring>(select);
	LPCWSTR pcwstr;
	pcwstr = wstr.c_str();
	//
	bool ok = false;
	std::wstring str;
	// инициализируем WinInet
	HINTERNET hInternet = ::InternetOpen(TEXT("Arshin request"), INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
	if (hInternet != NULL) {
		// открываем HTTP сессию
		HINTERNET hConnect = ::InternetConnect(hInternet, TEXT("fgis.gost.ru"), INTERNET_DEFAULT_HTTP_PORT, NULL, NULL, INTERNET_SERVICE_HTTP, 0, 1u);
		if (hConnect != NULL) {
			// открываем запрос
			HINTERNET hRequest = ::HttpOpenRequest(hConnect, TEXT("GET"), pcwstr, NULL, NULL, 0, INTERNET_FLAG_KEEP_CONNECTION, 1);
			if (hRequest != NULL) {
				// посылаем запрос
				BOOL bSend = ::HttpSendRequest(hRequest, NULL, 0, NULL, 0);
				if (bSend) {
					for (;;) {
						// читаем данные
						wchar_t szData[1024];
						DWORD dwBytesRead;
						BOOL bRead = ::InternetReadFile(hRequest, szData, sizeof(szData) - 1, &dwBytesRead);
						// выход из цикла при ошибке или завершении
						if (bRead == FALSE || dwBytesRead == 0)
							break;
						// сохраняем результат
						szData[dwBytesRead] = 0;
						str += szData;
						ok = true;
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
	select = msclr::interop::marshal_as<String^>(str);
	textBox9->Text = select;

}


private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}

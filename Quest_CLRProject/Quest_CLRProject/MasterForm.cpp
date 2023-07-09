#include "MasterForm.h"

using namespace QuestCLRProject;

[STAThreadAttribute]
int main(array<System::String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    Application::Run(gcnew MasterForm());
    return 0;
}

// запрос в БД
SQLiteDataReader^ QuestCLRProject::MasterForm::responseBD(String^ str) {
    SQLiteCommand^ cmdSelect = db->CreateCommand();
    cmdSelect->CommandText = str;
    return cmdSelect->ExecuteReader();
    throw (gcnew System::Exception("Error in responseBD"));
}
// autorize form reload
System::Void QuestCLRProject::MasterForm::autorizePanel() {
	this->SuspendLayout();
    //resize MF
    _widthMF = 300;
    _heightMF = 300;
    this->ClientSize = System::Drawing::Size(_widthMF, _heightMF);
    // move to center screen
    Drawing::Size sz = Screen::PrimaryScreen->Bounds.Size;
    Top = (sz.Height - Height) / 2;
    Left = (sz.Width - Width) / 2;
    //cleaning
    _tableLayoutPanel2->Controls->Clear();
    this->Controls->Clear();
    logInfo->clear();
    _toolStripLabel1->Text = "";
    //
	this->Controls->Add(this->_tableLayoutPanel1);
	this->MaximizeBox = false;
	this->MaximumSize = System::Drawing::Size(_widthMF, _heightMF);
	this->MinimizeBox = false;
	this->MinimumSize = System::Drawing::Size(_widthMF, _heightMF);
	this->ResumeLayout();
    return System::Void();
}
// подготовка _tableLayoutPanel2
System::Void QuestCLRProject::MasterForm::fillTLP2() {
    _tableLayoutPanel2->Controls->Add(_toolStrip1, 0, 0);
    _tableLayoutPanel2->SetColumnSpan(_toolStrip1, 2);
    _tableLayoutPanel2->Controls->Add(_dataGridView1, 0, 1);
    _tableLayoutPanel2->SetColumnSpan(_dataGridView1, 2);
    _tableLayoutPanel2->Controls->Add(_statusStrip1, 0, 2);
    _tableLayoutPanel2->SetColumnSpan(_statusStrip1, 2);
    return System::Void();
}
// подготовка _tableLayoutPanel3 под вариант вопроса
System::Void QuestCLRProject::MasterForm::fillTLP3() {
    _labelQuestionNumber->Text = L"Вопрос № " + numberQuestion;
    for (int i = 0; i < CountAnswers; ++i) {
        CheckBox^ chbTMP = gcnew System::Windows::Forms::CheckBox();
        chbTMP->AutoSize = false;
        chbTMP->Dock = System::Windows::Forms::DockStyle::Fill;
        chbTMP->Tag = i;
        chbTMP->CheckedChanged += gcnew System::EventHandler(this, &MasterForm::checkedChanged);
        _vCBAnswers->push_back(chbTMP);
    }
    int RowCountAnswers = CountAnswers;
    if (RowCountAnswers < 2) RowCountAnswers = 1;
    if (RowCountAnswers % 2 != 0) RowCountAnswers++;
    RowCountAnswers /= 2;
    _tableLayoutPanel3->RowCount = RowCountAnswers + 3; // + номер вопроса, вопрос и строка под кнопки
    _tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 50)));
    _tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 60)));
    for (int i = 0; i < RowCountAnswers; ++i)
        _tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10)));
    _tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
    _tableLayoutPanel3->Controls->Add(_labelQuestionNumber, 0, 0);
    _tableLayoutPanel3->SetColumnSpan(_labelQuestionNumber, 2);
    _tableLayoutPanel3->Controls->Add(_labelQuestion, 0, 1);
    _tableLayoutPanel3->SetColumnSpan(_labelQuestion, 2);
    for (int i = 0, c = 0, r = 2; i < CountAnswers; ++i) {
        (i % 2 == 0) ? c = 0 : c = 1;
        _tableLayoutPanel3->Controls->Add(_vCBAnswers[i], c, r);
        if (c == 1)
            r++;
    }
    _tableLayoutPanel3->Controls->Add(_buttonQuit, 0, RowCountAnswers + 2);
    _tableLayoutPanel3->Controls->Add(_buttonNext, 1, RowCountAnswers + 2);
    _buttonNext->Enabled = false;
    return System::Void();
}

System::Void QuestCLRProject::MasterForm::clearTLP3() {
    _tableLayoutPanel3->SuspendLayout();
    --CountAnswers;
    for (; 0 <= CountAnswers; --CountAnswers) {
        _tableLayoutPanel3->Controls->Remove(_vCBAnswers[CountAnswers]);
        _vCBAnswers->pop_back();
    } 
    _vCBAnswers->clear();
    _labelQuestionNumber->Text = "";
    _labelQuestion->Text = "";
    _tableLayoutPanel3->Controls->Clear();
    _tableLayoutPanel3->RowCount = 1;
    CountAnswers = 0;
    VAcount = 0;
    _tableLayoutPanel3->ResumeLayout();
    return System::Void();
}

// авторизация вход
System::Void QuestCLRProject::MasterForm::_buttonEnter_Click(System::Object^ sender, System::EventArgs^ e) {
    // reading log & pass
    String^ _log = _textBoxLogin->Text->Trim();
    String^ _pass = _textBoxPass->Text->Trim();
    _textBoxLogin->Clear();
    _textBoxPass->Clear();
    // обращение к БД
    try {
        SQLiteDataReader^ readerLog = responseBD("SELECT login, password, logstatus, name, email, logfile FROM autorize WHERE login='" + _log + "' AND password='" + _pass + "';");
        if (readerLog->HasRows && logInfo->empty()) {
            while (readerLog->Read()) {
                logInfo->push_back(readerLog->GetString(0)->ToString());
                logInfo->push_back(readerLog->GetString(1)->ToString());
                logInfo->push_back(Convert::ToString(readerLog->GetInt32(2)));
                logInfo->push_back(readerLog->GetString(3)->ToString());
                logInfo->push_back(readerLog->GetString(4)->ToString());
                logInfo->push_back(readerLog->GetString(5)->ToString());
            }
            if (logInfo[2] == L"111")
                _log += L" (ДОРОГОЙ БРАТ)";
        }
        else { // guest
            _log = L"дорогой гость!";
        }
        readerLog->Close();
    }
    catch (Exception^ e) {
        MessageBox::Show("Error when executing SQL query: " + e->ToString(), "Exception While executing SQL query ...");
    }
    // front
    this->Controls->Clear(); // очищаю форму от элементов авторизации
    // увеличиваю размер формы
    _widthMF = 600;
    _heightMF = 400;
    Drawing::Size sz = Screen::PrimaryScreen->Bounds.Size;
    // меняю место формы по центру экрана
    this->SetDesktopLocation((sz.Width - _widthMF) / 2,(sz.Height -  _heightMF) / 2);
    this->ClientSize = System::Drawing::Size(_widthMF, _heightMF);
    // разрешаю сворачивать и разворачивать окно формы
    this->MaximizeBox = true;
    this->MaximumSize = System::Drawing::Size(0, 0);
    this->MinimizeBox = true;
    this->MinimumSize = System::Drawing::Size(0, 0);
    fillTLP2();
    this->Controls->Add(_tableLayoutPanel2);
    // end front

    // add in toolStriplabel1 name user and status
    _toolStripLabel1->Text = L"Вы вошли как, " + _log;
    // запрос доступных тестов
    SQLiteDataReader^ readerTest = responseBD("SELECT name FROM test_name;");
    if (readerTest->HasRows) {
        DataTable^ tableTestName = gcnew DataTable;
        DataColumn^ columnName = gcnew DataColumn("Доступные тесты", String::typeid);
        tableTestName->Columns->Add(columnName);
        DataRow^ rowTestNames;
        while (readerTest->Read()) {
            rowTestNames = tableTestName->NewRow();
            rowTestNames[0] = readerTest->GetString(0)->ToString();
            tableTestName->Rows->Add(rowTestNames);
        }
        _dataGridView1->DataSource = tableTestName;
    }
    readerTest->Close();

    return System::Void();
}
// CANCEL autorization
System::Void QuestCLRProject::MasterForm::_buttonCancel_Click(System::Object^ sender, System::EventArgs^ e) {
    if (_textBoxLogin->Text == "" && _textBoxPass->Text == "")
        this->Close();
    else {
        _textBoxLogin->Text = "";
        _textBoxPass->Text = "";
    }
    return System::Void();
}
// connect BD in loader
System::Void QuestCLRProject::MasterForm::MasterForm_Load(System::Object^ sender, System::EventArgs^ e) {
    try {
        db->ConnectionString = "Data Source=\"" + fileName + "\"";
        db->Open();
    }
    catch (Exception^ e) {
        MessageBox::Show("Error Executing SQL: " + e->ToString(), "Exception While Displaying MyTable ...");
    }
    return System::Void();
}
// exit into autorize
System::Void QuestCLRProject::MasterForm::toolStripButton1_Click(System::Object^ sender, System::EventArgs^ e) {
    autorizePanel();
    _toolStripStatusLabel1->Text = "";
    return System::Void();
}

System::Void QuestCLRProject::MasterForm::checkedChanged(System::Object^ sender, System::EventArgs^ e) {
    CheckBox^ _chbx = (CheckBox^)sender;
    if (_chbx->Checked) {
        if (VAcount == 1) {
            for (int i = 0; i < CountAnswers; ++i) {
                if (i != (int)_chbx->Tag)
                    _vCBAnswers[i]->AutoCheck = false;
            }
        }
        _buttonNext->Enabled = true;
        //_buttonNext->Text += " " + _chbx->Tag->ToString();//пока так
    }
    else {
        for (int i = 0; i < CountAnswers; ++i)
            _vCBAnswers[i]->AutoCheck = true;
        _buttonNext->Enabled = false;
    }

    return System::Void();
}

// кнопка далее (следующий вопрос)
System::Void QuestCLRProject::MasterForm::button_Next_Click(System::Object^ sender, System::EventArgs^ e) {
    if (numberQuestion <= CountQuestion) {
        _tableLayoutPanel2->SuspendLayout();
        clearTLP3();
        _tableLayoutPanel2->Controls->Remove(_tableLayoutPanel3);
        // количество вариантов ответа
        SQLiteDataReader^ readerCount = responseBD("SELECT COUNT(id_q) FROM answers WHERE id_q=" + numberQuestion + " AND id_t=" + CurrentRowIndex + ";");
        CountAnswers = 0;
        if (readerCount->HasRows) {
            while (readerCount->Read())
                CountAnswers = System::Convert::ToInt32(readerCount->GetValue(0));
        }
        readerCount->Close();
        // количество правильных ответов
        SQLiteDataReader^ countValidyAnswers = responseBD("SELECT COUNT(id_q) FROM answers WHERE id_q=" + numberQuestion + " AND id_t=" + CurrentRowIndex + " AND validity = 1;");
        VAcount = 0;
        if (countValidyAnswers->HasRows) {
            while (countValidyAnswers->Read())
                VAcount = System::Convert::ToInt32(countValidyAnswers->GetValue(0));
        }
        countValidyAnswers->Close();
        fillTLP3();
        _tableLayoutPanel2->Controls->Add(_tableLayoutPanel3, 0, 1);
        _tableLayoutPanel2->SetColumnSpan(_tableLayoutPanel3, 2);

        SQLiteDataReader^ readerQuestions = responseBD("SELECT tests_questions.question, answers.answer, answers.validity FROM tests_questions, answers WHERE tests_questions.id_t=" + CurrentRowIndex + " AND tests_questions.id_q=" + numberQuestion + " AND tests_questions.id_t = answers.id_t AND tests_questions.id_q = answers.id_q;");
        if (readerQuestions->HasRows) {
            int numAns = 0;
            while (readerQuestions->Read()) {
                for (int colCtr = 0; colCtr < readerQuestions->FieldCount; ++colCtr) {
                    if (_labelQuestion->Text == "" && colCtr == 0)
                        _labelQuestion->Text = readerQuestions->GetValue(colCtr)->ToString();
                    else if (_labelQuestion->Text != "" && colCtr == 0)
                        continue;
                    else if (colCtr == 1)
                        _vCBAnswers[numAns]->Text = readerQuestions->GetValue(colCtr)->ToString();
                    // validity добавить
                    // еще нет реализации учета правильных ответов
                    // может вностить это в лог?
                }
                ++numAns;
            }
        }
        readerQuestions->Close();
        _toolStripStatusLabel1->Text = numberQuestion + L" из " + CountQuestion;
        _tableLayoutPanel2->ResumeLayout();
        numberQuestion++;
    }
    else {
        // результат теста


    }
    

    return System::Void();
}
// cell click
System::Void QuestCLRProject::MasterForm::dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
    CurrentRowIndex = _dataGridView1->CurrentRow->Index + 1;
    numberQuestion = 1;
    // количество вопросов в тесте
    SQLiteDataReader^ readerCQ = responseBD("SELECT max(id_q) FROM answers WHERE id_t=" + CurrentRowIndex + ";");
    CountQuestion = 0;
    if (readerCQ->HasRows) {
        while (readerCQ->Read())
            CountQuestion = System::Convert::ToInt32(readerCQ->GetValue(0));
    }
    readerCQ->Close();
    // количество вариантов ответа
    SQLiteDataReader^ readerCount = responseBD("SELECT COUNT(id_q) FROM answers WHERE id_q=" + numberQuestion + " AND id_t=" + CurrentRowIndex + ";");
    CountAnswers = 0;
    if (readerCount->HasRows) {
        while (readerCount->Read())
            CountAnswers = System::Convert::ToInt32(readerCount->GetValue(0));
    }
    readerCount->Close();
    // количество правильных ответов
    SQLiteDataReader^ countValidyAnswers = responseBD("SELECT COUNT(id_q) FROM answers WHERE id_q=" + numberQuestion + " AND id_t=" + CurrentRowIndex + " AND validity = 1;");
    VAcount = 0;
    if (countValidyAnswers->HasRows) {
        while(countValidyAnswers->Read())
            VAcount = System::Convert::ToInt32(countValidyAnswers->GetValue(0));
    }
    countValidyAnswers->Close();
    
    /*
    * (похоже нужен запрос о количестве вопросов в тесте, хотя бы чтобы номер вопроса не зашкаливал) +
    Нужна структура логирования, например:
    int autirize_id - если 0 - гость
    string login_name
    vector из структуры учета прохождения теста:
        int test_id
        vector из пары int num, bool y/n
    При авторизации создается экземпляр структуры логирования или считывается из таблицы autorize -> logfile (придумать как)
    если гость - ничего не создается (хотя можно для гостя одну строку держать)
    При нажатии кнопки некст, в текущей структуре логирования в векторе учета ищется структура с текущим test_id
    если такого нет - добавляется в вектор. В эту структуру дописывается результат.
    Если такой тест уже был начат имеет смысл добавить: продолжить / начать заново (соответственно удалить структуру)
    При выходе изавторизации записывать эту структуру в autorize -> logfile (придумать как)

    Далее нужно плюсануть номер вопроса и повторить запрос..
    возможно проработать этот момент пока без логирования и учета ответа
    видимо многое вывести в функции
    */
    
    // front
    _tableLayoutPanel2->SuspendLayout();
    _tableLayoutPanel2->Controls->RemoveAt(1); //удаляю из табличного слоя2 датагридвью с тестами (сама таблица не удаляется)
    fillTLP3();
    _tableLayoutPanel2->Controls->Add(_tableLayoutPanel3, 0, 1);
    _tableLayoutPanel2->SetColumnSpan(_tableLayoutPanel3, 2);
    // end front
    // основной запрос вопроса, ответов и какой/какие из них правильные
    SQLiteDataReader^ readerQuestions = responseBD("SELECT tests_questions.question, answers.answer, answers.validity FROM tests_questions, answers WHERE tests_questions.id_t=" + CurrentRowIndex + " AND tests_questions.id_q=" + numberQuestion + " AND tests_questions.id_t = answers.id_t AND tests_questions.id_q = answers.id_q;");
    if (readerQuestions->HasRows) {
        int numAns = 0;
        while (readerQuestions->Read()) {
            for (int colCtr = 0; colCtr < readerQuestions->FieldCount; ++colCtr) {
                if (_labelQuestion->Text == "" && colCtr == 0)
                    _labelQuestion->Text = readerQuestions->GetValue(colCtr)->ToString();
                else if (_labelQuestion->Text != "" && colCtr == 0)
                    continue;
                else if (colCtr == 1)
                    _vCBAnswers[numAns]->Text = readerQuestions->GetValue(colCtr)->ToString();
                // validity добавить
            }
            ++numAns;
        }
    }
    readerQuestions->Close();
    _toolStripStatusLabel1->Text = numberQuestion + L" из " + CountQuestion;
    _tableLayoutPanel2->ResumeLayout();
    numberQuestion++;

    return System::Void();
}



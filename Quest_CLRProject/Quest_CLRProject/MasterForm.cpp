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
    // toolStripButton1
    this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
    this->toolStripButton1->Name = L"toolStripButton1";
    this->toolStripButton1->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
    this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::ImageAndText;
    //this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton1.Image")));
    this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
    this->toolStripButton1->Size = System::Drawing::Size(100, 25);
    this->toolStripButton1->Text = L"Выйти";
    this->toolStripButton1->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
    this->toolStripButton1->Click += gcnew System::EventHandler(this, &MasterForm::toolStripButton1_Click);
    // toolStripLabel1
    _toolStripLabel1 = gcnew System::Windows::Forms::ToolStripLabel();
    _toolStripLabel1->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
    // toolStrip1
    _toolStrip1 = gcnew System::Windows::Forms::ToolStrip();
    _toolStrip1->Name = L"toolStrip1";
    _toolStrip1->AutoSize = true;
    _toolStrip1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right
        | System::Windows::Forms::AnchorStyles::Left));
    _toolStrip1->Dock = System::Windows::Forms::DockStyle::Fill;
    _toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->toolStripButton1, this->_toolStripLabel1 });
    // _statusStrip1
    _statusStrip1 = gcnew System::Windows::Forms::StatusStrip();
    _statusStrip1->Name = L"_statusStrip1";
    _statusStrip1->AutoSize = true;
    _statusStrip1->Dock = System::Windows::Forms::DockStyle::Fill;
    _statusStrip1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right
        | System::Windows::Forms::AnchorStyles::Left));
    //dataGridView1
    _dataGridView1 = gcnew System::Windows::Forms::DataGridView();
    _dataGridView1->Name = L"dataGridView1";
    _dataGridView1->AutoSize = true;
    _dataGridView1->AllowUserToAddRows = false;
    _dataGridView1->AllowUserToDeleteRows = false;
    _dataGridView1->AllowUserToResizeColumns = false;
    _dataGridView1->AllowUserToResizeRows = false;
    _dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
        | System::Windows::Forms::AnchorStyles::Right));
    _dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
    _dataGridView1->BackgroundColor = System::Drawing::SystemColors::Menu;
    _dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
    _dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
    _dataGridView1->ColumnHeadersVisible = false;
    _dataGridView1->Cursor = System::Windows::Forms::Cursors::Default;
    _dataGridView1->EditMode = System::Windows::Forms::DataGridViewEditMode::EditOnEnter;
    _dataGridView1->MultiSelect = false;
    _dataGridView1->ReadOnly = true;
    _dataGridView1->RowHeadersVisible = false;
    _dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::CellSelect;
    _dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MasterForm::dataGridView1_CellClick);
    //dataGridView1->CellMouseEnter += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellMouseEnter);
    //dataGridView1->CellMouseLeave += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellMouseLeave);
    // _tableLayoutPanel2
    _tableLayoutPanel2 = gcnew System::Windows::Forms::TableLayoutPanel();
    _tableLayoutPanel2->Name = L"_tableLayoutPanel2";
    _tableLayoutPanel2->Location = System::Drawing::Point(0, 0);
    _tableLayoutPanel2->AutoSize = true;
    _tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
    _tableLayoutPanel2->ColumnCount = 1;
    _tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 100)));
    _tableLayoutPanel2->RowCount = 3;
    _tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 25)));
    _tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 90)));
    _tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 25)));
    _tableLayoutPanel2->Controls->Add(_toolStrip1, 0, 0);
    _tableLayoutPanel2->Controls->Add(_dataGridView1, 0, 1);
    _tableLayoutPanel2->Controls->Add(_statusStrip1, 0, 2);

    return System::Void();
}
// подготовка _tableLayoutPanel3 под вариант вопроса
System::Void QuestCLRProject::MasterForm::fillTLP3() {
    _labelQuestionNumber = gcnew System::Windows::Forms::Label();
    _labelQuestionNumber->Anchor = System::Windows::Forms::AnchorStyles::None;
    _labelQuestionNumber->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
    _labelQuestionNumber->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204));
    _labelQuestionNumber->AutoSize = false;
    _labelQuestionNumber->Dock = System::Windows::Forms::DockStyle::Fill;
    _labelQuestionNumber->Text = L"Вопрос № " + numberQuestion;
    _labelQuestion = gcnew System::Windows::Forms::Label();
    _labelQuestion->AutoSize = false;
    _labelQuestion->Dock = System::Windows::Forms::DockStyle::Fill;
    _aCBAnswers = gcnew array<System::Windows::Forms::CheckBox^>(CountAnswers);
    for (int i = 0; i < CountAnswers; ++i) {
        _aCBAnswers[i] = gcnew System::Windows::Forms::CheckBox();
        _aCBAnswers[i]->AutoSize = false;
        _aCBAnswers[i]->Dock = System::Windows::Forms::DockStyle::Fill;
        _aCBAnswers[i]->Tag = i;
        _aCBAnswers[i]->CheckedChanged += gcnew System::EventHandler(this, &MasterForm::checkedChanged);
    }
    _buttonNext = gcnew System::Windows::Forms::Button();
    _buttonNext->Text = L"Далее >>";
    _buttonNext->AutoSize = false;
    _buttonNext->Size = System::Drawing::Size(150, 26);
    _buttonNext->Margin = System::Windows::Forms::Padding(25, 3, 3, 3);
    _buttonNext->Click += gcnew System::EventHandler(this, &MasterForm::button_Next_Click);
    _buttonQuit = gcnew System::Windows::Forms::Button();
    _buttonQuit->Text = L"Отмена";
    _buttonQuit->AutoSize = false;
    _buttonQuit->Size = System::Drawing::Size(150, 26);
    _buttonQuit->Margin = System::Windows::Forms::Padding(25, 3, 3, 3);
    _tableLayoutPanel3 = gcnew System::Windows::Forms::TableLayoutPanel();
    _tableLayoutPanel3->AutoSize = false;
    _tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
    _tableLayoutPanel3->ColumnCount = 2;
    _tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 50)));
    _tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 50)));
    int RowCountAnswers = CountAnswers / 2;
    if (RowCountAnswers < 2) RowCountAnswers = 1;
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
        _tableLayoutPanel3->Controls->Add(_aCBAnswers[i], c, r);
        if (c == 1)
            r++;
    }
    _tableLayoutPanel3->Controls->Add(_buttonQuit, 0, RowCountAnswers + 2);
    _tableLayoutPanel3->Controls->Add(_buttonNext, 1, RowCountAnswers + 2);

    return System::Void();
}

System::Void QuestCLRProject::MasterForm::clearTLP3() {
    _aCBAnswers->Clear;
    _labelQuestionNumber->Text = "";
    _labelQuestion->Text = "";
    _tableLayoutPanel3->Controls->Remove(_labelQuestionNumber);
    _tableLayoutPanel3->Controls->Remove(_labelQuestion);
    for (int i = 0; i < CountAnswers; ++i)
        _tableLayoutPanel3->Controls->Remove(_aCBAnswers[i]);
    _tableLayoutPanel3->Controls->Remove(_buttonQuit);
    _tableLayoutPanel3->Controls->Remove(_buttonNext);
    _tableLayoutPanel3->Controls->Clear();
    _tableLayoutPanel3->RowCount = 0;
    _tableLayoutPanel3->ColumnCount = 0;
    CountAnswers = 0;
    VAcount = 0;

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
    return System::Void();
}

System::Void QuestCLRProject::MasterForm::checkedChanged(System::Object^ sender, System::EventArgs^ e) {
    CheckBox^ _chbx = (CheckBox^)sender;
    if (_chbx->Checked) {
        if (VAcount == 1) {
            for (int i = 0; i < CountAnswers; ++i) {
                if (i != (int)_chbx->Tag)
                    _aCBAnswers[i]->AutoCheck = false;
            }
        }
        //_buttonNext->Text += " " + _chbx->Tag->ToString();//пока так
    }
    else {
        for (int i = 0; i < CountAnswers; ++i)
            _aCBAnswers[i]->AutoCheck = true;
    }

    return System::Void();
}

System::Void QuestCLRProject::MasterForm::button_Next_Click(System::Object^ sender, System::EventArgs^ e) {
    ++numberQuestion;

    
    clearTLP3();
    return System::Void();
}
// cell click
System::Void QuestCLRProject::MasterForm::dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
    size_t CurrentRowIndex = _dataGridView1->CurrentRow->Index + 1;
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
    _tableLayoutPanel2->Controls->RemoveAt(1); //удаляю из табличного слоя2 датагридвью с тестами (сама таблица не удаляется)
    fillTLP3();
    _tableLayoutPanel2->Controls->Add(_tableLayoutPanel3, 0, 1);
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
                    _aCBAnswers[numAns]->Text = readerQuestions->GetValue(colCtr)->ToString();
                // validity добавить
            }
            ++numAns;
        }
    }
    readerQuestions->Close();

    return System::Void();
}



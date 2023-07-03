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
    this->Controls->Add(_tableLayoutPanel2);
    // end front
    // 
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
// cell click
System::Void QuestCLRProject::MasterForm::dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
    size_t CurrentRowIndex = _dataGridView1->CurrentRow->Index + 1;
    numberQuestion = 1;
    SQLiteDataReader^ readerCount = responseBD("SELECT COUNT(id_q) FROM answers WHERE id_q=" + numberQuestion + ";");
    //readerCount->StepCount
    int RowCount = 0;
    RowCount = System::Convert::ToInt32(readerCount->GetValue(1));
    readerCount->Close();
    SQLiteDataReader^ countValidyAnswers = responseBD("SELECT COUNT(id_q) FROM answers WHERE id_q=" + numberQuestion + " AND validity = 1; ");
    int VAcount = 0;
    VAcount = System::Convert::ToInt32(countValidyAnswers->GetValue(1));
    countValidyAnswers->Close();
    SQLiteDataReader^ readerQuestions = responseBD("SELECT tests_questions.question, answers.answer, answers.validity FROM tests_questions, answers WHERE tests_questions.id_t=" + CurrentRowIndex + " AND tests_questions.id_q=" + numberQuestion + " AND tests_questions.id_t = answers.id_t AND tests_questions.id_q = answers.id_q;");
    /*
    if (readerQuestions->HasRows) {
        //label3->Text += Convert::ToString(CurrentRowIndex); //номер вопроса
        cliext::vector<String^>^ vQuestions = gcnew cliext::vector<String^>();
        while (readerQuestions->Read()) {
            for (int colCtr = 0; colCtr < readerQuestions->FieldCount; ++colCtr) {
                if (vQuestions->empty() && colCtr == 0)
                    vQuestions->push_back(readerQuestions->GetValue(colCtr)->ToString());
                else if (!vQuestions->empty() && colCtr == 0)
                    continue;
                else
                    vQuestions->push_back(readerQuestions->GetValue(colCtr)->ToString());
            }
        }
        */
        _tableLayoutPanel2->Controls->RemoveAt(1); //удаляю из табличного слоя2 датагридвью с тестами
        Label^ _lbl = gcnew Label();
        _lbl->Text = L"Количество ответов: " + RowCount + L"; из них правильных: " + VAcount;
        _tableLayoutPanel2->Controls->Add(_lbl, 0, 1);

        //TestTemplTable^ _ttt = gcnew TestTemplTable((vQuestions->size() - 1) / 2); //размер для шаблона без вопроса и правильности ответа
       // _ttt->setNumberQuestion(numberQuestion); //номер вопроса
        //_ttt->setQuestion(vQuestions[0]); //вопрос
        //считывание вектора с ответами и количеством правильных
        /*
        int countValidyAnswers = 0;
        for (int i = 1, num = 0; i < vQuestions->size(); ++i) {
            if (i % 2 == 0) {
                countValidyAnswers += Convert::ToInt32(vQuestions[i]); // счет правильных
            }
            else {
                //_ttt->setAnswers(vQuestions[i], num); // запись в массив ответов
                ++num;
            }
        }
        */
       // _ttt->setOneOrMany(countValidyAnswers); // запись количества правильных ответов
        // добавление табличного слоя к форме
        //this->Controls->Add(_ttt->_tableLayoutPanel1);
        //panelHome->Visible = false;
        //_ttt->setVisible(true);
        //}
    
    readerQuestions->Close();

    return System::Void();
}



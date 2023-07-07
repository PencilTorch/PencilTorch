#pragma once
#include <cliext/vector>

namespace QuestCLRProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Data::SQLite;
	using namespace System::Text;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MasterForm
	/// </summary>
	public ref class MasterForm : public System::Windows::Forms::Form
	{
	public:
		MasterForm(void)
		{
			_widthMF = 284; // ширина основной формы на старте
			_heightMF = 262; //высота
			//название подключемой базы
			fileName = "tests.db3";
			db = gcnew SQLiteConnection();
			logInfo = gcnew cliext::vector<String^>();
			_vCBAnswers = gcnew cliext::vector<CheckBox^>();
			//TLP2
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
			// _toolStripStatusLabel1
			_toolStripStatusLabel1 = gcnew System::Windows::Forms::ToolStripStatusLabel();
			_toolStripStatusLabel1->Alignment = System::Windows::Forms::ToolStripItemAlignment::Left;
			// _statusStrip1
			_statusStrip1 = gcnew System::Windows::Forms::StatusStrip();
			_statusStrip1->Name = L"_statusStrip1";
			_statusStrip1->AutoSize = true;
			_statusStrip1->Dock = System::Windows::Forms::DockStyle::Fill;
			_statusStrip1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right
				| System::Windows::Forms::AnchorStyles::Left));
			_statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->_toolStripStatusLabel1 });
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
			//_tableLayoutPanel2->Controls->AddRange(gcnew cli::array< System::Windows::Forms::Control^  >(3) { _toolStrip1 , _dataGridView1, _statusStrip1 });
			_tableLayoutPanel2->BorderStyle = BorderStyle::FixedSingle;
			// 
			//TLP3
			_labelQuestionNumber = gcnew System::Windows::Forms::Label();
			_labelQuestionNumber->Anchor = System::Windows::Forms::AnchorStyles::None;
			_labelQuestionNumber->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			_labelQuestionNumber->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204));
			_labelQuestionNumber->AutoSize = false;
			_labelQuestionNumber->Dock = System::Windows::Forms::DockStyle::Fill;
			
			_labelQuestion = gcnew System::Windows::Forms::Label();
			_labelQuestion->AutoSize = false;
			_labelQuestion->Dock = System::Windows::Forms::DockStyle::Fill;

			_buttonNext = gcnew System::Windows::Forms::Button();
			_buttonNext->Text = L"Далее >>";
			_buttonNext->AutoSize = false;
			_buttonNext->Size = System::Drawing::Size(150, 26);
			_buttonNext->Margin = System::Windows::Forms::Padding(25, 3, 3, 3);
			_buttonNext->Enabled = false;
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
			
			InitializeComponent();
		}

		~MasterForm()
		{
			db->Close();
			logInfo->clear();
			_vCBAnswers->clear();
			if (components)
			{
				delete components;
			}
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		
	private:
		//masterF
		int _widthMF;
		int _heightMF;
		//connectBD
		SQLiteConnection^ db;
		String^ fileName;
		// авторизация
		cliext::vector<String^>^ logInfo;
		System::Windows::Forms::TableLayoutPanel^ _tableLayoutPanel1;
		System::Windows::Forms::Label^ _labelAutorize;
		System::Windows::Forms::Label^ _labelLogin;
		System::Windows::Forms::Label^ _labelPass;
		System::Windows::Forms::TextBox^ _textBoxLogin;
		System::Windows::Forms::TextBox^ _textBoxPass;
		System::Windows::Forms::Button^ _buttonEnter;
		System::Windows::Forms::Button^ _buttonCancel;
		// список доступных тестов
		System::Windows::Forms::TableLayoutPanel^ _tableLayoutPanel2;
		System::Windows::Forms::ToolStrip^ _toolStrip1;
		System::Windows::Forms::StatusStrip^ _statusStrip1;
		System::Windows::Forms::ToolStripLabel^ _toolStripLabel1;
		System::Windows::Forms::ToolStripButton^ toolStripButton1;
		System::Windows::Forms::ToolStripStatusLabel^ _toolStripStatusLabel1;
		System::Windows::Forms::DataGridView^ _dataGridView1;
		size_t CurrentRowIndex; // индекс строки выбранного теста
		size_t numberQuestion; //номер вопроса
		// выбранный тест
		System::Windows::Forms::TableLayoutPanel^ _tableLayoutPanel3;
		System::Windows::Forms::Label^ _labelQuestionNumber;
		System::Windows::Forms::Label^ _labelQuestion;
		//array<CheckBox^>^ _aCBAnswers;
		cliext::vector<CheckBox^>^ _vCBAnswers;
		System::Windows::Forms::Button^ _buttonNext;
		System::Windows::Forms::Button^ _buttonQuit;
		int CountQuestion; // количество вопросов в тесте
		int CountAnswers; // количество ответов в вопросе
		int VAcount; // количество правильных ответов
	private:
		SQLiteDataReader^ responseBD(String^ str);
		System::Void autorizePanel();
		System::Void fillTLP2();
		System::Void fillTLP3();
		System::Void clearTLP3();

		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		
		void InitializeComponent(void)
		{
			this->_labelAutorize = (gcnew System::Windows::Forms::Label());
			this->_labelLogin = (gcnew System::Windows::Forms::Label());
			this->_labelPass = (gcnew System::Windows::Forms::Label());
			this->_textBoxLogin = (gcnew System::Windows::Forms::TextBox());
			this->_textBoxPass = (gcnew System::Windows::Forms::TextBox());
			this->_buttonEnter = (gcnew System::Windows::Forms::Button());
			this->_buttonCancel = (gcnew System::Windows::Forms::Button());
			this->_tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->_tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// _labelAutorize
			// 
			this->_tableLayoutPanel1->SetColumnSpan(this->_labelAutorize, 2);
			this->_labelAutorize->Dock = System::Windows::Forms::DockStyle::Fill;
			this->_labelAutorize->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->_labelAutorize->Location = System::Drawing::Point(3, 0);
			this->_labelAutorize->Name = L"_labelAutorize";
			this->_labelAutorize->Size = System::Drawing::Size(278, 65);
			this->_labelAutorize->TabIndex = 0;
			this->_labelAutorize->Text = L"Авторизация";
			this->_labelAutorize->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// _labelLogin
			// 
			this->_labelLogin->Dock = System::Windows::Forms::DockStyle::Fill;
			this->_labelLogin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->_labelLogin->Location = System::Drawing::Point(3, 65);
			this->_labelLogin->Name = L"_labelLogin";
			this->_labelLogin->Padding = System::Windows::Forms::Padding(20, 0, 0, 0);
			this->_labelLogin->Size = System::Drawing::Size(136, 65);
			this->_labelLogin->TabIndex = 1;
			this->_labelLogin->Text = L"логин: ";
			// 
			// _labelPass
			// 
			this->_labelPass->Dock = System::Windows::Forms::DockStyle::Fill;
			this->_labelPass->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->_labelPass->Location = System::Drawing::Point(3, 130);
			this->_labelPass->Name = L"_labelPass";
			this->_labelPass->Padding = System::Windows::Forms::Padding(20, 0, 0, 0);
			this->_labelPass->Size = System::Drawing::Size(136, 65);
			this->_labelPass->TabIndex = 2;
			this->_labelPass->Text = L"пароль: ";
			// 
			// _textBoxLogin
			// 
			this->_textBoxLogin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->_textBoxLogin->Location = System::Drawing::Point(145, 68);
			this->_textBoxLogin->Name = L"_textBoxLogin";
			this->_textBoxLogin->Size = System::Drawing::Size(100, 23);
			this->_textBoxLogin->TabIndex = 1;
			// 
			// _textBoxPass
			// 
			this->_textBoxPass->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->_textBoxPass->Location = System::Drawing::Point(145, 133);
			this->_textBoxPass->Name = L"_textBoxPass";
			this->_textBoxPass->PasswordChar = '*';
			this->_textBoxPass->Size = System::Drawing::Size(100, 23);
			this->_textBoxPass->TabIndex = 2;
			// 
			// _buttonEnter
			// 
			this->_buttonEnter->Location = System::Drawing::Point(20, 198);
			this->_buttonEnter->Margin = System::Windows::Forms::Padding(20, 3, 3, 3);
			this->_buttonEnter->Name = L"_buttonEnter";
			this->_buttonEnter->Size = System::Drawing::Size(100, 26);
			this->_buttonEnter->TabIndex = 3;
			this->_buttonEnter->Text = L"Войти";
			this->_buttonEnter->Click += gcnew System::EventHandler(this, &MasterForm::_buttonEnter_Click);
			// 
			// _buttonCancel
			// 
			this->_buttonCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->_buttonCancel->Location = System::Drawing::Point(145, 198);
			this->_buttonCancel->Name = L"_buttonCancel";
			this->_buttonCancel->Size = System::Drawing::Size(100, 26);
			this->_buttonCancel->TabIndex = 4;
			this->_buttonCancel->Text = L"Отмена";
			this->_buttonCancel->Click += gcnew System::EventHandler(this, &MasterForm::_buttonCancel_Click);
			// 
			// _tableLayoutPanel1
			// 
			this->_tableLayoutPanel1->ColumnCount = 2;
			this->_tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->_tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->_tableLayoutPanel1->Controls->Add(this->_labelAutorize, 0, 0);
			this->_tableLayoutPanel1->Controls->Add(this->_labelLogin, 0, 1);
			this->_tableLayoutPanel1->Controls->Add(this->_labelPass, 0, 2);
			this->_tableLayoutPanel1->Controls->Add(this->_textBoxLogin, 1, 1);
			this->_tableLayoutPanel1->Controls->Add(this->_textBoxPass, 1, 2);
			this->_tableLayoutPanel1->Controls->Add(this->_buttonEnter, 0, 3);
			this->_tableLayoutPanel1->Controls->Add(this->_buttonCancel, 1, 3);
			this->_tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->_tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->_tableLayoutPanel1->Name = L"_tableLayoutPanel1";
			this->_tableLayoutPanel1->RowCount = 4;
			this->_tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->_tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->_tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->_tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->_tableLayoutPanel1->Size = System::Drawing::Size(284, 262);
			this->_tableLayoutPanel1->TabIndex = 0;
			// 
			// MasterForm
			// 
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->_tableLayoutPanel1);
			this->KeyPreview = true;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(300, 300);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(300, 300);
			this->Name = L"MasterForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Оттестируй меня полностью";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &MasterForm::MasterForm_Load);
			this->_tableLayoutPanel1->ResumeLayout(false);
			this->_tableLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void _buttonEnter_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void _buttonCancel_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MasterForm_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void toolStripButton1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
	private: System::Void checkedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_Next_Click(System::Object^ sender, System::EventArgs^ e);
};
}
//this->Controls->Add(_logForm->tableLayoutPanel1);
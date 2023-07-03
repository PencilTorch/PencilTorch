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


			InitializeComponent();
		}

		~MasterForm()
		{
			db->Close();
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
		System::Windows::Forms::DataGridView^ _dataGridView1;
		size_t numberQuestion;
		// выбранный тест
		System::Windows::Forms::TableLayoutPanel^ _tableLayoutPanel3;
		System::Windows::Forms::Label^ _labelQuestionNumber;
		System::Windows::Forms::Label^ _labelQuestion;
		array<CheckBox^>^ _aCBAnswers;
		array<RadioButton^>^ _aRBAnswers;
		System::Windows::Forms::Button^ _buttonNext;
		System::Windows::Forms::Button^ _buttonQuit;
	private:
		SQLiteDataReader^ responseBD(String^ str);
		System::Void autorizePanel();

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
			this->_tableLayoutPanel1->Size = System::Drawing::Size(284, 261);
			this->_tableLayoutPanel1->TabIndex = 0;
			// 
			// MasterForm
			// 
			this->ClientSize = System::Drawing::Size(284, 261);
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
};
}
//this->Controls->Add(_logForm->tableLayoutPanel1);
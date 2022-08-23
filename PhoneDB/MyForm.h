#pragma once
#include <cliext/vector>
#define ATB 11 //количество текстбоксов в массиве


namespace ProjectCLR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SQLite;
	using namespace System::Text;
	using namespace cliext;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void) {
			fileName = "fonebase.db3";
			db = gcnew SQLiteConnection();
			ColName = gcnew vector<String^>();
			ColumnsHeader = gcnew vector<String^>();
			arrTextBox = gcnew array<TextBox^>(ATB);
			// Windows Form Designer generated code
			InitializeComponent();
			// groupBox1
			for (int i = 0; i < arrTextBox->Length; ++i)
				this->arrTextBox[i] = (gcnew System::Windows::Forms::TextBox());
			for (int i = 0; i < arrTextBox->Length; ++i)
				this->groupBox1->Controls->Add(this->arrTextBox[i]);
			// textBox_SPP
			this->arrTextBox[0]->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
			this->arrTextBox[0]->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::CustomSource;
			this->arrTextBox[0]->Location = System::Drawing::Point(42, 24);
			this->arrTextBox[0]->Name = L"textBox_SPP";
			this->arrTextBox[0]->Size = System::Drawing::Size(100, 20);
			this->arrTextBox[0]->TabIndex = 1;
			this->arrTextBox[0]->GotFocus += gcnew System::EventHandler(this, &MyForm::textBox1_GotFocus);
			// textBox_podrazdel
			this->arrTextBox[1]->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
			this->arrTextBox[1]->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::CustomSource;
			this->arrTextBox[1]->Location = System::Drawing::Point(252, 24);
			this->arrTextBox[1]->Name = L"textBox_podrazdel";
			this->arrTextBox[1]->Size = System::Drawing::Size(100, 20);
			this->arrTextBox[1]->TabIndex = 3;
			this->arrTextBox[1]->GotFocus += gcnew System::EventHandler(this, &MyForm::textBox2_GotFocus);
			// textBox_dolzhnost
			this->arrTextBox[2]->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
			this->arrTextBox[2]->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::CustomSource;
			this->arrTextBox[2]->Location = System::Drawing::Point(438, 24);
			this->arrTextBox[2]->Name = L"textBox_dolzhnost";
			this->arrTextBox[2]->Size = System::Drawing::Size(100, 20);
			this->arrTextBox[2]->TabIndex = 21; // pomenyat
			this->arrTextBox[2]->GotFocus += gcnew System::EventHandler(this, &MyForm::textBox11_GotFocus);
			// textBox_fname
			this->arrTextBox[3]->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
			this->arrTextBox[3]->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::CustomSource;
			this->arrTextBox[3]->Location = System::Drawing::Point(230, 55);
			this->arrTextBox[3]->Name = L"textBox_fname";
			this->arrTextBox[3]->Size = System::Drawing::Size(100, 20);
			this->arrTextBox[3]->TabIndex = 7;
			this->arrTextBox[3]->GotFocus += gcnew System::EventHandler(this, &MyForm::textBox4_GotFocus);
			// textBox_sname
			this->arrTextBox[4]->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
			this->arrTextBox[4]->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::CustomSource;
			this->arrTextBox[4]->Location = System::Drawing::Point(68, 55);
			this->arrTextBox[4]->Name = L"textBox_sname";
			this->arrTextBox[4]->Size = System::Drawing::Size(100, 20);
			this->arrTextBox[4]->TabIndex = 5;
			this->arrTextBox[4]->GotFocus += gcnew System::EventHandler(this, &MyForm::textBox3_GotFocus);
			// textBox_tname
			this->arrTextBox[5]->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
			this->arrTextBox[5]->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::CustomSource;
			this->arrTextBox[5]->Location = System::Drawing::Point(412, 55);
			this->arrTextBox[5]->Name = L"textBox_tname";
			this->arrTextBox[5]->Size = System::Drawing::Size(126, 20);
			this->arrTextBox[5]->TabIndex = 9;
			this->arrTextBox[5]->GotFocus += gcnew System::EventHandler(this, &MyForm::textBox5_GotFocus);
			// textBox_fone1
			this->arrTextBox[6]->Location = System::Drawing::Point(68, 90);
			this->arrTextBox[6]->Name = L"textBox_fone1";
			this->arrTextBox[6]->Size = System::Drawing::Size(100, 20);
			this->arrTextBox[6]->TabIndex = 11;
			this->arrTextBox[6]->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox8_TextChanged);
			// textBox_fone2
			this->arrTextBox[7]->Location = System::Drawing::Point(262, 90);
			this->arrTextBox[7]->Name = L"textBox_fone2";
			this->arrTextBox[7]->Size = System::Drawing::Size(100, 20);
			this->arrTextBox[7]->TabIndex = 13;
			// textBox_tfone
			this->arrTextBox[8]->Location = System::Drawing::Point(128, 120);
			this->arrTextBox[8]->Name = L"textBox_tfone";
			this->arrTextBox[8]->Size = System::Drawing::Size(128, 20);
			this->arrTextBox[8]->TabIndex = 19;
			// textBox_mfone
			this->arrTextBox[9]->Location = System::Drawing::Point(403, 120);
			this->arrTextBox[9]->Name = L"textBox_mfone";
			this->arrTextBox[9]->Size = System::Drawing::Size(135, 20);
			this->arrTextBox[9]->TabIndex = 15;
			// textBox_notes
			this->arrTextBox[10]->Location = System::Drawing::Point(553, 24);
			this->arrTextBox[10]->Multiline = true;
			this->arrTextBox[10]->Name = L"textBox_notes";
			this->arrTextBox[10]->Size = System::Drawing::Size(351, 116);
			this->arrTextBox[10]->TabIndex = 17;
			//openFoleDialog1
			this->openFileDialog1->InitialDirectory = Application::StartupPath;
			//заполнение заголовком столбцов
			FillColumnsHeader();
		}
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm() {
			if (components) {
				delete components;
			}
			db->Close();
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:

	private:
		String^ fileName; //название файла базы данных
		SQLiteConnection^ db; //переменная подключения к бд
		vector<String^>^ ColumnsHeader; //Вектор названий столбцов в хэдере
		vector<String^>^ ColName; //Вектор названий столбцов в sql-таблице
		array<TextBox^>^ arrTextBox; //массив текстбоксов
		
	private: System::Windows::Forms::Panel^ panel1;

	private: System::Windows::Forms::ToolStrip^ toolStrip1;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton2;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton3;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton4;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::TextBox^ textBox12;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label12;
private: System::Windows::Forms::Button^ button4;
private: System::Windows::Forms::MenuStrip^ menuStrip1;
private: System::Windows::Forms::ToolStripMenuItem^ файлToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ importToolStripMenuItem;

private: System::Windows::Forms::ToolStripMenuItem^ exportToolStripMenuItem;

private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem1;

private: System::Windows::Forms::ToolStripMenuItem^ правкаToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ добавитьЗаписьToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ редактироватьЗаписьToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ удалитьЗаписьToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ справкаToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ оПрограммеToolStripMenuItem;
private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItemRedacting;
private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItemDeleting;
private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItemCopyCell;
private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator1;
private: System::ComponentModel::IContainer^ components;



		
#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->toolStripMenuItemRedacting = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemDeleting = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton2 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton3 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton4 = (gcnew System::Windows::Forms::ToolStripButton());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->файлToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->importToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exportToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->правкаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->добавитьЗаписьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->редактироватьЗаписьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->удалитьЗаписьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->справкаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->оПрограммеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripMenuItemCopyCell = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->contextMenuStrip1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->Padding = System::Windows::Forms::Padding(1);
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->ContextMenuStrip = this->contextMenuStrip1;
			this->dataGridView1->EnableHeadersVisualStyles = false;
			this->dataGridView1->Location = System::Drawing::Point(3, 22);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::Green;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->RowHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 5;
			this->dataGridView1->Size = System::Drawing::Size(928, 593);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellContentDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentDoubleClick);
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->toolStripMenuItemCopyCell,
					this->toolStripSeparator1, this->toolStripMenuItemRedacting, this->toolStripMenuItemDeleting
			});
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(195, 98);
			// 
			// toolStripMenuItemRedacting
			// 
			this->toolStripMenuItemRedacting->Name = L"toolStripMenuItemRedacting";
			this->toolStripMenuItemRedacting->Size = System::Drawing::Size(194, 22);
			this->toolStripMenuItemRedacting->Text = L"Редактировать запись";
			this->toolStripMenuItemRedacting->Click += gcnew System::EventHandler(this, &MyForm::toolStripMenuItemRedacting_Click);
			// 
			// toolStripMenuItemDeleting
			// 
			this->toolStripMenuItemDeleting->Name = L"toolStripMenuItemDeleting";
			this->toolStripMenuItemDeleting->Size = System::Drawing::Size(194, 22);
			this->toolStripMenuItemDeleting->Text = L"Удалить запись";
			this->toolStripMenuItemDeleting->Click += gcnew System::EventHandler(this, &MyForm::toolStripMenuItemDeleting_Click);
			// 
			// panel1
			// 
			this->panel1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->panel1->AutoSize = true;
			this->panel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->groupBox1);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Location = System::Drawing::Point(3, 22);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(924, 199);
			this->panel1->TabIndex = 1;
			this->panel1->Visible = false;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->label9);
			this->groupBox1->Controls->Add(this->label10);
			this->groupBox1->Controls->Add(this->label11);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(9, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(910, 153);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(30, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"СПП";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(159, 27);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(87, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Подразделение";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 58);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(56, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Фамилия";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(195, 58);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(29, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Имя";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(352, 58);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(54, 13);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Отчество";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(285, 123);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(112, 13);
			this->label6->TabIndex = 14;
			this->label6->Text = L"Мобильный телефон";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(195, 93);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(61, 13);
			this->label7->TabIndex = 12;
			this->label7->Text = L"Телефон 2";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(6, 93);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(61, 13);
			this->label8->TabIndex = 10;
			this->label8->Text = L"Телефон 1";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(545, 8);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(51, 13);
			this->label9->TabIndex = 16;
			this->label9->Text = L"Заметки";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(6, 123);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(116, 13);
			this->label10->TabIndex = 18;
			this->label10->Text = L"Другой способ связи";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(367, 27);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(65, 13);
			this->label11->TabIndex = 20;
			this->label11->Text = L"Должность";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(785, 171);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(128, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Отмена";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(562, 171);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(183, 23);
			this->button1->TabIndex = 1;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// toolStrip1
			// 
			this->toolStrip1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->toolStrip1->Dock = System::Windows::Forms::DockStyle::None;
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->toolStripButton1,
					this->toolStripButton2, this->toolStripButton3, this->toolStripButton4
			});
			this->toolStrip1->Location = System::Drawing::Point(3, 616);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(104, 25);
			this->toolStrip1->TabIndex = 2;
			this->toolStrip1->Text = L"Быстрое меню";
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(23, 22);
			this->toolStripButton1->Text = L"Добавить запись";
			this->toolStripButton1->Click += gcnew System::EventHandler(this, &MyForm::toolStripButton1_Click);
			// 
			// toolStripButton2
			// 
			this->toolStripButton2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton2.Image")));
			this->toolStripButton2->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton2->Name = L"toolStripButton2";
			this->toolStripButton2->Size = System::Drawing::Size(23, 22);
			this->toolStripButton2->Text = L"Редактировать выделенную запись";
			this->toolStripButton2->Click += gcnew System::EventHandler(this, &MyForm::toolStripButton2_Click);
			// 
			// toolStripButton3
			// 
			this->toolStripButton3->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton3.Image")));
			this->toolStripButton3->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton3->Name = L"toolStripButton3";
			this->toolStripButton3->Size = System::Drawing::Size(23, 22);
			this->toolStripButton3->Text = L"Удалить выделенную запись";
			this->toolStripButton3->Click += gcnew System::EventHandler(this, &MyForm::toolStripButton3_Click);
			// 
			// toolStripButton4
			// 
			this->toolStripButton4->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton4.Image")));
			this->toolStripButton4->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton4->Name = L"toolStripButton4";
			this->toolStripButton4->Size = System::Drawing::Size(23, 22);
			this->toolStripButton4->Text = L"Поиск";
			this->toolStripButton4->Click += gcnew System::EventHandler(this, &MyForm::toolStripButton4_Click);
			// 
			// panel2
			// 
			this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->panel2->Controls->Add(this->button4);
			this->panel2->Controls->Add(this->button3);
			this->panel2->Controls->Add(this->textBox12);
			this->panel2->Controls->Add(this->comboBox1);
			this->panel2->Controls->Add(this->label12);
			this->panel2->Location = System::Drawing::Point(110, 616);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(536, 25);
			this->panel2->TabIndex = 3;
			this->panel2->Visible = false;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(450, 0);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Отмена";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(350, 1);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(94, 23);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Показать";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// textBox12
			// 
			this->textBox12->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
			this->textBox12->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::CustomSource;
			this->textBox12->Location = System::Drawing::Point(192, 3);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(143, 20);
			this->textBox12->TabIndex = 2;
			this->textBox12->GotFocus += gcnew System::EventHandler(this, &MyForm::textBox12_GotFocus);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"-= Везде =-" });
			this->comboBox1->Location = System::Drawing::Point(65, 3);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 1;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label12->Location = System::Drawing::Point(15, 4);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(49, 15);
			this->label12->TabIndex = 0;
			this->label12->Text = L"Искать";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->файлToolStripMenuItem,
					this->правкаToolStripMenuItem, this->справкаToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(934, 24);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// файлToolStripMenuItem
			// 
			this->файлToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->importToolStripMenuItem,
					this->exportToolStripMenuItem, this->exitToolStripMenuItem1
			});
			this->файлToolStripMenuItem->Name = L"файлToolStripMenuItem";
			this->файлToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->файлToolStripMenuItem->Text = L"Файл";
			// 
			// importToolStripMenuItem
			// 
			this->importToolStripMenuItem->Name = L"importToolStripMenuItem";
			this->importToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->importToolStripMenuItem->Text = L"Загрузить данные";
			this->importToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::importToolStripMenuItem_Click);
			// 
			// exportToolStripMenuItem
			// 
			this->exportToolStripMenuItem->Name = L"exportToolStripMenuItem";
			this->exportToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->exportToolStripMenuItem->Text = L"Выгрузить данные";
			this->exportToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exportToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem1
			// 
			this->exitToolStripMenuItem1->Name = L"exitToolStripMenuItem1";
			this->exitToolStripMenuItem1->Size = System::Drawing::Size(175, 22);
			this->exitToolStripMenuItem1->Text = L"Выход";
			this->exitToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem1_Click);
			// 
			// правкаToolStripMenuItem
			// 
			this->правкаToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->добавитьЗаписьToolStripMenuItem,
					this->редактироватьЗаписьToolStripMenuItem, this->удалитьЗаписьToolStripMenuItem
			});
			this->правкаToolStripMenuItem->Name = L"правкаToolStripMenuItem";
			this->правкаToolStripMenuItem->Size = System::Drawing::Size(59, 20);
			this->правкаToolStripMenuItem->Text = L"Правка";
			// 
			// добавитьЗаписьToolStripMenuItem
			// 
			this->добавитьЗаписьToolStripMenuItem->Name = L"добавитьЗаписьToolStripMenuItem";
			this->добавитьЗаписьToolStripMenuItem->Size = System::Drawing::Size(194, 22);
			this->добавитьЗаписьToolStripMenuItem->Text = L"Добавить запись";
			this->добавитьЗаписьToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::добавитьЗаписьToolStripMenuItem_Click);
			// 
			// редактироватьЗаписьToolStripMenuItem
			// 
			this->редактироватьЗаписьToolStripMenuItem->Name = L"редактироватьЗаписьToolStripMenuItem";
			this->редактироватьЗаписьToolStripMenuItem->Size = System::Drawing::Size(194, 22);
			this->редактироватьЗаписьToolStripMenuItem->Text = L"Редактировать запись";
			this->редактироватьЗаписьToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::редактироватьЗаписьToolStripMenuItem_Click);
			// 
			// удалитьЗаписьToolStripMenuItem
			// 
			this->удалитьЗаписьToolStripMenuItem->Name = L"удалитьЗаписьToolStripMenuItem";
			this->удалитьЗаписьToolStripMenuItem->Size = System::Drawing::Size(194, 22);
			this->удалитьЗаписьToolStripMenuItem->Text = L"Удалить запись";
			this->удалитьЗаписьToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::удалитьЗаписьToolStripMenuItem_Click);
			// 
			// справкаToolStripMenuItem
			// 
			this->справкаToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->оПрограммеToolStripMenuItem });
			this->справкаToolStripMenuItem->Name = L"справкаToolStripMenuItem";
			this->справкаToolStripMenuItem->Size = System::Drawing::Size(65, 20);
			this->справкаToolStripMenuItem->Text = L"Справка";
			// 
			// оПрограммеToolStripMenuItem
			// 
			this->оПрограммеToolStripMenuItem->Name = L"оПрограммеToolStripMenuItem";
			this->оПрограммеToolStripMenuItem->Size = System::Drawing::Size(149, 22);
			this->оПрограммеToolStripMenuItem->Text = L"О программе";
			this->оПрограммеToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::оПрограммеToolStripMenuItem_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->Filter = L"\"Excel файлы (*.xlsx)|*.xlsx|Excel файлы (*.xls)|*.xls\"";
			this->openFileDialog1->Title = L"Выберите импортируемый файл";
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->CreatePrompt = true;
			this->saveFileDialog1->Filter = L"\"Excel файлы (*.xlsx)|*.xlsx|Excel файлы (*.xls)|*.xls\"";
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(191, 6);
			// 
			// toolStripMenuItemCopyCell
			// 
			this->toolStripMenuItemCopyCell->Name = L"toolStripMenuItemCopyCell";
			this->toolStripMenuItemCopyCell->Size = System::Drawing::Size(194, 22);
			this->toolStripMenuItemCopyCell->Text = L"Копировать";
			this->toolStripMenuItemCopyCell->Click += gcnew System::EventHandler(this, &MyForm::toolStripMenuItemCopyCell_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(934, 641);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->dataGridView1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MinimumSize = System::Drawing::Size(777, 300);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"PhoneBase 2.0";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->contextMenuStrip1->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e);
private: DataTable^ fillDataTable(); //вывод бд на форму
private: System::Void FillColumnsHeader();
private: System::Void FillColName();
private: System::Void seekerComboBox1();
private: System::Void changing_an_entry(); //код вызова панели редактирования записи
private: System::Void adding_an_entry(); //код вызова панели добавления записи
private: System::Void deleting_an_entry(); //код вызова меню удаления записи
private: System::Void makeVectorHint(vector<String^>^ VectorHint, int numberColumns);
private: System::Void toolStripButton1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void textBox1_GotFocus(System::Object^ sender, System::EventArgs^ e);
private: System::Void textBox2_GotFocus(System::Object^ sender, System::EventArgs^ e);
private: System::Void textBox11_GotFocus(System::Object^ sender, System::EventArgs^ e);
private: System::Void textBox3_GotFocus(System::Object^ sender, System::EventArgs^ e);
private: System::Void textBox4_GotFocus(System::Object^ sender, System::EventArgs^ e);
private: System::Void textBox5_GotFocus(System::Object^ sender, System::EventArgs^ e);
private: System::Void textBox8_TextChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void toolStripButton2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void toolStripButton3_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void toolStripButton4_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void textBox12_GotFocus(System::Object^ sender, System::EventArgs^ e);
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void importToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void exportToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void exitToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void добавитьЗаписьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void редактироватьЗаписьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void удалитьЗаписьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void оПрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void dataGridView1_CellContentDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
private: System::Void toolStripMenuItemRedacting_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void toolStripMenuItemDeleting_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void toolStripMenuItemCopyCell_Click(System::Object^ sender, System::EventArgs^ e);

};
}

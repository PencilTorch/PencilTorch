#pragma once
#include "PrintForm.h"
//#include <cliext/vector> //нужна для CLR вектора, а тут std
#include "Response.h"
#include <windows.h>
#include <wininet.h>
#include <string>
#include <vector>
#include <regex>
#include <iterator>
#include <msclr/marshal_cppstd.h>
#pragma comment(lib,"wininet")

namespace Arshin {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	//using namespace cliext; //нужна для CLR вектора, а тут std
	std::string Utf8_to_cp1251(const std::string_view& str);
	void HttpParsRequest(std::string& request_str, const std::string& connect_adr, const std::string& connect_site = "fgis.gost.ru");
	std::vector<Response*> vResponses;

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
	private: System::Windows::Forms::Label^ label21;
	public:
		PrintForm^ print_form = gcnew PrintForm();
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
			delete print_form;
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
		String^ valid_date2;
		System::Windows::Forms::ListBox^ _lb1;
		System::Windows::Forms::ListBox^ _lb2;

	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Panel^ panel2_responses;
	private: System::Windows::Forms::Panel^ panel3_viewer;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label32;
	private: System::Windows::Forms::Label^ label30;
	private: System::Windows::Forms::Label^ label28;
	private: System::Windows::Forms::Label^ label27;
	private: System::Windows::Forms::Label^ label26;
	private: System::Windows::Forms::Label^ label25;
	private: System::Windows::Forms::Label^ label24;
	private: System::Windows::Forms::Label^ label23;
	private: System::Windows::Forms::Label^ label22;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Button^ button4;
private: System::Windows::Forms::ComboBox^ comboBox1;
private: System::Windows::Forms::TextBox^ textBox9;
private: System::Windows::Forms::TextBox^ textBox10;
private: System::Windows::Forms::TextBox^ textBox11;
private: System::Windows::Forms::TextBox^ textBox12;
private: System::Windows::Forms::TextBox^ textBox13;
private: System::Windows::Forms::TextBox^ textBox14;
private: System::Windows::Forms::TextBox^ textBox15;
private: System::Windows::Forms::TextBox^ textBox16;
private: System::Windows::Forms::TextBox^ textBox17;
private: System::Windows::Forms::TextBox^ textBox18;
private: System::Windows::Forms::TextBox^ textBox19;
private: System::Windows::Forms::TextBox^ textBox20;
private: System::Windows::Forms::TabControl^ tabControl1;
private: System::Windows::Forms::TabPage^ tabPage1;
private: System::Windows::Forms::TabPage^ tabPage2;
private: System::Windows::Forms::Button^ button5;
private: System::Windows::Forms::LinkLabel^ linkLabel1;
private: System::Windows::Forms::LinkLabel^ linkLabel2;
private: System::Windows::Forms::Label^ label48;


private: System::Windows::Forms::TextBox^ textBox2;
private: System::Windows::Forms::ListBox^ listBox1;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1_filterSI = (gcnew System::Windows::Forms::Panel());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
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
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->panel2_responses = (gcnew System::Windows::Forms::Panel());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->panel3_viewer = (gcnew System::Windows::Forms::Panel());
			this->linkLabel2 = (gcnew System::Windows::Forms::LinkLabel());
			this->label48 = (gcnew System::Windows::Forms::Label());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->_lb1 = (gcnew System::Windows::Forms::ListBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->_lb2 = (gcnew System::Windows::Forms::ListBox());
			this->textBox20 = (gcnew System::Windows::Forms::TextBox());
			this->textBox19 = (gcnew System::Windows::Forms::TextBox());
			this->textBox18 = (gcnew System::Windows::Forms::TextBox());
			this->textBox17 = (gcnew System::Windows::Forms::TextBox());
			this->textBox16 = (gcnew System::Windows::Forms::TextBox());
			this->textBox15 = (gcnew System::Windows::Forms::TextBox());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->panel1_filterSI->SuspendLayout();
			this->panel2_responses->SuspendLayout();
			this->panel3_viewer->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(11, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(782, 36);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Фильтр поиска СИ";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel1_filterSI
			// 
			this->panel1_filterSI->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1_filterSI->Controls->Add(this->textBox2);
			this->panel1_filterSI->Controls->Add(this->comboBox1);
			this->panel1_filterSI->Controls->Add(this->button2);
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
			this->panel1_filterSI->Location = System::Drawing::Point(0, 10);
			this->panel1_filterSI->Name = L"panel1_filterSI";
			this->panel1_filterSI->Size = System::Drawing::Size(802, 629);
			this->panel1_filterSI->TabIndex = 1;
			this->panel1_filterSI->Layout += gcnew System::Windows::Forms::LayoutEventHandler(this, &MyForm::panel1_filterSI_Layout);
			// 
			// textBox2
			// 
			this->textBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(344, 143);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(438, 24);
			this->textBox2->TabIndex = 28;
			// 
			// comboBox1
			// 
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(344, 101);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(152, 26);
			this->comboBox1->TabIndex = 27;
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(569, 557);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(141, 23);
			this->button2->TabIndex = 26;
			this->button2->Text = L"Очистить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// dateTimePicker3
			// 
			this->dateTimePicker3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->dateTimePicker3->Location = System::Drawing::Point(568, 449);
			this->dateTimePicker3->Name = L"dateTimePicker3";
			this->dateTimePicker3->Size = System::Drawing::Size(166, 24);
			this->dateTimePicker3->TabIndex = 25;
			this->dateTimePicker3->ValueChanged += gcnew System::EventHandler(this, &MyForm::dateTimePicker3_ValueChanged);
			// 
			// dateTimePicker4
			// 
			this->dateTimePicker4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->dateTimePicker4->Location = System::Drawing::Point(344, 449);
			this->dateTimePicker4->Name = L"dateTimePicker4";
			this->dateTimePicker4->Size = System::Drawing::Size(175, 24);
			this->dateTimePicker4->TabIndex = 24;
			this->dateTimePicker4->ValueChanged += gcnew System::EventHandler(this, &MyForm::dateTimePicker4_ValueChanged);
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->dateTimePicker2->Location = System::Drawing::Point(566, 405);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(168, 24);
			this->dateTimePicker2->TabIndex = 23;
			this->dateTimePicker2->ValueChanged += gcnew System::EventHandler(this, &MyForm::dateTimePicker2_ValueChanged);
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Checked = false;
			this->dateTimePicker1->CustomFormat = L" ";
			this->dateTimePicker1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->dateTimePicker1->Location = System::Drawing::Point(344, 405);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(173, 24);
			this->dateTimePicker1->TabIndex = 22;
			this->dateTimePicker1->ValueChanged += gcnew System::EventHandler(this, &MyForm::dateTimePicker1_ValueChanged);
			// 
			// textBox8
			// 
			this->textBox8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox8->Location = System::Drawing::Point(344, 495);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(438, 24);
			this->textBox8->TabIndex = 19;
			// 
			// textBox7
			// 
			this->textBox7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox7->Location = System::Drawing::Point(344, 363);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(438, 24);
			this->textBox7->TabIndex = 18;
			// 
			// textBox6
			// 
			this->textBox6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox6->Location = System::Drawing::Point(344, 319);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(438, 24);
			this->textBox6->TabIndex = 17;
			// 
			// textBox5
			// 
			this->textBox5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox5->Location = System::Drawing::Point(344, 275);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(438, 24);
			this->textBox5->TabIndex = 16;
			// 
			// textBox4
			// 
			this->textBox4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox4->Location = System::Drawing::Point(344, 231);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(438, 24);
			this->textBox4->TabIndex = 15;
			// 
			// textBox3
			// 
			this->textBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(344, 182);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(438, 24);
			this->textBox3->TabIndex = 14;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(344, 557);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(141, 23);
			this->button1->TabIndex = 11;
			this->button1->Text = L"Поиск";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label11->Location = System::Drawing::Point(62, 498);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(163, 18);
			this->label11->TabIndex = 10;
			this->label11->Text = L"Номер свидетельства";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->Location = System::Drawing::Point(62, 454);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(137, 18);
			this->label10->TabIndex = 9;
			this->label10->Text = L"Действительна до";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(62, 410);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(104, 18);
			this->label9->TabIndex = 8;
			this->label9->Text = L"Дата поверки";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(62, 366);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(133, 18);
			this->label8->TabIndex = 7;
			this->label8->Text = L"Заводской номер";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(62, 322);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(134, 18);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Модификация СИ";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(62, 278);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(59, 18);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Тип СИ";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(62, 234);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(172, 18);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Наименование типа СИ";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(62, 190);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(240, 18);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Регистрационный номер типа СИ";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(62, 146);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(184, 18);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Организация-поверитель";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(62, 102);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(182, 18);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Год проведения поверки";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label13->Location = System::Drawing::Point(48, 15);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(137, 18);
			this->label13->TabIndex = 2;
			this->label13->Text = L"Найдено записей: ";
			// 
			// listBox1
			// 
			this->listBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->listBox1->BackColor = System::Drawing::SystemColors::Control;
			this->listBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->HorizontalScrollbar = true;
			this->listBox1->ItemHeight = 15;
			this->listBox1->Location = System::Drawing::Point(3, 46);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(792, 379);
			this->listBox1->TabIndex = 3;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox1_SelectedIndexChanged);
			// 
			// panel2_responses
			// 
			this->panel2_responses->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel2_responses->Controls->Add(this->button3);
			this->panel2_responses->Controls->Add(this->label13);
			this->panel2_responses->Controls->Add(this->listBox1);
			this->panel2_responses->Location = System::Drawing::Point(0, 10);
			this->panel2_responses->Name = L"panel2_responses";
			this->panel2_responses->Size = System::Drawing::Size(802, 629);
			this->panel2_responses->TabIndex = 4;
			this->panel2_responses->Visible = false;
			// 
			// button3
			// 
			this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button3->Location = System::Drawing::Point(671, 594);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(111, 23);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Назад";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// panel3_viewer
			// 
			this->panel3_viewer->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel3_viewer->BackColor = System::Drawing::SystemColors::Control;
			this->panel3_viewer->Controls->Add(this->label21);
			this->panel3_viewer->Controls->Add(this->linkLabel2);
			this->panel3_viewer->Controls->Add(this->label48);
			this->panel3_viewer->Controls->Add(this->linkLabel1);
			this->panel3_viewer->Controls->Add(this->button5);
			this->panel3_viewer->Controls->Add(this->tabControl1);
			this->panel3_viewer->Controls->Add(this->textBox20);
			this->panel3_viewer->Controls->Add(this->textBox19);
			this->panel3_viewer->Controls->Add(this->textBox18);
			this->panel3_viewer->Controls->Add(this->textBox17);
			this->panel3_viewer->Controls->Add(this->textBox16);
			this->panel3_viewer->Controls->Add(this->textBox15);
			this->panel3_viewer->Controls->Add(this->textBox14);
			this->panel3_viewer->Controls->Add(this->textBox13);
			this->panel3_viewer->Controls->Add(this->textBox12);
			this->panel3_viewer->Controls->Add(this->textBox11);
			this->panel3_viewer->Controls->Add(this->textBox10);
			this->panel3_viewer->Controls->Add(this->textBox9);
			this->panel3_viewer->Controls->Add(this->button4);
			this->panel3_viewer->Controls->Add(this->label28);
			this->panel3_viewer->Controls->Add(this->label27);
			this->panel3_viewer->Controls->Add(this->label26);
			this->panel3_viewer->Controls->Add(this->label25);
			this->panel3_viewer->Controls->Add(this->label24);
			this->panel3_viewer->Controls->Add(this->label23);
			this->panel3_viewer->Controls->Add(this->label22);
			this->panel3_viewer->Controls->Add(this->label20);
			this->panel3_viewer->Controls->Add(this->label19);
			this->panel3_viewer->Controls->Add(this->label18);
			this->panel3_viewer->Controls->Add(this->label17);
			this->panel3_viewer->Controls->Add(this->label16);
			this->panel3_viewer->Controls->Add(this->label15);
			this->panel3_viewer->Controls->Add(this->label14);
			this->panel3_viewer->Controls->Add(this->label12);
			this->panel3_viewer->Location = System::Drawing::Point(0, 10);
			this->panel3_viewer->Name = L"panel3_viewer";
			this->panel3_viewer->Size = System::Drawing::Size(802, 629);
			this->panel3_viewer->TabIndex = 27;
			this->panel3_viewer->Visible = false;
			// 
			// linkLabel2
			// 
			this->linkLabel2->AutoSize = true;
			this->linkLabel2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->linkLabel2->Location = System::Drawing::Point(566, 33);
			this->linkLabel2->Name = L"linkLabel2";
			this->linkLabel2->Size = System::Drawing::Size(56, 14);
			this->linkLabel2->TabIndex = 57;
			this->linkLabel2->TabStop = true;
			this->linkLabel2->Text = L"linkLabel2";
			this->linkLabel2->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MyForm::linkLabel2_LinkClicked);
			// 
			// label48
			// 
			this->label48->AutoSize = true;
			this->label48->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label48->Location = System::Drawing::Point(361, 33);
			this->label48->Name = L"label48";
			this->label48->Size = System::Drawing::Size(181, 16);
			this->label48->TabIndex = 56;
			this->label48->Text = L"Номер записи в ФИФ ОЕИ";
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->linkLabel1->Location = System::Drawing::Point(258, 33);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(56, 14);
			this->linkLabel1->TabIndex = 55;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"linkLabel1";
			this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MyForm::linkLabel1_LinkClicked);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(549, 598);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(116, 23);
			this->button5->TabIndex = 53;
			this->button5->Text = L"Вывести на печать";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tabControl1->Location = System::Drawing::Point(11, 389);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(775, 203);
			this->tabControl1->TabIndex = 52;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->_lb1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(767, 177);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Средства поверки";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// _lb1
			// 
			this->_lb1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_lb1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->_lb1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->_lb1->FormattingEnabled = true;
			this->_lb1->HorizontalScrollbar = true;
			this->_lb1->ItemHeight = 15;
			this->_lb1->Location = System::Drawing::Point(0, 0);
			this->_lb1->Name = L"_lb1";
			this->_lb1->Size = System::Drawing::Size(767, 165);
			this->_lb1->TabIndex = 36;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->_lb2);
			this->tabPage2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(767, 177);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Дополнительные сведения";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// _lb2
			// 
			this->_lb2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_lb2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->_lb2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->_lb2->FormattingEnabled = true;
			this->_lb2->HorizontalScrollbar = true;
			this->_lb2->ItemHeight = 15;
			this->_lb2->Location = System::Drawing::Point(0, 0);
			this->_lb2->Name = L"_lb2";
			this->_lb2->Size = System::Drawing::Size(771, 165);
			this->_lb2->TabIndex = 38;
			// 
			// textBox20
			// 
			this->textBox20->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox20->Location = System::Drawing::Point(671, 364);
			this->textBox20->Name = L"textBox20";
			this->textBox20->ReadOnly = true;
			this->textBox20->Size = System::Drawing::Size(115, 21);
			this->textBox20->TabIndex = 51;
			this->textBox20->TabStop = false;
			// 
			// textBox19
			// 
			this->textBox19->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox19->Location = System::Drawing::Point(221, 364);
			this->textBox19->Name = L"textBox19";
			this->textBox19->ReadOnly = true;
			this->textBox19->Size = System::Drawing::Size(100, 21);
			this->textBox19->TabIndex = 50;
			this->textBox19->TabStop = false;
			// 
			// textBox18
			// 
			this->textBox18->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox18->Location = System::Drawing::Point(221, 336);
			this->textBox18->Name = L"textBox18";
			this->textBox18->ReadOnly = true;
			this->textBox18->Size = System::Drawing::Size(308, 21);
			this->textBox18->TabIndex = 49;
			this->textBox18->TabStop = false;
			// 
			// textBox17
			// 
			this->textBox17->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox17->Location = System::Drawing::Point(671, 336);
			this->textBox17->Name = L"textBox17";
			this->textBox17->ReadOnly = true;
			this->textBox17->Size = System::Drawing::Size(115, 21);
			this->textBox17->TabIndex = 48;
			this->textBox17->TabStop = false;
			// 
			// textBox16
			// 
			this->textBox16->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox16->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox16->Location = System::Drawing::Point(221, 275);
			this->textBox16->Multiline = true;
			this->textBox16->Name = L"textBox16";
			this->textBox16->ReadOnly = true;
			this->textBox16->Size = System::Drawing::Size(565, 55);
			this->textBox16->TabIndex = 47;
			this->textBox16->TabStop = false;
			// 
			// textBox15
			// 
			this->textBox15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox15->Location = System::Drawing::Point(569, 210);
			this->textBox15->Name = L"textBox15";
			this->textBox15->ReadOnly = true;
			this->textBox15->Size = System::Drawing::Size(100, 21);
			this->textBox15->TabIndex = 46;
			this->textBox15->TabStop = false;
			// 
			// textBox14
			// 
			this->textBox14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox14->Location = System::Drawing::Point(219, 210);
			this->textBox14->Name = L"textBox14";
			this->textBox14->ReadOnly = true;
			this->textBox14->Size = System::Drawing::Size(110, 21);
			this->textBox14->TabIndex = 45;
			this->textBox14->TabStop = false;
			// 
			// textBox13
			// 
			this->textBox13->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox13->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox13->Location = System::Drawing::Point(219, 236);
			this->textBox13->Multiline = true;
			this->textBox13->Name = L"textBox13";
			this->textBox13->ReadOnly = true;
			this->textBox13->Size = System::Drawing::Size(567, 32);
			this->textBox13->TabIndex = 44;
			this->textBox13->TabStop = false;
			// 
			// textBox12
			// 
			this->textBox12->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox12->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox12->Location = System::Drawing::Point(177, 129);
			this->textBox12->Name = L"textBox12";
			this->textBox12->ReadOnly = true;
			this->textBox12->Size = System::Drawing::Size(609, 21);
			this->textBox12->TabIndex = 43;
			this->textBox12->TabStop = false;
			// 
			// textBox11
			// 
			this->textBox11->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox11->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox11->Location = System::Drawing::Point(177, 155);
			this->textBox11->Name = L"textBox11";
			this->textBox11->ReadOnly = true;
			this->textBox11->Size = System::Drawing::Size(609, 21);
			this->textBox11->TabIndex = 42;
			this->textBox11->TabStop = false;
			// 
			// textBox10
			// 
			this->textBox10->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox10->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox10->Location = System::Drawing::Point(177, 84);
			this->textBox10->Multiline = true;
			this->textBox10->Name = L"textBox10";
			this->textBox10->ReadOnly = true;
			this->textBox10->Size = System::Drawing::Size(609, 40);
			this->textBox10->TabIndex = 41;
			this->textBox10->TabStop = false;
			// 
			// textBox9
			// 
			this->textBox9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox9->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox9->Location = System::Drawing::Point(177, 58);
			this->textBox9->Name = L"textBox9";
			this->textBox9->ReadOnly = true;
			this->textBox9->Size = System::Drawing::Size(609, 21);
			this->textBox9->TabIndex = 40;
			this->textBox9->TabStop = false;
			// 
			// button4
			// 
			this->button4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button4->Location = System::Drawing::Point(711, 598);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 34;
			this->button4->Text = L"Закрыть";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// label28
			// 
			this->label28->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label28->Location = System::Drawing::Point(500, 365);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(163, 21);
			this->label28->TabIndex = 15;
			this->label28->Text = L"Знак поверки на СИ";
			// 
			// label27
			// 
			this->label27->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label27->Location = System::Drawing::Point(8, 365);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(201, 21);
			this->label27->TabIndex = 14;
			this->label27->Text = L"Знак поверки в паспорте";
			// 
			// label26
			// 
			this->label26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label26->Location = System::Drawing::Point(8, 335);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(213, 22);
			this->label26->TabIndex = 13;
			this->label26->Text = L"Номер свидетельства";
			// 
			// label25
			// 
			this->label25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label25->Location = System::Drawing::Point(566, 338);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(97, 19);
			this->label25->TabIndex = 12;
			this->label25->Text = L"СИ пригодно";
			// 
			// label24
			// 
			this->label24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label24->Location = System::Drawing::Point(8, 276);
			this->label24->MaximumSize = System::Drawing::Size(250, 0);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(207, 0);
			this->label24->TabIndex = 11;
			this->label24->Text = L"Наименование документа, на основании которого выполнена поверка";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label23->Location = System::Drawing::Point(361, 210);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(187, 16);
			this->label23->TabIndex = 10;
			this->label23->Text = L"Поверка действительна до";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label22->Location = System::Drawing::Point(8, 210);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(120, 16);
			this->label22->TabIndex = 9;
			this->label22->Text = L"Дата поверки СИ";
			// 
			// label20
			// 
			this->label20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label20->Location = System::Drawing::Point(8, 236);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(213, 47);
			this->label20->TabIndex = 7;
			this->label20->Text = L"Наименование организации-поверителя";
			// 
			// label19
			// 
			this->label19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label19->Location = System::Drawing::Point(19, 179);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(763, 25);
			this->label19->TabIndex = 6;
			this->label19->Text = L"Сведения о поверке";
			this->label19->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label18->Location = System::Drawing::Point(10, 131);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(122, 16);
			this->label18->TabIndex = 5;
			this->label18->Text = L"Модификация СИ";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label17->Location = System::Drawing::Point(10, 157);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(145, 16);
			this->label17->TabIndex = 4;
			this->label17->Text = L"Заводской номер СИ";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label16->Location = System::Drawing::Point(10, 85);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(163, 16);
			this->label16->TabIndex = 3;
			this->label16->Text = L"Наименование типа СИ";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label15->Location = System::Drawing::Point(10, 59);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(55, 16);
			this->label15->TabIndex = 2;
			this->label15->Text = L"Тип СИ";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label14->Location = System::Drawing::Point(10, 33);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(226, 16);
			this->label14->TabIndex = 1;
			this->label14->Text = L"Регистрационный номер типа СИ";
			// 
			// label12
			// 
			this->label12->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label12->Location = System::Drawing::Point(15, 5);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(778, 20);
			this->label12->TabIndex = 0;
			this->label12->Text = L"Сведения о результатах поверки СИ";
			this->label12->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label21
			// 
			this->label21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label21->Location = System::Drawing::Point(8, 276);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(213, 52);
			this->label21->TabIndex = 58;
			this->label21->Text = L"Наименование документа, на основании которого выполнена поверка";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(805, 645);
			this->Controls->Add(this->panel3_viewer);
			this->Controls->Add(this->panel2_responses);
			this->Controls->Add(this->panel1_filterSI);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"Аршин";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			this->panel1_filterSI->ResumeLayout(false);
			this->panel1_filterSI->PerformLayout();
			this->panel2_responses->ResumeLayout(false);
			this->panel2_responses->PerformLayout();
			this->panel3_viewer->ResumeLayout(false);
			this->panel3_viewer->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->ResumeLayout(false);

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
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	comboBox1->Items->Add(DateTime::Now.Year);
	comboBox1->Items->Add(DateTime::Now.Year - 1);
	comboBox1->Items->Add(DateTime::Now.Year - 2);
	comboBox1->Items->Add(DateTime::Now.Year - 3);
	comboBox1->Items->Add(DateTime::Now.Year - 4);
	comboBox1->Items->Add(DateTime::Now.Year - 5);
	comboBox1->SelectedIndex = 0;
};
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e);

	   //вывод на печать
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	print_form->Show();
	this->Hide();
}

//открытие ссылки по клику на ГР
private: System::Void linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	System::Diagnostics::Process::Start(e->Link->LinkData->ToString());
}
//открытие ссылки по клику на номере записи
private: System::Void linkLabel2_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	System::Diagnostics::Process::Start(e->Link->LinkData->ToString());
}

//нажатие button1 (поиск на фильтре) если нажат ентер
private: System::Void MyForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (panel1_filterSI->Visible == true && e->KeyCode == Keys::Enter) {
		button1->PerformClick();
	}
}
};
//
String^ getVriType(const int vri_id) {
	if (vResponses[vri_id]->_vri_info->_vriType == "2")
		return "периодической";
	else
		return "первичной";
}
String^ getApplay(const int vri_id) {
	if (vResponses[vri_id]->_result->get_applicability_bool())
		return "пригодным";
	else
		return "не пригодным";
}
//удалятель обратной косой черты
void backslash_del(std::string& str) {
	while (str.find('\\', 0) != std::string::npos) {
		str.erase(str.find('\\'), 1);
	}
}
//добавление косой черты перед кавычкой " и тире -
std::string backslash_add(const std::string& str) {
	std::string return_str = str;
	size_t it = 0;
	while (return_str.find_first_of("\"-", it) != std::string::npos) {
		it = return_str.find_first_of("\"-", it);
		return_str.insert(it, 1, '\\');
		it += 2;
	}
	return return_str;
}

//очистка вектора найденных СИ
void vResponsesClear() {
	if (!vResponses.empty()) {
		for (std::vector<Response*>::iterator ib = vResponses.begin(); ib != vResponses.end(); ++ib) {
			delete* ib;
		}
		vResponses.resize(0);
	}
}

}

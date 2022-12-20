#pragma once

namespace Arshin {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для PrintForm
	/// </summary>
	public ref class PrintForm : public System::Windows::Forms::Form
	{
	public:
		PrintForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		void setIzvVisible(bool);
		void setIzvOrSvd(String^ str);
		void setVrfDate(String^ str);
		void setValidDate(String^ str);
		void setSI(String^ str);
		void setZNum(String^ str);
		void setOrg(String^ str);
		void setDocTitle(String^ str);
		void setVriURL(String^ str);
		void setEtalons(String^ str);
		void setStructure(String^ str);
		void setBriefCharacter(String^ str);
		void setAddInfo(String^ str);
		void setVriType(String^ str);
		void setZakluchenie(String^ str);
		void ClearPrintForm();
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~PrintForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel_PrintV;
	protected:
	private: System::Windows::Forms::Label^ label35;
	private: System::Windows::Forms::Label^ label53;
	private: System::Windows::Forms::Label^ label52;
	private: System::Windows::Forms::Label^ label51;
	private: System::Windows::Forms::Label^ label50;
	private: System::Windows::Forms::Label^ label49;
	private: System::Windows::Forms::Label^ label47;
	private: System::Windows::Forms::Label^ label46;
	private: System::Windows::Forms::Label^ label45;
	private: System::Windows::Forms::Label^ label44;
	private: System::Windows::Forms::Label^ label43;
	private: System::Windows::Forms::Label^ label42;
	private: System::Windows::Forms::Label^ label41;
	private: System::Windows::Forms::Label^ label40;
	private: System::Windows::Forms::Label^ label39;
	private: System::Windows::Forms::Label^ label38;
	private: System::Windows::Forms::Label^ label37;
	private: System::Windows::Forms::Label^ label36;
	private: System::Windows::Forms::Label^ label34;
	private: System::Windows::Forms::Label^ label33;
	private: System::Windows::Forms::Label^ label31;
	private: System::Windows::Forms::Label^ label29;
	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button8;
	private: System::Drawing::Printing::PrintDocument^ printDocument1;
	private: System::Windows::Forms::PageSetupDialog^ pageSetupDialog1;
	private: System::Windows::Forms::PrintDialog^ printDialog1;
	private: System::Windows::Forms::PrintPreviewDialog^ printPreviewDialog1;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(PrintForm::typeid));
			this->panel_PrintV = (gcnew System::Windows::Forms::Panel());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->label53 = (gcnew System::Windows::Forms::Label());
			this->label52 = (gcnew System::Windows::Forms::Label());
			this->label51 = (gcnew System::Windows::Forms::Label());
			this->label50 = (gcnew System::Windows::Forms::Label());
			this->label49 = (gcnew System::Windows::Forms::Label());
			this->label47 = (gcnew System::Windows::Forms::Label());
			this->label46 = (gcnew System::Windows::Forms::Label());
			this->label45 = (gcnew System::Windows::Forms::Label());
			this->label44 = (gcnew System::Windows::Forms::Label());
			this->label43 = (gcnew System::Windows::Forms::Label());
			this->label42 = (gcnew System::Windows::Forms::Label());
			this->label41 = (gcnew System::Windows::Forms::Label());
			this->label40 = (gcnew System::Windows::Forms::Label());
			this->label39 = (gcnew System::Windows::Forms::Label());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->printDocument1 = (gcnew System::Drawing::Printing::PrintDocument());
			this->pageSetupDialog1 = (gcnew System::Windows::Forms::PageSetupDialog());
			this->printDialog1 = (gcnew System::Windows::Forms::PrintDialog());
			this->printPreviewDialog1 = (gcnew System::Windows::Forms::PrintPreviewDialog());
			this->panel_PrintV->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel_PrintV
			// 
			this->panel_PrintV->BackColor = System::Drawing::SystemColors::HighlightText;
			this->panel_PrintV->Controls->Add(this->label35);
			this->panel_PrintV->Controls->Add(this->label53);
			this->panel_PrintV->Controls->Add(this->label52);
			this->panel_PrintV->Controls->Add(this->label51);
			this->panel_PrintV->Controls->Add(this->label50);
			this->panel_PrintV->Controls->Add(this->label49);
			this->panel_PrintV->Controls->Add(this->label47);
			this->panel_PrintV->Controls->Add(this->label46);
			this->panel_PrintV->Controls->Add(this->label45);
			this->panel_PrintV->Controls->Add(this->label44);
			this->panel_PrintV->Controls->Add(this->label43);
			this->panel_PrintV->Controls->Add(this->label42);
			this->panel_PrintV->Controls->Add(this->label41);
			this->panel_PrintV->Controls->Add(this->label40);
			this->panel_PrintV->Controls->Add(this->label39);
			this->panel_PrintV->Controls->Add(this->label38);
			this->panel_PrintV->Controls->Add(this->label37);
			this->panel_PrintV->Controls->Add(this->label36);
			this->panel_PrintV->Controls->Add(this->label34);
			this->panel_PrintV->Controls->Add(this->label33);
			this->panel_PrintV->Controls->Add(this->label31);
			this->panel_PrintV->Controls->Add(this->label29);
			this->panel_PrintV->Controls->Add(this->label21);
			this->panel_PrintV->Location = System::Drawing::Point(0, 0);
			this->panel_PrintV->Name = L"panel_PrintV";
			this->panel_PrintV->Size = System::Drawing::Size(711, 1005);
			this->panel_PrintV->TabIndex = 30;
			// 
			// label35
			// 
			this->label35->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label35->Location = System::Drawing::Point(135, 884);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(124, 20);
			this->label35->TabIndex = 24;
			// 
			// label53
			// 
			this->label53->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label53->Location = System::Drawing::Point(584, 175);
			this->label53->Name = L"label53";
			this->label53->Size = System::Drawing::Size(113, 20);
			this->label53->TabIndex = 23;
			// 
			// label52
			// 
			this->label52->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label52->Location = System::Drawing::Point(172, 533);
			this->label52->Name = L"label52";
			this->label52->Size = System::Drawing::Size(525, 196);
			this->label52->TabIndex = 22;
			// 
			// label51
			// 
			this->label51->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label51->Location = System::Drawing::Point(172, 468);
			this->label51->Name = L"label51";
			this->label51->Size = System::Drawing::Size(525, 40);
			this->label51->TabIndex = 21;
			// 
			// label50
			// 
			this->label50->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label50->Location = System::Drawing::Point(172, 424);
			this->label50->Name = L"label50";
			this->label50->Size = System::Drawing::Size(525, 20);
			this->label50->TabIndex = 20;
			// 
			// label49
			// 
			this->label49->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label49->Location = System::Drawing::Point(172, 381);
			this->label49->Name = L"label49";
			this->label49->Size = System::Drawing::Size(525, 20);
			this->label49->TabIndex = 19;
			// 
			// label47
			// 
			this->label47->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label47->Location = System::Drawing::Point(172, 336);
			this->label47->Name = L"label47";
			this->label47->Size = System::Drawing::Size(525, 20);
			this->label47->TabIndex = 17;
			this->label47->Text = L"-";
			// 
			// label46
			// 
			this->label46->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label46->Location = System::Drawing::Point(172, 293);
			this->label46->Name = L"label46";
			this->label46->Size = System::Drawing::Size(525, 20);
			this->label46->TabIndex = 16;
			// 
			// label45
			// 
			this->label45->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label45->Location = System::Drawing::Point(18, 918);
			this->label45->Name = L"label45";
			this->label45->Size = System::Drawing::Size(679, 79);
			this->label45->TabIndex = 15;
			// 
			// label44
			// 
			this->label44->AutoSize = true;
			this->label44->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label44->Location = System::Drawing::Point(15, 339);
			this->label44->Name = L"label44";
			this->label44->Size = System::Drawing::Size(72, 19);
			this->label44->TabIndex = 14;
			this->label44->Text = L"в составе";
			// 
			// label43
			// 
			this->label43->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label43->Location = System::Drawing::Point(19, 832);
			this->label43->Name = L"label43";
			this->label43->Size = System::Drawing::Size(678, 20);
			this->label43->TabIndex = 13;
			// 
			// label42
			// 
			this->label42->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label42->Location = System::Drawing::Point(18, 750);
			this->label42->Name = L"label42";
			this->label42->Size = System::Drawing::Size(679, 66);
			this->label42->TabIndex = 12;
			// 
			// label41
			// 
			this->label41->AutoSize = true;
			this->label41->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label41->Location = System::Drawing::Point(15, 427);
			this->label41->Name = L"label41";
			this->label41->Size = System::Drawing::Size(94, 19);
			this->label41->TabIndex = 11;
			this->label41->Text = L"тип поверки";
			// 
			// label40
			// 
			this->label40->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label40->Location = System::Drawing::Point(172, 205);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(525, 65);
			this->label40->TabIndex = 10;
			// 
			// label39
			// 
			this->label39->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label39->Location = System::Drawing::Point(15, 883);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(114, 15);
			this->label39->TabIndex = 9;
			this->label39->Text = L"Дата поверки";
			// 
			// label38
			// 
			this->label38->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label38->Location = System::Drawing::Point(15, 536);
			this->label38->MaximumSize = System::Drawing::Size(114, 40);
			this->label38->MinimumSize = System::Drawing::Size(114, 20);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(114, 40);
			this->label38->TabIndex = 8;
			this->label38->Text = L"с применением эталонов";
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label37->Location = System::Drawing::Point(15, 471);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(124, 19);
			this->label37->TabIndex = 7;
			this->label37->Text = L"в соответствии с";
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label36->Location = System::Drawing::Point(15, 384);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(73, 19);
			this->label36->TabIndex = 6;
			this->label36->Text = L"поверено";
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label34->Location = System::Drawing::Point(15, 296);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(122, 19);
			this->label34->TabIndex = 4;
			this->label34->Text = L"заводской номер";
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label33->Location = System::Drawing::Point(15, 208);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(151, 19);
			this->label33->TabIndex = 3;
			this->label33->Text = L"Средство измерений";
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label31->Location = System::Drawing::Point(442, 174);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(136, 19);
			this->label31->TabIndex = 2;
			this->label31->Text = L"Действительно до:";
			// 
			// label29
			// 
			this->label29->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label29->Location = System::Drawing::Point(18, 114);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(679, 25);
			this->label29->TabIndex = 1;
			this->label29->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label21
			// 
			this->label21->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label21->AutoEllipsis = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label21->Location = System::Drawing::Point(18, 10);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(679, 80);
			this->label21->TabIndex = 0;
			this->label21->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(739, 47);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(115, 23);
			this->button10->TabIndex = 33;
			this->button10->Text = L"Сохранить в файл";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &PrintForm::button10_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(739, 81);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(115, 23);
			this->button7->TabIndex = 32;
			this->button7->Text = L"Настройка печати";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &PrintForm::button7_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(739, 114);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(115, 23);
			this->button6->TabIndex = 31;
			this->button6->Text = L"Печатать";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &PrintForm::button6_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(739, 181);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(115, 23);
			this->button9->TabIndex = 35;
			this->button9->Text = L"Отмена";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &PrintForm::button9_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(739, 148);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(115, 23);
			this->button8->TabIndex = 34;
			this->button8->Text = L"Просмотр";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &PrintForm::button8_Click);
			// 
			// printDocument1
			// 
			this->printDocument1->PrintPage += gcnew System::Drawing::Printing::PrintPageEventHandler(this, &PrintForm::printDocument1_PrintPage);
			// 
			// pageSetupDialog1
			// 
			this->pageSetupDialog1->Document = this->printDocument1;
			// 
			// printDialog1
			// 
			this->printDialog1->Document = this->printDocument1;
			this->printDialog1->UseEXDialog = true;
			// 
			// printPreviewDialog1
			// 
			this->printPreviewDialog1->AutoScrollMargin = System::Drawing::Size(0, 0);
			this->printPreviewDialog1->AutoScrollMinSize = System::Drawing::Size(0, 0);
			this->printPreviewDialog1->ClientSize = System::Drawing::Size(400, 300);
			this->printPreviewDialog1->Document = this->printDocument1;
			this->printPreviewDialog1->Enabled = true;
			this->printPreviewDialog1->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"printPreviewDialog1.Icon")));
			this->printPreviewDialog1->Name = L"printPreviewDialog1";
			this->printPreviewDialog1->Visible = false;
			// 
			// PrintForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(876, 1006);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->panel_PrintV);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(821, 683);
			this->Name = L"PrintForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Окно просмотра бланка на печать";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &PrintForm::PrintForm_FormClosing);
			this->panel_PrintV->ResumeLayout(false);
			this->panel_PrintV->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		//обработчик печати
	private: System::Void printDocument1_PrintPage(System::Object^ sender, System::Drawing::Printing::PrintPageEventArgs^ e) {
		System::Drawing::Bitmap^ _bm = gcnew System::Drawing::Bitmap(panel_PrintV->ClientRectangle.Width, panel_PrintV->ClientRectangle.Height);
		panel_PrintV->DrawToBitmap(_bm, panel_PrintV->ClientRectangle);
		int pbWidth = e->MarginBounds.Width;
		int pbHeight = e->MarginBounds.Height;
		int ImageWidth = _bm->Width;
		int ImageHeight = _bm->Height;
		System::Drawing::SizeF _sf(ImageWidth / _bm->HorizontalResolution, ImageHeight / _bm->VerticalResolution);
		float fSale = Math::Min(pbWidth / _sf.Width, pbHeight / _sf.Height);
		_sf.Width *= fSale;
		_sf.Height *= fSale;
		System::Drawing::Size _size = System::Drawing::Size::Ceiling(_sf);
		System::Drawing::Rectangle^ _rect = gcnew System::Drawing::Rectangle(e->MarginBounds.Location.X, e->MarginBounds.Location.Y, _size.Width, _size.Height);
		e->Graphics->DrawImage(_bm, *_rect);
	}
		   //настройка печати
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	pageSetupDialog1->ShowDialog();
}
	   //собсна печать
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	if (printDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		printDocument1->Print();
	}
}
	   //предварительный просмотр печати
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
	printPreviewDialog1->ShowDialog();
}
	   //кнопка Отмена печати
private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
	this->Hide();
	Application::OpenForms[0]->Show();
}
private: System::Void PrintForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	e->Cancel = true;
	this->Hide();
	//Form^ ifrm = Application::OpenForms[0];
	//ifrm->Show();
	Application::OpenForms[0]->Show();
}

	   //сохранить в файл
private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
	SaveFileDialog^ sf1 = gcnew SaveFileDialog();
	sf1->Title = "Сохранить как... ";
	sf1->Filter = "Image Files(*.BMP)|*.BMP|Image Files(*.JPG)|*.JPG|ImageFiles(*.GIF)|*.GIF|Image Files(*.PNG)|*.PNG|All files (*.*)|*.*";
	//sf1->DefaultExt = "*.png";
	sf1->InitialDirectory = System::Environment::CurrentDirectory;
	sf1->OverwritePrompt = true; //предупреждение, если такой файл уже есть
	sf1->CheckPathExists = true; //предупреждает, если такой папки нет
	if (sf1->ShowDialog() == System::Windows::Forms::DialogResult::OK && sf1->FileName->Length > 0) {
		try {
			System::Drawing::Rectangle erect = System::Drawing::Rectangle(0, 0, 2481, 3507); //А4 в пикселях при разрешении 300 точек
			System::Drawing::Bitmap^ bm = gcnew System::Drawing::Bitmap(panel_PrintV->ClientRectangle.Width, panel_PrintV->ClientRectangle.Height);
			panel_PrintV->DrawToBitmap(bm, erect);
			bm->Save(sf1->FileName, System::Drawing::Imaging::ImageFormat::Png);
		}
		catch (Exception^ ex) {
			MessageBox::Show("При сохранении картинки, что-то пошло не так... " + ex->Message, "КРИТИЧЕСКАЯ ОШИБКА!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}
};
}

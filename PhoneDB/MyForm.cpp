#include "MyForm.h"

using namespace ProjectCLR; //name of your project

[STAThreadAttribute]
int main(array<System::String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    Application::Run(gcnew MyForm());
    return 0;
}

DataTable^ ProjectCLR::MyForm::fillDataTable() {
    DataTable^ table;
    try {
        SQLiteCommand^ cmdSelect = db->CreateCommand();
        //�������� ��������, ��� SQL ������ ��������� ��� ������� �������
        cmdSelect->CommandText = "SELECT * FROM fonebase;";
        SQLiteDataReader^ reader = cmdSelect->ExecuteReader();
        //����������
        DataColumn^ column; //������� �������
        DataRow^ row; //������ �������
        //������� ������� ������
        table = gcnew DataTable();
        //������ �������� ��������
        vector<String^>^ nameColumns = gcnew vector<String^>();
        //�������� ������ � ��������
        for (int i = 0; i < reader->FieldCount; i++) {
            nameColumns->push_back(reader->GetName(i));
            column = gcnew DataColumn(nameColumns->at(i), String::typeid);
            table->Columns->Add(column);
        }
        //��������� �� ������ ������
        while (reader->Read()) {
            //��������� ������� �������
            row = table->NewRow();
            //� ������ ������ ��������� �� ���� ��������
            for (int i = 0; i < reader->FieldCount; i++) {
                //��������� �������� ������� � row
                row[nameColumns->at(i)] = reader->GetValue(i)->ToString();
                reader->GetValue(i)->ToString();
            }
            table->Rows->Add(row);
        }
    }
    catch (Exception^ e)
    {
        MessageBox::Show("Error Executing SQL: " + e->ToString(), "Exception While Displaying MyTable ...");
    }
    return table;
}

System::Void ProjectCLR::MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
    try {
        db->ConnectionString = "Data Source=\"" + fileName + "\"";
        db->Open();
        DataTable^ table = fillDataTable();
        dataGridView1->DataSource = table;
        FillColName(); // ��������� ������ ���� �������� ��� � sql-�������
        for (int i = 0; i < ColumnsHeader->size(); ++i) {
            dataGridView1->Columns[i]->HeaderText = ColumnsHeader->at(i);
        }
        seekerComboBox1(); //��������� ComboBox1 ��� ������
        dataGridView1->Columns[0]->Visible = false; //������ ������� _id
        MyForm::button1->Enabled = false; //������ "��������" �� ������� ���� �� ������ �������
    }
    catch (Exception^ e) {
        MessageBox::Show("Error Working SQL: " + e->ToString(), "Exception ...");
    }
    return System::Void();
}
//��������� ������ � ����������� ��������
System::Void ProjectCLR::MyForm::FillColumnsHeader() {
    ColumnsHeader->push_back("�");
    ColumnsHeader->push_back("���"); //0
    ColumnsHeader->push_back("���������"); //1
    ColumnsHeader->push_back("���������"); //2
    ColumnsHeader->push_back("���"); //3
    ColumnsHeader->push_back("�������"); //4
    ColumnsHeader->push_back("��������"); //5
    ColumnsHeader->push_back("������� 1"); //6
    ColumnsHeader->push_back("������� 2"); //7
    ColumnsHeader->push_back("�����"); //8
    ColumnsHeader->push_back("��������� �������"); //9
    ColumnsHeader->push_back("����������"); //10
    return System::Void();
}
//��������� ������ ���� �������� ��� � sql-�������
System::Void ProjectCLR::MyForm::FillColName() {
    for (int i = 0; i < dataGridView1->ColumnCount; ++i)
        ColName->push_back(dataGridView1->Columns[i]->Name);
    return System::Void();
}
//��������� ������ ComboBox1
System::Void ProjectCLR::MyForm::seekerComboBox1() {
    for (int i = 1; i < ColumnsHeader->size(); ++i) {
        MyForm::comboBox1->Items->Add(ColumnsHeader->at(i));
    }
    return System::Void();
}
//��� ������ ������ �������������� ������
System::Void ProjectCLR::MyForm::changing_an_entry() {
    MyForm::button1->Text = L"��������";
    MyForm::groupBox1->Text = L"��������� ������";
    for (int i = 0; i < MyForm::ColName->size() - 1; ++i) {
        MyForm::arrTextBox[i]->Text = MyForm::dataGridView1->CurrentRow->Cells[i + 1]->Value->ToString();
    }
    MyForm::dataGridView1->Visible = false;
    MyForm::panel1->Visible = true;
    MyForm::toolStrip1->Enabled = false;
    MyForm::������ToolStripMenuItem->Enabled = false;
    return System::Void();
}
//��� ������ ������ ���������� ������
System::Void ProjectCLR::MyForm::adding_an_entry() {
    MyForm::dataGridView1->Visible = false;
    MyForm::panel1->Visible = true;
    MyForm::toolStrip1->Enabled = false;
    MyForm::������ToolStripMenuItem->Enabled = false;
    MyForm::groupBox1->Text = L"���������� ����� ������";
    MyForm::button1->Text = L"��������";
    return System::Void();
}
//��� ������ ���� �������� ������
System::Void ProjectCLR::MyForm::deleting_an_entry() {
    MyForm::toolStrip1->Enabled = false;
    MyForm::������ToolStripMenuItem->Enabled = false;
    System::Windows::Forms::DialogResult result = MessageBox::Show(L"�� ����� ������ ������� ��� ������?", L"��������!", MessageBoxButtons::OKCancel);
    if (result == ::DialogResult::OK) {
        String^ id = MyForm::dataGridView1->CurrentRow->Cells[0]->Value->ToString();
        int current_str = dataGridView1->CurrentRow->Index;
        SQLiteCommand^ cmdInsertValue = db->CreateCommand();
        cmdInsertValue->CommandText = "DELETE FROM fonebase WHERE _id = " + id + "; ";
        cmdInsertValue->ExecuteNonQuery();
        DataTable^ table = fillDataTable();
        MyForm::dataGridView1->DataSource = table;
        MyForm::dataGridView1->Columns[0]->Visible = false; //������ ������� _id
        //��������� ���������� ������
        if (current_str >= 1)
            dataGridView1->CurrentCell = dataGridView1[1, current_str - 1];
        else
            dataGridView1->CurrentCell = dataGridView1[1, 1];
    }
    MyForm::toolStrip1->Enabled = true;
    MyForm::������ToolStripMenuItem->Enabled = true;
    return System::Void();
}
//��������� ������ ��������� �� ���������� �������
System::Void ProjectCLR::MyForm::makeVectorHint(vector<String^>^ VectorHint, int numberColumns) {
    bool povtor = false;
    String^ sTemp;
    for (int i = 0; i < dataGridView1->RowCount; ++i) {
        sTemp = dataGridView1->Rows[i]->Cells[numberColumns]->Value->ToString();
        if (!VectorHint->empty()) {
            for (auto& it = VectorHint->begin(); it != VectorHint->end(); ++it) {
                if (*it == sTemp) {
                    povtor = true;
                    break;
                }
            }
        }
        if (povtor == false)
            VectorHint->push_back(sTemp);
        else
            povtor = false;
    }
    return System::Void();
}
//������ �������� ������ �� ������� ���� - ������� ������ � ������ �����
System::Void ProjectCLR::MyForm::toolStripButton1_Click(System::Object^ sender, System::EventArgs^ e) {
    adding_an_entry();
    return System::Void();
}
//������ ������ ����������/�������������� ������
System::Void ProjectCLR::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e) {
    MyForm::dataGridView1->Visible = true;
    MyForm::panel1->Visible = false;
    MyForm::toolStrip1->Enabled = true;
    MyForm::������ToolStripMenuItem->Enabled = true;
    for (int i = 0; i < MyForm::arrTextBox->Length; ++i)
        MyForm::arrTextBox[i]->Text = "";
    return System::Void();
}
//������ ���������� ������ � ��
System::Void ProjectCLR::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        SQLiteCommand^ cmdInsertValue = db->CreateCommand();
        String^ commandSQL;
        String^ colSQL;
        int curr_str = 0; // ���������� ������ ����� �����������
        //���� ��������� ������
        if (MyForm::button1->Text == "��������") {
            bool emptCell = false;
            curr_str = dataGridView1->RowCount;
            for (int i = 0; i < MyForm::ColName->size() - 1; ++i) {
                if (arrTextBox[i]->Text != "") {
                    if (i == 0 || emptCell == false) {
                        commandSQL = "'" + MyForm::arrTextBox[i]->Text->ToString() + "'";
                        colSQL = MyForm::ColName[i + 1]->ToString();
                        emptCell = true;
                    }
                    else {
                        commandSQL += ",'" + MyForm::arrTextBox[i]->Text->ToString() + "'";
                        colSQL += ", " + MyForm::ColName[i + 1]->ToString();
                    }
                    MyForm::arrTextBox[i]->Text = "";
                }
            }
            //������� ���������� ������
            cmdInsertValue->CommandText = "INSERT INTO fonebase (" + colSQL + ") VALUES(" + commandSQL + "); ";
        }
        else {
            //���� ����������� ������
            String^curr_id = MyForm::dataGridView1->CurrentRow->Cells[0]->Value->ToString();
            curr_str = dataGridView1->CurrentRow->Index;
            commandSQL = "UPDATE fonebase SET ";
            for (int i = 0; i < MyForm::ColName->size() - 1; ++i) {
                if (i == 0)
                    commandSQL += MyForm::ColName[i + 1]->ToString() + " = '" + MyForm::arrTextBox[i]->Text->ToString() + "'";
                else
                    commandSQL += ", " + MyForm::ColName[i + 1]->ToString() + " = '" + MyForm::arrTextBox[i]->Text->ToString() + "'";
                MyForm::arrTextBox[i]->Text = "";
            }
            commandSQL += " WHERE _id = " + curr_id + ";";
            cmdInsertValue->CommandText = commandSQL;
        }
        cmdInsertValue->ExecuteNonQuery();
        DataTable^ table = fillDataTable();
        dataGridView1->DataSource = table;
        dataGridView1->Columns[0]->Visible = false; //������ ������� _id
        dataGridView1->CurrentCell = dataGridView1[1, curr_str]; //��������� ���������� ������
        MyForm::dataGridView1->Visible = true;
        MyForm::panel1->Visible = false;
        MyForm::toolStrip1->Enabled = true;
        MyForm::������ToolStripMenuItem->Enabled = true;
    }
    catch (Exception^ e) {
        MessageBox::Show("Error Executing SQL: " + e->ToString(), "Exception ...");
    }
    return System::Void();
}
//��������� ���� ���
System::Void ProjectCLR::MyForm::textBox1_GotFocus(System::Object^ sender, System::EventArgs^ e) {
    int namberColumn = 1; // SPP
    vector<String^>^ vTemp = gcnew vector<String^>();
    makeVectorHint(vTemp, namberColumn);
    for (auto& it = vTemp->begin(); it != vTemp->end(); ++it) {
        MyForm::arrTextBox[0]->AutoCompleteCustomSource->Add(*it);
    }
    return System::Void();
}
//��������� ���� ���������
System::Void ProjectCLR::MyForm::textBox2_GotFocus(System::Object^ sender, System::EventArgs^ e) {
    int namberColumn = 2; // podrazdel
    vector<String^>^ vTemp = gcnew vector<String^>();
    makeVectorHint(vTemp, namberColumn);
    for (auto& it = vTemp->begin(); it != vTemp->end(); ++it) {
        MyForm::arrTextBox[1]->AutoCompleteCustomSource->Add(*it);
    }
    return System::Void();
}
//��������� ���� ���������
System::Void ProjectCLR::MyForm::textBox11_GotFocus(System::Object^ sender, System::EventArgs^ e) {
    int namberColumn = 3; // dolzhnost
    vector<String^>^ vTemp = gcnew vector<String^>();
    makeVectorHint(vTemp, namberColumn);
    for (auto& it = vTemp->begin(); it != vTemp->end(); ++it) {
        MyForm::arrTextBox[2]->AutoCompleteCustomSource->Add(*it);
    }
    return System::Void();
}
//��������� ���� ���
System::Void ProjectCLR::MyForm::textBox4_GotFocus(System::Object^ sender, System::EventArgs^ e) {
    int namberColumn = 4; // fname
    vector<String^>^ vTemp = gcnew vector<String^>();
    makeVectorHint(vTemp, namberColumn);
    for (auto& it = vTemp->begin(); it != vTemp->end(); ++it) {
        MyForm::arrTextBox[3]->AutoCompleteCustomSource->Add(*it);
    }
    return System::Void();
}
//��������� ���� �������
System::Void ProjectCLR::MyForm::textBox3_GotFocus(System::Object^ sender, System::EventArgs^ e) {
    int namberColumn = 5; // sname
    vector<String^>^ vTemp = gcnew vector<String^>();
    makeVectorHint(vTemp, namberColumn);
    for (auto& it = vTemp->begin(); it != vTemp->end(); ++it) {
        MyForm::arrTextBox[4]->AutoCompleteCustomSource->Add(*it);
    }
    return System::Void();
}
//��������� ���� ��������
System::Void ProjectCLR::MyForm::textBox5_GotFocus(System::Object^ sender, System::EventArgs^ e) {
    int namberColumn = 6; // tname
    vector<String^>^ vTemp = gcnew vector<String^>();
    makeVectorHint(vTemp, namberColumn);
    for (auto& it = vTemp->begin(); it != vTemp->end(); ++it) {
        MyForm::arrTextBox[5]->AutoCompleteCustomSource->Add(*it);
    }
    return System::Void();
}
//���������� ������ "��������" � ����������� �� ���� "�������1"
System::Void ProjectCLR::MyForm::textBox8_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    if (arrTextBox[6]->Text != "")
        MyForm::button1->Enabled = true;
    else
        MyForm::button1->Enabled = false;
    return System::Void();
}
//������ "�������������� ������" �� �������� ����
System::Void ProjectCLR::MyForm::toolStripButton2_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        changing_an_entry();
    }
    catch (Exception^ e) {
        MessageBox::Show("Error Working Changing an Entry in toolStripButton2_Click: " + e->ToString(), "Exception ...");
    }
    return System::Void();
}
//������ "�������� ������" �� �������� ����
System::Void ProjectCLR::MyForm::toolStripButton3_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        deleting_an_entry();
    }
    catch (Exception^ e) {
        MessageBox::Show("Error Working Button of Delete: " + e->ToString(), "Exception ...");
    }
    return System::Void();
}
//������ "�����" �� �������� ����
System::Void ProjectCLR::MyForm::toolStripButton4_Click(System::Object^ sender, System::EventArgs^ e) {
    if (MyForm::panel2->Visible == true)
        MyForm::panel2->Visible = false;
    else {
        MyForm::comboBox1->SelectedIndex = 0;
        MyForm::textBox12->Text = "";
        MyForm::panel2->Visible = true;
    }
    return System::Void();
}
//������ "��������" ������2 ������ �� �������� ���� 
System::Void ProjectCLR::MyForm::button3_Click(System::Object^ sender, System::EventArgs^ e) {
    int namberColumn = comboBox1->SelectedIndex;
    BindingSource^ bs = gcnew BindingSource();
    bs->DataSource = dataGridView1->DataSource;
    if(namberColumn)
        bs->Filter = ColName[namberColumn] + " LIKE '%" + textBox12->Text +"%'";
    else {
        String^ temp = ColName[1] + " LIKE '%" + textBox12->Text + "%'";
        for (int i = 2; i < ColName->size(); ++i)
            temp += " OR " + ColName[i] + " LIKE '%" + textBox12->Text + "%'";
        bs->Filter = temp;
    }
    dataGridView1->DataSource = bs;
    //dataGridView1->CurrentCell = dataGridView1->Rows[bs->Position]->Cells[2];
    return System::Void();
}
//��������� ���� ������
System::Void ProjectCLR::MyForm::textBox12_GotFocus(System::Object^ sender, System::EventArgs^ e) {
    int namberColumn = comboBox1->SelectedIndex; //�������� ������ ���������� ���� (0 - ��� �����)
    vector<String^>^ vTemp = gcnew vector<String^>();
    if (namberColumn) {
        makeVectorHint(vTemp, namberColumn);
        for (auto& it = vTemp->begin(); it != vTemp->end(); ++it) 
            MyForm::textBox12->AutoCompleteCustomSource->Add(*it);
    }
    return System::Void();
}
//����� �������
System::Void ProjectCLR::MyForm::button4_Click(System::Object^ sender, System::EventArgs^ e) {
    DataTable^ table = fillDataTable();
    dataGridView1->DataSource = table;
    MyForm::textBox12->Text = "";
    MyForm::comboBox1->SelectedIndex = 0;
    return System::Void();
}
//��������� ���� �� ������
System::Void ProjectCLR::MyForm::importToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
        try {
            System::Data::OleDb::OleDbConnectionStringBuilder^ csbuilder = gcnew System::Data::OleDb::OleDbConnectionStringBuilder;
            csbuilder->Provider = "Microsoft.ACE.OLEDB.12.0";
            csbuilder->DataSource = openFileDialog1->FileName;
            csbuilder->Add("Extended Properties", "Excel 12.0 Xml;HDR=YES");
            System::Data::OleDb::OleDbConnection^ con = gcnew System::Data::OleDb::OleDbConnection(csbuilder->ConnectionString);
            con->Open();
            String^ sqlQuery = "SELECT * FROM [Sheet1$]";
            System::Data::OleDb::OleDbDataAdapter^ datAdapt = gcnew System::Data::OleDb::OleDbDataAdapter(sqlQuery, con);
            DataTable^ dt = gcnew DataTable();
            datAdapt->Fill(dt);
            con->Close();
            //insert into sql db
            SQLiteCommand^ cmdInsertValue = db->CreateCommand();
            for (int i = 1; i < dt->Rows->Count; ++i) {
                sqlQuery = "INSERT INTO fonebase (SPP, podrazdel, dolzhnost, fname, sname, tname, fone1, fone2, tfone, mfone, notes) ";
                sqlQuery += "VALUES('" + dt->Rows[i]->ItemArray[0]->ToString() + "', '" + dt->Rows[i]->ItemArray[1]->ToString() +
                    "', '" + dt->Rows[i]->ItemArray[2]->ToString() + "', '" + dt->Rows[i]->ItemArray[3]->ToString() +
                    "', '" + dt->Rows[i]->ItemArray[4]->ToString() + "', '" + dt->Rows[i]->ItemArray[5]->ToString() +
                    "', '" + dt->Rows[i]->ItemArray[6]->ToString() + "', '" + dt->Rows[i]->ItemArray[7]->ToString() +
                    "', '" + dt->Rows[i]->ItemArray[8]->ToString() + "', '" + dt->Rows[i]->ItemArray[9]->ToString() +
                    "', '" + dt->Rows[i]->ItemArray[10]->ToString() + "');";
                cmdInsertValue->CommandText = sqlQuery;
                cmdInsertValue->ExecuteNonQuery();
            }
            //read sql db in application
            DataTable^ table = fillDataTable();
            dataGridView1->DataSource = table;
        }
        catch (Exception^ e) {
            MessageBox::Show("���-�� ����� �� ���: " + e->ToString(), "�������������� ��������...");
        }
    }
    return System::Void();
}
//��������� ���� � ������
System::Void ProjectCLR::MyForm::exportToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        Microsoft::Office::Interop::Excel::Application^ ExcelApp = gcnew Microsoft::Office::Interop::Excel::ApplicationClass();
        Microsoft::Office::Interop::Excel::Workbook^ ExcelWorkBook = ExcelApp->Workbooks->Add(Type::Missing);// ��������� ����� � 1-�� ���������
        Microsoft::Office::Interop::Excel::Worksheet^ ExcelActiveWorkSheet;// ������� ������ ��� ������ � �������� ���������
        safe_cast<Microsoft::Office::Interop::Excel::Worksheet^>(ExcelApp->ActiveWorkbook->Sheets[1])->Select(Type::Missing);// ������ 1 �������� ��������
        ExcelActiveWorkSheet = safe_cast<Microsoft::Office::Interop::Excel::Worksheet^>(ExcelApp->ActiveSheet);
        ExcelActiveWorkSheet->Name = L"���������� �����";
        safe_cast<Microsoft::Office::Interop::Excel::Worksheet^>(ExcelApp->ActiveWorkbook->Sheets[1])->Select(Type::Missing); // ������ 1 �������� �������� ��� ���������� 
        ExcelActiveWorkSheet = safe_cast<Microsoft::Office::Interop::Excel::Worksheet^>(ExcelApp->ActiveSheet);
        Microsoft::Office::Interop::Excel::Range^ cells_area;
        cells_area = ExcelActiveWorkSheet->Range["A1:K" + (1 + MyForm::dataGridView1->RowCount).ToString(), Type::Missing]; // ���������� ������� ������ ������
        cells_area->HorizontalAlignment = Microsoft::Office::Interop::Excel::XlHAlign::xlHAlignCenter; // ����������� �� ����������� ����� � �������
        cells_area->VerticalAlignment = Microsoft::Office::Interop::Excel::XlVAlign::xlVAlignCenter;  // ����������� �� ��������� ����� � �������
        cells_area->Font->Size = 10;// ������ ������ ������
        cells_area->Font->Name = "Calibri";// ������ �������� ������
        cells_area->Borders[Microsoft::Office::Interop::Excel::XlBordersIndex::xlEdgeBottom]->LineStyle = Microsoft::Office::Interop::Excel::XlLineStyle::xlContinuous;  // ������ ����� ������ ������
        cells_area->Borders[Microsoft::Office::Interop::Excel::XlBordersIndex::xlEdgeTop]->LineStyle = Microsoft::Office::Interop::Excel::XlLineStyle::xlContinuous;  // ������ ����� ������� ������
        cells_area->Borders[Microsoft::Office::Interop::Excel::XlBordersIndex::xlEdgeLeft]->LineStyle = Microsoft::Office::Interop::Excel::XlLineStyle::xlContinuous;  // ������ ����� ����� ������
        cells_area->Borders[Microsoft::Office::Interop::Excel::XlBordersIndex::xlEdgeRight]->LineStyle = Microsoft::Office::Interop::Excel::XlLineStyle::xlContinuous;  // ������ ����� ������ ������
        cells_area->Borders[Microsoft::Office::Interop::Excel::XlBordersIndex::xlInsideVertical]->LineStyle = Microsoft::Office::Interop::Excel::XlLineStyle::xlContinuous;  // ������ ����� ���������� ������������ �����
        cells_area->Borders[Microsoft::Office::Interop::Excel::XlBordersIndex::xlInsideHorizontal]->LineStyle = Microsoft::Office::Interop::Excel::XlLineStyle::xlContinuous;  // ������ ����� ���������� �������������� �����
        cells_area->ColumnWidth = 15;
        cells_area->WrapText = true;
        //��������� ������� ������� �� datadridview1
        for (int i = 0; i < MyForm::dataGridView1->RowCount; ++i) {
            for (int j = 1; j < MyForm::dataGridView1->ColumnCount; ++j)
                ExcelActiveWorkSheet->Cells[i + 2, j] = MyForm::dataGridView1->Rows[i]->Cells[j]->Value;
        }
        // ------ ������ "�����" ������� --------------------------
        for (int i = 1; i < ColumnsHeader->size(); ++i) {
            ExcelActiveWorkSheet->Cells[1, i] = ColumnsHeader[i]->ToString();
            safe_cast<Microsoft::Office::Interop::Excel::Range^>(ExcelActiveWorkSheet->Cells[1, i])->Font->Size = 11;// ������ ������ ������
            safe_cast<Microsoft::Office::Interop::Excel::Range^>(ExcelActiveWorkSheet->Cells[1, i])->Font->Name = "Calibri";// ������ �������� ������
            safe_cast<Microsoft::Office::Interop::Excel::Range^>(ExcelActiveWorkSheet->Cells[1, i])->Font->Bold = true;// ������ �������� ������
            safe_cast<Microsoft::Office::Interop::Excel::Range^>(ExcelActiveWorkSheet->Cells[1, i])->Interior->Color = Color::SpringGreen;
        }
        //�������� ���� ��������� ��������.
        ExcelApp->Visible = true;
        ExcelApp->UserControl = true;
    }
    catch (Exception^ e) {
        MessageBox::Show("���-�� ����� �� ���: " + e->ToString(), "�������������� ��������...");
    }
    return System::Void();
}
//������� ���� - �������� ������
System::Void ProjectCLR::MyForm::��������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    adding_an_entry();
    return System::Void();
}
//������� ���� - ������������� ������
System::Void ProjectCLR::MyForm::�������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        changing_an_entry();
    }
    catch (Exception^ e) {
        MessageBox::Show("Error Working Changing an Entry in ToolStripMenuItem_Click(): " + e->ToString(), "Exception ...");
    }
    return System::Void();
}
//������� ���� - ������� ������
System::Void ProjectCLR::MyForm::�������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        deleting_an_entry();
    }
    catch (Exception^ e) {
        MessageBox::Show("Error Working Button of Delete: " + e->ToString(), "Exception ...");
    }
    return System::Void();
}
//� ���������
System::Void ProjectCLR::MyForm::����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    MessageBox::Show("��������� �������� � ����� CLI/C++ � ����������� SQLite � �������� ���� ������.\n�����������: ��������� �.�.\nemail: furyaxe@yandex.ru", "� ���������");
    return System::Void();
}
//��������� �������� ����� �� ������ - ����� ������ ��������������
System::Void ProjectCLR::MyForm::dataGridView1_CellContentDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
    try {
        changing_an_entry();
    }
    catch (Exception^ e) {
        MessageBox::Show("Error Working CellContentClick: " + e->ToString(), "Exception ...");
    }
    return System::Void();
}
//������ ������ ���� - ������������� ������
System::Void ProjectCLR::MyForm::toolStripMenuItemRedacting_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        changing_an_entry();
    }
    catch (Exception^ e) {
        MessageBox::Show("Error Working toolStripMenuItemRedacting_Click: " + e->ToString(), "Exception ...");
    }
    return System::Void();
}
//������ ������ ���� - ������� ������
System::Void ProjectCLR::MyForm::toolStripMenuItemDeleting_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        deleting_an_entry();
    }
    catch (Exception^ e) {
        MessageBox::Show("Error Working toolStripMenuItemDeleting_Click: " + e->ToString(), "Exception ...");
    }
    return System::Void();
}
//������ ������ ���� - ���������� ���������� ������
System::Void ProjectCLR::MyForm::toolStripMenuItemCopyCell_Click(System::Object^ sender, System::EventArgs^ e) {
    Clipboard::SetText(MyForm::dataGridView1->CurrentCell->Value->ToString());
    return System::Void();
}


//����� �� ��������
System::Void ProjectCLR::MyForm::exitToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
    Application::Exit();
    return System::Void();
}





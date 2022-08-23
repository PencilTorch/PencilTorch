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
        //Обратите внимание, что SQL запрос оформляем как обычную строчку
        cmdSelect->CommandText = "SELECT * FROM fonebase;";
        SQLiteDataReader^ reader = cmdSelect->ExecuteReader();
        //Переменные
        DataColumn^ column; //Столбец таблицы
        DataRow^ row; //Строка таблицы
        //Создаем таблицу данных
        table = gcnew DataTable();
        //Вектор названий столбцов
        vector<String^>^ nameColumns = gcnew vector<String^>();
        //Заполним данные о столбцах
        for (int i = 0; i < reader->FieldCount; i++) {
            nameColumns->push_back(reader->GetName(i));
            column = gcnew DataColumn(nameColumns->at(i), String::typeid);
            table->Columns->Add(column);
        }
        //Пробегаем по каждой записи
        while (reader->Read()) {
            //Заполняем строчку таблицы
            row = table->NewRow();
            //В каждой записи пробегаем по всем столбцам
            for (int i = 0; i < reader->FieldCount; i++) {
                //Добавляем значение столбца в row
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
        FillColName(); // заполнить вектор имен столбцов как в sql-таблице
        for (int i = 0; i < ColumnsHeader->size(); ++i) {
            dataGridView1->Columns[i]->HeaderText = ColumnsHeader->at(i);
        }
        seekerComboBox1(); //заполнить ComboBox1 для поиска
        dataGridView1->Columns[0]->Visible = false; //прячем колонку _id
        MyForm::button1->Enabled = false; //кнопка "добавить" не активна пока не введен телефон
    }
    catch (Exception^ e) {
        MessageBox::Show("Error Working SQL: " + e->ToString(), "Exception ...");
    }
    return System::Void();
}
//заполняет вектор с заголовками столбцов
System::Void ProjectCLR::MyForm::FillColumnsHeader() {
    ColumnsHeader->push_back("№");
    ColumnsHeader->push_back("СПП"); //0
    ColumnsHeader->push_back("Подраздел"); //1
    ColumnsHeader->push_back("Должность"); //2
    ColumnsHeader->push_back("Имя"); //3
    ColumnsHeader->push_back("Фамилия"); //4
    ColumnsHeader->push_back("Отчество"); //5
    ColumnsHeader->push_back("Телефон 1"); //6
    ColumnsHeader->push_back("Телефон 2"); //7
    ColumnsHeader->push_back("Почта"); //8
    ColumnsHeader->push_back("Мобильный телефон"); //9
    ColumnsHeader->push_back("Примечания"); //10
    return System::Void();
}
//заполнить вектор имен столбцов как в sql-таблице
System::Void ProjectCLR::MyForm::FillColName() {
    for (int i = 0; i < dataGridView1->ColumnCount; ++i)
        ColName->push_back(dataGridView1->Columns[i]->Name);
    return System::Void();
}
//заполняет ищущий ComboBox1
System::Void ProjectCLR::MyForm::seekerComboBox1() {
    for (int i = 1; i < ColumnsHeader->size(); ++i) {
        MyForm::comboBox1->Items->Add(ColumnsHeader->at(i));
    }
    return System::Void();
}
//код вызова панели редактирования записи
System::Void ProjectCLR::MyForm::changing_an_entry() {
    MyForm::button1->Text = L"Заменить";
    MyForm::groupBox1->Text = L"Изменение записи";
    for (int i = 0; i < MyForm::ColName->size() - 1; ++i) {
        MyForm::arrTextBox[i]->Text = MyForm::dataGridView1->CurrentRow->Cells[i + 1]->Value->ToString();
    }
    MyForm::dataGridView1->Visible = false;
    MyForm::panel1->Visible = true;
    MyForm::toolStrip1->Enabled = false;
    MyForm::правкаToolStripMenuItem->Enabled = false;
    return System::Void();
}
//код вызова панели добавления записи
System::Void ProjectCLR::MyForm::adding_an_entry() {
    MyForm::dataGridView1->Visible = false;
    MyForm::panel1->Visible = true;
    MyForm::toolStrip1->Enabled = false;
    MyForm::правкаToolStripMenuItem->Enabled = false;
    MyForm::groupBox1->Text = L"Добавление новой записи";
    MyForm::button1->Text = L"Добавить";
    return System::Void();
}
//код вызова меню удаления записи
System::Void ProjectCLR::MyForm::deleting_an_entry() {
    MyForm::toolStrip1->Enabled = false;
    MyForm::правкаToolStripMenuItem->Enabled = false;
    System::Windows::Forms::DialogResult result = MessageBox::Show(L"Вы точно хотите удалить эту запись?", L"ВНИМАНИЕ!", MessageBoxButtons::OKCancel);
    if (result == ::DialogResult::OK) {
        String^ id = MyForm::dataGridView1->CurrentRow->Cells[0]->Value->ToString();
        int current_str = dataGridView1->CurrentRow->Index;
        SQLiteCommand^ cmdInsertValue = db->CreateCommand();
        cmdInsertValue->CommandText = "DELETE FROM fonebase WHERE _id = " + id + "; ";
        cmdInsertValue->ExecuteNonQuery();
        DataTable^ table = fillDataTable();
        MyForm::dataGridView1->DataSource = table;
        MyForm::dataGridView1->Columns[0]->Visible = false; //прячем колонку _id
        //назначаем выделенную ячейку
        if (current_str >= 1)
            dataGridView1->CurrentCell = dataGridView1[1, current_str - 1];
        else
            dataGridView1->CurrentCell = dataGridView1[1, 1];
    }
    MyForm::toolStrip1->Enabled = true;
    MyForm::правкаToolStripMenuItem->Enabled = true;
    return System::Void();
}
//заполняет вектор подсказок по выбранному столбцу
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
//кнопка добавить запись на быстром меню - выводит панель с полями ввода
System::Void ProjectCLR::MyForm::toolStripButton1_Click(System::Object^ sender, System::EventArgs^ e) {
    adding_an_entry();
    return System::Void();
}
//кнопка отмены добавления/редактирования записи
System::Void ProjectCLR::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e) {
    MyForm::dataGridView1->Visible = true;
    MyForm::panel1->Visible = false;
    MyForm::toolStrip1->Enabled = true;
    MyForm::правкаToolStripMenuItem->Enabled = true;
    for (int i = 0; i < MyForm::arrTextBox->Length; ++i)
        MyForm::arrTextBox[i]->Text = "";
    return System::Void();
}
//кнопка добавления записи в бд
System::Void ProjectCLR::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        SQLiteCommand^ cmdInsertValue = db->CreateCommand();
        String^ commandSQL;
        String^ colSQL;
        int curr_str = 0; // выделенная строка после манипуляций
        //если добавляем запись
        if (MyForm::button1->Text == "Добавить") {
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
            //команда добавления звписи
            cmdInsertValue->CommandText = "INSERT INTO fonebase (" + colSQL + ") VALUES(" + commandSQL + "); ";
        }
        else {
            //если редактируем запись
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
        dataGridView1->Columns[0]->Visible = false; //прячем колонку _id
        dataGridView1->CurrentCell = dataGridView1[1, curr_str]; //назначаем выделенную строку
        MyForm::dataGridView1->Visible = true;
        MyForm::panel1->Visible = false;
        MyForm::toolStrip1->Enabled = true;
        MyForm::правкаToolStripMenuItem->Enabled = true;
    }
    catch (Exception^ e) {
        MessageBox::Show("Error Executing SQL: " + e->ToString(), "Exception ...");
    }
    return System::Void();
}
//подсказки поля СПП
System::Void ProjectCLR::MyForm::textBox1_GotFocus(System::Object^ sender, System::EventArgs^ e) {
    int namberColumn = 1; // SPP
    vector<String^>^ vTemp = gcnew vector<String^>();
    makeVectorHint(vTemp, namberColumn);
    for (auto& it = vTemp->begin(); it != vTemp->end(); ++it) {
        MyForm::arrTextBox[0]->AutoCompleteCustomSource->Add(*it);
    }
    return System::Void();
}
//подсказки поля подраздел
System::Void ProjectCLR::MyForm::textBox2_GotFocus(System::Object^ sender, System::EventArgs^ e) {
    int namberColumn = 2; // podrazdel
    vector<String^>^ vTemp = gcnew vector<String^>();
    makeVectorHint(vTemp, namberColumn);
    for (auto& it = vTemp->begin(); it != vTemp->end(); ++it) {
        MyForm::arrTextBox[1]->AutoCompleteCustomSource->Add(*it);
    }
    return System::Void();
}
//подсказки поля должность
System::Void ProjectCLR::MyForm::textBox11_GotFocus(System::Object^ sender, System::EventArgs^ e) {
    int namberColumn = 3; // dolzhnost
    vector<String^>^ vTemp = gcnew vector<String^>();
    makeVectorHint(vTemp, namberColumn);
    for (auto& it = vTemp->begin(); it != vTemp->end(); ++it) {
        MyForm::arrTextBox[2]->AutoCompleteCustomSource->Add(*it);
    }
    return System::Void();
}
//подсказки поля имя
System::Void ProjectCLR::MyForm::textBox4_GotFocus(System::Object^ sender, System::EventArgs^ e) {
    int namberColumn = 4; // fname
    vector<String^>^ vTemp = gcnew vector<String^>();
    makeVectorHint(vTemp, namberColumn);
    for (auto& it = vTemp->begin(); it != vTemp->end(); ++it) {
        MyForm::arrTextBox[3]->AutoCompleteCustomSource->Add(*it);
    }
    return System::Void();
}
//подсказки поля фамилия
System::Void ProjectCLR::MyForm::textBox3_GotFocus(System::Object^ sender, System::EventArgs^ e) {
    int namberColumn = 5; // sname
    vector<String^>^ vTemp = gcnew vector<String^>();
    makeVectorHint(vTemp, namberColumn);
    for (auto& it = vTemp->begin(); it != vTemp->end(); ++it) {
        MyForm::arrTextBox[4]->AutoCompleteCustomSource->Add(*it);
    }
    return System::Void();
}
//подсказки поля отчество
System::Void ProjectCLR::MyForm::textBox5_GotFocus(System::Object^ sender, System::EventArgs^ e) {
    int namberColumn = 6; // tname
    vector<String^>^ vTemp = gcnew vector<String^>();
    makeVectorHint(vTemp, namberColumn);
    for (auto& it = vTemp->begin(); it != vTemp->end(); ++it) {
        MyForm::arrTextBox[5]->AutoCompleteCustomSource->Add(*it);
    }
    return System::Void();
}
//активность кнопки "добавить" в зависимости от поля "телефон1"
System::Void ProjectCLR::MyForm::textBox8_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    if (arrTextBox[6]->Text != "")
        MyForm::button1->Enabled = true;
    else
        MyForm::button1->Enabled = false;
    return System::Void();
}
//кнопка "редактирования записи" из быстрого меню
System::Void ProjectCLR::MyForm::toolStripButton2_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        changing_an_entry();
    }
    catch (Exception^ e) {
        MessageBox::Show("Error Working Changing an Entry in toolStripButton2_Click: " + e->ToString(), "Exception ...");
    }
    return System::Void();
}
//кнопка "удаление записи" из быстрого меню
System::Void ProjectCLR::MyForm::toolStripButton3_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        deleting_an_entry();
    }
    catch (Exception^ e) {
        MessageBox::Show("Error Working Button of Delete: " + e->ToString(), "Exception ...");
    }
    return System::Void();
}
//кнопка "поиск" из быстрого меню
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
//кнопка "Показать" панели2 поиска из быстрого меню 
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
//подсказки поля поиска
System::Void ProjectCLR::MyForm::textBox12_GotFocus(System::Object^ sender, System::EventArgs^ e) {
    int namberColumn = comboBox1->SelectedIndex; //получили индекс выбранного поля (0 - это везде)
    vector<String^>^ vTemp = gcnew vector<String^>();
    if (namberColumn) {
        makeVectorHint(vTemp, namberColumn);
        for (auto& it = vTemp->begin(); it != vTemp->end(); ++it) 
            MyForm::textBox12->AutoCompleteCustomSource->Add(*it);
    }
    return System::Void();
}
//сброс фильтра
System::Void ProjectCLR::MyForm::button4_Click(System::Object^ sender, System::EventArgs^ e) {
    DataTable^ table = fillDataTable();
    dataGridView1->DataSource = table;
    MyForm::textBox12->Text = "";
    MyForm::comboBox1->SelectedIndex = 0;
    return System::Void();
}
//загрузить базу из экселя
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
            MessageBox::Show("Что-то пошло не так: " + e->ToString(), "Исключительная ситуация...");
        }
    }
    return System::Void();
}
//выгрузить базу в эксель
System::Void ProjectCLR::MyForm::exportToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        Microsoft::Office::Interop::Excel::Application^ ExcelApp = gcnew Microsoft::Office::Interop::Excel::ApplicationClass();
        Microsoft::Office::Interop::Excel::Workbook^ ExcelWorkBook = ExcelApp->Workbooks->Add(Type::Missing);// создается книга с 1-ой страницей
        Microsoft::Office::Interop::Excel::Worksheet^ ExcelActiveWorkSheet;// заводим объект для работы с активной страницей
        safe_cast<Microsoft::Office::Interop::Excel::Worksheet^>(ExcelApp->ActiveWorkbook->Sheets[1])->Select(Type::Missing);// делаем 1 страницу активной
        ExcelActiveWorkSheet = safe_cast<Microsoft::Office::Interop::Excel::Worksheet^>(ExcelApp->ActiveSheet);
        ExcelActiveWorkSheet->Name = L"Телефонная книга";
        safe_cast<Microsoft::Office::Interop::Excel::Worksheet^>(ExcelApp->ActiveWorkbook->Sheets[1])->Select(Type::Missing); // делаем 1 страницу активной для заполнения 
        ExcelActiveWorkSheet = safe_cast<Microsoft::Office::Interop::Excel::Worksheet^>(ExcelApp->ActiveSheet);
        Microsoft::Office::Interop::Excel::Range^ cells_area;
        cells_area = ExcelActiveWorkSheet->Range["A1:K" + (1 + MyForm::dataGridView1->RowCount).ToString(), Type::Missing]; // определяем область вывода данных
        cells_area->HorizontalAlignment = Microsoft::Office::Interop::Excel::XlHAlign::xlHAlignCenter; // выравниваем по горизонтали текст в ячейках
        cells_area->VerticalAlignment = Microsoft::Office::Interop::Excel::XlVAlign::xlVAlignCenter;  // выравниваем по вертикали текст в ячейках
        cells_area->Font->Size = 10;// задаем размер шрифта
        cells_area->Font->Name = "Calibri";// задаем название шрифта
        cells_area->Borders[Microsoft::Office::Interop::Excel::XlBordersIndex::xlEdgeBottom]->LineStyle = Microsoft::Office::Interop::Excel::XlLineStyle::xlContinuous;  // задаем стиль нижних границ
        cells_area->Borders[Microsoft::Office::Interop::Excel::XlBordersIndex::xlEdgeTop]->LineStyle = Microsoft::Office::Interop::Excel::XlLineStyle::xlContinuous;  // задаем стиль верхних границ
        cells_area->Borders[Microsoft::Office::Interop::Excel::XlBordersIndex::xlEdgeLeft]->LineStyle = Microsoft::Office::Interop::Excel::XlLineStyle::xlContinuous;  // задаем стиль левых границ
        cells_area->Borders[Microsoft::Office::Interop::Excel::XlBordersIndex::xlEdgeRight]->LineStyle = Microsoft::Office::Interop::Excel::XlLineStyle::xlContinuous;  // задаем стиль правых границ
        cells_area->Borders[Microsoft::Office::Interop::Excel::XlBordersIndex::xlInsideVertical]->LineStyle = Microsoft::Office::Interop::Excel::XlLineStyle::xlContinuous;  // задаем стиль внутренних вертикальных линий
        cells_area->Borders[Microsoft::Office::Interop::Excel::XlBordersIndex::xlInsideHorizontal]->LineStyle = Microsoft::Office::Interop::Excel::XlLineStyle::xlContinuous;  // задаем стиль внутренних горизонтальных линий
        cells_area->ColumnWidth = 15;
        cells_area->WrapText = true;
        //заполняем данными таблицу из datadridview1
        for (int i = 0; i < MyForm::dataGridView1->RowCount; ++i) {
            for (int j = 1; j < MyForm::dataGridView1->ColumnCount; ++j)
                ExcelActiveWorkSheet->Cells[i + 2, j] = MyForm::dataGridView1->Rows[i]->Cells[j]->Value;
        }
        // ------ рисуем "шапку" таблица --------------------------
        for (int i = 1; i < ColumnsHeader->size(); ++i) {
            ExcelActiveWorkSheet->Cells[1, i] = ColumnsHeader[i]->ToString();
            safe_cast<Microsoft::Office::Interop::Excel::Range^>(ExcelActiveWorkSheet->Cells[1, i])->Font->Size = 11;// задаем размер шрифта
            safe_cast<Microsoft::Office::Interop::Excel::Range^>(ExcelActiveWorkSheet->Cells[1, i])->Font->Name = "Calibri";// задаем название шрифта
            safe_cast<Microsoft::Office::Interop::Excel::Range^>(ExcelActiveWorkSheet->Cells[1, i])->Font->Bold = true;// задаем жирность шрифта
            safe_cast<Microsoft::Office::Interop::Excel::Range^>(ExcelActiveWorkSheet->Cells[1, i])->Interior->Color = Color::SpringGreen;
        }
        //Вызываем нашу созданную эксельку.
        ExcelApp->Visible = true;
        ExcelApp->UserControl = true;
    }
    catch (Exception^ e) {
        MessageBox::Show("Что-то пошло не так: " + e->ToString(), "Исключительная ситуация...");
    }
    return System::Void();
}
//верхнее меню - добавить запись
System::Void ProjectCLR::MyForm::добавитьЗаписьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    adding_an_entry();
    return System::Void();
}
//верхнее меню - редактировать запись
System::Void ProjectCLR::MyForm::редактироватьЗаписьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        changing_an_entry();
    }
    catch (Exception^ e) {
        MessageBox::Show("Error Working Changing an Entry in ToolStripMenuItem_Click(): " + e->ToString(), "Exception ...");
    }
    return System::Void();
}
//верхнее меню - удалить запись
System::Void ProjectCLR::MyForm::удалитьЗаписьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        deleting_an_entry();
    }
    catch (Exception^ e) {
        MessageBox::Show("Error Working Button of Delete: " + e->ToString(), "Exception ...");
    }
    return System::Void();
}
//о программе
System::Void ProjectCLR::MyForm::оПрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    MessageBox::Show("Программа написана в среде CLI/C++ с применением SQLite в качестве базы данных.\nРазработчик: Строганов М.С.\nemail: furyaxe@yandex.ru", "О программе");
    return System::Void();
}
//обработка двойного клика по ячейке - вывод панели редактирования
System::Void ProjectCLR::MyForm::dataGridView1_CellContentDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
    try {
        changing_an_entry();
    }
    catch (Exception^ e) {
        MessageBox::Show("Error Working CellContentClick: " + e->ToString(), "Exception ...");
    }
    return System::Void();
}
//правая кнопка мыши - редактировать запись
System::Void ProjectCLR::MyForm::toolStripMenuItemRedacting_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        changing_an_entry();
    }
    catch (Exception^ e) {
        MessageBox::Show("Error Working toolStripMenuItemRedacting_Click: " + e->ToString(), "Exception ...");
    }
    return System::Void();
}
//правая кнопка мыши - удалить запись
System::Void ProjectCLR::MyForm::toolStripMenuItemDeleting_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        deleting_an_entry();
    }
    catch (Exception^ e) {
        MessageBox::Show("Error Working toolStripMenuItemDeleting_Click: " + e->ToString(), "Exception ...");
    }
    return System::Void();
}
//правая кнопка мыши - копировать содержимое ячейки
System::Void ProjectCLR::MyForm::toolStripMenuItemCopyCell_Click(System::Object^ sender, System::EventArgs^ e) {
    Clipboard::SetText(MyForm::dataGridView1->CurrentCell->Value->ToString());
    return System::Void();
}


//выход из програмы
System::Void ProjectCLR::MyForm::exitToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
    Application::Exit();
    return System::Void();
}





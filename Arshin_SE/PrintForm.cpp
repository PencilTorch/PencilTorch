#include "PrintForm.h"

void Arshin::PrintForm::setIzvVisible(bool flag) {
    if (flag) {
        label31->Visible = true;
        label53->Visible = true;
    }
    else {
        label31->Visible = false;
        label53->Visible = false;
    }
    //throw gcnew System::NotImplementedException();
}

void Arshin::PrintForm::setIzvOrSvd(String^ str) {
    label29->Text = str;
    //throw gcnew System::NotImplementedException();
}

void Arshin::PrintForm::setVrfDate(String^ str) {
    label35->Text = str;
    //throw gcnew System::NotImplementedException();
}

void Arshin::PrintForm::setValidDate(String^ str) {
    label53->Text = str;
    //throw gcnew System::NotImplementedException();
}

void Arshin::PrintForm::setSI(String^ str) {
    label40->Text += str;
    //throw gcnew System::NotImplementedException();
}

void Arshin::PrintForm::setZNum(String^ str) {
    label46->Text = str;
    //throw gcnew System::NotImplementedException();
}

void Arshin::PrintForm::setOrg(String^ str) {
    label21->Text = str;
    //throw gcnew System::NotImplementedException();
}

void Arshin::PrintForm::setDocTitle(String^ str) {
    label51->Text = str;
    //throw gcnew System::NotImplementedException();
}

void Arshin::PrintForm::setVriURL(String^ str) {
    label43->Text = str;
    //throw gcnew System::NotImplementedException();
}

void Arshin::PrintForm::setEtalons(String^ str) {
    label52->Text = str;
    //throw gcnew System::NotImplementedException();
}

void Arshin::PrintForm::setStructure(String^ str) {
    label47->Text = str;
    //throw gcnew System::NotImplementedException();
}

void Arshin::PrintForm::setBriefCharacter(String^ str) {
    label49->Text = str;
    //throw gcnew System::NotImplementedException();
}

void Arshin::PrintForm::setAddInfo(String^ str) {
    label45->Text += str;
    //throw gcnew System::NotImplementedException();
}

void Arshin::PrintForm::setVriType(String^ str) {
    label50->Text = str;
    //throw gcnew System::NotImplementedException();
}

void Arshin::PrintForm::setZakluchenie(String^ str) {
    label42->Text = str;
    //throw gcnew System::NotImplementedException();
}

void Arshin::PrintForm::ClearPrintForm() {
    label21->Text = "";//�����������-����������
    label29->Text = "";//��� ��� ���
    label35->Text = "";//���� �������
    label40->Text = "";//��
    label42->Text = "";//����������
    label43->Text = "";//������
    label45->Text = "";//����������
    label46->Text = "";//��������� �����
    label47->Text = "-";//� �������
    label49->Text = "";//� ������
    label50->Text = "";//��� �������
    label51->Text = "";//��������
    label52->Text = "";//�������
    label53->Text = "";//����� ��
    //throw gcnew System::NotImplementedException();
}


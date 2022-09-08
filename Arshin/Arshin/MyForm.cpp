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


std::string ProjectCLR::Utf8_to_cp1251(const std::string_view str) {
    const auto countW = ::MultiByteToWideChar(CP_UTF8, 0, str.data(), str.size(), 0, 0);
    std::wstring UTF16(countW, L'\0'); ::MultiByteToWideChar(CP_UTF8, 0, str.data(), str.size(), UTF16.data(), UTF16.size());

    const auto countA = ::WideCharToMultiByte(1251, 0, UTF16.data(), UTF16.size(), 0, 0, 0, 0);
    std::string cp1251(countA, '\0'); ::WideCharToMultiByte(1251, 0, UTF16.data(), UTF16.size(), cp1251.data(), cp1251.size(), 0, 0);

    return cp1251;
}


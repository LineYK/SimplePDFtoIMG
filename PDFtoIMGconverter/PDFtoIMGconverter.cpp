#include <locale>
#include <codecvt>
#include "PTI_function.cpp"

string uft16_to_utf8(const wstring& utf16)
{
	wstring_convert<codecvt_utf8_utf16<wchar_t>> converter;
	return converter.to_bytes(utf16);
}

int main()
{
	setlocale(LC_ALL, "");
    wstring pdfPath;
	cout << "PDF 파일 주소를 입력하세요: " << endl;
	getline(wcin, pdfPath);

	string pdfPath_utf8 = uft16_to_utf8(pdfPath);

	wcout << L"PDF 파일 경로: " << pdfPath << endl;

	try
	{
		document& doc = process_pdf(pdfPath_utf8);
		int numPages = doc.pages();
		cout << "총 페이지 수: " << numPages << endl;

		for (int i = 0; i < numPages; i++)
		{
			process_page(doc, i);
		}

		delete &doc;
	}
	catch (const char* msg)
	{
		cout << msg << endl;
		return 1;
	}

    return 0;
}
#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
#include "popplerHeader.h"

using namespace std;

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

	poppler::document* doc = poppler::document::load_from_file(pdfPath_utf8);
	if (!doc || doc->is_locked())
	{
		cout << "Error: PDF 파일이 유효하지 않거나 잠겨있습니다." << endl;
		return 1;
	}

	int numPages = doc->pages();
	cout << "총 페이지 수: " << numPages << endl;

	for (int i = 0; i < numPages; i++)
	{
		poppler::page* pdfPage = doc->create_page(i);

		double width = pdfPage->page_rect().width();
		double height = pdfPage->page_rect().height();

		poppler::page_renderer renderer;
		poppler::image img = renderer.render_page(pdfPage, width, height);

		string imgPath = pdfPath_utf8.substr(0, pdfPath_utf8.find_last_of('.')) + "_" + to_string(i + 1) + ".png";
		cout << "이미지 경로: " << imgPath << endl;

		cout << i + 1 << "번째 이미지 생성 중" << endl;
		img.save("C:\\" + to_string(i) + ".png", "png");
		cout << i + 1 << "번째 이미지 생성 완료" << endl;
	}

	delete doc;

    return 0;
}
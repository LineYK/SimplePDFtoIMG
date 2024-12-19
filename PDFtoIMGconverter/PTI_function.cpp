#include <iostream>
#include <ctime>
#include <experimental/filesystem>
#include "PTI_function.h"

namespace fs = std::experimental::filesystem;

document& process_pdf(const string& pdf_path)
{
    document* doc = document::load_from_file(pdf_path);

    if (!doc || doc->is_locked())
    {
        throw "Error: PDF ������ ��ȿ���� �ʰų� ����ֽ��ϴ�.";
    }

    return *doc;
}

document& process_pdf_raw_data(uint8_t* data, size_t len)
{
    char* pdfData = reinterpret_cast<char*>(data);
    document* doc = document::load_from_raw_data(pdfData, len);

    if (!doc || doc->is_locked())
    {
        throw "Error: PDF ������ ��ȿ���� �ʰų� ����ֽ��ϴ�.";
    }

    int numPages = doc->pages();
    cout << "�� ������ ��: " << numPages << endl;

    return *doc;
}

void process_page(document& doc, int pageNum)
{
    page* pdfPage = doc.create_page(pageNum);

    page_renderer renderer;
    image img = renderer.render_page(pdfPage, 300, 300);

    auto now = time(0);
    tm ltm;
    localtime_s(&ltm, &now);

    cout << pageNum + 1 << "��° �̹��� ���� ��" << endl;
    string imgPath = ".\\image\\" + to_string(ltm.tm_year + 1900) + to_string(ltm.tm_mon + 1) + to_string(ltm.tm_hour) + to_string(ltm.tm_min) + to_string(pageNum) + ".png";
    
	fs::path p("./image");

	if (!fs::exists(p))
	{
		fs::create_directory(p);
	}

    
    cout << "�̹��� ���: " << imgPath << endl;
    img.save(imgPath, "png");
    cout << "�̹��� ���: " << imgPath << endl;
    cout << pageNum + 1 << "��° �̹��� ���� �Ϸ�" << endl;

    delete pdfPage;
}
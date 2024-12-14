#include <iostream>
#include "PTI_function.h"

using namespace std;
using namespace poppler;

void process_pdf(uint8_t* data, size_t len)
{
	char* pdfData = reinterpret_cast<char*>(data);
	document* doc = document::load_from_raw_data(pdfData, len);

	if (!doc || doc->is_locked())
	{
		cout << "Error: PDF 파일이 유효하지 않거나 잠겨있습니다." << endl;
		return;
	}

	int numPages = doc->pages();
	cout << "총 페이지 수: " << numPages << endl;



}
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
		cout << "Error: PDF ������ ��ȿ���� �ʰų� ����ֽ��ϴ�." << endl;
		return;
	}

	int numPages = doc->pages();
	cout << "�� ������ ��: " << numPages << endl;



}
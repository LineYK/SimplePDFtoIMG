#pragma once

#include <poppler/cpp/poppler-document.h>
#include <poppler/cpp/poppler-page.h>
#include <poppler/cpp/poppler-image.h>
#include <poppler/cpp/poppler-page-renderer.h>
#include <poppler/cpp/poppler-page-transition.h>

#ifdef _cplusplus
extern "C" {
#endif

using namespace std;
using namespace poppler;

document& process_pdf(const string& pdf_path);
document& process_pdf_raw_data(uint8_t* data, size_t len);
void process_page(document& doc, int pageNum);

#ifdef _cplusplus
}
#endif
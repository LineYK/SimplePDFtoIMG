#pragma once

#include <poppler/cpp/poppler-document.h>
#include <poppler/cpp/poppler-page.h>
#include <poppler/cpp/poppler-image.h>
#include <poppler/cpp/poppler-page-renderer.h>
#include <poppler/cpp/poppler-page-transition.h>

#ifdef _cplusplus
extern "C" {
#endif

void process_pdf(uint8_t* data, size_t len);

#ifdef _cplusplus
}
#endif
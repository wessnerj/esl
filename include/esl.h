#pragma once

#ifdef _WIN32
  #define esl_EXPORT __declspec(dllexport)
#else
  #define esl_EXPORT
#endif

esl_EXPORT void esl();

#ifndef ANSIDEFINE_H
#define ANSIDEFINE_H

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
  #include "NoANSIEsc.h"
  #define WITH_ANSI 0
#else
  #include "ANSIEsc.h"
  #define WITH_ANSI 1
#endif

#endif

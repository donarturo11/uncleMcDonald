#ifndef TEXTUI_H 
#define TEXTUI_H


#include <iostream>
#include <map>
#include "../Fence/Fence.h"
#include "../Fence/FencePicture.h"
#include "../Fence/FenceLengthError.h"
#include "../DrawMatrix/DrawMatrix.h"

#include "../ANSIEsc/ANSIDefine.h"

/*
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
  #include "../ANSIEsc/NoANSIEsc.h"
#else
  #include "../ANSIEsc/ANSIEsc.h"  
#endif

*/


class InputError{};

class TextUI {
  public:
      TextUI();
      ~TextUI();
      void runCommand(std::string command);
                  
   private:
      void commandLoop();
      void greateUser();
      void printQuitInstructions();
      void run();
      void helpCmd();
      void wrongCmd();
      void startCmd();
      void stopCmd();
      void printText(std::string text);
      void inputLengthCmd();
      void displayFenceParametersCmd();
      void drawFence();
      
    protected:  
      
      Fence * fence;
      FencePicture * fencePicture;
      DrawMatrix * fenceMatrix;
    
};

#endif

#ifndef FENCEPICTURE_H 
#define FENCEPICTURE_H


#include <iostream>
#include <map>
#include "../DrawMatrix/DrawMatrix.h"



class FencePicture {
  public:
      FencePicture(DrawMatrix *picture);
      ~FencePicture();
      
      void drawAll();
      void drawWall();
      void drawFence();
      void drawGrass();
      void setFenceDimensions(int width, int height);
      void setFenceWidthString();
      void setFenceHeightString();
      std::string getFenceWidthString();
      std::string getFenceHeightString();
      void setASCII();
      void setANSI();
      
  protected:
      int fenceWidth;
      int fenceHeight;
      std::string widthString;
      std::string heightString;
      DrawMatrix * picture;
      std::map<std::string, int> objectID;
      
      
};

#endif

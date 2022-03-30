#include "FencePicture.h"

FencePicture::FencePicture(DrawMatrix *picture)
{
    std::cout << "Fence Contructor" << std::endl;
    this->picture = picture;
    
    
    this->objectID["wall"]=1;
    this->objectID["fence"]=2;
    this->objectID["grass"]=3;
    this->objectID["widthText"]=4;
    this->objectID["heightText"]=5;
}

FencePicture::~FencePicture()
{
    
}

void FencePicture::setFenceDimensions(int width, int height)
{
    this->fenceWidth=width;
    this->fenceHeight=height;
    picture->setGeometry(width+10, height+6);
}

void FencePicture::drawAll()
{
    picture->clearPicture();
    
    int pictureWidth=picture->getWidth();
    int pictureHeight=picture->getHeight();
    
    //drawGrass();
    drawWall();
    drawFence();
    
    picture->moveCursor(3+(this->fenceWidth/2)-1, 2);
    picture->fill(objectID["widthText"]);
    
    picture->moveCursor(3+(this->fenceWidth), 3+(this->fenceHeight/2));
    picture->fill(objectID["heightText"]);
    
    this->setFenceWidthString();
    this->setFenceHeightString();
    picture->assignSymbol(this->objectID["widthText"], this->getFenceWidthString());
    picture->assignSymbol(this->objectID["heightText"], this->getFenceHeightString());
    
    picture->refreshPicture();
}

void FencePicture::drawWall()
{
    for (int i=0; i<3; i++) {
    picture->moveCursor(i, 0);
    picture->drawLine(0, picture->getHeight(), objectID["wall"]);
    }
    
}

void FencePicture::drawFence()
{
    int fenceID=this->objectID["fence"];
    picture->moveCursor(3, 3);
    picture->drawLine(fenceWidth, 0, fenceID);
    picture->drawLine(0, fenceHeight, fenceID);
    picture->drawLine(-fenceWidth, 0, fenceID);
}

void FencePicture::drawGrass()
{
    int grassID=this->objectID["grass"];
    int width=picture->getWidth();
    int height=picture->getHeight();
    for (int y=0; y<height; y++){
       picture->moveCursor(0, y);
       if (y==2 || y==(height/2)) picture->drawLine(width-3, 0, grassID);
       else picture->drawLine(width, 0, grassID);
   }
}

void FencePicture::setFenceWidthString()
{
    this->widthString="a="+std::to_string(this->fenceWidth)+"m";
}

void FencePicture::setFenceHeightString()
{
    this->heightString="b="+std::to_string(this->fenceHeight)+"m";
}

std::string FencePicture::getFenceWidthString()
{
    return this->widthString;
}

std::string FencePicture::getFenceHeightString()
{
    return this->heightString;
}


void FencePicture::setASCII()
{
    picture->assignSymbol(objectID["wall"], "X");
    picture->assignSymbol(objectID["fence"], "*");
    picture->assignSymbol(objectID["grass"], ",");
}

void FencePicture::setANSI()
{
    
}

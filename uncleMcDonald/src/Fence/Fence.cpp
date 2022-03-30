#include "Fence.h"


Fence::Fence()
{
    //std::cout << "Fence Contructor" << std::endl;
}

Fence::~Fence()
{
    
}

void Fence::init()
{
    this->countLengthSideA();
    this->countLengthSideB();
    this->countArea();
}

void Fence::setLengthFence(int length)
{
    this->lengthFence=length; 
}


void Fence::countLengthSideA()
{
    int fenceLength=this->getLengthFence(); 
    this->lengthSideA=fenceLength/3;
}

void Fence::countLengthSideB()
{
    int fenceLength=this->getLengthFence();
    this->lengthSideB=(fenceLength/3)+(fenceLength%3);
}

void Fence::countArea()
{
    int lengthSideA=this->getLengthSideA();
    int lengthSideB=this->getLengthSideB();
    this->area=lengthSideA*lengthSideB;
}

int Fence::getLengthSideA()
{
    return this->lengthSideA;
}

int Fence::getLengthSideB()
{
    return this->lengthSideB;
}

int Fence::getArea()
{
   return this->area;
}

int Fence::getLengthFence()
{
   return this->lengthFence;   
}

#ifndef FENCE_H 
#define FENCE_H

#include <iostream>

#define MINIMAL_FENCE_LENGTH 3

class Fence {
  public:
      Fence();
      ~Fence();
      
      void init();
      void setLengthFence(int length);
      int getLengthSideA();
      int getLengthSideB();
      int getArea();
      int getLengthFence();
      
                  
   private:
      void countLengthSideA();
      void countLengthSideB();
      void countArea();
      
   protected:
      int lengthFence;
      int lengthSideA, lengthSideB;
      int area;
};

#endif

#ifndef FENCELENGTHERROR_H
#define FENCELENGTHERROR_H

#include <iostream>
#include "Fence.h"

class FenceLengthError{
    public:
        FenceLengthError();
        ~FenceLengthError();
        
        std::string getErrorMsg();
    private:
        void setErrorMsg();
    protected:
        std::string errorMsg;

};

#endif

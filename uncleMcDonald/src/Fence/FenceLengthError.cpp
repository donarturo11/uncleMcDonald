#include "FenceLengthError.h"


FenceLengthError::FenceLengthError()
{
    //std::cout << "Fence Error Constructor" << std::endl;
    setErrorMsg();
}

FenceLengthError::~FenceLengthError()
{
    
}

void FenceLengthError::setErrorMsg()
{
    int lengthMin=MINIMAL_FENCE_LENGTH;
    std::string errorMsg="";
    errorMsg+="Too small length.\n";
    errorMsg+="Put at least ";
    errorMsg+=std::to_string(lengthMin)+".";
    errorMsg+="\n";
    
    this->errorMsg=errorMsg;
}

std::string FenceLengthError::getErrorMsg()
{
    return this->errorMsg;
}

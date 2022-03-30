#include "TextUI.h"

TextUI::TextUI()
{
    greateUser();
    commandLoop();
}

TextUI::~TextUI()
{
    std::string text="";
    text+="This program was written by Artur Wrona (donarturo11)\n";
    text+="If do you have any suggestions,\nsend me message by e-mail:\n";
    text+=ansiEsc::bold;
    text+="artur";
    text+="wrona";
    text+="91";
    text+="@";
    text+="gmail.com";
    text+=ansiEsc::reset;
    text+=".";
    text+="\n"+ansiEsc::reset;
    printText(text);
}

void TextUI::commandLoop()
{
    
    std::string cmd;
    while(true){
        std::cout << ">>> ";
        std::cin >> cmd;
        if (cmd=="quit" || cmd == "quit") break;
        else runCommand(cmd);
        printQuitInstructions();
    }
}

void TextUI::printQuitInstructions()
{
    std::string quitInstruction="";
    quitInstruction+="\n\n";
    quitInstruction+="Type ";
    quitInstruction+=ansiEsc::bold+"quit"+ansiEsc::reset;
    quitInstruction+=" to exit.\n\n";
    printText(quitInstruction);
}

void TextUI::greateUser()
{
    std::string text="";
    
    text+=ansiEsc::bold;
    text+="Uncle McDonald\n";
    text+=ansiEsc::reset;
    text+="Uncle McDonald would like to make farm for his animals.\n";
    text+="To help him type " + ansiEsc::bold + "RUN" + ansiEsc::reset;
    text+=", " + ansiEsc::bold + "run" + ansiEsc::reset;
    text+=" or " + ansiEsc::bold + "start" + ansiEsc::reset;
    text+=" to begin.\n";
    text+="type " + ansiEsc::bold + "help" + ansiEsc::reset + " to get more commands.";
    text+="\n" ;   
       
    printText(text);
}

void TextUI::printText(std::string text)
{
    std::cout << text;
}

void TextUI::runCommand(std::string cmd)
{
    if (cmd=="help") helpCmd();
    else if (cmd=="run" || cmd=="RUN" || cmd=="start") startCmd();
    else if (cmd=="display") displayFenceParametersCmd();
    else if (cmd=="draw") drawFence();
    else if (cmd=="stop") stopCmd();
    else wrongCmd();
}

void TextUI::helpCmd()
{
    std::string text="";
    text+=ansiEsc::bold + "RUN,\nrun,\nstart" + ansiEsc::reset + "\t" + "Start counting fence\n";
    text+=ansiEsc::bold + "stop" + ansiEsc::reset + "\t" + "Stop counting fence\n";
    text+=ansiEsc::bold + "display" + ansiEsc::reset + "\t" + "Display fence parameters\n";
    text+=ansiEsc::bold + "quit" + ansiEsc::reset + "\t" + "exit this program\n";
    printText(text);
}

void TextUI::wrongCmd()
{
    printText(ansiEsc::bold + "Wrong command\n" + ansiEsc::reset);
}

void TextUI::startCmd()
{
    this->fence = new Fence;
    this->inputLengthCmd(); 
    this->displayFenceParametersCmd();
    
    std::string msg="";
    
    msg+="\n\n";
    msg+="If do you want see this fence, type ";
    msg+=ansiEsc::bold+"draw"+ansiEsc::reset;
    msg+="\n\n";
    
    printText(msg);
    
}

void TextUI::stopCmd()
{
    delete this->fence;
}

void TextUI::inputLengthCmd()
{
    int length;
    int lengthMin=MINIMAL_FENCE_LENGTH;  
    
    try {
    printText("Give length of fence in meters (at least "+std::to_string(lengthMin)+"): \n");
    std::cin >> length;
    if (length<lengthMin) throw FenceLengthError();
    else if (std::cin.fail()) throw InputError();
    }
    
    catch (FenceLengthError& lengthError) {
       printText(lengthError.getErrorMsg());
       std::cin >> length;
    }
    
    catch(...){
        length=0;
        std::cin.clear();
        commandLoop();
    }
    
    
    
    this->fence->setLengthFence(length);
    
    this->fence->init(); 
}

void TextUI::displayFenceParametersCmd()
{
    int sideALength=this->fence->getLengthSideA();
    int sideBLength=this->fence->getLengthSideB();
    int area=this->fence->getArea();
    
    std::string text="";
    text+="a:\t" + std::to_string(sideALength) + " m.\n";
    text+="b:\t" + std::to_string(sideBLength) + " m.\n";
    text+="area:\t" + std::to_string(area) + " m\u00B2.\n";
    
    printText(text);
}

void TextUI::drawFence()
{
    int sideA=this->fence->getLengthSideA();
    int sideB=this->fence->getLengthSideB();
    
    this->fenceMatrix=new DrawMatrix;
    this->fencePicture=new FencePicture(fenceMatrix);
    
    fencePicture->setFenceDimensions(sideA, sideB);
    fencePicture->setASCII();
    fencePicture->drawAll();
    
    printText(fenceMatrix->getPictureString());
    
    
    
    
    
}

#include "DrawMatrix.h"

DrawMatrix::DrawMatrix()
{
    this->error=false;
    this->symbolMap[0]=" ";
    this->symbolMap[1]="#";
}

DrawMatrix::~DrawMatrix()
{

}

void DrawMatrix::setGeometry(int width, int height)
{
    if (width > MAX_WIDTH || height > MAX_HEIGHT ){
        this->width=MAX_WIDTH;
        this->height=MAX_HEIGHT;
     }
     else {
        this->error=false;
        this->width=width+1;
        this->height=height+1;
     }
}

void DrawMatrix::clearPicture()
{
    for (int y=0; y<MAX_HEIGHT; y++){
        for (int x=0; x<MAX_WIDTH; x++) this->matrix[y][x]=0;
    }
}

void DrawMatrix::checkCursor()
{
    int curXPos=this->getCursorXPos();
    int curYPos=this->getCursorYPos();
    int width=this->getWidth();
    int height=this->getHeight();
    
    if (curXPos<0 || curYPos<0 || curXPos>width || curYPos>height){
     flagError();
    } else unFlagError();
}

void DrawMatrix::moveCursor(int x, int y)
{
    checkCursor();
    if (isError()){
        x=0;
        y=0;
        unFlagError();
    }
    this->cursorXPos=x;
    this->cursorYPos=y;
}

void DrawMatrix::rmoveCursor(int x, int y)
{
    this->cursorXPos+=x;
    this->cursorYPos+=y;
}


void DrawMatrix::fill(int nr)
{
    checkCursor();
    bool error=this->isError();
    if (error) moveCursor(0, 0);
    else this->matrix[this->cursorYPos][this->cursorXPos]=nr;
}

void DrawMatrix::draw(int x, int y, int nr)
{
    this->fill(nr);
    this->rmoveCursor(x, y);
    
    
}

void DrawMatrix::drawLine(int xPosMove, int yPosMove, int nr)
{
    int x=0;
    int y=0;
    
    int xStep=0;
    int yStep=0;
    
    
    int currentXPos=this->getCursorXPos();
    int destinationXPos=currentXPos+xPosMove;
    int lengthX=destinationXPos-currentXPos;
    int currentYPos=this->getCursorYPos();
    int destinationYPos=currentYPos+yPosMove;
    int lengthY=destinationYPos-currentYPos;
    
    if (lengthX<0) lengthX*=-1;
    if (lengthY<0) lengthY*=-1;
    
    // Test
    /*
    std::string text="";
    text+="X current: " + std::to_string(currentXPos) + "\n";
    text+="X destination: " + std::to_string(destinationXPos) + "\n";
    text+="X length: " + std::to_string(lengthX) + "\n";
    text+="Y current: " + std::to_string(currentYPos) + "\n";
    text+="Y destination: " + std::to_string(destinationYPos) + "\n";
    text+="Y length: " + std::to_string(lengthY) + "\n";
    std::cout << text << std::endl;
    */
    //
    
    if (xPosMove>0) xStep=1;
    if (xPosMove<0) xStep=-1;
    
    if (yPosMove>0) yStep=1;
    if (yPosMove<0) yStep=-1;
    
    bool endX=false;
    bool endY=false;

    for (int i=0; endX==false || endY==false; i++ ){
        currentXPos=this->getCursorXPos();
        currentYPos=this->getCursorYPos();
        
        draw(xStep, yStep, nr);
        
        //std::cout << "X: " << currentXPos << "\nY: " << currentYPos << std::endl;
        if (this->isError()) break;
        endX=(getCursorXPos()==destinationXPos);
        endY=(getCursorYPos()==destinationYPos);
    }
    rmoveCursor(-xStep, -yStep);
   
}


void DrawMatrix::assignSymbol(int nr, std::string symbol)
{
    if (symbol=="space") symbol=" ";
    this->symbolMap[nr]=symbol;
}

void DrawMatrix::refreshPicture()
{
    std::string bufferStringRaw="";
    std::string bufferString="";
    int symbolCell;
    for (int y=0; y<(this->height); y++){
        for (int x=0; x<(this->width); x++){
            symbolCell=getMatrixCell(x, y);
            bufferStringRaw+=std::to_string(symbolCell);     
            bufferString+=this->symbolMap[symbolCell];
            } // columns 
        
        bufferString+="\n";
        bufferStringRaw+="\n";
    } // rows
    
    this->pictureRawString=bufferStringRaw;
    this->pictureString=bufferString;
}

int DrawMatrix::getMatrixCell(int x, int y)
{
    return this->matrix[y][x];
}

std::string DrawMatrix::getPictureRawString()
{
    return this->pictureRawString;
}

std::string DrawMatrix::getPictureString()
{
    return this->pictureString;
}

int DrawMatrix::getWidth()
{
    return this->width;
}

int DrawMatrix::getHeight()
{
    return this->height;
}

int DrawMatrix::getCursorXPos()
{
    return this->cursorXPos;    
}

int DrawMatrix::getCursorYPos()
{
    return this->cursorYPos;
}

bool DrawMatrix::isError()
{
    return this->error;
}


void DrawMatrix::flagError()
{
    this->error=true;
}

void DrawMatrix::unFlagError()
{
    this->error=false;
}

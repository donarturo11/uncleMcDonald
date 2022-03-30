#ifndef DRAWMATRIX_H
#define DRAWMATRIX_H

#define MAX_WIDTH 200
#define MAX_HEIGHT 200

#include <iostream>
#include <vector>
#include <map>

class DrawMatrix
{
  public:
     DrawMatrix();
     ~DrawMatrix();
     std::string getPictureString();
     std::string getPictureRawString();
     int getWidth();
     int getHeight();
     int getCursorXPos();
     int getCursorYPos();
     int getMatrixCell(int x, int y);
     void setGeometry(int width, int height);
     void moveCursor(int x, int y);
     void rmoveCursor(int x, int y);
     void draw(int x, int y, int nr);
     void drawLine(int xPosMove, int yPosMove, int nr);
     void fill(int nr);
     void clearPicture();
     void assignSymbol(int nr, std::string symbol);
     void refreshPicture();
     void checkCursor();
     void flagError();
     void unFlagError();
     bool isError();
  protected:
     int width, height;
     int cursorXPos;
     int cursorYPos;
     std::string pictureRawString;
     std::string pictureString;
     std::map<int, std::string> symbolMap;
     int matrix[MAX_WIDTH][MAX_HEIGHT];
     bool error;
     

};


#endif

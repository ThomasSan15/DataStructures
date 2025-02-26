#include <iostream>

using namespace std;

typedef struct{
    int red;
    int green;
    int blue;
}RGBcolor;

typedef struct{
int row;
int col;
RGBcolor *color;
}pixel;

RGBcolor create(int r, int g, int b){
    RGBcolor color;
    color.red = 255;
    color.green = 0;
    color.blue = 0;
    return color;
}

void print(RGBcolor *color){
    cout << color->red << "," << color->green << "," << color->blue << endl;
}
int main(){
  RGBcolor red = create(255,0,0);
  pixel p;
  p.row = 0;
  p.col = 0;
  p.color = &red;

int a = 43;
int *r = &a;
int **q = &r;
int **w = &r;

  print(&red);
    return 0;
}
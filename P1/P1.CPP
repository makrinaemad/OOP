#include <iostream>
#ifndef SETCOLORFUN_H_INCLUDED
#define SETCOLORFUN_H_INCLUDED
#include <windows.h>
#endif // SETCOLORFUN_H_INCLUDED
using namespace std;
class ColoredBox{
private:
    int length;
    int width;
    int colour;
    char character;
    static int area ;
public:
    void set_clr(int);
    void setcharacter(char);
    int getcolour()const;
    char getcharacter()const;
    int getarea();
    void display();
     void displaying_wider();
     void displaying_transposed();
     void SetColor(int ForgC);
     void displaying_Chess(int cl2);
     int getMaxArea();
     ColoredBox(int l,int w);
     ColoredBox(int l,int w,int col,char ch);
     ~ColoredBox();
    };

void  ColoredBox:: SetColor(int ForgC)
 {
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                 //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
}
int ColoredBox::area=0;
    void ColoredBox::set_clr(int cl) {
    colour=cl;}
    void ColoredBox::setcharacter(char ch){
    character=ch;}
    int ColoredBox::getcolour()const{
    return colour;}
    char ColoredBox::getcharacter()const{
    return character;}
    int ColoredBox::getarea(){
    return width*length;}
void ColoredBox::display(){
    SetColor(colour);
for(int i=0;i<length;i++){
    for(int j=0;j<width;j++)
    {cout<< character;}
    cout<<"\n";
    }
    SetColor(15);
}
void ColoredBox::displaying_wider(){
  SetColor(colour);
for(int i=0;i<length;i++){
    for(int j=0;j<width;j++)
    {cout<< character<<" ";}
    cout<<"\n";
    }
    SetColor(15);
}
void ColoredBox::displaying_transposed(){
      SetColor(colour);
for(int i=0;i<width;i++){
    for(int j=0;j<length;j++)
    {cout<< character;}
    cout<<"\n";
    }
    SetColor(15);
}


void  ColoredBox:: displaying_Chess(int cl2){
for(int i=0;i<length;i++){
    for(int j=0;j<width;j++)
    {if(i%2==0){
         if(j%2==0){
                SetColor(colour);
        cout<< character;}
        else{
            SetColor(cl2);
            cout<< character;
        }}
        if(i%2!=0){
         if(j%2!=0){
  SetColor(colour);
        cout<< character;}
        else{
            SetColor(cl2);
            cout<< character;
        }}
    }
    cout<<"\n";
    }
SetColor(15);
}
int ColoredBox:: getMaxArea(){
return max(area,width*length);
}

ColoredBox ::ColoredBox(int l,int w):length(l),width(w),colour(15),character('#'){

 }
  ColoredBox::ColoredBox(int l,int w,int col,char ch):length(l),width(w),colour(col),character(ch){

  }
  ColoredBox::~ColoredBox(){
  area=length*width;
  }
int main()
{
 int len,wid,col,col2;
 char boxChar;
 cout<<"Enter length and width of the box separated by a space: ";
 cin>>len>>wid;
 ColoredBox* cb1;
 cb1 = new ColoredBox(len,wid);
 cb1->display();
 cout<<"Set the box to another color: ";
 cin>>col;
 cb1->set_clr(col);
 cout<<"Displaying Transposed: "<<endl;
 cb1->displaying_transposed();
 //SetBkColor(15);
 cout<<"Displaying Wider: "<<endl;
 cb1->displaying_wider();
 cout<<"Displaying Chess, enter the other color: "<<endl;
 cin>>col2;
 cb1->displaying_Chess(col2);
 cout<<endl<<"Area= "<<cb1->getarea();
 cout<<endl<<"Max Area= "<<cb1->getMaxArea();
 delete cb1;
 cout<<endl<<"Enter length,width,color,character of the box separated by spaces: ";
 cin>>len>>wid>>col>>boxChar;
 ColoredBox* cb2;
 cb2 = new ColoredBox(len,wid,col,boxChar);
 cb2->display();
 cout<<"Displaying Transposed: "<<endl;
 cb2->displaying_transposed();
 cout<<"Displaying Wider: "<<endl;
 cb2->displaying_wider();
 cout<<"Displaying Chess, enter the other color: "<<endl;
 cin>>col2;
 cb2->displaying_Chess(col2);
 cout<<"Displaying original again:"<<endl;
 cb2->display();
 cout<<endl<<"Area= "<<cb1->getarea();
 cout<<endl<<"Max Area= "<<cb1->getMaxArea();
 delete cb2;
 return 0;
}
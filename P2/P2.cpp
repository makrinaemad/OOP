#include<bits/stdc++.h>
#include <fstream>
using namespace std;
class FloatArray{
private:
    int size;
protected:
    float *floats;
    int c;
public:
    FloatArray(int s) :c(0)
    {
        size = s;
        floats = new float[size];
    }
    virtual void Add(float f) {
        if(c<size)
        {
            floats[c]=f;
            c++;
        }
    }
    int getsize(){
        return size;
    }
    friend ifstream& operator >> (ifstream& in,FloatArray  & f)
    {
        float flt;
        for(int i=0;i<f.getsize();i++)
        {
            in >>flt;
            f.Add(flt);
        }
        return in;
    }


    friend ofstream& operator << (ofstream& out, FloatArray  & f)
    {
        out<<f.getsize()<<"|"<<" ";
        for(int i=0;i<f.c;i++)
        {
            out << f.floats[i]<<"  ";
        }
        out<<endl ;
        return out;
    }


    ~  FloatArray(){
        delete []floats;
    }
};
class  SortedArray : public FloatArray{
public:
    SortedArray(int s): FloatArray(s){

    }
    virtual void Add(float f){

        if(c<getsize()){
            floats[c]=f;
            for(int i=c;i>0;i--)
            {
               if(floats[i]<=floats[i-1])
                   swap(floats[i],floats[i-1]);
            }
            c++;
        }
    }
};

class FrontArray:public FloatArray{
public:
    FrontArray(int s): FloatArray(s){

    }
     void Add(float f){

        if(c<getsize()){
            floats[c]=f;
            swap(floats[0],floats[c]);
            for(int i=1;i<c;i++)
            {
                swap(floats[i],floats[c]);
            }
        }
        c++;
    }


};
class PositiveArray:public SortedArray{
public:
    PositiveArray(int s):SortedArray(s)
    {          }
    void Add(float f){
        if(f>0)
            SortedArray:: Add(f);
    }
};
class negativeArray:public SortedArray{
public:
    negativeArray(int s):SortedArray(s)
    {          }
    void Add(float f)
    {
        if(f < 0)
            SortedArray:: Add(f);
    }

};

int main()

{
    int sz;
    FloatArray* theArray[11];
    FloatArray* obj;
    string ifilename,ofilename;
    ifstream ifile;
    ofstream ofile;
    cout<< "enter the name of the input file \n";
    cin>>ifilename;
    cout<<"enter the name of the output file \n";
    cin>>ofilename;
    ifile.open (ifilename.c_str()) ;
    ofile.open(ofilename.c_str());
    for (int i=0;i<10;i++)
    {
        string type;
        ifile>>type;
        ifile>>sz;


        if (type=="Array")
        {
            obj=new FloatArray(sz);
            ifile>>*obj;
            theArray[i]=obj;
        }
        else if (type=="Sorted")
        {
            obj=new SortedArray(sz);
            ifile>>*obj;
            theArray[i]=obj;
        }
        else if (type=="Front")
        {
            obj=new FrontArray(sz);
            ifile>>*obj;
            theArray[i]=obj;
        }
        else if (type=="Positive")
        {
            obj=new PositiveArray(sz);
            ifile>>*obj;
            theArray[i]=obj;
        }
        else if (type=="Negative")
        {
            obj=new negativeArray(sz);
            ifile>>*obj;
            theArray[i]=obj;

        }
        ofile<<*theArray[i];
    }
    for (int i=0;i<10;i++)
    {
        delete theArray[i];
    }
    ifile.close();
    ofile.close();
    return 0;
}
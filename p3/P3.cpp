#include <iostream>
using namespace std;
class Item{
private:
   static int id;
   int ID=id;
    string name;
    float quantity;
    float price;
    //al id fe al copy han8ero wla
public:
Item(){
id++;}
Item(string n,float q,float p){
name=n;
quantity=q;
price=p;
}
Item(const Item &ob){
name=ob.name;
quantity=ob.quantity;
price=ob.price;
id++;
}
void setName(string n){
name=n;
}
void setID(){
ID=id;
}
void setQuantity(float q){
quantity=q;
}
void setPrice(int p){
price=p;
}
string getName(){
return name;
}
float getQuantity(){
return quantity;
}
float getPrice(){
return price;
}
int getID(){
return ID;}

 Item operator-=(  Item ob1)
{
    quantity-=ob1.quantity;

return *this;}

 Item operator+=(  Item ob1)
{
    quantity+=ob1.quantity;

return *this;}
bool operator==(  Item &ob)
{
    if (name==ob.name)
      return true;
  else
      return false;
}

friend istream &operator>>(istream &input,Item&ob)
 {
cout<<"Enter The Name Of an Item,Quantity and Price: \n";
    input>>ob.name>>ob.quantity>>ob.price;
    return input;

 }
friend ostream &operator<<(ostream &output,Item&ob)
 {

    output<<"The ID: "<<ob.ID<<"\nThe Name of an item: "<<ob.name<<"\nThe quantity of an item: "<<ob.quantity<<"\nIts Price: "<<ob.price<<"\n";
    return output;

 }

};
int Item::id=0;

class seller{

private:
    string name,email;
    int maxItems;
    Item *item;
public:
    seller(string n,string e,int mx,Item it[] )
    {
        name=n;
        email=e;
        maxItems=mx;
        item=new Item [maxItems];
       item=it;
    }
     friend istream &operator>>(istream &input,seller&ob)
    {
       input>>ob.name>>ob.email>>ob.maxItems;
       return input;
    }
    friend ostream &operator<<(ostream &output,seller&ob)
    {
       output<<"Name: "<<ob.name<<"\nAn e-mail: "<<ob.email<<"\n";
       return output;
    }
int getMaxItems(){
return maxItems;
}
     void setSellName(string nm)
    {
    name=nm;
    }
     void setSellEmail(string ml)
    {
     email=ml;
    }
    string getSellName()
    {
    return name;
    }

    string getSellMail()
    {
    return email;
    }

int c=0;
bool AddAnItem(Item &it){
     c++;
for(int i=0;i<maxItems;i++)
    {
    if (it==item[i])
        item[i]+=it;
     else{
        if(c<maxItems)
            return true;
        else
            return false;
     }

        }


}

bool SellAnItem(string n,float q)
    {Item it;
    it.setName(n);
    it.setQuantity(q);
        for (int i=0;i<maxItems;i++)
        {
          if (item[i]==it)
            { if(item[i].getQuantity()>=it.getQuantity())
                 item[i]-=it;

          else {cout<<"There is only {"<<item[i].getQuantity()<<"} left for this item"<<endl;}
               }
               else
                return false;
        }
    }

void PrintItems()
{
    for (int i=0;i<maxItems;i++)
    {
        cout <<item[i];
    }
     }

bool FindAnItem(Item &it)
{
    for (int i=0;i<maxItems;i++)
        {
        if ( item[i].getID() == it.getID() )
            {cout << item[i];
                return true;
            }
            else
                return false;
        }
    }

   ~seller()
    {
  delete[]item;
    }
};
int main()
{Item a,Arr[5];
    seller b("Makrina","makrina51@",5,Arr);
    cout << "Enter your Name,e-mail and Capacity"<<endl;
    cin>>b;
    cout<<"Choose the option you need: "
    <<"\n1-Print My Info."
    <<"\n2-Add An Item. "
    <<"\n3-Sell An Item."
    <<"\n4-Print Items. "<<
    "\n5-Find An Item by ID."<<
    "\n6-Exit. \n";
    int n,q;
    string name;
    while (true){cin>>n;
    if (n==1)
          cout<<b;
    else if (n==2)
         {cin>>a;
             b.AddAnItem(a);}
    else if (n==3)
        {cout<<"Enter Name of item and quantity:\n";
           cin>>name>>q;
          b.SellAnItem(name,q);}
    else if (n==4)
          b.PrintItems();
    else if (n==5)
          b.FindAnItem(a);
    else
        return 0;
          cout << "Enter your Name,e-mail and Capacity"<<endl;
          }


    return 0;
}
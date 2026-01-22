#include<iostream>
#include<fstream>
using namespace std;

class student{
    char name[20];
    int rollno;
    float marks;
    public:
        void getdata(){
            cout<<"Enter name: ";
            cin>>name;
            cout<<"Enter rollno: ";
            cin>>rollno; 
            cout<<"Enter marks: ";
            cin>>marks;
        }
        void putdata(){
            cout<<"Name: "<<name;
            cout<<"\nRollno: "<<rollno;
            cout<<"\nMarks: "<<marks;
        }
};

int main()
{
    student obj1,obj2;
    obj1.getdata();
    fstream file;
    file.open("Data",ios::in | ios::out);
    file.write((char*)&obj1,sizeof(obj1));
    
    file.seekg(0);
    file.read((char*)&obj2,sizeof(obj2));
    obj2.putdata();
    return 0;
}
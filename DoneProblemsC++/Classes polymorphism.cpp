#include <iostream>
using namespace std;

class Mammal
{
public:
    Mammal(int ag) {age = ag;};
    void  virtual Eat(){cout << "Mammal eats food" << endl;};
    void  virtual Speak(){cout << "Mammal speaks mammalian!!" << endl;};
    int get_Age(){return age;};

protected:
    int age;
};

//define dog class that inhearted from Mammal class
class Dog: public Mammal
{
public:
    Dog(int ag):Mammal(ag){}
    void Eat(){cout << "Dog eats meat" << endl;}
    void Speak(){cout << "Dog barks : ruff! ruff!" << endl;}
    
};

class Cat: public Mammal
{
public:
    Cat(int ag):Mammal(ag){};
    void Eat(){cout << "Cat eats meat" << endl;};
    void Speak(){cout << "Cat meows: Meow! Meow!" << endl;};
    
};


int main() {
  Mammal *M_obj;
  Dog D_obj(3);
  Cat C_obj(2);

  
  cout << "Calling Dog class functions"<<endl;
  M_obj = &D_obj;
  M_obj->Eat();
  M_obj->Speak();

  cout << "Dog's age is: " << M_obj->get_Age() << endl;
    

    cout << "Calling Cat class functions"<<endl;
    M_obj = &C_obj;
    M_obj->Eat();
    M_obj->Speak();
    cout << "Cat's age is: " << M_obj->get_Age() << endl; //cout the age by calling the get_Age() function here
  
  system("pause");
  return 0;
}
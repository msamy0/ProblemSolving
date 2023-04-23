#include <iostream>
#include <string>
#include <chrono>

using namespace std;

template <class T>
class Complex{
   public:
    Complex(T real, T imaginary){ this->real = real ; this->imaginary = imaginary;}

    T get_real();
    T get_im(){return this->imaginary;}


   private:
    T real;
    T imaginary;
};

template <class T>
T Complex <T>:: get_real(){
    return this->real;
}




int main() {

    cout << endl;
  return 0;
}
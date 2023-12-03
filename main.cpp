// #include<bits/stdc++.h>
#include "LinkedList.h"
#include <algorithm>
#include <ctime>
#include <iostream>
#include <vector>
class Dog {
private:
    std::string name;
    int age;

public:
    // Constructor
    Dog(std::string n, int a) {
      name=n;
      age=a;
    }
    Dog(): name("anon"), age(20){}
    // Member function to bark
    void bark() {
        std::cout << name << " says Woof!" << std::endl;
    }
   void setName(string n)
   {
     name=n;
   }
   string getName()
   {
     return name;
   }
    // Member function to celebrate birthday
    void celebrateBirthday() {
        age++;
        std::cout << "Happy Birthday, " << name << "! Now " << name << " is " << age << " years old." << std::endl;
    }
    
    void setAge(int age)
    {
      this->age=age;
    }
    // Getter function to retrieve the age
    int getAge() const {
        return age;
    }
};
void fun(string balh)
{
  cout<<balh<<endl;
}
int main() {
    // Creating instances of the Dog class
    Dog dog1("Buddy", 2);
    fun("mohamed");
    // Accessing attributes
    std::cout << dog1.getAge() << std::endl;  
    // Calling methods
    dog1.bark();
    int x=dog1.getAge();
    cout<<dog1.getAge();
    // Celebrating birthdays
    dog1.celebrateBirthday();
    dog1.setAge(4);
    // Checking the updated age
    std::cout << "Now, " << dog1.getAge() << " years old." << std::endl;

    return 0;
}

#include <iostream>
#include <string>

using namespace std;
 class car
 {
     public:
        car() {wheels = 4; max_speed = 120; junk_in_trunk = new int[25];}
        ~car() {delete [] junk_in_trunk; junk_in_trunk = NULL;}
        void drive();
        void set_wheels(int num);
     private:
        int wheels;
        int max_speed;
        int* junk_in_trunk;

 };
 class motorcycle
 {
    public:
        motorcycle() {wheels = 2; max_speed = 180; has_helmet = false;}
        motorcycle(string c) {wheels = 2; max_speed = 180; has_helmet = false; color = c;}
        motorcycle(string c, bool helmet) {wheels = 2; max_speed = 180; has_helmet = false; color = c; has_helmet = helmet;}
        void drive();
 
    private:
        int wheels;
        int max_speed;
        bool has_helmet;
        string color;
 };
 void car::drive()
 {
     cout << "Vroom." << endl;
 }
 void car::set_wheels(int num)
 {
     if (num > 18)
     {
         wheels = 18;
     }
     else
     {
        wheels = num;   
     }
 }
 void motorcycle::drive()
 {
     cout << "VRRRRRRRROOOOOOOOOOOOOMMMM" << endl;
     cout << "Oh no! Watch out!" << endl;
     cout << "CRAP!" << endl;
     if (has_helmet)
     {
         cout << "Wow, look at this hospital bill. Good thing I still have a brain." << endl;
     }
     else
     {
         cout << "*splat*" << endl; 
     }
 }
 int main ()
 {
     car c1;
     car c2;
     c2.set_wheels(3);

     motorcycle m;
     motorcycle m2("red");
     motorcycle m3("red", true);
     c1.drive();
     m.drive();
 }
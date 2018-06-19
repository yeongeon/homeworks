#include <iostream>

using namespace std;


template <typename T>
T add(T a, T b) { 
   return a + b; 
}

class Employee {
    protected:
        string name;
        int* birth;
        int now;

    public:
        Employee(){
            now = 2018;
        }

        string get_name(){
            return name;
        }

        virtual int how_old(int birth){
            return now-birth;
        }
};

class Tom : public Employee {
    public:
        Tom(string n, string f, int _now){
            name = add(n, f);
            now = _now;
        }

        string get_name(){
            return name;
        }

        virtual int how_old(int birth){
            return add(now, -1*birth);
        }
};

class Lewis : public Employee {
    private:
        int month;

    public:
        Lewis(string n, string f, int _now, int _month){
            name = add(n, f);
            now = _now;
            month = _month;
        }

        string get_name(){
            return name;
        }

        virtual int how_old(int birth){
            return add((now-birth)*12, month);
        }
};


int main(){
    int now = 2018;
    int month = 5;
    Tom* tom = new Tom("tom", "cat", now);
    Lewis* lewis = new Lewis("lewis", "kim", now, month);

    Employee* ptr_emp;

    ptr_emp = tom;
    cout << ptr_emp->get_name() << " :: " << ptr_emp->how_old(1982);
    cout << " years since " << now << endl;

    ptr_emp = lewis;
    cout << ptr_emp->get_name() << " :: " << ptr_emp->how_old(1982);
    cout << " months since "<< now << endl;
}
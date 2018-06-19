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

        int how_old(int birth){
            return now-birth;
        }
};

class Tom : public Employee {
    public:
        Tom(string n, string f, int _now){
            name = add(n, f);
            now = _now;
        }

        int how_old(int birth){
            return add(now, birth*-1);
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

        int how_old(int birth){
            return add((now-birth)*12, month);
        }
};


int main(){
    int now = 2018;
    Tom* tom = new Tom("tom", "cat", now);
    cout << tom->get_name() << " :: " << tom->how_old(1982);
    cout << " years since " << now << endl;

    int month = 5;
    Lewis* lewis = new Lewis("lewis", "kim", now, month);
    cout << lewis->get_name() << " :: " << lewis->how_old(1982);
    cout << " months since "<< now << endl;
}
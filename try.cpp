#include <iostream>
using namespace std;

class Box
{
private:
    double length;
    double width;
    double heigth;

public:
    Box(int = 1, int = 1, int = 1);  //初始化的办法
    /*析构函数*/
    ~Box()
    {
        cout<<"Destructor called."<<endl;
    }
    int volumn() const  //常函数，它不能修改数据的值，只能引用
    {
        return length * width * heigth;
    }
    friend istream& operator>>(istream&, Box&);
    friend ostream& operator<<(ostream&, Box&);
    friend double operator+ (const Box& a, const Box& b);
};

/*参数初始化表*/
Box::Box(int l, int w, int h):length(l), width(w), heigth(h){}

/**有数组作为数据成员的情况，要在函数体里对数组进行复制
Student(int n, char s, nam[]):name(n), sex(s){strcpy(name,nam);}
**/

/*指向成员函数的指针*/
void (Box::*p)();

/*指向对象的常指针*/
Box const *p1 = 0; //常指针的值不能被改变

/*指向常对象的指针*/
const Box *p2 = 0;  //可以指向常变量，并且如果指向普通变量，不能用 p2 改变指向的值

/*常引用*/
//const Box &t;

/*常对象*/
const Box Box1(1, 2, 3);
Box const Box2(3, 2, 1);//与上面等价

/*类模板*/
template <class numtype>
class Compare
{
public:
    Compare(numtype a, numtype b)
    {
        x = a;
        y = b;
    }
    numtype max()
    {
        return (x > y) ? x : y;
    }
private:
    numtype x, y;
};

/*使用方式*/
Compare <int> cmp(4,7);

/*重载插入运算符和提取运算符*/
istream& operator>> (istream& cin, Box &a)
{
    cin>>a.length>>a.width>>a.heigth;
    return cin;
}

ostream& operator<< (ostream& cout, Box &b)
{
    cout<<b.length<<b.width<<b.heigth;
    return cout;
}

/*转换构造函数*/
/***
Complex(double r){real = r; imag = 0;}

operator double()
{
    return real; //只能作为成员函数
}
***/


/*派生类的构造函数*/
/**
Student1(int n, string nam, char s, int a, string ad):Student(n,nam, s) //声明哪些是父类中出现的数据
{
    age = a;  //派生类中新出现的数据成员
    addr = ad;
}
**/

double operator+ (const Box& a, const Box& b)
{
    return a.volumn() + b.volumn();
}

int main()
{

}

#include <iostream>
using namespace std;

class Box
{
private:
    double length;
    double width;
    double heigth;

public:
    Box(int = 1, int = 1, int = 1);  //��ʼ���İ취
    /*��������*/
    ~Box()
    {
        cout<<"Destructor called."<<endl;
    }
    int volumn() const  //���������������޸����ݵ�ֵ��ֻ������
    {
        return length * width * heigth;
    }
    friend istream& operator>>(istream&, Box&);
    friend ostream& operator<<(ostream&, Box&);
    friend double operator+ (const Box& a, const Box& b);
};

/*������ʼ����*/
Box::Box(int l, int w, int h):length(l), width(w), heigth(h){}

/**��������Ϊ���ݳ�Ա�������Ҫ�ں��������������и���
Student(int n, char s, nam[]):name(n), sex(s){strcpy(name,nam);}
**/

/*ָ���Ա������ָ��*/
void (Box::*p)();

/*ָ�����ĳ�ָ��*/
Box const *p1 = 0; //��ָ���ֵ���ܱ��ı�

/*ָ�򳣶����ָ��*/
const Box *p2 = 0;  //����ָ�򳣱������������ָ����ͨ������������ p2 �ı�ָ���ֵ

/*������*/
//const Box &t;

/*������*/
const Box Box1(1, 2, 3);
Box const Box2(3, 2, 1);//������ȼ�

/*��ģ��*/
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

/*ʹ�÷�ʽ*/
Compare <int> cmp(4,7);

/*���ز������������ȡ�����*/
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

/*ת�����캯��*/
/***
Complex(double r){real = r; imag = 0;}

operator double()
{
    return real; //ֻ����Ϊ��Ա����
}
***/


/*������Ĺ��캯��*/
/**
Student1(int n, string nam, char s, int a, string ad):Student(n,nam, s) //������Щ�Ǹ����г��ֵ�����
{
    age = a;  //���������³��ֵ����ݳ�Ա
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

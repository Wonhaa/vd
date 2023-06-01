
#include<iostream>
#include<iomanip>
using namespace std;

class lophoc;
class Person
{
protected:
    char hoten[30];
    char ngsinh[20];
    char quequan[30];
public:
    void nhap();
    void xuat();
};

class sinhvien:public Person
{
protected:
    int masv;
    char nganh[30];
    int khoahoc;
public:
    void nhap();
    void xuat();
    friend class lophoc;
    friend void dem(lophoc a);
    friend void sortClass(lophoc &a);
};

class lophoc
{
protected:
    int malh;
    char tenlh[30];
    char ngaymo[30];
    sinhvien x[20];
    int n;
    char giaovien[30];
public:
    void nhap();
    void xuat();
    friend void dem(lophoc a);
    friend void sortClass(lophoc &a);
};

void sinhvien::nhap()
{

    cout<<"Nhap ho ten: ";                  fflush(stdin);gets(hoten);
    cout<<"Nhap Ngay sinh: ";               fflush(stdin);gets(ngsinh);
    cout<<"Nhap Que quan: ";                fflush(stdin);gets(quequan);
    cout<<"Nhap Ma sv: ";                   cin>>masv;
    cout<<"Nhap Nganh: ";                   fflush(stdin);gets(nganh);
    cout<<"Nhap Khoa hoc: ";                cin>>khoahoc;

}
void sinhvien::xuat()
{
    cout <<setw(15)<<hoten;
    cout <<setw(15)<<ngsinh;
    cout <<setw(15)<<quequan;
    cout <<setw(15)<<masv;
    cout <<setw(15)<<nganh;
    cout <<setw(15)<<khoahoc<<endl;
}

void lophoc::nhap()
{
    cout<<"Nhap Ma lh: ";                   cin>>malh;
    cout<<"Nhap Ten lh: ";                  fflush(stdin);gets(tenlh);
    cout<<"Nhap Ngay mo: ";                 fflush(stdin);gets(ngaymo);
    cout<<"Nhap gv: ";                      fflush(stdin);gets(giaovien);
    cout << "\nNhap so sinh vien: ";        cin>>n;
    for ( int i=0;i<n;i++)
    {
        cout << "Nhap sinh vien thu "<<i+1<<endl;
        x[i].nhap();
    }
}
void lophoc::xuat()
{
    cout <<left<< "Ma lop: "<<setw(15)<<malh<< "Ten lop: "<<setw(15)<<tenlh<< "Ngay mo: "<<setw(15)<<ngaymo<< "Giao vien: "<<setw(15)<<giaovien<<endl;
    cout <<setw(15)<<"Hoten";
    cout <<setw(15)<<"Ngay sinh";
    cout <<setw(15)<<"Que quan";
    cout <<setw(15)<<"Ma sinh vien";
    cout <<setw(15)<<"Nganh";
    cout <<setw(15)<<"Khoa hoc"<<endl;
    for ( int i=0;i<n;i++)
    {
        x[i].xuat();
    }
}
void dem(lophoc a)
{
    int cnt=0;
    for (int i=0; i<a.n; i++)
    {
        if (a.x[i].khoahoc == 11)
        {
            cnt++;
        }
    }
    cout<<"\nSo sinh vien khoa 11 la: "<<cnt<<endl;
}
void sortClass(lophoc& a)
{

    for (int i=0 ; i < a.n - 1; i++)
    {
        for (int j=i+1; j<a.n; j++ )
        {

            if (a.x[i].khoahoc > a.x[j].khoahoc)
            {
                sinhvien k = a.x[i];
                a.x[i] = a.x[j];
                a.x[j] = k;
            }
        }
    }
}
int main()
{
    lophoc a;
    a.nhap();
    a.xuat();
    dem(a);
    sortClass(a);
    a.xuat();
    return 0;
}

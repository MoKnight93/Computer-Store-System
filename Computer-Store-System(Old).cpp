#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>
typedef long long ll;
using namespace std;
class computers
{
public:
    void lenovo()
    {
        cout << "Brand: Lenovo\n";
        cout << "Name: Lenovo Legion 5\n";
        cout << "Color: Black\n";
        cout << "CPU: Intel core i7\n";
        cout << "GPU: GTX 1660 Ti\n";
        cout << "Storage: 1 TB\n";
        cout << "OS Type: Windows 10\n";
        cout << "Camera: 18 MP\n";
        cout << "RAM: 16 GB\n";
        cout << "VRAM: 6 GB\n";
        cout << "Salary: 21000\n";
    }
    void apple()
    {
        cout << "Brand: Apple\n";
        cout << "Name: Apple MacBook Pro Late 2020\n";
        cout << "Color: Silver\n";
        cout << "CPU: APPLE M1\n";
        cout << "GPU: APPLE\n";
        cout << "Storage: 512 GB\n";
        cout << "OS Type= IOS\n";
        cout << "Camera: 48 MP\n";
        cout << "RAM: 8 GB\n";
        cout << "VRAM: 6 GB\n";
        cout << "Salary: 25000\n";
    }
    void dell()
    {
        cout << "Brand: Dell\n";
        cout << "Name: Dell G5 15-5500\n";
        cout << "Color: Black\n";
        cout << "CPU: Intel core i5\n";
        cout << "GPU: RTX 2060\n";
        cout << "Storage: 512 GB\n";
        cout << "OS Type= Dos\n";
        cout << "Camera: 8 MP\n";
        cout << "RAM: 16 GB\n";
        cout << "VRAM: 6 GB\n";
        cout << "Salary: 18000\n";
    }
        void msi()
    {
        cout << "Brand: MSI\n";
        cout << "Name: MSI GF65\n";
        cout << "Color: Black\n";
        cout << "CPU: Intel core i9\n";
        cout << "GPU: RTX 3060\n";
        cout << "Storage: 2 TB\n";
        cout << "OS Type= Windows 10\n";
        cout << "Camera: 18 MP\n";
        cout << "RAM: 32 GB\n";
        cout << "VRAM: 8 GB\n";
        cout << "Salary: 24000\n";
    }
        void hp()
    {
        cout << "Brand: HP\n";
        cout << "Name: HP OMEN 15\n";
        cout << "Color: Black\n";
        cout << "CPU: Intel core i7\n";
        cout << "GPU: GTX 1660 Ti\n";
        cout << "Storage: 1 TB\n";
        cout << "OS Type= Windows 10\n";
        cout << "Camera: 18 MP\n";
        cout << "RAM: 8 GB\n";
        cout << "VRAM: 4 GB\n";
        cout << "Salary: 19500\n";
    }
    void r_a_m(int a)
    {
        if(a == 16)
        {
            cout << "We have\n";
            lenovo();
            cout << endl;
            dell();
        }
        else if(a == 8)
        {
            cout << "We have\n";
            apple();
            cout << endl;
            hp();
        }
        else if(a == 32)
        {
            cout << "We have\n";
            msi();
        }
    }
    void v_r_a_m(int b)
    {
        if(b == 6)
        {
            cout << "We have\n";
            lenovo();
            cout << endl;
            dell();
            cout << endl;
            apple();
        }
        else if(b == 8)
        {
            cout << "We have\n";
            msi();
        }
        else if(b == 4)
        {
            cout << "We have\n";
            hp();
        }
    }
    void os_type(string c)
    {
        if(c == "windows")
        {
            cout << "We have\n";
            lenovo();
            cout << endl;
            hp();
            cout << endl;
            msi();
        }
        else if(c == "ios")
        {
            cout << "We have\n";
            apple();
        }
        else if(c == "dos")
        {
            cout << "We have\n";
            hp();
        }
    }
    void hard_disk(int d)
    {
        if(d == 1)
        {
            cout << "We have\n";
            lenovo();
            cout << endl;
            hp();
        }
        else if(d == 2)
        {
            cout << "We have\n";
            msi();
        }
        else if(d == 512)
        {
            cout << "We have\n";
            dell();
            cout << endl;
            apple();
        }
    }
    void cam_era(int e)
    {
        if(e == 18)
        {
            cout << "We have\n";
            lenovo();
            cout << endl;
            msi();
            cout << endl;
            hp();
        }
        else if(e == 48)
        {
            cout << "We have\n";
            apple();
        }
        else if(e == 8)
        {
            cout << "We have\n";
            dell();
        }
    }
};
class user:public computers
{
private:
    string name,email;
    int phone;
public:
    string num(string n)
    {
        name=n;
        return name;
    }
    string e_mail(string m)
    {
        email=m;
        return email;
    }
    int numb(int u)
    {
        phone = u;
        return phone;
    }
    void receipt(string re)
    {

        if(re == "Lenovo")
        {
            cout << "User Name: " << name << endl;
            cout << "User Phone: " << phone << endl;
            cout << "User Email: " << email << endl;
            cout << endl;
            cout << "Product Name: Lenovo Legion 5\n";
            cout << "Product Information: " ;
			lenovo();
        }
        else if(re == "Dell")
        {
            cout << "User Name: " << name << endl;
            cout << "User Phone: " << phone << endl;
            cout << "User Email: " << email << endl;
            cout << endl;
            cout << "Product Name: Dell G5 15-5500\n";
            cout << "Product Information: ";
			dell();
        }
        else if(re == "HP")
        {
            cout << "User Name: " << name << endl;
            cout << "User Phone: " << phone << endl;
            cout << "User Email: " << email << endl;
            cout << endl;
            cout << "Product Name: HP OMEN 15\n";
            cout << "Product Information: " ;
			hp();
        }
        else if(re == "Apple")
        {
            cout << "User Name: " << name << endl;
            cout << "User Phone: " << phone << endl;
            cout << "User Email: " << email << endl;
            cout << endl;
            cout << "Product Name: Apple MacBook Pro Late 2020\n";
            cout << "Product Information: " ;
			apple();
        }
        else if(re == "MSI")
        {
            cout << "User Name: " << name << endl;
            cout << "User Phone: " << phone << endl;
            cout << "User Email: " << email << endl;
            cout << endl;
            cout << "Product Name: MSI GF65\n";
            cout << "Product Information: " ;
			msi();
        }
    }
};
int main()
{
    computers x;
    user y;
    int r,vr,sto,cam,p;
    string str,str1,str2,str3,str4,str5,str6,str7,os,na,em,ds,fds;
    do
    {
    cout << "Welcome to Comp_Store, Thank you for choosing our store, What are you looking for Brand or Technical Details? \n" << "User: ";
    cin >> str;
    cout << endl;
    if(str == "Brand")
    {
        cout << "Which device's brand you are looking for?\n" << "User: ";
        cin >> str1;
        cout << endl;
        if(str1 == "Lenovo")
        {
            cout << "We have\n";
            x.lenovo();
        }
        else if(str1 == "Apple")
        {
            cout << "We have\n";
            x.apple();
        }
        else if(str1 == "Dell")
        {
            cout << "We have\n";
            x.dell();
        }
        else if(str1 == "HP")
        {
            cout << "We have\n";
            x.hp();
        }
        else if(str1 == "MSI")
        {
            cout << "We have\n";
            x.msi();
        }
    }
    else if(str == "Technical")
    {
        jump:
        cout << "Which device's technical details you are looking for?\n" << "User: ";
        cin >> str2;
        cout << endl;
        if(str2 == "RAM")
        {
            cout << "How Much RAM Do You Need?\n" << "User: ";
            cin >> r;
            x.r_a_m(r);
        }
        else if(str2 == "VRAM")
        {
            cout << "How Much VRAM Do You Need?\n" << "User: ";
            cin >> vr;
            x.v_r_a_m(vr);
        }
        else if(str2 == "OS-Type")
        {
            cout << "Which Operating System Type Do You Need?\n" << "User: ";
        }
        else if(str2 == "Storage")
        {
            cout << "How Much Hard Disk Capacity Do You Need?\n" << "User: ";
            cin >> sto;
            x.hard_disk(sto);
        }
        else if(str2 == "Camera")
        {
            cout << "Which Camera Type Do You Need?\n" << "User: ";
            cin >> cam;
            x.cam_era(cam);
        }
    }
    cout << endl;
    cout << "Do you want to inquire about something else? \n" << "User: ";
    cin >> str7;
    if(str7 == "yes")
    {
        goto jump;
    }
    cout << "Now, Would you like to take another look at the devices before making your decision? \n" << "User: ";
    cin >> str3;
    }while(str3 == "yes");
    cout << endl;
    l:
    cout << "Make your decision..... \n" << "User: ";
    cin >> str4;
    cout << str4 <<", Remember you can modify your order.....modify !! \n" << "User: ";
    cin >> str6;
    if(str6 == "no")
    {
        str4;
    }
    else if(str6 == "yes")
    {
        cout << "we will show you all the devices for you to choose..... \n";
        x.lenovo();
        cout << endl;
        x.dell();
        cout << endl;
        x.hp();
        cout << endl;
        x.apple();
        cout << endl;
        x.msi();
        cout << endl;
        cout << "Make your final decision..... \n" << "User: ";
        cin >> str4;
    }
    cout << endl;
    cout << "we will order it ,Payment method(Cash or Credit) \n" << "User: ";
    cin >> str5;
    cout << endl;
    cout << " Add personal information about you to complete the purchase \n" << "Your name: ";
    cin >> na;
    cout << "Your Phone: ";
    cin >> p;
    cout << "Your Email: ";
    cin >> em;
    y.num(na);
    y.numb(p);
    y.e_mail(em);
    cout << endl;
    cout << "Here is the receipt..... \n";
    cout << endl;
    y.receipt(str4);
    cout << endl;
    cout << "Successful purchase";
    cout << endl;
    return 0;
}

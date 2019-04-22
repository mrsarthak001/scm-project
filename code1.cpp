#include<iostream .h>
#include<conio .h>
#include<string .h>
#include<graphics .h>
#include<dos .h>
#include<stdio .h>
#include<fstream .h>
#include<iomanip .h>
#include<stdlib .h>



//********************************************
// THIS CLASS CONTAINS FUNTIONS FOR FOOD
//********************************************


class food
{
private:
    fstream p1;
    int c;
    char ap;
    struct fd
    {
        char name[55];
        float price;
    } f;
public:
    food()
    {
        c=0;
    }
    void food_menu(void);
    void app_fmenu(void);
    void food_bill();
    void del_all();
};

//************
//  FUNCTION TO DELETE FOOD MENU
//**********
void food::del_all()
{
    remove("food.txt");
    p1.open("food.txt",ios::out);
    p1.close();
    c=0;
}

//*******************
//  FUNCTION FOR DISPLAYING FOOD MENU
//*******************

void food::food_menu(void)
{
    cleardevice();
    setfillstyle(7,1);
    floodfill(0,0,4);
    setfillstyle(7,10);
    bar(17,40,605,420);
    rectangle(17,40,605,420);
    setfillstyle(1,10);
    bar(24,47,598,413);
    rectangle(24,47,598,413);
    p1.close();
    c=0;
    p1.open("food.txt",ios::in|ios::binary);
    outtextxy(30,50,"S.N.       ITEM NAME             PRICE");
    gotoxy(4,5);
    char h[5],pr[15];
    while(p1.read((char*)&f,sizeof(f)))
    {
        c++;
        settextstyle(4,0,1);
        itoa(c,h,10);
        outtextxy(40,60+20*c,h);
        outtextxy(150,60+20*c,f.name);
        itoa(f.price,pr,10);
        outtextxy(390,60+20*c,pr);
    }//END OF WHILE
    p1.close();
    settextstyle(15,0,1);
    outtextxy(30,325,"DO YOU WANT TO ADD AN ITEM - (Y/N)");
    gotoxy(60,20);
    cin>>ap;
    if(ap=='y'||ap=='Y')
    {
        app_fmenu();
        //CALLING APPEND FUNCTION
    }
    else
    {
        if(ap=='n'||ap=='N')
        {
            outtextxy(30,360,"DO YOU WANT TO DELETE ALL  (Y/N)");
            char ch;
            gotoxy(60,23);
            cin>>ch;
            if(ch=='y'||ch=='Y')
            {
                del_all();
                //CALLING DELETE FUNCTION
            }
        }
    }
}

//**********
//  FUNCTION FOR ROOM BILL
//********

    void room_bill()
    {
        double bill;
        int days,no,dt,mth;
        cleardevice();
        setfillstyle(7,1);
        floodfill(0,0,4);
        setfillstyle(7,10);
        bar(17,40,605,420);
        rectangle(17,40,605,420);
        setfillstyle(1,7);
        bar(24,47,598,413);
        rectangle(24,47,598,413);
        setcolor(4);
        settextstyle(7,0,1);
        outtextxy(30,70,"ENTER CUSTOMER NO DEPARTING");
        gotoxy(50,6);
        cin>>no;
        outtextxy(30,120,"DATE OF DEPARTURE");
        gotoxy(50,9);
        cin>>dt;
        outtextxy(30,170,"MONTH OF DEPARTURE");
        gotoxy(50,12);
        cin>>mth;
        if(p.a_month>mth)
        {
            bill=0;
        }
        f1.close();
        f1.open("cust.txt",ios::in|ios::binary);
        int c=0;
        while(f1.read((char*)&p,sizeof(p)))
        {
            if(p.c_no==no)
            {
                c++;
                if(p.a_month==mth)
                {
                    days=dt-p.a_date;
                }
                else
                {
                    days=(mth-p.a_month)*30+(dt-p.a_date);
                }
                if(p.room_no<=11)
                {
                    char d[5],m[5],h[5],mt[5],dy[5],bl[5];
                    bill=days*250;
                    setcolor(4);
                    outtextxy(30,270," NAME    ARRIVAL    DEPARTURE    DAYS IN    BILL ");
                    setcolor(1);
                    settextstyle(1,0,1);
                    outtextxy(40,300,p.c_name);
                    itoa(p.a_date,d,10);
                    outtextxy(150,300,d);
                    outtextxy(160,300,"/");
                    itoa(p.a_month,m,10);
                    outtextxy(170,300,m);
                    itoa(dt,h,10);
                    outtextxy(270,300,h);
                    outtextxy(280,300,"/");
                    itoa(mth,mt,10);
                    outtextxy(290,300,mt);
                    itoa(days,dy,10);
                    outtextxy(405,300,dy);
                    itoa(bill,bl,10);
                    outtextxy(515,300,bl);
                }
                else
                {
                    char d[5],m[5],h[5],mt[5],dy[5],bl[5];
                    bill=days*150;
                    setcolor(4);
                    outtextxy(30,270," NAME    ARRIVAL    DEPARTURE    DAYS IN    BILL ");
                    setcolor(1);
                    settextstyle(1,0,1);
                    outtextxy(40,300,p.c_name);
                    itoa(p.a_date,d,10);
                    outtextxy(150,300,d);
                    outtextxy(160,300,"/");
                    itoa(p.a_month,m,10);
                    outtextxy(170,300,m);
                    itoa(dt,h,10);
                    outtextxy(270,300,h);
                    outtextxy(280,300,"/");
                    itoa(mth,mt,10);
                    outtextxy(290,300,mt);
                    itoa(days,dy,10);
                    outtextxy(405,300,dy);
                    itoa(bill,bl,10);
                    outtextxy(510,300,bl);
                }
                f1.close();
                int count=1;
                f1.open("cust.txt",ios::in| ios::binary);
                fstream f2;
                while(f1.read((char*)&p,sizeof(p)))
                {
                    if(p.c_no==no)
                    {
                        continue;
                    }
                    else
                    {
                        f2.open("dup.txt",ios::app|ios::binary);
                        p.c_no=count;
                        f2.write((char*)&p,sizeof(p));
                        count++;
                        f2.close();
                    }
                }//END OF WHILE
                remove("cust.txt");
                rename("dup.txt","cust.txt");
                f1.close();
            }
        }//END OF WHILE
        if(c==0)
        {
            for(int i=0; i<=10; i++)
            {
                settextstyle(1,0,3);
                setcolor(4);
                outtextxy(150,300,"CUSTOMER IS NOT PRESENT");
                delay(100);
                setcolor(WHITE);
                outtextxy(150,300,"CUSTOMER IS NOT PRESENT");
                delay(100);
            }
        }


        getch();
    }

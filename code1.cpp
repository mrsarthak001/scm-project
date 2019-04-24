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


//*************
//  FUNCTION TO APPEND IN FOOD MENU
//*************

void food::app_fmenu(void)
{
    p1.open("food.txt",ios::app|ios::binary);
    outtextxy(30,360,"ENTER ITEM NAME U WANTTO ADD");
    gotoxy(60,23);
    gets(f.name);
    outtextxy(30,380,"ENTER THE PRICE");
    gotoxy(60,24);
    cin>>f.price;
    p1.write((char*)&f,sizeof(f));
    p1.close();
    getch();
}

//************
//  FUNCTION FOR CUSTOMER BILL
//***********
void cust_bill()
{
     int cho;
      do
      {
            cleardevice();
            f1.close();
            setfillstyle(7,1);
            floodfill(0,0,4);
            setfillstyle(7,10);
            bar(10,70,600,450);
            rectangle(10,70,600,450);
            setfillstyle(1,7);
            bar(17,77,593,443);
            rectangle(17,77,593,443);
            setcolor(5);
            setfillstyle(1,2);
            settextstyle(7,0,1);
            setcolor(9);
            setfillstyle(1,2);
            bar(210,140,410,238);
            rectangle(210,140,410,158);
            rectangle(210,140,410,174);
            rectangle(210,140,410,190);
            rectangle(210,140,410,206);
            rectangle(210,140,410,222);
            rectangle(210,140,410,238);
            setcolor(4);
            settextstyle(1,0,4);
            outtextxy(180,20,"HOTEL BILL");
            line(180,60,383,60);
            setcolor(4);
            settextstyle(1,0,1);
            outtextxy(210,137,"  1.  ROOM BILL");
            outtextxy(210,170,"  2.  FOOD BILL");
            outtextxy(210,200,"  3.  MAIN MENU");
            outtextxy(63,318,"ENTER CHOICE FOR WHICH YOU WANT THE BILL");
            gotoxy(67,21);
            cin>>cho;
            choose(cho);
     }
     while(cho!=3); //END OF WHILe//
}

void choose(int a)
{
    switch(a)
    {
        case 1:
        {
            room_bill();
            break;
        }
        case 2:
        {
            j.food_bill();
            break;
        }
        case 3:break;
   }
}


//****************
//  FUNCTION FOR MODIFYING CUSTOMER DETAIL
//****************

void cust_mod()
{
        cleardevice();
        f1.close();
        setfillstyle(7,1);
        floodfill(0,0,4);
        setfillstyle(7,10);
        bar(10,10,600,470);
        rectangle(10,10,600,470);
        setfillstyle(1,7);
        bar(17,17,593,463);
        rectangle(17,17,593,463);
        setcolor(9);
        setfillstyle(1,2);
        setcolor(4);
        int no;//,count=0;
        outtextxy(30,42,"ENTER CUSTOMER NO TO BE MODIFIED");
        gotoxy(65,4);
        cin>>no;
        f1.open("cust.txt",ios::in|ios::binary);
=======
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

                f1.close();
                int num=sizeof(p)*(no-1);
                f1.open("cust.txt",ios::out|ios::ate|ios::binary);
                f1.seekp(num,ios::beg);
                outtextxy(30,110,"ENTER NEW RECORD ");
                outtextxy(30,150,"NAME");
                gotoxy(30,11);
                cin>>p.c_name;
                outtextxy(30,200,"ADDRESS");
                gotoxy(30,14);
                cin>>p.c_add;
                outtextxy(30,250,"DATE");
                gotoxy(30,17);
                cin>>p.a_date;
                outtextxy(30,300,"MONTH");
                gotoxy(30,20);
                cin>>p.a_month;
                outtextxy(30,350,"YEAR");
                gotoxy(30,23);
                cin>>p.a_year;
                f1.write((char*)&p,sizeof(p));
                f1.close();
            }
        }//END OF WHILE
        getch();
}

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


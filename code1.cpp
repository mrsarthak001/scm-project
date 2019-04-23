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

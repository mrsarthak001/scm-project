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
//***********
//  FUNCTION FOR FOOD BILL
//***********

void food::food_bill()
{
    double bill=-1;
    char c_name[20],f_name[20];
    int dt;
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
    outtextxy(30,70,"ENTER CUSTOMER NAME ");
    gotoxy(50,6);
    cin>>c_name;
    outtextxy(30,120,"ENTER ITEM NAME TAKEN");
    gotoxy(50,9);
    cin>>f_name;
    outtextxy(30,170,"ENTER THE QUANTITY");
    gotoxy(50,12);
    cin>>dt;
    p1.close();
    p1.open("food.txt",ios::in|ios::binary);
    while(p1.read((char*)&f,sizeof(f)))
    {
        if(strcmp(f.name,f_name)==0)
        {
            bill=dt*f.price;
        }
    }//END OF WHILE
    if(bill==-1)
    {
        setcolor(1);

        for(int i=0; i<=20; i++)
        {
            setcolor(1);
            outtextxy(30,220,"ITEM IS NOT PRESENT");
            delay(100);
            setcolor(WHITE);
            outtextxy(30,220,"ITEM IS NOT PRESENT");
            delay(100);
            //  delay(2500);
        }
    }
    else
    {
        char t[5],b[5];
        setcolor(1);
        itoa(dt,t,10);
        itoa(bill,b,10);
        outtextxy(30,250,"NAME FOOD.NAME      QUANTITY      BILL ");
        setcolor(1);
        settextstyle(4,0,1);
        outtextxy(30,280,c_name);
        outtextxy(140,280,f_name);
        outtextxy(320,280,t);
        outtextxy(445,280,b);
        getch();
    }
}
//*************
// THIS CLASS CONTAINS INFORMATION
//   RELATED TO CUSTOMER
//*************


class customer
{
private:
    int q,w;
    fstream f1;
    struct cust
    {
        int c_no;
        char c_name[20];
        char c_add[80];
        int a_date;
        int a_month;
        int a_year;
        int d_date;
        int d_month;
        int d_year;
        int room_no;
        char room_type[25];
    } p;
public:
    food j;

    customer()
    {
        p.c_no=0;
        p.d_date=0;
        p.d_month=0;
    }
//**************
//  FUNCTION TO DISPLAY CUSTOMER DETAIL
//**************

    void cust_detail()
    {
        int c;
        do
        {
            cleardevice();
            setfillstyle(7,1);
            floodfill(0,0,4);
            setfillstyle(7,10);
            bar(50,80,600,470);
            rectangle(50,80,600,470);
            setfillstyle(1,7);
            bar(57,87,593,463);
            rectangle(57,87,593,463);
            setcolor(9);
            setfillstyle(1,2);
            bar(210,140,410,254);
            rectangle(210,140,410,158);
            rectangle(210,140,410,174);
            rectangle(210,140,410,190);
            rectangle(210,140,410,206);
            rectangle(210,140,410,222);
            rectangle(210,140,410,238);
            rectangle(210,140,410,254);
            setcolor(4);
            settextstyle(1,0,4);
            outtextxy(160,20,"CUSTOMER DETAIL ");
            setcolor(14);
            line(163,60,475,60);
            setcolor(4);
            settextstyle(1,0,1);
            outtextxy(225,137,"  CHOICES ARE :-");
            setcolor(4);
            settextstyle(1,0,1);
            outtextxy(210,154," 1. APPEND");
            outtextxy(210,170," 2. MODIFY");
            outtextxy(210,186," 3. DELETE ");
            outtextxy(210,202," 4. DELETE ALL ");
            outtextxy(210,218," 5. DISPLAY ");
            outtextxy(210,234," 6. MAIN MENU");
            setcolor(4);
            settextstyle(7,0,2);
            outtextxy(210,300,"ENTER CHOICE :- ");
            gotoxy(53,20);
            cin>>c;
            switch(c)
            {
            case 1:
            {
                cust_app();
                break;
            }
            case 2:
            {
                cust_mod();
                break;
            }
            case 3:
            {
                cust_del();
                break;
            }
            case 4:
            {
                cust_adel();
                break;
            }
            case 5:
            {
                cust_disp();
                break;
            }
            }
        }
        while(c!=6); //END OF WHILE
    }

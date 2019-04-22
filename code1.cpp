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

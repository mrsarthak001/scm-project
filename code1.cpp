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


class food//initializing class name food//
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

//************************
//  FUNCTION OF ENDING
//************************

    void bye()
    {
        cleardevice();
        setcolor(12);
        settextstyle(1,0,5);
        setbkcolor(BLUE);
        outtextxy(70,150,"THANKS FOR VISITING");
        setcolor(10);
        settextstyle(1,0,8);
        outtextxy(100,250,"PROJECT");
        settextstyle(1,0,3);
        outtextxy(150,450,"SHUTTING DOWN.. . .");
        getch();
        setcolor(12);
        settextstyle(1,0,5);
        outtextxy(70,150,"THANKS FOR VISITING");
        setcolor(10);
        settextstyle(1,0,8);
        outtextxy(100,250,"PROJECT");
        settextstyle(1,0,3);
        outtextxy(150,450,"SHUTTING DOWN.. . .");

        for(int i=0; i<=10; i++)//loop//
        {
            sound(1000*i);
            setbkcolor(i);
            nosound();
        }
    }

/


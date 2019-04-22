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

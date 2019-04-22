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

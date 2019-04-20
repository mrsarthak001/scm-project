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

/ / * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
/ / FUNCTI ON FOR DI SPLAYI NG FOOD MENU
/ / * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
voi d f ood: : f ood_menu( voi d)
{
cl ear devi ce( ) ;
set f i l l st yl e( 7, 1) ;
f l oodf i l l ( 0, 0, 4) ;
set f i l l st yl e( 7, 10) ;
bar ( 17, 40, 605, 420) ;
r ect angl e( 17, 40, 605, 420) ;
set f i l l st yl e( 1, 10) ;
bar ( 24, 47, 598, 413) ;
r ect angl e( 24, 47, 598, 413) ;
p1. cl ose( ) ;
c=0;
p1. open( " f ood. t xt " , i os: : i n| i os: : bi nar y) ;
out t ext xy( 30, 50, " S. N. I TEM NAME PRI CE" ) ;
got oxy( 4, 5) ;
char h[ 5] , pr [ 15] ;
whi l e( p1. r ead( ( char * ) &f , si zeof ( f ) ) )
{
c++;
set t ext st yl e( 4, 0, 1) ;
i t oa( c, h, 10) ;
out t ext xy( 40, 60+20* c, h) ;
out t ext xy( 150, 60+20* c, f . name) ;
i t oa( f . pr i ce, pr , 10) ;
out t ext xy( 390, 60+20* c, pr ) ;
} / / END OF WHI LE
    
    

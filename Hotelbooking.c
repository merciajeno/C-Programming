#include <string.h>
#include <stdio.h>
struct Hotel
{
char name[50];
char aadhar[14];//including spaces in between
char phone[10];
int no_of_person;//max 180
int days;
int res;
char cancel;
}h[180];
int verification(char aadhar[14]);
int cnumber(int*cl_room1_ptr,int*cl_room2_ptr,int*cl_room3_ptr,int );
int lnumber(int*l_room1_ptr,int*l_room2_ptr,int*l_room3_ptr,int );
void cbilling(int);
void lbilling(int);
int PhoneVerification(char phone[10]);
int main()
{
    char chance;
    int rem;
    int d;
    int tc1,tc2,tc3,tl1,tl2,tl3;
    tc1=tc2=tc3=tl1=tl2=tl3=15;
    int crooms_available=45,lrooms_available=45;
    int *cl_room1_ptr,*cl_room2_ptr,*cl_room3_ptr,*l_room1_ptr,*l_room2_ptr,*l_room3_ptr;
    int cl_room1=15,cl_room2=15,cl_room3=15;
    int l_room1=15,l_room2=15,l_room3=15;
    cl_room1_ptr=&cl_room1,cl_room2_ptr=&cl_room2,cl_room3_ptr=&cl_room3;
    l_room1_ptr=&l_room1,l_room2_ptr=&l_room2,l_room3_ptr=&l_room3;
//Hotel Booking


printf("------------------------------------------------------------------------------------------------------------");
printf("\n                             Welcome to Hotel Laura Stone:");
printf("\n**********************************************************************************************************");
int op;
char package;


char c;
int i=0;
int ch;
int rem_no_of_person=0;
if((crooms_available==0) && (lrooms_available==0))
printf("\nSorry all the packages are over."
" Room Booking closed...........................  ");

while_again:while((crooms_available!=0)||(lrooms_available!=0))
{
    rem_no_of_person+=h[i].no_of_person;
    printf("\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
    printf("\nNo. of rooms under classic package is %d ",crooms_available);
    printf("\nNo. of rooms under luxury package is %d ",lrooms_available);
printf("\nFor person%d:",++i);
printf("\nEnter your name:");
scanf(" %[^\n]s",h[i].name);
aadhar_again:printf("\nEnter your aadhar number including spaces in between:");
scanf(" %[^\n]s",h[i].aadhar);
int ver=verification(h[i].aadhar);
if(ver!=0)
{
phone:printf("\nEnter your phone number:");
scanf(" %s",h[i].phone);
int phone_verify=PhoneVerification(h[i].phone);
if(phone_verify==0)
{
    printf("\nInvalid phone number!!!!");
    goto phone;
}
printf("\nEnter the stay period:");
scanf("%d",&h[i].days);

l:printf("\nNo of persons : Maximum people is 90 under each package");
scanf("%d",&h[i].no_of_person);

if(h[i].no_of_person>(180-rem_no_of_person))
{
    printf("\nOnly %d persons can be accomodated.",(180-rem_no_of_person));
    h[i].no_of_person=0;
    printf("\nIf you want to reduce the no. of persons, press Y or if you want to cancel the ticket, press any letter:");
    scanf(" %c",&c);
    if(c=='Y')
    goto l;
    else {
        printf("\nYour room booking is cancelled");
        goto while_again;
    };
}



if(h[i].no_of_person<=90)
{
again:printf("\nWe , Hotel Laura Stone ,provide 2 packages and feel free to choose any one of the two: ");
printf("\n1. Classic Package");
printf("\n- Fee per person per day:1000");
printf("\n- Amenities provided here - only POOL which costs 100/day");
printf("\n- free Breakfast but lunch and dinner requires payment of 100 for each");
printf("\n- Parking of your vehicle is free");
printf("\n- If you are staying more than 10 days, then there is a  5 per cent Discount");


printf("\n--------------------------------------------------------------------------\n");
printf("\n2.Luxury Package");
printf("\n- Fee per person per day: 2500");
printf("\n- Amenities provided here - POOL AND SPA  which  together costs 500/day");
printf("\n- Breakfast , lunch and dinner requires payment of 800 each");
printf("\n- Parking of your vehicle costs 500/day");
printf("\n- If you are staying for more than 10 days,then there is a discount of 30 percent ");
printf("\nChoose any one of the above options:");
scanf("%d",&op);

switch_again:switch(op){

classic: case  1:
printf("\n");
printf("\nAvailability of rooms accomodating single person is %d",*cl_room1_ptr);
printf("\nAvailability of rooms accomodating  two people are %d",*cl_room2_ptr);
printf("\nAvailability of rooms accomodating three people are %d",*cl_room3_ptr);
if((cl_room1==0)&&(cl_room2==0)&&(cl_room3==0))
{printf("\nClassic Package is fully utilised!!");
goto again;
}
crooms_available=cnumber(cl_room1_ptr,cl_room2_ptr,cl_room3_ptr,i);
if(h[i].cancel=='Y')
goto can;
printf("\nLooks like you have booked only for %d people",(tc1-*cl_room1_ptr)*1+(tc2-*cl_room2_ptr)*2+(tc3-*cl_room3_ptr)*3);
h[i].no_of_person=(tc1-*cl_room1_ptr)*1+(tc2-*cl_room2_ptr)*2+(tc3-*cl_room3_ptr)*3;
cbilling(i);
tc1=*cl_room1_ptr,tc2=*cl_room2_ptr,tc3=*cl_room3_ptr;
crooms_available=*cl_room1_ptr+*cl_room2_ptr+*cl_room3_ptr;

break;
luxury:case 2:
printf("\n");
printf("\nAvailability of rooms accomodating single person is %d",*l_room1_ptr);
printf("\nAvailability of rooms accomodating  two people are %d",*l_room2_ptr);
printf("\nAvailability of rooms accomodating three people are %d",*l_room3_ptr);
if((l_room1==0)&&(l_room2==0)&&(l_room3==0))
{printf("\nLuxury Package is fully utilised!!");
goto again;
}
lrooms_available=lnumber(l_room1_ptr,l_room2_ptr,l_room3_ptr,i);
if(h[i].cancel=='Y')
goto can;
printf("\nLooks like you have booked only for %d people",(tl1-*l_room1_ptr)*1+(tl2-*l_room2_ptr)*2+(tl3-*l_room3_ptr)*3);
h[i].no_of_person=(tl1-*l_room1_ptr)*1+(tl2-*l_room2_ptr)*2+(tl3-*l_room3_ptr)*3;
lbilling(i);
tl1=*l_room1_ptr,tl2=*l_room2_ptr,tl3=*l_room3_ptr;
lrooms_available=*l_room1_ptr+*l_room2_ptr+*l_room3_ptr;

break;
default:
printf("\nInvalid option!!. Please try again");
goto switch_again;
}


   

}
else{
printf("\n Sorry for inconvenience. A person can choose only package at a time and each package allows only 90 people");
    printf("\nIf you want to reduce the number , enter Y or if you want to cancel the ticket, enter any letter:");
    scanf(" %c",&chance);
    if(chance=='Y')
    goto l;
    else
    {
        h[i].no_of_person=0;
        printf("\nBooking cancelled!!");
        goto while_again;
    }
}
}
else
{printf("\n Your aadhar is invalid");
    goto aadhar_again;
}
if(h[i].cancel=='Y')
can:printf("\nBooking cancelled");
}
if((crooms_available==0) && (lrooms_available==0))
printf("\nSorry all the packages are over."
" Room Booking closed...........................  ");


return 0;
}

int cnumber(int *cl_room1_ptr,int *cl_room2_ptr,int *cl_room3_ptr,int i)
{
    char c,t1;
    int single,doubl,triple;

    s1:printf("\nChoose how many rooms accomodating one person do you want?");
    scanf("%d",&single);
    if(single>*cl_room1_ptr){
    printf("\nSorry only %d rooms are available",*cl_room1_ptr);single=0;
        goto s1;
    }
   s2: printf("\nChoose how many rooms accomodating two person do you want?");
    scanf("%d",&doubl);
    if(doubl>*cl_room2_ptr)
    {printf("\nSorry only %d rooms are available",*cl_room2_ptr);doubl=0;
        goto s2;
    }
   s3: printf("\nChoose how many rooms accomodating three person do you want?");
    scanf("%d",&triple);
    if(triple>*cl_room3_ptr)
    {printf("\nSorry only %d rooms are available",*cl_room3_ptr);triple=0;
        goto s3;
    }
    printf("\nIf you want to cancel the entire ticket,enter Y or else enter any other key:");
    scanf(" %c",&t1);
    if(t1=='Y')
    {
        h[i].cancel='Y';
        single=triple=doubl=0;
        goto r;
    }
    printf("\nIf you want to cancel  certain rooms enter Y or else enter any key:");
    scanf(" %c",&c);
    if(c=='Y')
    goto s1;
    if((single*1+doubl*2+triple*3)>h[i].no_of_person)
    {
       
        printf("\nLooks like you have booked more than the inputted value, please try again:");
        goto s1;
    }
    r:*cl_room1_ptr-=single;
    *cl_room2_ptr-=doubl;
    *cl_room3_ptr-=triple;
    
    int res;
    res=45-(single+doubl+triple);
    return res;
    
}

int lnumber(int *l_room1_ptr,int *l_room2_ptr,int *l_room3_ptr,int i)
{
    char c,t1;
    int single,doubl,triple;

    s1:printf("\nChoose how many rooms accomodating one person do you want?");
    scanf("%d",&single);
    if(single>*l_room1_ptr){
    printf("\nSorry only %d rooms are available",*l_room1_ptr);single=0;
        goto s1;
    }
   s2: printf("\nChoose how many rooms accomodating two person do you want?");
    scanf("%d",&doubl);
    if(doubl>*l_room2_ptr)
    {printf("\nSorry only %d rooms are available",*l_room2_ptr);doubl=0;
        goto s2;
    }
   s3: printf("\nChoose how many rooms accomodating three person do you want?");
    scanf("%d",&triple);
    if(triple>*l_room3_ptr)
    {printf("\nSorry only %d rooms are available",*l_room3_ptr);triple=0;
        goto s3;
    }
    printf("\nIf you want to cancel the entire ticket, enter Y or else enter any other letter:");
    scanf(" %c",&t1);
    if(t1=='Y')
    {
        h[i].cancel='Y';
        single=doubl=triple=0;
        goto r;
    }
    printf("\nIf you want to cancel certain rooms ,enter Y or else any other key :");
    scanf(" %c",&c);
    if(c=='Y')
    goto s1;
    if((single*1+doubl*2+triple*3)>h[i].no_of_person)
    {
       
        printf("\nLooks like you have booked more than the inputted value, please try again:");
        goto s1;
    }
    r:*l_room1_ptr-=single;
    *l_room2_ptr-=doubl;
    *l_room3_ptr-=triple;
    
    int res;
    res=45-(single+doubl+triple);
    return res;
    
}

int verification(char aadhar[14])
{
    int i,ctr=0;
    
    if(strlen(aadhar)==14&& aadhar[0]!=0 && aadhar[0]!=1 && aadhar[4]==' ' && aadhar[9]==' ')
    {
        for(i=0;i<4;i++)
        {
            if(aadhar[i]>='0'&&aadhar[i]<='9')
            ctr++;
        }
        for(i=5;i<9;i++)
        {
            if(aadhar[i]>='0'&&aadhar[i]<='9')
            ctr++;
        }
        for(i=10;i<14;i++)
        {
            if(aadhar[i]>='0'&&aadhar[i]<='9')
            ctr++;
        }
        if(ctr==12)
        return 1;
        else return 0;
    }
    else return 0;
}

void cbilling(int i)
{
    int pool_days;
    pool:printf("\nEnter the number of days you want to utilise the pool:");
    scanf("%d",&pool_days);
   if(pool_days>h[i].days)
    {
        printf("\nPool days are more than the days you will live here. Please try again!!");
        goto pool;
    }
    int res;
    res=h[i].no_of_person*h[i].days*(2*100  +1000)+pool_days*100;
    if(h[i].days>10)
    {
        printf("\nSince your stay period is more than 10, there is discount of 5 percent");
        res=res-(5/100*res);
    }
    printf("\nTHANKS FOR BOOKING. WE HOPE THAT YOU HAVE WONDERFUL STAY");
    printf("\nHere is your bill");
    printf("\nNAME:%s",h[i].name);
    printf("\nAADHAR NUMBER:%14s",h[i].aadhar);
    printf("\nPHONE NUMBER:%10s",h[i].phone);
    printf("\nSTAY PERIOD:%d",h[i].days);
    printf("\nNo.of persons accomodating :%d",h[i].no_of_person);
    printf("\n***********************BILL**********************");
    printf("\nFee per person is:%d",1000);
    printf("\nParking Charges:%d",0);
    printf("\nFood Charges:%d",h[i].days*2*100);
    printf("\nPool charges:%d",pool_days*100);
    printf("\n------------------------------------------");
    printf("\nTotal fees:%d",res);
}


void lbilling(int i)
{
    int res;
    char c;
    int pool_days;
    int spa_days;
   pool: printf("\nEnter the number of days you want to utilise the pool:");
    scanf("%d",&pool_days);
    if(pool_days>h[i].days)
    {
        printf("\nPool days are more than the days you will live here. Please try again!!");
        goto pool;
    }
   spa: printf("\nEnter the number of days you want to allot for spa treatment:");
   if(spa_days>h[i].days)
    {
        printf("\nSpa days are more than the days you will live here. Please try again!!");
        goto spa;
    }
    scanf("%d",&spa_days);
    printf("\nClick Y if you have a vehicle");
    scanf(" %c",&c);
    if(c=='Y')
    res=h[i].no_of_person*h[i].days*(3*800+2500+500)+pool_days*500+spa_days*500;
    else
    res=h[i].no_of_person*h[i].days*(3*800+2500)+pool_days*500+spa_days*500;
    
    if(h[i].days>10)
    {
        printf("\nSince your stay period is more than 10 days, you have a discount of 30 percent");
        res=res-(30*res/100);
    }
    printf("\nTHANKS FOR BOOKING. WE HOPE THAT YOU HAVE WONDERFUL STAY");
    printf("\nHere is your bill");
    printf("\nNAME:%s",h[i].name);
    printf("\nAADHAR NUMBER:%14s",h[i].aadhar);
    printf("\nPHONE NUMBER:%10s",h[i].phone);
    printf("\nSTAY PERIOD:%d",h[i].days);
    printf("\nNo.of persons accomodating :%d",h[i].no_of_person);
    printf("\n***********************BILL**********************");
    printf("\nFee per person is:%d",2500);
    if(c=='Y')
    printf("\nParking Charges:%d",500);
    else
    printf("\nParking Charges:%d",0);
    printf("\nFood Charges:%d",h[i].days*3*800);
    printf("\nPool charges:%d",pool_days*500);
    printf("\nSpa charges:%d",spa_days*500);
    printf("\n------------------------------------------");
    printf("\nTotal fees:%d",res);
}

int PhoneVerification(char phone[10])
{
    int i;
    
    int ctr=0;
    int phone_length=strlen(phone);
    if(phone_length==10)
    {
        for(i=0;i<10;i++)
        {
            if(phone[i]>='0'&&phone[i]<='9')
            ctr++;
        }
        if(ctr==10)
        return 1;
        else
        return 0;
    }
    else return 0;
}

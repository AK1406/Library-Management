
#include<conio.h>
#include<iostream.h>
#include<string.h>
#include<dos.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip.h>
void cate_books();
void search1();
void mbr_record();
void IR();
void menu();
void trs_record();
void sts_record();
void del_trs();
void del_sts();
void del_books();
void search_sts();
void search_sts();
void search1();
void search2();
void add_sts();
void add_trs();
void add_books();
void kids();
void study_mat();
void mag();
void non_fic_books();
void fic_books();
void cate_books();
void begin();
void borrow_sts();
void borrow_trs();
void trs_ir();
void sts_ir();
void title();
void title2();
void title3();
void display1(struct Books);
void display2();
void display4();
void displayI_R();
void titleI_R();
int count=0;
int accno=100;
int ch;
struct Books
 {
   int acc_no;
   char books_title[40];
   char writer[40],author[40];
   float price;
   int qty;
 } B[100];
int rec=0;
int choice;
struct Mbr_Record
 {
   int std,id_no;
   char name[20],iss_bk_name[20];
   char mob_no[11];
   int dd,mm,yy;
 }R[100];


//******************************TITLE*****************************
void title()
 {
   clrscr();
   cout<<"\n\n\nBook Code\tBook Name\t  Author\t\tPrice\t\tQuantity"<<endl;
 }
//**************************** Title for I_R **************************
void titleI_R()
 {
   clrscr();
   cout<<"\n\n\tIdno.\t\Name\tIssue Date\tReturn Date";
 }
//*************************** Display I_R ******************************
void displayI_R(Mbr_Record R[])
{
  titleI_R();
  for(int i=0;i<rec;i++)
  cout<<"\n\t\t"<<setw(4)<<R[i].id_no<<"\t"<<setw(7)<<R[i].name<<"\t"<<setw(1)<<R[i].dd<<"/"<<setw(1)<<R[i].mm<<"/"<<setw(1)<<R[i].yy;
  getch();
}


//***************************** STUDENT i_r ***************************
void sts_ir()
{ int dd,mm,yy;
char name[30];
int std;
int stu_id;
cout<<"\t\t\t Fill your details"<<endl;
cout<<"\n IDno: \t\t\tName: \t\t\tClass: ";
fflush(stdin);
gotoxy(15,3);
cin>>stu_id;
gotoxy(38,3);
fflush(stdin);
cin>>name;
gotoxy(63,3);
fflush(stdin);
cin>>std;
gotoxy(5,4);
cout<<"\n\tIssue Date:";
cin>>dd;
gotoxy(19,4);
cout<<"/";
dd=dd+14;
gotoxy(21,4);
cin>>mm;
gotoxy(24,4);
cout<<"/";
gotoxy(26,4);
cin>>yy;
if(mm==1||mm==3||mm==5||mm==7||mm==8||mm==10||mm==12)
{
if(dd>31)
mm=mm+1;
if(mm>12)
yy=yy+1;
if(dd>31)
dd=dd-31;
if(mm>12)
mm=mm-12;
}
if(mm==4||mm==6||mm==9||mm==11)
{
if(dd>30)
mm=mm+1;
 if(mm>12)
 yy=yy+1;
if(dd>30)
dd=dd-30;
}
if(mm==2)
{
if(dd>28)
mm=mm+1;
 if(mm>12)
 yy=yy+1;
if(dd>28)
dd=dd-28;
}
search1();
clrscr();
cout<<"\n\t\t Returning date:"<<dd<<"/"<<mm<<"/"<<yy;
getch();

}

//****************************** Teacher i_r *************************
void trs_ir()
 { int dd,mm,yy;
char name[30];
int std;
int stu_id;
cout<<"\t\t Fill your details";
cout<<"\n\n\t IDno:\t\t\tName:";
fflush(stdin);
gotoxy(15,3);
cin>>stu_id;
gotoxy(38,3);
fflush(stdin);
cin>>name;
gotoxy(63,3);
fflush(stdin);
gotoxy(5,4);
cout<<"\n\tIssue Date:";
cin>>dd;
gotoxy(19,4);
cout<<"/";
dd=dd+14;
gotoxy(21,4);
cin>>mm;
gotoxy(24,4);
cout<<"/";
gotoxy(26,4);
cin>>yy;
if(mm==1||mm==3||mm==5||mm==7||mm==8||mm==10||mm==12)
{
if(dd>31)
mm=mm+1;
if(mm>12)
yy=yy+1;
if(dd>31)
dd=dd-31;
if(mm>12)
mm=mm-12;
}
if(mm==4||mm==6||mm==9||mm==11)
{
if(dd>30)
mm=mm+1;
 if(mm>12)
 yy=yy+1;
if(dd>30)
dd=dd-30;
}
if(mm==2)
{
if(dd>28)
mm=mm+1;
 if(mm>12)
 yy=yy+1;
if(dd>28)
dd=dd-28;
}
search1();
clrscr();
cout<<"\n\t Returning date:"<<dd<<"/"<<mm<<"/"<<yy;
getch();
}

//***************************** Issue & Return ********************
void IR()
{       clrscr();
  textcolor(YELLOW);
  clrscr();
  cout<<"\n";
  cprintf("                ==============================");
  textcolor(RED);
  cout<<"\n";
  cprintf("                   Issue & Return of Books");
  textcolor(YELLOW);
  cout<<"\n";
  cprintf("                ==============================");
  cout<<"\n\n\t\t1.Students"<<endl;
  cout<<"\n\t\t2.Teachers"<<endl;
  cout<<"\n\t\t3.Exit"<<endl;
  cout<<"\n\n\n\t\tEnter your choice [1 or 3]: ";
  char ch;
  fflush(stdin);
  cin>>ch;
  switch(ch)
  {
    case '1':clrscr();

	     sts_ir(); //for students
	     break;
    case '2':clrscr();

	     trs_ir();  //for teachers
	     break;
    case '3':break;
    default:cout<<"\n\n\t\tInvalid choice !! Try again";
	    exit(0);
 }
}
//***************************** Borrowing of books by students ****************************
void borrow_sts()
{ textcolor(YELLOW);
  clrscr();
  cout<<"\n";
  cprintf("              ========================");
  textcolor(GREEN);
  cprintf("\n               Borrowing of books ");
  textcolor(YELLOW);
  cout<<"\n";
  cprintf("              ========================");
  cout<<"\n\n\t\tDo you want to issue any book ?[y/n]: ";
  cin>>ch;
   if(ch=='y'||ch=='Y')
    {
      sts_ir();
    }
   else
      cout<<"\n\n\n\t\tDon't want to issue";
      getch();
}

//**************************** Borrowing of books by teachers *****************
void borrow_trs()
{ textcolor(YELLOW);
  clrscr();
  cout<<"\n";
  cprintf("                    ========================");
  textcolor(GREEN);
  cprintf("\n                     Borrowing of books ");
  textcolor(YELLOW);
  cout<<"\n";
  cprintf("                    ========================");
  cout<<"\n\n\t\tDo you want to issue any book ?[y/n]: ";
  cin>>ch;
   if(ch=='y'||ch=='Y')
    {
      trs_ir();

    }
   else
      cout<<"\n\n\n\t\tDon't want to issue";
      getch();
}
 //**************************** BEGINING **************************

void begin()
{
 clrscr();
  int i,j;
  gotoxy(10,5);
  for(i=0;i<=10;i++)
{
 cout<<"*";
}
  cout<<" WELCOME TO SCHOOL LIBRARY ";
  for(i=10;i>=0;i--)
{
  cout<<"*";
}
{
 const char U_P[]="dimpi*7*";
 const char U_I[]="Anju";
 char name[30];
 char pass[40];
  cout<<"\n";
  gotoxy(20,10);
  cout<<"ID-NAME  : ";
   cin>>name;
  gotoxy(20,12);
  cout<<"PASSWORD : ";
  cin>>pass;
  if((strcmp(U_I,name)==0)&&(strcmp(U_P,pass)==0))
      {
	char st[]=" \n\n\n\n\t\t\tLOADING PROGRAM.....";
	for(i=0;i<strlen(st);i++)

	  {  clrscr();
	     for(j=0;j<=i;j++)
	      cout<<st[j];
	     delay(500);
	   }
      }
   else
   {
       cout<<"\n\n\n\n\n\n\t\t         INCORRECT !!!!";
       getch();
       exit(0);
       }
}
}
//********************CATEGORIES OF BOOKS******************
void cate_books()
  {
  char choice;
 do {
      clrscr();
     textcolor(BLUE);
     clrscr();
     cprintf("\n                 Categories Of Books");
     textcolor(YELLOW);
     cout<<"\n";
     cprintf("               ==============================");
     cout<<"\n\n\t\t\t1.Fiction books"<<endl;
     cout<<"\n\t\t\t2.Non-Fiction books"<<endl;
     cout<<"\n\t\t\t3.Magazines"<<endl;
     cout<<"\n\t\t\t4.Study Materials"<<endl;
     cout<<"\n\t\t\t5.Books for kids"<<endl;
     cout<<"\n\t\t\t6.exit"<<endl;
     cout<<"\n\tEnter your choice[1....6]:";
     fflush(stdin);
     cin>>choice;
     switch(choice)
      {
	case '1':clrscr();
	       cout<<"Function for displaying Fiction books";
	       fic_books();

	       break;
	case '2':clrscr();
	       cout<<"Function for displaying Non-Fictionn books";
	       non_fic_books();
	       break;
	case '3':clrscr();
	       cout<<"Function for displaying Magazines";
	       mag();
	       break;
	case '4':clrscr();
	       cout<<"Function for displaying Study Materials";
	       study_mat();
	       break;
	case '5':clrscr();
	       cout<<"Function for displaying Books for kids";
	       kids();
	       break;
	case'6':clrscr();
	       cout<<"Thanks for using this program !!";
	       break;
	default:cout<<"Please try again,enter[1....6]";
     }

   }while(choice!='6');
 }
//******************************DISPLAY 1****************************
void display1(Books B[])
{
  title();
  for(int i=0;i<count;i++)
    cout<<"\n"<<setw(5)<<B[i].acc_no<<"\t\t"<<setw(7)<<B[i].books_title<<"\t\t"<<setw(7)<<B[i].author<<"\t\t"<<setw(12)<<B[i].price<<"\t\t"<<setw(4)<<B[i].qty;
    getch();
}
//************************** display 2(books)  **********************************
void display2()
{
  title();
  for(int i=0;i<count;i++)
   cout<<"\n"<<setw(5)<<B[i].acc_no<<"\t\t"<<setw(7)<<B[i].books_title<<"\t\t"<<setw(7)<<B[i].author<<"\t\t"<<setw(12)<<B[i].price<<"\t\t"<<setw(4)<<B[i].qty;
   }
//************************Record Display 3(student) ****************************************
  void display3(Mbr_Record R[])
{
  title2();
  for(int i=0;i<rec;i++)
    cout<<"\n\t\t"<<setw(5)<<R[i].id_no<<"\t\t"<<setw(7)<<R[i].name<<"\t\t\t"<<setw(4)<<R[i].std;
    getch();
}
//************************ Display 4 (teacher)****************************************
  void display4(Mbr_Record R[])
{
  title3();
  for(int i=0;i<count;i++)
    cout<<"\n"<<setw(5)<<R[i].id_no<<"\t\t"<<setw(7)<<R[i].name<<"\t\t"<<setw(10)<<R[i].mob_no;
    getch();
}
//***************************FICTION************************************
void fic_books()
{
 textcolor(YELLOW);
  clrscr();
 cout<<"\n";
 cprintf("                       ===================");
 textcolor(BROWN);
  clrscr();
 cprintf("\n                       Fiction Books");
 textcolor(YELLOW);
  cout<<"\n";
 cprintf("                       ===================");
 cout<<"\n\n\t1.Addition of books"<<endl;
 cout<<"\n\t  2.Displaying of books"<<endl;
 cout<<"\n\t  3.Search for any book"<<endl;
 cout<<"\n\t  4.Remove any book"<<endl;
 cout<<"\n\t  5.Exit"<<endl;
 cout<<"\n\n\tEnter your choice [1 or 5]: ";
 char ch;
 fflush(stdin);
 cin>>ch;
 switch(ch)
 { case '1': add_books();
	   break;
   case '2': display1(B);
	   break;
   case '3': search2();
	   break;
   case '4': del_books();
	   break;
   case '5':break;
   default: cout<<"\n\t invalid choice !! Try again";
	     getch();
	    exit(0);
  }
}
//********************************Non-FICTION***************************
void non_fic_books()
{
 textcolor(BLUE);
  clrscr();
 cout<<"\n";
 cprintf("                    ======================");
 textcolor(YELLOW);
 cprintf("\n                    Non-Fiction Books");
 textcolor(BLUE);
 cout<<"\n";
 cprintf("                     ===================");
 cout<<"\n\n\t1.Addition of books"<<endl;
 cout<<"\n\t  2.Displaying of books"<<endl;
 cout<<"\n\t  3.Search for any book"<<endl;
 cout<<"\n\t  4.Remove any book"<<endl;
 cout<<"\n\t  5.Exit"<<endl;
 cout<<"\n\n\tEnter your choice [1 or 5]: ";
 char ch;
 fflush(stdin);
 cin>>ch;
 switch(ch)
 { case '1': add_books();
	   break;
   case '2': display1(B);
	   break;
   case '3': search2();
	   break;
   case '4': del_books();
	   break;
   case '5':break;
   default: cout<<"\n\t invalid choice !! Try again";
	    exit(0);
  }
getch();
}
//*******************************MAGAZINES*******************************
void mag()
{
  textcolor(YELLOW);
   clrscr();
   cout<<"\n";
  cprintf("                  ==========================");
  textcolor(RED);
  cout<<"\n";
  cprintf("                     Collection of Magaines");
  textcolor(YELLOW);
  cout<<"\n";
  cprintf("                  ========================");
  cout<<"\n\n\t\t1.Andhra Bhoomi\n\t\t2.Andhra Jyoti\n\t\t3.Chandamama\n\t\t4.Rythubandhu";
  cout<<"n\n\n\t\t enter any key to exit";
  getch();
}
//******************************* Study Materials **********************
void study_mat()
{
 textcolor(RED);
  clrscr();
  cout<<"\n";
 cprintf("                   =====================");
 textcolor(BROWN);
 cout<"\n";
 cprintf("                      Study Materials");
 textcolor(RED);
 cout<<"\n";
 cprintf("                   =====================");
 cout<<"\n\n\t 1.Addition of books"<<endl;
 cout<<"\n\t   2.Displaying of books"<<endl;
 cout<<"\n\t   3.Search for any book"<<endl;
 cout<<"\n\t   4.Remove any book"<<endl;
 cout<<"\n\t   5.Exit"<<endl;
 cout<<"\n\n\t\tEnter your choice [1 or 5]: ";
 char ch;
 fflush(stdin);
 cin>>ch;
 switch(ch)
 { case '1': add_books();
	   break;
   case '2': display2();
	   break;
   case '3': search2();
	   break;
   case '4': del_books();
	   break;
   case '5':break;
   default: cout<<"\n\t invalid choice !! Try again";
	    exit(0);
  }
getch();
}
//**********************************BOOKS FOR KIDS************************
void kids()
{
 textcolor(YELLOW);
  clrscr();
 cout<<"\n";
 cprintf("                  =====================");
 textcolor(BLUE);
 cout<<"\n";
 cprintf("                     Books for Kids");
 textcolor(YELLOW);
 cout<<"\n";
 cprintf("                  ======================");
 cout<<"\n\n\t1.Addition of books"<<endl;
 cout<<"\n\t  2.Displaying of books"<<endl;
 cout<<"\n\t  3.Search for any book"<<endl;
 cout<<"\n\t  4.Remove any book"<<endl;
 cout<<"\n\t  5.Exit"<<endl;
 cout<<"\n\n\tEnter your choice [1 or 5]: ";
 char ch;
 fflush(stdin);
 cin>>ch; //choice
 {
 switch(ch)
  { case '1': add_books();
	   break;
    case '2': display1(B);
	   break;
    case '3': search2();
	   break;
    case '4': del_books();
	   break;
    case '5':break;
    default: cout<<"\n\t invalid choice !! Try again";
	     exit(0);
   }

 getch();
}
  }
//*****************************ADDING OF BOOKS*************************
void add_books()
{
  clrscr();
B[count].acc_no=accno+count;
cout<<"\n\n\t Enter the detail of book \n";
cout<<"\n\t Enter the book title=";
 fflush(stdin);
 gets(B[count].books_title);
 fflush(stdin);
 cout<<"\n\t Enter the name of author=";
 gets(B[count].author);
 fflush(stdin);
 cout<<"\n\t Enter the cost of book=";
 cin>>B[count].price;
 cout<<"\n\t Enter the Quantity=";
 fflush(stdin);
 cin>>B[count].qty;
 count++;
 getch();
}

//************************* Adding of students record *******************
void add_sts(Mbr_Record R[])
{
 int idno=100;
 idno=idno+rec;
 cout<<"\n\t Enter the detail of student \n";
 R[rec].id_no=idno;
 cout<<"\n\t Enter the student name =";
 gets(R[rec].name);
 fflush(stdin);
 cout<<"\n\t Enter the class =";
 cin>>R[rec].std;
 rec++;
 getch();
}
//************************* Adding of teachers record *******************
  void add_trs(Mbr_Record R[])
{ int idno=100;
 idno=idno+rec;
 cout<<"\n\t Enter the detail of teacher \n";
 cout<<"\n\t Enter the teacher's name =";
 gets(R[rec].name);
 fflush(stdin);
 cout<<"\n\t Enter the mobile no =";
 gets(R[rec].mob_no);
 fflush(stdin);
 rec++;
 getch();
}
//****************************** SEARCHING ******************************
void search1()
{
  clrscr();
  textcolor(RED);
  cprintf("\n     In which categories do you want to search ??");
  textcolor(YELLOW);
  cout<<"\n";
  cprintf("    =====================================================");
  cout<<"\n\t\t1.Fiction Books"<<endl;
  cout<<"\n\t\t2.Non-Fiction Books"<<endl;
  cout<<"\n\t\t3.Magazines"<<endl;
  cout<<"\n\t\t4.Study Materials"<<endl;
  cout<<"\n\t\t5.Books for kids"<<endl;
  cout<<"\n\t\t6.Exit"<<endl;
  cout<<"\n\tEnter your choice [1...6]: ";
  char ch;
  fflush(stdin);
  cin>>ch;
  switch(ch)
  { case '1':clrscr();
	     fic_books();
	     break;
    case '2':clrscr();
	     non_fic_books();
	     break;
    case '3':clrscr();
	     mag();
	     break;
    case '4':clrscr();
	     study_mat();
	     break;
    case '5':clrscr();
	     kids();
	     break;
    case '6':break;
    default:cout<<"\n\n\t Invalid choice !! Try again";
	    getch();
	    exit(0);
  }
}
//**************************** Search 2 **********************************
void search2()
{
  int code,found=0;
  cout<<"\n\tEnter Book code:";
  fflush(stdin);
  cin>>code;
  title();
  for(int i=0;i<count;i++)
  {
   if(B[i].acc_no==code)
     {
       found=found+1;
       cout<<"\n"<<setw(5)<<B[i].acc_no<<"\t\t"<<setw(7)<<B[i].books_title<<"\t\t"<<setw(7)<<B[i].author<<"\t\t"<<setw(12)<<B[i].price<<"\t\t"<<setw(4)<<B[i].qty;
       getch();
       cout<<"\n\t\tDo you want to issue this book ?[y/n]: ";
       fflush(stdin);
       char ch;
       fflush(stdin);
       cin>>ch;
	if(ch=='y'||ch=='Y')
	   {
	     //del_books();
	   }
	else
	   {cout<<"\n\tNot issued";
	   getch();
	   return;
	  }
     }}
   if(found==0)
      cout<<"\n\t Book not in Library";
   getch();

}
//**************************** Search for student ***********************
void search_sts()
{ int ch,idcode,found=0;
  cout<<"\n\n\tEnter student Id_no: ";
  cin>>idcode;
  title2();
  for(int i=0;i<rec;i++)
   if(R[i].id_no==idcode)
     {
       found=1;
	 cout<<"\n\t\t"<<setw(5)<<R[i].id_no<<"\t\t"<<setw(7)<<R[i].name<<"\t\t"<<setw(10)<<R[i].std;
	 }
   if(found==0)
      cout<<"\n\tNot found in the Record";
   getch();
}
//***************************** Search for teacher **********************
void search_trs()
{ int idcode,found=0;
  cout<<"\n\n\tEnter teacher's Id_no: ";
  cin>>idcode;
  title2();
  for(int i=0;i<rec;i++)
   if(R[i].id_no==idcode)
     {
       found=1;
       cout<<"\n"<<setw(5)<<R[i].id_no<<"\t\t"<<setw(7)<<R[i].name<<"\t\t"<<setw(10)<<R[i].mob_no;
     }
   if(found==0)
      cout<<"\n\tNot found in the Record";
   getch();
}
//*****************************DELETING*********************************
void del_books()
{ int code,found=0;
int inc=0;
  cout<<"\n\n\tEnter book code:";
  cin>>code;
  title();
  for(int i=0;i<count;i++)
  if(B[i].acc_no==code)
 {
  found=1;
  cout<<"\n"<<setw(5)<<B[i].acc_no<<"\t\t"<<setw(7)<<B[i].books_title<<"\t\t"<<setw(7)<<B[i].author<<"\t\t"<<setw(12)<<B[i].price<<"\t\t"<<setw(4)<<B[i].qty;
   }
 if(found==0)
 cout<<"\n\tBook is not in library";
 else
 cout<<"\n\tAre you sure to delete [y/n]:";
 char choice;
 fflush(stdin);
 cin>>choice;
 if(tolower(choice!='y'))
   cout<<"\n\tRecord not deleted ";
 else
  if(found==1)
  {

   for(int i=0;i<count;i++)
   {
    if(code!=B[i].acc_no)
    {
    B[inc]=B[i];
    inc++;
    }
    }
    count--;
    for(i=0;i<count;i++)
    {
     B[i].acc_no=100+i;
    }
  }
 getch();
}
//******************** Removal of students record **********************
void del_sts(Mbr_Record R[])
{ int idcode,found=0;
  cout<<"\n\n\tEnter student's id_no: ";
  cin>>idcode;
  title2();
  for(int i=0;i<rec;i++)
  if(R[i].id_no==idcode)
 {
  found=1;
 cout<<"\n"<<setw(5)<<R[i].id_no<<"\t\t"<<setw(7)<<R[i].name<<"\t\t"<<setw(10)<<R[i].mob_no;
 }
 if(found==0)
 cout<<"\n\tNot found in the record";
 cout<<"\n\tAre you sure to delete [y/n]:";
 char ch;
 cin>>ch;
 if(tolower(choice!='y'))
   cout<<"\n\tRecord not deleted ";
 else
  if(found==1)
  {
   for(int i=0;i<(count-1);i++)
   R[i]=R[i+1];
    count--;
  }
 getch();
}
//******************** Removal of teachers record ******************
void del_trs(Mbr_Record R[])
{ int idcode,found=1;
  cout<<"\n\tEnter teacher's id_no: ";
  cin>>idcode;
  title3();
  for(int i=0;i<rec;i++)
  if(R[i].id_no==idcode)
 {
  found=1;
  cout<<"\n\t\t"<<setw(5)<<R[i].id_no<<"\t\t"<<setw(7)<<R[i].name<<"\t\t"<<setw(10)<<R[i].mob_no;
 }
 if(found==0)
 cout<<"\n\tNot found in the record";
 cout<<"\n\tAre you sure to delete [y/n]:";
 char choice;
 cin>>choice;
 if(tolower(choice!='y'))
   cout<<"\n\tRecord not deleted ";
 else
  if(found==1)
  {
   for(int i=0;i<(count-1);i++)
    R[i]=R[i+1];
    count--;
  }
 getch();
}
//**********************TITLE 2***********************************
void title2()
{
  clrscr();
  cout<<"\n\n\n\t\tStudent IDno.\tStudent Name\t\tClass"<<endl;
}
//********************TITLE 3**************************************
void title3()
{
  clrscr();
  cout<<"\n\n\n\t\tTeacher IDno.\tTeacher Name\t\tMob.no."<<endl;
}
//********************MEMBER TYPE*******************************
void mbr_record()
{ char choice;
do
   { clrscr();
     textcolor(BROWN);
      clrscr();
     cprintf("\n                   MEMBER RECORD");
     textcolor(YELLOW);
      cout<<"\n";
     cprintf("                ========================");
     cout<<"\n\n\t\t1.Students Record"<<endl;
     cout<<"\n\t\t2.Teachers record"<<endl;
     cout<<"\n\t\t3.Exit"<<endl;
     cout<<"\n\tEnter your choice[1..3]:";
     fflush(stdin);
     cin>>choice;
     switch(choice)
     {
       case '1':clrscr();
		cout<<"Function for maintaing students record";
		sts_record();
		break;
       case '2':clrscr();
		cout<<"Function for maintaing teachers record";
		trs_record();
		break;
       case '3':clrscr();
		cout<<"\n\tRecord is maintained";
		break;
       default:cout<<"\n\n\t\tPlease try again!! enter [1..3]:";
     }
   }while(choice!='3');
 }
//******************** STUDENTS  RECORD *****************************
void sts_record()
{
  textcolor(RED);
   clrscr();
   cout<<"\n";
  cprintf("                ========================");
  textcolor(GREEN);
  cout<<"\n";
  cprintf("                    Students Record");
  textcolor(RED);
   cout<<"\n";
  printf("                 =======================");
  cout<<"\n\n\t1.Adding of member"<<endl;
  cout<<"\n\t  2.Displaying of records"<<endl;
  cout<<"\n\t  3.Searching for a particular record"<<endl;
  cout<<"\n\t  4.Exit"<<endl;
  cout<<"\n\n\tEnter your choice [1...4]: ";
  char ch;
  fflush(stdin);
  cin>>ch;
  switch(ch)
  {
    case '1':clrscr();
	     add_sts(R);
	     break;
    case '2':clrscr();
	     display3(R);
	     break;
    case '3':clrscr();
	     search_sts();
	     break;
    case '4':break;
    default: cout<<"\n\n\t\tInvalid choice !! Try again";
	     getch();
	     exit(0);
  }
}
//***************************** TEACHERS RECORD *************************
void trs_record()
{
  textcolor(RED);
   clrscr();
   cout<<"\n";
  cprintf("               =======================");
  textcolor(GREEN);
  cout<<"\n";
  cprintf("                   Teachers record");
  textcolor(RED);
  cout<<"\n";
  cprintf("              ======================");
  cout<<"\n\n\t1.Adding of member"<<endl;
  cout<<"\n\t  2.Displaying of records"<<endl;
  cout<<"\n\t  3.Searching for a particular record"<<endl;
  cout<<"\n\t  4.Exit"<<endl;
  cout<<"\n\n\tEnter your choice [1...4]: ";
  char ch;
  fflush(stdin);
  cin>>ch;
  switch(ch)
  {
    case '1':clrscr();
	     add_trs(R);
	     break;
    case '2':clrscr();
	     display4(R);
	     break;
    case '3': clrscr();
	     search_trs();
	     break;
    case '4':break;
    default: cout<<"\n\n\t\tInvalid choice !! Try again";
	     getch();
	     exit(0);
  }
}
//***************************** Fields *******************************

void menu()
{
char  choice;
 do
   { clrscr();
    textcolor(YELLOW);
     clrscr();
    cprintf("\n\n             Your School Library");
    textcolor(YELLOW);
    cout<<"\n";
    cprintf("\n        =================================");
    cout<<"\n\n\t\t  1.Collection of books"<<endl;
    cout<<"\n\t\t  2.Searching of books"<<endl;
    cout<<"\n\t\t  3.Member record"<<endl;
    cout<<"\n\t\t  4.Transaction"<<endl;
    cout<<"\n\t\t  5.Exit"<<endl;
    cout<<"\n\t Enter your choice[1...5]:"<<endl;
    fflush(stdin);
    cin>>choice;
    switch(choice)
    {
	case '1': cout<<"Function for displaying categories of books";
		cate_books();
		break;
	case '2': cout<<"Function for searching of books";
		search1();
		break;
	case '3': cout<<"Function for member record";
		mbr_record();
		break;
	case '4': cout<<"Function for transaction of books";
		IR();
		break;
	case '5': cout<<"Thank You !!!";
		 getch();
		 exit(0);
		break;
	default: cout<<"Please try again";

    }
 getch();
 }while(choice!='5');
}
//****************************** Main Function **************************
int main()
 {
  begin();
  menu();
  return 0;
}

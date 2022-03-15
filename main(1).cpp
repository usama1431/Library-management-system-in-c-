#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>

using namespace std;

void intro();
void main_setup();
void add_book();
void edit_book();
void delete_book();
void search_book();
void add_library_user();
void edit_library_user();
void delete_library_user();
void search_library_user();
void issue_book();
void delete_issued_book();
void back_up();

struct book
{
   char book_name[100];
   char ISBN[100];
   char author_name[100];
   char publisher_name[100];
   int no_of_copies;
   string date_of_issue;
};

struct user
{
   int library_id;
   char first_name[100];
   char last_name[100];
   string d_o_b;
   char identity[100];
};

int main()
{
    main_setup();
    return 0;
}

void intro()
{
    system("cls");
    system("color 3f");
    cout << endl << endl ;
    cout << "\t\t----------------------------------------------------------------------------------\n" ;
	cout << "\t\t:                                                                                :\n" ;
	cout << "\t\t--------------#         UOS :  Library Management System          #---------------\n" ;
	cout << "\t\t:                                                                                :\n" ;
	cout << "\t\t----------------------------------------------------------------------------------\n" ;
	cout << endl << endl;
}

void main_setup()
{
    system ("cls");
    system ("color 30");
    cout << endl << endl ;
    cout << "\t\t----------------------------------------------------------------------------------\n" ;
	cout << "\t\t:                                                                                :\n" ;
	cout << "\t\t--------------#         UOS :  Library Management System          #---------------\n" ;
	cout << "\t\t:                                                                                :\n" ;
	cout << "\t\t----------------------------------------------------------------------------------\n\n" ;
	cout << "            Press option key to activate the following function\n" << endl ;
	cout << "\t(0). Add New Book\n\t(1). Edit Book\n\t(2). Delete Book\n\t(3). Search Book\n\t(4). Add Library User\n\t(5). Edit Library User\n\t(6). Delete Library User\n\t(7). Search Library User\n\t(8). Issue Book\n\t(9). Delete Issued Book\n\t\t ";
	cout << "(10). To Quit" << endl ;
	int n;
	cout << "Please select from above numbers to activate that the function " <<endl;
	cin >> n;
	while (n<0 || n>10)
        {
            cout << "Invalid input" <<endl;
            cout << "      Please! select only from the above mentioned numbers" <<endl;
            cin >> n;
        }
    if(n==0)
        add_book();
    else if(n==1)
        edit_book();
    else if(n==2)
        delete_book();
    else if(n==3)
        search_book();
    else if(n==4)
        add_library_user();
    else if(n==5)
        edit_library_user();
    else if(n==6)
        delete_library_user();
    else if(n==7)
        search_library_user();
    else if(n==8)
        issue_book();
    else if(n==9)
        delete_issued_book();
    else if(n==10)
        back_up();
}

void add_book()
{
    intro();
loop:
    cout << "\tAdd New Book  ( Please add required information in the appropriate field ) " <<endl<<endl;
    char ch;
    book obj;
    ofstream myfile("book.txt",ios::app);
    cout << "Enter Book Name:\t";
    cin >> obj.book_name;
    cout << "Enter ISBN:\t";
    cin >> obj.ISBN;
    cout << "Enter Author Name:\t";
    cin >> obj.author_name;
    cout << "Enter Publisher Name:\t";
    cin >> obj.publisher_name;
    cout << "Enter No. of copies:\t";
    cin >> obj.no_of_copies;
    cout << "Enter date of Issue:\t";
    cin >> obj.date_of_issue;
    myfile<<obj.book_name<<" " <<obj.ISBN<<" "<<obj.author_name<<" "<<obj.publisher_name<<" "<<obj.no_of_copies<<" "<<obj.date_of_issue<<endl;
    myfile.close();
    cout << endl;
    cout << "\tPress 'A' to add new book and 'R' to go main setup" << endl;
    cin >> ch;
    if(ch=='a'||ch=='A')
        {
            intro();
            cout << "The book information was not duplicate and the new book information is successfully added in the system!" << endl;
            goto loop;
            }
    if(ch=='r'||ch=='R')
        main_setup();
}

void add_library_user()
{
    intro();
    int pass=8704;
    int word;
    cout << "Enter Password to add user" <<endl;
    cin >> word;
    if (pass==word)
    {
    loop:
        intro();
        ofstream userfile("user.txt",ios::app);
        user obj;
        int ch;
        cout << "Select the option to add User" << endl;
        cout << "\t(1). Student\n\t(2). Employ " << endl;
        cin >> ch;
        if (ch==1)
        {
            intro();
             cout << "Enter student , Library ID" <<endl;
            cin >> obj.library_id;
            cout << "Enter first name of student" <<endl;
            cin >> obj.first_name;
            cout << "Enter last name of student" <<endl;
            cin >> obj.last_name;
            cout << "Enter student DOB" << endl;
            cin >> obj.d_o_b;
            userfile<<obj.library_id<<" "<<obj.first_name<<" "<<obj.last_name<<" "<<obj.d_o_b<<" "<<"Student"<<endl;
            userfile.close();
            cout << "Press 1 to add another user and 0 to go main setup" <<endl;
            cin >> ch;
            if (ch==1)
                goto loop;
            else if (ch==0)
                main_setup();
        }
        else if (ch==2)
        {
            intro();
            cout << "Enter employ , Library ID" <<endl;
            cin >>obj.library_id;
            cout << "Enter first name of employ" <<endl;
            cin >> obj.first_name;
            cout << "Enter last name of employ" <<endl;
            cin >> obj.last_name;
            cout << "Enter employ DOB" <<endl;
            cin >>obj.d_o_b;
            userfile<<obj.library_id<<" "<<obj.first_name<<" "<<obj.first_name<<" "<<obj.last_name<<" "<<obj.d_o_b<<" "<<"Employ"<<endl;
            userfile.close();
            cout << "Press 1 to add another user and 0 to go main setup" <<endl;
            cin >> ch;
            if (ch==1)
            goto loop;
            else if (ch==0)
                main_setup();
        }
    }
    else if (word!=pass)
    {
        int ch;
        cout << "You have entered incorrect Password!\n\t Enter again or press 0 to go main setup" <<endl;
        if (ch==0)
            main_setup();
    }
}

void edit_book()
{
    intro();
    loop:
        int ch;
        char isbn[100];
        char new_book_name[100];
        book obj;
        cout << "\tSelect option key to access the book\n\t(1). Access book by isbn\n\t(2). Access book by name" <<endl;
        cin >> ch;
        if (ch==1)
        {
            cout << "Enter book ISBN" <<endl;
            cin >> isbn;
        }
        else if (ch==2)
        {
            cout << "Enter book name" <<endl;
            cin >> new_book_name;
        }
        ifstream openfile("book.txt" , ios::app);
        ofstream editbookfile("edit_book.txt" , ios::app);
        while (openfile>>obj.ISBN>>obj.book_name>>obj.author_name>>obj.publisher_name>>obj.no_of_copies>>obj.date_of_issue)

          {
    if(strcmp(isbn,obj.ISBN)==0 || strcmp(new_book_name,obj.book_name)==0)
    {
    cout<<"Enter New Book Name : ";
    cin>>obj.book_name;
    cout<<"Enter ISBN : ";
    cin>>obj.ISBN;
    cout<<"Enter Author Name : ";
    cin>>obj.author_name;
    cout<<"Enter Publisher name : ";
    cin>>obj.publisher_name;
    cout<<" Enter no. of copies : ";
    cin>>obj.no_of_copies;
    cout<<" Date of issue : ";
    cin>>obj.date_of_issue;
    }
    editbookfile<<obj.ISBN<<"    "<<obj.book_name<<"    "<<obj.author_name<<"    "<<obj.publisher_name<<"    "<<obj.no_of_copies<<"    "<<obj.date_of_issue<<endl;

    }
            editbookfile.close();
        openfile.close();
cout<<"The book data is successfully Edited"<<endl<<endl<<"Press 'R' to go back to main menu OR Press 'E'  to edit other book"<<endl;
      cin>>ch;
      if(ch=='r'|| ch=='R')
        main_setup();
      if(ch=='e'||ch=='E')
        goto loop;
}


void edit_library_user()
{
    loop:
          intro();
   user obj;
 int id;
ifstream openuser("user.txt",ios::app);
ofstream edituser("edit_user.txt",ios::app);
cout<<"Enter User ID you want to edit"<<endl;
cin>>id;
while(openuser>>obj.library_id>>obj.first_name>>obj.last_name>>obj.d_o_b>>obj.identity){
    if(id==obj.library_id){
        cout<<"Enter New name of user : ";
cin>>obj.first_name;
cout<<"Enter last name of user : ";
cin>>obj.last_name;
cout<<"Enter New ID : ";
cin>>obj.library_id;
cout<<"Enter DOB : ";
cin>>obj.d_o_b;
    cout<<"User identity 'Student or Employ': ";
cin>>obj.identity;
        }

  edituser<<obj.library_id<<"      "<<obj.first_name<<"      "<<obj.last_name<<"      "<<obj.d_o_b<<obj.identity<<"       "<<endl;


    }
openuser.close();
edituser.close();
 if( remove( "user.txt"  ) != 0)
    cout<<"User not removed " <<endl;
    else if( rename( "edit_user.txt"  ,  "user.txt" ) != 0 )
       cout<<"User not renamed "<<endl;
      else {
      cout<<"The User data is successfully Edited"<<endl<<endl;
      int ch;
        cout<<"  (a). Return to main setup"<<"   "<<"(e). Edit another user"<<endl;
        cin>>ch;
        if(ch=='a'|| ch=='A')
            main_setup();
        if(ch=='e'|| ch=='E')
            goto loop;
}
}


void search_book()
{
loop:
    intro();
int ch;
char isbn[100];
char new_book_name[100];
book obj;
cout<<"(1). Access Book by ISBN"<<endl<<"(2).Access book by Name"<<endl;
cin>>ch;
if(ch==1){
    cout<<"Enter ISBN : ";
    cin>>isbn;
    }
 if(ch==2){
    cout<<"Enter Book name : ";
    cin>>new_book_name;
 }

ifstream openfile("book.txt",ios::app);
while(openfile>>obj.ISBN>>obj.book_name>>obj.author_name>>obj.publisher_name>>obj.no_of_copies>>obj.date_of_issue){
if(strcmp(isbn,obj.ISBN)==0){

     cout<<obj.ISBN<<"   "<<obj.book_name<<"   "<<obj.author_name<<"   "<<obj.publisher_name<<"   "<<obj.no_of_copies<<"   "<<obj.date_of_issue<<endl;
}
else if(strcmp(new_book_name,obj.book_name)==0){

     cout<<obj.ISBN<<"   "<<obj.book_name<<"   "<<obj.author_name<<"   "<<obj.publisher_name<<"   "<<obj.no_of_copies<<"   "<<obj.date_of_issue<<endl;
}
}
openfile.close();
 cout<<endl<<endl<<"Press 0 to go back to main menu OR Press 1  to search again book"<<endl;
      cin>>ch;
      if(ch==0)
        main_setup();
      if(ch==1)
        goto loop;
}

void search_library_user()
{
loop:
    intro();
user obj;
int ch;
int id;
char name[100];

cout<<"(1). Search By ID"<<endl<<"(2). Search by name"<<endl;
cin>>ch;
if(ch==1){
    cout<<"Enter ID : ";
    cin>>id;
    }
 if(ch==2){
    cout<<"Enter User  name : ";
    cin>>name;
 }
 ifstream openuser("user.txt",ios::app);

while(openuser>>obj.library_id>>obj.first_name>>obj.last_name>>obj.d_o_b>>obj.identity){
    if(id=obj.library_id){
cout<<obj.library_id<<"      "<<obj.first_name<<"      "<<obj.last_name<<"      "<<obj.d_o_b<<"      "<<obj.identity<<endl;
}
else if(strcmp(name , obj.first_name)==0){
    cout<<obj.library_id<<"      "<<obj.first_name<<"      "<<obj.last_name<<"      "<<obj.d_o_b<<"       "<<obj.identity<<endl;
}
}
openuser.close();
cout<<endl<<endl<<"Press 0 to go back to main menu OR Press 1  to search again book"<<endl;
        cin>>ch;
        if(ch==0)
            main_setup();
        if(ch==1)
            goto loop;
}


void delete_book()
{
loop:
    intro();
int ch;
char  isbn[100];
char new_book_name[100];
book obj;
cout<<"(1). Delete Book By ISBN"<<endl<<"(2).Delete Book by Name"<<endl;
cin>>ch;
if(ch==1){
    cout<<"Enter ISBN : ";
    cin>>isbn;
    }
 if(ch==2){
    cout<<"Enter Book name : ";
    cin>>new_book_name;
 }

ifstream openfile("book.txt",ios::app);
ofstream editbook("edit_book.txt",ios::app);
while(openfile>>obj.ISBN>>obj.book_name>>obj.author_name>>obj.publisher_name>>obj.no_of_copies>>obj.date_of_issue){
    if(strcmp(isbn,obj.ISBN)!=0){
if(strcmp(new_book_name,obj.book_name)!=0)
    {
editbook<<obj.ISBN<<"   "<<obj.book_name<<"   "<<obj.author_name<<"   "<<obj.publisher_name<<"   "<<obj.no_of_copies<<"   "<<obj.date_of_issue<<endl;
        }

}}
        editbook.close();
        openfile.close();
         if( remove( "book.txt" ) != 0){
        cout<<"File not removed " <<endl;}
      else if(rename( "edit_book.txt"  ,  "book.txt" ) !=0 ){
      cout<<"file not renamed "<<endl;}
       else{
      cout<<"The book data is successfully Deleted"<<endl<<endl<<"Press 0 to go back to main menu OR Press 1  to Delete other book"<<endl;
      cin>>ch;
      if(ch==0)
        main_setup();
      if(ch==1)
        goto loop; }
}

void delete_library_user()
{
loop:
     intro();
user obj;
bool flag;
int id;
ifstream openuser("user.txt",ios::app);
ofstream edituser("edit_user.txt",ios::app);
cout<<"Enter User ID you want to deleted"<<endl;
cin>>id;
while(openuser>>obj.library_id>>obj.first_name>>obj.last_name>>obj.d_o_b>>obj.identity){
    if(id=obj.library_id){
edituser<<obj.library_id<<"      "<<obj.first_name<<"      "<<obj.last_name<<"      "<<obj.d_o_b<<"       "<<obj.identity<<endl;
}
 if(id=obj.library_id)
       {
           flag=true;
            cout<<"The User data is successfully Deleted"<<endl<<endl;
       }

}
openuser.close();
edituser.close();
if(flag != true )
{
    cout<<"The record against this ID in not found"<<endl;
}
 if( remove( "user.txt"  ) != 0)
    cout<<"User not removed " <<endl;
    else if( rename( "edit_user.txt"  ,  "user.txt" ) != 0 )
       cout<<"User not renamed "<<endl;
int ch;
        cout<<"  (0). Return to main menu"<<"   "<<"(1). Delete another user"<<endl;
        cin>>ch;
        if(ch==0)
            main_setup();
        if(ch==1)
            goto loop;
}

void issue_book()
{
    loop:
        intro();
user ob;
book obj;

int id;
bool flag;

 ifstream openuser("user.txt");
 ifstream openfile("book.txt");
 ofstream issue("issue.txt",ios::app);

 cout<<"Enter user id you want to issue book : ";
 cin>>id;
 while(openuser>>ob.library_id>>ob.first_name>>ob.last_name>>ob.d_o_b){
 if(id=ob.library_id){
    flag=true;
   break;
 }}
 if(flag==true){
 intro();
cout<<"ISBN"<<"        "<<"Book Name"<<"       "<<"Author"<<"       "<<"Publisher"<<"       "<<"Copies"<<"       "<<"Issue date"<<endl;
  while(openfile>>obj.ISBN>>obj.book_name>>obj.author_name>>obj.publisher_name>>obj.no_of_copies>>obj.date_of_issue){
     cout<<obj.ISBN<<"      "<<obj.book_name<<"       "<<obj.author_name<<"       "<<obj.publisher_name<<"      "<<obj.no_of_copies<<"      "<<obj.date_of_issue<<endl;
} openfile.close();

char issue_isbn[100];
cout<<"Enter book ISBN which you want to issue this user"<<endl;
 openfile.open("book.txt");
cin>>issue_isbn;
  while(openfile>>obj.ISBN>>obj.book_name>>obj.author_name>>obj.publisher_name>>obj.no_of_copies>>obj.date_of_issue){
if(strcmp(obj.ISBN,issue_isbn)==0){

    issue<<ob.library_id<<"\t"<<ob.first_name<<"\t"<<obj.ISBN<<"\t"<<obj.book_name<<"\t"<<obj.author_name<<endl;
    cout<<"The book "<<obj.book_name<<"  has been issued to user\t"<<ob.first_name<<endl;
}}
 }
else if(flag!=true)
                {
                    cout<<"The user with this Id does not exist"<<endl;
                }
                issue.close();
            openfile.close();
            openuser.close();
int ch;
cout<<"(1). Issue another book to other user"<<"   "<<"(2).Return main menu"<<endl;
cin>>ch;
if(ch==1)
    goto loop;
if(ch==2)
    main_setup();
}

void delete_issued_book()
{
loop:
      intro();
user ob;
book obj;
int id;
ifstream openissue("issue.txt");
ofstream editissue("edit_issue.txt");
cout<<"Enter User ID you want to deleted"<<endl;
cin>>id;
bool flag;
while(openissue>>ob.library_id>>ob.first_name>>obj.ISBN>>obj.book_name>>obj.author_name){
        if(id!=ob.library_id){
    editissue<<ob.library_id<<"   "<<ob.first_name<<"   "<<obj.ISBN<<"   "<<obj.book_name<<"   "<<obj.author_name<<endl;
}
 if(ob.library_id==id)
       {
           flag=true;
       }
        cout<<"The User data is successfully Deleted"<<endl<<endl;
}
openissue.close();
editissue.close();
if(flag != true )
{
    cout<<"The record against this ID in not found"<<endl;
}
remove( "issue.txt"  );
    rename( "edit_issue.txt"  ,  "issue.txt" );
      int ch;
        cout<<"  (0). Return to main menu"<<"   "<<"(1). Delete another user"<<endl;
        cin>>ch;
        if(ch==0)
            main_setup();
        if(ch==1)
            goto loop;
}

 void back_up()
{
    intro();
    cout << "\t\t\t\t\tPress any key to Exit!\n\n\n\n"<<endl;
}

#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<fstream>
 using namespace std;
 class BookShop
 {
 	public:
 		char author[25],title[50],publisher[50];
 		int price;
 };
 BookShop BS;
 float total;
 void menu();
 void addbook();
 void editbook();
 void listbooks();
 void searchbook();
 void buybook();
 void file()
 {
 	ofstream fp;
 	ifstream fp1;
 	fp.open("BookShop.txt",ios::out);
 	if(fp.fail())
 	  {
 	  		cout<<"Cannot open the file!";
 	  		exit(0);
	  }
	fp1.open("TempFile",ios::in);
	if(fp1.fail())
	  {
        	cout<<"Cannot open the file!";
        	exit(0);
 	  }
    while(fp1.read((char*)&BS,sizeof(BS)))
    	{
        	fp.write((char*)&BS,sizeof(BS));
    	}
    fp.close();
    fp1.close();
 }
 
 
 

void menu()
 {
 	system("cls");
 	char option,enter;
 	cout<<"\n\n\n\n\n\n";
 	cout<<"\t\t\t\t---------------------------------------\n";
 	cout<<"\t\t\t\t-                                     -\n";
 	cout<<"\t\t\t\t-\t\tMENU                  -\n";
 	cout<<"\t\t\t\t-\t    A   Add Book              -\n";
 	cout<<"\t\t\t\t-\t    E   Edit Book             -\n";
 	cout<<"\t\t\t\t-\t    L   List Books            -\n";
 	cout<<"\t\t\t\t-\t    S   Search Book           -\n";
 	cout<<"\t\t\t\t-\t    B   Buy Book              -\n";
 	cout<<"\t\t\t\t-\t    X   Exit                  -\n";
 	cout<<"\t\t\t\t---------------------------------------\n";
	cout<<"\t\t\t\t     Choose any option from above:";
	option=getchar();
	switch(option)
 		  {
 				case 'A':
					addbook();
					break;	
													
				case 'E':
					editbook();
					break;
						
	     		case 'L':
					listbooks();
					break;
												
				case 'S':
				 	searchbook();
				 	break;
					 	
				case 'B':
				 	buybook();
					break;
						
				case 'X':
					exit(0);		
						
				default:
					cout<<"\t\t\t\t\t  Invalid Choice";	
					cout<<"\n-----------------------------------------------------------------------------------------------------------------------\n";	  	
					cout<<"\t\t\t\t\tPress enter to repeat again";
					fflush(stdin);
					enter=getchar();
					menu();			
	 	   }
 }

 void addbook()
 {
 	char enter;
 	ofstream fp;
 	fp.open("BookShop.txt",ios::app);
 	if(fp.fail())
 	  {
 	  		cout<<"Cannot open the file!";		
	  }
	cout<<"\n-----------------------------------------------------------------------------------------------------------------------\n";
	cout<<"\t\t\t\t\t   Adding Details"<<endl;
	cout<<"\t\t\t\t   Enter the Author Name:";
	fflush(stdin);
	cin>>BS.author;
 	cout<<"\t\t\t\t   Enter the Title of the Book:";
 	fflush(stdin);
 	cin>>BS.title;
 	cout<<"\t\t\t\t   Enter the Publisher:";
 	fflush(stdin);
 	cin>>BS.publisher;
 	cout<<"\t\t\t\t   Enter the Price:";
 	fflush(stdin);
 	cin>>BS.price;  
 	cout<<"\n-----------------------------------------------------------------------------------------------------------------------\n";
 	fp.write((char*)&BS,sizeof(BS));
 	fp.close();
 	cout<<"\t\t\t\t\tPress enter to go to menu";
	fflush(stdin);
	enter=getchar();
	menu();	
 }
 
 
 void editbook()
 { 
 	char booktitle[50],enter;
	int found=0;
	ifstream fp;
	ofstream fp1;
	fp.open("BookShop.txt",ios::in);
	if(fp.fail())
    {
        cout<<"Cannot open the file!";
        exit(0);
    }
    fp1.open("TempFile",ios::out);
    if(fp1.fail())
    {
        cout<<"Cannot open the file!";
        exit(0);
    }
	system("cls");
	cout<<"\t\tEnter the title of the book from above list to edit the details:";
	cin>>booktitle;
	while(fp.read((char*)&BS,sizeof(BS)))	
		 {
		 	if(strcmp(booktitle,BS.title)==0)
		 	  { 
				 	found=1;
				 	cout<<"\n-----------------------------------------------------------------------------------------------------------------------\n";
				 	cout<<"\t\t\t\t   Enter New Author Name:";
				 	fflush(stdin);
				 	cin>>BS.author;
				 	cout<<"\t\t\t\t   Enter New Title:";
				 	fflush(stdin);
				 	cin>>BS.title;
				 	cout<<"\t\t\t\t   Enter New Publisher:";
				 	fflush(stdin);
				 	cin>>BS.publisher;
				 	cout<<"\t\t\t\t   Enter New Price:";
				 	fflush(stdin);
				 	cin>>BS.price;
				 	cout<<"\n-----------------------------------------------------------------------------------------------------------------------\n";
				 	fp1.write((char*)&BS,sizeof(BS));
			  }
			else
			{
				fp1.write((char*)&BS,sizeof(BS));	
			}
		 }
	fp.close();
	fp1.close();
	file();
	
	if(found==0)
	  {
			cout<<"\t\t\tThe Title does not match any book in the record";
	  }
	else
	{
		cout<<"\t\t\t\tThe details of the books has been updated:";
	}
	cout<<"\n-----------------------------------------------------------------------------------------------------------------------\n";
	cout<<"\t\t\t\t\tPress enter to go to menu";
	fflush(stdin);
	enter=getchar();
	menu();			
 }
 
 void listbooks()
 {
 	char enter;
 	ifstream fp;
 	fp.open("BookShop.txt",ios::in);
 	system("cls");
 	cout<<endl<<"\t\t\t\t\t   The list of Books are:";
 	while(fp.read((char*)&BS,sizeof(BS)))
 		 {
 		 	cout<<"\n-----------------------------------------------------------------------------------------------------------------------\n";
 		 	cout<<"\t\t\t\t\t   Author Name:"<<BS.author<<endl;
			cout<<"\t\t\t\t\t   Title:"<<BS.title<<endl;
			cout<<"\t\t\t\t\t   Publisher:"<<BS.publisher<<endl;
			cout<<"\t\t\t\t\t   Price:"<<BS.price<<endl;
			cout<<"\n-----------------------------------------------------------------------------------------------------------------------\n";
		 }
	cout<<"\t\t\t\t\tPress enter to go to menu";
	fflush(stdin);
	enter=getchar();
	menu();			
 }
 
 
 void searchbook()
 {
 	char booktitle[50],enter;
 	int found=0;
 	ifstream fp;
 	fp.open("BookShop.txt",ios::in);
 	if(fp.fail())
 	  {
 	  		cout<<"Cannot open the file!";
 	  		exit(0);
	  }
	cout<<"\n-----------------------------------------------------------------------------------------------------------------------\n";
	cout<<"\t\t\t\t Enter title of the book to search:";
	cin>>booktitle;
	while(fp.read((char*)&BS,sizeof(BS))) 
		 {
			if(strcmp(booktitle,BS.title)==0)
		 	  {
		 			found=1;
		 			cout<<"\n-----------------------------------------------------------------------------------------------------------------------\n";
 		 			cout<<"\t\t\t\t\t   Author Name:"<<BS.author<<endl;
					cout<<"\t\t\t\t\t   Title:"<<BS.title<<endl;
					cout<<"\t\t\t\t\t   Publisher:"<<BS.publisher<<endl;
					cout<<"\t\t\t\t\t   Price:"<<BS.price<<endl;
					cout<<"\n-----------------------------------------------------------------------------------------------------------------------\n";
		 	  }
		 }
	fp.close();
	if(found==0)
	{
	 	cout<<"\t\t\t   The title does not match any book in the record";	
	}
	cout<<"\n-----------------------------------------------------------------------------------------------------------------------\n";
	cout<<"\t\t\t\t\tPress enter to go to menu";
	fflush(stdin);
	enter=getchar();
	menu();			 
 }
 
 void buyanother()
 {
 	int c;
	char enter;
 	cout<<"\n\n\n";
 	cout<<"\t\t\t\t--------------------------------------\n";
 	cout<<"\t\t\t\t-\t 1  Buy Another Book         -\n";
 	cout<<"\t\t\t\t-\t 2  Total Amount             -\n";
 	cout<<"\t\t\t\t---------------------------------------\n";
 	cout<<"\t\t\t\t     Choose any option from above:";
	cin>>c;
	switch(c)
	      {
	     		case 1:
	     			cout<<"\n-----------------------------------------------------------------------------------------------------------------------\n";
				 	buybook();
					break;
					
				case 2:
					cout<<"\n-----------------------------------------------------------------------------------------------------------------------\n";
					cout<<"\t\t\t\t\tThe Total Amount Is Rs:"<<total<<endl;
					total=0;
					cout<<"\n-----------------------------------------------------------------------------------------------------------------------\n";
					cout<<"\t\t\t\t\tPress enter to go to menu";
					fflush(stdin);
					enter=getchar();
					menu();	
					break;
					
				default:
        			cout<<"\n-----------------------------------------------------------------------------------------------------------------------\n";
		  			cout<<"\t\t\t\t\t  Invalid Choice";	
					cout<<"\n-----------------------------------------------------------------------------------------------------------------------\n";	  	
					cout<<"\t\t\t\t Press enter to repeat again";
					fflush(stdin);
					enter=getchar();
       				buyanother();
        			break;	
          }
 }
 
 void calculatetotal(int price)
 {
 	int quantity;
 	cout<<"\t\t\t\tEnter the quantity of the selected book:";
 	cin>>quantity;
 	total=total+(price)*(quantity);
 	buyanother();
 }
 void buybook()
 {
 	ifstream fp;
 	int pob[50],option,enter;
 	int i;
 	for(i=0;i<50;i++)
 	   {
 	   		pob[i]=0;
	   }
	i=1;
	fp.open("BookShop.txt",ios::in);
	system("cls");
	cout<<"\t\t\t\t---------------------------------------\n";
	cout<<"\t\t\t\t     List Of Available Books               \n";
	cout<<"\t\t\t\t---------------------------------------\n";
	cout<<"\t\t\t\t Input Number For Selected Menu";
	cout<<"\n-----------------------------------------------------------------------------------------------------------------------\n";
	cout<<"\t\t SN \t\t Author \t\t Title \t\t Pubisher \t\t Price \n";
	while(fp.read((char*)&BS,sizeof(BS)))
		 {
		 	cout<<"\n\t\t"<<i<<"\t\t"<<BS.author<<"\t\t"<<BS.title<<"\t\t"<<BS.publisher<<"\t\t"<<BS.price<<endl;
		 	pob[i]=BS.price;
		 	i++;
		 }
	fp.close();
	cout<<"\n-----------------------------------------------------------------------------------------------------------------------\n";
	cout<<"\t\t0\t\t\t  Back to Menu";
	cout<<"\n-----------------------------------------------------------------------------------------------------------------------\n";
	cout<<"\t\t\t\t\t Enter your option:";
	cin>>option;
	
	if(option==0)
	  {
	 		menu(); 	
      }	 
	else if(pob[option]==0)
		  {
		  		cout<<"\n-----------------------------------------------------------------------------------------------------------------------\n";
		  		cout<<endl<<"\t\t\t\t\t  Invalid Choice";	
				cout<<"\n-----------------------------------------------------------------------------------------------------------------------\n";	  	
				cout<<"\t\t\t\t\tPress enter to repeat again";
				fflush(stdin);
				enter=getchar();
				buybook();
	      }  
	else
	{
		int p;
		p=pob[option];
		calculatetotal(p);
	}      	   
 } 	
 
 int main()
 {
 	char enter;
 	cout<<"\n\n\n\n\n\n";
 	cout<<"\t\t\t\t-----------------------------------------\n";
 	cout<<"\t\t\t\t-                                       -\n";
 	cout<<"\t\t\t\t-                                       -\n";
 	cout<<"\t\t\t\t-\tBookshop Management System      -\n";
 	cout<<"\t\t\t\t-                                       -\n";
 	cout<<"\t\t\t\t-                                       -\n";
 	cout<<"\t\t\t\t-----------------------------------------\n";
    cout<<"\t\t\t\t\t Press enter to continue";
    enter=getchar();
    menu();
 }

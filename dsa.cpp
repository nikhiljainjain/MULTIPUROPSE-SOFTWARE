#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
using namespace std;
struct node
{
	int data;
	int pri;
	struct node *prev;
	struct node *next;
	
}*l,*f;
int c=0;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void insert(int index,int priority)
{
	struct node *newnode=new struct node;
	newnode->next=NULL;
	newnode->prev=NULL;
	newnode->data=index;
	newnode->pri=priority;
	if(l==NULL)
	{
		l=newnode;
		f=l;
	}
	else
	{
		newnode->prev=l;
		l->next=newnode;
		l=newnode;
	}
}

void hidden_folder()
{
	cout<<"\nHidden folder operation is started\n";
	int x2;
	string x1,x3;
	cout<<"Enter the directory \n";
	cin>>x1;
	ofstream file;
	file.open("hide.txt");
	file<<"@echo off"<<endl;
	file<<"attrib +s +h "<<x1;
	file.close();
	system("rename hide.txt hide.bat");
	system("hide.bat");
	cout<<"\nPress\n1.To make folder visible\n2.To remain same condition\n=>";
	cin>>x2;
	if (x2==1)
	{
		ofstream file1;
		file1.open("hide1.txt");
		file1<<"attrib -s -h "<<x1;//<<"/"<<x3<<endl;
		file1.close();
		system("rename hide1.txt hide1.bat");
		system("hide1.bat");
	}
	else
	{cout<<"Folders isn't visible'\n";}
}

void remove_virus()
{
	cout<<"\nRemove virus operation is started now\n";
	string x1;
	cout<<"Enter the directory\n=>";
	cin>>x1;
	ofstream revir;
	revir.open("remove.txt");
	revir<<"@Echo off"<<endl;
	revir<<"attrib -s -h "<<x1<<endl;
	revir.close();
	system("rename remove.txt remove.bat");
	system("remove.bat");
	cout<<"Now check the directory \nIf you will get some unwanted files then\nDelete them\n";
}

void write_protection()
{
	system("color D");
	cout<<"\nCurrently remove write protection program in work\n\n";
	cout<<"Now type \n->list disk\n->select disk 'get disk number from list'\n->";
	cout<<"attributes disk clear readonly\nexit\n";
	system("diskpart");
}

void stop_net()
{
	system("color C");
	cout<<"\nCurrently stop internet programme is running\n\n";
	system("ipconfig/release");
	cout<<"\n->Chcek your internet connection\n";
}

void courrpted_usb()
{
	system("color B");
	cout<<"\nNow repair courrpt usb program is started\n\n";
	cout<<"In pop-up window\nType following commands\n->list disk\n->select disk 'disk number form list'\n->clean\n->";
	cout<<"create partition primary\n->active\n->select partition 1\n->fs=fat32\n";
	cout<<"->After completion of format\n->exit\n";
	system("diskpart");
}

void pc_talk()
{
	system("color A");
	cout<<"\nIt's time for text to speech\n\n";
	system("t2s.vbs");
}

void format_drive()
{
	cout<<"\nNow we are go format your drive\n";
	char l1;
	cout<<"Enter the Driver letter\n->";
	cin>>l1;
	ofstream file;
	file.open("format.txt");
	file<<"@echo off"<<endl;
	file<<"format ";
	l1=toupper(l1);
	file<<l1<<":/FS:NTFS/X/Q"<<endl;
	file .close();
	system("rename format.txt format.bat");
	cout<<"Your file is for the operation with name format.bat\nOpen file as Administrator\n";
	cout<<"Enter drive letter for confirmation\nEnter volume label you want\n";
	
}

void antivirus()
{
	system("color A");
	cout<<"\nLets check your antivirus\n";
	ofstream file;
	file.open("virus.txt");
	file<<"X50!P%@AP[4PZX554(P^)7CC)7}$SYSTEM-HACKED!$H+H*"<<endl;
	file.close();
	system("rename virus.txt virus.exe");
	system("virus.exe");
	cout<<"Scan this program folder\nAfter scaning \nIf you get virus.exe file then your antivirus is not working \nElse its working\n";
	system("attrib -s -h virus.exe");
}

void recover_file()
{
	cout<<"\nNow we are going to recover your important files\n";
	char x1;
	cout<<"Enter driver letter\n";
	cin>>x1;
	cout<<"If it ask for any premission\nSimply give yes\n";
	ofstream file;
	file.open("usb.txt");
	file<<"chkdsk "<<x1<<":/r"<<endl;
	file.close();
	system("rename usb.txt usb.bat");
	system("usb.bat");
}


void swap ( int* a, int* b )
{   int t = *a;      *a = *b;       *b = t;   }
 

struct node *lastNode(node *root)
{
    while (root && root->next)
        root = root->next;
    return root;
}
 

node* partition(node *l, node *h)
{
   
    int x  = h->pri;
 
  
    node *i = l->prev;
 
   
    for (node *j = l; j != h; j = j->next)
    {
        if (j->pri <= x)
        {
            
            i = (i == NULL)? l : i->next;
 
            swap(&(i->pri), &(j->pri));
            swap(&(i->data), &(j->data));
        }
    }
    i = (i == NULL)? l : i->next; 
    swap(&(i->pri), &(h->pri));
    swap(&(i->data), &(h->data));
    return i;
}
 

void _quickSort(struct node* l, struct node *h)
{
    if (h != NULL && l != h && l != h->next)
    {
        struct node *p = partition(l, h);
        _quickSort(l, p->prev);
        _quickSort(p->next, h);
    }
}
 

void quickSort(struct node *head)
{
    // Find last node
    struct node *h = lastNode(head);
 
    // Call the recursive QuickSort
    _quickSort(head, h);
}
void execute()
{
	struct node *temp;
	temp=f;
	while(temp!=NULL)
	{
		switch (temp->data)
    {
    case 1 :
    remove_virus();
    break;
    case 2 :
    write_protection();
    break;
    case 3 :
    hidden_folder();
    system("del hide.bat");
    break;
    case 4 :
    antivirus();
    break;
    case 5 :
    courrpted_usb();
    break;
    case 6 :
    recover_file();
    break;
    case 7 :
    stop_net();
    break;
    case 8 :
    format_drive();
    break ;
    case 9 :
    pc_talk();
    break;
    }
    temp=temp->next;
	}
}

int main(int argc, char** argv) {
	int x1=0;
	system("color F");
    cout<<"Press\n1.Remove computer virus\n2.Remove write protection\n";
    cout<<"3.Hide files\n4.Checking antivirus working\n";
    cout<<"5.Repair corrupted memory card/usb\n";
    cout<<"6.Recover files from corrupted USB\n";
    cout<<"7.Stop internet access\n";
    cout<<"8.Format any drive\n";
    cout<<"9.To make your pc talk\n10.Exit\n";
    cout<<"Do u want to execute?\nY or N"<<endl;
    char ch;
    cin>>ch;
    while(ch=='y'|| ch=='Y')
    {
    	system("color E");
    	cout<<"Enter the index no of the function"<<endl<<"->";
    	int ind;
    	cin>>ind;
    	cout<<"Enter the priority of your job"<<endl<<"->";
    	int prior;
    	cin>>prior;
    	insert(ind,prior);
    	cout<<"Do u want to execute?\nY or N"<<endl<<"->";
     	cin>>ch;
     	system("color B");
	}
	cout<<"Let begain\n";
	quickSort(f);
	execute();
	system("color F");
	cout<<"This program is made by\n->NIKHIL JAIN\n=>Rajdeepa Chakrabarty\n";
    cout<<"-> Thank You :) <-\n";
}

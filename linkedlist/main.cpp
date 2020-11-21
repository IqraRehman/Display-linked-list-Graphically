
#include <iostream>
#include<windows.h>
#include<conio.h>
#include<graphics.h>
#include<string>
#include<fstream>
using namespace std;

struct node{
int item;
node* pre;
node* next;
};
class DbLink{
    node* start, *pn , *cur , *temp;
    int n , count;
public:
    //constructor
    DbLink():start(NULL){}
    //set NULL for to start
    void set(){
    start = NULL;
    }
    //insertion for double link list
	void dbadd(int x){
			if(start==NULL){
			temp=new node;
			start = temp;
			start->item = x;
			start->next = NULL;
			start->pre = NULL;
			}
			else{
				cur = start;
				while(cur->next!=NULL)
				cur = cur->next;
			  pn = temp;
			  temp = new node;
			  temp->pre = pn;
			  temp->item = x;
			  temp->next = NULL;
			  cur->next = temp;
			}
		}
		//insertion for double link list in specific location
    void dbinsert(int n,int p){
        if(p==1)
            {
              temp = new node;
              temp->item = n;
              temp->pre = NULL;
              temp->next = start;
              start->pre = temp;
              start = temp;
			}
        else if(p > 1){
            	cur=start;
			for(int i=1; i<p-1 ; i++){
				cur = cur->next;
			   if(cur==NULL)
			   {
			   	cout<<"\ninvalid position\n";
			   	return;
			   }
			}
				temp = new node;
				cur->next->pre = temp;
				temp->pre = cur;
				temp->item = n;
				temp->next = cur->next;
				cur->next = temp;
        }
    }
    //deletion for double link list
    void dbdel(int p){
        if(p==1){
        cout<<"\nEnter value\n\n";
        cin>>n;
        cur = start;
        if(cur->item==n){
        start = cur->next;
        start->pre = NULL;
        delete cur;
        }
        if(cur==start)
            cout<<"\ninvalid input\n";
      }
      else if(p==2){
        cout<<"\nEnter value\n\n";
        cin>>n;
       cur = temp = start ;
       while(cur!=NULL){
        if(cur->item==n){
            temp->next = cur->next;
            cur->next->pre = temp;
            delete cur;
            break;
        }
        temp = cur;
        cur = cur->next;
       }
      }
      else if(p==3){
          cout<<"\nEnter value\n\n";
        cin>>n;
        cur = temp = start ;
        while(cur!=NULL){
        if(cur->item==n){
        temp->next = cur->next;
        delete cur;
        break;
        }
        temp = cur;
        cur = cur->next;
       }
      }
      if(cur==NULL)
        cout<<"\nValue not found\n";
    }
    //searching in double linked list
    int search(int n){
        int i=0;
    cur = start;
    while(cur!=NULL){
        i++;
        if(cur->item==n){
           break;
            }
            cur = cur->next;
            }
            if(cur==NULL)
              return 0;
              else
                return i;
    }
    //isnertion for cicular double link list
   void cdadd(int n){
   if(start==NULL){
    temp = new node;
    start = temp;
    start->item = n;
    start->pre = temp;
    start->next = temp;
   }
   else{
    cur = start;
    while(cur->next!=start)
        cur = cur->next;
         pn = temp;
         temp = new node;
         temp->item = n;
         temp->pre = pn;
         temp->next = start;
         cur->next = temp;
         start->pre = temp;
   }
   }
   //insertion for circular double link list for specified location
    void cdbinsert(int p , int n){
        if(p==1)
        		{
                cur = start;
				while(cur->next!=start){
                cur = cur->next;
				}
				temp = new node;
				cur->next = temp;
				temp->item = n;
				temp->pre = cur;
				temp->next = start;
			    start->pre = temp;
				start = temp;
			}
       else {
        cur = start;
        for(int i=1 ; i<p-1 ; i++){
            cur = cur->next;
            if(cur==start){
                cout<<"\ninvalid position\n";
                return;
            }
        }
        temp = new node;
        cur->next->pre = temp;
        temp->item = n;
        temp->pre = cur;
        temp->next = cur->next;
        cur->next = temp;
    }
    }
    //deletion in circular linked list
    void cdbdel(int p){
      if(p==1){
        cout<<"\nEnter value\n\n";
        cin>>n;
        cur = start;
        if(cur->item==n){
        while(cur->next!=start)
            cur = cur->next;
        cur->next = start->next;
        start->next->pre = cur;
        delete start;
        start = cur->next;
      }
      }
      else if(p==2){
        cout<<"\nEnter value\n\n";
        cin>>n;
         cur = temp = start;
         while(cur->next!=start){
         if(cur->item==n){
            temp->next = cur->next;
            cur->next->pre = temp;
         delete cur;
         break;
    }
    temp = cur;
    cur = cur->next;
    }
    if(cur->next==start)
        cout<<"\nvalue not found\n";
    }
    else if(p==3){
        cout<<"\nEnter value\n\n";
        cin>>n;
        cur = start;
        while(cur->next!=start)
            cur = cur->next;
            if(cur->item==n){
         cur->pre->next = start;
         start->pre = cur->pre;
         delete cur;
    }
    if(cur->next==start)
        cout<<"\nvalue not found\n";
    }
      if(cur==start)
        cout<<"\nvalue not found\n";
    }
    //search function for circular linked list
    int csearch(int n){
        int i=0;
    cur = start;
    do{
           i++;
        if(cur->item==n){
            break;
        }
    cur = cur->next;
    }
   while(cur!=start);
   //agr first loaction pr hi value match ho jahay gi to cur me start ka address ho ga cur = start return 0 krta hy isi liay cur me next ka address rakha
   if(i==1)
    cur = cur->next;
    if(cur==start)
        return 0;
    else
        return i;
    }
    void display(){
        char ch[10] , ss[10] , spre[10];
        int x=217,y=190,left = 210, right = 240 , x2 = 28 , left1 = 210 , right1 = 325 ,left2 = 20 , right2 = 100 , xpre = 135 , preleft = 130 , preright = 210 ,
        x1 = 98 , y1 = 200 , x4 = 115 , y2 = 200 , arx = 115 , ary = 192 , count = 1 , arx1 = 1290;
        cur = start;
        //display start address
        ofstream file("C:\\filehandlingtxt\\string.txt");
        file<<cur;
        file.close();
        ifstream file1;
        file1.open("C:\\filehandlingtxt\\string.txt");
        file1>>ss;
         outtextxy(x2,150,"start");
         setbkcolor(5);
        setcolor(YELLOW);
        setlinestyle(0,0,3);
        rectangle(left2,180,right2,210);
        outtextxy(x2,y,ss);
        x2+=215;
        setbkcolor(5);
            while(cur!=NULL){
                    if(count<=5){
                            setbkcolor(0);
                     setcolor(WHITE);
                      outtextxy(x-10,150,"item");
                      outtextxy(xpre,150,"pre");
                      outtextxy(x2+10,150,"next");
                      setcolor(YELLOW);
                    setbkcolor(5);
                    //setline style
                    setlinestyle(0,0,3);
                //display previous address
                    ofstream filepre("C:\\filehandlingtxt\\previous.txt");
                    filepre<<cur->pre;
                    filepre.close();
                    ifstream filepre1("C:\\filehandlingtxt\\previous.txt");
                    filepre1>>spre;
                      rectangle(preleft , 180 , preright , 210);
                    outtextxy(xpre,y,spre);
                    filepre1.close();
                    //display next address
                   ofstream filen("C:\\filehandlingtxt\\string1.txt");
                    filen<<cur->next;
                    filen.close();
                    ifstream filenx;
                    filenx.open("C:\\filehandlingtxt\\string1.txt");
                    filenx>>ss;
                    rectangle(left1 , 180 , right1 , 210);
                    outtextxy(x2,y,ss);
                      filenx.close();
                      //itoa convert number to string
                    itoa(cur->item,ch,10);
                    //make rectangle box
                     rectangle(left,180,right,210);
                     //display data x left side space , y top se space
            outtextxy(x,y,ch);
            setlinestyle(2,0,3);
            line(x1 , y1 , x4 , y2);
            setbkcolor(0);
            outtextxy(arx , ary , ">");
            // x used for space in data number
            x +=240;
            // left and right used to make rectangle
            left += 240;
            right +=240;
            // x2 used for next address
            x2+=240;
            //left1 and right1 also used for next address
            left1+=240;
            right1+=240;
            // used for previous space
            preleft +=240;
            preright +=240;
            //used to print values outtextxy space
               xpre+=240;
               //line addition
               x1 +=240;
               x4 +=240;
            //for arrow sign
               arx +=240;
            cur = cur->next;
            delay(1000);
            count++;
        }
        else {
          y=240  , y1 = 250 , y2 = 250  , ary = 242;
                         // x used for space in data number
            x -=240;
            // left and right used to make rectangle
            left -= 240;
            right -=240;
            // x2 used for next address
            x2-=240;
            //left1 and right1 also used for next address
            left1-=240;
            right1-=240;
            // used for previous space
            preleft -=240;
            preright -=240;
            //used to print values outtextxy space
               xpre-=240;
               setbkcolor(0);
                     setcolor(WHITE);
                    outtextxy(x+10,270,"item");
                      outtextxy(xpre+140,270,"pre");
                      outtextxy(x2-90,270,"next");
               //line addition
               setbkcolor(5);
               setcolor(YELLOW);
                    //setline style
                    setlinestyle(0,0,3);
                    //display previous address
                    ofstream filepre("C:\\filehandlingtxt\\previous.txt");
                    filepre<<cur->pre;
                    filepre.close();
                    ifstream filepre1("C:\\filehandlingtxt\\previous.txt");
                    filepre1>>spre;
                      rectangle(preleft , 230 , preright , 260);
                    outtextxy(x2,y,spre);
                    filepre1.close();
                    //display next address
                   ofstream filen("C:\\filehandlingtxt\\string1.txt");
                    filen<<cur->next;
                    filen.close();
                    ifstream filenx;
                    filenx.open("C:\\filehandlingtxt\\string1.txt");
                    filenx>>ss;
                    rectangle(left1 , 230 , right1 , 260);
                    outtextxy(xpre,y,ss);
                      filenx.close();
                      //itoa convert number to string
                    itoa(cur->item,ch,10);
                    //make rectangle box
                     rectangle(left,230,right,260);
                     //display data x left side space , y top se space
            outtextxy(x,y,ch);
            if(count==6)
            {
                setlinestyle(2,0,3);
                line(x1 , 200 , x4 , 200);
                line(x1+15,200,x1+15,250);
                line(x1,250,x4,250);
                setbkcolor(0);
                outtextxy(arx1, ary , "<");
}
            else{
            setlinestyle(2,0,3);
            line(x1 , y1 , x4 , y2);
            setbkcolor(0);
            outtextxy(arx1, ary , "<");
            }
            cur = cur->next;
               x1 -=240;
               x4 -=240;
            //for arrow sign
               arx1 -=240;
            count++;
            delay(1000);
        }}

          settextstyle(10,0,5);
          setbkcolor(3);
          setcolor(12);
          outtextxy(500,80,"DOUBLE LINKED LIST");
    }
       void cdbdisplay(){
       char ch[10] , ss[10] , spre[10];
        int x=217,y=190,left = 210, right = 240 , x2 = 28 , left1 = 210 , right1 = 325 ,left2 = 20 , right2 = 100 , xpre = 135 , preleft = 130 , preright = 210 ,
          x1 = 98 , y1 = 200 , x4 = 115 , y2 = 200 , arx = 115 , ary = 192 , count = 1 ,arx1 = 1290 , l1=1130 ,l2 = 1300;
        cur = start;
        //display start address
        ofstream file("C:\\filehandlingtxt\\string.txt");
        file<<cur;
        file.close();
        ifstream file1;
        file1.open("C:\\filehandlingtxt\\string.txt");
        file1>>ss;
        setbkcolor(0);
        outtextxy(x2,150,"start");
        setcolor(YELLOW);
        setbkcolor(5);
        setlinestyle(0,0,3);
        rectangle(left2,180,right2,210);
        outtextxy(x2,y,ss);
        x2+=215;
        setbkcolor(5);
           // while(cur->next!=start){
           do{
                if(count<=5){
                    setbkcolor(0);
                     setcolor(WHITE);
                      outtextxy(x-10,150,"item");
                      outtextxy(xpre,150,"pre");
                      outtextxy(x2+10,150,"next");
                    setbkcolor(5);
                setcolor(YELLOW);
                    //setline style
                    setlinestyle(0,0,3);
                    //display previous address
                    ofstream filepre("C:\\filehandlingtxt\\previous.txt");
                    filepre<<cur->pre;
                    filepre.close();
                    ifstream filepre1("C:\\filehandlingtxt\\previous.txt");
                    filepre1>>spre;
                      rectangle(preleft , 180 , preright , 210);
                    outtextxy(xpre,y,spre);
                    filepre1.close();
                    //display next address
                   ofstream filen("C:\\filehandlingtxt\\string1.txt");
                    filen<<cur->next;
                    filen.close();
                    ifstream filenx;
                    filenx.open("C:\\filehandlingtxt\\string1.txt");
                    filenx>>ss;
                    rectangle(left1 , 180 , right1 , 210);
                    outtextxy(x2,y,ss);
                      filenx.close();
                      //itoa convert number to string
                    itoa(cur->item,ch,10);
                    //make rectangle box
                     rectangle(left,180,right,210);
                     //display data x left side space , y top se space
            outtextxy(x,y,ch);
            setlinestyle(2,0,3);
            line(x1 , y1 , x4 , y2);
            setbkcolor(0);
            outtextxy(arx , ary , ">");
            // x used for space in data number
            x +=240;
            // left and right used to make rectangle
            left += 240;
            right +=240;
            // x2 used for next address
            x2+=240;
            //left1 and right1 also used for next address
            left1+=240;
            right1+=240;
            // used for previous space
            preleft +=240;
            preright +=240;
            //used to print values outtextxy space
               xpre+=240;
               //line addition
               x1 +=240;
               x4 +=240;
            //for arrow sign
               arx +=240;
            cur = cur->next;
            delay(1000);
           count++;
        }
               else{
          y=240  , y1 = 250 , y2 = 250  , ary = 242;
                         // x used for space in data number
            x -=240;
            // left and right used to make rectangle
            left -= 240;
            right -=240;
            // x2 used for next address
            x2-=240;
            //left1 and right1 also used for next address
            left1-=240;
            right1-=240;
            // used for previous space
            preleft -=240;
            preright -=240;
            //used to print values outtextxy space
               xpre-=240;
               setbkcolor(0);
               setcolor(WHITE);
               outtextxy(x,270,"item");
               outtextxy(xpre+140,270,"pre");
               outtextxy(x2-90,270,"next");
               //line addition
               setbkcolor(5);
               setcolor(YELLOW);
                    //setline style
                    setlinestyle(0,0,3);
                    //display previous address
                    ofstream filepre("C:\\filehandlingtxt\\previous.txt");
                    filepre<<cur->pre;
                    filepre.close();
                    ifstream filepre1("C:\\filehandlingtxt\\previous.txt");
                    filepre1>>spre;
                      rectangle(preleft , 230 , preright , 260);
                    outtextxy(x2,y,spre);
                    filepre1.close();
                    //display next address
                   ofstream filen("C:\\filehandlingtxt\\string1.txt");
                    filen<<cur->next;
                    filen.close();
                    ifstream filenx;
                    filenx.open("C:\\filehandlingtxt\\string1.txt");
                    filenx>>ss;
                    rectangle(left1 , 230 , right1 , 260);
                    outtextxy(xpre,y,ss);
                      filenx.close();
                      //itoa convert number to string
                    itoa(cur->item,ch,10);
                    //make rectangle box
                     rectangle(left,230,right,260);
                     //display data x left side space , y top se space
            outtextxy(x,y,ch);
            //display line between nodes
               if(count==6)
            {
                setlinestyle(2,0,3);
                line(x1 , 200 , x4 , 200);
                line(x1+15,200,x1+15,250);
                line(x1,250,x4,250);
            setbkcolor(0);
            outtextxy(arx1, ary , "<");

            }
            setlinestyle(2,0,3);
            line(x1 , y1 , x4 , y2);
            setbkcolor(0);
            outtextxy(arx1, ary , "<");
            cur = cur->next;
               x1 -=240;
               x4 -=240;
            //for arrow sign
               arx1 -=240;
            count++;
            delay(1000);
                }}
                while(cur!=start);
                if(count<=6){
                setlinestyle(2,0,3);
                line(x1,200,x4,200);
                line(x1+15,200,x1+15,250);
                line(l2-l1,250,x4,250);
                line(l2-l1,230,l2-l1,250);
                outtextxy(170,215,"^");
                }
                else {
                    setlinestyle(2,0,3);
                    line(l2-l1,250,x4,250);
                    line(170,230,170,250);
                    outtextxy(170,215,"^");
                    l1 -=230;
                }
                settextstyle(10,0,5);
          setbkcolor(3);
          setcolor(12);
          outtextxy(400,80,"CIRCULAR DOUBLE LINKED LIST");
       }
};
int main()
{
    DbLink l1;
       int p , d , n;
       char ch , op;
       do{
            system("cls");
       system("color f5");
       cout<<"\n\na-)Operations for Double linked list \n\nb-)Operation for cirular double linked list \n\nc-)Esc for Exit\n\n\n";
        ch = _getch();
        switch(ch){
        case 'a':
            do{
            system("cls");
            system("color e2");
            cout<<"\n\n\tDOUBLE LINKED LIST OPERATION";
            cout<<"\n\n1-)inserting values \n2-)insertion at beiginning and specified loacation \n3-)Deletion operation \n4-)Searching operation \n5-)Display Linked List \n6-)Goto Front\n\n\n";
            ch = _getch();
            if(ch=='1'){
                    system("cls");
            system("color e1");
                cout<<"\n\nEnter 5 values\n\n";
                for(int i=1 ; i<=5 ; i++){
                    //cin>>n;
                    while(!(cin>>n)){
                        cout<<"Plz enter a number\n";
                        cin.clear();
                        cin.ignore();
                    }
                    l1.dbadd(n);
                }
                    cout<<endl;
                    system("pause");
                }
                else if(ch=='2'){
                        system("cls");
                        system("color f5");
                        cout<<"\nEnter Position(1-5)\n\n";
                        cin>>p;
                        cout<<"\nEnter value\n\n";
                        cin>>d;
                        l1.dbinsert(d,p);
                        cout<<endl;
                        system("pause");
                }
                else if(ch=='3'){
                            system("cls");
                            system("color e0");
                            cout<<"\nDeletion at beigning(1), middle(2) and end (3)\n\n";
                            cin>>d;
                            if(d>3)
                                cout<<"\ninvalid position\n";
                            else
                            l1.dbdel(d);
                            cout<<endl;
                            system("pause");
            }
            else if(ch=='4'){
                system("cls");
                system("color e1");
                cout<<"\nEnter value to search\n\n";
                cin>>d;
                int c = l1.search(d);
                if(c==0)
                   cout << "\nvalue not found" << endl;
                else
                cout<<"\nvalue found in index  "<<c;
                cout<<endl<<endl;
                system("pause");
            }
              else if(ch=='5'){
                                initwindow(1320,700,"Linked list",700,500);
                                l1.display();
                                delay(5000);
                                closegraph();
            }
            else if(ch=='6'){}
            else{
                cout<<"\ninvalid option\n\n";
            system("pause");
            }
            }
            while(ch!='6');
            l1.set();
                        break;
        case 'b':
            do{
              system("cls");
            system("color e2");
              cout<<"\n\n\tCIRCULAR DOUBLE LINKED LIST OPERATION";
            cout<<"\n\n1-)insert values \n2-)insertion at beiginning and specified loactioin \n3-)Deletion operation \n4-)Searching operation \n5-)Display Linked List \n6-)Goto Front\n\n\n";
            ch = _getch();
                        if(ch=='1'){
                system("cls");
                system("color e1");
                cout<<"\n\nEnter 5 values\n\n";
                for(int i=1 ; i<=5 ; i++){
                   // cin>>n;
                   while(!(cin>>n)){
                    cout<<"plz enter a number\n";
                    cin.clear();
                    //discard the previous value
                    cin.ignore();
                   }
                    l1.cdadd(n);
                }
                cout<<endl;
                system("pause");
                }
                else if(ch=='2'){
                        system("cls");
                        system("color f4");
                        cout<<"\nEnter Position\n\n";
                        cin>>p;
                        cout<<"\nEnter value\n\n";
                        cin>>d;
                        l1.cdbinsert(p,d);
                        cout<<endl;
                        system("pause");
                }
                else if(ch=='3'){
                            system("cls");
                            system("color e0");
                            cout<<"\nDeletion at beigning(1), middle(2) and end (3)\n\n";
                            cin>>d;
                            if(d>3)
                                cout<<"\ninvalid position\n";
                            else
                            l1.cdbdel(d);
                            cout<<endl;
                            system("pause");
            }
            else if(ch=='4'){
                    system("cls");
                    system("color e1");
                    cout<<"\nEnter value to search\n\n";
                    cin>>d;
                    int c = l1.csearch(d);
                    if(c==0)
                   cout << "\nvalue not found" << endl;
                   else
                   cout<<"\nvalue found in index  "<<c;
                   cout<<endl;
                   system("pause");
                    }
              else if(ch=='5'){
                                initwindow(1320,700,"Linked list",700,500);
                                l1.cdbdisplay();
                                delay(5000);
                                closegraph();
            }
            else if(ch=='6'){}
            else{
                cout<<"\ninvalid option\n";
                system("Pause");
        }}
            while(ch!='6');
            l1.set();
            break;
        case 27:
            break;
            default:
                cout<<"\ninvalid option\n\n";
                system("pause");
                break;
       }
       }
       while(ch!=27);
        system("pause");
    return 0;
}



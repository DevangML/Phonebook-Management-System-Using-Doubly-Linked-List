
#include <iostream>
#include<cstring>
using namespace std;
class dnode
{
    public:
        char number[50];
        char gmail[40];
        char name[30];
        dnode *prev,*next;
        dnode(char n[],char r[],char g[])
{
               strcpy(name,n);
                strcpy(number,r);
               strcpy(gmail,g);
                next=NULL;
                prev=NULL;
}
	friend class dlist;
};
class dlist
{
    dnode *head,*temp,*ptr;

    dnode *ptr1, *ptr2, *dup;
    public:
    dnode *prevn;

    void insert();
    void sort();
    void deletecontact(char n[20]);
    void deletesamenumber();
    void deletesamename();
    void deletesamegmail();
    void searchbyname(char p[20]);
    void searchbynumber(char no[30]);
    void searchbygmail(char g[20]);

        // dnode *head,*temp,*ptr;
        // friend class apply;
        void accept();
        void display();
        void update(char ch[10]);
        dlist()
                {
                        head=NULL;
                        temp=NULL;
                        ptr=NULL;
                        ptr1=NULL;
                        ptr2=NULL;
                        dup=NULL;
                }
};
// class apply()
// {

// }
void dlist::accept()
{
        char number[50];
        char gmail[40];
        char name[30];
    char ans;
      do
        {
    cout<<"ENTER NAME      :";
    cin>>name;
    // cin.getline (name,30);
    cout<<"ENTER NUMBER    :";
    cin>>number;
    while(strlen(number)!=10)
    {
    cout<<"ENTER VALID NUMBER  :";
    cin>>number;
    }
    cout<<"ENTER G-MAIL    :";
    cin>>gmail;
    temp=new dnode(name,number,gmail);
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
       ptr=head;
		while(ptr->next!=NULL)
		{
ptr=ptr->next;
		}
		ptr->next=temp;
		temp->prev=ptr;
    }
	    cout<<"DO YOU WANT TO CONTINUE?????????";
    cin>>ans;
}while(ans=='y');

}
void dlist::display()
{
    ptr=head;//start the node
	while(ptr!=NULL)//traverse till last
	{
			cout<<"\n\nNAME  ::\t"<<ptr->name;
			cout<<"\nNUMBER::\t+91-"<<ptr->number;
			cout<<"\nG-MAIL::\t"<<ptr->gmail;
			ptr=ptr->next;
	}
}

    void dlist::insert()
    {
        accept();
    }
    void dlist::sort()
    {
        dnode *i,*j;
        int temp;
        char n[10];
        for(i=head;i->next!=NULL;i=i->next)
        {
            for(j=i->next;j!=NULL;j=j->next)
            {
                temp=strcmp(i->name,j->name);
                if(temp>0)
                {
                   strcpy(n,i->name);
                   strcpy(i->name,j->name);
                   strcpy(j->name,n);
                }
            }
        }

    }



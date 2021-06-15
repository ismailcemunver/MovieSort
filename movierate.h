#ifndef MOVIERATE_H_INCLUDED
#define MOVIERATE_H_INCLUDED
using namespace std;
struct node{
    string moviename;
    int movieyear;
    double movierate;
    node *next;
};
node *i=NULL;
node *years=NULL;
node *names=NULL;
node *rates=NULL;
node *nameptr;
node *rateptr;
node *yearptr;
int counter=0;
void add(string name,double rate, int year)
{
    node *nametemp=new node;
    node *ratetemp=new node;
    node *yeartemp=new node;
    nametemp->moviename = name;
    nametemp->movierate = rate;
    nametemp->movieyear = year;
    yeartemp->moviename = name;
    yeartemp->movierate = rate;
    yeartemp->movieyear = year;
    ratetemp->moviename = name;
    ratetemp->movierate = rate;
    ratetemp->movieyear = year;
    if(names == NULL || names->moviename[0] > name[0]){
            nametemp->next=names;
            names=nametemp;
            counter++;
    }
    else{
        for(i = names; i->next != NULL && i->next->moviename < name; i=i->next){
        }
        nametemp->next=i->next;
        i->next=ratetemp;
        counter++;
    }
    if(rates==NULL || rates->movierate > rate){
            ratetemp->next=rates;
            rates=ratetemp;
    }
    else{
        for(i = rates; i->next != NULL && i->next->movierate < rate; i=i->next){
        }
        ratetemp->next=i->next;
        i->next=ratetemp;
    }
    if(years==NULL || years->movieyear > year){
            yeartemp->next=years;
            years=yeartemp;
    }
    else{
        for(i = years; i->next != NULL && i->next->movieyear < year; i=i->next){
        }
        yeartemp->next=i->next;
        i->next=yeartemp;
    }
}
bool remove_movie(string name) {
    node *ratetemp=rates;
    node *nametemp=names;
    node *yeartemp=years;
    node *nameptr=NULL;
    node *rateptr= NULL;
    node *yearptr=NULL;
    if(yeartemp != NULL && yeartemp->moviename == name){
        years=yeartemp->next;
        delete yeartemp;
    }
    else{
        while(yeartemp != NULL && yeartemp->moviename != name){
            yearptr=yeartemp;
            yeartemp = yeartemp->next;
        }
        if(yeartemp == NULL){
            return 0;
        }
        yearptr->next = yeartemp->next;
        delete yeartemp;
    }
    if(ratetemp != NULL && ratetemp->moviename == name){
        rates=ratetemp->next;
        delete ratetemp;
    }
    else{
        while(ratetemp != NULL && ratetemp->moviename != name){
            rateptr=ratetemp;
            ratetemp = ratetemp->next;
        }
        if(ratetemp == NULL){
            return 0;
        }
        rateptr->next = ratetemp->next;
        delete ratetemp;
    }
    if(nametemp != NULL && nametemp->moviename == name){
        names=nametemp->next;
        delete nametemp;
    }
    else{
        while(nametemp != NULL && nametemp->moviename != name){
            nameptr=nametemp;
            nametemp = nametemp->next;
        }
        if(nametemp == NULL){
            return 0;
        }
        nameptr->next = nametemp->next;
        delete nametemp;
    }
}
void update(string name, double rate)
{
    rateptr=rates;
    yearptr=years;
    nameptr=names;
    if(names->moviename == name){
        names->movierate = rate;
    }
    while(nameptr->next!=NULL && nameptr->moviename != name){
        nameptr=nameptr->next;
    }
    nameptr->movierate=rate;
    if(rates->moviename == name){
        rates->movierate = rate;
    }
    while(rateptr->next!=NULL && rateptr->moviename != name){
        rateptr=rateptr->next;
    }
    rateptr->movierate=rate;
    if(years->moviename == name){
        years->movierate = rate;
    }
    while(yearptr->next!=NULL && yearptr->moviename != name){
        yearptr=yearptr->next;
    }
    yearptr->movierate=rate;
}
void printByYear(){
    i=years;
    int k=1;
    cout<<"Printing by years... \n";
    while(i!=NULL){
            cout<<k<<": ";
            cout<<"Name : "<<i->moviename<<" ";
            cout<<"Rate : "<<i->movierate<<" ";
            cout<<"Year : "<<i->movieyear<<"\n";
            i=i->next;
            k++;
    }
}
void printByName(){
    i=names;
    int k=1;
    cout<<"Printing alphabetically... \n";
    while(i!=NULL&&k<counter){
            cout<<k<<": ";
            cout<<"Name : "<<i->moviename<<" ";
            cout<<"Rate : "<<i->movierate<<" ";
            cout<<"Year : "<<i->movieyear<<"\n";
            i=i->next;
            k++;
    }
}
void printByRate(){
    i=rates;
    int k=1;
    cout<<"Printing by rate... \n";
    while(i!=NULL){
            cout<<k<<": ";
            cout<<"Name : "<<i->moviename<<" ";
            cout<<"Rate : "<<i->movierate<<" ";
            cout<<"Year : "<<i->movieyear<<"\n";
            i=i->next;
            k++;
    }
}
void saveToFileByYear(string filename){
    ofstream writer(filename);
    int k=1;
    writer<<"Printed by years... \n";
    i=years;
    while(i!=NULL){
            writer<<k<<": ";
            writer<<"Name : "<<i->moviename<<" ";
            writer<<"Rate : "<<i->movierate<<" ";
            writer<<"Year : "<<i->movieyear<<"\n";
            i=i->next;
            k++;
    }
}
void saveToFileByName(string filename){
    ofstream writer(filename);
    int k=1;
    writer<<"Printed alphabetically... \n";
    i=names;
    while(i!=NULL){
            writer<<k<<": ";
            writer<<"Name : "<<i->moviename<<" ";
            writer<<"Rate : "<<i->movierate<<" ";
            writer<<"Year : "<<i->movieyear<<"\n";
            i=i->next;
            k++;
    }
}
void saveToFileByRate(string filename){
    ofstream writer(filename);
    int k=1;
    writer<<"Printed by rate... \n";
    i=rates;
    while(i!=NULL){
            writer<<k<<": ";
            writer<<"Name : "<<i->moviename<<" ";
            writer<<"Rate : "<<i->movierate<<" ";
            writer<<"Year : "<<i->movieyear<<"\n";
            i=i->next;
            k++;
    }
}
#endif // MOVIERATE_H_INCLUDED

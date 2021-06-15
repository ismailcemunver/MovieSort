#include <iostream>
#include <string.h>
#include <fstream>
#include "movierate.h"
using namespace std;
int main()
{
    int choice=1;
    string mname,mfile;
    double mrate;
    int myear;
    while(choice != 0){
        cout<<"(1) Add a movie to the list.\n";
        cout<<"(2) Change a movie rating in the list.\n";
        cout<<"(3) Delete a movie in the list.\n";
        cout<<"(4) Print the movie list sorted by names.\n";
        cout<<"(5) Print the movie list sorted by ratings.\n";
        cout<<"(6) Print the movie list sorted by years.\n";
        cout<<"(7) Write the movie list sorted by names to a file.\n";
        cout<<"(8) Write the movie list sorted by ratings to a file.\n";
        cout<<"(9) Write the movie list sorted by years to a file.\n";
        cout<<"(0) Exit the movie sorter.\n";
        cin>>choice;
        if(choice==1){
            cout<<"Enter a movie name.\n";
            cin.ignore();
            getline(cin,mname);
            cout<<"Enter a movie rate.\n";
            cin>>mrate;
            cout<<"Enter a movie year.\n";
            cin>>myear;
            add(mname,mrate,myear);
            cout<<"Successfully added.\n";
        }
        if(choice==2){
            cout<<"Enter a movie name to update. \n";
            cin.ignore();
            getline(cin,mname);
            cout<<"Enter a movie rate to update. \n";
            cin>>mrate;
            update(mname,mrate);
            cout<<"Successfully updated.\n";
        }
        if(choice==3){
            cout<<"Enter a movie name to delete. \n";
            cin.ignore();
            getline(cin,mname);
            remove_movie(mname);
            cout<<"Successfully removed.\n";
        }
        if(choice==4){
            printByName();
            cout<<"Successfully printed.\n";
        }
        if(choice==5){
            printByRate();
            cout<<"Successfully printed.\n";
        }
        if(choice==6){
            printByYear();
            cout<<"Successfully printed.\n";
        }
        if(choice==7){
            cout<<"Enter a file name to write the list by names. \n";
            cin.ignore();
            getline(cin,mfile);
            saveToFileByName(mfile);
            cout<<"Successfully writed.\n";
        }
        if(choice==8){
            cout<<"Enter a file name to write the list by rates. \n";
            cin.ignore();
            getline(cin,mfile);
            saveToFileByRate(mfile);
            cout<<"Successfully writed.\n";
        }
        if(choice==9){
            cout<<"Enter a file name to write the list by years. \n";
            cin.ignore();
            getline(cin,mfile);
            saveToFileByYear(mfile);
            cout<<"Successfully writed.\n";
        }
        if(choice==0){
            break;
        }

    }
}

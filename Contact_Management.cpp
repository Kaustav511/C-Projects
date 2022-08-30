#include<bits/stdc++.h>
#include<conio.h>
#include<fstream>
using namespace std;

string fn,ln,ph_no;



void addContact();
void serchContact();
void help();
void self_exit();
bool check_digit(string);
bool check_number(string);
int main(){
    short int choice;
    system("cls");
    system("color 0A");
    cout<<"\n\n\n\t\t\tContact Management.";
    cout<<"\n\n\t1. Add Contact\n\t2. Search Contact\n\t3. Help\n\t4. Exit\n\t> ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        addContact();
        break;
    case 2:
        serchContact();
        break;
    case 3:
        help();
        break;
    case 4:
        self_exit();
        break;
    default:
        cout<<"\n\n\tInvalid Input !";
        cout<<"\n\tPress Ant Key To Continue.. ";
        getch();
        main();
    }
return 0;
}
void addContact(){
    ofstream number("number.txt",ios::app);
    system("cls");
    cout << "\n\n\tEnter First Name : ";
    cin >> fn;
    cout << "\n\tEnter Last Name : ";
    cin >> ln;
    cout << "\n\tEnter 10-Digit Phone Number : ";
    cin >> ph_no;

    if(check_digit(ph_no)==true){
        if(check_number(ph_no)==true){
            if(number.is_open()){
                number <<fn <<" " <<ln <<" "<<ph_no<<endl;
                cout<<"\n\tContact Saved Successfully...";
            }
            else{
                cout<<"\n\tError Opening File !";
            }
        }
        else{
            cout<<"\n\tA Phone Number Must Contain Only Numbers";
        }
    }
    else{
        cout<<"\n\tA Phone Number Must COntain 10 Digits.";
    }
    number.close();
}
void serchContact(){
    bool found = false;
    ifstream myfile("number.txt");
    string keyword;
    cout << "\n\tEnter Name To Search : ";
    cin >> keyword;
    while(myfile >> fn >> ln >> ph_no)
    {
        if(keyword == fn || keyword == ln)
        {
            system("cls");
            cout << "\n\n\n\t\tContact details..";
            cout << "\n\n\tFirst Name : " << fn;
            cout << "\n\tLast Name : " << ln;
            cout << "\n\tPhone Number : " << ph_no;
            found = true;
            break;
        }
    }
    if(found == false)
    cout << "\n\tNo Such Contact Found";
}
void help(){

}
void self_exit(){
    system("cls");
    cout<<"\n\n\n\t\tThank You For Using !..";
    exit(1);
}
bool check_digit(string k){
    if(k.length()==10){
        return true;
    }
    else{
        return false;
    }
}
bool check_number(string k){
    bool check=true;
    for(int i=0;i<k.length();i++){
        if(!(int(k[i])>=48 && int(k[i])<=57)){
            check=false;
            break;
        }
    }
    if(check==true){
            return true;
        }
        else{
            return false;
        }
}
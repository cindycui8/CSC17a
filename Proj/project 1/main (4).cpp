/* 
 * File:   main.cpp
 * Author: Cui,Zhiyan
 * Purpose: create a basic game for hamburger restaurant, and the player will 
 *          serve the customer food 
 * Created on April 20, 2015, 2:27 PM
 */

// system libraries
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>

//global constant
const int SIZE =100;
// user libraries
struct User{
    char id[SIZE];   // user id
    char pw[SIZE];   // user password
    int point;  // user's point
    
};
using namespace std;

// function prototype
// function for menu system
void Menu(); // menu system for game
void menu(); // menu for the game
int getN();

//function for check user id
int open(User *);    // make sure the file can open and pass the length of the User array
bool checkId(User *,int);   // check user name is available
bool checkPw(char *); //check the password
int countLetters(char*);
int countDigits(char*);
void sign(User *,int);
void log(User *,int);
bool chckOld(User *, int);
//function for game
void game(User *,int);
bool comp(int,char *);
void def(int);


/*
 * 
 */
int main(int argc, char** argv) {

    // Declare the variable
    int inN;
    User *u = new User [SIZE];
    int length;
    length =open(u); // call for open the file
    
    do{
        Menu();
        inN=getN();
        switch(inN){
        case 1:    sign(u,length);break;
        case 2:    log(u,length);break;
        case 3:    game(u,length);break;
        default:   def(inN);}
    }while(inN>=1&&inN<=3);
    fstream out ;
    out.open("user.txt",ios::out|ios::binary);
    out.write(reinterpret_cast<char *>(u),sizeof(User));
    delete []u;
    
    return 0;
}

void Menu(){
    cout<<"Welcome to the Happy Star"<<endl;
    cout<<"Type 1 for sign in "<<endl;
    cout<<"Type 2 for log in "<<endl;
    cout<<"Type 3 for start"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

int getN(){
        int inN;
        cin>>inN;
        return inN;
}

int open(User *u){
    fstream indata;
    int length=1;
    int i =0;
    
    char fn[] = "user.txt";
    indata.open(fn,ios::in|ios::out|ios::binary);
    if(!indata){
        cout <<"Error, cannot open the file" << endl;
        cout <<"It may not exist where it indicate"<< endl;
    }
    cout << " open file Successfully" << endl;
    
    do{
        //Read from the file
        indata >> u[i].id;
        indata >> u[i].pw;
        indata >> u[i].point;
        i++;
        
    }while(!indata.eof());
            
    indata.close();
    return i;
}

bool checkId(User *u,int length){
     cout <<" check id" << endl;
    int row = 0;
        bool same = false;  // two id name is not same 
     do{
           if(u[length].id == u[row].id)
           {
                           same = true;
                           return same;
           }
           row++;
     }while(row < length);
     return same;
}
void sign(User *u,int length){
    cin.ignore(80,'\n');
    //Declare the variable
    ofstream outfile;
    outfile.open("user.txt", ios::out|ios::binary);
    // get the user name
    
     cout << " Please enter your user name :" ;
     cin >> u[length].id;
     if(length!=0){
     do{
     if (checkId(u,length))
     {
        cout << " your user name is not avaiable" << endl;
        cout << " you can change a another user name" << endl;
        cin >> u[length].id;
     }
     else
     {
         cout << " your name is ok to use" << endl;
     }
     }while(checkId(u,length));
     }
     
     // get the user's password
     
        cout << " Plese enter a password consisting of more than 6 characters less than 13 characters" << endl;
        cin >> u[length].pw;
        if(length!=0){
        do{
        if ( checkPw(u[length].pw))
           cout << " Your password is OK to use" << endl;
        else
        {
                cout << "Invalid password. Please enter a password" << endl;
                cout << " For example, My37Run9 is valid" << endl;
                cin >>u[length].pw;
        }
      }while ( checkPw(u[length].pw)!= true);
        }
    u[length].point =0;
        outfile.write(reinterpret_cast<char *>(u),sizeof(User));
    // delete the file
    outfile.close();
    
    
     cout << " Here are some instructions " << endl;
    game(u,length);
    
}
bool checkPw(char *passWord){
    int length, numL, numD, num;
     length = strlen(passWord);
     numL = countLetters(passWord);
     numD = countDigits(passWord);
     if ( numL > 0 && numD > 0 && length > 6 && length < 13)
        return true;
     else
         return false;
    
}
int countLetters(char *strPtr)
{
    int occurs = 0;
    while (*strPtr != '\0')
    {
          if(isalpha(*strPtr))
                 occurs++;
          strPtr++;
    }
    return occurs;
}   
int countDigits(char *strPtr)
{
    int occurs = 0;
    while (*strPtr != '\0')
    {
          if(isdigit(*strPtr))
                 occurs++;
          strPtr++;
    }
    return occurs;
}  
void log(User *u,int length){
     
     cout << " Please enter your user name and password" << endl;
     cout << " user name: ";
     cin >> u[length].id;
     cout << endl;
     cout << " Password: " ;
     cin >> u[length].pw; 
     cout << endl;
     if(chckOld(u, length)){
     cout << u[length].id << " welcome to Happy Star" <<endl;
     } 
     else{
           cout << " sorry, your name or password is invalid" << endl;
           sign(u,length);
           }
           
     cout << " Here are some instructions " << endl;
    
}
bool chckOld(User *u, int length)
{
     int row = 0;
     char found = 'f';
     while (row < length && !found)
     {
        
           if(u[row].id == u[length].id && u[row].pw == u[length].pw)
           {
                           found = 't';
           }
           row++;
         
     }
     if(found = 't')
              return true;
     else
         return false;
}
void game(User *u,int length){
    cin.ignore(80,'\n');
     cout << endl << endl<< endl;
    cout << " Welcome to Happy Star" << endl;
    cout << " Our restaurant serves hamburgers to costumer" << endl;
    cout <<" You need to cook the different burger and serve the costumers" << endl;
    cout <<" Let's start" << endl;
    // declare the variables
    menu();
    int cus;    // number of the customers
    char type[6];  // type in all the ingradius for ingredients
    int cash =10;
     char chicken[]={'b','c','t','l','s','b'};
     char beef[] = {'b','f','o','l','s','b'};
    char egg[] = {'b','e','t','n','s','b'};
    int quit;
    int bur;    // burger
    cout <<" if you want to quit the game, plese type 0" << endl;
    do
    {
        cus = rand()%10+3;
        int i =0;
        int count =0;
        cout << " initial cash " << cash << endl;
        do{
            bur = rand()%2+1;
            cout << " cash after make one burger " << cash << endl;
            if(bur ==1){
                
             cout << " cash before make chicken burger " << cash << endl;
                cout <<" a chicken burger" << endl;
                cout <<"A chicken sandwich is  Bread, chicken, tomato,lettuce,sauces,and bread"<< endl;
                for(int i =0;i < 6;i++){
                    cin >> type[i];
                }
                if(comp(bur,type)){
                        cout << " Perfect" << endl;
                        cout << " you reveive $10" << endl;
                        cout << " cash before add" << cash << endl;
                        cash +=10;
                        cout << " cash " << cash << endl;
                        }
                else{
                      cout <<"You serve the wrong burger" << endl;
                      cout <<"You lose $3" << endl;
                      cash-=3;
                      
                        cout << " cash " << cash << endl;
                      }
            }
            else if(bur ==2){
                
             cout << " cash before make beef burger " << cash << endl;
                cout <<" a regurlar hamburger" << endl;
                cout <<"Beef burger is bead, beef,onion,lettuce,sauces,and bread"<< endl;
                for(int i =0;i < 6;i++){
                    cin >> type[i];
                }
                
                 cout << " cash before " << cash << endl;
                if(comp(bur,type)){
                        cout << " Perfect" << endl;
                        cout << " you reveive $12" << endl;
                        
                        cout << " cash before add" << cash << endl;
                        cash +=12;
                        
                        cout << " cash " << cash << endl;
                        }
                else{
                      cout <<"You serve the wrong burger" << endl;
                      cout <<"You lose $6" << endl;
                      cash-=6;
                      
                        cout << " cash " << cash << endl;
                      }
            }
            else{
                 cout <<" a egg sandwich" << endl;
                cout <<"Egg sandwich is bread,egg,tomato,bacon,sauces,and bread"<< endl;
                for(int i =0;i < 6;i++){
                    cin >> type[i];
                }
                 cout << " cash before " << cash << endl;
                if(comp(bur,type)){
                        cout << " Perfect" << endl;
                        cout << " you reveive $11" << endl;
                        
                        cout << " cash before add" << cash << endl;
                        cash +=11;
                        
                        cout << " cash " << cash << endl;
                        }
                else{
                      cout <<"You serve the wrong burger" << endl;
                      cout <<"You lose $6" << endl;
                      cash-=4;
                      
                        cout << " cash " << cash << endl;
                      }
                 }
                 if(cash <=0){
                         cout <<" Sorry, you don't have enough money to make burger" << endl;
                         cout <<" Game Over " << endl;
                         u[length].point +=0;
                 }
            i++;
        }while(i<cus&&cash >0);
        cin.ignore(80,'\n');
        cout <<" you earn $ " << cash << " for toady" << endl;
        u[length].point = 0;
        u[length].point += cash;
        cout <<" Now your total point is " << u[length].point << endl;
        cout <<" do you want to quit the game"<< endl;
        cout <<" enter 0 to quit the game" << endl;
        cout <<" enter any other number to continue" <<endl; 
        cin >> quit;
        
        
    }while(quit !=0);      
    
}
void menu(){
    cout <<"Happy Star has three type of burger"<< endl;
    cout <<"chicken sandwich, beef burger,and egg sandwich"<< endl;
    cout <<"Type b for bread "<< endl;
    cout <<"Type l for lettuce"<< endl;
    cout <<"Type t for tomato"<< endl;
    cout <<"Type o for onion"<< endl;
    cout <<"Type c for chicken"<< endl;
    cout <<"Type f for beef"<< endl;
    cout <<"Type n for bacon"<< endl;
    cout <<"Type e for egg"<< endl;
    cout <<"Type s for sauces"<< endl;
    cout <<"Type h for cheese"<< endl;
    cout <<"When you cook remember always start with bottom to top"<< endl;
    cout <<"A chicken sandwich is  Bread, chicken, tomato,lettuce,sauces,and bread"<< endl;
    cout <<"Beef burger is bead, beef,onion,lettuce,sauces,and bread"<< endl;
    cout <<"Egg sandwich is bread,egg,tomato,bacon,sauces,and bread"<< endl;
    cout <<"regular hamger == bfolsb" << endl;
    cout <<"Chicken Burger == bctlsb" << endl;
    cout <<"Egg Sandwich == betnsb" << endl;
    cout <<"if customer asks for a chicken sandwich,"<< endl;
    cout <<"you need to type in bctlsb"<< endl;
    cout << endl << endl << endl;
    cout << " Let's Play" << endl;
    cout << " Remember dont put space in between " << endl;
    
}
bool comp(int bur, char *type){
    cout << endl << endl; 
    cout << " compare " << endl;
    int  count =0;
    bool equal = true;
     char chicken[]={'b','c','t','l','s','b'};
     char beef[] = {'b','f','o','l','s','b'};
    char egg[] = {'b','e','t','n','s','b'};
    for(int i =0;i < 6 ;i++){
        cout << " chicken " << chicken[i] << " " ;
        cout << " type " << type[i] <<    " "; 
        cout << endl;
                
    }
    if(bur ==1){
        do{
            cout << type[count] << " type " ;
            cout << beef[count] << " beef ";
            if(type[count]!= chicken[count])
            {return false;}
                            count++;
        }while(count <6 &&equal == true);
        
    }
    else if(bur ==2){
        do{
        if(type[count]!= beef[count])
        {return false;}
                            count++;
        }while(count <6 &&equal == true);
    }
       else {
      do{
        if(type[count]!= egg[count])
        { return false;}
                            count++;
        }while(count <6 &&equal == true);
}
    return true;
}
void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}



/* 
 * File:   main.cpp
 * Author: Zhiyan Cui
 * Created on March 25, 2015, 2:00 PM
 */

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <cstring>
#include <fstream>
#include <cctype>

using namespace std;
// Global constant
const int SIZE = 80;

// structure
// problem 11.9
struct Speaker
{
    char name[SIZE];
    int phone;
    char topic[SIZE];
    float fee;
};
//problem 11.4
struct Weather
{
    int rain;
    int hTem;
    int lTem;
    float ave;
};
//problem 11.6
struct Soccer
{
       char name [SIZE];
       int num;
       int points;      
};
// problem 12.11
struct User
{
       char name[SIZE];
       int quart;
       float sale[SIZE];       
};

// function prototype 
void pro1();        // homework 10.4
void pro2();        // homework 10.6
int countV(char[], int);      // count vowels
int countC(char [],int);      // count consonants
void pro3();        // homework 10.7
void pro4();        // homework 11.9
void pro5();        // homework 11.
void pro6();        // homework 11.
void pro7();        // homework 12.7
void pro8();        // homework 12.8
void arrayToFile(char [], int *, int);    // conver array to file
void fileToArray(char [], int *, int);
void pro9();        // homework 12.11
void pro10();       // homework 12.

/*
 * 
 */
int main(int argc, char** argv) {
    
    // initialize the variables
    int choice;
    const int  PROB1 =1,
              PROB2 =2,
              PROB3 =3,
              PROB4 =4,
              PROB5 =5,
              PROB6 =6,
              PROB7 =7,
              PROB8 =8,
              PROB9 =9,
              PROB10 =10,
              QUIT = 11;
    // for the menu system
    do{
    cout << " 1. problem 10.4" << endl;
    cout << " 2. problem 10.6" << endl;
    cout << " 3. problem 10.7" << endl;
    cout << " 4. problem 11.9" << endl;
    cout << " 5. problem 11.4" << endl;
    cout << " 6. problem 11.6" << endl;
    cout << " 7. problem 12.7" << endl;
    cout << " 8. problem 12.8" << endl;
    cout << " 9. problem 12.11" << endl;
    cout << " 10. problem 12." << endl;
    cout << " 11. quit program" << endl;
    cout << " Please type in the number that you wish to check" << endl;
    cin >> choice;
    while(choice < PROB1 || choice > QUIT){
                 cout << " Please input a valid number" << endl;
                 cin >> choice;
                 }
                 if(choice != QUIT){
                           switch (choice){
                                  case PROB1: 
                                              pro1();
                                              break;
                                  case PROB2: 
                                              pro2();
                                              break;
                                  case PROB3: 
                                              pro3();
                                              break;
                                  case PROB4: 
                                              pro4();
                                              break;
                                  case PROB5: 
                                              pro5();
                                              break;
                                  case PROB6: 
                                              pro6();
                                              break;
                                  case PROB7: 
                                              pro7();
                                              break;
                                  case PROB8: 
                                              pro8();
                                              break;
                                  case PROB9: 
                                              pro9();
                                              break;
                                  case PROB10: 
                                              pro10();
                                              break;
                                  
                                  }
                                  }
    }while (choice !=QUIT);
 
    system("PAUSE");
    return EXIT_SUCCESS;
}
void pro1()
{
    // declare the variables
    char word[SIZE];
    int i=0;
    int length;   // the length of the word
    int count =1;    // count how many word 
    int ave;    // find the average number of letter
    // get a line of input
    cin.ignore(80,'\n');
    cout << " Please enter a sentence of no more than "  << (SIZE - 1) << " characters" << endl;
    cin.getline(word,SIZE);
    // find the size of the array
    length = strlen(word);
    while(i < length ){
        if(word[i] == ' ')
            count++;
            i++;
            
    }
    cout << endl;
    cout << " There are " << count << " number of word" << endl;
    ave = (length-count)/count;
    cout << " The average number of letters in each word is " << ave << endl;

}

void pro2()
{ 
    // declare the variables
    char word[SIZE];
    char choice;
    int s;      // size of the array
    int v;      // vowels of the string
    int c;      // consonats of the string
    cin.ignore(80,'\n');
    cout << " Please enter a sentence of no more than "  << (SIZE - 1) << " characters" << endl;
    cin.getline(word,SIZE);
    s= strlen(word);
    do{
    cout << " A. count the number of vowels in the string" << endl;
    cout << " B. count the number of consonants in the string" << endl;
    cout << " C. count both the vowels and consonants in the string" << endl;
    cout << " D. enter another string" << endl;
    cout << " E. exit the program" << endl;
    cin >> choice;
    cout << " choice " << choice << endl;
   
    if(tolower(choice) !='e' ){
        if (choice == 'a'||choice == 'A'){
                         v = countV(word,s);
                         cout << " there are " << v << " of vowels in the string" << endl;
        }
        else if (choice == 'b'||choice == 'B'){
                         c = countC(word,s);
                         cout << " there are " << c << " of consonants in the string" << endl;
        }
        else if (choice == 'c'||choice == 'C'){
                         v = countV(word,s);
                         c = countC(word,s);
                         cout << " there are " << (c+v) << " of vowels and consonants in the string" << endl;
        }
        else if (choice == 'd'||choice == 'D'){     
                         cin.ignore(80,'\n');
                         cout << " Please enter a sentence of no more than "  << (SIZE - 1) << " characters" << endl;
                         cin.getline(word,SIZE);
                         s= strlen(word);
        }
        else {
            cout << "Invalid input, please retype your choice" << endl;
            cin >> choice;
        }
    }         
    }while(tolower(choice) != 'e');           
   cout << "end program" << endl;
    

}
int countV(char w[], int s)
{
    int count =0;   // count vowels
    for(int i = 0; i < s; i++){
        if(w[i]=='a'||w[i]=='e'||w[i]=='i'||w[i]=='o'||w[i]=='u'||w[i]=='A'||w[i]=='E'||w[i]=='I'||w[i]=='O'||w[i]=='U')
        count++;
    }
    return count;
}
int countC(char w[],int s)
{
    
    int count =0;   // count vowels
    int v =0;
    int i =0;
    int c;
    for(int i = 0; i < s; i++){
        if(w[i]=='a'||w[i]=='e'||w[i]=='i'||w[i]=='o'||w[i]=='u'||w[i]=='A'||w[i]=='E'||w[i]=='I'||w[i]=='O'||w[i]=='U')
        v++;
    }
    
    while(i<s){
        if(w[i] == ' ')
            count ++;
        i++;
    }
      c = s - v - count;
      return c;
    }
        

void pro3()
{
    // declare the variable
    char first[SIZE];
    char mid[SIZE];
    char last[SIZE];
    char name[SIZE];
    int f;
    int m;
    int l;
    
    cin.ignore(80,'\n');
    cout << " Please enter a sentence of no more than "  << (SIZE - 1) << " characters" << endl;
    cout << "Please enter your first name "; 
    cin.getline(first,SIZE);
    f = strlen(first);
    cout << endl;
    cout << "Please enter your middle name "; 
    cin.getline(mid,SIZE);
    m = strlen(mid);
    cout << endl;
    cout << "Please enter your last name "; 
    cin.getline(last,SIZE);
    l = strlen(last);
    cout << endl;
    
    strcat(name,last);
    strcat(name,", ");
    strcat(name, first);
    strcat(name, " ");
    strcat(name, mid);
    cout << "revised name array is " << name << endl; 
}
void pro4()
{
    // initialize the variable
    const int NUM = 20;
    Speaker *s = new Speaker[NUM];
    const int A =1,
                B= 2,
                C=3,
                D=4,
                E=5;
    int i;
    int choice;
    cin.ignore(80,'\n');
    // fill the structure
    for(i = 0;i <NUM; i++){
        cout << "your name : " ;
        cin.getline(s[i].name,SIZE);
        cout << endl;
        cout << "Telephone Number : ";
        cin >> s[i].phone;
        cin.ignore(80,'\n');
        cout << endl << "Speaking Topic : ";
        cin.getline(s[i].topic,SIZE);
        cout << endl << "Fee Required : ";
        cin >> s[i].fee;
        cout << endl;
    }
        do{
        // change the contents
        cout << " use the menu to change the contents"<< endl;
        cout << "1. change the name "<< endl;
        cout << "2. change Telephone Number "<< endl;
        cout << "3. change Speaking Topic "<< endl;
        cout << "4. change Fee "<< endl;
        cout << "5. quit the program" << endl;
        cin >> choice;
        
        if(choice < A || choice > E){
            cout << " Please enter a valid menu choice: ";
            cin >> choice;
        }
        if(choice != E){
            cout << " which one you want to change?"<< endl;
            cin >>i;
            i=i-1;
            switch(choice){
                case A :
                    cout << "your name : " ;
                    cin.ignore(80,'\n');
                    cin.getline(s[i].name,SIZE);
                    break;
                case B :
                    cout << "Telephone Number : ";
                    cin >> s[i].phone;
                    break;
                case C :
                    cout << endl << "Speaking Topic : ";
                    cin.ignore(80,'\n');
                    cin.getline(s[i].topic,SIZE);
                    break;
                case D :
                    cout << endl << "Fee Required : ";
                    cin >> s[i].fee;
                    break;
            }
                    
        }
        
    }while(choice !=E);
    for(i = 0;i <NUM; i++){
        cout << "your name : " << s[i].name << "   ";
        cout << "Telephone Number : " <<s[i].phone << "   ";
        cout << endl << "Speaking Topic : "<< s[i].topic << "  ";
        cout << endl << "Fee Required : "<< s[i].fee << endl;
    }
    delete[]s;
}
void pro5()
{
    const int MON = 12;
    Weather *w = new Weather [MON];
    int i;
    int totR =0;      // total rainfall
    float sum =0.0;       // total temperature
    float ave;            // average temperature
    float aveR;           // average rainfall
    int h;              // higest temoerature
    int l;              // lowest temperature
    int hMon;             // month at higest temperature 
    int lMon;             // month at loest temperature
    for(i =0; i<MON; i ++){
        cout << "Please enter  for month" << i+1 << endl;
        cout << " Total rainfall : ";
         w[i].rain = rand()%90+10;
         cout << w[i].rain;
        totR +=w[i].rain;
        aveR = totR / 12.0;
        cout << endl ;
        cout << " High Temperature : ";
        w[i].hTem = rand()%50+50;
        cout << w[i].hTem;
        cout << endl;
        cout << " Low Temperature : ";
        w[i].lTem = rand()%40+10;
        cout << w[i].lTem;
        w[i].ave = (w[i].hTem + w[i].lTem)/2.0;
        sum += w[i].ave;    
    }
    ave = sum/12.0;
    h = w[0].hTem;
    hMon=0;
    lMon =0;
    l = w[0].lTem;
    for(i=0;i<MON;i++){
        if(h<w[i].hTem){
                        h=w[i].hTem;
                        hMon=i;
                        }
        if(l>w[i].lTem){
                        l=w[i].lTem;
                        lMon =i;
                        }
    }
    
    for(i=0;i<MON; i++){
        cout << " Average Rainfall : " << aveR <<endl;
        cout << " Total RainFall : " << totR<<endl;
        cout << " highest temperatrue : " << h<< "at Month " <<hMon <<endl;
        cout << " Lowest Temperature : "<< l <<"at Month "<<lMon << endl;
        cout << " The average of all avrage temperature : " << ave << endl;
    }
    delete []w;
}
void pro6() 
{
     // initialized variable 
     const int PLAY= 2;
     Soccer *s =new Soccer [PLAY];
     int i;
     int tot=0;
     int max;
     int mP;
     cin.ignore(80,'\n');
     cout << "Please input all the information for each player : " <<endl;
     for (i =0; i<PLAY; i++){
         cout << " for player " << i +1 << endl;
         cout << " name : " ;
         cin.getline(s[i].name,SIZE);
         cout << endl;
         cout << " players number : ";
         cin >> s[i].num;
         cout << " points scored by player : ";
         cin >> s[i].points;
         tot+=s[i].points;
     }
     max = s[0].points;
     mP=0;
     for(i=0; i<PLAY; i++)
     {
              if(max < s[i].points){
                     max = s[i].points;
                     mP=i;
                     }
              }
     cout << " The total score : " << tot;
     cout << " Player " << s[mP].name << " earns the most points : " << max;
     delete []s;
     
}
void pro7()
{
     //initialize the vraiable
     fstream indata;          // input file
     fstream outdata;         // output file 
     string nameIn;
     string nameOut;
     char input[SIZE];        // transfer the input to output
     int length;              // count the length of the input
     cout <<" Please input a filename for input file : " ;
     cin.ignore(80,'\n');
     getline(cin,nameIn);
     cout <<" Please input a filename for output file : " ;
     cin.ignore(80,'\n');
     getline(cin,nameOut);
     cout<< "opening the file" << endl;
     // open file 
     indata.open(nameIn.c_str());
     outdata.open(nameOut.c_str());
      // read the input file
      if(indata){
                 if(outdata){
      while(indata){
                 for(int i =0;i <SIZE; i++){
                         indata >> input[i];
                         cout << input[i] ;
                 }
                 cout << endl;
                 length = strlen(input);
                 for(int i =0; i <length;i ++){
                         if(input[i] =='.' && input[i+1] == ' '){
                                  outdata << toupper(input[i+2]);
                                  }
                         else outdata << tolower(input[i]);
                         }
                 }
                 }
                 }
     
     indata.close();
     outdata.close();
     
     
}
void pro8()
{
     // name of the file
     char name[] = "file.dat";
     const int NUM =100;
     int arr[NUM];
     int i;
     // fill the array
     for (i =0;i <NUM;i++){
         arr[i]= rand()%90 +10;
     }
     
      arrayToFile(name,arr,NUM);    // conver array to file
      fileToArray(name,arr,NUM);    // read the file
      for(i=0;i < NUM;i++){
                cout << arr[i] << " " ;
                if(i%10==9) cout << endl;
                }
}
void arrayToFile(char name[], int *a, int n)
{
     fstream out;
     out.open(name,ios::out|ios::binary);
     // write the file
     out.write(reinterpret_cast<char *>(a),sizeof(a)*n);
     // close the file
     out.close();
     }    
void fileToArray(char name[], int *a, int n)
{
     // open the file
     fstream in;
     in.open(name,ios::in|ios::binary);
     // read the file
     in.read(reinterpret_cast<char *>(a),sizeof(a)*n); 
     in.close();
}


void pro9()
{
     // initialize the variable
     const int NUM =4;
     User *u = new User [NUM];
     int div,      // division counter
         q;        // quarter counter
     // fill in the information
     cin.ignore(80,'\n');
    cout << " for Division Name please type in East, West, North, and South" << endl;
     for(div =0;div< NUM;div++){
             cout << " Division Name  : " ;
             cin.getline(u[div].name,SIZE);
             for(q=0;q<NUM;q++){
             cout << " Quarter " << q+1 << "     : " << endl;
             cout << " Quarterly Sales : " ;
             u[div].sale[q]= rand()%90 +10; 
             cout << u[div].sale[q] << endl;
             }
             cout << endl;
     }
     // put information to the file
     // open the file
     char fn[] = "sales.txt";
     fstream out;
     out.open(fn,ios::out);
     // write to the file
     out.write(reinterpret_cast<char *>(u),sizeof(User)*NUM);
     // close the file
     out.close();
     
     // close the dynamic array
     delete []u;
}
void pro10()
{
     // initialize the variable
     const int NUM =4;
     User *u = new User [NUM];
     char fn[] = "sales.txt";
      int div,      // division counter
         q;        // quarter counte
      float tQuar[NUM] ; // total sale for each quarter
      float tYear[NUM]; // total yearly sale for each division
      float total=0; // total yearly corporate sale
      float ave;   // average quarterly sales for divison
      float h;       // highest sale
      int hQ;      // highest quarter
      float l;       // lowest sale   
      int lQ;      // lowest quarter
     fstream in;
     in.open(fn,ios::in);
     in.read(reinterpret_cast<char *>(u),sizeof(User)*NUM);
     for(q=0;q<NUM;q++){
             for(div=0;div<NUM;div++){
                       tQuar[q]+= u[div].sale[q];                         
             }                              
              cout << " total sale for quarter" << q+1 << " : "<< tQuar[q] << endl;         
     }
       for(div =0; div< NUM;div++){
               
               for(q=0;q<NUM;q++){
                             tYear[div]+= u[div].sale[q];  
                                  }
                                  total+=tYear[div];
               cout << " Total yearly sale for Division " << u[div].name << " : " << tYear[div] << endl;
               }
               cout << " Total yearly corporate sale : " << total << endl;
               h=tQuar[0];
               l =tQuar[0];
               for(q=0;q< NUM;q++){
                          if(h <tQuar[q]){
                               hQ =q;
                               }     
                          if(l>tQuar[q]){
                               lQ =q;          
                                         }      
               }
               cout << " Higest Quarter : " << hQ << endl;
               cout << " Lowest Quarter : " << lQ << endl;
               // close file
               in.close();
               // delete dynamic
               delete []u;
}

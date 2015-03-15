/*  Program : assignment 1
    Programmer: Zhiyan Cui                       

*/


#include <iomanip>      // formating 
#include <iostream>    // input and output 
#include <string>      // for enter stings
#include <fstream>     // for infile and outfile


using namespace std;

// function prototype 
void pro1();        // homework 3.12
void pro2();        // homework 3.13
void pro3();        // homework 4.10      
void pro4();        // homework 5.11
void pro5();        // homework 6.7
void pro6();        // homework 7.6
void pro7();        // homework 8.7

float celsius(int); // prototype for 6.7

int main()
{
    
    // initialize the variables
    int choice;
    // for the menu system
    
    cout << " 1. problem 3.12" << endl;
    cout << " 2. problem 3.13" << endl;
    cout << " 3. problem 4.10" << endl;
    cout << " 4. problem 5.11" << endl;
    cout << " 5. problem 6.7" << endl;
    cout << " 6. problem 7.6" << endl;
    cout << " 7. problem 8.7" << endl;
    cout << " Please type in the number that you wish to check" << endl;
    cin >> choice;
    
    
    
    
    if (choice == 1)
    {
               // call function for solve the homework
               // homework 3.12
                  pro1();
    }    
    else if ( choice == 2)
    {    // for the problem 3.13 
            pro2();
    } 
    else if (choice == 3)
    {    // for the problem 4.10
            pro3();
    }
    else if (choice == 4)
    {    // for the problem 5.11
            pro4();
    }
    else if (choice == 5)
    {    // for the problem 6.7
            pro5();
    }
    else if (choice == 6)
    {    // for the problem 7.6
            pro6();
    }
    else if (choice == 7)
    {    // for the problem 8.7
         string nm;
         cout << " Please type in a name, last name, first name" << endl;
      cout << " Holland, Beth" << endl;
      getline(cin, nm);
      cout << endl;
            pro7();
    }
    else 
    {
         cout << " Invalid choice, please type in the number " << endl;
         
         }
    
    
    system("PAUSE");
    return EXIT_SUCCESS;
}


// function pro1 to solve the 3.12
void pro1()
{
     // variable
    string month;
    short year;
    float total;
    float sale;
    float cTax;
    float sTax;
    float tTax;
    
    // constants
    const float ST = 0.04;
    const float CT = 0.02;
   
    
    // Ask for month, year, and total income
    cout << " Please type the month that you want to file  " ;   // ask for the month for the file
    cin >> month;
    cout << endl;
    cout << " What year is it?  ";                               // ask for the year
    cin >> year;
    cout << endl;
    cout << " what is the total income?  " ;                     // ask for income
    cin >> total;
    cout << endl << endl;
    
    // calculate the sales, and different type taxes;
    sale = total / 1.06;
    cTax = sale * CT;
    sTax = sale * ST;
    tTax = cTax + sTax;
    
    // set two decimo points
    cout << setprecision(2) << fixed;
    
    cout << " Month: "  << month << endl;
    cout << " -------------------"<< endl;
    cout << " Total Collected:       $" 
         << setw(10) << total << endl;
    cout << " Sales:                 $" 
         << setw(10) << sale << endl;
    cout << " County Sales Tax:      $" 
         << setw(10) << cTax << endl;
    cout << " State Sales Tax:       $" 
         << setw(10) << sTax << endl;    
    cout << " Total Sales Tax:       $" 
         << setw(10) << tTax << endl;
     
 }

// function for pro2 to solve for 3.13
void pro2()
{
     // initialize the varibles
     int val;     // the actual value for the piece of property
     float asse;  // the assessment value of the property
     float tax;   // the tax for the property
     
     // constant 
     const float AS = 0.6;   // assessment value is 60% of the property
     const float TX = 0.0064;  // tax for the property
     
     cout << " Please type in the actual value fro the piece of property" << endl;
     cin >> val;
     // calculate for assessment value and tax
     asse = 0.6 * val;
     tax = TX * asse; 
     
     // print out the results
     cout << " for your property, " << endl;
     cout << " the assessment : $" << setw (8) << asse << endl;
     cout << " the tax :        $" << setw (8) << tax << endl;
      
     }
// function for pro3 to solve for 4.10
void pro3()
{
     // initialize the variables
     int unit;    // for the unit that customer purchase
     float cost;  // the total cost for all the purchase
     
     // constants
     const int PRI = 99;       // a unit cost $ 99
     
     cout << " how many unit do you want to purchase? "<< endl;
     cin >> unit;
     if (unit <=0){
              cout << " sorry, invalid input, please type a number is greater than zero" << endl;
              cin >> unit;
     }
     else if (unit > 100)                  
          {cost = PRI * unit * 0.5;}      // discount for unit more than 100
     else if (unit >= 50)
          {cost = PRI * unit * 0.6;}      // discount for unit 50-100
     else if (unit >=20)
          {cost = PRI * unit * 0.7;}      // discount for unit 20-50
     else if (unit >=10)      
          {cost = PRI * unit * 0.8;}      // discount for unit from 10 -19
     else 
          {cost = PRI * unit;}            // discount for unit under 10
     
     // print out the resuls
     cout << " you purchase " << unit << " packages" << endl;
     cout << " Your total cost is $ " << cost << endl;
          
     }
void pro4()
{
     // initialize the variables
     float st;      // starting number of the organism
     float per;  //  average daily population increase
     int day;    // number of days that they will multiply
     
     cout << " please input the starting number of the organism" << endl;
     cin >> st; 
     while( st < 2)
     { 
            cout << " Please type a number is greater than 1" << endl;
            cin >> st;
     }
     cout << " Please input the percentage of the increase" << endl;
     cout << " Please type into decimo points eg: 0.6" << endl;
     cin >> per;
     while(per < 0)      
     {         
               cout << " Please type a number is greater than 0 " << endl;
               cin >> per;
     }
     
     cout << " Please type in the day that you would multiply" << endl;
     cin >> day;
     while(day < 1)
     {
               cout << " Please type in a number is greater than 1" << endl;
               cin >> day;
     }
     for(int i = 1; i <= day; i++)
     {
             cout << setprecision(2) << fixed;
             st = st*(1+per);
             cout << " at day " << i << " the population is " << st << endl;
     }
}
void pro5()
{
     // initialize all the variables
     float c;   // celsius
     int f;   // Fahrenheit
     f = 0;   // assign fahrenheit to 0 
     cout << " Farenheit " << setw(8) << "Celsius" << endl;
     cout << setprecision(2) << fixed;
     while(f <= 20)
     {
           c = celsius(f);
           
           cout <<"  " << f << "        " << setw(8) << c << endl;  
           f++;
     }
}
float celsius(int f)
{
  return 5.0*(f - 32.0)/9.0 ;     
}

void pro6()
{
     // initialize the variables
     string fname;      // filename
     int i = 0;         // counter
     int arr[10];       // array for size of 10
     int h;             // highest array
     int l;             // lowest number in the array
     int s;             // sum of all numbers
     float ave;         // average of all numbers
     ifstream inFile;   // set file for reading;
     ofstream outFile;  // set file for wrighting; 
     cout << setprecision(2) << fixed;
     cout << " Please type in a file name" << endl;   // get the file name from the user
     cin >> fname;
     
     outFile.open(fname.c_str());   // open the file use the user's file name;
     while(i <= 10)
     {
             outFile << rand() << endl;
             i++;
     }
     outFile.close();
     // now read the data from the file;
     inFile.open(fname.c_str());
     for( int i = 0; i < 10 ; i++)
     {
          inFile >> arr[i];
          cout << arr[i] << endl;
     } 
     inFile.close();
     // find the lowest number in the array
     l = arr[0];
     for( i = 1; i < 10; i++)
     {
          if(arr[i]< l)
          {
                     l= arr[i];
          }
     }
     cout << " The lowest number is " << l << endl;
     // find the highest number in the array
      h = arr[0];
     for( i = 1; i < 10; i++)
     {
          if(arr[i]> h)
          {
                     h= arr[i];
          }
     }
     cout << " The highest number is " << h << endl;
     // find the sum of the numbers
     for(i=0; i < 10; i++)
     {
              s+= arr[i];
     }
     cout << " The sum of all number is " << s << endl;
     ave = s / 10.0;
     cout << " The average of the array is " << ave << endl;
}

void pro7()
{
    // initialize all the variable
     const int NUM = 20;
     int i;                 // counter
     int min;            // hold the location of smallest value
     string val;            // smallest value
     string nm;            // ueser's name
     int find;
     int first;             
     int last ;
     int middle;
     string names[NUM] = { "Collins, Bill","Smith, Bart", "Allen, Jim",
                           "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                           "Taylor, Terri", "Johnson, Jill",
                           "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
                           "James, Jean", "Weaver, Jim", "Pore, Bob",
                           "Rutherford, Greg", "Javens, Renee",
                           "Harrison, Rose", "Setzer, Cathy",
                           "Pike, Gordon", "Holland, Beth"} ;
                           
      
                           
     // sort the array in alphabetical order 
      for(i = 0; i < (NUM -1); i ++)
      {
            min = i;
            val = names[i];
            for(int count = i+1 ; count < NUM; count++)
            {
                    if (names[count] < val )
                    {
                             val = names[count];
                             min = count;
                    }
            }
            names[min]= names[i];
            names[i]= val;
      }
      for( i=0; i < NUM; i++)
      {
           cout << names[i] << endl;
      }
      cout << endl << endl;
      
      cout << " Please type in a name, last name, first name" << endl;
      cout << " Holland, Beth" << endl;
      getline(cin, nm);
      
      cout << endl;
     first = 0;
     last = NUM -1;
     find = -1;
     while(first <= last)
     {
                 middle = first +(last - first)/2; 
                 cout <<  names[middle] << endl;
                 if (names[middle] == nm)
                    {
                                   find = middle;
                    cout << " The number " << middle<< endl;
                                  first = last +1;
                    }
                 else if(names[middle] > nm)
                      {
                                       last = middle -1;
                                       cout << " the last " << last << endl;}
                 else
                     {
                                       first = middle +1;
                                       cout << " the first" << first << endl;
                                       }
     }
     if(find != -1)
     {
             
             cout << " The name" << nm << " is in position " << middle+1 << " of the list" << endl;
             \
             }
     else
         cout << " sorry, we did not find the name" << endl;
     }
     

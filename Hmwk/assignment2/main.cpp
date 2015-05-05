
#include <cstdlib>

#include <iostream>
#include <iomanip>      // formating
#include <string>

using namespace std;


// function prototype 
float mean(int[], int);          // homework calculate mean
float medium(int[], int);        // homework calculate medium
int *mode(int[], int);                   // homework calculate mode   
void pro4();                             // problem 9.2
void sort(float *, int);
void ave(float *, int);
void pro5();                             // problem 9.6
void arrSelc(int*[], int);
void showAry(const int[], int);
void shwAryP(int * [], int);
void pro6();                             // problem 9.7
void arrD(int*[], int);
void pro7();                             // problem 9.5
int doSmth(int *, int *);
void pro8();                             // problem 9.4
void sort(float *, string *, int);   

int main(int argc, char *argv[])
{
    
    // initialize the variables
    int choice;
    // for the menu system
    
    cout << " 1. mean " << endl;
    cout << " 2. medium " << endl;
    cout << " 3. mode " << endl;
    cout << " 4. problem 9.2" << endl;
    cout << " 5. problem 9.7" << endl;
    cout << " 6. problem 9.6" << endl;
    cout << " 7. problem 9.5" << endl;
    cout << " 8. problem 9.4" << endl;
    cout << " Please type in the number that you wish to check" << endl;
    cin >> choice;
    cout << endl << endl;
    
    // initialize the array to calulate the mean, medium, and mode;
    const int SIZE = 10;
    int arr[SIZE] ;
    for(int i = 0; i < SIZE; i++)
    {
            cin >> arr[i];
    }
    for(int i = 0; i < SIZE; i++){
          cout << arr[i];
          }
    
    // sort the array
     // initialize the variables
     int seek;     // array position current is put in order
     int min;      // location of the smallest value
     int mVal;     // the smallest value
     for (seek = 0 ; seek < (SIZE -1); seek ++)
     {
         min = seek;
         mVal = arr[seek];   // set the first array to minmum value
         for (int i = seek +1; i < SIZE; i++)
         {
             if (arr[i] < mVal)
                {
                        mVal = arr[i];
                        min = i;
                }   
         }
        arr[min] = arr[seek];
        arr[seek] = mVal;
     }
    
    
     if (choice == 1)
     {
               // initialize the varible
                  float m;      // the mean of the array
                  m = mean(arr, SIZE);
                  cout << " The mean of the array is " << m << endl;
    }    
    else if ( choice == 2)
    {    // for medium
         // initalize the varible
         float med;     // the medium number of the array
            med = medium(arr,SIZE);
            cout << " The meadium number of the array is " << med << endl;
    } 
    else if (choice == 3)
    {    // for the problem 4.10
            *mode(arr,SIZE);
            
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
            pro7();
    }
    else if (choice == 8)
    {
         
         pro8();
         }
    else 
    {
         cout << " Invalid choice, please type in the number " << endl;
         
         }
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

float mean(int arr[], int SIZE)
{
  // set two decimo points
    cout << setprecision(2) << fixed;
    
  // calculate the mean
     int s;    // calulate the sum of the array
     float m;  // calculate the mean of the array
     for ( int i = 0; i < SIZE; i++)
     {
         s += arr[i];
         cout << s << endl;
     }
     cout << " The total of the array is " << s  << endl;
     m = s/SIZE;
     return m;     
}
float medium(int arr[], int SIZE)
{
    // calculate the medium
     float med;       // the medium 
     int middle;    // the element 5;
     int mid;       // the element 4
     middle = SIZE/2;
     mid = middle -1;
     med = (arr[middle] + arr[mid])/2;
     return med;
}
int *mode(int arr[], int SIZE)
{
     // initialize the variables
     int seek;
     int s;
     int i;
     int same;            // count how many same numbers;
     int count = 0;
     int num =0;                
     int max[SIZE-1];        // set the max difference as a array;
     int *modes ;            // set the dynamic allocate array
     int f;                 // set the max frequence;  
    
    for(i = 0 ; i < SIZE; i++)
    {
          cout << arr[i] << "  " ;
          }
          
          cout << endl << endl;
      // set the number of difference as a array        
      for (int s = 0; s < SIZE-1 ; s ++)
      { 
               if (arr[s] == arr[s+1])
               {
                   count ++;  
                   seek = count;  
                   cout << " same " << seek << endl; ;      
               }
               else 
               {
                    count = 0; // set the differce number of the difference = 0
                    seek = count;
                    cout << " difference " << seek << endl; 
                    
               } 
          max[s]= seek; 
          cout << "the number of difference" << max[s] << endl;
    } 
    
    for ( i = 0; i < (SIZE -1); i++)
    {
        cout << max[i] << " " ;
        }
        
        cout << endl;
        
        
      f = max[0]; 
      cout <<"compare the number of difference" << f << endl << endl;
      count = 0; 
    for (int i = 1; i < (SIZE -1) ; i ++)
    {
        if ( max[i] >= f)
             f = max[i];
             cout << "try to find the maximum difference "  << f << endl;
    }
      cout << " max frequency is " << f << endl;
      for (int i = 0; i < (SIZE -1); i ++)
      {
          if ( max[i] == f){
               count ++; 
               
               }   
      }
      
      cout << " dynamic allocate the array" << endl;
      // dynamic allocate the array
      modes = new int (count+2);

      modes[0] = count;  
      cout << modes[0] << endl; 
      modes[1] = f+1;
      cout << modes[1] << endl;
      i = 2;
      do
      {
             for (int s =0 ; s < SIZE; s ++)
             {
                 if( max[s] == f)
                 {
                     num = arr[s];
                     modes[i] = num ; 
                     i ++;       
                     } 
             } 
                  
      }while(i < (count +2));
      
      for(i = 0; i < (count + 2); i ++)
      {
            cout << modes[i] << "    " ;
            }
      return modes;
        
}
void pro4()
{
     float *score;     // dynamic allocated array
     int num;          // the number of the test score;
     
     // set the size of the array
     cout << "  Please type in the number of the test score " << endl;
     cin >> num;
     // set the dynamic allocated array
     score = new float[num];
     // get the each test score
     for (int i = 0; i < num; i ++)
     {
         cout << " test score " << i+1  << " ";
         cin >> score[i];
         cout << endl;    
         if (score[i] < 0)
         {
            cout << " sorry, invalid numbers, please type in a positive number" << endl;
            cin >> score[i];
            cout << endl;             
         }
     }
     // call function to sort the array
     sort(score, num);
     // cal function to calculate the average score
     ave(score, num);
     
     
     // free the  memory
     delete[] score;
     

}
void sort(float *score, int num)
{
     // initialize the varibles
     float mVal;      // set the smallest scores
     int min;         // the position that smallest scores holds
     int i ;
     cout << " Test Score " << endl;
     for(i = 0; i < (num-1) ; i ++)     
     {
             min = i;
             mVal = score[i];
             for(int count = i +1; count < num; count++)
             {
                     if( score[count] < mVal)
                     {
                             mVal = score[count];
                             min = count;                        
                     }        
             }
             score[min] = score[i];
             score[i] = mVal;
     }
     for(i = 0; i < num; i ++)
     {
           cout << " test score " << i+1 << " :   " << score[i] << endl;       
     }
}
void ave(float *score, int num)
{
     // inialize the variables
     float sum = 0;
     float ave;
     cout << setprecision(2) << fixed;
     // calculate the sum
     for(int i = 0; i < num; i++)     
     {
             sum += score[i];        
     }
     cout << " the sum is " << sum << endl;
     ave = sum / num;
     cout << " The average of the test score is " << ave << endl;
     
}
void pro5()   // problem 9.6
{
     // initializes the variable
     int num;      // number of people to donate 
     int *donation; // dynamic allocated array
     
     cout << " Please type in the number of people who donate" ;
     cin >> num;
     cout << endl;
     
     // dynamic allocated the array
     donation = new int[num];
     
     for(int i = 0; i < num; i++)
     {
             cout << " donation for person " << i + 1 << " is " ;
             cin >> donation[i];        
     }
     // an array of pointers to int
     int* arr[num];
     for(int count = 0; count < num; count++)
     {
             arr[count] = &donation[count];
     }

     // sort the element of the array of pointers
     arrSelc(arr, num);
     // display the donations using the array of pointers
     cout << " The donations , sorted in descending order are : " << endl;
     shwAryP(arr, num);
     // display the donations in their orginal order
     cout << " The donations, in their orginal order are : " << endl;
     showAry(donation, num);
     
     // free the memory
     delete []donation;
}
void arrSelc(int*arr[], int size)
{
    int s,             // initial count
        min;           // 
    int * minE;
    for(s = 0; s < (size -1); s++)
    {
        min = s;
        minE = arr[s];
        for( int i = s+1; i< size; i ++)
        {
            if(*(arr[i])< * minE)
            {
                minE = arr[i];
                min = i;
            }
        }
        arr[min] = arr[s];
        arr[s] = minE;
    }
}
void showAry(const int arr[], int size)
{
    for(int count = 0; count < size; count++)
        cout << arr[count] << "  ";
    cout << endl;
}
void shwAryP(int * arr[], int size)
{
    for(int i = 0; i < size; i ++)
        cout << *(arr[i]) << " ";
    cout << endl;
}

void pro6()
{
    // initializes the variable
     int num;      // number of people to donate 
     int *donation; // dynamic allocated array
     
     cout << " Please type in the number of people who donate" ;
     cin >> num;
     cout << endl;
     
     // dynamic allocated the array
     donation = new int[num];
     
     for(int i = 0; i < num; i++)
     {
             cout << " donation for person " << i + 1 << " is " ;
             cin >> donation[i];        
     }
     // an array of pointers to int
     int* arr[num];
     for(int count = 0; count < num; count++)
     {
             arr[count] = &donation[count];
     }

     // sort the element of the array of pointers
     arrD(arr, num);
     // display the donations using the array of pointers
     cout << " The donations , sorted in ascending order are : " << endl;
     shwAryP(arr, num);
     // display the donations in their orginal order
     cout << " The donations, in their orginal order are : " << endl;
     showAry(donation, num);
     
     // free the memory
     delete []donation;


}
void arrD(int*arr[], int size)
{
    int s,             // initial count
        max;           // 
    int * maxE;
    for(s = 0; s < (size -1); s++)
    {
        max = s;
        maxE = arr[s];
        for( int i = s+1; i< size; i ++)
        {
            if(*(arr[i])> * maxE)
            {
                maxE = arr[i];
                max = i;
            }
        }
        arr[max] = arr[s];
        arr[s] = maxE;
    }
}
void pro7()   // problem 9.5
{
    // declare and initialize the varibles
    const int SIZE = 10;             // declare the size of the pointers
    int *x;
    int *y;
    int num1, num2;
    int sum;
    
    num1 = rand();
    num2 = rand();  
            x= &num1;
            y= &num2;
           cout << " x = " << *x << endl;
           cout << " y = " << *y << endl; 
    // call function to calculate the sum of the 10x + 10y
    sum = doSmth(x, y);
    cout << " The sum of the 10x +10y is " <<sum << endl;

}
int doSmth(int *x, int *y)
{
    int sum ;

        int temp = *x;
            *x = *y * 10;
            *y = temp * 10;
            sum =*x + *y;
    return sum;
}
void pro8()
{
     float *score;     // dynamic allocated array
     string *name;      // dynamic allocated array
     int num;          // the number of the test score;
     
     // set the size of the array
     cout << "  Please type in the number of the test score " << endl;
     cin >> num;
     // set the dynamic allocated array
     score = new float[num];
     name = new string [num];
     // get the each test score
     for (int i = 0; i < num; i ++)
     {
         cout << " test score " << i+1  << " ";
         cin >> score[i]; 
         if (score[i] < 0)
         {
            cout << " sorry, invalid numbers, please type in a positive number" << endl;
            cin >> score[i];
            cout << endl;             
         }
         cin.ignore(80,'\n');
         cout << " student name" << i+1 << " ";
         getline(cin, name[i]);
     }
     // call function to sort the array
     sort(score, name, num);
     // cal function to calculate the average score
     ave(score, num);
     
     
     // free the  memory
     delete[] score;
}
void sort(float *score, string *name, int num)
{
     // initialize the varibles
     float mVal;      // set the smallest scores
     int min;         // the position that smallest scores holds
     int i ;
     cout << " Test Score " << endl;
     for(i = 0; i < (num-1) ; i ++)     
     {
             min = i;
             mVal = score[i];
             for(int count = i +1; count < num; count++)
             {
                     if( score[count] < mVal)
                     {
                             mVal = score[count];
                             min = count;                        
                     }        
             }
             score[min] = score[i];
             score[i] = mVal;
     }
     
     cout << " Student Name   "  
          << setw(6) << "test score" << endl;
     for(i = 0; i < num; i ++)
     {
           cout <<name[i] << "  " 
                << setw(6) << score[i] << endl;  
     }
}

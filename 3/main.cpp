//
//  main.cpp
//  2
//
//  Created by Константин Кириленко on 20.03.2022.
//
#include <iostream>
#include "add.h"
#include <string>
using namespace std;

 void sort(string *a, int n){
     string temp;
    string lowkey;
    int lowindex;
    for (int i=0; i<n-1; i++){
        lowindex = i;
        lowkey = a[i];
    
        for (int j=i+1; j<n;j++)
            if (a[j].length()<lowkey.length() || (a[j].length()==lowkey.length() && a[j]<lowkey) ){
                lowkey=a[j];
                lowindex=j;
            }
            
            temp = a[i];
            a[i]=a[lowindex];
        a[lowindex]=temp;
        }
    
}

int main(int argc, const char * argv[]) {
    

    
    int n;
    cin>>n;
    string *m = create<string>(n);
    read(m,n);
    print(m, n);
    cout<<endl;
    sort(m, n );
    print(m, n);
  
}

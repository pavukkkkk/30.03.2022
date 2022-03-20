//
//  add.h
//  30.03.2022
//
//  Created by Константин Кириленко on 20.03.2022.
//

#ifndef add_h
#define add_h
#include <iostream>
using namespace std;


template <typename type> type* create(int n) {
    type* mass = new type[n];
    for (int i=0; i<n;i++){
    }
    return mass;
}

template <typename type>
void read(type* mass, int n) {
    for (int i = 0; i < n; i++)
        cin >> mass[i];
}
void deleted(int* mass, int n) {
    delete[] mass;
    mass = nullptr;
}

template <typename type>
void print(type* mass, int n) {
    for (int i = 0; i < n; i++)
            cout << mass[i] << '\t';
    cout<<endl;
}

template <typename type> void del(type* mass, int &n, int k){
    
    for (int i = k; i < n - 1; i++) {
                   mass[i]=mass[i + 1];
               }
               n --;
           
}

#endif /* add_h */

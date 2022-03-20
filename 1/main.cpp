#include "add.h"
#include <iostream>

template <typename type>
type min(type* mass, int &n) {
    type m = mass[0];
        int index = 0;
        for (int i = 0; i < n; i++) {
            if (mass[i]<m){
                m=mass[i];
                index=i;
            }
}
    del(mass,n,index);
    return m;
}

template <typename type>
void sort(type* mass, int &n) {
    int k=n;
    for (int i = 0; i < k; i++) {
        cout<<min(mass, n)<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    int *m = create<int>(n);
    read(m,n);
  
    sort<int> (m,n);
   
    
}

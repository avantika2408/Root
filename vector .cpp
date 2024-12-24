#include<iostream>
#include<TVector3.h>
using namespace std;

void vectors(){
    TVector3 v1(2,3,4);
    
    cout << v1.Z() << endl;
    cout << v1(1) << endl;

   // v1.Print(); // in degree
    double rho = v1.Mag();
    double theta = v1.Theta(); //radians
    double phi = v1.Phi(); //radians

    cout << rho <<" " << theta << " " << phi << " " << endl;
}



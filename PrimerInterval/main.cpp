//
//  main.cpp
//  PrimerInterval
//
//  Created by Miguel Cuellar on 1/21/16.
//  Copyright © 2016 Miguel Cuellar. All rights reserved.
//

#include <iostream>
#include "math.h"
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

bool myfunction (int i,int j) {
    return (i<j);
}
int main() {
    vector<int> myVector;
    vector<bool> encontrado;
    int M,dato,izq,der;
    cin>>M;
    myVector.push_back(0);
    myVector.push_back(1);
    myVector.push_back(2);
    myVector.push_back(3);
    myVector.push_back(4);
    myVector.push_back(5);
    encontrado.push_back(false);//0
    encontrado.push_back(false);//1
    encontrado.push_back(true);//2
    encontrado.push_back(true);//3
    encontrado.push_back(false);//4
    encontrado.push_back(true);//5
    for (int i=5; i<=100000;i++){
        encontrado.push_back(false);
        myVector.push_back(i);
    }
    
    for (int ix=1;ix<=320;ix++)
    {
        for (int iy=1;iy<=320;iy++)
        {
            int dato = (4*ix^2+iy^2);
            if (dato <= 100000 && (dato % 12 == 1 || dato % 12 == 5))
            {
                encontrado[dato] = true;
            }
            dato = (3*ix^2+iy^2);
            if (dato<=100000&&(dato%12==7))
            {
                encontrado[dato] = true;

            }
            
            if (ix>iy)
            {
                dato = (3*ix^2-iy^2);
                if (dato <= 100000 && (dato % 12 == 11))
                {
                    encontrado[dato] = true;

                }
            }
        }
    }
    for (int i=1; i<=320;i++)
    {
        if (encontrado[i])
        {
            for (int j=i^2; j<=100000; j+=i)
            {
                encontrado[j] = false;
            }
        }
    }
    encontrado[7]=true;
    for (int i=0; i<M;i++) {
        cin>>dato;
        izq=dato;
        der=dato;
        if (encontrado[dato-2]==true) {
            cout<<dato<<" "<<dato<<endl;
        }
        else{
            while (encontrado[izq]!=true) {
                izq--;
            }
            while (encontrado[der]!=true) {
                der++;
            }
     cout<<myVector[izq+2]<<" "<<myVector[der-2]<<endl;
            cout<<myVector[4];
        }
        
    }

    return 0;
}

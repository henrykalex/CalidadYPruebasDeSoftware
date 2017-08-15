//
//  Pila.h
//  AsercionesBasicas
//
//  Created by Enrique Mondragon on 15/08/17.
//  Copyright © 2017 ealex_mondrat. All rights reserved.
//

//#ifndef Pila_h
//#define Pila_h

#include <stack>
using namespace std;

template <class T>
class myStack{
public:
    void push(T value){
        st.push(value);
    }
    void pop(){
        st.pop();
    }
    unsigned int size(){
        return st.size();
    }
protected:
    stack<T> st;
};

//#endif /* Pila_h */

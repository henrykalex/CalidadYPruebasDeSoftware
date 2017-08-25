//
//  main.cpp
//  Evaluacion1
//
//  Created by Enrique Mondragon on 25/08/17.
//  Copyright © 2017 ealex_mondrat. All rights reserved.
//

#include <iostream>
#include "Scanner.h"

int main(int argc, const char * argv[]) {
    Scanner * temp = new Scanner();
    std::vector<unsigned int> resultPorts = temp->getListeningPorts();
    // insert code here...
    std::cout << "Hello, World!\n" << Scanner::countNew;
    return 0;
}

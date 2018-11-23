//
// Created by Kamil Owczarz on 11/11/2018.
// Copyright (c) 2018 Kamil Owczarz. All rights reserved.
//

#pragma once


#include <string>
#include <stack>
#include <vector>
#include <map>
#include <iostream>
#include <memory>
#include "Package.h"
#include "Exeptions.h"

class Warehouse {
public:
    Warehouse(unsigned long n, unsigned long m);
    void acceptPackage(const std::string& package);        //pass by reference to const var, to save memory
    PACKAGE_TYPE issuePackage(const std::string& package);

private:
    unsigned long findLeastFilled();
    unsigned long removePackageFromMap(const std::string& package);
    const unsigned long shelvesNo;
    const unsigned long shelvesHeight;
    std::vector<std::stack<PACKAGE_TYPE>> shelves;
    std::map<std::string, unsigned long > nameMap;

};




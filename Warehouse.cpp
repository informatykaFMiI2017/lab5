//
// Created by Kamil Owczarz on 11/11/2018.
// Copyright (c) 2018 Kamil Owczarz. All rights reserved.
//


#include "Warehouse.h"

Warehouse::Warehouse(unsigned long n, unsigned long m) : shelvesNo(n), shelvesHeight(m) {
    for (int i = 0; i < shelvesNo; ++i)
        shelves.push_back(std::stack<PACKAGE_TYPE>());
}

void Warehouse::acceptPackage(const std::string& package) {
    unsigned long leastFilledPos = 0;

    try {
        leastFilledPos = findLeastFilled();
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        return;
    }
    auto result = nameMap.insert(std::pair<std::string, unsigned long>(package, leastFilledPos));

    if (!result.second) {
        std::cout << "name already used!" << std::endl;
        return;
    }

    std::cout << "ppodaj dane adresata\n";
    std::string recipient;
    std::getline(std::cin, recipient);
    auto tmpPack = std::make_shared<Package>(package, recipient);

    shelves[leastFilledPos].push(tmpPack);
}

PACKAGE_TYPE Warehouse::issuePackage(const std::string& package) {
    const unsigned long shelfIndex = removePackageFromMap(package);

    auto returnValue = shelves[shelfIndex].top();
    shelves[shelfIndex].pop();

    return returnValue;
}

unsigned long Warehouse::findLeastFilled() {
    unsigned long leastFilled = shelves[0].size();
    unsigned long position = 0;
    unsigned long it = 0;

    for (const auto &stackPtr : shelves) {
        if (stackPtr.size() < leastFilled) {
            leastFilled = stackPtr.size();
            position = it;
        }
        ++it;
    }

    if (shelvesHeight == leastFilled)
        throw warehouseException("warehouse is full!");

    return position;
}

unsigned long Warehouse::removePackageFromMap(const std::string& package) {
    auto searchRes = nameMap.find(package);
    if (searchRes != nameMap.end()) {
        unsigned long retVal = searchRes->second;
        nameMap.erase(searchRes);
        return retVal;
    } else
        throw warehouseException("package not found!");
}

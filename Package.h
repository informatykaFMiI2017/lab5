//
// Created by Kamil Owczarz on 11/11/2018.
// Copyright (c) 2018 Kamil Owczarz. All rights reserved.
//

#pragma once

#include <string>

#define PACKAGE_TYPE std::shared_ptr<Package>
class Package {
public:
    Package(std::string pName, std::string pRecipient);
    std::string getName();
    std::string getRecipient();

private:
    const std::string packageName;
    const std::string packageRecipient;
};
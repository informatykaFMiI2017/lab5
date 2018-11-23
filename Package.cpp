#include <utility>

#include <utility>

//
// Created by Kamil Owczarz on 11/11/2018.
// Copyright (c) 2018 Kamil Owczarz. All rights reserved.
//

#include "Package.h"

Package::Package(std::string pName, std::string pRecipient) : packageName(std::move(pName))
    ,packageRecipient(std::move(pRecipient)) {}

std::string Package::getName() {
    return packageName;
}

std::string Package::getRecipient() {
    return packageRecipient;
}

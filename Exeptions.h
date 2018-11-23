#include <utility>

//
// Created by Kamil Owczarz on 11/11/2018.
// Copyright (c) 2018 Kamil Owczarz. All rights reserved.
//

#pragma once


#include <exception>
#include <string>

class warehouseException : public std::exception {
public:
    warehouseException() : message("No message"){};

    explicit warehouseException(std::string msg) : message(std::move(msg)){};
    const char* what() const throw() override;

private:
    std::string message;
};




//
// Created by Kamil Owczarz on 11/11/2018.
// Copyright (c) 2018 Kamil Owczarz. All rights reserved.
//

#include "Exeptions.h"

const char *warehouseException::what() const throw() { return message.c_str(); };

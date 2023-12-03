/*
 * EmptyDataCollectionException.cpp
 *
 * Class Description: Defines the exception that is thrown when data collection is empty.
 *
 * Author: Inspired from our textbook's authors Frank M. Carrano and Tim Henry.
 *         Copyright (c) 2013 __Pearson Education__. All rights reserved.
 */
 
#include "EmptyDataCollectionException.h"  

// Constructor
EmptyDataCollectionException::EmptyDataCollectionException(const string& message): 
logic_error("EmptyDataCollectionException: " + message) {}  

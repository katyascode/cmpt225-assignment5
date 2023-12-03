/*
 * UnableToInsertException.cpp
 *
 * Class Description: Defines the exception that is thrown when a newElement
 *                    cannot be inserted into the data collection ADT class.
 *
 * Author: Inspired from our textbook's authors Frank M. Carrano and Tim Henry.
 *         Copyright (c) 2013 __Pearson Education__. All rights reserved.
 */

#include "UnableToInsertException.h"  

// Constructor
UnableToInsertException::UnableToInsertException(const string& message): 
logic_error("newElement cannot be inserted into the data collection ADT class Exception: " + message) {}

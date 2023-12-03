/*
 * ElementAlreadyExistsException.cpp
 *
 * Class Description: Defines the exception that is thrown when 
 *                    we are attempting to insert an element
 *                    which is already in the data collection ADT class.
 *
 * Author: Inspired from our textbook's authors Frank M. Carrano and Tim Henry.
 *         Copyright (c) 2013 __Pearson Education__. All rights reserved.
 */
 
#include "ElementAlreadyExistsException.h"  

// Constructor
ElementAlreadyExistsException::ElementAlreadyExistsException(const string& message): 
logic_error("ElementAlreadyExistsException: " + message) {}

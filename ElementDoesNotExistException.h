/*
 * ElementDoesNotExistException.h
 *
 * Class Description: Defines the exception that is thrown when 
 *                    we are searching for an element
 *                    which is not in the data collection ADT class.
 *
 * Author: Inspired from our textbook's authors Frank M. Carrano and Tim Henry.
 *         Copyright (c) 2013 __Pearson Education__. All rights reserved.
 */
 
#ifndef ELEMENT_DOES_NOT_EXIST_EXCEPTION_H
#define ELEMENT_DOES_NOT_EXIST_EXCEPTION_H

#include <stdexcept>

using std::string;
using std::logic_error;

class ElementDoesNotExistException : public logic_error {

   public:
      // Constructor
      ElementDoesNotExistException(const string& message = "");
   
}; 
#endif

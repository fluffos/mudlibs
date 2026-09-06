#ifndef _ACCESS_H_
#define _ACCESS_H_

// Use this macro in an if() statement to decide if variable modification is allowed.
#define SET_OK this_object()->query_allow_set(previous_object())

// This function will generate an error if an illegal set is attempted.
// Pass in the name of the function (or any string you want in the debug
// message, but the name of the function is expected).
#define CHECK_SET(x) if( extern_call() && !"/secure/file_security"->query_allow_set(previous_object(), this_object()) ) raise_error("User ID '"+getuid(previous_object())+"' may not modify objects with ID '"+getuid(this_object())+"' in "+x+"\n")

#endif
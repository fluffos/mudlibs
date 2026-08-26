/* gettype.c
	Fantome @ TMI-2, 23 July 1993

	int gettype (mixed item);
		--- return a value indicating the type of item
			--- undefinedp (item)	== IS_UNDEFINED
			--- nullp (item)	== IS_NULL
			--- intp (item)		== IS_INT
			--- stringp (item)	== IS_STRING
			--- objectp (item)	== IS_OBJECT
			--- pointerp (item)	== IS_POINTER
			--- mapp (item)		== IS_MAPPING
			--- floatp (item)	== IS_FLOAT
			--- functionp (item)	== IS_FUNCTION

	string strtype (mixed item);
		--- return a string representation of the type of item

	int comptype (mixed item, mixed other);
		--- returns 1 if item and other are of the same type, else 0
*/

#include <gettype.h>

int gettype (mixed item) {
  if (undefinedp (item))	return IS_UNDEFINED;
  if (nullp (item))		return IS_NULL;
  if (intp (item))		return IS_INT;
  if (stringp (item))		return IS_STRING;
  if (objectp (item))		return IS_OBJECT;
  if (pointerp (item))		return IS_POINTER;
  if (mapp (item))		return IS_MAPPING;
  if (floatp (item))		return IS_FLOAT;
  if (functionp (item))		return IS_FUNCTION;
  return IS_UNKNOWN;
}

string strtype (mixed item) {
  switch (gettype (item)) {
    case IS_UNKNOWN:	return "unknown";
    case IS_UNDEFINED:	return "undefined";
    case IS_NULL:	return "null";
    case IS_INT:	return "int";
    case IS_STRING:	return "string";
    case IS_OBJECT:	return "object";
    case IS_POINTER:	return "array";
    case IS_MAPPING:	return "mapping";
    case IS_FLOAT:	return "float";
    case IS_FUNCTION:	return "function";
  }
  return "unknown";
}

int comptype (mixed item, mixed other) {
  if (gettype (item) == gettype (other))
    return 1;
  return 0;
}

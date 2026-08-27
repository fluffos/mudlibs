// The main difference between this and sprintf("%O", arg);
// is that strings are not quoted, things like arrays and mappings are
// not converted to a string format.
#include <type.h>

string
to_string(mixed arg)
{
  switch( typeof(arg) )
  {
  case STRING:
    return arg;
  case INT:
  case FLOAT:
    return arg + "";
  case ARRAY:
    return "(array)";
  case OBJECT:
    return file_name(arg);
  case MAPPING:
    return "(mapping)";
  case FUNCTION:
    return "(function)";
  case BUFFER:
    return "(buffer)";
  case CLASS:
    return "(class)";
  default:
    return "(unknown)";
  }
}

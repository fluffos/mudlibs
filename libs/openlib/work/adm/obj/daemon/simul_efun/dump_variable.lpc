// dump_variable, author: Huthar@Portals, TMI
// - returns a printable representation of any variable.
// Changed by Symmetry@IdeaExchange, Tmi-2 5/4/95
// - the format is retained
// Beek - changed to use foreach()
// 09/16/95  Tim McIntosh: fixed the sprintf statement so it'll do a mapping
//           containing arrays or other mappings.

#include <type.h>

string
dump_variable(mixed arg)
{
  string rtn;
  mixed x, y;
  
  switch(typeof(arg)){
  case OBJECT: return "("+file_name(arg)+")";
  case STRING: return "\""+arg+"\"";
  case INT: return "#"+arg;
  case ARRAY: 
    {
      rtn = "ARRAY\n";
      foreach (y in arg) 
	rtn += sprintf("[%d] == %s\n", x++, dump_variable(y));
      
      return rtn;
    }
    
  case MAPPING:
    {
      rtn = "MAPPING\n" +
	implode(values(map_mapping(arg,
				   (: sprintf("[%O] == %O", $1, $2) :))),
		"\n");
      return rtn;
    }
  
  case FUNCTION:
  case CLASS:
  case FLOAT:
  case BUFFER:
    {
      return sprintf("%O\n", arg);
    }
    
    return "UNKNOWN";
  }
}

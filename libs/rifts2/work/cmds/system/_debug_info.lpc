//

//	Author: Zortek@Rhovan 94.04.22

//	

//	Interface to the debug_info efun.

//

#include <std.h>



inherit DAEMON;



int cmd_debug_info(string rest)

{

  object tp,ob;

  

  tp = this_player();

  

  if(!rest)

    ob = tp;

  else

    ob = find_object(rest);

  

  debug_info(0,ob);

  debug_info(1,ob);

  

  return 1;

}



int help()

{

  write(@HELP

This command prints a set of statistics about the object in

question.  If there is no object argument specified it uses this_player().

HELP

);

  return 1;

}


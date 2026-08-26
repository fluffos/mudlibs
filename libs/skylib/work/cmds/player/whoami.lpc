/* whoami command, trial out by Turrican for a commands daemon. */

#include <command.h>

inherit COMMAND_BASE;

mixed cmd() {
  write( "You are "+ (string)WHO_H->
         who_line(TP, creatorp(TP),
                  TP->query_cols(), 1) +".\n" );
  return 1;
} /* cmd() */

mixed *query_patterns() {
   return ({ "", (: cmd() :) });
} /* query_patterns() */

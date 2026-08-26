
#include <group_handler.h>

inherit COMMAND_BASE;

mixed cmd() {
   return GROUP_CMD->group_command_control( "list", "", "", "", ({ "" }), "list" );
} /* cmd() */

mixed *query_patterns() {
   return ({ "", (: cmd :) });
} /* query_patterns() */

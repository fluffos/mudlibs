#include <creator.h>

inherit COMMAND_BASE;

#include <peopler.h>
#include <creator.h>

mixed cmd(string str) {
   mixed *stuff;

   stuff = this_player()->query_property("netstat list");
   if (!stuff) {
      stuff = N_DEFAULT;
   }
   return PEOPLER->do_command(stuff, str);
} /* cmd() */

mixed *query_patterns() {
   return ({ "", (: cmd(0) :),
             "<word>", (: cmd($4[0]) :) });
} /* query_patterns() */

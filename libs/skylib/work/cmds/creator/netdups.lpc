
#include <creator.h>
#include <peopler.h>

inherit COMMAND_BASE;

#define MULTIPLAYER "/handlers/multiplayer"

int cmd(string str) {
   mixed *bing;

   bing = this_player()->query_property("netdups list");
   if (!bing) {
      bing = ND_DEFAULT;
   }
   return PEOPLER->do_command(bing, str, (: strcmp(query_ip_number($1),
                                            query_ip_number($2)) :), 1);
} /* cmd() */

mixed *query_patterns() {
   return ({ "", (: cmd(0) :),
             "<word>", (: cmd($4[0]) :) });
} /* query_patterns() */

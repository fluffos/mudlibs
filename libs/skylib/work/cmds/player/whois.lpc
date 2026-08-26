/* whois command, trial out by Turrican for a commands daemon. */

#include <command.h>

inherit COMMAND_BASE;

mixed cmd(object *obs) {
  write("That is " + (string)WHO_H->
        who_line(TP->expand_nickname(obs[0]),
                 creatorp(TP),
                 TP->query_cols()) +".\n" );
  return 1;
} /* cmd() */

mixed *query_patterns() {
  return ({ "<indirect:player>", (: cmd($1) :),
            this_player()->query_name(), (: cmd(({this_player()})) :) });
} /* query_patterns() */

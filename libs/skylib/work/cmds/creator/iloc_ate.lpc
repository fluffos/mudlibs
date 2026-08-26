/* locate command, trial out by Turrican for a commands daemon. */

#include <network.h>

inherit COMMAND_BASE;

mixed cmd(string who) {
  if (!who) {
    notify_fail("Syntax: locate <name>\n");
    return 0;
  }
  if (INTERMUD_H -> locate(who))
    tell_object(TP,"Intermud locate request for "+CAP(who)+" sent.\n");
  else
    tell_object(TP,"Intermud is currently being shutdown.\n");

  return 1;
}

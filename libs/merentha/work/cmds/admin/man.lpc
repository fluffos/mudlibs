// Petrarch
// Merentha Lib 1.0
// <man>

#include <daemons.h>

varargs int command(string topic) {
if(topic) MAN_D->get_help_file(topic,this_player()->getenv("SCREEN"));
  else MAN_D->do_help(topic,this_player()->getenv("SCREEN"));
  return 1;
}

string help() {
  return "Syntax: man <topic>\n\n\This command will display the man for a specific topic or function.  Or you can leave out the optional topic to enter the interactive man system.";
}


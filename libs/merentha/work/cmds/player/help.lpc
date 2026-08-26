// Petrarch
// Merentha Lib 1.0
// <help>

#include <daemons.h>

varargs int command(string topic) {
if(topic) HELP_D->get_help_file(topic,this_player()->getenv("SCREEN"));
  else HELP_D->do_help(topic,this_player()->getenv("SCREEN"));
  return 1;
}

string help() {
  return "Syntax: help <topic>\n\n\This command will display the help for a specific topic.  Or you can leave out the optional topic to enter the interactive help system.";
}


/*    /cmds/player/help.c
 *    from the Foundation II LPC Library
 *    the help command
 *    created by Descartes of Borg 950427
 */

#include <lib.h>
#include <daemons.h>

inherit LIB_DAEMON;

mixed cmd(string args) {
    string topic, category;
    int x;

    if( !args || args == "" ) args = "*player general";
    else args = trim(args);
    if( (x = strsrch(args, "*")) != -1 ) {
	if( !x ) {
	    topic = "";
	    category = args;
	}
	else {
	    topic = args[0..(x-2)];
	    category = args[x..];
	}
    }
    else {
	topic = args;
	category = "";
    }
    HELP_D->help(topic, category);
    return 1;
}

void help() {
    message("help", "Syntax: <help ([topic|category]) ([category])>\n\n"
      "With no arguments, you are sent into the general help menu.  "
      "You may, instead, pass a topic, a category, or both a topic "
      "and a category as an argument.  If you pass a category, "
      "you will be given the help menu for that category.  If you pass "
      "a topic as an argument, you will see the help information on that "
      "topic.  Since come categories may have topics of the same name, "
      "you can specify both a topic and a category on the command line.  "
      "\nExamples:\n\"help\"\n\"help arches\"\n\"help *player commands\"\n"
      "\"help mail *high mortal commands\"", this_player());
}

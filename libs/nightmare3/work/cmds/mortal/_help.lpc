/*    /cmds/mortal/_help.c
 *    from Nightmare IV
 *    the new help menu command interface
 *    created by Descartes of Borg 940420
 */

#include <std.h>
#include <daemons.h>

inherit DAEMON;

int cmd_help(string str) {
    string topic, category;
    int x;

    if(!str) str = "*player general";
    if((x = strsrch(str, "*")) != -1) {
        if(x < 2) topic = str;
        else {
            topic = str[0..x-2];
            category = str[x..strlen(str)-1];
	  }
      }
    else topic = str;
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

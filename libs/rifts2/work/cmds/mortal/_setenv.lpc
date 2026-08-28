//      /bin/mortal/_setenv.c
//      from the Nightmare Mudlib
//      a limited set command for users
//      created by Descartes of Borg 930903

#include <std.h>
#include <daemons.h>

inherit DAEMON;

int cmd_setenv(string str) {
    string cle, val;
    string *vars;
   int i;

    if(!str || sscanf(str, "%s %s", cle, val) != 2) {
	vars = this_player()->regexp_query_env(".*");
	if(!vars || !sizeof(vars))
	    return notify_fail("No variables set.\n");
	for(i=0;i<sizeof(vars);i++) {
	    printf("%-15s%s\n",vars[i],this_player()->getenv(vars[i]));
	} 
	return 1;
    }
    switch(cle) {
      case "SCREEN": case "LINES":
        if(!atoi(val)) return notify_fail("Enter in a number.\n");
        else this_player()->setenv(cle, val);
        break;
      case "TZONE":
        this_player()->setenv(cle, val);
        break;
      case "TERM":
        if(!TERMINAL_D->query_term_support(val)) {
          message("info", "Unknown terminal type.", this_player());
          val = "unknown";
        }
        this_player()->setenv("TERM", val);
        this_player()->reset_terminal();
        break;
      case "TITLE":
        if(!wizardp(this_player()) && !high_mortalp(this_player()) )
	    return notify_fail("You cannot set your title yet.\n");
	this_player()->setenv("TITLE", val);
	break;
      default:
	if(!wizardp(this_player()) && !ambassadorp(this_player()) &&
	    !high_mortalp(this_player()))
	    return notify_fail("Invalid variable: "+cle+"\n");
	this_player()->setenv(cle,val);
    }
    message("info",sprintf("Variable %s set to %s.", cle, val),this_player());
    return 1;
}

void help() { 
    message("help",
      "Syntax: <setenv [variable] [value]>\n\n"
      "Sets environment variables which customize the way the game "
      "appears to you.  You may set the following values:\n\n"
      "LINES: sets how many lines appear for paged information (like the "
      "who command) (default: 20)\n\nSCREEN: sets how wide your screen is so "
      "that information coming to you automatically gets wrapped to fit "
      "your screen width (default: 75)\n\nTERM: sets what set of instructions "
      "your terminal needs to be in colour (see help terminal) (default: "
      "unknown)\n\nTZONE: sets what time zone you are in for conversion "
      "of real world times into your time zone (default: PST) "
      "\nNOTE: Now, wizards, high mortals, and ambassadors may use this "
      "command like set, which no longer exists, i.e., they may set ANY "
      "environment variable with it. "
      "\nsetenv with no args lists current environment vars.\n"
        "\nROOM_KNOWN: set this to anything but 0 if you want players to "
	"be able to tell what room you're in by typing who -line.  Set back "
	"to zero to make your position unknown again.\n",
      this_player()
    );
}

//      /bin/mortal/_setenv.c
//      from the Nightmare Mudlib
//      a limited set command for users
//      created by Descartes of Borg 930903

#include <std.h>
#include <daemons.h>

inherit DAEMON;

int cmd_setenv(string str) {
    string cle, val;

    if(!str || sscanf(str, "%s %s", cle, val) != 2) 
	return notify_fail("Usage <setenv [variable] [value]>\n");
    switch(cle) {
    case "TITLE":
	if (archp(this_player()))
	{
	    this_player()->setenv("TITLE", val);
	} else return notify_fail("Invalid varible: "+cle+"\n");
	break;     
    case "BOAT_DESC":
	switch(val) {
	case "0":
	    this_player()->setenv("BOAT_DESC", 0);
	    break;
	case "1":
	    this_player()->setenv("BOAT_DESC", 1);
	    break;
	default:
	    write("Use 0 to turn off boat descriptions, and 1 to turn it on.\n");
	    return 1;
	    break;
	}
	break;
    case "CENSOR_PRIVATE":
      this_player()->setenv(cle, atoi(val));
      break;
    case "ASK_ADVANCE":
      this_player()->setenv(cle, atoi(val));
      break;
    case "SKILL_SHOW":
	this_player()->setenv("SKILL_SHOW", val);
        break;
    case "SCREEN": case "LINES":
	if(!atoi(val)) return notify_fail("Enter in a number.\n");
	if (atoi(val) < 1 || atoi(val) > 1000) return notify_fail("Enter a number 1 - 1000\n");
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
    default: return notify_fail("Invalid variable: "+cle+"\n");
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
      "of real world times into your time zone (default: PST)\n\nBOAT_DESC:"
      " sets if you will see your boats description when you sail.\n"
        "\nCENSOR_PRIVATE: sets whether or not to censor incoming "
        "communications, like tells\n"
      "\nASK_ADVANCE: sets whether or not to verify if you want to advance in level\n",
      this_player()
    );
}


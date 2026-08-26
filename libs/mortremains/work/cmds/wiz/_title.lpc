// Written by Chronos (6/4/96) 
// (04-05-98) Chronos removed all traces of %^BOLD%^ references and their like.
//            This command is designed to allow wizards to change their titles
//            quickly and easily.

#include <mudlib.h>

inherit DAEMON ;

int cmd_title(string title) {
    string temp;
    if (!title) {
	write("Your title is currently set to:\n"+TP->query("short") +
	  "\n");
	return 1;
    } 
    if (sscanf(title, "%s$N%s", temp, temp)!=2)
	TP->setenv("TITLE", "$N "+title+" ($A)");
    else TP->setenv("TITLE", title + " ($A)");
    write("Your title is now set to:\n"+TP->query("short")+"\n");
    return 1 ;
}

string help() {
    return(@ENDLONG

Syntax: title [title]

Allows you to set your title.  If no argument is specified,
your current title is displayed.

Remember that $N is automagically added to the beginning of the title string,
and that $A is added to the end of the string.

ENDLONG
    );
}

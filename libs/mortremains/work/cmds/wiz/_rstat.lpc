// Kyako's first command.
// At some point Chronos disabled it.
// Re-enabled by Cyanide, 2000 Jan 06, about 3:21pm.

#include <uid.h>
#include <mudlib.h>

#define SYNTAX "Syntax: rstat <stat>\n"

inherit DAEMON;

int cmd_rstat(string str) {
// int cmd_rstat(string str) { //Chronos added this.
    string statr;
    int curval, newval, test;

    seteuid(ROOT_UID);

    if (!str) {
	write(SYNTAX);
	return 1;
    }

    switch (str) {
    case "constitution" : statr = "constitution";break;
    case "strength" : statr = "strength";break;
    case "dexterity" : statr = "dexterity";break;
    case "intelligence" : statr = "intelligence";break;
    case "wisdom" : statr = "wisdom";break;
    case "charisma" : statr = "charisma";break;
    case "con" : statr = "constitution";break;
    case "str" : statr = "strength";break;
    case "dex" : statr = "dexterity";break;
    case "int" : statr = "intelligence";break;
    case "wis" : statr = "wisdom";break;
    case "cha" : statr = "charisma";break;
    default : statr = "not";
    }

    if (statr=="not") {
	write("Invalid stat.\n");
	return 1;
    }

    write("What do you want to set "+statr+" to? :");
    input_to("set_var", statr);

    return 1;
}

void set_var (string i, string statr) {
    string basestatr;
    int num, newval, curval;

    sscanf(i, "%d", num); 
    basestatr = "base_stat/"+statr;
    curval = TP -> query(basestatr);
    newval = num;

    if (newval < 1 || newval > 25) {
	write("Please keep stats between 1 and 25.\n");
	return 1;
    }

    if (newval <= 0 || statr == "not") {
	write(wrap("Command failure. You cannot change your stat"+
	    " to that value or you have selected an invalid stat."));
    } else {
	TP -> set(basestatr, newval);
	TP -> set("stat/"+statr, newval);
	write("You have set your "+statr+" to "+num+".\n");
    }
    return 1;
}

string help() {
    return (@EndHelp
Usage: rstat <stat>

This command sets your base stat to to the given value.
EndHelp
    );
}

/*
**  FILE:  _agehack.c
**  CREATOR:  Originally Chronos@AtFoD
**  CHANGES:
**    07 Aug 96   Chronos	Created the file.
**    10 Apr 97	  Cyanide       Re-created the file...
*/

#include <uid.h>

inherit DAEMON;

int cmd_agehack(string tmp) {
    int age;

    seteuid(ROOT_UID);

    if (!adminp(this_player())) {
	write("Only admin may agehack!\n");
	return 1;
    }

    if (!tmp) {
	write("Usage: agehack <days>\n");
	return 1;
    }

    if (sscanf(tmp, "%d", age) != 1) {
	write("Usage: agehack <days>\n");
	return 1;
    }

    this_player()->set("age", age * 86400);
    write("Done.\n");
    return 1;
}

string help() {
    string str;

    str = (@ENDHELP
Usage: agehack <days>

This command will make you EXACTLY x days old.
ENDHELP
    );
    return str;
}

/*
** FILE : _Unnuke.c
** PURPOSE : Reverses a previous 'nuke'.
** CREDITS : 
**    18 May 99   Cyanide wrote this file.
*/

#include <config.h>
#include <uid.h>
#include "/u/c/cyanide/debug.h"

inherit DAEMON;

string help();

int cmd_unnuke(string str) {
    string f_link, f_user;
    int flag_O = 0, err_flag = 0;

    if (!adminp(TP)) {
	write("Access denied. Attempt logged.\n");
	return 1;
    }

    seteuid(ROOT_UID);

    if (!str) {
	write(help());
	return 1;
    }

    // Check for switches
    if (sscanf(str, "-%s %s", str, f_user)==2) {
	int i, sz = strlen(str);
	string err = "";

	// Unravel the flags.
	while (sz--) {

	    switch(str[sz..sz]) {
	    case "O" : flag_O = 1; break;
	    default : 
		err += (strlen(err) ? ", " : "") + str[sz..sz];
	    }
	}

	if (strlen(err)) 
	    write("*Warning: Unknown switch(es): "+err+"\n");

	str = f_user;
    }

    str = lower_case(str);
    if (user_exists(str) && !flag_O) {
	write("That user already exists. Operation aborted.\n");
	return 1;
    }

    if (ARCHIVE_DIR) {
	f_user = ARCHIVE_DIR + "user/" + str + __SAVE_EXTENSION__;
	f_link = ARCHIVE_DIR + "connection/" + str + __SAVE_EXTENSION__;
    } else {
	write("Player archive directory not defined. Aborting.\n");
	return 1;
    }

    if (!file_exists(f_user)) err_flag += 1;
    if (!file_exists(f_link)) err_flag += 2;
    if (err_flag) {
	string err_msg = "No valid archive for "+capitalize(str)+": ";

	switch (err_flag) {
	case 1 : err_msg += "User archive data not present."; break;
	case 2 : err_msg += "Connection archive data not present."; break;
	case 3 : err_msg += "No copy of "+capitalize(str)+
	    " has been archived."; break;
	}

	write(iwrap(err_msg + "\nAborting."));
	return 1;
    }

    err_flag = cp (f_user, "/data/std/user/" + str[0..0] + "/" + str 
      + __SAVE_EXTENSION__);
    err_flag += cp (f_link, PDATA_DIR + str[0..0] + "/" + str + 
      __SAVE_EXTENSION__);

    if (err_flag!=2) 
	write("Operation failed. Errors in copy.\n");
    else
	write(capitalize(str) + " successfully restored.\n");

    return 1;
}

string help() {
    return (@EndHelp
NAME
    unnuke

SYNOPSIS
    unnuke [-O] [username]

DESCRIPTION
    This command restores a previously nuked character from 
    archives.

OPTIONS
    -O    Overrides check to whether or not the user is already
          active. The existing character is deleted irrevocably.
EndHelp
    );

}

/* EOF */

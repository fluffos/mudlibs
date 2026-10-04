// File: /cmds/adm/_aproposm.c
//   - apropos database manager
//
// Creator: Robocoder@TMI-2 (04-Jul-93)
//
// See also:
//   /adm/daemons/aproposd.c, /cmds/xtra/_apropos.c

#include <config.h>
#include <mudlib.h>
#include <daemons.h>

inherit DAEMON;

void menu();
string help();

int cmd_aproposm(string str) {
    if (!adminp(geteuid(this_player())))
        return 0;

    menu();
    return 1;
}

// if you change the menu text, update the help text (where applicable)
protected void menu() {
    write( @ENDMENU

APROPOS DATABASE MAINTENANCE
~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    List data       - browse the database, and then quit
    Scan            - scan function docs to build database, and then quit
    Scan <doc file> - scan a new manual section to add to the database
    Quit/eXit       - leave program
ENDMENU
    );
    write("Command: ");
    input_to("select");
}

protected int select(string str) {
    string arg;
    string *files, *phrases;
    int i, s;

    if (!str || str == "") {
        write("Command [L,S,Q,X,?]: ");
        input_to("select");
        // does not return
    } else {
        str = lower_case(str);
	if (str != "list data")
            sscanf(str, "%s %s", str, arg);

        // command switch
        //   checks for abbreviations
        //   processes valid commands
        switch (str) {
	    case "list":
            case "list data":
            case "ld":
            case "data":
                files = (string *) APROPOS_D->query_files();
                phrases = (string *) APROPOS_D->query_phrases();
                if (!files || !sizeof(files)
	              || !phrases || !sizeof(phrases)) {
                    write("*** Database is currently empty. ***\n");
                } else {
                    // this is essentially a man -k "all" :)
                    s = sizeof(files);
                    if (s != sizeof(phrases)) {
                        write("*** Database corrupt.  Recommend [re]scanning function docs. ***\n");
                    } else {
                        // merge arrays for output
                        for (i = 0; i < s; i++)
                            files[i] = files[i] + ": " + phrases[i];
			files = sort_array(files, "compare", APROPOS_D);
                        this_player()->more(files, 1);
                        return 1;
                    }
                }
                break;

	    case "s":
            case "scan":
                if (!arg || arg == "") {
                    // rescan database
                    (void) APROPOS_D->update_aplist();
                } else {
                    // scan file into database
                    (void) APROPOS_D->process_file(arg);
                }
                break;

            case "q":
            case "x":
            case "quit":
            case "exit":
                return 1;
                break;  // not reached

            case "?":   // redisplay menu
                break;

            default:
                write("Unrecognized command.\n");
        }
    }
    menu();
}

void done_more() {
    // returns here from pager
    write("Command [L,S,Q,X,?]: ");
    input_to("select");
}

// if you change the help text, update the menu text (where applicable)
string help() {
    return( @ENDHELP
Syntax: aproposm

This admin command permits maintenance of the apropos database.  A menu
will present the following commands for database manipulation:

    list data         - browse the database, and then quit
    scan              - scan function docs to build database, and then quit
    scan <doc file>   - scan a new manual section to add to the database
ENDHELP
    );
}

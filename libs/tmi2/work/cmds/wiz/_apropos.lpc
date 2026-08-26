// File: _apropos.c
//   Modeled after UNIX(tm) command 'man -k' or 'apropos'
//   This command is different from 'whatis' in that it returns all
//   matches that contain the string in question.
//
// History:
//   Created by Whiplash@TMI
//   Minor rewrite by Truilkan@TMI
//   Cleaned up by Robocoder@TMI-2 (04-Jul-93)
//
// See also: /adm/daemons/aproposd.c, /cmds/adm/_aproposm.c

#include <mudlib.h>
#include <daemons.h>

inherit DAEMON;

int help() {
    write ( @ENDHELP
Usage: apropos <topic>

Given a topic, apropos will list all the efuns and lfuns that are related
to that topic. Not unlike 'man -k' on a UNIX box.
ENDHELP
    );
    return 1;
}

int cmd_apropos(string str) {
    string *all_match;

    if (!str || str == "") {
        help();
        return 1;
    }

    all_match = (string *)APROPOS_D->apropos(str, 1);
    if (sizeof(all_match)) {
        all_match = sort_array(all_match, "compare", APROPOS_D);
        this_player()->more(all_match, 1);
    } else {
        write("No matching entry.\n");
    }
    return 1;
}

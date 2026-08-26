// my command
// This checks all wizards with directories and prints their last
// login times. Used to identify people whose directories should be
// purged.
// Most of the code to do this was taken from the TMI-2 finger daemon,
// written by Buddha. His code header follows. Several other people
// made bug fixes to it. See that file for full details. Its code was
// copied on 8-20-94, so comments up to that date apply here.
// Buddha sez:
// This version of the finger daemon was written by Buddha@TMI-2, with some
// existing code from the old finger daemon (most of which he also did).
// This is part of the TMI-2 distribution mudlib.
// Please retain this header.
// * end Buddha's comment *

#include <uid.h>
#include <config.h>
#include <mudlib.h>

inherit DAEMON;

#define ACK ([ 1 : "/u/a/", \
	2 : "/u/b/", \
        3 : "/u/c/", \
        4 : "/u/d/", \
        5 : "/u/e/", \
        6 : "/u/f/", \
        7 : "/u/g/", \
        8 : "/u/h/", \
        9 : "/u/i/", \
        10 : "/u/j/", \
        11 : "/u/k/", \
        12 : "/u/l/", \
        13 : "/u/m/", \
        14 : "/u/n/", \
        15 : "/u/o/", \
        16 : "/u/p/", \
        17 : "/u/q/", \
        18 : "/u/r/", \
        19 : "/u/s/", \
        20 : "/u/t/", \
        21 : "/u/u/", \
        22 : "/u/v/", \
        23 : "/u/w/", \
        24 : "/u/x/", \
        25 : "/u/y/", \
        26 : "/u/z/", ]) 

void create() {
    seteuid(getuid()) ;
}

//  This function is called to restore the user's connection object that
//  holds the essential login information.  If the user in question is
//  currently logged in, then their current connection object is returned,
//  otherwise it is restored.  You should probably call clean_up() on the
//  object when finished, and it will either self-destruct, if not interactive
//  or associated to a body, or save and wait for further information
//  requests, if it is.
object restore_data(string name) {
    object link;

    if (find_player(name) && interactive(find_player(name))) {
        return (object)find_player(name)->query_link();
    }

    link = new(CONNECTION);
    seteuid(name);
    export_uid(link);
    seteuid(ROOT_UID);

    link->set("name", name);
    if (link->restore()) {
        return link;
    }

    // If this fails, then let's clean up afterwards...
    link->remove();
    return 0;
}

string finger_user(string who) {
    object link;
    mixed tmp1, tmp2, tmp3, tmp4, tmp5;
    string msg;

    link = restore_data(who);
    if (!link) {
        return "There is no such user as "+capitalize(who)+".\n";
    }

    if (!link->query("last_on"))
	return capitalize(who)+": Last login time not available.\n" ;
    else
	return capitalize(who)+": Last on "+
              ctime((int)link->query("last_on")) + " from " +
              (string)link->query("ip") + " \n";

}

int cmdd_dirpurge() {
    int i ;
    string *wizzes ;
    int z, j ;

    for (i=1;i<27;i++) {
	wizzes = get_dir(ACK[i]) ;
	for (j=0;j<sizeof(wizzes);j++) {
	    write (finger_user(wizzes[j])) ;
	     write_file ("/adm/priv/WIZ_DIRS", finger_user(wizzes[j])) ;
	}
	z += sizeof(wizzes) ;
    }
    write (z+" directories.\n") ;
    return 1 ;
}

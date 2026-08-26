/** 
 * This file sets resistances for characters.
 * AUTHOR:  Cyanide
 * DATE  :  3 August 2000
 */

#include <uid.h>

inherit DAEMON;

int cmd_resist( string str ) {
    int val;

    seteuid( ROOT_UID );

    if (!mapp(TP->query("resist_type"))) {
	write("Invalid resistances mapping. Deleted.\n");
	TP->delete("resist_type");
	return 1;
    }

    if (!str) {
    }


    return 1;
}

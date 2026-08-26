/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: player_cmd.c,v 1.1 1998/01/06 04:42:56 ceres Exp $
 * $Log: player_cmd.c,v $
 * Revision 1.1  1998/01/06 04:42:56  ceres
 * Initial revision
 * 
*/
/*
 * This is a shadow to allow the command() efun to be called from another
 * object (like an effect).  Only commands in legal[] can be passed
 * to command().
 */

inherit "/std/effect_shadow";

// Just a few simple ones for testing
mapping legal = (["east" : 1,
                  "west" : 1,
                  "north" : 1,
                  "south" : 1,
                  "up" : 1,
                  "down" : 1,
                  ]);

int remote_cmd(string cmd) {
    if ( legal[cmd] ) {
        write("Legal...\n");
        return command( cmd );
    }
    write("Illegal...\n");
    return 0;
}

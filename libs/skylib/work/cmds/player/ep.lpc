/*
 * Original by Manshoon of Newmoon in February 1995
 * Rewritten for Discworld by Deutha in March 1995
 */

/*
 * This command shows a player how many of their energy points are
 * available for use for different commands. With commands using
 * query_specific_gp( string type ) instead of the straight query_gp()
 * the various stupid paradoxes of the old system will be avoided by
 * making sure that a player's available points for a given command
 * depend on the points skill most relevant.
 */

#include <skills.h>

inherit COMMAND_BASE;


int cmd() {
   int gp, max_gp;
   gp = (int)this_player()->query_gp();
   max_gp = (int)this_player()->query_max_gp();
   write( "You have "+ gp +" ("+ max_gp +") Ep.\n" );
   return 1;
} /* cmd() */


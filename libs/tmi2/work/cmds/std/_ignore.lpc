/*
// File:     /cmds/std/_ignore.c
// Author:   Pallando @ TMI
//           Rewritten by Inspiral @ TABOR, 93-09-20
// Purpose:  Allow for supressing various types of player output
//           from one or more users
// 
//
// 94-11-10 Leto changed status to int
*/


#include <mudlib.h>

inherit DAEMON;

int cmd_ignore( string input ) {
  string *ignore;
  string *list;
  int rem_flag;
  int loop, size;

  ignore = this_player() -> query( "ignore" );

  if( !pointerp( ignore ) ) ignore = ({ });

  if( !input ) {
    if( !sizeof( ignore ) ) write( "You are ignoring no-one.\n" );
    else write( wrap( "You are ignoring: " + implode( ignore, ", " ) ) );
    return 1;
  }

   list = explode( lower_case( input ), " " );

   for( loop = 0, size = sizeof( list );
		 loop < size; loop++, rem_flag = 0 ) {
      if( sscanf( list[loop], "-%s", list[loop] ) )
		rem_flag = 1;

        //  Why would you want to ignore someone who doesn't exist?
    // Because it might be a user@mud , or maybe you even fear a whole mud !
/*
      if( !user_exists( list[loop] ) ) {
          printf( "IGNORE: Ther is no such user: %s.\n",
			capitalize( list[loop] ) );
          continue;
      }
*/

     // Take someone out of ignore list.
     if( rem_flag ) {
       if( member_array( list[loop], ignore ) == -1 ) {
         printf( "IGNORE: You aren't ignoring %s!\n",
			capitalize( list[loop] ) );
         continue;
       }

       printf( "IGNORE: You are no longer ignoring %s.\n",
		capitalize( list[loop] ) );
       ignore -= ({ list[loop] });
       continue;
     }

   // Add a name to the ignore list.
    if( member_array( list[loop], ignore ) != -1 ) {
       printf( "IGNORE: You are already ignoring %s!\n",
		capitalize( list[loop] ) );
       continue;
    }

  // Well, you can't ignore the evil admin!!!! Muahahahah!
    if( adminp(list[loop]) ) {
      printf( "IGNORE: %s is an admin, and cannot be ignored!\n",
		capitalize( list[loop] ) );
      continue;
    }

    printf( "IGNORE: You are now ignoring %s.\n",
			capitalize( list[loop] ) );
    ignore += ({ list[loop] });
  }

  this_player() -> set( "ignore", ignore );
  return 1;
}

string help() {
  return( ""+
    "Syntax: ignore [[-]<name>]\n\n"
    "Ignore on its own lists the names you are ignoring\n"
    "currently.  If you give a name, or a list of names, it tries to\n"
     "add that name to your ignore list.  If you give a name prepended with \"-\",\n"
    "that particular name will be removed from your ignore list.\n"
    "\nA name can be that of a user or @mud or user@mud\n"+
    "\nIgnoring someone blocks their tells, and any channel communica"
    "tion,\nexcept from admins.\n"
    "\nSee also: tell\n"
  "" );
}

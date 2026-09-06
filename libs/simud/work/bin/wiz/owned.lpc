/*
 * Coded by : Zarylse
 * Date     : 2003-09-07
 * Notes    : Lists owners of buildings, buildings without owners, or both.
 *
 * Changes  : [2003-10-12]
 *              - name changed from owners.c to owned.c
 *              - syntax changed from Unix-style to MUD-style
 *              - allows searching for objects in any specified location
 *              - fixed extra newline between heading and "No buildings"
 *              - finished commenting each section of code
 *            [2003-10-10]
 *              - filters out objects without a query_owner() function
 *              - allows -h to look only at objects in this_player's room
 */

#include <const.h>
#include <wizard.h>
#define BLDG_DIRS ({ "/bldg/", "/econ/" })

int main( string str ) {
   string dir, file, *files = ({ });
   string options, args, player, location, locstr;
   string owner, no_own, trunc = "";
   object ob, loc;
   int i, no_owners, both;

   WIZ_CHECK

   // parses syntax, allowing all possible permutations
   if ( str ) {
      if ( sscanf(str, "-%s %s", options, args) == 2 ||
           (sscanf(str, "%s", args) == 1 && args[0] != '-') )
      {
         if ( sscanf(args, "by %s at %s", player, location) != 2 &&
              sscanf(args, "at %s by %s", location, player) != 2 &&
              sscanf(args, "by %s %s", player, location) != 2 &&
              sscanf(args, "at %s", location) != 1 &&
              sscanf(args, "by %s", player) != 1 &&
              args != "here" )
            return notify_fail( "==> [Syntax] owned [-options] [by <whom>] [at <location>]\n" );
      }
      if ( args[0] == '-' && sscanf(str, "-%s", options) != 1 )
         return notify_fail( "==> [Syntax] owned [-options] [by <whom>] [at <location>]\n" );
   }
   // allows the shorthand "owned here"
   if ( args == "here")
      location = "env";

   // errors and exits if player or location can't be found
   if ( player && !file_exists(PLAYER_DIR + lower_case(player) + ".o") )
      return notify_fail( "==> [Error] That player does not exist.\n" );
   if ( location ) {
      if ( location == "here" )
         location = "env";
      if ( !(loc = find_thing(location)) )
         return notify_fail( "==> [Error] That location does not exist.\n" );

      // sets the location string, for displaying the list(s) of buildings
      if ( loc == environment(this_player()) )
         locstr = " here";
      else
         locstr = " at " + get_location(loc);
   }

   // looks for valid switches, ignores invalid ones
   if ( options ) {
      if ( member(options, 'n') != -1 ) no_owners = 1;
      if ( member(options, 'b') != -1 ) both = 1;
      if ( options == "n" ) player = 0;
   }

   // creates an array with the full path of every file in the directories
   foreach( dir : BLDG_DIRS )
      files += get_dir( dir, GETDIR_PATH );

   // removes any buildings that are not loaded or that can't be owned
   foreach ( file : files )
      if ( !find_object(file) || member(functionlist(file), "query_owner") == -1 )
         files -= ({ file });

   // exits if no loaded, ownable buildings exist anywhere in the MUD
   if ( !sizeof(files) ) {
      msg( "==> [Notice] There are no ownable buildings in the world." );
      return 1;
   }

   // sets up the title strings for each section of the display
   if ( !no_owners || both )
      owner = "~CTITThe following buildings are owned" + (player ? " by " + capitalize(player) : "") +
              (locstr ? locstr : "") + ":~CDEF\n";
   if ( no_owners || both )
      no_own = "~CTITThe following buildings are ownerless" + (locstr ? locstr : "") + ":~CDEF\n";

   // check each building for an owner
   foreach ( file : files ) {
      i = 0; // reset counter for each building type
      foreach ( ob : clones(file) ) {
         // if only looking at objects at loc, skip objects in other locations
         if ( location && member(all_environment(ob), loc) == -1 )
            continue;

         // buildings WITH owners...
         if ( (!no_owners || both) && ob->query_owner() ) {
            if ( player && ob->query_owner() != lower_case(player) )
               continue;
            owner += "~CBRT   " + object_name(ob) + "~CDEF is at ~CLAB" +
                     (environment(ob) ? get_location(environment(ob)) : "[an invalid location]") +
                     (player ? "" : "~CDEF, owned by ~CTIT" + capitalize(ob->query_owner())) + "~CDEF\n";
            if ( ++i == 20 )
               trunc += "~CWRNTruncated: There exist " + sizeof(clones(file)) + " " +
                        find_object(object_name(ob))->query_plural() + " in all, though some may not have owners.~CDEF\n";
            if ( i > 20 ) continue;  // can't break, or won't get other building types or unowned ones
         } // end owners

         // ...and buildings WITHOUT owners
         if ( (no_owners || both) && !ob->query_owner() ) {
            no_own += "~CBRT   " + object_name(ob) + "~CDEF is at ~CLAB" +
                     (environment(ob) ? get_location(environment(ob)) : "[an invalid location]" ) + "~CDEF\n";
            if ( ++i == 20 )
               trunc += "~CWRNTruncated: There exist " + sizeof(clones(file)) + " " +
                        find_object(object_name(ob))->query_plural() + " in all, though some may have owners.~CDEF\n";
            if ( i > 20 ) continue;  // can't break, or won't get other building types or owned ones
         } // end no_owners
      } // end for each clone
   }

   // displays the list of buildings owned
   if ( owner ) {
      msg( owner[..<2] );  // removes the last newline
      if ( sizeof(explode(owner,"\n")) <= 2 ) msg( "   No buildings." );
      if ( no_own ) msg( "" );  // adds a blank line to separate the sections
   }
   // displays the list of buildings unowned
   if ( no_own ) {
      msg( no_own[..<2] );  // removes the last newline
      if ( sizeof(explode(no_own,"\n")) <= 2 ) msg( "   No buildings." );
   }
   // warns about truncated lists
   if ( trunc && trunc != "" )
      msg( trunc );

   return 1;
}

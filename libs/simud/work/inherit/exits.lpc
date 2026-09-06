#include <const/exitsconst.h>
#include <const.h>

/** This object is used for objects that need to have exits attached to them.
 * It is therefore particularly used by the room object, but this is hardly
 * a requirement. In general, any object which a player can get inside of
 * should probably inherit this, so that they can get back out :).
 */

// Prototypes:
mapping query_exit( string dir );

// A mapping of all the exit information in this object.
// Deleted, not used anymore.
// mapping exits;

/** An array of all objects that have recently passed through this room.
 * This list is circular.
 */
string *tracklist;
/// Most recent item in the tracklist
int tlistpos;
/// Number of items in the tracklist
int tlistlen;

/// Used by the object editor for fetching exits information.
string exits_info() {
   return "tlistpos\ntlistlen\nexit_list";
}

/** Called every time someone walks into this room (by the
 * init() function). Each room tracks the names of the
 * last five objects that entered them and called init.
 * This is intended to make it easy for someone to add
 * tracking/trailing skills later on.
 */
void add_track(object ob) {
   if( tlistlen <= 0 ) return;
   if( !tracklist ) tracklist = allocate( tlistlen );
   tracklist[tlistpos] = ob->query_name();
   tlistpos++;
   if(tlistpos >= tlistlen) tlistpos = 0;
}

/** Called everytime something walks in. This is used
 * to create the exit 'actions'. This may later be
 * replaced by standardized bin/ verbs.
 */
void _init_exits() {
   if( environment(this_player()) == this_object() ) {
      add_track(this_player());
   }
}

/** Returns an array of object pointers (probably with some
 * 0's in it), giving the objects which most recently passed
 * through this room/area/whatever. There may be duplicates.
 */
string *query_tracklist() {
   return tracklist;
}

/** \return The current length of the list used for tracking
 * things that pass through this room.
 */
int query_tlistlen() {
   return tlistlen;
}

/** Allows you to change the length of the list used
 * for tracking things that pass through.
 */
void set_tlistlen( int x ) {
   if( intp(x) ) { tlistlen = x; tracklist = allocate(tlistlen); }
}

/** A \n delimited list in a string giving the directions
 * of all the exits in this room.
 */
string *query_exit_list() {
   string *slist = ({ });
   object ob;
   int iexit;
   mapping offset = ([ 0: 0 ]);

   foreach( ob : filter(all_inventory(this_object()), (: $1->query_is_exit() && $1->query_dir() :)) )
      slist += ({ ob->query_dir() });
   slist = sort_array( slist, #'> );
   for( iexit = 1; iexit < sizeof(slist); iexit++ )
      if( slist[iexit-1] == slist[iexit] )
         offset[iexit] = offset[iexit - 1] + 1;

   for( iexit = 1; iexit < sizeof(slist); iexit++ )
      if( offset[iexit] ) slist[iexit] = "/daemon/dictionary"->get_string_from_number( -offset[iexit] - 1 ) + " " + slist[iexit];
   if( sizeof(slist) )
      return slist;
   else
      return 0;
}

/** Initializes some variables in this object. Useful to be sure that
 * exits is always a mapping, and to initialize the tracking list.
 */
void _create_exits() {
   tlistlen = 5;
   tracklist = allocate(tlistlen);
}

#include <const.h>

/** Defines the basis functions for objects in the mud. Any object
 * that can be cloned or moved, and any object that makes use
 * of components (all #include's that don't have 'const' in the
 * name) should #include <object.h>, which is how you use this file.
 * This defines some reasonably clean default implementations of
 * certain functions.
 */

/** This variable is considered 'internal.' It is initialized when
 * this object is created, and contains the names of all functions
 * in this object which are considered constructors or destructors.
 * Any function whose name begins with "_create" is considered a
 * constructor, "_reset" for functions called on reset, and
 * "_destructor" for functions called when the object is destroyed.
 * There is also an "_init" available, called along with the
 * object's init() event.
 *
 * Note that you should take some care when creating your own
 * inheritable object that you use unique names for your special
 * functions. If there are any ambiguities, no error will be
 * detected, but only one of the functions will be called.
 *
 * If you override the create(), destructor(), etc. functions in
 * your own object, then you should always allow the control
 * to drop through using ::create(), ::destructor(), etc. If you
 * don't do this, parts of your object's inheritance tree may
 * not initialize properly.
 */
nosave string * __FLIST;

/** A generic mapping of customized variables on this object.
 * Rather than store a large number of variables that are rarely going
 * to get changed (for descriptions, etc.), this only records
 * deviations from some fixed default value.
 *
 * This is initialized to be a mapping because it is ESSENTIAL that
 * this be a mapping. Setting it to anything else will cause some
 * very, very nasty errors.
 */
mapping vars = ([ ]);

/// The basis init function -- calls all init_ functions in this_object()
void init() {
   string f;

   if( !pointerp(__FLIST) ) return;
   foreach( f: __FLIST )
   if( f[1] == 'i' ) // "init_" is the only one that starts with i
      call_other( this_object(), f );
}

/// For debugging purposes.
string *query___FLIST() {
   return __FLIST;
}

/** The basis create function -- calls all create_ functions in this_object().
 * The __FLIST array of function names is also initialized here.
 */
void create() {
   string f;

//   write("object::create() called, making __FLIST\n");
   __FLIST = functionlist( this_object() );
   __FLIST = filter( __FLIST, (: $1[0..6] == "_create" || $1[0..5] == "_reset" || $1[0..10] == "_destructor" || $1[0..4] == "_init" :) );
//   write("__FLIST is " + to_string(__FLIST) + "\n" );
   if( !pointerp(__FLIST) ) return;
   foreach( f: __FLIST )
   if( f[1] == 'c' ) // "_create" is the only one that starts with c
      call_other( this_object(), f );
}

/// The basis reset function -- calls all reset_ functions in this_object()
void reset() {
   string f;

   if( !pointerp(__FLIST) ) return;
   foreach( f: __FLIST )
   if( f[1] == 'r' ) // "_reset" is the only one that starts with r
      call_other( this_object(), f );
}

/// The basis destructor function -- calls all destructor_ functions in this_object()
string destructor( object ob ) {
   string f;

   if( !pointerp(__FLIST) ) return 0;
   foreach( f: __FLIST )
   if( f[1] == 'd' ) // "_destructor" is the only one that starts with d
      call_other( this_object(), f, ob );

   return 0; // Destructors return false if destruction is allowed.
}

/** The standard movement function. You should override this function if you want
 * to prevent movement under some circumstances, or if you want to be able to move
 * without triggering events. Both of these are very dangerous things to override,
 * so be sure you know what you are doing.
 *
 * The 'no_events' parameter is for system use; the purpose of it is to try and
 * speed up slow updates, where it doesn't matter if the objects know that they've
 * moved.
 */
varargs void move( object dest, int no_events ) {
   object ob_dest, old_env;

   if( !clonep(this_object()) )
      raise_error("Attempted to move blueprint object " + object_name(this_object()));

   if( stringp(dest) )
      ob_dest = find_object((string)dest);
   else
      ob_dest = dest;

   if( ob_dest == environment() ) {
      move_object( this_object(), ob_dest );
      return;
   }

   if( !objectp(ob_dest) )
      raise_error("Attempted to move object "+object_name(this_object())+" to an invalid destination ("+to_string(dest)+")");

   old_env = environment(this_object());
   move_object( this_object(), ob_dest );
   if( !this_object() ) return; // Self-destruction in init().
   if( no_events ) return; // Don't bother with events.
   if( environment(this_object()) )
      environment(this_object())->on_remove(this_object());
   if( !this_object() ) return;

   this_object()->on_move( old_env );
   if( !this_object() ) return;

   if( environment(this_object()) ) {
      environment(this_object())->on_insert(this_object());
   }
}

/** Moves this object to a valid position in the room. Doesn't do anything if
 * called in room, area, etc. objects, or if the environment doesn't have a
 * a grid. If it's already in a valid position, nothing is done -- this is
 * only to fix glitches.
 *
 * Caveat: This is only intended for use with objects that are fundamentally
 * mobile, meaning those that use on_paint. This function checks if this object
 * implements on_map_paint; if it does, this call is ignored (there's an
 * obnoxious self-collision bug that pops up occasionally otherwise).
 *
 * \return True if the object is moved, false otherwise.
 */
int validate_position() {
   if( !this_object()->query_has_map() && environment() && environment()->query_has_map() && !function_exists("on_map_paint") ) {
      int empty;

      // If the current position isn't valid, use the center of the room as a reference.
      if( !environment()->query_valid_square(this_object()->query_x(), this_object()->query_y()) )
         this_object()->set_coord( MAKE_C(environment()->query_map_xdim()/2, environment()->query_map_ydim()/2, 0) );

      // Find a new legal position from there.
      empty = environment()->get_empty(this_object()->query_x(), this_object()->query_y(), 0, this_object());
      if( empty != -1 )
         this_object()->set_coord( empty );

      return 1;
   }
   return 0;
}

/// A security mechanism to preserve data integrity between objects. Called a *lot*.
int query_allow_set( object caller ) {
   return "/secure/file_security"->query_allow_set( caller, this_object() );
}

/// \return A string giving a summary of all the public variables in this object. Handy for viewing stats of an object.
string get_stat() {
   return save_object(0);
}

/// \return An empty mapping. Override this function to define aspects in your object (see /include/const/classification.h)
mapping query_aspects() {
   mapping m = this_object()->query_default_aspects();
   if( mappingp(m) ) return m;
   return ([ ]);
}

/// \return True if this object as the aspect given by \a x. See /include/const/classification.h for possible values for \a x.
int query_has_aspect( int x ) {
   return member( query_aspects(), x );
}

/// \return The mapping of all customized variables. See the comment on \a vars.
mapping query_vars() {
   return vars;
}

/// Allows you to set the entire customized variables mapping at once. If \a m is not a mapping, it will be quietly ignored.
void set_vars( mapping m ) {
   if( mappingp(m) ) vars = m;
}

/// \return The value of the customized value for \a var -- If there is no custom value, 0 is returned.
mixed query_var( string var ) {
   return vars[var];
}

int query_has_var( string var ) {
   return member( vars, var );
}

/// Sets the value for \a var to \a val. See \a vars for more information.
void set_var( string var, mixed val ) {
   vars[var] = val;
}

/// Resets \a var to its default value.
void remove_var( string var ) {
   m_delete( vars, var );
}

/// Calls on_restore on all its contents
void on_restore() {
  object ob;

  foreach( ob : all_inventory(this_object()) )
    ob->on_restore();
}

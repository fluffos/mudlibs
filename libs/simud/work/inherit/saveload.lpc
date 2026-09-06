/**
 * Inherit this file if you want an object to be able to save its variables
 * to a .O file and you want it to be able to load from the same file.  This
 * also allows an object to be recloned and repositioned exactly, making
 * a stable world possible (essential for simulation).
 *
 * Note that objects which are capable of holding other objects (i.e.
 * monsters, boxes, chests, etc.) should NOT inherit this file. Instead,
 * inherit obj/inven, which encapsulates all the behaviors of obj/saveload
 * and also stabilizes inventories.
 */

#define ID_MONITOR "/secure/odin"

#define DB "/secure/db_saveload"	// object for using db to save

/// Makes objects capable of saving and reloading when the mud reboots.

/// The .c file from which this object was created.
nosave string my_file_name;

/// A magic number, used to determine where this object will save. No two saveload objects have the same one.
private nosave int unique_id;

/// An object reference -- where I saved.
symbol save_location;

/// \return The unique ID (used to determine this object's save file name, see Odin).
nomask query_unique_id() {
   if( !unique_id )
      unique_id = ID_MONITOR->get_new_id();
   return unique_id;
}

string query_file_name() {
   my_file_name = load_name(this_object());
   return my_file_name;
}

/** A string which gives the combination of this object's file name and
 * identification number, seperated by a a colon. This is used by Inven
 * to save the contents of an object.
 */
string query_full_id() {
   return query_file_name() + ":" + query_unique_id();
}

/** Used internally for loading this object's information
 * from a .o file in the /data/ directory. It has several
 * possible uses:
 *
 *  - Called while the world is loading to set up the object
 *    from its saved state
 *  - Called after the world has already loaded to fix a
 *    bug where the original object was destroyed, but its
 *    .o file is still intact (this is a little like an "undelete" --
 *    the old .o file is only around until it gets reassigned).
 *    Simply give it the ID for the .o file and it will load from it.
 *  - This may also be used to duplicate an existing object. In
 *    this case, it will load the data in ID but, upon detecting
 *    that the object is a duplicate, will change to a new ID.
 */
void load_self( int id ) {
   string dummy;

   if( !intp(id) )
      raise_error("load_self only accepts an integer id as argument. Try load_template to load a file.");

   if( unique_id ) {
      ID_MONITOR->free_id(unique_id);
   }
   unique_id = id;

   // TESTING
   dummy = DB->restore_object( unique_id );
   if( dummy == "" )
      restore_object( ID_MONITOR->get_save_file_name(id) );
   else
      restore_object( dummy );
   // TESTING

   if( my_file_name != load_name(this_object()) ) {
      log_file( "bad_template", as_string(this_object()) + " loaded from a file marked for " + my_file_name + " (uid " + unique_id + "/id="+id+")\n" );
   }
   my_file_name = load_name(this_object());

   // If this object was sharing a data file with another, already
   // loaded object, keep its settings but assign them to a new save
   // file ID.
   if( !ID_MONITOR->check_id(unique_id) ) {
      if( "/world/world"->query_load_in_progress() )
         call_out( "reset_unique_id", 0 );
      else
         unique_id = ID_MONITOR->get_new_id();
   }
}

void reset_unique_id() {
   remove_call_out("reset_unique_id");
   if( "/world/world"->query_load_in_progress() )
      call_out( "reset_unique_id", 2 );
   else
      unique_id = ID_MONITOR->get_new_id();
}

void load_stat( string data ) {
   restore_object( data );
}

/** Allows you to save this object's information
 * to any file, as long as the object has write
 * access to it. A .o extension is always assumed.
 */
void save_template( string str ) {
   if(!str) return;

   query_file_name(); // Sets my_file_name.
   save_object( str );
}

/** Allows you to load settings for this object
 * from any file, as long as this object has
 * read access to it. A .o extension is assumed,
 * and must not be specified.
 */
void load_template( string str ) {
   if( !str ) return;

   restore_object( str );
   my_file_name = 0;
}

/* Use this to save clones
 * If do_not_differ is true, it will call save_template instead (for objects
 * that do not use a copy number as part of the filename).
 */
void save_self() {
   if( unique_id == 0 ) {
      unique_id = ID_MONITOR->get_new_id();
   }

   query_file_name();
      // Sets my_file_name ... not strictly necessary, but allows you to
      // use the /data/ files as templates if need be.
   if( !environment() )
      save_location = 0;
   else
      save_location = to_objectref(environment());
   save_object(ID_MONITOR->get_save_file_name(unique_id));
   // TESTING
   DB->save_object( unique_id, save_object(0) );
}

/** In a saveload object, this is the same thing as save_self.
 */
void save_self_only() {
   save_self();
}

/** Frees up the unique ID being used by this object, unless
 * the world is busy being shut down.
 *
 * ... I commented this out, because I think it may be
 * causing problems. -- Acius
 */
string _destructor_saveload() {
   if( !"/obj/shut"->query_shutdown_in_progress() )
      ID_MONITOR->free_id( unique_id );
   return 0;
}

void set_unique_id( int x ) {
   if( unique_id ) ID_MONITOR->free_id( unique_id );
   unique_id = x;
   ID_MONITOR->check_id( unique_id );
}

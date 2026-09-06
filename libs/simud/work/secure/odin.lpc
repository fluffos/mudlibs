/** This object is named after Odin, the all-seeing god of Norse mythology.
 * It has a rather obscure but highly important job -- it keeps track of all
 * the saveload identification numbers for all the objects in the MUD. When
 * a new object is created, it is Odin's job to assign it a number and (using
 * the number) a spot in the file system where it can save itself.
 *
 * The original saveload system didn't work this way, but since I intend
 * to get rid of the old system as soon as this one is working, it doesn't
 * matter much how it worked.
 *
 * In theory, this object stores every Unique ID (a 32-bit integer used by
 * saveload to determine its filename). Every saveload object also knows
 * its unique ID once it has loaded itself. Since it would eat way too much
 * space to actually store every single unique ID, though (I'm aiming for
 * this MUDlib to handle tens of thousands of objects), it optimizes by only
 * storing *unused* unique ID's. This works well as long as all of the unique
 * ID's are within a known, densely populated range (such as 0-20,000, with
 * 95% used).
 *
 * The \a max_id is the highest known used ID (if there are no known used
 * ID's, then max_id is 0, which is an illegal unique ID). The zero-width
 * mapping \a unused_ids holds every unused ID between 0 and max_id.
 *
 * Odin does not save its data; it is regenerated during world-loading.
 * Since this process can't be duplicated after the MUD has started,
 * you will get an error if you try to destruct Odin before shutdown.
 * This is quite deliberate -- it is possible for two objects to get
 * confused and assign themselves the same save file, and it is possible
 * for an object to get destructed without notifying Odin that its
 * ID is now free. Regenerating the data on startup detects and fixes
 * both kinds of problems.
 *
 * Object data itself is stored under /data.
 */

#define MAX_ID_GROWTH 200000

/// A mapping of all the currently unused ID's that are less than max_id
mapping unused_ids;
/// The highest used unique ID
int max_id;

/// Initializes variables
create() {
   unused_ids = ([ ]);
   max_id = 0;
}

/** \return A mapping of the unused id's. This mapping is returned
 * as a copy.
 * \warning This call is very expensive. Only call it for debugging
 * reasons; you should never use this in normal code.
 */
mapping query_unused_ids() {
   return copy(unused_ids);
}

/** \return The current value of max_id. Mainly useful for debugging
 * or curiosity.
 */
int query_max_id() {
   return max_id;
}

/** Called by objects when they are created. This function allocates
 * a unique id for the object and returns it; no other object in the
 * game will have that id.
 */
int get_new_id() {
   int i;

   foreach( i : unused_ids ) {
      m_delete( unused_ids, i );
      return i;
   }

   return max_id++;
}

/** Frees up \a id, allowing it to be used by another object. This
 * function is called by objects when they are destructed.
 */
void free_id( int id ) {
   if( id <= 0 ) return;

   unused_ids += ([ id ]);

   while( member(unused_ids, max_id) ) {
      m_delete( unused_ids, max_id );
      max_id--;
   }
}

/** Called if someone tries to destruct odin. The destruct is only
 * permitted if the MUD is busy shutting down.
 */
string destructor() {
   if( !"/obj/shut"->query_shutdown_in_progress() )
      return "Odin may not be destructed except during shutdown.";
}

/** Used while the MUD is booting up. As each object loads, it calls
 * check_id to inform odin which id's are already in use. Odin thus
 * builds its database of id's from scratch.
 *
 * \return True, if the id really is unique. If a different object
 * had already allocated that id, it will be detected here, and this
 * function will return false; in this case, the object will ask for
 * a new id, and will be split off into a seperate data file.
 */
int check_id( int id ) {
   if( id <= 0 )
      return 0; // This ID is never legal.

   if( id > max_id ) {
      int i, count, *arr;

      if( id - max_id - 1 > MAX_ID_GROWTH ) {
         debug("Warning:  ID exceeds maximum");
      }
      arr = allocate( id - max_id - 1);
      for( i = sizeof(arr), count = id - 1; i--; count-- )
         arr[i] = count;

      unused_ids += mkmapping(arr);
      max_id = id;
      return 1;
   }

   if( member(unused_ids, id) ) {
      m_delete( unused_ids, id );
      return 1;
   }

   // Oops, this ID's used already!
   // I try to log this, so as to prevent further damage.
   log_file("bad_id", "The object " + as_string(previous_object()) + " had a duplicate ID: " + id + "\n" );
   return 0;
}

/** Added for debugging. Tells me if an ID is free or not.
 */
int query_id_free( int id ) {
   return member(unused_ids, id) || id > max_id;
}

/** \return The full file name to which the object identified by \a id
 * should save its data.
 */
string get_save_file_name( int id ) {
   string hexval;
   string dir;
   int temp, i;

   temp = id;
   if( !intp(id) )
      raise_error("The value '"+as_string(id)+"' is not a valid id.");
   hexval = "";
   for( i = 0; i < 8; i++) {
      hexval = "0123456789abcdef"[temp & 0xf..temp & 0xf] + hexval;
      temp >>= 4;
   }

   dir = "/data/" + hexval[<2..];
   if( file_size(dir) != -2 )
      mkdir(dir);

   return dir + "/" + hexval;
}

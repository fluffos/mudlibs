#include <sys/rtlimits.h>
#include <const.h>

#pragma no_clone

/** Dumps the data for a single object to a string.
 */
string dump_object_data( object ob ) {
   string data;
   int uid;
   object inv;

   uid = ob->query_unique_id();
   data = ob->get_stat();
   if( uid == 0 || !stringp(data) ) return "!obj 0 0\n";
   return "!obj " + uid + " " + (sizeof(explode(data, "\n")) - 1) + "\n" + data;
}

/** This function does the recursive legwork for full_save_object;
 * The actual fuil_save_object function adds a header, footer, and
 * initial values for the recursion.
 *
 * Note that objects which respond to query_is_player() are silently
 * ignored by this function. Objects which return 0 for get_stat()
 * are still saved, but without stats. Such objects are restored
 * in their default state.
 */
varargs void dump_object( string file, object ob, int indent ) {
   string s;
   object inv;

   // Silently ignore player objects; they have to fend for themselves.
   if( ob->query_is_player() ) return;

   s = tab("\t", indent) + load_name(ob) + "\n";
   write_file( file, s );
   write_file( file, dump_object_data(ob) );

   foreach(inv : all_inventory(ob))
      dump_object( file, inv, indent+1 );
}

/** Saves an object and all of its contents (deeply recursed) to
 * a file. We've been giving this file type a .obj extension. See
 * full_restore_object() to see how to undo this.
 */
void full_save_object( string file, object ob ) {
   rm(file);
   write_file(file, "!full_save_object\n");
   dump_object(file, ob);
   write_file(file, "!eof\n");
}

#define BUFFER_LEN 180000

/// Variable for file streaming
nosave string curr_buf, read_filename;
/// Variable for file streaming
nosave int file_pos, buf_pos, line_num;

/** Starts reading a file (similar to opening it as a stream). See
 * get_lines() for information about how to use this.
 */
void start_file( string fname ) {
   read_filename = fname;
   curr_buf = "";
   file_pos = 0;
   buf_pos = 0;
   line_num = 0;
}

/** This function is used to read in the .obj files. These files can
 * be very large (up to tens of megabytes is expected), which is far
 * to large for the MUD to handle in a single string. Additionally, the
 * MUD's read_file function is far too inefficient to handle a file of
 * this size.
 *
 * It is possible to write more efficient functions, and that's
 * precisely what this is. This function works around the concept of
 * a stream. You call start_file("filename") to begin reading from
 * it, then read it in by lines. So if you call get_lines(3), it will
 * return the first 3 lines of the file, separated by \n's. If you
 * call get_lines(3) again, it will return lines 4-6, and so on.
 *
 * Note that it's not particularly more efficient to read in a large
 * number of lines at once; it only touches the files when it has
 * to, and will always read the file in big chunks to keep things
 * fast.
 */
string get_lines( int line_count ) {
   string curr_lines = "";
   int iline, break_pos;

   if( !curr_buf ) {
//      msg("No buffer, returning 0");
      return 0;
   }

   for( iline = 0; iline < line_count; iline++ ) {
      // Wrap around end of buffer
      while( (break_pos = strstr(curr_buf, "\n", buf_pos)) == -1 ) {
         curr_lines += curr_buf[buf_pos..];
//         write("Buffer wrap: curr_lines += " + as_lpc(curr_buf[buf_pos..])+"\n");
         buf_pos = 0;
         file_pos += strlen(curr_buf);
         curr_buf = read_bytes( read_filename, file_pos, BUFFER_LEN );
         if( !curr_buf ) {
//            msg("Got line(s) (and EOF): " + as_lpc(curr_lines));
            return curr_lines; // End of file hit.
         }
//         write("Reading next buffer: " + as_lpc(curr_buf)+"\n");
      }
      // Read until next \n
      curr_lines += curr_buf[buf_pos..break_pos];
//      write("From current buffer: curr_lines += " + as_lpc(curr_buf[buf_pos..break_pos])+"\n");
      buf_pos = break_pos + 1;
   }
   if( !strlen(curr_lines) ) {
//      msg("Failed to get more lines, returning 0.");
      return 0;
   }
//   msg( "Got line(s): " + as_lpc(curr_lines));
   return curr_lines;
}

/** Tells which line of the file is to be read next by get_lines().
 * This function is mainly useful for reporting error messages (it'd
 * be a bit tough to find an error if we didn't give you some kind
 * of hint!).
 */
int get_line_num() {
   return line_num;
}

/** This function is used to restore an object saved with
 * full_save_object(). It's big, complex, and messy! The object
 * is returned after being restored. If force_uid is set to
 * true (for world loads, it is) then the unique ID's specified in the
 * file will be strictly conformed to. If it is not set to true,
 * then the system will assign new unique ID's on the fly, allowing
 * for object cloning. If you're making many copies of something,
 * force_uid must be false.
 *
 * As of this writing, this function CANNOT repair broken object
 * references caused by clearing force_uid; if you clone an
 * area this way, many exits will probably break.
 */
varargs object full_restore_object( string file, int force_uid ) {
   string curr_line;
   int depth;
   object base_ob, curr_ob, *allenv;
   mapping original_id = ([ ]);

   start_file( file );
   curr_line = get_lines( 1 );

   if( curr_line != "!full_save_object\n" ) raise_error("Invalid format in full_restore_object (bad header)");

   depth = 0;
   allenv = ({ });
   do {
      int new_depth;
      string file_name, file_data;
      int uid, nvar;

      // Read file name
      curr_line = get_lines( 1 );
      curr_line -= "\n";
      if( curr_line == "!eof" ) break; // Normal exit.
      // Verify sanity
      file_name = explode(curr_line, "\t")[<1] - "\n";
      new_depth = strlen(curr_line) - strlen(file_name);
      if( new_depth > depth )
         raise_error("Invalid format in full_restore_object: Depth increased by over 1, not possible (line " + get_line_num() + ")" );
      if( new_depth == 0 && sizeof(allenv) )
         raise_error("Invalid format in full_restore_object: Indent expected, not found (line " + get_line_num() + ")" );

      // Read in the file data
      curr_line = get_lines( 1 );
      if( sscanf(curr_line, "!obj %d %d", uid, nvar) != 2 )
         raise_error("Invalid format in full_restore_object: !obj <n> <n> expected. (line " + get_line_num() + ")" );
      if( nvar != 0 )
      file_data = get_lines( nvar );

      // Make the object
      curr_ob = 0;
      if( "/world/world" == file_name )
         curr_ob = load_object("/world/world");
      else
         catch( curr_ob = clone_object(file_name) );
      if( !curr_ob ) {
         log_file( "world", "Failed to load " + file_name + "\n" );
      }
      if( curr_ob && load_name(curr_ob) == "/world/maparea" )
         log_file("world", "Maparea loaded: " + as_lpc(curr_ob) + " (new_depth " + new_depth + ", depth " + depth + "), allenv="+as_lpc(allenv)+"\n");
      // If it's the first object, then it's the root object, which we return.
      if( !base_ob )
         base_ob = curr_ob;
      // Set its unique id
      if( curr_ob && force_uid ) curr_ob->set_unique_id( uid );
//      log_file("world", "After set_unique_id, curr_ob is " + as_lpc(curr_ob) + ", id is " + curr_ob->query_unique_id() + "\n" );
      // Climb the object tree to wherever I belong (based on indentation)
      while( depth > new_depth ) {
         if( curr_ob && (load_name(curr_ob) =="/world/maparea" || load_name(curr_ob) == "/world/world") )
            log_file("world", "ob="+as_lpc(curr_ob)+", depth="+depth+", new_depth="+new_depth+", allenv="+as_lpc(allenv)+"\n");
         depth--;
         allenv = allenv[..<2];
      }
//      log_file("world", "load_name is " + load_name(curr_ob)+"\n");
      if( load_name(curr_ob) == "/world/maparea" || load_name(curr_ob) == "/world/world"  )
         log_file("world", "ob="+as_lpc(curr_ob)+", depth="+depth+", new_depth="+new_depth+", allenv="+as_lpc(allenv)+"\n");
      // As long as we have an env, move me there (not true for base_ob ONLY)
      if( curr_ob && sizeof(allenv) ) {
         int ienv;
         if( load_name(curr_ob) =="/world/maparea" )
            log_file("world", "ob="+as_lpc(curr_ob)+", allenv="+as_lpc(allenv)+"\n");
         for( ienv = 1; ienv <= sizeof(allenv); ienv++ ) {
            if( objectp(allenv[<ienv]) ) {
               curr_ob->move(allenv[<ienv]);
               break;
            }
         }
         if( curr_ob && !environment(curr_ob) )
            log_file("world", "Failed to move " + as_lpc(curr_ob) + " ANYWHERE, allenv=" + as_lpc(allenv) + "\n" );
      }
      // Set myself as the next environment, and increment depth to reflect
      // having done this -- if the next object is next to me or above me,
      // it'll climb out, so this assumption works.
      allenv += ({ curr_ob });
      depth++;
      // Load variables.
      if( curr_ob )
         curr_ob->load_stat( file_data );
   } while( stringp(curr_line) );
   if( curr_line != "!eof" )
      raise_error( "Invalid format in full_restore_object: !eof tag missing." );

   return base_ob;
}

varargs string restore_sub_object( string file, string obj, int force_uid ) {
   string curr_line;
   int depth;
   object base_ob, curr_ob, *allenv;
   mapping original_id = ([ ]);

   start_file( file );
   curr_line = get_lines( 1 );

   if( curr_line != "!full_save_object\n" ) raise_error("Invalid format in full_restore_object (bad header)");

   depth = 0;
   allenv = ({ });
   do {
      int new_depth;
      string file_name, file_data;
      int uid, nvar;

      // Read file name
      curr_line = get_lines( 1 );
      curr_line -= "\n";
      if( curr_line == "!eof" ) break; // Normal exit.
      // Verify sanity
      file_name = explode(curr_line, "\t")[<1] - "\n";
      new_depth = strlen(curr_line) - strlen(file_name);
      if( new_depth > depth )
         raise_error("Invalid format in full_restore_object: Depth increased by over 1, not possible (line " + get_line_num() + ")" );
      if( new_depth == 0 && sizeof(allenv) )
         raise_error("Invalid format in full_restore_object: Indent expected, not found (line " + get_line_num() + ")" );

      // Read in the file data
      curr_line = get_lines( 1 );
      if( sscanf(curr_line, "!obj %d %d", uid, nvar) != 2 )
         raise_error("Invalid format in full_restore_object: !obj <n> <n> expected. (line " + get_line_num() + ")" );
      if( nvar != 0 )
      file_data = get_lines( nvar );

      // Make the object
      curr_ob = 0;
      if( "/world/world" == file_name )
         curr_ob = load_object("/world/world");
      else
         catch( curr_ob = clone_object(file_name) );
      if( !curr_ob ) {
         log_file( "world", "Failed to load " + file_name + "\n" );
      }
      if( curr_ob && load_name(curr_ob) == "/world/maparea" )
         log_file("world", "Maparea loaded: " + as_lpc(curr_ob) + " (new_depth " + new_depth + ", depth " + depth + "), allenv="+as_lpc(allenv)+"\n");
      // If it's the first object, then it's the root object, which we return.
      if( !base_ob )
         base_ob = curr_ob;
      // Set its unique id
      if( curr_ob && force_uid ) curr_ob->set_unique_id( uid );
//      log_file("world", "After set_unique_id, curr_ob is " + as_lpc(curr_ob) + ", id is " + curr_ob->query_unique_id() + "\n" );
      // Climb the object tree to wherever I belong (based on indentation)
      while( depth > new_depth ) {
//         if( curr_ob && (load_name(curr_ob) =="/world/maparea" || load_name(curr_ob) == "/world/world") )
//            log_file("world", "ob="+as_lpc(curr_ob)+", depth="+depth+", new_depth="+new_depth+", allenv="+as_lpc(allenv)+"\n");
         depth--;
         allenv = allenv[..<2];
      }
//      log_file("world", "load_name is " + load_name(curr_ob)+"\n");
//      if( load_name(curr_ob) == "/world/maparea" || load_name(curr_ob) == "/world/world"  )
//         log_file("world", "ob="+as_lpc(curr_ob)+", depth="+depth+", new_depth="+new_depth+", allenv="+as_lpc(allenv)+"\n");
      // As long as we have an env, move me there (not true for base_ob ONLY)
      if( curr_ob && sizeof(allenv) ) {
         int ienv;
         if( load_name(curr_ob) =="/world/maparea" )
            log_file("world", "ob="+as_lpc(curr_ob)+", allenv="+as_lpc(allenv)+"\n");
         for( ienv = 1; ienv <= sizeof(allenv); ienv++ ) {
            if( objectp(allenv[<ienv]) ) {
               curr_ob->move(allenv[<ienv]);
               break;
            }
         }
         if( curr_ob && !environment(curr_ob) )
            log_file("world", "Failed to move " + as_lpc(curr_ob) + " ANYWHERE, allenv=" + as_lpc(allenv) + "\n" );
      }
      // Set myself as the next environment, and increment depth to reflect
      // having done this -- if the next object is next to me or above me,
      // it'll climb out, so this assumption works.
      allenv += ({ curr_ob });
      depth++;
      // Load variables.
      if( curr_ob )
         curr_ob->load_stat( file_data );
   } while( stringp(curr_line) );
   if( curr_line != "!eof" )
      raise_error( "Invalid format in full_restore_object: !eof tag missing." );

   return base_ob;
}

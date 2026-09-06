#include <sys/rtlimits.h>
#include <const.h>

inherit "/world/area";

#pragma no_clone

/** This is the world object. All of the world is, eventually, somewhere
 * inside of it. The reason that we use a world object is to make the saveload
 * system a bit easier. The saveload (more specifically, the 'inven' component)
 * saves its own state, then sends a signal to each of the objects in its
 * inventory, causing them to save their states. This cascades down until the
 * whole world state is saved.
 *
 * There are other possible ways of handling this, but this one works pretty
 * well, so we're keeping it :).
 *
 * Note that the world may not be cloned; the master copy of the world object is
 * the one used.
 */

// This code is specialized stuff used for saving...

string dump_object_data( object ob ) {
   string data;
   int uid;
   object inv;

   uid = ob->query_unique_id();
   data = ob->get_stat();
   if( uid == 0 || !stringp(data) ) return "!obj 0 0\n";
   return "!obj " + uid + " " + (sizeof(explode(data, "\n")) - 1) + "\n" + data;
}

varargs void dump_object( string file, object ob, int indent ) {
   string s;
   object inv;

   // Silently ignore player objects; they have to fend for themselves.
   if( ob->query_is_player() ) return;

   s = tab("\t", indent) + load_name(ob) + "\n";
   if( !write_file(file, s) ) {
      raise_error("Save error");
   }
   if( !write_file(file, dump_object_data(ob)) ) {
      raise_error("Save error");
   }

   foreach(inv : all_inventory(ob))
      dump_object( file, inv, indent+1 );
}

void full_save_object( string file, object ob ) {
   rm(file);
   if( !write_file(file, "!full_save_object\n") ) {
      raise_error("Save error");
   }
   dump_object(file, ob);
   if( !write_file(file, "!eof\n") ) {
      raise_error("Save error");
   }
}

#define BUFFER_LEN 180000

nosave string curr_buf;
nosave int file_pos, buf_pos, line_num;
nosave string read_filename;

void start_file( string fname ) {
   read_filename = fname;
   curr_buf = "";
   file_pos = 0;
   buf_pos = 0;
   line_num = 0;
}

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

int get_line_num() {
   return line_num;
}

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
      /*if( curr_ob && load_name(curr_ob) == "/world/maparea" )
         log_file("world", "Maparea loaded: " + as_lpc(curr_ob) + " (new_depth " + new_depth + ", depth " + depth + "), allenv="+as_lpc(allenv)+"\n");*/
      // If it's the first object, then it's the root object, which we return.
      if( !base_ob )
         base_ob = curr_ob;
      // Set its unique id
      if( curr_ob && force_uid )
         curr_ob->set_unique_id( uid );
//      log_file("world", "After set_unique_id, curr_ob is " + as_lpc(curr_ob) + ", id is " + curr_ob->query_unique_id() + "\n" );
      // Climb the object tree to wherever I belong (based on indentation)
      while( depth > new_depth ) {
         /*if( curr_ob && (load_name(curr_ob) =="/world/maparea" || load_name(curr_ob) == "/world/world") )
            log_file("world", "ob="+as_lpc(curr_ob)+", depth="+depth+", new_depth="+new_depth+", allenv="+as_lpc(allenv)+"\n");*/
         depth--;
         allenv = allenv[..<2];
      }
//      log_file("world", "load_name is " + load_name(curr_ob)+"\n");
      /*if( load_name(curr_ob) == "/world/maparea" || load_name(curr_ob) == "/world/world"  )
         log_file("world", "ob="+as_lpc(curr_ob)+", depth="+depth+", new_depth="+new_depth+", allenv="+as_lpc(allenv)+"\n");*/
      // As long as we have an env, move me there (not true for base_ob ONLY)
      if( curr_ob && sizeof(allenv) ) {
         int ienv;
         /*if( load_name(curr_ob) =="/world/maparea" )
            log_file("world", "ob="+as_lpc(curr_ob)+", allenv="+as_lpc(allenv)+"\n");*/
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
      if( curr_ob ) {
         if( !stringp(file_data) )
            log_file( "world", "Object " + object_name(curr_ob) + " had invalid file_data: " + as_lpc(file_data) + "\n" );
         else
            curr_ob->load_stat( file_data );
      }
   } while( stringp(curr_line) );
   if( curr_line != "!eof" )
      raise_error( "Invalid format in full_restore_object: !eof tag missing." );

   return base_ob;
}


/** Returns the world's .o file in a string.
 */
string get_stat() {
   return save_object();
}

/** Tracks whether the world is in the middle of loading. Some objects might
 * have problems if they try to do something while the world is loading, so
 * this can be useful.
 */
nosave int load_in_progress;

/// Used when timing world saves
nosave int save_start_time;

/** Called from the constructor. A task that causes the world to save itself
 * every few hours (depending on the value of WORLD_SAVE_TIME in const.h).
 */
void world_timed_save() {
   string buf;
   object ob;

   catch( buf = "/world/savemsg"->query_message() );
   catch( AUDIO_DAEMON->sfx_mud("clocktickfast.wav") );
   if(!buf)
      buf = "Saving world state! Please wait, this may take a little while.";
   remove_call_out("world_timed_save");
   // Independently save all the players -- they otherwise might lose hours and hours
   foreach( ob : users() ) {
      mixed actions;
      if(!ob->query_env_var("Tnosave"))
         msg_object(ob, "[~CTITWorld~CDEF] ~CWRN"+buf+"~CDEF", 8);
      actions = ob->query_actions();
      ob->save_self();
      ob->set_actions( actions );
      // caching the save actions is just a test to see if saves are purging
      // the queue by accident somehow...
   }
   call_out("world_timed_save", WORLD_SAVE_TIME);
   call_out("save_self", 2 );
}

/// Save the world!
void save_self() {
//   debug("WORLD NOT SAVING. Please re-enable this as soon as the hard drive is happy again.");
   save_start_time = time();
// Turned off till loading works again, don't want to corrupt good data!
//   limited( (: ::save_self(); :), LIMIT_UNLIMITED, 0 );
   if( !find_object("/obj/bank") )
      debug( "Inventory bank seems to be MISSING. Please clone /obj/bank and put it in /world/world. Inventories are not currently being saved." );
   else
      "/obj/bank"->presave();
   // Make a backup of the old world save.
   if( file_exists("/world/world.obj") )
      rename( "/world/world.obj", "/world/world.obj.backup" );
   limited( (: full_save_object("/world/world.obj", this_object()) :), LIMIT_UNLIMITED, 0 );
   if( find_object("/obj/bank") )
      "/obj/bank"->postsave();
   call_out("report_delay",2);
   // Remove the backup.
   if( file_exists("/world/world.obj.backup") )
      rm( "/world/world.obj.backup" );
//   copy_file("/world/world.obj", "/world/backup/world-" + time() + ".obj");
}

/// Say how long the save actually took
void report_delay() {
   int time = time() - save_start_time - 2;
   string timestr = int_to_time(time);
   if(time > 59) {
      int now, five, ten;
      catch(sscanf(read_file("/proc/loadavg"),"%s %s %s ", now, five, ten));
      msg_all("[~CTITWorld~CDEF] Time elapsed: ~CTIT"+timestr+"~CDEF. "+
             "CPU Load: ~CTIT"+now+"~CDEF.");
   } else {
      if( time < 0 )
         timestr = "??? seconds";
      foreach( object ob : users() )
         if(!ob->query_env_var("Tnosave"))
            msg_object(ob, "[~CTITWorld~CDEF] Time elapsed: ~CTIT"+timestr+"~CDEF.");
   }
   catch( AUDIO_DAEMON->sfx_mud("clockchime1.wav") );
}

/** Allows you to check how long it will be until the world next saves itself.
 */
int query_world_timed_save() {
   return find_call_out("world_timed_save");
}

/** This overrides Inven::load_self, because unlike every other object, the
 * world is loaded *before* its unique_id is known. It thus has a constant unique_id
 * of 1. Since load_self requires a unique_id to be passed in, this function takes
 * a parameter, but it is ignored; the unique_id of the world is always assumed to be
 * 1.
 */
void load_self( int x ) {
   // If there's a backup save file, it means we crashed mid-save from a previous
   // attempt. Attempt to restore the backup.
   if( file_exists("/world/world.obj.backup") )
      rename( "/world/world.obj.backup", "/world/world.obj" );
   limited( (: full_restore_object("/world/world.obj", 1) :), LIMIT_UNLIMITED, 0 );
}

/// \return True, if the world is busy loading.
int query_load_in_progress() {
   return load_in_progress;
}

/** The constructor. This sets up the default state for the world object
 * and then has it load itself from disk by calling load_self().
 */
void create() {
   object update_ob;

   load_in_progress = 1;

   name = "world";
   // type = "world";
   // long = "You are standing in the world room.";
   // short = "The world room";
   // distant = "a world";
   // plural = "worlds";
   // look = "Please don't clone the world.";
   seteuid("world");
   load_object("/secure/master_security");
   call_out("world_timed_save", WORLD_SAVE_TIME);
   ::create();
   if( !find_object("/obj/bank") )
      // If the inventory bank exists somewhere, I assume the world
      // is already loaded and don't load myself.
      load_self( 1 );
   load_in_progress = 0;
}

/** Causes an error (cannot destruct) unless the MUD is busy shutting down.
 */
string destructor( object ob ) {
   if( ob = find_object("/bin/wiz/update") ) return ::destructor(ob);
   if( !"/obj/shut"->query_shutdown_in_progress() )
      return "Only the update command may destruct the world object.";
   return ::destructor(ob);
}

/** \return The string "world". Even if you try to set the name to something
 * else, this will force it back to being 'world', as this is considered
 * a sort of reserved word.
 */
string query_name() {
   name = "world";
   return ::query_name();
}

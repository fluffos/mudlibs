#include <object.h>
#include <const.h>

/**
 * A quick and nasty offline file editor by Acius
 *
 * Use fileout to spit a file out to your terminal window. When you see
 * the message telling you to push enter, turn on your telnet client's
 * logging ability and push enter. When the file is done, turn it off then
 * hit enter again. You could also block-copy from the telnet window.
 *
 * When you have finished editing your file, use the filein command to
 * upload (paste the file into your telnet window).
 *
 * Known bug: This doesn't work for downloading large files! Maybe in
 * version 2.0. The problem is that the string overloads.
 */

string io_catch;

// Prototypes here.
void fileout2();

/// The buffer used for holding a file-entry-in-progress.
string my_file;

/// Standard id(), name is "offedit"
object id(string str) { if( str == "offedit" ) return this_object(); return 0; }

/// \return "offedit"
string query_name() { return "offedit"; }

/// \return "an offline editor"
string query_distant() { return "an offline editor"; }

/// \return "the offline editor"
string query_specific() { return "the offline editor"; }

/// When they're being sent a file, postpone conversation stuff!
void catch_tell( string str ) {
   io_catch += str;
}

/// \return Ok to get
int on_get() {
   return MOVE_OK_FLAG;
}

/// \return Ok to drop
int on_drop() {
   return MOVE_OK_FLAG;
}

/// \return Ok to give
int on_give() {
   return MOVE_OK_FLAG;
}

/// Implements the 'fileout' verb; uses fileout2 and fileout3.
int fileout(string fname)
{
   int now;

   if(!fname) {
      msg("==> [Format] fileout [-now] <file name>");
      return 1;
   }
   if( fname[..4] == "-now " ) {
      now = 1;
      fname = fname[5..];
   }
   fname = this_player()->make_path_absolute(fname, this_player()->query_path());
   my_file = read_file(fname);
   if(!my_file) {
      notify_fail("==> [Error] File not found or is empty\n");
      return 1;
   }
   if( !now ) {
      write("==> [Offline Editor] Push ENTER to start sending of "+fname+"\n");
      add_interface( "fileout2", "" );
   }
   else {
      add_interface( "fileout2", "" );
      fileout2();
   }
   set_interface_catch( 1 );
   io_catch = "";
   return 1;
}

/// Prints whatever's in my_file; used by fileout.
void fileout2()
{
   if( strlen(my_file) > 4096 ) {
      write(my_file[..4095]);
      call_out( "fileout2", 2 );
      my_file = my_file[4096..];
   }
   else {
      write(my_file);
      shift_interface("fileout3", "");
      write("==> [Offline Editor] File send complete. Push Enter, and I'll return you to the MUD.\n");
   }
}

/// Prints a goodbye message, and drops the interface.
void fileout3()
{
   write( io_catch );
   drop_interface();
}

/// Name of the file to append
string append_file;

/// Implements the filein verb.
int filein(string filename)
{
   if(!filename) {
      msg("==> [Format] filein <filename>");
      return 1;
   }

   filename = this_player()->make_path_absolute(filename);
   if(!filename) {
      msg("==> [Error] Access denied");
      return 1;
   }
   if( file_exists(append_file) ) {
      msg("==> [Warning] That file already exists; This function will APPEND to it, not replace it.");
   }
   msg("==> [Offline Editor] Start your upload. When done type '~*' (Type ~* immediately to do nothing)");
   append_file = filename;
   add_interface("filein2", "");
   return 1;
}

/// A "reminder" of what to type when done pasting.
void remind_ts() {
   write("==> [Offline Editor] Don't forget, when finished type '~*'\n");
}

/// An accessory function for filein; reads in the file line-by-line.
void filein2(string line) {
   remove_call_out("remind_ts");
   call_out("remind_ts", 10);
   if(line == "~*") {
      write("==> [Offline Editor] Thank you, and good bye.\n");
      remove_call_out("remind_ts");
      drop_interface();
      return;
   }
   write_file(append_file, line+"\n");
}

/// Initializes the filein and fileout verbs which this object provides.
init()
{
   add_action("filein", "filein");
   add_action("fileout", "fileout");
}

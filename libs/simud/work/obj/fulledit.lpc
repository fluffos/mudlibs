#include <textdraw.h>
#include <keys.h>
#include <object.h>

/**
 * Hello, and welcome to my second attempt at a full screen text
 * editor. I'll explain it more if I get anywhere.
 */

// Prototypes.
/** Refreshes the editor. Only stuff that's changed (as marked by
 * a refresh flag) is modified.
 */
void do_refresh();
/// Redraws the information bar at the bottom of the screen.
void draw_info_bar();
/// Internal function to scroll screen vertically if necessary
void resolve_vertical_scroll();

// The text in the editor, naturally :-)
string *edited_text;
// A parallel array to edited_text, giving flag values for each line.
int *flags;

/// Name of the file/variable being edited.
string filename;

/// Height of the user's terminal window
int term_height;
/// Lookup the ANSI code (if any) and save it; avoids some ANSI parsing overhead from the MUD.
string title_color, text_color, ans_ceol;

/// Refresh flags; indicates what needs refreshing.
int refresh_scroll, refresh_line, refresh_status;

/// Is the file read-only?
int read_only;
/// Has the file been modified?
int file_modified;

/// Used for storing cursor position.
int cursorx, cursory;
int left_col;
/// Remember if the variable type queried was a string or not.
int string_format;

/// Text edited in an object.
string keybuf;
/// Terminal settings
int width, height, linenum, total_lines, bottom_line;

/// Buffer for received messages at bottom;
string *termbuf;

object caller;      ///< Name of the object who requested editing service.
string return_func; ///< Name of the function to be called when finished.

/// Number of spaces per tab.
int tab_size;

/// Initialization code.
void create() {
   keybuf = "";
   term_height = 5;
   width = 79;
   height = 24;
   termbuf = ({ });
   bottom_line = height - 1;
   tab_size = 3;
   ::create();
}

void on_suspend() {
   destruct(this_object());
}

/** Called by the sefun string_edit in order to initialize the returning
 * of a string to an object. Passing this function invalid values
 * will cause an error later on.
 */
void init_return( object ob, string func ) {
   caller = ob;
   return_func = func;
}

/// Used for debug
string *query_termbuf() {
   return termbuf;
}

/** Exits this editor by dropping the interface & destructing.
 * If a return value was desired, it will be passed back before
 * the call to destruct is made.
 */
void exit_editor() {
   drop_interface();
   gotoxy( 1, this_player()->query_term_height() );
   msg_bare("~CDEF\n");
   if( caller && return_func )
      caller->return_func( implode( termbuf, "\n" ) );
   destruct( this_object() );
}

/// Returns index of currently edited line
int curr_line() {
   return linenum + cursory - 1;
}

/** Used to catch incoming messages. These will be printed in the
 * small "terminal area" below the status line. This is so that
 * incoming messages don't clobber the file you're editing.
 */
void catch_tell( string data ) {
   if( !data || data == "" ) data = "BLANK";
   if( sizeof(termbuf) != term_height )
      refresh_status = 1;
   termbuf = add_text( termbuf, data, width, term_height );
   draw_terminal( termbuf, 1, height-sizeof(termbuf)+1, environment(this_object()) );
   bottom_line = height - sizeof(termbuf) - 1;
}

/// Used for printing out informational messages. A \\n is implied.
void editor_message( string str ) {
   catch_tell(process_string("~CDEF[~CLABEditor~CDEF] "+str+"\n"));
}

/// Internal function to scroll screen sideways if necessary.
resolve_sideways_scroll() {
   while( cursorx > width ) {
      left_col += width / 3;
      cursorx -= width / 3;
      refresh_scroll = 1;
   }
   while( cursorx < 1 ) {
      left_col -= width / 3;
      cursorx += width / 3;
      if( left_col < 0 ) left_col = 0;
      refresh_scroll = 1;
   }
}

void resolve_vertical_scroll() {
   int i;

   if( cursory + linenum < 1 ) cursory = 1 - linenum;
   if( cursory + linenum >= total_lines ) cursory = total_lines - linenum;
   while( cursory > bottom_line ) {
      linenum += bottom_line / 3;
      cursory -= bottom_line / 3;
      refresh_scroll = 1;
   }
   while( cursory < 1 ) {
      i = bottom_line / 3;
      if( linenum - i < 0 ) i = linenum;
      linenum -= i;
      cursory += i;
      refresh_scroll = 1;
   }
}

/// Called to "type" a character into the editor. Modifies buffer, etc.
void type_char( string c ) {
   int rc, rl;

   file_modified = 1;

   rc = cursorx + left_col - 1;
   rl = cursory + linenum - 1;

   if( rc == 0 ) {
      edited_text[rl] = c + edited_text[rl];
      refresh_line = 1;
   }
   else if( rc > strlen(edited_text[rl]) ) {
      edited_text[rl] += tab(" ", rc - strlen(edited_text[rl]));
      edited_text[rl] += c;
      msg_bare( c );
   } else {
      edited_text[rl] =
         edited_text[rl][0..rc-1] + c + edited_text[rl][rc..];
      refresh_line = 1;
   }
   cursorx++;
   resolve_sideways_scroll();
}

/// Called whenever the "backspace" key is pressed.
void do_backspace() {
   int rc, rl, i;

   rc = cursorx + left_col - 1;
   rl = cursory + linenum - 1;

   if( rc == 0 ) {
      if( rl <= 0 ) return;
      cursorx = strlen( edited_text[rl - 1] ) + 1 - left_col;
      cursory--;
      resolve_sideways_scroll();
      resolve_vertical_scroll();
      edited_text[rl - 1] += edited_text[rl];
      edited_text = edited_text[..rl-1] + edited_text[rl+1..];
      flags = flags[..rl-1] + flags[rl+1..];
      refresh_scroll = 1;
      total_lines--;
   }
   else {
      // Past end-of-line backspace
      if( rc > strlen(edited_text[rl]) ) cursorx--;
      else {
         // Normal mid-line backspace
         if( rc == 1 ) edited_text[rl] = edited_text[rl][1..];
         else
            edited_text[rl] = edited_text[rl][..rc - 2] + edited_text[rl][rc..];
         cursorx--;
         if( cursorx == strlen(edited_text[rl]) + 1 && cursorx != 2)
            msg_bare( text_color + "\b " );
         else
            refresh_line = 1;
      }
   }
   file_modified = 1;
}

/// Called whenever "Enter" is pushed.
void do_enter() {
   int rc, rl, i;

   rc = cursorx + left_col - 1;
   rl = cursory + linenum - 1;

   if( rc == 0 ) {
      if( rl <= 0 ) {
         edited_text = ({ "" }) + edited_text;
         flags = ({ 0 }) + flags;
      }
      else {
         flags = flags[..rl-1] + ({ 0 }) + flags[rl..];
         edited_text = edited_text[..rl-1] + ({ "" }) + edited_text[rl..];
      }
   }
   else if( rc >= strlen(edited_text[rl]) ) {
      flags = flags[..rl] + ({ 0 }) + flags[rl+1..];
      edited_text = edited_text[..rl] + ({ "" }) + edited_text[rl+1..];
   }
   else {
      if( rl == 0 ) {
         flags = ({ flags[0] }) + ({ 0 }) + flags[1..];
         edited_text = ({ edited_text[0][0..rc-1] }) + ({ edited_text[0][rc..] }) + edited_text[1..];
      }
      else {
         flags = ({ flags[..rl-1] }) + ({ 0 }) + flags[rl..];
         edited_text = edited_text[0..rl-1] + ({ edited_text[rl][0..rc-1] }) + ({ edited_text[rl][rc..] }) + edited_text[rl+1..];
      }
   }
   cursory++;
   total_lines++;
   cursorx = 1 - left_col;
   resolve_sideways_scroll();
   resolve_vertical_scroll();
   refresh_scroll = 1;
   file_modified = 1;
}

/// Draws the editing field (the text edited)
void draw_text() {
   int i;

   gotoxy( 1, 1 );
   msg_bare(text_color);
   for( i = 0; i < bottom_line; i++ )
   if( i + linenum < total_lines )
      write( edited_text[i+linenum][left_col..left_col+width-2] + ans_ceol + "\n" );
   else
      write( ans_ceol + "\n" );
   refresh_scroll = 0;
}


/// Redraws a single line of the editing field.
void draw_line() {
   msg_bare( text_color );
   gotoxy( 1, cursory );
   if( cursory + linenum - 1 < total_lines )
      write( edited_text[cursory+linenum-1][left_col..left_col+width-2] + ans_ceol + "\n" );
   else
      write( ans_ceol + "\n" );
   refresh_line = 0;
}

void draw_info_bar() {
   string info_text;

   // Draw the information bar
   info_text = title_color + " Acius's Editor   Line: " +
      pad((string)(cursory + linenum), 5, 0) + "  Column: " +
      pad((string)(cursorx + left_col), 5, 0) +
      "[Ctrl+B] menu  " +
      (file_modified?"M":"") +
      (read_only?"R":"") + "   ";

   gotoxy( 1, bottom_line + 1 );
   tell_object( environment(this_object()), info_text );
   gotoxy( cursorx, cursory );
}

void do_refresh() {
   // Update cursor pos.
   if( refresh_scroll ) draw_text();
   if( refresh_line ) draw_line();
   if( refresh_status ) {
      // Blank out the status bar (works for lazy CEOL ANSI implementations)
      gotoxy( 1, bottom_line + 1 );
      tell_object( environment(this_object()), title_color + tab(" ", width) );
      draw_info_bar();
      remove_call_out("draw_info_bar");
      refresh_status = 0;
   }
   // Status is always refreshed, refresh_status just
   // determines whether it happens on a timer or not.
   else if( find_call_out("draw_info_bar") < 0 )
      call_out("draw_info_bar", 0);
   gotoxy( cursorx, cursory );
}

void full_refresh() {
   // Clear the screen
   msg_bare("~CLRS");

   // Do a complete refresh
   refresh_scroll = 1;

   // Completely redraw the status bar.
   refresh_status = 1;

   draw_terminal( termbuf, 1, bottom_line + 2, environment(this_object()) );

   do_refresh();
}

void load_file( string fname ) {
   string s, obname, var, param;

   if( !fname || fname == "" ) {
      editor_message("Load aborted.");
      return;
   }

   if( sscanf(fname, "%s->%s", obname, var) == 2 ) {
      object ob;

      s = "";
      ob = "/obj/wizard"->find_thing(obname);
      if( ob ) {
         if( sscanf(var,  "%s(%s)%~s", var, param) == 3 )
            s = call_other( ob, "query_" + var, param );
         else
            s = call_other( ob, "query_" + var );
         string_format = stringp(s);
         if( !string_format && s == 0 ) {
            string_format = 1;
            s = "<No value>";
         }
         if( !string_format )
            s = as_lpc( s );
         read_only = !function_exists( "set_" + var, ob );
      }
      else s = "No such object -- "+obname+".";
   }
   else {
      fname = this_player()->make_path_absolute( fname );
      if( !file_exists(fname) ) {
         s = "";
         read_only = !query_write_access(fname, this_player());
      }
      else {
         s = read_bytes( fname, 0, file_size(fname) );
         if( !stringp(s) ) s = "";
         read_only = !query_write_access(fname, this_player());
      }
   }
   if( read_only )
      editor_message("Warning: This file is read-only.");
   // Quick check for "illegal" chars.
   s = implode( explode(s, "\r"), "");
   s = implode( explode(s, "\t"), tab(" ", tab_size));
   edited_text = explode( s, "\n" );
   flags = allocate( sizeof(edited_text) );
   total_lines = sizeof( edited_text );
   filename = fname;
   file_modified = 0;
}

void save_file( string fname ) {
   string var, obname, param;
   mixed s;

   if( fname == "" ) {
      editor_message("No file name was entered, save aborted.");
      return;
   }
   if( !fname ) fname = filename;
   if( sscanf(fname, "%s->%s", obname, var) == 2 ) {
      object ob;

      ob = "/obj/wizard"->find_thing(obname);
      if( string_format ) {
         int x;
         s = implode(edited_text, "\n");
         x = to_int(s);
         if( !query_to_int_fail() )
            s = as_lpc( x );
         else
            s = as_lpc( s );
      }
      else s = implode( edited_text, "\n" );
      if( ob ) {
         if( sscanf(var, "%s(%s)%~s", var, param) == 3 )
            "/obj/wizard"->exec_code( "object ob;\n" +
               "ob = find_object(\"" + object_name(ob) + "\");" +
               "ob->set_" + var + "( \"" + param + "\", " + s + " );" );
         else
            "/obj/wizard"->exec_code( "object ob;\n" +
               "ob = find_object(\"" + object_name(ob) + "\");" +
               "ob->set_" + var + "( " + s + " );" );
         if( !function_exists("set_" + var, ob ) )
            editor_message("Warning: set_"+var+" function in "+object_name(ob)+"doesn't exist, so value is not set.");
         else {
            editor_message("Called set_"+var+" in "+object_name(ob)+" with the buffer as a parameter.");
            file_modified = 0;
         }
      }
   }
   else {
      fname = this_player()->make_path_absolute( fname );
      if( !query_write_access(fname, this_player()) )
         editor_message("This file is read-only for you! Save it under a different name.");
      else {
         rm( fname );
         write_file( fname, implode(edited_text, "\n"));
         editor_message("Saved edit buffer to "+fname);
         file_modified = 0;
      }
   }
}

/// Start editing!
void start_edit( string fname ) {
   if( fname ) load_file( fname );
   if( !this_player()->query_ansi() ) {
      msg("You cannot use this text editor without turning ansi on.\n");
      return;
   }
   title_color = process_string("~[007", 0);
   text_color = process_string("~[070", 0);
   ans_ceol = process_string("~CEOL", 0);
   cursory = 1;
   cursorx = 1;
   linenum = left_col = 0;
   add_interface("@keypress", 0);
   set_interface_catch( 1 );
   gotoxy(cursorx, cursory);
   width = this_player()->query_term_width();
   height = this_player()->query_term_height();
   term_height = height / 5;
   bottom_line = height - 1;
   termbuf = ({ });
   full_refresh();
   keybuf = "";
}

/** Inputs a string in a mini-editor
 * \param prompt The prompt to write at the top of the input box.
 * \param finish_to The function to call when input has finished.
 * The input will be passed to the function as a string.
 * \param box_width The width of the input box in characters.
 * Use the global variable width.
 * \param initial_text (Optional) The text initially in the
 * edit box, which may be edited.
 */
varargs void input_box( string prompt, string finish_to, int box_width, string initial_text ) {
   if( !initial_text ) initial_text = "";
   drawbox( width / 2 - box_width / 2 - 2, height / 2 - 2, box_width + 4, 4, "~[007" );
   gotoxy( width / 2 - box_width / 2, height / 2 - 1 );
   write( prompt );
   line_input( width / 2 - box_width / 2, box_width, height / 2, 0, finish_to, initial_text );
}

void issue_command( string str ) {
   string err;

   msg("~CDEF");
   err = catch(command(str, this_player()));
   if( err )
      editor_message("Error in command: "+err);
   if( this_player()->query_interface() == this_object() ) {
      refresh_scroll = 1;
      do_refresh();
   }
}

void mainmenu( string str );

/// The last string searched for, used for "search for next..."
string last_search;

void search_for_text( string text ) {
   int pos, rc, rl;

   rc = cursorx + left_col; // Would be - 1, but I want it to skip the one under cursor.
   rl = cursory + linenum - 1;
   last_search = text;

   // Loop through till we find either the text or EOF
   while( rl < total_lines ) {
      pos = strstr(edited_text[rl], text, rc);
      if( pos >= 0 ) {
         rc = pos;
         break;
      }
      rl++;
      rc = 0;
   }
   if( rl < total_lines ) {
      cursorx = rc - left_col + 1;
      cursory = rl - linenum + 1;
      resolve_vertical_scroll();
      resolve_sideways_scroll();
   }
   else
      editor_message("No more matches to find.");
   refresh_scroll = 1;
   do_refresh();
   shift_interface("@keypress", 0);
}

void goto_line( string line_num ) {
   int n;

   n = to_int( line_num );
   if( query_to_int_fail() )
      editor_message("Invalid line number.");
   else {
      cursory = n - linenum;
      resolve_vertical_scroll();
   }
   refresh_scroll = 1;
   do_refresh();
   shift_interface("@keypress", 0);
}

void do_load( string name ) {
   load_file( name );
   shift_interface("@keypress", 0);
   full_refresh();
}

void do_save( string name ) {
   save_file( name );
   shift_interface("@keypress", 0);
   full_refresh();
}

/// Interface handler for the main menu.
void mainmenu(string str) {
   int corner;

   if( find_call_out("draw_info_bar") >= 0 ) {
      remove_call_out("draw_info_bar");
      draw_info_bar();
   }

   if( str == "q" ) {
      exit_editor();
      return;
   }
   if( str == "s" ) {
      save_file(0);
      str = 0;
   }
   if( str == "a" ) {
      editor_message("filename = "+filename);
      input_box("Enter New File/Variable Name:", "do_save", width * 3 / 4, filename );
   }
   if( str == "f" ) {
      input_box("Enter Search String:", "search_for_text", width * 3 / 4 );
   }
   if( str == "g" ) {
      input_box("Enter Line Number:", "goto_line", width / 2 );
   }
   if( str == "\n" || str == "\r" ) {
      shift_interface("@keypress", 0);
      full_refresh();
      return;
   }
   if( str == "l" ) {
      input_box("What file to load?", "do_load", width * 3 / 4, filename );
   }
   if( !str ) {
      // Draw the main menu
      corner = width / 2 - 25;

      drawbox( corner, 3, 50, 12, "~[157" );
      gotoxy( corner + 2, 4); msg_bare("~[127MAIN MENU");
      gotoxy( corner + 1, 5); msg_bare("~[007" + tab("-", 48) );
      gotoxy( corner + 2, 6); msg_bare("[l] Load buffer...");
      gotoxy( corner + 2, 7); msg_bare("[s] Save buffer");
      gotoxy( corner + 2, 8); msg_bare("[a] Save as...");
      gotoxy( corner + 2, 9); msg_bare("[f] Find text...");
      gotoxy( corner + 2, 10); msg_bare("[g] Goto line...");
      gotoxy( corner + 2, 11); msg_bare("[q] Quit");
      gotoxy( corner + 2, 12); msg_bare("[Enter] Exit menu");
      msg_bare("~[070");
   }
}

/** Takes input one character at a time and generates events from it.
 * This is the interface handler for the editor.
 */
void keypress( string c ) {
   int comm_code, i;


   if( !c ) {
      full_refresh();
      return;
   }

   keybuf += c;
   comm_code = this_player()->translate_code( keybuf );

   if( comm_code != KEY_NONE ) {
      if( comm_code == KEY_UP ) {
         cursory--;
         resolve_vertical_scroll();
      }
      if( comm_code == KEY_LEFT && cursorx + left_col > 1 ) {
         cursorx--;
         resolve_sideways_scroll();
      }
      if( comm_code == KEY_RIGHT || comm_code == KEY_DELETE ) {
         cursorx++;
         resolve_sideways_scroll();
      }
      if( comm_code == KEY_DOWN) {
         cursory++;
         resolve_vertical_scroll();
      }
      if( comm_code == KEY_PGDN ) {
         if( linenum < total_lines - bottom_line ) {
            linenum += bottom_line / 2;
            refresh_scroll = 1;
         }
         else
            cursory = total_lines - linenum;
      }
      if( comm_code == KEY_PGUP ) {
         if( linenum > 0 ) {
            linenum -= bottom_line / 2;
            if( linenum < 0 ) linenum = 0;
            refresh_scroll = 1;
         }
         else
            cursory = 1;
      }
      if( comm_code == KEY_END ) {
         cursorx = strlen( edited_text[curr_line()] ) + 1 - left_col;
         resolve_sideways_scroll();
      }
      if( comm_code == KEY_HOME ) {
         cursorx = 1 - left_col;
         resolve_sideways_scroll();
      }
      if( comm_code == KEY_BACKSPACE || comm_code == KEY_DELETE ) {
         do_backspace();
         resolve_sideways_scroll();
      }
      if( comm_code == KEY_CR ) {
         do_enter();
      }
      if( comm_code == KEY_F1 || comm_code == KEY_CTRL_B ) {
         mainmenu( 0 );
         shift_interface("@mainmenu", 0);
         keybuf = "";
         return;
      }
      if( comm_code == KEY_F2 || comm_code == KEY_CTRL_D ) {
         input_box( "Enter MUD command to execute:", "issue_command", width * 3 / 4 );
         keybuf = "";
         return;
      }
      if( comm_code == KEY_F3 || comm_code == KEY_CTRL_L ) {
         if( last_search )
            search_for_text( last_search );
      }
      if( comm_code == KEY_TAB ) {
         type_char(" ");
         while( (cursorx - 1) % tab_size != 0 ) type_char(" ");
      }
      if( comm_code == KEY_UNKNOWN ) keybuf = keybuf[1..];
      keybuf = "";
      if( comm_code == KEY_CTRL_Y ) {
         int rl, rc;

         rc = cursorx + left_col - 1;
         rl = cursory + linenum - 1;

         if( rl < total_lines - 1 ) {
            cursorx = 1 - left_col;
            resolve_sideways_scroll();
            resolve_vertical_scroll();
            edited_text = edited_text[..rl-1] + edited_text[rl+1..];
            flags = flags[..rl-1] + flags[rl+1..];
            refresh_scroll = 1;
            total_lines--;
         }
      }
   }
   else {
      if( keybuf[0] < 32 || keybuf[0] > 127 ) return;
      type_char( keybuf );
      keybuf = "";
   }
   do_refresh();
}

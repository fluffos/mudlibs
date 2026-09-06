#include <keys.h>
#include <const.h>

/// A helper object for the keysetup verb.
/** Call the setup function in this object to start an interface.
 * It should be cloned and moved inside the user's player object
 * before being invoked (there is a slight risk of conflict if
 * two players attempt to use it at once from the master copy).
 *
 * From the help: Different MUD and telnet clients use a wide variety of special codes to
 * represent different keys on your keyboard. When using certain parts of the
 * MUD, like the full screen text editor, the MUD needs to know what these codes
 * are. The MUD will understand a lot of the standard codes, but your
 * client may have some special codes we don't know about. This object
 * lets you type in those codes, so that your keyboard settings will work
 * properly.
 */

/// Call this function to start the keyboard setup interface.
setup() {
   add_interface("key_menu", "[Keyboard setup | ? for Help] ");
}

/// A string used to build up the code as characters are received one at a time.
string curr_code;
int curr_key;

/// Prints a pretty list of available keys (with indices) to the player.
void write_key_list() {
   int i, tot;
   string buf, curr;

   buf = "~[100";

   tot = 0;
   for( i = 0; i < MAX_KEY_INDEX; i++ )
   if( KEY_NAMES[i] ) {
      tot++;
      buf += pad( "" + i + "." + KEY_NAMES[i], 20, JUST_LEFT );
      if( tot % (this_player()->query_term_width() / 20) == 0 ) buf += "\n";
   }
   buf += "~CDEF\n";
   msg_bare(buf);
}

void write_custom_keys() {
   int i, j, tot;
   string buf, curr, str;

   buf = "~[100";

   tot = 0;
   foreach( curr, i : this_player()->query_key_codes() ) {
      tot++;
      str = "[" + i + "]: ";
      for( j = 0; j < strlen(curr); j++ )
         str += "" + curr[j] + ".";
      buf += pad( str, 20, JUST_LEFT );
      if( tot % (this_player()->query_term_width() / 20) == 0 ) buf += "\n";
   }
   buf += "~CDEF\n";
   if( tot == 0 )
      msg("==> [Notice] You have no custom key settings.");
   else
      msg_bare(buf);
}

void get_code( string key ) {
   if( key[0] == 13 || key[0] == 10 ) {
      if( strlen( curr_code ) > 0 ) {
         this_player()->add_key_code( curr_key, curr_code );
         msg_bare("\nKey set!\n");
      }
      else {
         msg_bare("\nNo codes were sent! If you pushed the key, try a different client!\n");
      }
      drop_interface();
      return;
   }

   if( curr_code == "" )
      msg_bare("(Push ENTER after entering code) Data received: ");

   msg_bare( "<" + efun::to_string(key[0]) + "> " );

   curr_code += key;

   if( strlen( curr_code ) > 8 ) {
      msg_bare("Escape sequence too long! Starting over.\n");
      curr_code = "";
      return;
   }
}


void key_menu(string s) {
   int i;

   if( !s ) return;
   if( s == "q" ) {
       drop_interface();
       destruct( this_object() );
       return;
   }
   if( s == "?" ) {
      msg("Different MUD and telnet clients use a wide variety of special codes to " +
         "represent different keys on your keyboard. When using certain parts of the " +
         "MUD, like the full screen text editor, the MUD needs to know what these codes " +
         "are. The MUD will understand a lot of the standard codes, but your " +
         "client may have some special codes we don't know about. This object " +
         "lets you type in those codes, so that your keyboard settings will work " +
         "properly.\n\n" +
         "Commands in keyboard setup are:\n" +
         " l - Give a list of all the keys that can be set up\n" +
         " k - Show all my custom key settings\n" +
         " s # - Set up the #'th key (customizing it for your keyboard)\n" +
         " r # - Removes any custom key codes for the #'th key.\n" +
         " r! - Removes ALL custom key codes for this player.\n" +
         " q - Leave keyboard setup\n");
   }
   if( s == "l" ) {
      write_key_list();
   }
   if( s == "k" ) {
      write_custom_keys();
   }
   if( s == "r!" ) {
      this_player()->clear_key_codes();
      msg("All customized keyboard settings cleared.");
   }
   if( sscanf(s, "s %d", i) == 1 ) {
      if( !KEY_NAMES[i] ) {
         msg("==> [Error] Not a valid key number. Use 'k' to get a list.");
         return;
      }
      msg_bare("==> [Keysetup] Setting up key '" + KEY_NAMES[i] + "'.\n");
      msg_bare("Push the key on your keyboard, then push Enter.\n");
      curr_key = i;
      curr_code = "";
      add_interface( "@get_code", 0 );
   }
   if( sscanf(s, "r %d", i) == 1 ) {
      if( !KEY_NAMES[i] ) {
         msg("==> [Error] Not a valid key number. Use 'k' to get a list.");
         return;
      }
      msg_bare("==> [Keysetup] Removing any custom settings for '" + KEY_NAMES[i] + "'.\n");
      this_player()->remove_key_code( i );
   }
}

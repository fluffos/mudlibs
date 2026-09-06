#include <const.h>
#include <reports.h>
#include <textdraw.h>

/* Executes the "help" command. Searches for the
 * file <str>.hlp in all of the directories given in the
 * help_paths environment variable and, if found,
 * formats the file and dumps it to the player's terminal.
 * \param str The topic you want help about.
 */
int main( string str ) {
  string temp, u_str;
  int pathloop;
  string * help_paths;

  // return notify_fail("The database server is giving us troubles, please use the web page to report this "+query_verb()+".\n");

  help_paths = ({ "/help" });
  if( this_player()->query_level() >= WIZLEVEL ) help_paths += ({ "/help/wiz" });

  if(!str) str = "main";
  u_str = implode( explode(str, " "), "_" );
  for(pathloop = 0; pathloop < sizeof(help_paths); pathloop++) {
     temp = read_file(help_paths[pathloop]+"/"+u_str+".hlp");
     if(temp) break;
  }
  if(!temp) {
     msg("==> [Nohelp] Ok, we've added that topic to our list. Thanks.");
#ifdef __MYSQL__
      temp = "No help for topic \"" +
         str + "\".";

     FORUM->create_new_thread( NOHELP_BOARD_ID, get_location(environment(this_player())), str, temp );
#endif
     log_file( "nohelp", "Posted a nohelp: "+str+"\n" );
     return 1;
  }
  if( temp[0] == '!' ) {
     temp = temp[1..];
     while( temp[<1] == '\n' || temp[<1] == ' ' ) temp = temp[..<2];
     if( temp[<4..<1] != ".hlp" ) temp += ".hlp";
     temp = read_file( temp );
  }

  if( !temp )
     msg("That help file exists, but has a broken reference. Please file a typo.");
  else
     msg("Um, actually, there is help on that topic. Check. If the help is wrong, or outdated, use the 'typo' command instead.");
  return 1;

}

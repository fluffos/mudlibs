/* shadow for OCprisoners  *
 * Coded by Laffs 22/04/99 */

#include <move_failures.h>

inherit "/std/effect_shadow";

int command_shadowed( string verb, string args ) {
  int tells;
  string *tokenargs;
  if ( verb == "shout" ) {
    write( "You feel too depressed to shout.\n" );
    return 1;
  }
  if ( ( verb == "chat" ) ||
       ( verb == "one" ) ||
       ( verb == "two" ) ||
       ( verb == "thieves" ) ||
       ( verb == "assassins" ) ||
       ( verb == "warriors" ) ||
       ( verb == "witches" ) ||
       ( verb == "wizards" ) ||
       ( verb == "apex" ) ||
       ( verb == "a'tuin" ) ||
       ( verb == "intermud" ) ||
       ( verb == "sek" ) ||
       ( verb == "gapp" ) ||
       ( verb == "gufnork" ) ||
       ( verb == "sandelfon" ) ||
       ( verb == "pishe" ) ||
       ( verb == "hat" ) ||
       ( verb == "fish" ) ||
       ( verb == "playerkillers" ) ) {
    write( "The eyes feel too depressed to relay your message.\n" );
    return 1;
  }
  if ( ( verb == "tell" ) ||
       ( verb == "t" ) ||
       ( verb == "gchat" ) ) {
    tells = this_player()->query_property("tell block");
    if( tells >= 3 ) {
      write("You seem to have used up all your tells.\n");
      return 1;
    }
    if( tells <= 2 ) {
       
       tokenargs = explode (args, " ");
       
       if (!find_player(this_player()->expand_nickname(lower_case(tokenargs[0]))))
       {
        
                tell_object(this_player(), "That person does not seem to "
                        "be available to contact.\n");
                return 1;
        }
        
      
      tells++;
      tell_object(this_player(),
        "You have used "+query_num(tells)+" \"tell\" "
        "command"+(tells == 1 ? "" : "s")+" and you only get "
        "three, so make them count.\n");
      this_player()->add_property("tell block", tells);
      return player->command_shadowed( verb, args );
    }
    write("You have used your three allowed tells.\n");
    this_player()->remove_property("tell block");
    return 1;
  }
  if ( verb == "circle" ) {
    write( "There isn't enough room to draw a circle.\n" );
    return 1;
  }
  if ( verb == "erect" ) {
    write( "You can't decide where to erect it and soon give up.\n" );
    return 1;
  }
  return player->command_shadowed( verb, args );
} /* command_shaowed() */

varargs int move( mixed dest, string msgin, string msgout ) {
  int flag;
  flag = (int)player->move( dest, msgin, msgout );
  if ( flag == MOVE_OK )
    remove_this_effect();
  return flag;
} /* move() */

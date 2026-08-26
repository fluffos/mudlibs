/**
 * Arrested shadow
 * @author Terano
 * @started 20/5/00
 * Will stop object using any commands except for kill/attack [and only for the guard]
 */

#include <living.h>

int command_shadowed( string command, string args );
void remove_arrested_shadow();
void move_to_guard();

object guard;
object player;

void setup_shadow( object ob, object _guard ) {
  shadow( ob );
  guard = _guard;
  player = ob;
  tell_object( ob, "You are now being restrained by "+ 
    guard->the_short() + ".\n" );
}

int command_shadowed( string command, string args ) {
int temp;

  if ( member_array( command, environment( player )->query_exits() ) != -1 ) 
    return 1;

  //So guard can react. If the function returns 1, it means the behavior is 
  //allowed, if it returns -1, it means it isn't allowed. Either way, 
  //messaging has been handled.
  if ( temp = guard->register_behavior( player, command, args ) ) {
    if ( temp == 1 )
      return 0;
    else return 1;
  }
    
  switch( command ) {
    case "'":
    case "say":
    case "lsay":
    case "shout":   
    case "group":
    case "t":
    case "tell":
    case "l":
    case "look":
    case "glance":
    case "stop":
    case "call":
    case "destruct":
    case "cre":
    case "i":
    case "inventory":
    case "get":
    case "drop":
    case "END_ALIAS":
      return 0;

    case "kill":
      //They are only allowed to kill the guard.
      if ( guard->id( args ) ) {
        tell_object( player, "You make your preperations to attack "+
        guard->the_short() +" and escape!\n" );
        call_out( (: remove_arrested_shadow() :), 0 );
        return 0;
      }
    default:      
      tell_object( player, "You are being restrained by "+ 
        guard->the_short() + ".\n" );
      return 1;
  }
}

varargs int exit_command( string word, mixed verb, object thing ) {
  if ( member_array( word, environment( player )->query_exits() ) != -1 ) {
    tell_object( player, "You are being restrained by "+ 
      guard->the_short() + ".\n" );
    return 0;
  }
  return player->exit_command( word, verb, thing );
}

void remove_arrested_shadow() {
  tell_object( player, "You are no longer being restrained.\n" );
  destruct( this_object() );
}

/**
 * Because of the exit_command hack, we need to do it this way
 */
void event_exit( object ob, string message, object to ) {
  if ( ob == guard ) {
    tell_object( player, "You follow " + guard->the_short() +".\n" );
    call_out( "move_to_guard", 0 );
  }
  player->event_exit( ob, message, to );
}

void move_to_guard() {
  player->move_with_look( environment( guard ), 
    "$N follows "+ guard->a_short()+" in.", 
    "$N follows "+ guard->a_short()+" out." );
}

object query_arrested_by() {
  return guard;
}
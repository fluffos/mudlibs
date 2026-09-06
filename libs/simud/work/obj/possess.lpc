#include <object.h>
#include <alias.h>

/** A quicky daemon object used for possessing beasties. This is intended to be
 * a tool for a game-master style wizard to use in role-playing NPC's.
 */

mapping alias;

/// The thing being possessed
object target;

/// \return possesion_ob
string query_name() {
   return "possession_ob";
}

/// A convenience function to let you refer to this object as possession_ob.
object id( string x ) {
   return x == query_name()? this_object(): 0;
}

/// Set the creature possessed.
void set_target( object ob ) {
   target = ob;
}

/// For debugging purposes, query what is possessed.
object query_target() {
   return target;
}

/// Creates a new possession object, initialize it for \a victim, and give it to this_player().
int possess( object victim ) {
   object ob;

   if( !victim->query_allow_possess() )
      return 0;

   ob = clone_object( this_object() );
   ob->set_target( victim );
   victim->set_possessor( this_player() );
   ob->move( this_player() );
   return 1;
}

/// Set up the possession interface for the possessor.
void init() {
   if( !target ) {
      destruct( this_object() );
      return;
   }
   add_interface( "do_comm", capitalize(target->query_name()) + "> " );
   set_interface_catch( 1 );
   alias = ALIAS_LIST;
   alias += environment()->query_alias();
}

void do_comm( string comm ) {
   if( target == 0 ) {
      msg( "The object you were possessing seems to have vanished." );
      drop_interface();
      destruct( this_object() );
      return;
   }
   else if( comm == "help" ) {
      msg( "You are currently possessing something. Commands entered here are executed by the thing " +
         "possessed. If you add '!' in front of a command, it will be executed by your wizard " +
         "character instead. Stuff heard by the possessed creature is relayed to you directly. " +
         "Stuff heard by your wizard character is marked as remotely sensed. Use 'return' to go back to normal play." );
   }
   else if( comm == "return" ) {
      drop_interface();
      target->set_possessor( 0 );
      destruct( this_object() );
      return;
   }
   else if( comm ) {
      string verb;

      // Short forms
      if( comm[0] == '\'' ) comm[0..0] = "say ";
      if( comm[0] == ':' ) comm[0..0] = "emote ";

      // Allow aliases
      verb = explode( comm, " " )[0];
      if( member(alias, verb) )
         comm = "/daemon/parse_alias"->parse_alias( alias[verb], implode(explode(comm, " ")[1..], " "), verb );

      command( comm, target );
   }
   else {
      write( capitalize(target->query_name()) + "> " );
   }
}

/// Handle incoming text.
void catch_tell( string str ) {
   // Possessed critters tag their messages with an ASCII 255.
   if( str[0] == '\255' ) {
      if( !query_verb() )
         tell_object( environment(), "\n" );
      tell_object( environment(), str[1..] );
   }
   else {
      // Messages heard by the wizard -- mark them.
      while( str[0] == '\n' ) str = str[1..];
      while( str[<1] == '\n' ) str = str[..<2];
      tell_object( environment(), ":> " + implode(explode(str,"\n"), "\n:> ") + "\n" );
   }
}

/// If the player object leaves, get rid of this.
void on_suspend() {
   drop_interface();
   destruct(this_object());
}

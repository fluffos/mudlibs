#include <lock.h>
#include <desc.h>
#include <saveload.h>
#include <item.h>
#include <object.h>

PLURAL( "keys" )
DISTANT( "a key" )
SPECIFIC( "the key" )
ALT_PLURAL( ({ "keys" }) )
LOOK( "It's just an ordinary key." )
ALT_NAME( ({ }) )
GETTABLE( 1 )
DROPPABLE( 1 )
WEIGHT( 20 )

void create() {
   ::create();
   set_name( "key" );
}

int on_unlock( object target ) {
   int fail_count = 0, success_count = 0;
   object ob;

   set_actor(this_player());
   set_target(target);

   if( !target->query_is_lockable() )
      return 0;

   ob = target->query_lock();
   if( !ob ) return 0;
   set_target( target );
   if( ob->query_locked() ) {
      if( ob->query_keycode() == query_keycode() ) {
         ob->set_locked( 0 );
         this_player()->msg_local("~CACT~Name ~verbunlock ~targ.~CDEF" );
      }
      else {
         fail_count++;
         msg("You need a different key for this ~targ.");
      }
   }
   else
      msg("~Targ ~vertis already unlocked.");
   return 1;
}

int on_lock( object target ) {
   object ob;

   if( !target->query_is_lockable() )
      return 0;

   ob = target->query_lock();
   if( !ob ) return 0;
   set_target( target );
   if( !ob->query_locked() ) {
      if( ob->query_keycode() == query_keycode() ) {
         ob->set_locked( 1 );
         this_player()->msg_local("~CACT~Name ~verblock ~targ.~CDEF" );
         return 1;
      }
      else
         msg("You need a different key to lock ~targ.");
   }
   else
      msg("~Targ ~vertis already locked.");

   return 1;
}

int query_is_key() {
   return 1;
}

void randomize_keycode() {
   int i;
   string s = "     ";
   for( i = 0; i < strlen(s); i++ )
      s[i] = random(10) + '0';

   set_keycode( s );
}

void key_config( string params ) {
   if( !stringp(params) || strlen(params) < 2 || strlen(params) > 15 ) {
      msg( "Key name must be between 2 and 15 characters long." );
      return;
   }
   if( params == "finish" ) {
      object ob;
      this_player()->msg_local( "~Name ~verbcraft a key." );
      foreach( ob : all_inventory() )
         destruct( ob );
      drop_interface();
      return;
   }
   set_distant( query_default_distant() + " (" + params + ")" );
   set_specific( query_default_specific() + " (" + params + ")" );
   set_plural( query_default_plural() + " (" + params + ")" );
   set_look( query_default_look() + " It has the word '"+params+"' carved on it." );
   set_alt_name( query_default_alt_name() + ({ params + " key", "key " + params }) );
   msg("OK, you'll mark '" + params + "' on the key. Type something else to change your mind, or 'finish' if you're done." );
}

void key_dup_config( string param ) {
   object ob;

   if( !param || param == "" ) return;
   if( param == "new" ) {
      randomize_keycode();
      msg("OK, this will be a new key. You'll need to craft a lock afterwards.");
      shift_interface( "key_config", "[Enter a short name for this key] " );
      return;
   }
   ob = single_present(param);
   if( !ob && !ob = single_present(param + " key")) {
      msg( "Don't know what key you're talking about. Type 'new' for a new key." );
      return;
   }

   msg("OK, you'll make a copy of that key.");
   set_keycode( ob->query_keycode() );
   shift_interface( "key_config", "[Enter a short name for this key] " );
}

int on_craft() {
   msg("Which key would you like to duplicate? Type 'new' if you want to make a new key.");
   add_interface( "key_dup_config", "[Key name, or new] " );
   randomize_keycode();
   return 1;
}

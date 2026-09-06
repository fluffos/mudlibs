#include <const.h>
#include <object.h>
#include <container.h>
#include <inven.h>
#include <item.h>
#include <desc.h>

NAME( "keyring" )
DISTANT( "a keyring" )
SPECIFIC( "the keyring" )
PLURAL( "keyrings" )
ALT_NAME( ({ "keyring" }) )
ALT_PLURAL( ({ "keyrings" }) )
LOOK( "A round metal keyring?(HASINV:, with $(INV) attached to it)." )
BULK( 100 )
WEIGHT( 10 )
GETTABLE( 1 )
DROPPABLE( 1 )

void create() {
/* OBJEDIT { */
   set_bulk_capacity( 300 );
   set_weight_capacity( 2500 );
/* } OBJEDIT */
   ::create();
}

object container_id( string val ) {
   return present( val, this_object() );
}

mapping query_aspects() {
   return ([ C_METAL ]);
}

int query_is_keyring() {
   return 1;
}

object find_key( string keycode ) {
   object *keys;

   keys = filter( deep_inventory(this_object()), (: $1->query_is_key() :) );

   foreach( object key: keys) {
      debug("Seeking keycode " + keycode + ", checking key " + key->query_keycode(), "keys" );
      if( key->query_keycode() == keycode ) {
         return key;
      }
   }

   return 0;
}

int on_unlock( object target ) {
   object ob, key;

   set_actor( this_player() );
   set_target( target );

   if( !target->query_is_lockable() )
      return 0;

   ob = target->query_lock();

   if( !ob ) return 0;

   key = find_key( ob->query_keycode() );

   if( !key ) {
      msg("You need a different key for this ~targ");
      return 1;
   }

   return key->on_unlock( target );
}

int on_lock( object target ) {
   object ob, key;

   set_actor( this_player() );
   set_target( target );

   if( !target->query_is_lockable() )
      return 0;

   ob = target->query_lock();

   if( !ob ) return 0;

   key = find_key( ob->query_keycode() );

   if( !key ) {
      msg("Your keyring doesn't have the correct key to lock ~targ.");
      return 1;
   }

   return key->on_lock( target );
}

void keyring_config( string params ) {
   if( !stringp(params) || strlen(params) < 2 || strlen(params) > 15 ) {
      msg( "Keyring name must be between 2 and 15 characters long." );
      return;
   }
   if( params == "finish" ) {
      object ob;
      this_player()->msg_local( "~Name ~verbcraft a keyring." );
      foreach( ob : all_inventory() )
         destruct( ob );
      drop_interface();
      return;
   }
   set_distant( query_default_distant() + " (" + params + ")" );
   set_specific( query_default_specific() + " (" + params + ")" );
   set_plural( query_default_plural() + " (" + params + ")" );
   set_look( query_default_look() + "\n\nIt has a tag attached with the word '" + params + "' carved on it." );
   set_alt_name( query_default_alt_name() + ({ params + " keyring", "keyring " + params }) );
   msg("OK, you'll tag the keyring with '" + params + "'.  Type something else to change your mind, or 'finish' if you're done." );
}


int on_craft()
{
   msg("Please choose a name for this keyring.");
   add_interface( "keyring_config", "[Enter a short name for this keyring] " );
   return 1;
}
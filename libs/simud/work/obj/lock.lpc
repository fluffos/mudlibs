#include <lock.h>
#include <desc.h>
#include <saveload.h>
#include <item.h>
#include <object.h>

NAME( "lock" )
LOOK( "This is a lock, ready to be ~CCOMinstall~CDEFed in something." )
SPECIFIC( "the lock" )
DISTANT( "a lock" )
PLURAL( "locks" )
DROPPABLE( 1 )

void create() {
   ::create();
}

/// Can't get the lock from inside the door, after it's installed.
int query_gettable() {
   if( !environment() || !environment()->query_is_lockable() ) return 1;
   return 0;
}

int on_install( object target ) {
   if( !environment() || environment()->query_is_lockable() || !target || !target->query_is_lockable() ) return 0;
   // Could do skill checks or something here...
   if( target->query_master_ob() )
      target = target->query_master_ob();
   if( present("lock", target) ) {
      msg( "It already has a lock installed!" );
      return 1;
   }
   move( target );
   set_target( target );
   this_player()->msg_local( "~CACT~Name ~verbinstall " + query_distant() + " in ~targ.~CDEF" );
   return 1;
}

int on_uninstall() {
   set_actor( this_player() );
   set_target( environment( this_object() ) );

   this_object()->move( this_player() );

   this_player()->msg_local( "~CACT~Name ~verbuninstall " + this_object()->query_distant() + " from ~targ.~CDEF" );

    return 1;
}

int query_is_lock() {
   return 1;
}

void lock_config( string params ) {

   if( !params ) {
      msg("Setup lock:");
      if( query_keycode() ) msg("Keycode has been set. Use ~CCOMkey <keyname>~CDEF again if you change your mind.");
      else msg("You need to choose which key will open this lock. The key name is whatever you named it when you created the key. Type ~CCOMset <keyname>~CDEF to match the key to the lock.");
      msg("Type ~CCOMfinish~CDEF when you're done, or ~CCOMabort~CDEF to give up and destroy the lock.");
      return;
   }

   if( params[0..3] == "set " ) {
      object key;
      key = single_present( params[4..] );
      if( !key ) key = single_present( params[4..] + " key" );
      if( !key ) msg("No such key.");
      else {
         set_keycode( key->query_keycode() );
         msg( "Keycode set! This lock will be opened by ~CBRT" + key->query_specific() + "~CDEF." );
      }
   }

   if( params == "abort" ) {
      object ob;
      msg("Giving up.");
      drop_interface();
      // Materials return to player...
      foreach( ob : all_inventory() )
         ob->move( this_player() );
      destruct(this_object());
      return;
   }

   if( params == "finish" ) {
      if( !query_keycode() ) msg("You have to set a keycode, or the lock's useless. Abort if you don't have a key, then make a key.");
      else {
         object ob;
         this_player()->msg_local( "~CACT~Name ~verbfinish crafting " + query_distant() + ".~CDEF" );
         drop_interface();
         // Get rid of materials used for crafting
         foreach( ob: all_inventory() )
            destruct(ob);
      }
   }
}

int on_craft() {
   add_interface( "lock_config", "[Lock Setup] " );
   this_player()->msg_local( "~CACT~Name ~verbstart crafting " + query_distant() + ".~CDEF" );
   lock_config(0);
   return 1;
}

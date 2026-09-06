#include <lock.h>
#include <desc.h>
#include <saveload.h>
#include <item.h>
#include <object.h>

PLURAL( "signs" )
DISTANT( "a storefront sign" )
SPECIFIC( "the storefront sign" )
//LOOK( "It's sign for a store, okay? Stop staring at it!!" )
ALT_NAME( ({ }) )
GETTABLE( 1 )
DROPPABLE( 1 )
WEIGHT( 30 )

string sign_desc;
string sign_text;

void create() {
   ::create();
   set_name( "sign" );
   sign_desc = 0;
   sign_text = 0;
}

string query_look() {
   string look_data;

   look_data = "It's a sign for a store, okay? Stop staring at it!";
   if( sign_text ) look_data += "\n Label: " + sign_text;
   if( sign_desc ) look_data += "\n Description: " + sign_desc;

   return look_data;
}

int query_is_store_sign() {
   return 1;
}

void abort_setup() {
   object ob;

   msg( "Aborting craft job." );
   foreach( ob : all_inventory() ) {
      ob->move( this_player() );
   }
   destruct( this_object() );
}

void sign_setup2( string params ) {
   if( !stringp(params) || strlen(params) > 7 ) {
      msg( "Sign text must be less then 7 characters" );
      return;
   }
   if( params == "abort" ) {
      drop_interface();
      abort_setup();
      return;
   }
   if( params == "finish" ) {
      object ob;
      this_player()->msg_local( "~Name ~verbcraft a sign." );
      foreach( ob : all_inventory() )
         destruct( ob );
      drop_interface();
      return;
   }
   msg( "Setting [Sign Text] to: '" + params + "'" );
   sign_text = params;
}

void sign_setup( string params ) {

   if( !stringp(params) || strlen(params) > 200 ) {
      msg( "Sign description must be less than 200 characters." );
      return;
   }
   if( params == "abort" ) {
      drop_interface();
      abort_setup();
      return;
   }
   if( params == "finish" ) {
      msg( "How would you like the sign to read on the map? It must be 7 characters or less.  Type abort to cancel, or finish to, erm finish." );
      shift_interface( "sign_setup2", "[Sign Text] " );
      return;
   }
   msg( "Setting [Sign Description] to: '" + params + "'" );
   sign_desc = params;
}

int on_craft() {
   msg( "What would you like to be written on your new sign? This is what people will see when they look at it. Type abort to cancel, or finish to move on." );
   add_interface( "sign_setup", "[Sign Description] " );
   return 1;
}

int on_install( object ob ) {
  if( !ob ) return 0;
  object ob2;

  if( !ob->query_has_sign() ) return 0;

  ob->set_sign( sign_text );
  ob->set_sign_desc( sign_desc );
  ob->add_alt_name( lower_case(sign_text) + " " + lower_case(ob->query_name()) );
  foreach( ob2:all_inventory(environment(ob)) ) {
     if( ob2->query_host() == ob ) {
        ob2->add_alt_name( lower_case(sign_text) + " " + lower_case(ob->query_name()) + " door" );
     }
  }
  set_actor( this_player() );
  this_player()->msg_local( "~CACT~Name ~verbinstall a sign onto " + ob->query_specific() + ".~CDEF" );
  destruct( this_object() );

  return 1;
}

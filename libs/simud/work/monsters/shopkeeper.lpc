#include <const.h>
#include <const/talkconst.h>
inherit "/obj/monster";

create() {
   ::create();
/* OBJEDIT { */
   set_gender( 2 );
   set_spd( 10 );
   set_con( 10 );
   set_str( 10 );
   set_dex( 10 );
   set_wil( 10 );
   set_cha( 10 );
   set_int( 10 );
   set_emp( 10 );
   set_hp( 59 );
   set_distant( "a shopkeeper" );
   set_specific( "the shopkeeper" );
   set_look( "~Name ~verbis a shopkeeper. Try buying something." );
   set_plural( "shopkeepers" );
   set_name( "shopkeeper" );
   add_alt_name( "keeper" );
/* } OBJEDIT */

   clone_object("/ai/buy")->move(this_object());
}

void on_hunger() {
   add_food( 100 );
}

void on_thirst() {
   add_drink( 100 );
}

// Override the default only.
//varargs void on_soul( int type, object actor, object target, string text ) {
//}

ICON( 'h', 11, LAYER_LIVING )

#include <const.h>
#include <const/talkconst.h>
inherit "/obj/monster";

void give_coin( string text, object actor, object target );

create() {
   ::create();
/* OBJEDIT { */
   set_gender( 1 );
   set_spd( 10 );
   set_con( 10 );
   set_str( 10 );
   set_dex( 10 );
   set_wil( 10 );
   set_cha( 10 );
   set_int( 10 );
   set_emp( 10 );
   set_hp( 59 );
   set_distant( "Harry the affectionate" );
   set_specific( "Harry the affectionate" );
   set_look( "~Pron ~verbis wearing faded brown overalls, and has a look of puzzlment on ~poss face. ~Pron ~verblook a bit drunk." );
   set_name( "harry" );
   add_alt_name( "harry the affectionate" );
/* } OBJEDIT */

   set_wimpy(100);

   // probably never want people to be able to butcher him, ne? :P

   clone_object("/ai/talk")->move(this_object());
   add_talk_response( "hello", "say Hello! I love everything!" );
   add_talk_response( "how are you", "say I'm just peachy, thanks!" );
   add_talk_response( "your name", ({ "smile", "say Harry's my name! Don't wear it out!", #'give_coin }) );
}

void give_coin( string text, object actor, object target ) {
   object ob = clone_object("/obj/coins");
   ob->move(this_object());
   command("give coin to " + actor->query_name(), this_object());
}

void on_hunger() {
   add_food( 100 );
}

void on_thirst() {
   add_drink( 100 );
}

ICON( 'h', 11, LAYER_LIVING )

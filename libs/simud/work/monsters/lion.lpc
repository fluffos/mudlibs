#include <const.h>
inherit "/obj/monster";

void create() {
   object ob;
   ::create();
   set_gender( random(2)+1 );
/* OBJEDIT { */
   set_spd( 12 );
   set_con( 13 );
   set_str( 14 );
   set_dex( 15 );
   set_wil( 10 );
   set_cha( 3 );
   set_int( 4 );
   set_emp( 3 );
   if ( query_gender() == 1 ) {
      set_distant( "a lion" );
      set_specific( "the lion" );
      set_look( "~Name ~verbis ragged and thin with a short mane and a matted yellow hide. ~Pron is $(HP)." );
   } else {
      set_distant( "a lioness" );
      set_specific( "the lioness" );
      set_look( "~Name ~verbis lean and fit. A killing machine. ~Pron is $(HP)." );
      set_alt_name( "lioness" );
      set_alt_plural( "lionesses" );
   }
   set_plural( "lions" );
   set_name( "lion" );
   set_type( "animal" );
   set_droppable( 1 );
   set_weight( 45000 );
/* } OBJEDIT */

   set_living_name( name );

   set_food(query_food_capacity()/2);
   set_drink(query_drink_capacity()/2);

   add_form("animal");
   set_form("animal", 1);
   remove_form("brawl");

   set_race("feline");
   set_wc((["piercing":6]));
   set_wimpy(20);

   set_product_aspect( C_LION );
   add_product( C_MEAT, 3, 40 );
   add_product( C_PELT, 7, 20 );
   // add_product( C_TOOTH, 4, 40 );

   clone_object("/ai/carnivore")->move(this_object());
   ob = clone_object("/ai/aggro");
   ob->set_aggro_level(20);
   ob->move(this_object());
}

ICON( 'l', 11, LAYER_LIVING )

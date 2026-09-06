#include <const.h>
inherit "/obj/monster";

NAME( "lumberjack" )
LOOK( "~Name is a big, strong lumberjack with a neandarthal slope to ~poss forehead and arms the size of barrels. ~Pron looks like ~pron'd chop down trees just for the fun of it. ~Pron is $(HP)." )
DISTANT( "a lumberjack" )
SPECIFIC( "the lumberjack" )
PLURAL( "lumberjacks" )
TYPE( "human" )
WEIGHT( 80000 )
DROPPABLE( 1 )

void create() {
   ::create();
   set_gender( 1 );
/* OBJEDIT { */
   set_spd( 8 );
   set_con( 15 );
   set_str( 13 );
   set_dex( 7 );
   set_wil( 9 );
   set_cha( 9 );
   set_int( 7 );
   set_emp( 5 );
/* } OBJEDIT */

   set_living_name( name );

   set_food(query_food_capacity());
   set_drink(query_drink_capacity());

   add_form("axe");

   set_race("human");
   set_wc((["blunt":4]));
   set_wimpy(45);
   call_out( "get_axe", 1 ); // If busy loading, then I'll get my axe soon enough.
   // If initially being created, then I'll need to create an axe.
}

ICON( 'h', 9, LAYER_LIVING )

void on_hunger() {
   add_food( 100 );
}

void on_thirst() {
   add_drink( 100 );
}

void get_axe() {
   if( !present("axe", this_object()) )
      clone_object("/items/weapon/axe")->move(this_object());
   command("hold axe");
}

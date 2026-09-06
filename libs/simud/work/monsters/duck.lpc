#include <const.h>
inherit "/obj/monster";

string duck_color;
string query_color() { return duck_color; }
void set_color(string str) { duck_color = str; }
int query_color_int() {
	switch( duck_color ) {
		case "green": return 2;
		case "brown": return 3;
		case "white": return 15;
		case "black": return 8;
	}
	return 9;	// bright red ;)
}

NAME( "duck" )
DISTANT( "a "+query_color()+" duck" )
SPECIFIC( "the "+query_color()+" duck" )
LOOK( "It's a duck, a medium-sized aquatic bird. This particular one happens to be "+query_color()+". ~Pron is $(HP)." )
PLURAL( "ducks" )
ALT_NAME( ({ query_color()+" duck" }) )
ALT_PLURAL( ({ query_color()+" ducks" }) )

DROPPABLE( 1 )
GETTABLE( 1 )
WEIGHT( 1500 )


void create() {
   ::create();
   set_gender( random(2)+1 );
/* OBJEDIT { */
   set_spd( 20 );
   set_con( 6 );
   set_str( 4 );
   set_dex( 18 );
   set_wil( 18 );
   set_cha( 10 );
   set_int( 4 );
   set_emp( 2 );
   set_type( "bird" );
/* } OBJEDIT */

   duck_color = ({ "white", "green", "green", "green",
				   "brown", "brown", "black" })[random(7)];

   set_living_name( name );

   set_food(query_food_capacity());
   set_drink(query_drink_capacity());

   set_product_aspect( C_DUCK );
   add_product( C_MEAT, 4, 20 );
   //add_product( C_FEATHER, 4, 10 ); - feathers are broken somehow right now

   add_form("animal");
   set_form("animal", 1);
   remove_form("brawl");
   set_race("avian");	// yeah, yeah, I know
   set_wc((["piercing":4]));
   set_wimpy(60);
}

string *query_default_ai() { return ({ "forage", "egglaying" }); }

ICON( 'd', query_color_int(), LAYER_LIVING )

#include <const.h>
inherit "/obj/food";

string query_animal();

GETTABLE( 1 )
DROPPABLE( 1 )
WEIGHT( 10 )	// smaller than 1/10 of a piece of raw meat
BULK( 10 )
NAME( query_animal() + " jerky" )
ALT_NAME( ({ "jerky", "strip of jerky" }) )
ALT_PLURAL( ({ "strips", "strips of jerky" }) )
SPECIFIC( "the strip of " + query_animal() + " jerky" )
PLURAL( "strips of " + query_animal() + " jerky" )
LOOK( "A thin strip of dried " + query_animal() + " meat. It will last forever and is actually just about as nutritious as the original product." )
DISTANT( query_quantity() > 1 ? query_plural() : "a strip of " + query_animal() + " jerky" )
// These are defaults and should always be overridden by a much higher value
FOOD_VALUE( 10 )
DRINK_VALUE( 0 )

TASTE( "It tastes like salted "+query_animal()+" proteins." )

FOOD_BUFF( (["str":1, "thirst":1]) )
FOOD_BUFF_TIME( max(this_object()->query_food_value() / 10,4) )

string animal;

string query_animal() {
   if( !animal )
      return "dried";
   return animal;
}

mapping aspects;

void create() {
   ::create();
   set_edible( 1 );
   aspects = ([ C_FOOD, C_JERKY ]);
}

void add_aspect( int x ) {
	aspects += ([ x ]);
}

mapping query_aspects() {
   return aspects;
}

void set_animal(string str) {
   animal = str;
}

// We don't return - this way the mats are dested by the daemon
void on_craft( object *mats ) {
	object ob;
	foreach( ob : mats )
		if( ob->query_has_aspect(C_RAW) && ob->query_has_aspect(C_MEAT) ) {
			string tmp = ob->query_animal();
			if( tmp == "cow" )
				set_animal( "beef" );
			else if( tmp == "pig" )
				set_animal( "pork" );
			else
				set_animal( ob->query_animal() );
			add_aspect( ob->query_aspect_map()[tmp] );
			set_food_value( ob->query_food_value() / 10 );
			set_drink_value( 0 );
		}
}

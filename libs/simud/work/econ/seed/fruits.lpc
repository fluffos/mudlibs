#include <edible.h>
inherit "/obj/seed";

TASTE( "It tastes generic." )

void create() {
	::create();
	set_edible( 1 );
}

string query_treed_fruit_look() {
   /* instances should override. */
    return "?";
}

int query_treed_fruit_color() {
   /* instances should override */
   return 7;
}

string query_floored_fruit_look() {
   /* instances should override */
   return "?";
}


void on_paint(object painter) {
   painter->paint(query_x(),query_y(),query_floored_fruit_look()[0], 3, LAYER_ITEMS);
}

int on_consume( int max ) {
   default_consume(max);
   return 1;
}

mapping query_aspects() {
   return ([ C_SEED, C_FRUIT, C_RAW, C_FOOD ]);
}

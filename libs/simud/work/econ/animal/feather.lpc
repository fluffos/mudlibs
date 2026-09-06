#include <const.h>
#include <quantity.h>
inherit "/obj/trinket";

GETTABLE( 1 )
DROPPABLE( 1 )
WEIGHT( 1 )
BULK( 1 )	

string type;
string query_type() { return type; }
int aspect;

string *query_alt_name() {
   return ({ "feather", query_type() + " feather" });
}

string *query_alt_plural() {
   return ({ "feathers", query_type() + " feathers" });
}

mapping query_aspect_map() {
   return ([ "chicken": C_CHICKEN, "duck": C_DUCK ]);
}

string query_name() {
   return query_type() + " feather";
}

string query_specific() {
   return "the " + query_type() + " feather";
}

string query_plural() {
   return rough_amount(query_quantity()) + " " + query_type() + " feathers";
}

string query_distant() {
   int q = query_quantity();
   if (q > 1)
      return query_plural();
   return "a " + query_type() + " feather";
}

string query_look() {
   return "It's " + query_distant() + ". It was removed from the body of some poor little feathered critter. There are uses for this sort of thing, surely if you found an appropriate crafting recipe you could figure out the rest...";
}

void set_type(string str) {
   type = str;

   if (member(query_aspect_map(), type))
      aspect = query_aspect_map()[type];
}
void set_product_aspect(int x) {
   string str;
   mapping map = query_aspect_map();
   foreach ( str : m_indices(map) ) {
      if ( map[str] == x ) {
         set_type(str);
         return;
      }
   }
}
mapping query_aspects() {
   return ([ C_FEATHER, aspect ]);
}

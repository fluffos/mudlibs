// Eventually, this file needs to contain a generic structure for animal body
// parts that really don't do anything except sit around and rot (and of course
// get used in alchemy):
// - legs, feet, arms, hands, fingers
// - scales, fins, tails, wings
// - eyes
// - venom sacs, stomachs?, livers?, hearts, brains?
// The following parts do not decay:
// - teeth, claws, stingers, mandibles
// - bones (limb), scapulae, skulls
// - shells, carapace
// Another file should probably be written to handle liquids:
// - blood, ichor, venom

#include <const.h>
#include <quantity.h>
inherit "/obj/trinket";

GETTABLE( 1 )
DROPPABLE( 1 )

string type;
string query_type() { return type; }

mapping aspects;
int size;

string query_size_string() {
   if (size < 3)
      return "very small";
   if (size < 5)
      return "small";
   if (size < 7)
      return "medium";
   if (size < 9)
      return "large";
   if (size < 15)
      return "very large";
   return "huge";
}

string *query_alt_name() {
   return ({ "skin", query_type() + " skin", query_size_string() + " skin",
             query_size_string() + " " + query_type() + " skin" });
}

string *query_alt_plural() {
   return ({ "skins", query_type() + " skins", query_size_string() + " skins",
             query_size_string() + " " + query_type() + " skins" });
}

mapping query_aspect_map() {
   return ([ "rabbit": C_RABBIT, "bear": C_BEAR, "deer": C_DEER,
             "wolf": C_WOLF, "bat": C_BAT, "beaver": C_BEAVER ]);
}

/* NOTE: When making hides, the size will vary based on the skill of the maker,
 * and eventually the size of the animal.
 */
int query_size() {
   return size;
}
void set_size(int x) {
   size = x;
   set_weight( 50 * x );
   set_bulk( 55 * x );
}

string query_name() {
   return query_type() + " skin";
}

string query_specific() {
   return "the " + query_size_string() + " " + query_type() + " skin";
}

string query_plural() {
   return rough_amount(query_quantity()) + " " + query_size_string() + " " + query_type() + " skins";
}

string query_distant() {
   int q = query_quantity();
   if (q > 1)
      return query_plural();
   return "a " + query_size_string() + " " + query_type() + " skin";
}

string query_look() {
   return "It's " + query_distant() + ". It was removed from the body of some poor little animal. You should probably tan it and make a pair of boots or something before it goes bad. Maybe a nice rug or a stylish hat...";
}

void create() {
   ::create();
   size = 1; // by default... it's pretty teeny
   aspects = ([ C_PELT ]);
}

void set_type(string str) {
   type = str;

   if (member(query_aspect_map(), type))
      aspects += ([ query_aspect_map()[type] ]);
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
   return aspects;
}

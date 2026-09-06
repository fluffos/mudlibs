#include <const.h>
inherit "/obj/trinket";
#include <decay.h>

// Carapace does not rot :)
// PERISHABLE( 30 )
GETTABLE( 1 )
DROPPABLE( 1 )

string animal_type;
string query_animal_type() { return animal_type; }

mapping aspects;
int size;

string query_size_string() {
   if (size < 5)
      return "small";
   if (size < 10)
      return "medium";
   return "large";
}

string *query_alt_name() {
   return ({ "carapace", query_animal_type() + " carapace", query_size_string() + " carapace",
             query_size_string() + " " + query_animal_type() + " carapace" });
}

string *query_alt_plural() {
   return ({ "carapaces", query_animal_type() + " carapaces", query_size_string() + " carapaces",
             query_size_string() + " " + query_animal_type() + " carapaces" });
}

mapping query_aspect_map() {
   return ([ "scorpion": C_SCORPION, "insect": C_INSECT, "crab": C_CRAB ]);
}

/* NOTE: When making hides, the size will vary based on the skill of the maker,
 * and eventually the size of the animal.
 */
int query_size() {
   return size;
}
void set_size(int x) {
   size = x;
   set_weight( 75 * x );
   set_bulk( 50 * x );
   if( size < 5 )
      aspects += ([ C_SMALL ]);
   else if( size < 10 )
      aspects += ([ C_MEDIUM ]);
   else
      aspects += ([ C_LARGE ]);
}

string query_name() {
   return query_animal_type() + " carapace";
}

string query_specific() {
   return "the " + query_size_string() + " " + query_animal_type() + " carapace";
}

string query_plural() {
   return query_size_string() + " " + query_animal_type() + " carapaces";
}

string query_distant() {
   return "a " + query_size_string() + " " + query_animal_type() + " carapace";
}

string query_look() {
   return "It's " + query_distant() + ". It was removed from the body of some poor little ugly scaly monster. Rumor says that there are those who can actually use this stuff to make armour and other useful items.";
}

void create() {
   ::create();
   size = 1; // by default... it's pretty teeny
   aspects = ([ C_CARAPACE, C_RAW ]);
}

void set_animal_type(string str) {
   animal_type = str;

   if (member(query_aspect_map(), animal_type))
      aspects += ([ query_aspect_map()[animal_type] ]);
}

void set_product_aspect(int x) {
   string str;
   mapping map = query_aspect_map();
   foreach ( str : m_indices(map) ) {
      if ( map[str] == x ) {
         set_animal_type(str);
         return;
      }
   }
}
mapping query_aspects() {
   return aspects + ([ C_RAW ]);
}

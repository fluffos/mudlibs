#include <const.h>
inherit "/obj/trinket";
#include <decay.h>

PERISHABLE( 30 )
GETTABLE( 1 )
DROPPABLE( 1 )

string animal_type;
string query_animal_type() { return animal_type; }

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
   return ({ "skin", query_animal_type() + " skin", query_size_string() + " skin",
             query_size_string() + " " + query_animal_type() + " skin" });
}

string *query_alt_plural() {
   return ({ "skins", query_animal_type() + " skins", query_size_string() + " skins",
             query_size_string() + " " + query_animal_type() + " skins" });
}

mapping query_aspect_map() {
   return ([ "rabbit": C_RABBIT, "bear": C_BEAR, "deer": C_DEER,
             "wolf": C_WOLF, "bat": C_BAT, "beaver": C_BEAVER,
			 "dragon": C_DRAGON, "lion": C_LION, "lizard": C_LIZARD ]);
}

string query_thickness() {
   if ( member( ({ "rabbit", "deer", "bat", "wolf" }), query_animal_type() ) != -1 )
      return "thin";
   else if ( query_animal_type() == "dragon" )
      return "dragon";
   else
      return "thick";
}

object on_cut() {
   object ob;
   if( size < 1 )
      return 0;
   this_player()->practice_skill("craft.leatherworker");
   catch( ob = clone_object("/econ/animal/"+query_thickness()+"_hide") );
   size--;
   return ob;
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
   return query_animal_type() + " skin";
}

string query_specific() {
   return "the " + query_size_string() + " " + query_animal_type() + " skin";
}

string query_plural() {
   return query_size_string() + " " + query_animal_type() + " skins";
}

string query_distant() {
   return "a " + query_size_string() + " " + query_animal_type() + " skin";
}

string query_look() {
   return "It's " + query_distant() + ". It was removed from the body of some poor little animal. You should probably tan it and make a pair of boots or something before it goes bad. Maybe a nice rug or a stylish hat...";
}

void create() {
   ::create();
   size = 1; // by default... it's pretty teeny
   aspects = ([ C_PELT ]);
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
   return aspects;
}

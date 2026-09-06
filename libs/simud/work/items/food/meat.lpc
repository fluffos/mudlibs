#include <const.h>
inherit "/obj/food";

string query_animal();

GETTABLE( 1 )
DROPPABLE( 1 )
WEIGHT( 120 )
BULK( 150 )
ALT_NAME( ({ "meat", "piece of meat", query_animal() + " meat" }) )
ALT_PLURAL( ({ "meat", "meats", "pieces of meat", query_animal() + " meats" }) )
PERISHABLE( 50 )

// These are defaults and should always be overridden by a much higher value
FOOD_VALUE( 100 )
DRINK_VALUE( 0 )

// TODO: custom buffs based on animal type
//       ie, dragon more than just good filling food ;)
FOOD_BUFF( (["str":2, "cha":-1, "int":-1]) )
FOOD_BUFF_TIME( max(this_object()->query_food_value() / 10,4) )

string animal;

string query_animal() {
   return animal;
}

mapping aspects;

mapping query_aspect_map() {
   return ([ "rabbit": C_RABBIT, "bear": C_BEAR, "deer": C_DEER,
             "wolf": C_WOLF, "bat": C_BAT, "beaver": C_BEAVER,
			 "dragon": C_DRAGON, "lion": C_LION, "lizard": C_LIZARD,
			 "insect": C_INSECT, "scorpion": C_SCORPION, "crab": C_CRAB,
			 "duck": C_DUCK, "chicken": C_CHICKEN, "cow": C_COW ]);
}

// how much hunger does this cure?
mapping query_nutrition_map() {
   return ([ "rabbit": 150, "bear": 175, "deer": 200, "wolf": 150,
			 "dragon": 500, "lion": 150, "lizard": 225, "insect": 100,
			 "crab": 200,
			 "scorpion": 125, "duck": 200, "chicken": 250, "cow": 300 ]);
}

/// How cooked it is.
int cooked;

int query_cooked() {
   return cooked;
}

void set_cooked( int x ) {
   float mod;
   cooked = x;
   if (!member(query_nutrition_map(), query_animal()))
      return;
   // improve nutritional value ;)
   if (cooked < 1) // raw and frozen
      mod = 0.75;
   else if (cooked >= 3 && cooked <= 5) // medium-rare to well
      mod = 1.25;
   else if (cooked >= 6)
      mod = 1.0 - 0.15 * (cooked - 5);
   set_food_value( max((int)floor(query_nutrition_map()[query_animal()] * mod), 1) );
}

string query_cooked_string() {
   switch( cooked ) {
      case -1: return "frozen";
      case 0: return "raw";
      case 1: return "lightly seared";
      case 2: return "rare";
      case 3: return "medium-rare";
      case 4: return "cooked";
      case 5: return "well-done";
      case 6: return "slightly burnt";
      case 7: return "burnt";
      default: return "badly burnt";
   }
   return "stupidly fried because our mud driver is cranky";
}

string query_name() {
   return query_animal() + " meat";
}

string query_specific() {
   return "the piece of " + query_cooked_string() + " " + query_animal() + " meat";
}

string query_plural() {
   return rough_amount(query_quantity()) + " pieces of " + query_cooked_string() + " " + query_animal() + " meat";
}

string query_distant() {
   if (query_quantity() > 1)
      return query_plural();
   return "a piece of " + query_cooked_string() + " " + query_animal() + " meat";
}

string query_look() {
   return "It's " + query_distant() + ". You can eat it, or do other meat-related things with it.";
}

void create() {
   ::create();
   set_edible( 1 );
   aspects = ([ C_FOOD, C_MEAT, C_RAW ]);
}

void on_heat( int temp ) {
   if( temp > 130 )
      set_cooked( query_cooked() + (temp / 150) + 1 );

   if( cooked > 30 ) {
      msg_room( environment(), "~CACTThe meat, far beyond the 'charcoal' stage, disintegrates into ashes.~CDEF" );
      destruct(this_object());
   }
}

void set_animal(string str) {
   animal = str;

   if (member(query_aspect_map(), animal))
      aspects += ([ query_aspect_map()[animal] ]);

   if (member(query_nutrition_map(), animal))
      set_food_value(query_nutrition_map()[animal]);
}

void set_product_aspect(int x) {
   string str;
   mapping map = query_aspect_map();
   foreach ( str : m_indices(map) ) {
      if ( map[str] == x ) {
         set_animal(str);
         return;
      }
   }
}

mapping query_aspects() {
   return aspects + ([ C_RAW ]);	// temporary stupid hack
}

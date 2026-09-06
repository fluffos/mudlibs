/**
 * NOTE: This object is probably going to be deprecated soon?
 *       At least the whole metal-specific bit about it will be.
 *       - Al [ Oct, '05 ]
 */

mapping aspect_map = ([
                  // METAL
                  C_ADAMANT:   "adamant",      C_ADAMANTORE:  "adamant ore",
                  C_ALUMINUM:   "aluminum",      C_ALUMINUMORE: "aluminum ore",
                  C_BRASS:   "brass",
                  C_BRONZE:   "bronze",
                  C_COPPER:   "copper",      C_COPPERORE:   "copper ore",
                  C_ELECTRUM:   "electrum",
                  C_GOLD:      "gold",         C_GOLDORE:     "gold ore",
                  C_HARDENED_STEEL: "hardened steel",
                  C_IRON:      "iron",         C_IRONORE:     "iron ore",
                  C_LEAD:      "lead",         C_LEADORE:     "lead ore",
                  C_MITHRIL:   "mithril",      C_MITHRILORE:  "mithril ore",
                  C_NICKEL:   "nickel",      C_NICKELORE:   "nickel ore",
                  C_ORICHALCUM:"orichalcum",   C_ORICHALCUMORE: "orichalcum ore",
                  C_PEWTER:   "pewter",
                  C_PLATINUM:   "platinum",      C_PLATINUMORE: "platinum ore",
                  C_SILVER:   "silver",      C_SILVERORE:   "silver ore",
                  C_STEEL:   "steel",
                  C_TIN:      "tin",         C_TINORE:      "tin ore",
                  C_WHITE_GOLD: "white gold",
                  C_ZINC:      "zinc",         C_ZINCORE:     "zinc ore",
                  // WOOD
                  // FOOD
                  C_BARLEY:   "barley",
                  C_CORN:      "corn",
                  C_OATS:      "oats",
                  C_RICE:      "rice",
                  C_RYE:      "rye",
                  C_WHEAT:   "wheat",

                  C_LIME:   "lime",
                  C_APPLE:   "apple",
                  C_ORANGE:   "orange",
                  C_LEMON:   "lemon",
                  C_BANANA:   "banana",
                  C_CHERRY:   "cherry",
                  C_COCONUT:   "coconut",
                  C_OLIVE:   "olive",
                  C_PLUM:      "plum",
                  // ANIMAL
                  C_DUCK:      "duck",
                  C_CHICKEN:   "chicken",
                  C_LIZARD:   "lizard",
                 ]);

string query_aspect_string( int aspect ) {
   //debug( aspect + " = " + aspect_map[aspect] );
   return aspect_map[aspect];
}

string *query_aspect_array( mapping aspects ) {
   string *arr = ({});
   int x;
   foreach( x : aspects )
      arr += ({ query_aspect_string(x) });
   //debug( as_lpc(arr) );
   return arr;
}

int query_aspect( string str ) {
   string tmp;
   int aspect;
   foreach( aspect, tmp : aspect_map )
      if( tmp == str )
         return aspect;
   return -1;
}

///// EVERYTHING UNDER HERE GOES /////

mapping metal_types = ([ C_BRONZE: "bronze", C_LEAD: "lead",
   C_TIN: "tin", C_SILVER: "silver", C_GOLD: "golden", C_COPPER: "copper",
   C_IRON: "iron", C_STEEL: "steel", C_NICKEL: "nickel",
   C_WHITE_GOLD: "white gold", C_PLATINUM: "platinum" ]);

string get_metal_type( mapping aspect ) {
   if( !mappingp(aspect) ) {
      debug("From " + as_string(previous_object()) + ", passed " + as_lpc(aspect) + " for aspect (non-mapping)");
      return "";
   }
   return comma_list( m_values(metal_types - (metal_types - aspect)) );
}

/// The metal type and an article (a or an).
string get_a_metal_type( mapping aspect ) {
   string ret;

   if( !mappingp(aspect) ) {
      debug("From " + as_string(previous_object()) + ", passed " + as_lpc(aspect) + " for aspect (non-mapping)");
      return "";
   }
   ret = comma_list( m_values(metal_types - (metal_types - aspect)) );

   if( member("aeiou", ret[0]) >= 0 ) return "an " + ret;
   else return "a " + ret;
}

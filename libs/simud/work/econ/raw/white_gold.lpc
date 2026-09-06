#include <const.h>
inherit "/obj/resource";

NAME( "white gold" )
SPECIFIC( "white gold" )
DISTANT( "white gold" )
PLURAL( "white gold" )
LOOK( "A bunch of white gold. It is a warm silvery-white in color." )
TASTE( "It tastes exotic." )
UNIT( "ingot" )
ICON( '#', 0x8F, LAYER_ITEMS )

// density of white gold approx. 18.91 g/cm^3
WEIGHT( 189100 )
// made up, based on gold and silver's values
BULK( 25000 )

mapping query_aspects() { return ([ C_RAW, C_METAL, C_WHITE_GOLD ]); }

void apply_armor_properties( object ob ) {
   int ival;
   string sval;

   // hard coded values that apply to the ac values on armour if you
   // use this material to craft a piece of armour
   int p_ac = 0;
   mapping p_ac_mod = ([ "electric": -30 ]);

   // apply ac values from the material to the object pointer,
   // which should be a piece of armour
   ob->set_base_ac( ob->query_base_ac() + p_ac );
   foreach( sval, ival : p_ac_mod  ) {
      ob->set_ac_mod( sval, ival + ob->query_ac_mod(sval) );
   }
   ob->add_aspects( ([ C_WHITE_GOLD, C_METAL ]) );
}

/*
 * References:
 *  - http://www.24carat.co.uk/whatiswhitegold.html
 */

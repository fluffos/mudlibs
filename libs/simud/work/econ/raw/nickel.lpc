#include <const.h>
inherit "/obj/resource";

NAME( "nickel" )
SPECIFIC( "nickel" )
DISTANT( "nickel" )
PLURAL( "nickel" )
LOOK( "A bunch of nickel. It can be used to make things out of nickel." )
TASTE( "It tastes like buffalo." )
UNIT( "ingot" )
ICON( '*', 0x88, LAYER_ITEMS )

// density of nickel is 8.9 g/cm^3
WEIGHT( 89000 )
// made up, based on gold and silver's values
BULK( 25000 )

mapping query_aspects() { return ([ C_RAW, C_METAL, C_NICKEL ]); }

void apply_armor_properties( object ob ) {
   int ival;
   string sval;

   // hard coded values that apply to the ac values on armour if you
   // use this material to craft a piece of armour
   int p_ac = 0;
   mapping p_ac_mod = ([ "electric": -20 ]);

   // apply ac values from the material to the object pointer,
   // which should be a piece of armour
   ob->set_base_ac( ob->query_base_ac() + p_ac );
   foreach( sval, ival : p_ac_mod  ) {
      ob->set_ac_mod( sval, ival + ob->query_ac_mod(sval) );
   }
   ob->add_aspects( ([ C_NICKEL, C_METAL ]) );
}

/*
 * References:
 *  - http://www.24carat.co.uk/whatiswhitegold.html
 */

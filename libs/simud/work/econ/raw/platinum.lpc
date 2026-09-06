#include <const.h>
inherit "/obj/resource";

SPECIFIC( "platinum" )
DISTANT( "platinum" )
PLURAL( "platinum" )
LOOK( "A bunch of platinum. It is pale silvery-white in color." )
TASTE( "It tastes extremely expensive." )
UNIT( "ingot" )
ICON( '*', 0x8F, LAYER_ITEMS )

// density of platinum is 21.45 g/cm^3
WEIGHT( 214500 )
// made up, based on gold and silver's values
BULK( 25000 )

mapping query_aspects() { return ([ C_RAW, C_METAL, C_PLATINUM ]); }

void apply_armor_properties( object ob ) {
   int ival;
   string sval;

   // hard coded values that apply to the ac values on armour if you
   // use this material to craft a piece of armour
   int p_ac = 0;
   mapping p_ac_mod = ([ "electric": -23 ]);

   // apply ac values from the material to the object pointer,
   // which should be a piece of armour
   ob->set_base_ac( ob->query_base_ac() + p_ac );
   foreach( sval, ival : p_ac_mod  ) {
      ob->set_ac_mod( sval, ival + ob->query_ac_mod(sval) );
   }
   ob->add_aspects( ([ C_PLATINUM, C_METAL ]) );
}

/*
 * References:
 *  - http://www.minerals.net/mineral/elements/platinum/platinum.htm
 *  - http://periodictable.mysterymaster.com/periodic_table_density.html
 */

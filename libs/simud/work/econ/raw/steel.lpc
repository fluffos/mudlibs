inherit "/obj/resource";
#include <const.h>

NAME( "steel" )
DISTANT( "steel" )
SPECIFIC( "steel" )
PLURAL( "steel" )
LOOK("A bunch of steel.  It can be used to make things out of steel.")
WEIGHT( 471000 )
BULK( 60000 )
UNIT( "ingot" )
TASTE( "Did ~pron die?" )

ICON( '*', 0x88, LAYER_ITEMS )

mapping query_aspects() {
   return ([ C_RAW, C_STEEL, C_METAL ]);
}

void apply_armor_properties( object ob ) {
   int ival;
   string sval;

   // hard coded values that apply to the ac values on armour if you
   // use this material to craft a piece of armour
   int p_ac = 10;
   mapping p_ac_mod = ([ "edged": 20, "electric": -10 ]);

   // apply ac values from the material to the object pointer, which should be a piece of
   // armour
   ob->set_base_ac( ob->query_base_ac() + p_ac );
   foreach( sval, ival : p_ac_mod  ) {
      ob->set_ac_mod( sval, ival + ob->query_ac_mod(sval) );
   }
   ob->set_max_condition( ob->query_max_condition() * 3 );
   ob->add_aspects( ([ C_STEEL, C_METAL ]) );
}

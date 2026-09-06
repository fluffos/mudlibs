inherit "/obj/resource";
#include <const.h>

NAME( "silver" )
DISTANT( "silver" )
SPECIFIC( "silver" )
PLURAL( "silver" )
LOOK("It shines coldly, like the moonlight.")
ALT_PLURAL( ({ "units of silver" }) )
TASTE( "It tastes like silverware." )
// density of silver is 10.5 g/cm^3
WEIGHT( 105000 )
BULK( 50000 )
ICON( '*', 0x87, LAYER_ITEMS )
UNIT( "ingot" )
ASPECT( ([ C_RAW, C_METAL, C_SILVER ]) )

void apply_armor_properties( object ob ) {
   int ival;
   string sval;

   // hard coded values that apply to the ac values on armour if you
   // use this material to craft a piece of armour
   int p_ac = -5;
   mapping p_ac_mod = ([ "electric": -25 ]);

   // apply ac values from the material to the object pointer, which should be a piece of
   // armour
   ob->set_base_ac( ob->query_base_ac() + p_ac );
   foreach( sval, ival : p_ac_mod  ) {
      ob->set_ac_mod( sval, ival + ob->query_ac_mod(sval) );
   }
   ob->add_aspects( ([ C_SILVER, C_METAL ]) );
}

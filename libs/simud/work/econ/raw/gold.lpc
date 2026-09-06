inherit "/obj/resource";
#include <const.h>

NAME( "gold" )
DISTANT( "gold" )
SPECIFIC( "gold" )
PLURAL( "gold" )
LOOK( "It's got a sparkly, warm color." )
TASTE( "It tastes like it'd be a great idea to tie a currency to it." )
// density of gold is 19.32 g/cm^3
WEIGHT( 193200 )
BULK( 25000 )
UNIT( "ingot" )
ICON( '*', 0x8B, LAYER_ITEMS )

mapping query_aspects() {
   return ([ C_RAW, C_METAL, C_GOLD ]);
}

void apply_armor_properties( object ob ) {
   int ival;
   string sval;

   // hard coded values that apply to the ac values on armour if you
   // use this material to craft a piece of armour
   int p_ac = -10;
   mapping p_ac_mod = ([ "electric": -30 ]);

   // apply ac values from the material to the object pointer, which should be a piece of
   // armour
   ob->set_base_ac( ob->query_base_ac() + p_ac );
   foreach( sval, ival : p_ac_mod  ) {
      ob->set_ac_mod( sval, ival + ob->query_ac_mod(sval) );
   }
   ob->add_aspects( ([ C_GOLD, C_METAL ]) );
}

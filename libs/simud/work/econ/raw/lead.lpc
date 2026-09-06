inherit "/obj/resource";
#include <const.h>

NAME( "lead" )
DISTANT( "lead" )
SPECIFIC( "lead" )
PLURAL( "lead" )
LOOK( "A bunch of lead. It can be used to make things out of lead." )
WEIGHT( 114000 )
BULK( 10000 )
UNIT( "ingot" )
TASTE( "It'd taste better if converted to gold." )
ICON( '*', 0x88, LAYER_ITEMS )

mapping query_aspects() {
   return ([ C_RAW, C_METAL, C_LEAD ]);
}

void apply_armor_properties( object ob ) {
   int ival;
   string sval;

   // hard coded values that apply to the ac values on armour if you
   // use this material to craft a piece of armour
   int p_ac = 0;
   mapping p_ac_mod = ([ "electric": 15, "edged": -5, "piercing": 10 ]);

   // apply ac values from the material to the object pointer, which should be a piece of
   // armour
   ob->set_base_ac( ob->query_base_ac() + p_ac );
   foreach( sval, ival : p_ac_mod  ) {
      ob->set_ac_mod( sval, ival + ob->query_ac_mod(sval) );
   }
   ob->set_weight( ob->query_weight() * 8 / 5 );
   ob->add_aspects( ([ C_LEAD, C_METAL ]) );
}

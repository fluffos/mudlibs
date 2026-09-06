inherit "/obj/resource";
#include <const.h>

NAME( "iron" )
DISTANT( "iron" )
SPECIFIC( "iron" )
PLURAL( "iron" )
LOOK("A bunch of iron ingots. Great for making metal things. Completely inedible.")
WEIGHT( 78600 )
BULK( 100000 )
UNIT( "ingot" )
TASTE( "It tastes like it's 2:44 AM." )

void create() {
   ::create();
/* OBJEDIT { */
   set_quantity(1);
   set_name( "iron" );
   set_distant("iron");
   set_specific("iron");
   set_plural("iron");
   set_look("A bunch of iron ingots. Great for making metal things. Completely inedible.");
   set_alt_plural( ({ "ingots", "iron", "units of iron" }) );
/* } OBJEDIT */
}

ICON( '*', 0x88, LAYER_ITEMS )

mapping query_aspects() {
   return ([ C_RAW, C_METAL, C_IRON ]);
}

void apply_armor_properties( object ob ) {
   int ival;
   string sval;

   // hard coded values that apply to the ac values on armour if you
   // use this material to craft a piece of armour
   int p_ac = 0;
   mapping p_ac_mod = ([ "electric": -20 ]);

   // apply ac values from the material to the object pointer, which should be a piece of
   // armour
   ob->set_base_ac( ob->query_base_ac() + p_ac );
   foreach( sval, ival : p_ac_mod  ) {
      ob->set_ac_mod( sval, ival + ob->query_ac_mod(sval) );
   }
   ob->add_aspects( ([ C_IRON, C_METAL ]) );
}

inherit "/obj/base_armour";

GETTABLE( 1 )
DROPPABLE( 1 )
VALUE(1000)
NAME( METAL_TYPE + " chain shirt" )
ALT_NAME( ({ "shirt", "chain shirt", METAL_TYPE + " shirt", "chain", "armour", "armor", METAL_TYPE + " armour", METAL_TYPE + " armor", METAL_TYPE + " chain shirt" }) )
DISTANT( A_METAL_TYPE +" chain shirt" )
LOOK( "This is a shirt of armour made by interlocking links of $(METAL) "+
      "chain together. You might be able to get some use out of it "+
      "by wearing the durned thing and hoping that it stops swords "+
      "from cutting you wide open.")
SPECIFIC( "the " + METAL_TYPE + " chain shirt" )
PLURAL( METAL_TYPE + " chain shirts" )
ALT_PLURAL( ({ "shirts", METAL_TYPE + " shirts", "chain shirts" }) )
TYPE( "armour" )
WEIGHT( 11300 ) // 11.3 kg =~ 25 lbs
TASTE( "It tastes like Cheerios." )

void create() {
   ::create();
   set_base_ac(15);
   set_ac_mod( (["edged":10,"piercing":-5]) );
   set_requirement( (["str":13]) );
   set_armour_type( "armour" );
   set_flexible(1);
   set_size(18);
   set_body_parts(BP_TORSO);
   set_aspects( ([ C_CLOTHING, C_SHIRT, C_CHAIN  ])  );
}

int query_dex_bonus()
{
   return -2;
}

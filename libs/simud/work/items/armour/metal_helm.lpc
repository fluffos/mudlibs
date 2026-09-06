inherit "/obj/base_armour";

GETTABLE( 1 )
DROPPABLE( 1 )
NAME( METAL_TYPE + " helm" )
ALT_NAME( ({"helmet", "helm", METAL_TYPE + " armour", METAL_TYPE + " armor"  }) )
DISTANT( A_METAL_TYPE + " helm" )
LOOK( "Made completely of $(METAL), this helm is a good deterrence for blades, but does not provide much defense from stabbing weapons.")
SPECIFIC( "the " + METAL_TYPE + " helm" )
PLURAL( METAL_TYPE + " helms" )
ALT_PLURAL( ({ "helms", "helmets" }) )
TYPE( "armour" )
TASTE( "It tastes like dandruff." )
FLEXIBLE( 0 )
BODY_PARTS( BP_HEAD )
SIZE( 20 )
ASPECT( ([ C_CLOTHING, C_HEADGEAR, C_METAL ]) )

void create() {
   ::create();
   set_base_ac(20);
   set_ac_mod( (["edged":10, "blunt":10,"electric":-20]) );
   set_requirement( (["str":10]) );
   set_armour_type( "armour" );
}

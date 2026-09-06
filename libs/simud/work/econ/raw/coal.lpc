inherit "/obj/resource";

NAME( "coal" )
DISTANT( "coal" )
SPECIFIC( "coal" )
PLURAL( "coal" )
ALT_NAME( ({ "coal lumps" }) )
LOOK( "Black, sooty coal." )
ALT_PLURAL( ({ "lumps of coal" }) )
WEIGHT( 150000 )
BULK( 100000 )
UNIT( "lump" )
TASTE( "~Pron tongue is now black." )

ICON( '*', 0x88, LAYER_ITEMS )

int query_fuel() {
   return query_quantity() * 10;
}

int query_fuel_strength() {
   return 1500;
}

mapping query_aspects() {
   return ([ C_RAW, C_COAL ]);
}

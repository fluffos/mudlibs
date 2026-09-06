inherit "/obj/seed";

NAME("pine cone")
DISTANT( "a pine cone" )
SPECIFIC( "the pine cone" )
LOOK( "A small, brownish-green pine cone. The interlaced bits of wood are so intricate as to give the impression of a finely sculpted piece of art." )
PLURAL( "pine cones" )
ALT_NAME( ({ "pine cone", "cone", "pine", "seed"}) )
ALT_PLURAL( ({ "cones", "pine cones", "seeds" }) )
TASTE( "What ~verbis ~pron, a squirrel?" )

void create() {
   ::create();
/* OBJEDIT { */
   set_plant_type( "/econ/trees/pinetree" );
   set_seed_strength( 10 );
/* } OBJEDIT */
}

ICON( '&', 0x8A, LAYER_ITEMS )

mapping query_aspects() {
   return ([ C_SEED, C_RAW, C_PINECONE ]);
}

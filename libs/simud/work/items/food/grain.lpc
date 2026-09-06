#include <const.h>
inherit "/obj/ingredient";

int grain_aspect;

string query_grain_type() {
   if( grain_aspect )
      return "/daemon/material"->query_aspect_string(grain_aspect);
   else
      return "refined grain";
}

TASTE( "Essential building blocks of nummy goodness." )
DISTANT( query_grain_type() )
NAME( query_grain_type() )
SPECIFIC( "the " + query_grain_type() )
// must id as 'wheat seed' or whatever for fields to work
ALT_NAME( ({ "grain", "refined " + query_grain_type(), query_grain_type() + " seed" }) )
ALT_PLURAL( ({ "grains", "refine " + query_grain_type() + "s", query_grain_type()+"s" }) )

LOOK( "It is some refined " + query_grain_type() + ", suitable for both planting and as food." )

// density of wheat is 780-800kg/m^3, corn is 760, barley is 600
WEIGHT( 760 )
BULK( 1000 )
GETTABLE( 1 )
DROPPABLE( 1 )

FOOD_VALUE( 2000 )   // per kilo

void create() {
   ::create();
   set_edible( 1 );
   set_solid( 1 );
}

int query_is_crop_seed() { return 1; }
string query_crop_type() { return "/econ/crop/"+query_grain_type(); }

void set_grain_aspect(int x) { grain_aspect = x; }
int query_grain_aspect() { return grain_aspect; }

void apply_aspect(int x) {
   if( member( ([ C_BARLEY, C_CORN, C_OATS, C_RICE, C_RYE, C_WHEAT ]), x ) )
      set_grain_aspect( x );
}

mapping query_aspects() {
   return ([ C_GRAIN, C_SEED ]) + ([ grain_aspect ]);
}

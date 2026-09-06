inherit "/obj/resource";
#include <const.h>

#ifndef ITEM_STR
#define ITEM_STR	"part"
#define ITEM_ASP	C_RAW
#endif
/*
 * All sub-parts must define these themselves
 *
WEIGHT( 89600 )
BULK( 10000 )
*/

int material_aspect;
string query_material_type() {
	if( material_aspect )
		return "/daemon/material"->query_aspect_string(material_aspect);
	else
		return "metal";
}

NAME( query_material_type()+" "+ITEM_STR )
DISTANT( query_material_type()+" "+ITEM_STR )
SPECIFIC( "the "+query_material_type()+" "+ITEM_STR )
PLURAL( query_material_type()+" "+ITEM_STR+"s" )

ALT_NAME( ({ ITEM_STR, "metal "+ITEM_STR }) )
ALT_PLURAL( ({ ITEM_STR+"s" , "metal "+ITEM_STR+"s" }) )

LOOK( capitalize(query_specific())+" is a generic crafting item, partway between raw "+query_material_type()+" and a usable product. More at 11." )
TASTE( "It tastes half baked." )


GETTABLE( 1 )
DROPPABLE( 1 )

ICON( '*', 0x88, LAYER_ITEMS )

void set_material_aspect(int x) { material_aspect = x; }
int query_material_aspect() { return material_aspect; }

void apply_aspect( int x ) {
   if( member( ([ C_ADAMANT, C_ALUMINUM, C_BRASS, C_BRONZE, C_COPPER, C_ELECTRUM,
                  C_GOLD, C_HARDENED_STEEL, C_IRON, C_LEAD, C_MITHRIL, C_NICKEL,
                  C_ORICHALCUM, C_PLATINUM, C_SILVER, C_STEEL, C_TIN, C_WHITE_GOLD,
                  C_ZINC ]), x ) ) {
		set_material_aspect( x );
   }
}	

mapping query_aspects() {
   return ([ ITEM_ASP, C_METAL ]) + ([ material_aspect ]);
}

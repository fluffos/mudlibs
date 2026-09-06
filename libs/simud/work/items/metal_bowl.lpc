#include <const.h>
#include <object.h>
#include <container.h>
#include <saveload.h>
#include <item.h>
#include <desc.h>

NAME( METAL_TYPE + " bowl" )
GETTABLE( 1 )
DROPPABLE( 1 )
WEIGHT( 700 )
DISTANT(A_METAL_TYPE + " bowl")
SPECIFIC("the " + METAL_TYPE + " bowl")
PLURAL(METAL_TYPE + " bowls")
ALT_NAME( ({ "metal bowl", "bowl" }) )
ALT_PLURAL( ({ "bowls", "metal bowls" }) )
LOOK( "This bowl is formed from a single sheet of " + METAL_TYPE + ", carefully pounded into a bowl shape.?(HASINV: Sitting in the base of the bowl $(ISINV) $(INV))" )
TASTE( "It tastes like its shape could be represented using a second order bezier curve, but only if the control polygon has weighted vertices." )

int query_bulk_capacity() {
   return 4000;
}

int query_weight_capacity() {
   return 35000;
}

object container_id( string val ) {
   return present( val, this_object() );
}

// Unaffected by heat, but passes the heat onto its contents
void on_heat( int temp ) {
   object ob;

   foreach( ob : all_inventory(this_object()) )
      ob->on_heat(temp);
}

mapping extra_aspects = ([ ]);

mapping query_aspects() {
   return ([ C_METAL ]) + extra_aspects;
}

void on_craft( object *materials ) {
   object ob;
   mapping m;

   extra_aspects = ([ ]);
   foreach( ob : materials ) {
      m = ob->query_aspects();
      if( mappingp(m) ) extra_aspects += m;
   }
   extra_aspects -= ([ C_RAW ]);
}

ICON( 'o', 0x88, LAYER_ITEMS )
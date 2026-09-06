#include <const.h>
#include <container.h>
#include <shape.h>
inherit "/obj/scenery";

DISTANT( "an automatic brick forge" )
SPECIFIC( "the brick forge" )
LOOK( "A strange mechanical forge has been built here; if you place broken weapons in them, they will be repaired!?(HASINV: Being repaired inside the forge $(ISINV) $(INV))." )
PLURAL( "forges" )
NAME( "forge" )
ALT_NAME( ({"brick forge"}) )
PHRASE( "An automatic brick forge has been built ~plac, and is working away mechanically." )
ASPECT( ([ C_FORGE, C_TOOL ]) )

void create() {
    ::create();
    set_position( "here" );
    set_preposition( "inv" );
    call_out( "repair_contents", 30 );
 }


void repair_contents() {
   object ob;

   // So that if it gets called externally, we don't
   // increase repair speed!
   remove_call_out( "repair_contents" );
   call_out( "repair_contents", 30 );

   foreach( ob : all_inventory(this_object()) ) {
      ob->set_condition(500);
  }
}

void on_map_paint( object painter ) {
   painter->paint_shape( query_x(), query_y(), "#####", 0x10, LAYER_WALL );
   painter->paint_shape( query_x(), query_y()+1, "#\t\t\t#", 0x10, LAYER_WALL );
   painter->paint_shape( query_x(), query_y()+1, "\t{\t}\t", 0x07, LAYER_WALL );
   painter->paint_shape( query_x(), query_y()+1, "\t\t#\t\t", 0x03, LAYER_WALL );
}

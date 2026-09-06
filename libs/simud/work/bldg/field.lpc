inherit "/econ/building";
inherit "/world/game/farming";
#include <const/shapeconst.h>
#include <const/roomconst.h>

NAME( "field" )
ALT_NAME( ({ query_crop_name() + " field" }) )
DISTANT( "a "+query_crop_name()+" field" )
LOOK( "A field of "+query_crop_name()+"." )
SPECIFIC( "the field" )
PLURAL( query_crop_name()+" fields" )
ALT_PLURAL( ({ "fields" }) )
TYPE( "field" )
PHRASE( capitalize(query_crop_name())+" is being grown in a field." )

string query_look() {
   string owner;

   owner = query_owner();
   return ::query_look() + "\n" +
      get_field_string() +
      "This field belongs to $(OWNER)";
}

create() {
   ::create();
/* OBJEDIT { */
   set_position( "here" );
   set_preposition( "on" );
/* } OBJEDIT */
}

void on_map_paint( object painter ) {
   painter->paint_shape( query_x(), query_y(), ":'''''''':\n:\t\t\t\t\t\t\t\t:\n:\t\t\t\t\t\t\t\t:\n:\t\t\t\t\t\t\t\t:\n:........:", 0x32, LAYER_ROUGH );
   painter->paint_shape( query_x()+1, query_y()+1, "'.'.'.'.\n.'.'.'.'\n'.'.'.'.", 0x3A, LAYER_ROUGH );
}

mapping query_shape() {
   return SHAPE_BOX( 10, 5 );
}

void on_craft( object *objs ) {
   object iob;

   foreach( iob : objs ) {
      if( iob->query_is_crop_seed() ) {
         set_crop_type( iob->query_crop_type() );
         add_seeds( iob->query_quantity() );
      }
   }
   if( !query_crop_type() )
      debug( "No crop type! Field could not find seeds to get started with." );
}

void on_build() {
   // Could vary this by fertility, etc...
   setup_weeds( 20 );
}

int on_use( object ob ) {
   if( ob ) return 0;
   if( this_player()->query_name() != query_owner() ) {
      msg( "This field is not yours!" );
      return 1;
   }

   show_field();
   enter_farming();

   return 1;
}

inherit "/world/exit/basedoor";

TYPE( "hole" )
DISTANT( "a hole" )
SPECIFIC( "the hole" )
LOOK( "It's a hole in the ground." )
PLURAL( "holes" )

/** Draw the exit. This adds the capability of drawing a closed (+) door.
 */
void on_paint( object painter ) {
   int p;
   mapping draw_shape = MCALL(exit_shape());

   if( !draw_shape ) return;
   foreach( p : draw_shape )
      painter->paint( CX(p)-4096, CY(p)-4096, query_dir()=="up"?'<':'>', 0x0F, LAYER_ROUGH );
}

inherit "/scn/water/waterpatch";

mapping deep_spots = ([ ]);

NAME( "pool" )
TYPE( "water" )
SPECIFIC( "the deep water" )
DISTANT( "deep water" )
LOOK( "Non-descript deep water" )

void add_spot( int pos ) {
   if( member(spots,pos) )
      deep_spots += ([ pos ]);
   ::add_spot( pos );
}

void remove_spot( int pos ) {
   ::remove_spot(pos);
   deep_spots -= ([ pos ]);
}

void set_deep_spots( mapping m ) {
   if( !m ) m = ([ ]);
   if( mappingp(m) ) deep_spots = m;
}

mapping query_deep_spots() {
   return deep_spots;
}

void on_map_paint( object painter ) {
   int pos;

   foreach( pos : spots ) {
      if( member(deep_spots,pos) )
         painter->paint( CX(pos), CY(pos), 'o', 70, LAYER_WATER );
      else
         painter->paint( CX(pos), CY(pos), '.', 70, LAYER_GROUND );
   }
}

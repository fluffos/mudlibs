/**
 * This is a really basic outside room. It has rocks and that's about all.
 * @author Ceres
 */

#define CREATOR "Ceres"

inherit OUTSIDE_OBJ;

mixed do_get_rock( string verb, object *dest ) {
  int rock_size;
  string rock_type;
  object rock;
  if ( query_property( "rock object" ) )
    return ( rock = clone_object( (string)query_property( "rock object" ) ) );
  if ( undefinedp( rock_size = (int)query_property( "rock size" ) ) )
    rock_size = 3;
  if ( !rock_size ) return 0;
  rock = clone_object( "/obj/mineral" );
  if ( undefinedp( rock_type = (string)query_property( "rock type" ) ) )
    rock_type = ({ "cinnabar", "coal", "rosy-quartz", "chalk", "flint",
                   "slate" })[ random( 6 ) ];
  rock->make_mineral( rock_type, 1 + random( rock_size ) );
  if ( !( rock->move( this_player() ) ) ) return 1;
  rock->dest_me();
  return 0;
}

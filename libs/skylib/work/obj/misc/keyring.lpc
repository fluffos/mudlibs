inherit "/std/container";

void setup() {
   set_name( "keyring" );
   set_short( "keyring" );
   /* It's best to have this, just in case something happens because of a key. */
   add_property( "determinate", "a " );
   add_alias( "ring" );
   add_adjective( "key" );
   set_main_plural( "keyrings" );
   add_plural( "rings" );
   add_property("shop type", "jewellers");
   /* Feel free to override this and make it more interesting. */
   set_long( "This is a ring of metal that overlaps itself at one point, "
         "allowing keys to be strung onto it and be kept together.  It's "
         "amazing how useful a ring of metal can be.\n" );
   set_weight( 2 );
   set_value( 20 );
   set_max_weight( 25 );
} /* setup() */

string long( string word, int dark ) {
   return ::long( word, dark ) +
         query_contents( "$C$"+ the_short() +" holds: " );
} /* long() */

mapping query_properties() {
   object thing;
   mixed arg, *args;
   mapping props, map;
   props = ::query_properties();
   args = copy( keys( props ) );
   foreach ( thing in find_inv_match( "", this_player() ) ) {
      map = (mapping)thing->query_properties();
      foreach ( arg in keys( map ) ) {
         if ( !stringp( arg ) ) {
            continue;
         }
         if ( member_array( arg, args ) != -1 ) {
            continue;
         }
         props[ arg ] = map[ arg ];
         args += ({ arg });
      }
   }
   return props;
} /* query_properties() */

mixed query_property( string word ) {
   object thing;
   mixed arg;

   arg = ::query_property( word );
   if ( arg ) {
      return arg;
   }
   foreach ( thing in find_inv_match( "", this_player() ) ) {
      arg = (mixed)thing->query_property( word );
      if ( arg ) {
         return arg;
      }
   }
   return 0;
} /* query_property() */

int test_add( object thing, int flag ) {
   if ( !thing->id( "key" ) && environment( thing ) ) {
      return 0;
   }
   return 1;
} /* test_add() */

mapping query_static_auto_load() {
   if ( explode( file_name(), "#" )[ 0 ] == "/obj/misc/keyring" ) {
      return int_query_static_auto_load();
   }
   return ([ ]);
} /* query_static_auto_load() */

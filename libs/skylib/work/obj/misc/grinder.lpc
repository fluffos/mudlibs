#define STATE_CHANGE "/handlers/state_change"

inherit "/std/object";

void setup() {
  set_name( "grinder" );
  set_short( "food grinder" );
  add_adjective( "food" );
  set_main_plural( "food grinders" );
  set_long( "This is a mechanical contraption to grind food into small "+
      "pieces.  There is a funnel-type piece at the top, a crank on one "+
      "side and a pipe where the ground food comes out on another.  You "+
      "could probably \"grind\" food in it.\n" );
  set_value( 4000 );
  set_weight( 100 );
} /* setup() */

void init() {
  this_player()->add_command( "grind", this_object(), "%I 'in' %D" );
} /* init() */

int do_grind( object *things ) {
  int i;
//  mapping amount_types;
  object ground;

  if ( living( environment() ) ) {
    this_player()->add_failed_mess( this_object(), "You have to put down "+
        "$D to use it.\n", ({ }) );
    return 0;
  }
  for ( i = 0; i < sizeof( things ); i++ )
    if ( environment( things[ i ] ) != this_player() ) {
      things = delete( things, i, 1 );
      i--;
    }
  if ( !sizeof( things ) ) {
    this_player()->add_failed_mess( this_object(), "You should be carrying "+
        "whatever you want to grind in $D.\n", ({ }) );
    return 0;
  }
  if ( sizeof( things ) > 1 ) {
    this_player()->add_failed_mess( this_object(), "You should only grind "+
        "one thing at a time in $D in case they get mixed up.\n", ({ }) );
    return 0;
  }
  ground = STATE_CHANGE->transform( things[0], "grind" );
  if ( !objectp( ground )) {
    this_player()->add_failed_mess( this_object(), "You cannot grind $I "+
        "in $D.  Trust me on this.\n", ({ things[ 0 ] }) );
    return 0;
  }
  things[ 0 ]->move( "/room/rubbish" );
  ground->move( environment() );
  this_player()->add_succeeded_mess( this_object(), "$N use$s $D to grind and make $I.\n",
      ({ ground }) );
  return 1;
} /* do_grind() */

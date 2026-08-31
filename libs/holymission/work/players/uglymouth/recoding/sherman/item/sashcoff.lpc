#define STD_LONG "This ebony coffin has a small gold plaque on it "\
  "lid which reads \"R.I.P. Count Sashya\". Along its bottom you "\
  "notice tiny magical symbols carved in the wood. They make "\
  "you feel the coffin radiates an elusive evil power."
#define CORNERS ({ "upper left", "upper right", "lower left",\
  "lower right" })
#define BLESSINGS ({ "holy water", "silver cross" })

inherit "/obj/container";

int *lighted;
int blessed;

void reset( int arg ) {
  ::reset( arg );
  if( arg ) return;
  set_name( "black coffin" );
  set_alias( "coffin" );
  set_short( "A black coffin" );
  set_long( STD_LONG + "\n" );
  set_lid_name( "lid" );
  set_can_get( 0 );
  set_only_for( "sashya" );
  lighted = ({ 0, 0, 0, 0 });
  blessed = ({ 0, 0 });
}

void init() {
  ::init();
  add_action( "do_put", "put" );
  add_action( "do_put", "place" );
  add_action( "do_burn", "burn" );
}

void update_long() {
  string desc;
  int i;

  desc = STD_LONG;
  for( i=0; i<4; i++ )
    if( lighted[i] )
      desc += sprintf( "A white candle burns at its %s corner.",
        CORNERS[i] );
  desc += blessed[0] ? " It has been blessed with holy water." : "";
  desc += blessed[1] ? " It has been blessed with a silver cross." : "";
  desc += "\n";
  set_long( desc );
}

int do_put( string str ) {
  string what, how;

  if( !str ) return 0;
  if( sscanf( str, "%s %s", what, how ) != 2 ) return 0;
  if( what != "white candle" && what != "candle" &&
      what != "holy water" && "what != "water" &&
      what != "silver cross" && what != "cross" )
    return 0;
  switch( what ) {
    case "white candle":
    case "candle":
      return place_candle( how );
    case "holy water":
    case "water":
      return place_holy water( how );
  }
  return place_cross( how );
}

int place_candle( string str ) {
  string which;
  object candle;

  if( sscanf( str, "at %s corner", which ) != 1 ) {
    notify_fail( "You musty place a white candle at each corner.\n" );
    return 0;
  }
  if( which != "upper left" && which != "upper right" &&
      which != "lower left" && which != "lower right" ) {
    notify_fail( "There are only the upper left, upper right, "
      + "lower left and lower right corners to choose from.\n" );
    return 0;
  }
  if( lighted[ member_array( which, CORNERS ) ] ) {
    notify_fail( "A white candle already burns at that corner.\n" );
    return 0;
  }
  if( !( candle = present( "candle", this_player() ) ) ) {
    notify_fail( "You don't seem to have any candles.\n" );
    return 0;
  }
  if( !candle->id( "white candle" ) ) {
    notify_fail( "You feel that you need white candles for this.\n" );
    return 0;
  }
  if( !candle->query_lighted() ) {
    notify_fail( "You better light it first.\n" );
    return 0;
  }
  lighted[ member_array( which, CORNERS ) ] = 1;
  destruct( candle );
  update_long();
  printf( "You put a lighted white candle at the %s corner.\n",
    which );
  say( sprintf( "%s puts a lighted white candle at the %s corner "
    + "of the coffin.\n", this_player()->query_name(), which ),
    this_player() );
  return 1;
}

int place_holy_water( string str ) {
  string what;
  object water;

  if( sscanf( str, "around %s", what ) != 1 ) {
    notify_fail( "You must put holy water around the coffin.\n" );
    return 0;
  }
  if( !id( what ) ) {
    notify_fail( "That would be a waste of good holy water.\n" );
    return 0;
  }
  if( !( water = present( "holy water", this_player() ) ) ) {
    notify_fail( "You don't seem to have any holy water.\n" );
    return 0;
  }
  if( blessed[ member_array( "holy water", BLESSINGS ) ] ) {
    notify_fail( "Someone already blessed the coffin with holy water.\n" );
    return 0;
  }
  blessed[ member_array( "holy water", BLESSINGS ) ] = 1;
  destruct( water );
  update_long();
  printf( "You bless the coffin by sprinkling holy water around it.\n" );
  say( sprintf( "%s blesses the coffin by sprinkling holy water around it.\n",
    this_player()->query_name() ), this_player() );
  return 1;
}

int place_cross( string str ) {
  string what;
  object cross;

  if( sscanf( str, "on %s", what ) != 1 ) {
    notify_fail( "You must put a silver cross on the coffin.\n" );
    return 0;
  }
  if( !id( what ) ) {
    notify_fail( "Don't. You just might lose a valuable item.\n" );
    return 0;
  }
  if( !( cross = present( "silver cross", this_player() ) ) ) {
    notify_fail( "You don't seem to have any holy water.\n" );
    return 0;
  }
  if( blessed[ member_array( "silver cross", BLESSINGS ) ] ) {
    notify_fail( "Someone already blessed the coffin with a "
      + "silver cross.\n" );
    return 0;
  }
  blessed[ member_array( "silver cross", BLESSINGS ) ] = 1;
  transfer( cross, this_object() );
  update_long();
  printf( "You bless the coffin by putting a silver cross on top of it.\n" );
  say( sprintf( "%s blesses the coffin by putting a silver cross on it.\n",
    this_player()->query_name() ), this_player() );
  return 1;
}

int do_burn( string str ) {
  if( !id( str ) ) {
    notify_fail( "Burn what?\n" );
    return 0;
  }
  if( !present( "torch", this_player() ) ) {
    notify_fail( "You don't have anything to start a fire with.\n" );
    return 0;
  }
  if( !present( "torch", this_player() )->query_lighted() ) {
    notify_fail( "To have something burning to start with would help...\n );
    return 0;
  }
  if( lighted[0] + lighted[1] + lighter[2] + lighter[3] != 4 ) {
    notify_fail( "The black powers of darkness drive back the mundane "
      + "flames of your torch. Search for lights to break this spell.\n" );
    return 0;
  }
  if( !blessed[0] ) {
    notify_fail( "You need a holy barrier to prevent this evil soul from "
      + "escaping to settle elsewhere and start its evil doings anew.\n" );
    return 0;
  }
  if( !blessed[1] ) {
    notify_fail( "You need a symbol of faith to destroy the very essence "
      + "of evil that will be hovering in the flames.\n" );
    return 0;
  }
  present( "sashya", this_object() )->move_to_coffin();
  present( "silver cross" )->drain_evil();
  printf( "As your torch lights the coffin, a line of bright white flames "
    + "arised between the candles surrounding the coffin. The flames of "
    + "the coffin itself are hardly visible through the jet black clouds "
    + "of smoke engulfing it. A little bright red spark twinkles through "
    + "the dark gases where you placed the cross on the coffin. After a "
    + "while nothing but ashes remain.\n" );
  say( sprintf( "As %s lights the coffin, a line of bright white flames "
    + "arised between the candles surrounding the coffin. The flames of "
    + "the coffin itself are hardly visible through the jet black clouds "
    + "of smoke engulfing it. A little bright red spark twinkles through "
    + "the dark gases where you placed the cross on the coffin. After a "
    + "while nothing but ashes remain.\n", this_player()->query_name() ),
    this_player() );
  destruct( this_object() );
  return 1;
}


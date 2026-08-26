inherit WEAPON_OBJ;

int wrapped;

void setup() {
   set_name( "chain" );
   set_short( "iron chain" );
   add_adjective( "iron" );
   set_main_plural( "iron chains" );
   set_long( "This is a heavy iron chain with thick links, about two "+
            "feet long in all.\n" );
   set_value( 100 );
   set_weight( 90 );
   set_wield_func( "check_wrapped", file_name( this_object() ) );
   new_weapon( 45000 );
   set_damage_chance( 6 );
   add_attack( "whip", 75, ({ 20, 2, 25 }), "blunt", "blunt" );
   add_attack( "sharp", 5, ({ 20, 4, 20 }), "sharp", "sharp" );
} /* setup() */

int query_wrapped() { return wrapped; }

void set_wrapped() {
   wrapped = 1;
   remove_attack( "whip" );
   add_attack( "hands", 50, ({ 30, 3, 35 }), "blunt", "blunt" );
   add_extra_look( this_object() );
} /* set_wrapped() */

void reset_wrapped() {
   wrapped = 0;
   remove_attack( "hands" );
   add_attack( "whip", 75, ({ 20, 2, 25 }), "blunt", "blunt" );
   remove_extra_look( this_object() );
} /* reset_wrapped() */

int check_wrapped( object thing ) {
  if ( !thing )
    reset_wrapped();
  return 1;
} /* check_wrapped() */

int query_ambush_bonus() { return 100; }

string query_ambush_mess() {
  if ( wrapped )
    return "smash";
  return "whip";
} /* query_ambush_mess() */

string extra_look( object thing ) {
  return "The chain is currently wrapped around your fist.\n";
} /* extra_look() */

void init() {
  this_player()->add_command( "pull", this_object() );
  this_player()->add_command( "wrap", this_object(), "%D 'around' 'fist'" );
  this_player()->add_command( "unwrap", this_object() );
} /* init() */

int do_pull() {
  object *hands;
  if ( query_wielded() != this_player() ) {
    this_player()->add_failed_mess( this_object(), "You need to be "+
        "holding $D to pull it.\n", ({ }) );
    return 0;
  }
  hands = (object *)this_player()->query_holding() -
      ({ this_object() });
  if ( sizeof( hands ) )
    if ( hands[ 0 ] ) {
      this_player()->add_failed_mess( this_object(), "You need your "+
          "other hand to be free to pull $D.\n", ({ }) );
      return 0;
    }
  if ( wrapped ) {
    this_player()->add_failed_mess( this_object(), "$D is currently "+
        "wrapped around your fist.\n", ({ }) );
    return 0;
  }
  this_player()->add_succeeded_mess( this_object(), "$N $V $D which "+
      "clanks loudly as it goes taut.\n", ({ }) );
  return 1;
} /* do_pull() */

int do_wrap() {
  if ( query_wielded() != this_player() ) {
    this_player()->add_failed_mess( this_object(), "You need to be "+
        "holding $D to wrap it around your fist.\n", ({ }) );
    return 0;
  }
  if ( wrapped ) {
    this_player()->add_failed_mess( this_object(), "$D is already wrapped "+
        "around your fist.\n", ({ }) );
    return 0;
  }
  set_wrapped();
  this_player()->add_succeeded_mess( this_object(), "$N $V $D around "+
      "$p fist.\n", ({ }) );
  return 1;
} /* do_wrap() */

int do_unwrap() {
  if ( !wrapped ) {
    this_player()->add_failed_mess( this_object(), "$D is not wrapped "+
        "around your fist.\n", ({ }) );
    return 0;
  }
  reset_wrapped();
  this_player()->add_succeeded_mess( this_object(), "$N $V $D from around "+
      "$p fist.\n", ({ }) );
  return 1;
} /* do_unwrap() */

mapping query_dynamic_auto_load() {
  return ([
    "::" : ::query_dynamic_auto_load(),
    "wrapped" : wrapped,
  ]);
} /* query_dynamic_auto_load() */

void init_dynamic_arg( mapping map ) {
  ::init_dynamic_arg( map[ "::" ] );
  if ( map[ "wrapped" ] )
    set_wrapped();
} /* init_dynamic_arg() */

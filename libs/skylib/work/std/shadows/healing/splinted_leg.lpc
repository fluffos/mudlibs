inherit "/std/effect_shadow";

int delayed;

/** @ignore yes */
string query_msgin() {
  return "$N hobble$s in from $F.";
}

/** @ignore yes */
string query_msgout() {
  delayed = 1;
  call_out( "delay_off", 5 );
  return "$N hobble$s $T.";
}

/** @ignore yes */
int cannot_walk() {
  if( delayed ) {
    tell_object( player, "You are too tired to walk.\n" );
    return 1;
  }
  else return player->cannot_walk();
}

/** @ignore yes */
void delay_off() { delayed = 0; }

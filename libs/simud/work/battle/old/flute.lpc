#include <const/battconst.h>
#include <weapon.h>

create() {
  ::create();
/* OBJEDIT { */
   set_weapon_type( "special" );
   set_condition( 1000 );
   set_enchanted( 1 );
   set_gettable( 1 );
   set_droppable( 1 );
   set_height( 30 );
   set_width( 3 );
   set_depth( 3 );
   set_weight( 50 );
   set_bulk( 150 );
   set_value( 50000 );
   set_distant( "the Flute of Amiboshi" );
   set_specific( "the flute of Amiboshi" );
   set_name( "flute" );
   set_type( "weapon" );
/* } OBJEDIT */
}

int do_hit(object *target) {
  int x;
  this_player()->msg_local("~Name ~verbplay a mind altering tune on the Flute of Amiboshi.");
  for (x = 0; x < sizeof(target); x++) {
    set_target(target[x]);
    this_player()->msg_local("~Targ ~vertshriek in pain as ~post life force is assaulted!");
    target[x]->take_damage(DAM_MENTAL, 10);
  }
  this_player()->add_readiness(-500);
  return 1;
}

int do_wield() {
  set_target(this_object());
  this_player()->msg_local("~Name ~verbplace the ~Targ to ~poss lips in preparation for combat.");
  this_object()->set_wielded(1);
  return 1;
}

int do_unwield() {
  set_target(this_object());
  this_player()->msg_local("~Name ~verblower the ~Targ.");
  this_object()->set_wielded(0);
  return 1;
}

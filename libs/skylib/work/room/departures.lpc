/*  -*- LPC -*-  */
/*
 * $Locker: pinkfish $
 * $Id: departures.c,v 1.7 2000/06/22 03:00:56 pinkfish Exp pinkfish $
 *
 *
 */

/*  /std/departures.c

    Change log:

    30/11/93 - copied from void.c as an idea for quitting
                by Ember
    12/12/92 - Modified by Godot to put in a red button because one of 
               his storerooms filled the place up one day.
    17/10/95 - Modified by Ceres to add event_enter check so if people
               login here they get transed to the drum.
               Oh, also tidied the code somewhat and deleted most of the
               unnecessariness.
*/
#include <config.h>
inherit "/std/room/basic_room";

int squish(string cmd);

void setup() {
  set_co_ord(({0,0,-1000})); // somewhere way beneath the world.
  set_light(100);
  set_short(mud_name()+"'s departure lounge");
  set_long("This is a small room.  Talk about boring.\n");

  /* It seems a couple of players have managed to mark this place
   * a teleport location.  */
  add_property( "no teleport", 1 );
  set_keep_room_loaded(1);
} /* setup() */

// prevents people doing things they shouldn't in here. It will screw up their
// start position and allow them to use this to trans to the drum.
void init() {
  ::init();
  if (!this_player()) {
    return;
  }
  this_player()->command_override((: squish :));
} /* init() */

int squish(string cmd) {
  if (cmd == "quit" ||
      cmd == "quit2" ||
      cmd == "save" ||
      cmd == "rescue" ||
      cmd == "su") {
    write( "Fat chance, bozo.\n" );
    return 1;
  } else {
    return 0;
  }
} /* squish() */

// if they enter from nowhere (and they aren't greco!) then throw them
// into the drum.  This prevents people logging in and being stuck here.
// Ceres - 1/11/95
void event_enter(object ob, string message, object from) {
  if(!from && interactive(ob)) {
    write("You shouldn't be in here.%^RESET%^\n"
          "You get teleported back to the Pub.\n");
    ob->move(CONFIG_START_LOCATION);
  }
} /* event_enter() */

int test_add( object thing, int flag ) {
  if(base_name(thing) != "/global/player" &&
     base_name(thing) != "/global/creator" &&
     base_name(thing) != "/global/lord") {
    call_out( "destroy_thing", 60, thing );
  }
  return 1;
} /* test_add() */

void destroy_thing(object thing) {
  if(!thing) {
    return;
  }

  thing->move("/room/rubbish");
} /* destroy_thing() */

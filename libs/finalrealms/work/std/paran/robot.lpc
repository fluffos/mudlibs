inherit "obj/monster";

int count,
    move_every_heart_beat;
/*
 * ok this does the standard robot.... will move every no heart_beats,
 * When it does it calls the function do_move.
 * once there it calls the function, we_arrived.
 */

heart_beat() {
  if (move_every_heart_beat)
    if (count++>move_every_heart_beat) {
      do_move();
      count = 0;
    }
  ::heart_beat();
}

create() {
  add_property("robot");
  ::create();
}

do_move() {
  string *dirs;

  if (environment()) {
    dirs = environment()->query_dest_dir();
    command(dirs[random(sizeof(dirs))]);
    we_arrived();
  }
}

we_arrived() {
}

query_move_every_heart_beat() { return move_every_heart_beat; }
set_move_every_heart_beat(arg) { move_every_heart_beat = arg; }

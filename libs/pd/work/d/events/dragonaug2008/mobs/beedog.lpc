#include <std.h>
#include <dragonevent.h>

inherit MONSTER;

int hound_die(object);

int chewing;

void create() {
  ::create();
  set_name("hound");
  set_short("A giant %^RESET%^%^RED%^h%^BOLD%^o%^RESET%^%^RED%^u%^BOLD%^n%^RESET%^%^RED%^d");
  set_long("An incredibly large hound with dark red fur and bright yellow eyes.");
  set_level(500);
  set_race("hound");
  set_body_type("dog");
  set_die( (: hound_die :) );
  chewing = 0;
}

int hound_die(object ob) {
  object env = environment(this_object());
  if(file_name(env)[0..sizeof(DRAG_ROOMS"py/6")-1] != DRAG_ROOMS"py/6") return 0;

  message("info", "As the dog dies, you notice that it was covering a hole in the ground.", env);
  message("info", "%^BOLD%^%^CYAN%^You notice a %^YELLOW%^beehive%^CYAN%^ on the hound's corpse!", env);

  env->add_exit(DRAG_ROOMS"py/8", "down");
  return 1;
}

void heart_beat() {
  ::heart_beat();
  if(!this_object()) return;

  if(chewing) {
    if(!present("bone")) {
      message("info", "The hound's bone has been stolen from it. It snarls in anger!", environment());
      force_me("kill all");
      chewing = 0;
    }
    else if(random(10000) < 170)
      message("info", "The hound gnaws happily on its bone.", environment());
  }
  else {
    if(present("bone")) {
      message("info", "The hound happily starts to chew on its bone.", environment());
      chewing = 1;
    }
  }
}


#include <std.h>
#include <id4.h>

inherit MONSTER;

void someone_listened(string what);

int said = 0;

string startmsg =
  "Some of my friends have been imprisoned somehow! "+
  "You've got to help me find them!";

void create() {
  ::create();
  set_name("little dragon");
  set_id( ({ "id4_dragon", "dragon" }) );
  set_short("a little dragon");
  set_long(
    "This small black dragon stands about as tall as a "
    "grown man. His wings flutter nervously as he looks "
    "around for someone to listen to him."
  );
  set_gender("male");
  set_race("dragon");
  set_class("dragon");
  set_subclass("black");
  set_body_type("dragon");
  set_alignment(0);
  set_level(15);
  /*
  set_says(1,
    ({ "Will somebody help me?",
       "I need some help, oh please!",
       "Won't anyone listen to my trouble?",
    }),
    0
  );
  set_listen("default", (: someone_listened :) );
  set_listen("trouble", (: someone_listened :) );
  */
}

void heart_beat() {
  ::heart_beat();
  if (!this_object()) return;
  if (!random(9)) said = 0;
}

void catch_tell(string str) {

  return;
  str = strip_color(str);

  if (said || !regexp(str, ".+ (says|asks|exclaims): .+"))
    return;

  said = 1;
  if (regexp(str, "help")) {
    command("say "+startmsg);
  }
  if (regexp(str, "find|imprisoned|where")) {
    command("say "+
      "I don't know where they are exactly. It smelled kind of "
      "damp and earthy, but I couldn't track them down.");
    command("say "+
      "Oh, who would dare do this to my brothers?");
  }

}

void someone_listened(string what) {
  command("say Thank you for listening, "+this_player()->query_cap_name()+"!");
  command("say "+startmsg);
}


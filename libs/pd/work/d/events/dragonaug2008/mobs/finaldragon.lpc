
#include <std.h>
#include <dragonevent.h>
#include <rooms.h>

inherit MONSTER;

mixed *speeches = ({
({
  "",
  "emote gets up slowly.",
  "say Oh...",
  "emote looks around.",
  "say Thank you so much!",
  "say I can't believe those ogres managed to catch me!",
  "say I was only trying to help stop the ogres, but I guess I'm not "
    "big enough yet.",
  "say I feel so foolish, after what happened to my friends before...",
  "emote looks abashed.",
  "say I'm sorry for all the trouble this must have caused.",
  "say You've done so much for us, I will talk to my father and our elder "
    "and see if there is anything we can do for you.",
  "",
  "",
  "",
  "",
}),
});

int speechcounter = -1;
int speed = 1;
object pl;

void set_speech(int x) {
  if (x < -1 || x >= sizeof(speeches)) x = -1;
  DRAG_D->set_data("speechfinaldragon", x);
}
void start_speech() { speechcounter = 0; }
void stop_speech() { speechcounter = -1; }
int query_speech() { return DRAG_D->query_data("speechfinaldragon"); }

void create() {
  ::create();
  set_property("passive", 1);
  set_name("little black dragon");
  set_id( ({ "dragon", "black dragon", "little black dragon", "little dragon" }) );
  set_short("a little black dragon");
  set_long(
    "This small black dragon stands about as tall as a grown man. "
    "He looks a little bit shaken from being kidnapped and imprisoned."
  );
  set_race("dragon");
  set_class("dragon");
  set_subclass("black");
  set_body_type("dragon");
  set_gender("male");
  set_level(25);
  set_spell_chance(80);
  set_spells( ({ "claw", "annihilate", "shadowfang", "void", "bite" }) );
  set_heart_beat(8);
  speed = 8;
}

void heart_beat() {
  string *sentences;
  object ob, tp, env;
  int ok = 0;
  int test;
  ::heart_beat();
  if (!this_object()) return;

  set_heart_beat(speed);
  env = environment();
  test = DRAG_D->query_data("testing");

  if (speechcounter > -1 && query_speech() > -1) {

    if (env && sizeof(filter(all_inventory(env), (: $1->is_player() :) )))
      ok = 1;

    sentences = speeches[query_speech()];

    switch (query_speech()+":"+speechcounter) {

      case "0:0":
        if (!ok) return;
        message("emote", "%^YELLOW%^As the last beam of light recedes, "
                         "the black dragon falls to the floor.%^RESET%^", env);
      break;

      case "0:11":
        if (!ok) return;
        command("shield me");
        move(ROOM_CACHE);
        message("mout", "The black dragon leaves for home.", env);
        speed = 5;
      break;

      case "0:12":
        move(DRAG_ROOMS+"summit");
        message("min", "A little black dragon arrives.",
          load_object(DRAG_ROOMS+"summit"));
        set_mp(query_max_mp());
        command(test ? "say Woot!" : "fireworks");
      break;

      case "0:13":
        message("info", "%^YELLOW%^"
          "A chorus of cheers and roars goes up from the dragonlands!"
          "%^RESET%^", test ? DRAG_D : users() );
        foreach (object dr in filter(all_inventory(env), (: $1->id("dragon") :) )) {
          if (dr == this_object()) continue;
          dr->set_mp(dr->query_max_mp());
          dr->force_me(test ? "say Yay!" : "fireworks");
        }
      break;

      case "0:14":
        message("info", "%^YELLOW%^"
          "The dragon has been freed!"
          "%^RESET%^", test ? DRAG_D : users() );
      break;

      default:
      if (!ok) return;
      command(sentences[speechcounter]);

    }

    // advance to next line of this speech
    speechcounter++;
    if (speechcounter >= sizeof(sentences)) {
      speechcounter = -1;
      // at end of speech, automatically stop talking but advance
      //   to the next speech in the list
      set_speech(query_speech()+1);
      if (query_speech() > sizeof(speeches))
        set_speech(-1);
    }
  }
}


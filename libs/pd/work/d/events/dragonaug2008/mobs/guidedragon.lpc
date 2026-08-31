
#include <std.h>
#include <dragonevent.h>
#include <rooms.h>
#include <locations.h>

inherit MONSTER;

mixed *speeches = ({
({
  "",
  "",
  "",
  "say Hello my friends!",
  "say I was sent by the elder on an urgent errand...",
  "say You see, he intended to invite you, the mortals who helped save us, "
    "into the Dragonlands at long last.",
  "say Unfortunately, we have been harassed endlessly by the ogres who infest "
    "the caves below our lands.",
  "say With some terrible spell, one of their warlocks captured the son of our "
    "most powerful mage during the latest incursion.",
  "say The ogres make sure there is no entrance to their caves large enough for "
    "dragons to get through, so our warriors cannot follow them.",
  "say As if that weren't enough, they seem to have put up a magical barrier "
    "that keeps us from locating them or my friend!",
  "say We would greatly appreciate your help!",
  "say Please, our lands are far to the east, follow me and speak with our elder!",
  "",
  "",
  "say Come this way, our elder is on the summit.",
  "",
  "",
  "",
}),
({
  "emote grins.",
  "",
  "say Will you lead the way?",
}),
({
  "",
  "say What is this?",
  "look platform",
  "say What powerful magic!",
  "say There must be some way to counter this spell. Let's look around.",
  "",
}),
({
  "",
  "look pillar",
  "say This must be part of the ogres' spell!",
  "say I will go and tell our elder of this right away!",
  "",
  "",
  "",
}),
}); // end of speeches

int speechcounter = -1;
int speed = 1;

int dont_die(object);
int do_follow(string);
void stop_following();

void set_speech(int x) {
  if (x < -1 || x >= sizeof(speeches)) x = -1;
  DRAG_D->set_data("speechguidedragon", x);
}
void start_speech() { speechcounter = 0; }
void stop_speech() { speechcounter = -1; }
int query_speech() { return DRAG_D->query_data("speechguidedragon"); }

void create() {
  ::create();
  set_name("blue dragon");
  set_id( ({ "guide_dragon", "dragon", "blue dragon", "little blue dragon" }) );
  set_short("a little blue dragon");
  set_long(
    "This adolescent blue dragon is truly massive. She is shorter than "
    "a grown man, but twice as wide and four times the weight. She flutters "
    "her tiny wings every now and then."
  );
  set_gender("female");
  set_race("dragon");
  set_body_type("dragon");
  set_class("dragon");
  set_subclass("blue");
  set_level(28);
  set_skill("faith", 28*5);
  set_skill("conjuring", 28*3);
  set_max_hp(query_max_hp()*2);
  set_hp(query_max_hp());
  set_spell_chance(75);
  set_spells( ({
    "cure me", "shield me", "crystallize me", "wrap 50", "cure me", "spire",
  }) );
  set_says(15, ({
    "Help!",
    "Please protect me!",
  }), 1);
  set_emotes(15, ({
    "The little dragon looks scared.",
    "The little dragon tries to get away.",
  }), 1);
  set_emotes(1, ({
    "The little dragon flutters her wings.",
  }), 0);
  set_wimpy(40);
  set_die( (: dont_die :) );
  set_heart_beat(12);
  speed = 12;
}

int dont_die(object killer) {
  message("magic", "The little blue dragon mutters a spell of healing.",
    environment() );
  add_hp(600+random(100));
  return 0;
}

int is_invincible() {
  if (this_player() && this_player()->is_player())
    return 1;
  return 0;
}

void heart_beat() {
  object *pl;
  string *sentences;
  object env, fol, dr;
  int ok = 0;
  int test;
  ::heart_beat();
  if (!this_object()) return;

  set_heart_beat(speed);
  env = environment();
  test = DRAG_D->query_data("testing");

  if (env && fol = query_following()) {
    // query_speech returns the next speech to be run!
    switch (query_speech()) {
      case 2:
        if (file_name(env) == DRAG_ROOMS+"ogre120") {
          DRAG_D->set_data("canleadguidedragon", 0);
          speed = 5;
          start_speech();
          stop_following();
        }
      break;

      case 3:
        if (file_name(env) == DRAG_ROOMS+"ogre75") {
          DRAG_D->set_data("canleadguidedragon", 0);
          speed = 5;
          start_speech();
          stop_following();
        }
      break;
    }
    if (fol->is_linkdead() || !environment(fol) ||
        strsrch(base_name(environment(fol)), DRAG_ROOMS) != 0) {
          stop_following();
    }
  }

  // do the current speech if set and started
  if (speechcounter > -1 && query_speech() > -1) {

    if (env && sizeof(filter(all_inventory(env), (: $1->is_player() :) )))
      ok = 1;

    sentences = speeches[query_speech()];

    switch (query_speech()+":"+speechcounter) {

      case "0:0":
        pl = filter(users(), (:
          (environment($1) && !environment($1)->query_property("indoors")) :)
        );
        if (!sizeof(pl)) return;
        message("info", "%^BOLD%^%^WHITE%^"
          "A dragon can be seen flying towards Tirun from the east."
          "%^RESET%^", test ? DRAG_D : pl);
        // slow it down for a bit
        speed = 12;
      break;

      case "0:1":
        pl = filter(users(), (:
          (environment($1) && !environment($1)->query_property("indoors")) :)
        );
        if (!sizeof(pl)) return;
        message("info", "%^BOLD%^%^WHITE%^"
          "The dragon circles in the skies over Tirun."
          "%^RESET%^", test ? DRAG_D : pl);
      break;

      case "0:2":
        if (!ok) return;
        if (!test) move(SQUARE_LOC);
        message("min", "A little blue dragon flies down from above and lands.",
          test ? DRAG_D : SQUARE_LOC);
        speed = 8;
      break;

      case "0:12":
        if (!ok) return;
        move(ROOM_CACHE);
        // env is already set to the room he was in earlier
        message("mout", "The little blue dragon leaps into the air "
                        "and flies away east!", env);
        speed = 8;
      break;

      case "0:13":
        move(DRAG_ROOMS+"beach");
        message("min", "A little blue dragon flies down from above and lands.",
          DRAG_ROOMS+"beach");
        speed = 4;
      break;
        
      case "0:15":
        if (!ok) return;
        move(ROOM_CACHE);
        message("mout", "The little blue dragon leaves for the summit.", env);
      break;

      case "0:16":
        move(DRAG_ROOMS+"summit");
        message("min", "A little blue dragon enters.", load_object(DRAG_ROOMS+"summit"));
      break;

      case "0:17":
        if (!ok) return;
        dr = present("dragon elder", env);
        if (dr) {
          dr->set_speech(0);
          dr->start_speech();
        }
        speed = 2;
      break;

      // ---

      case "1:1":
        if (!ok) return;
        command("emote jumps into the water and starts swimming "
                "around to the south.");
        move(DRAG_ROOMS+"ogrebeach");
        message("min", "A little blue dragon swims in and climbs "
                       "onto the small beach.", DRAG_ROOMS+"ogrebeach" );
        DRAG_D->set_data("canleadguidedragon", 1);
        speed = 2;
      break;

      // ---

      case "2:0":
        speed = 5;
      break;

      case "2:5":
        speed = 1;
        DRAG_D->set_data("canleadguidedragon", 1);
      break;

      // ---

      case "3:0":
        speed = 6;
      break;

      case "3:4":
        if (!ok) return;
        move(ROOM_CACHE);
        message("mout", "The little blue dragon runs out.", env);
      break;

      case "3:5":
        message("min", "A little blue dragon runs in.", load_object(DRAG_ROOMS+"summit"));
        message("whisper", "The little blue dragon whispers something to the Elder Dragon.",
          load_object(DRAG_ROOMS+"summit"));
        message("mout", "The little blue dragon runs out.",
          load_object(DRAG_ROOMS+"summit"));
        dr = present("dragon elder", load_object(DRAG_ROOMS+"summit"));
        if (dr) {
          dr->set_speech(1);
          dr->start_speech();
        }
      break;

      case "3:6":
        move(DRAG_ROOMS+"dragnorth37");
        message("min", "A little blue dragon arrives.", env);
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

void init() {
  ::init();
  add_action("do_follow", "follow");
}

int do_follow(string str) {
  object tp = this_player();
  string who;
  if (!query_following() && DRAG_D->query_data("canleadguidedragon") &&
      str && sscanf(str, "allow %s", who) == 1 && id(who)) {
        command("say Ok, I'll follow you, "+tp->query_cap_name()+".");
        tp->add_follower(this_object());
        return 1;
  }
  return 0;
}

void stop_following() {
  object fol = query_following();
  if (fol) {
    fol->remove_follower(this_object());
    set_following(0);
  }
}


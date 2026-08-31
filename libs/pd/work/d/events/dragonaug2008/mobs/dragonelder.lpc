
#include <std.h>
#include <dragonevent.h>

inherit MONSTER;

mixed *speeches = ({
({
  "",
  "say Greetings.",
  "say We are pleased to finally meet the mortals who saved our young ones.",
  "say It grieves us to have to ask for your assistance once again.",
  "say I trust our message was delivered?",
  "",
  "emote sighs deeply.",
  "say Some of our swimmers have found a small opening into a cave. "
    "It is south around the coast, but it is too small for any of us to "
    "enter and it is covered over by rocks, so we cannot fly there.",
  "say We have seen your small boats and we believe you could make it inside.",
  "",
  "emote thinks carefully.",
  "say Very well. Please show them to the cave.",
  "say Many of us are eager to help, especially our most learned mage, who is "
    "the young one's father. Please ask us if you need anything.",
  "",
}),
({
  "say I was told of the magical pillar that you found.",
  "say I fear I do not know anything myself. However, our most learned mage "
    "can probably help.",
  "say Please go and see him. He is within the black dragons' lair.",
  "",
}),
}); // end of speeches

int speechcounter = -1;
int speed = 1;

void set_speech(int x) {
  if (x < -1 || x >= sizeof(speeches)) x = -1;
  DRAG_D->set_data("speechdragonelder", x);
}
int query_speech() { return DRAG_D->query_data("speechdragonelder"); }
void start_speech() { speechcounter = 0; }
void stop_speech() { speechcounter = -1; }

void create() {
  ::create();
  set_property("passive", 1);
  set_property("no bump", 1);
  set_name("dragon elder");
  set_id( ({ "dragon", "white dragon", "dragon elder", "elder" }) );
  set_short("an elder white dragon");
  set_long(
    "This dragon looks incredibly ancient. Her white scales glisten in "
    "the light, and her eyes glow with wisdom. She is the largest denizen "
    "of the Dragonlands."
  );
  set_gender("female");
  set_level(75);
  set_race("dragon");
  set_body_type("dragon");
  set_class("dragon");
  set_subclass("white");
  set_alignment(1500);
  set_spells( ({ "sunder", "claw", "swoop", "dragonfury", "solarflare" }) );
  set_spell_chance(35);
  set_heart_beat(6);
  speed = 6;
}

void heart_beat() {
  string *sentences;
  object env, dr;
  int ok = 0;
  ::heart_beat();
  if (!this_object()) return;

  if (query_rest_type()) { command("wake"); command("stand"); }

  set_heart_beat(speed);

  // do the current speech if set and started
  if (speechcounter > -1 && query_speech() > -1) {

    env = environment();
    if (env && sizeof(filter(all_inventory(env), (: $1->is_player() :) )))
      ok = 1;

    sentences = speeches[query_speech()];

    switch (query_speech()+":"+speechcounter) {

      case "0:0":
        speed = 3;
      break;

      case "0:5":
        if (!ok) return;
        message("emote", "The little blue dragon nods.", env);
      break;

      case "0:9":
        if (!ok) return;
        message("say", "The little blue dragon says: "
          "I'm small enough, I could show them the way!", env);
      break;

      case "0:13":
        if (!ok) return;
        dr = present("guide_dragon", env);
        if (dr) {
          message("mout", "The little blue dragon runs back to the beach.", env);
          dr->move(DRAG_ROOMS+"beach");
          message("min", "A little blue dragon runs in.", load_object(DRAG_ROOMS+"beach"));
        }
        dr->set_speech(1);
        dr->start_speech();
      break;

      // ---

      case "1:3":
        dr = present("dragon mage", load_object(DRAG_ROOMS+"dragnorth37"));
        if (dr) {
          dr->set_speech(0);
          dr->start_speech();
        }
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


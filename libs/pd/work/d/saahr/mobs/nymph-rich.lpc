// deed built in to this mob

#include <std.h>
#include <saahr.h>

inherit MONSTER;

int deed_done = 0;

void create() {
  ::create();
  set_name("nymph");
  set_race("nymph");
  set_body_type("human");
  set_gender("female");

  set_id(({"nymph"}));
  set_short("An older nymph");
  set_long(
    "This nymph has short auburn hair and a very pale complexion. "
    "She looks a little older than the other nymphs, though still "
    "much younger than any human of her age. Her clothes look "
    "to be of very high quality, as if she were wealthy."
  );

  set_class("wanderer");
  set_subclass("bard");
  set_level(35);
  
  set_skill("attack", 70);
  set_skill("melee", 70);
  set_skill("defense", 400);
  set_skill("euphony", 400);
  
  set_spells( ({
    "sing song of blades", "sing song of winter",
    "sing hymn of faeries", "sing song of darkness",
  }) );
  set_spell_chance(80);

  set_inventory( ([
    ARM+"nymphdress2" : "wear dress",
  ]) );

  set_emotes(2, ({
    "The nymph cries quietly to herself.",
  }), 0);
  set_says(2, ({
    "They must have stolen it while I was sleeping...",
  }), 0);

  deed_done = 0;
}

void catch_tell(string str) {
  string who, what;
  object tp, env;

  if (!str || deed_done) return;

  env = environment();
  str = strip_color(str);

  if (sscanf(str, "%s %s: %*sstolen%*s", who, what) >= 3 ||
      sscanf(str, "%s %s: %*swhy%*scry%*s", who, what) >= 3 ||
      sscanf(str, "%s %s: %*swhat%*swrong%*s", who, what) >= 3) {
        if (member_array(what, ({ "says", "asks", "exclaims" }) ) != -1) {
          command("say Oh, it's terrible, my pretty red "
            "necklace was stolen from me. I don't know what to do!");
        }
  }

  else if (sscanf(str, "%s %s: %*snecklace%*s", who, what) >= 3) {
    if (member_array(what, ({ "says", "asks", "exclaims" }) ) != -1) {
      command("say It was a family heirloom. My grandmother gave it "
        "to me. Won't you help me find it?");
    }
  }
  
  else if (sscanf(str, "%s gives you %s.", who, what) == 2) {
    who = lower_case(who);
    what = remove_article(what);
    if ((tp = present(who, env)) && tp->is_player() &&
        present(what) && present(what)->id(NECKLACE_ID)) {
          call_out("do_deed", 1, tp);
    }
  }      

}

void do_deed(object tp) {
  if (tp && present(NECKLACE_ID, this_object())) {
    this_object()->force_me("say Oh, thank you so much!!");
    this_object()->force_me("hug "+tp->query_name());
    this_object()->force_me("wear necklace of rubies and garnets");
    this_object()->set_emotes(2, ({ "The nymph hums a little tune." }), 0);
    if (tp->set_mini_quest("nymph necklace", 10000,
        "You brought the nymph's precious heirloom back.")) {
          message("info", "You feel a bit more experienced from your deed.", tp);
          tp->add_alignment(25);
    }
    deed_done = 1;
  }
}

int query_deed_done() { return deed_done; }


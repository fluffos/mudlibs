#include <std.h>

inherit SONG;

void create() {
  ::create();
  set_verses(({
    "A bit of tomorrow is all that it takes,",
    "To see where your blows will fall",
    "Your pains and travails will be wasted,",
    "As the fortunes reveal their all"
  }));
  set_auto(0);
  set_type("detrimental");
  set_target_required(1);
  set_song_name("prescient refrain");
}

int song() {
  object tp=this_player();
  if (tp->query_subclass() == "gypsy" &&
      tp->query_skill("euphony") >= 22*3 &&
      tp->query_skill("clairvoyance") >= 22*6)
        return 1;
  return 0;
}

void help() {
  message("help",
    "Syntax: <sing prescient refrain [to whom]>\n\n"
    "This song for gypsies helps them focus their clairvoyant powers "
    "into predicting how a foe will move, often nullifying their foe's "
    "defenses and weapon prowess. This will temporarily leave the singer "
    "unable to perform any other foretelling abilities.",
    this_player() );
}

int check() {
  object tp=this_player();
  if (tp->query_mp() < 100)
    return notify_fail("Your magical energies are too low.\n");
  return 1;
}

void finish() {
  object tp = this_object()->query_caster();
  object ob = this_object()->query_target();
  object env;
  int clair;
  string *sk = ({});
  
  if (!tp) return;
  
  env = environment(tp);

  if (!ob || environment(ob) != env) {
     message("song", "Nothing happens.", tp);
     return;
  }

  clair = tp->query_skill("clairvoyance")/2;
  clair += tp->query_skill("euphony");

  if (sizeof(ob->query_wielded())) {
    foreach (object wep in ob->query_wielded()) {
      string type=wep->query_type();
      if (member_array(type, sk) == -1) {
        sk += ({type});
        if (ob->query_skill_bonus(type) >= 0)
          ob->add_skill_bonus(type, -(clair/2), clair/3);
      }
    }
  }

  ob->add_skill_bonus("defense", -(clair/3), clair/3);
  tp->add_skill_bonus("clairvoyance", -(tp->query_skill("clairvoyance")), clair/3);
  tp->add_mp(-(100+random(tp->query_level())));

  message("song", "You pour your powers of foresight into predicting "+
                  ob->query_cap_name()+"'s movements.", tp);
  message("song", "You feel affected by the words.", ob);
  message("song", ob->query_cap_name()+" seems affected by the lyrics.",
                  env, ({tp,ob}) );

}


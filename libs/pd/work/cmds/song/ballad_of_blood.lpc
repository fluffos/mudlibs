#include <std.h>
inherit SONG;

void create() {
  ::create();
  set_verses(({
    "The tempest rages; Lightning strikes and thunder roars,",
    "An army heads into the storm, they go to war, Led by courage, blessed by sages,",
    "Naught is hope, solely fury, The soldier fights with vengeance deadly",
    "Each of the fallen they bury, Fighting now for what was taken,",
    "Oh! sweeping death, we are ready!"
  }));
  set_type("other");
  set_target_required(0);
  set_song_name("ballad of blood");
}

int song() {
  object o=this_player();
  if (o->query_subclass() == "bard" && o->query_skill("euphony") >= 76)
    return 1;
}

void help() {
  message("help",
    "Syntax: <sing ballad of blood>\n\n"
    "The ballad of blood infuses you and your party with "
    "courage for combat, while also intimidating your enemies "
    "so they fight more poorly.",
    this_player() );
}

void finish() {
  object tp, env;
  object *p = ({ }), *att = ({ });
  int atk, time;
  string party;

  tp = this_object()->query_caster();
  if (!tp) return;

  env = environment(tp);
  party = tp->query_party();
  tp->clean_up_attackers();
  att = tp->query_attackers();
  if (sizeof(party))
    p = filter(all_inventory(env),
      function (object a, string party) {
        if (a->query_party() && a->query_party() == party) return 1;
      }, party
    );
  p |= ({tp});

  atk = tp->query_skill("euphony")/5;
  time = tp->query_level()/2;

  foreach (object who in p) {
    if (who != tp)
      message("song", "You gather up your wits and go to battle.", who);
    /*
    message("song", who->query_cap_name()+" looks a little more courageous.",
      env, who);
    */
    if (who->query_skill_bonus("melee") < ((atk*2) + 10))
        who->add_skill_bonus("melee", atk, time);
    if (who->query_skill_bonus("attack") < ((atk*2) + 10))
        who->add_skill_bonus("attack", atk, time);
  }

  foreach (object attacker in att) {
    message("song", "As your enemies gather courage, you nervously "
      "back down a little.", attacker);
    /*
    message("song", attacker->query_cap_name()+" looks a little more cowardly.",
      env, attacker);
    */
    if (attacker->query_skill_bonus("melee") > -((atk*2) - 10))
        attacker->add_skill_bonus("melee", -(atk), time);

    if (attacker->query_skill_bonus("defense") > -((atk*2) - 10))
        attacker->add_skill_bonus("defense", -(atk), time);
  }

  message("song", "You strike fear into the hearts of your enemies "
    "and inspire your alies.", tp);
}



#include <std.h>

#define FAIL(s) return notify_fail(s+"\n")

#define RES "%^RESET%^"
#define COL "%^BOLD%^%^BLACK%^"
#define COL2 "%^BOLD%^%^RED%^"

#define REND_PROP "rend_spell_time"
#define REND_WAIT_SECS 20

inherit DAEMON;

int spell() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "antipaladin" &&
      tp->query_skill("magic attack") >= 45*4 &&
      tp->query_skill("faith") >= 45*4)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <rend [victim]>\n\n"
    "A demonic spell that slams an opponent's body "
    "with infernal energy in order to rip them apart.",
    this_player() );
}

int can_cast(object tp, object tgt) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no magic") ||
      environment(tp)->query_property("no attack"))
        FAIL("Some force prevents your violence.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You cannot harness that power in your current form.");

  if (!tgt)
    FAIL("Rend who?");

  if (!tgt->is_living())
    FAIL("That is not alive.");

  if (tp == tgt)
    FAIL("Not the best of ideas.");

  if (tp->query_property(REND_PROP)+REND_WAIT_SECS > time())
    FAIL("You cannot harness such power again so soon.");

  if (!tp->kill_ob(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  return 1;
}

int cmd_rend(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  int ok = 0;

  if (!spell()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  if (!can_cast(tp, tgt)) return 0;

  if (tp->query_mp() < 250)
    FAIL("Too low on magic.");

  tp->add_mp(-(250+random(30)-random(30)));
  tp->set_magic_round(1);
  tp->remove_property(REND_PROP);
  tp->set_property(REND_PROP, time());

  message("magic", COL+"Bolts of "+COL2+"in"+COL+"fer"+COL2+"nal"+COL+
    " energy "+COL2+"slam"+COL+" into "+tgt->query_cap_name()+"!",
    environment(tgt), tgt);
  message("magic", COL+"Bolts of "+COL2+"in"+COL+"fer"+COL2+"nal"+COL+
    " energy "+COL2+"slam"+COL+" into your body!", tgt);

  foreach (string l in tgt->query_limbs()) {
    int fatal;
    int perc;

    // needed in case an arm or leg is severed -
    // we can't then try to sever the hand/foot
    if (!tgt->query_is_limb(l))
      continue;

    fatal = (tgt->query_reference(l) == "FATAL");
    perc = tgt->query_dam(l) * 100 / tgt->query_max_dam(l);

    // 70% damaged for fatal limbs, 40% for nonfatal
    if ((fatal && perc >= 70) || (!fatal && perc >= 40)) {
      tgt->heal_limb(l, -(tgt->query_max_dam(l)));
      ok++;
    }
    else {
      // 30-40 percent of max damage
      int dmg = tgt->query_max_dam(l) * (30+random(11)) / 100;
      tgt->heal_limb(l, -dmg);
    }
    tgt->check_on_limb(l);
  }

  if (!ok) {
    tgt->add_hp(-(300+random(100)));
    tgt->show_status_line();
  }
  
  return 1;
}

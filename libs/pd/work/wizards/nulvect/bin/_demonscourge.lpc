
#include <std.h>
#include <dirs.h>

#define FAIL(s) return notify_fail(s+"\n")

#define SCOURGE DIR_CLASS_CMDS+"/obj/demonscourge_ob"

#define MIN_WC 3
#define MAX_WC 15

#define COL "%^BOLD%^%^BLACK%^"
#define COL2 "%^YELLOW%^"
#define RES "%^RESET%^"

inherit DAEMON;

mixed *scourge_descs = ({
  ([ "ids" : ({ "demon scourge", "demonscourge", "demonic scourge", "scourge" }),
     "short" : "a demonic scourge",
     "long" : "This scourge is made of pulsing energy. "
              "It contracts or lengthens according to its master's will.",
  ]),
});

void finish_demonscourge(mixed *);

int spell() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "antipaladin" &&
      tp->query_skill("faith") >= 15*4)
        return 1;
  return 0;
}

string type() { return "faith"; }

void help() {
  message("help",
    "Syntax: <demonscourge>\n\n"
    "A prayer of pure evil. Antipaladins use this to summon forth a scourge "
    "made of demonic energy.",
    this_player() );
}

int can_cast(object tp) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force keeps your prayer from leaving your lips.");

  if (tp->query_ghost())
    FAIL("Your prayers come out as howls.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (!alignment_ok(tp))
    FAIL("You have betrayed the source of your powers!");

  if (sizeof(filter(children(SCOURGE), (: $1->query_owner() == $2 :), tp)))
    FAIL("The demons have already granted you one!");

  if (tp->query_mp() < 200)
    FAIL("Too low on magic.");

  return 1;
}

int cmd_demonscourge(string str) {
  object tp = this_player();
  object env = environment(tp);
  object wep;
  int cost, wc, which;
  mapping scourge_info;

  if (!spell()) return 0;

  if (!can_cast(tp)) return 0;

  wc = MIN_WC + (tp->query_skill("faith")-60)/25;
  wc += tp->query_stats("wisdom")/15;

  if (wc > 8)
    wc = 8 + (wc - 8)/2;

  wc += random(2);

  if (wc > MAX_WC)
    wc = MAX_WC;

  cost = 120 + wc*6;

  if (tp->query_mp() < cost)
    FAIL("Too low on magic.");

  if (!(wep = new(SCOURGE)))
    FAIL("An error has occurred, please contact a staff member.");

  tp->add_mp(-(cost+random(cost/11)));
  tp->set_magic_round(3);

  wep->set_wc(wc);
  wep->set_owner(tp);
  if (tp->query_alignment() <= -1300)
    wep->enable_special();

  // figure out how close to the strongest flail we are and pick the
  // descs accordingly
  which = (wc - MIN_WC) * 100 / (MAX_WC - MIN_WC);
  which = which * (sizeof(scourge_descs)-1) / 100;
  scourge_info = scourge_descs[which];
  wep->set_id(scourge_info["ids"]);
  wep->set_name(scourge_info["ids"][0]);
  wep->set_short(scourge_info["short"]);
  wep->set_long(scourge_info["long"]);

  message("magic", COL+"You pray to the demons."+RES, tp);
  message("magic", COL+tp->query_cap_name()+" prays to the demons."+RES, env, tp);

  call_out("finish_demonscourge", 6, ({ tp, wep }) );

  return 1;
}

void finish_demonscourge(mixed *args) {
  object tp = args[0];
  object wep = args[1];
  object env;

  if (!tp) return;

  if (!wep) {
    message("info", "An error has occurred, please contact a staff member.", tp);
    return;
  }

  env = environment(tp);

  if (wep->move(tp) ||
      !sizeof(tp->query_wielding_limbs() - tp->query_limbs_wielded())) {
        message("magic", COL2+"Energy crackles around your hand, "
                         "but there is no room for it to manifest."+RES, tp);
        message("magic", COL2+"Energy crackles around "+tp->query_cap_name()+
                         "'s hand briefly."+RES, env, tp);
        wep->remove();
        return;
  }

  message("magic", COL2+"Energy crackles around your hand, "
                   "finally manifesting into "+
                   indefinite_article(strip_color(wep->query_short()))+"."+RES, tp);
  message("magic", COL2+"Energy crackles around "+tp->query_cap_name()+
                   "'s hand, finally manifesting into "+
                   indefinite_article(strip_color(wep->query_short()))+"."+RES,
                   env, tp);

  tp->force_me("wield "+wep->query_id()[0]);

}

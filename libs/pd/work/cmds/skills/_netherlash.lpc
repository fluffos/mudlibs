
#include <std.h>
#include <dirs.h>

#define FAIL(s) return notify_fail(s+"\n")

#define LASH DIR_CLASS_CMDS+"/obj/netherlash_ob"

#define MIN_WC 3
#define MAX_WC 15

#define COL "%^BOLD%^%^BLACK%^"
#define COL2 "%^YELLOW%^"
#define RES "%^RESET%^"

inherit DAEMON;

mixed *lash_descs = ({
  ([ "ids" : ({ "nether lash", "netherlash", "lash", "long lash" }),
     "short" : "a long lash",
     "long" : "A length of soot-stained leather for punishing the holy.",
  ]),
  ([ "ids" : ({ "nether lash", "netherlash", "lash", "whip", "black whip" }),
     "short" : "a %^BOLD%^%^BLACK%^bl%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^ck%^RESET%^ whip",
     "long" : "A pitch black fog surrounds this whip.",
  ]),
  ([ "ids" : ({ "nether lash", "netherlash", "lash", "whip", "serpentine whip" }),
     "short" : "a %^BOLD%^%^GREEN%^ser%^RESET%^%^GREEN%^pe%^BOLD%^nt%^RESET%^%^GREEN%^ine%^RESET%^ whip",
     "long" : "This whip is made from the body and tail of a serpent from the Abyss. "
              "It twitches back and forth in anticipation of battle.",
  ]),
  ([ "ids" : ({ "nether lash", "netherlash", "lash", "whip", "demonic whip" }),
     "short" : "a %^MAGENTA%^demonic%^RESET%^ whip",
     "long" : "This whip is made of pulsing energy. "
              "It contracts or lengthens according to its master's will.",
  ]),
  ([ "ids" : ({ "nether lash", "netherlash", "lash", "scourge", "hellfire scourge" }),
     "short" : "a %^BOLD%^%^RED%^hell%^RESET%^%^ORANGE%^fire %^YELLOW%^sco%^BOLD%^%^RED%^urge%^RESET%^",
     "long" : "Formed from pure hellfire, the end of this scourge is split into eight flames.",
  ]),
  ([ "ids" : ({ "nether lash", "netherlash", "lash", "possessed lash", "possessed lash of the abyss" }),
     "short" : "a %^MAGENTA%^po%^BOLD%^%^BLACK%^sse%^RESET%^%^MAGENTA%^sse%^BOLD%^%^BLACK%^d lash %^RESET%^%^MAGENTA%^of th%^BOLD%^%^BLACK%^e Abyss%^RESET%^",
     "long" : "A lash made of braided coils of demonic energy, and possessed by a minor demon. "
              "An unearthly voice calls from it, hungering for blood.",
  ]),
});

void finish_netherlash(mixed *);

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
    "Syntax: <netherlash>\n\n"
    "A prayer of pure evil. Antipaladins use this to summon forth a whip "
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

  if (sizeof(filter(children(LASH), (: $1->query_owner() == $2 :), tp)))
    FAIL("The demons have already granted you one!");

  if (tp->query_mp() < 200)
    FAIL("Too low on magic.");

  return 1;
}

int cmd_netherlash(string str) {
  object tp = this_player();
  object env = environment(tp);
  object wep;
  int cost, wc, which;
  mapping lash_info;

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

  if (!(wep = new(LASH)))
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
  which = which * (sizeof(lash_descs)-1) / 100;
  lash_info = lash_descs[which];
  wep->set_id(lash_info["ids"]);
  wep->set_name(lash_info["ids"][0]);
  wep->set_short(lash_info["short"]);
  wep->set_long(lash_info["long"]);

  message("magic", COL+"You pray to the demons."+RES, tp);
  message("magic", COL+tp->query_cap_name()+" prays to the demons."+RES, env, tp);

  call_out("finish_netherlash", 6, ({ tp, wep }) );

  return 1;
}

void finish_netherlash(mixed *args) {
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

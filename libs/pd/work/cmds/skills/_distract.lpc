
#include <std.h>

#define FAIL(s) return notify_fail(s+"\n")

#define COL "%^BOLD%^%^BLUE%^"
#define RES "%^RESET%^"

#define DISTRACT_PROP "distract_abil_time"
#define DISTRACT_TIME 20

inherit DAEMON;

string expand_macros(string str);


mapping distractions = ([
  "joke" : ({
    "What do you call a parrot in a crate?\n"
    "  A squawkbox!",
    "Why was 6 afraid of 7?\n"
    "  Because 7 8 9!",
    "How do you get a tissue to dance?\n"
    "  You put a little boogy in it!",
    "What do you call a pig that does martial arts?\n"
    "  Pork chop!",
    "Two apples are baking in an oven, the first one says, \"Isn't it hot in here?\"\n"
    "  The other one says \"AAHHH a talking apple!\"",
  }),
  "stunt" : ({
    ([ "mymsg" : "You quickly make a balloon animal!",
       "yourmsg" : "$N quickly makes a balloon animal for you!",
       "theirmsg" : "$N quickly makes a balloon animal!",
    ]),
    ([ "mymsg" : "You wiggle your hands together and make shadow puppets!",
       "yourmsg" : "$N makes a shadow puppet for you by wiggling $P hands!",
       "theirmsg" : "$N makes a shadow puppet by wiggling $P hands!",
    ]),
    ([ "mymsg" : "You pretend to fall on your face!",
       "yourmsg" : "$N falls on $P face right in front of you!",
       "theirmsg" : "$N falls on $P face!",
    ]),
  }),
]);

int abil() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "jester" &&
      tp->query_skill("entertainment") >= 29*6)
        return 1;
  return 0;
}

string type() { return "deception"; }

void help() {
  message("help",
    "Syntax: <distract who [with distraction]>\n\n"
    "A clever jester can make a foe drop his guard with "
    "a quick trick or quip.\n\n"
    "Distractions include "+
    list(map(keys(distractions), (: pluralize($1) :) ))+".",
    this_player());
}

int can_cast(object tp, object tgt, string what) {

  if (!tp) return 0;

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You're dead!");

  if (!tgt)
    FAIL("Distract who?");

  if (!tgt->is_living())
    FAIL("It seems thoroughly distracted already.");

  if (tgt == tp)
    FAIL("You are too distracted to do that.");

  if (!distractions[what])
    FAIL("Distract "+tgt->query_objective()+" with what?");

  if (tp->query_sp() < 35)
    FAIL("You're too tired.");

  return 1;
}

int cmd_distract(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  int def, agil, time, hit, miss, ran;
  string who, what;
  string msgcl, mymsg, yourmsg, theirmsg;

  if (!abil()) return 0;

  if (str) {
    if (sscanf(str, "%s with %s", who, what) == 2)
      tgt = present(who, env);
    else
      tgt = present(str, env);
  }
  else
    tgt = tp->query_current_attacker();

  if (!what)
    what = keys(distractions)[random(sizeof(keys(distractions)))];

  if (what) {
    if (what[0..1] == "a ") what = what[2..<1];
    else if (what[0..2] == "an ") what = what[3..<1];
  }

  if (!can_cast(tp, tgt, what)) return 0;

  hit = tp->query_stats("charisma");
  hit += tp->query_stats("dexterity");
  hit += tp->query_stats("intelligence");
  hit += tp->query_skill("entertainment");
  hit += tp->query_skill("stealth")/2;

  miss = tgt->query_stats("intelligence")*5/3;
  miss += tgt->query_stats("wisdom");
  miss += tgt->query_skill("perception")*2;

  ran = random(sizeof(distractions[what]));

  if (what == "joke") {
    msgcl = "say";
    mymsg = yourmsg = theirmsg = distractions[what][ran];
    mymsg = "You say: "+mymsg;
    yourmsg = theirmsg = tp->query_cap_name()+" says: "+yourmsg;
  }
  else {
    msgcl = "emote";
    mymsg = COL+distractions[what][ran]["mymsg"]+RES;
    yourmsg = COL+distractions[what][ran]["yourmsg"]+RES;
    theirmsg = COL+distractions[what][ran]["theirmsg"]+RES;
  }

  mymsg = expand_macros(mymsg);
  yourmsg = expand_macros(yourmsg);
  theirmsg = expand_macros(theirmsg);

  message(msgcl, mymsg, tp);
  message(msgcl, yourmsg, tgt);
  message(msgcl, theirmsg, env, ({ tp, tgt }) );

  if ((int)tgt->query(DISTRACT_PROP)+DISTRACT_TIME > time() ||
      hit < miss+random(20)) {

    message("info", capitalize(tgt->query_subjective())+
      " doesn't seem to be very entertained.", env, tgt);
    message("info", "You are not entertained.", tgt);
  }
  else {
    def = tgt->query_base_skill("defense");
    agil = tgt->query_base_skill("agility")/2;
    time = 4;

    if (tgt->clean_up_attackers()) {
      def /= 2;
      agil /= 2;
    }

    tgt->add_skill_bonus("defense", -def, time);
    tgt->add_skill_bonus("agility", -agil, time);

    if (what == "joke") {
      message("info", tgt->query_cap_name()+" laughs heartily.", env, tgt);
      message("info", "You laugh heartily.", tgt);
    }
    else {
      message("info", tgt->query_cap_name()+" gawks at you.", tp);
      message("info", "You gawk at "+tp->query_cap_name()+".", tgt);
      message("info", tgt->query_cap_name()+" gawks at "+
          tp->query_cap_name()+".", env, ({ tp, tgt }) );
    }

  }

  tgt->set(DISTRACT_PROP, time());
  tp->set_disable(1);
  tp->add_sp(-(25+random(10)));

  return 1;
}

string expand_macros(string str) {
  mapping macros = ([
    "N" : (: (this_player() ? this_player()->query_cap_name() : "") :),
    "P" : (: (this_player() ? this_player()->query_possessive() : "") :),
  ]);

  foreach (string key, mixed val in macros)
    str = replace_string(str, "$"+key, evaluate(val));

  return str;
}

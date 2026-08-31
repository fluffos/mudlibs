
#include <std.h>

#define FAIL(s) return notify_fail(s+"\n")

#define RES "%^RESET%^"
#define COL "%^WHITE%^"

#define TRAILMARK_PROP "trailmark_abil_info"
#define TRAILMARK_OB "/cmds/skills/obj/trailmark_ob"
// 10 minutes
#define TRAILMARK_TIME 60*10

inherit DAEMON;

object *who = ({});

mapping locations = ([
    "forest" : ([
      "me" : "You $Carrange some twigs to mark the room.",
      "they" : "$N $Carranges some twigs.",
      "desc" : "Some twigs arranged in a pattern.",
      "mod" : 1.25
    ]),
    "beach" : ([
      "me" : "You $Cscratch some marks in the sand.",
      "they" : "$N $Cscratches some marks in the sand.",
      "desc" : "A mark scratched in the sand.",
      "mod" : 0.8
    ]),
    "swamp" : ([
      "me" : "You $Cscratch a marking into a tree.",
      "they" : "$N $Cscratches on a tree.",
      "desc" : "A mark scratched into a tree.",
    ]),
    "dessert" : ([
      "me" : "You trace a design $Cinto the sand.",
      "they" : "$N traces a design $Cinto the sand.",
      "desc" : "A design softly traced into the sand.",
      "mod" : 0.75
    ]),
    "desert" : ([
      "me" : "You trace a design $Cinto the sand.",
      "they" : "$N traces a design $Cinto the sand.",
      "desc" : "A design softly traced into the sand.",
      "mod" : 0.75
    ]),
    "plain" : ([
      "me" : "You $Cflatten a small clump of grass.",
      "they" : "$N $Cflattens a small clump of grass.",
      "desc" : "An oddly flattened clump of grass.",
    ]),
    "mountain" : ([
      "me" : "You arrange some rocks $Cinto a marker.",
      "they" : "$N arranges some rocks.",
      "desc" : "A pile of rocks arranged into a marker.",
      "mod" : 1.25
    ]),
    "polar" : ([
      "me" : "You $Cclump some snow into a marker.",
      "they" : "$N $Cclumps some snow together.",
      "desc" : "A large clump of snow.",
      "mod" : 0.75
    ]),
]);

int abil() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "scout" &&
      tp->query_skill("perception") >= 18*6)
        return 1;
  return 0;
}

string type() { return "other"; }

void help() {
  message("help",
    "Syntax: <trailmark [name] (carefully)>\n"
    "        <trailmark list>\n\n"
    "A scout's ability to leave temporary marks on a trail. "
    "The marks will be visible to anyone perceptive enough "
    "to notice them, as well as those well versed in nature "
    "lore. Marking carefully will make it much harder for "
    "anyone else to see them. The scout can <clear> "
    "his own marks away.",
    this_player() );
}

int can_cast(object tp, string name) {
  object env;
  mapping marks;

  if (!tp) return;

  env = environment(tp);
  marks = tp->query(TRAILMARK_PROP) || ([]);

  if (env->query_property("town"))
    FAIL("Town roads are not suitable for marking.");

  if (env->query_property("water"))
    FAIL("You can't do that underwater!");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You're dead.");

  if (!strlen(name))
    FAIL("Mark the trail with what name?");

  if (sizeof(marks) && sizeof(marks[name]))
      FAIL("You have already marked a trail with that name.");

  if (name != "list" && sizeof(filter(marks, (:
      ( environment($2["ob"]) == environment(this_player()) ) :) )) )
        FAIL("You have already marked this trail.");

  if (tp->query_sp() < 20)
    FAIL("You are too tired.");

  return 1;
}

int cmd_trailmark(string str) {

  object tp = this_player();
  object env = environment(tp);
  object ob;
  string name, junk;
  int careful = 0;
  int max;
  mapping marks;
  string mymsg, theirmsg, long;
  float perc;

  if (!abil()) return 0;

  if (str && sscanf(str, "%s %s", name, junk) != 2)
    name = str;

  if (strlen(junk)) {
    // in case they type 'mark carefully name'
    if (name == "carefully" && junk != "carefully") {
      string tmp = name;
      name = junk;
      junk = tmp;
    }
    if (junk == "carefully")
      careful = 1;
 }

  if (!can_cast(tp, name)) return 0;

  marks = (mapping)tp->query(TRAILMARK_PROP) || ([]);

  if (name == "list") {
    if (!sizeof(marks))
      message("info", "You have not marked any trails.", tp);
    else {
      message("info", "You have marked these trails:", tp);
      foreach (string k, mapping info in marks)
        message("info", k+": "+environment(info["ob"])->query_short(), tp);
    }
    return 1;
  }

  // careful of changing the reqs for this
  max = 3;
  max += (tp->query_level()-10)/14;

  if (sizeof(marks) >= max)
    FAIL("You cannot remember so many places at once.");

  foreach (string terrain, mapping tdata in locations) {
    if (env->query_property(terrain)) {
      mymsg = tdata["me"];
      theirmsg = replace_string(tdata["they"], "$N", tp->query_cap_name());
      long = tdata["desc"];
      if (tdata["mod"]) perc = tdata["mod"];
      else perc = 1.0;
      break;
    }
  }

  if (!strlen(mymsg))
    FAIL("You can't mark the trail here.");

  ob = new(TRAILMARK_OB);
  if (!objectp(ob))
    FAIL("An error occurred, please contact a staff member.");

  ob->set_id( ob->query_id() + ({"trailmark_ob", name}) );
  ob->set_owner(tp);
  ob->set_name(name);
  ob->set_long_desc(long);
  ob->move(env);

  if (careful) {
    ob->set_difficulty(tp->query_skill("perception"));
    mymsg = replace_string(mymsg, "$C", "carefully ");
    theirmsg = replace_string(theirmsg, "$C", "carefully ");
  }
  else {
    ob->set_difficulty(tp->query_skill("perception")/2);
    mymsg = replace_string(mymsg, "$C", "");
    theirmsg = replace_string(theirmsg, "$C", "");
  }
 
  tp->set(TRAILMARK_PROP,
    marks + ([
      name : ([
        "time" : time()+to_int(TRAILMARK_TIME*perc),
        "ob" : ob,
      ])
    ])
  );

  message("info", mymsg, tp);
  message("info", theirmsg, env, tp);

  tp->set_disable(1+careful);
  tp->add_sp(-(10+random(10)));
  who += ({ tp });
  set_heart_beat(10);
  
  return 1;
}

void heart_beat() {
  mapping marks;
  foreach (object p in who) {
    if (!objectp(p)) {
      who -= ({ p });
      break;
    }
    marks = p->query(TRAILMARK_PROP) || ([]);
    foreach (string name, mapping info in marks) {
      int time = info["time"];
      object ob = info["ob"];
      if (time < time()) {
        if (ob) ob->remove();
        map_delete(marks, name);
      }
    }
    if (sizeof(marks))
      p->set(TRAILMARK_PROP, marks);
    else
      who -= ({ p });
  }
  if (!sizeof(who)) set_heart_beat(0);
}


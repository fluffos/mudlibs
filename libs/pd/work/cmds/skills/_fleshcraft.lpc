
#include <std.h>

#define COL "%^BOLD%^%^BLACK%^"
#define COL2 "%^BOLD%^%^GREEN%^"
#define RES "%^RESET%^"

#define FAIL(s) return notify_fail(s+"\n")

#define FLESHCRAFT_ID "fleshcraft_ob_id"
#define FLESHCRAFT_TIME 60*60 // 1 hour
#define FLESHCRAFT_PROP "fleshcraft_spell_time"

inherit DAEMON;

object *items = ({});

mapping things = ([
  "wrapping" : ([
    "skills" : ([
      "necromancy" : 6*18,
      "conjuring" : to_int(4.5*18)
    ]),
    "id" : ({"flesh", "wrapping", "hardened flesh", "wrapping of hardened flesh"}),
    "name" : "wrapping of hardened flesh",
    "short" : "a wrapping of hardened flesh",
    "long" : "A thin tunic made of stiff, hardened skin and tendon.",
    "weight" : 6,
    "ac" : 1,
    "max" : 6,
    "limbs" : ({"torso", "head"}),
    "type" : "coat",
  ]),
  "shield" : ([
    "skills" : ([
      "necromancy" : 6*24,
      "conjuring" : to_int(4.5*24)
    ]),
    "id" : ({"bones", "bone shield", "shield of bones", "shield"}),
    "name" : "shield of bones",
    "short" : "a shield of bones",
    "long" : "Many bones arranged in a large and roughly square "
             "shape. All of the bones are fused together.",
    "weight" : 14,
    "ac" : 2,
    "max" : 7,
    "limbs" : ({"torso","left arm","right arm"}),
    "type" : "shield",
  ]),
  "helmet" : ([
    "skills" : ([
      "necromancy" : 6*27,
      "conjuring" : to_int(4.5*27)
    ]),
    "id" : ({"skull", "helm", "helmet", "skull helm", "skull helmet"}),
    "name" : "skull helmet",
    "short" : "a skull helmet",
    "long" : "A very large skull that is hinged so it can be worn. ",
    "weight" : 3,
    "ac" : 2,
    "max" : 8,
    "limbs" : ({"head"}),
    "type" : "helmet",
  ]),
  "sack" : ([
    "skills" : ([
      "necromancy" : 6*20,
      "conjuring" : to_int(4.5*20)
    ]),
    "id" : ({"sack", "sack of flesh", "flesh sack" }),
    "name" : "sack of flesh",
    "short" : "a sack of flesh",
    "long" : "Skin, tendons, and muscles have been thickened and "
             "reformed into this sack to hold things.",
    "weight" : 15,
    "capacity" : 800,
    "max" : 3500
  ]),
  "club" : ([
    "skills" : ([
      "necromancy" : 6*22,
      "conjuring" : to_int(4.5*22)
    ]),
    "id" : ({"club", "bone", "bone club"}),
    "name" : "bone club",
    "short" : "a bone club",
    "long" : "A club made of a single long, thick mass of bone. "
             "The business end is twice as massive as the handle.",
    "weight" : 9,
    "wc" : 3,
    "max" : 13,
    "type" : "blunt",
  ]),
  "blade" : ([
    "skills" : ([
      "necromancy" : 6*30,
      "conjuring" : to_int(4.5*30)
    ]),
    "id" : ({"blade", "bone", "bone blade"}),
    "name" : "bone blade",
    "short" : "a bone blade",
    "long" : "A sword made from a large mass of bone. "
             "The tip curves backwards a bit and there is no handguard.",
    "weight" : 8,
    "wc" : 4,
    "max" : 15,
    "type" : "blade",
  ])
]);

int can_craft(object tp, string what);

int spell() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "necromancer" &&
      can_craft(tp, "wrapping"))
        return 1;
  return 0;
}

string type() { return "conjuring"; }

void help() {
  message("help",
    "Syntax: <fleshcraft (wrapping | shield | helmet)>\n"
    "        <fleshcraft (sack | club | blade)>\n\n"
    "This necromancy spell uses the bones and flesh from a corpse "
    "to craft something useful. The dark magic that molds the "
    "flesh also strengthens it and makes it last longer, but "
    "these things will decay over enough time.",
    this_player() );
}

int can_cast(object tp, object corpse) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents your spell.");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("In a humorous twist of fate, your necromancy doesn't work while you're dead.");

  if (!corpse)
    FAIL("You need a fresh corpse first.");

  return 1;
}

int cmd_fleshcraft(string str) {
  object tp=this_player();
  object env=environment(tp);
  object *corpses;
  object corpse, newob;
  int level, cost, time, amt, max;
  string type;

  if (!spell()) return 0;

  corpses = filter(all_inventory(env), (: $1->query_corpse() :) );
  if (sizeof(corpses)) corpse=corpses[0];

  if (!can_cast(tp, corpse)) return 0;

  if (!(level = can_craft(tp, str)))
    FAIL("You do not know how to craft that.");

  // since they all depend on necro (6 per level) and conj (4.5 per level),
  // this tells me what level the caster is.. assuming maxed skills
  level = to_int(level/10.5);
  if (level < 10) level=10;

  cost = 55+level+random(level/2);

  if (tp->query_mp() < cost)
    FAIL("You need more magic power.");
  tp->set_magic_round(2);
  tp->add_mp(-cost);
  //tp->add_alignment(-1);

  time = FLESHCRAFT_TIME+(110*(level-10));
  
  if (amt = things[str]["ac"])
    type = "armour";
  else if (amt = things[str]["wc"])
    type = "weapon";
  else if (amt = things[str]["capacity"])
    type = "bag";
  else 
    FAIL("An error occurred, please contact a staff member.");

  // figure out, as a percentage, how close the caster is to level 60,
  // and add some more ac/wc/etc up to the maximum
  max = things[str]["max"];
  amt += percent(level,60.0)*(max-amt);
  if (amt > max) amt=max;

  switch (type) {
    case "armour":
      newob = new(ARMOUR);
      newob->set_ac(amt);
      newob->set_type(things[str]["type"]);
      newob->set_limbs(things[str]["limbs"]);
    break;
    case "weapon":
      newob = new(WEAPON);
      newob->set_wc(amt);
      newob->set_type(things[str]["type"]);
    break;
    case "bag":
      newob = new(BAG);
      newob->set_max_internal_encumbrance(amt);
    break;
  }

  newob->set_id(things[str]["id"]+({FLESHCRAFT_ID}) );

  newob->set_name(things[str]["name"]);
  newob->set_short(things[str]["short"]);
  newob->set_long(things[str]["long"]);
  newob->set_weight(things[str]["weight"]);
  newob->set_curr_value("gold", 0);
  newob->set_property("no auction", 1);
  newob->set_property(FLESHCRAFT_PROP, time()+time);
  
  set_heart_beat(3);
  items += ({newob});

  message("magic", COL+"You mold the "+COL2+"flesh"+COL+" and "+COL2+"bones"+
                   COL+" of the corpse into "+newob->query_short()+".", tp);
  message("magic", COL+tp->query_cap_name()+" molds the "+
                   COL2+"flesh"+COL+" and "+COL2+"bones"+
                   COL+" of the corpse into "+newob->query_short()+".", env, tp);

  corpse->loot(tp);
  
  message("magic", COL2+"The rest of the "+RES+"body"+COL2+
                   " turns to "+RES+"dust"+COL2+"."+RES, env);

  if (newob->move(tp))
    newob->move(env);
  corpse->remove();
  
  return 1;
}

int can_craft(object tp, string what) {
  int total=0;
  
  if (!tp || !what || member_array(what, keys(things)) == -1)
    return 0;
  
  foreach (string sk in keys(things[what]["skills"])) {
    int cur=things[what]["skills"][sk];
    total += cur;
    if (tp->query_skill(sk) < cur)
      return 0;
  }

  return total;
}

void heart_beat() {
  foreach (object w in items) {
    object env;
    int decay;
    if (!w) items -= ({w});
    else if ((decay=w->query_property(FLESHCRAFT_PROP)) <= time()) {
      env = environment(w);
      message("magic", "The "+w->query_name()+" decays and falls apart.", env);
      if (w->is_bag()) {
        message("magic", "The contents spill out.", env);
        if (living(env) && environment(env)) env=environment(env);
        all_inventory(w)->move(env);
      }
      items -= ({w});
      w->remove();
    }
    else if (decay > time() && decay-time() <= 300 && decay-time() >= 300-2*3)
      message("magic", COL2+"The "+w->query_name()+" starts to rot."+RES, environment(w));
  }
  if (!sizeof(items)) set_heart_beat(0);
}



#include <std.h>
// for ROOM_VOID
#include <rooms.h>

#define COL "%^BOLD%^%^MAGENTA%^"
#define COL2 "%^YELLOW%^"
#define RES "%^RESET%^"

#define FAIL(s) return notify_fail(s+"\n")

#define PHANTASM_PROP_INFO "phantasm_spell_info"

inherit DAEMON;

string *get_spells(string sub);

int spell() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "sorceror" &&
      tp->query_skill("psionics") >= 27*6)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <phantasm assume [whom]>\n"
    "        <phantasm attack [whom]>\n\n"
    "A sorceror can create a semi-real image of a living thing called a "
    "phantasm to damage his enemies. He must periodically refresh his "
    "memory to let his <phantasm assume> a more real shape. While fighting, "
    "he can make his <phantasm attack> someone. Despite being mostly illusion, "
    "it can cause real damage by fooling the victim's mind.",
    this_player() );
}

int can_cast(object tp, object tgt, string verb) {
  object env;
  
  if (!tp) return 0;

  env=environment(tp);
  
  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You are practically a phantasm yourself.");

  if (!tgt)
    FAIL("Target whom?");

  if (!living(tgt))
    FAIL("That is not alive.");

  if (tgt == tp)
    FAIL("That magic doesn't work that way.");

  switch (verb) {
    case "assume":
    break;
    case "attack":
      if (env->query_property("no attack") || env->query_property("no magic"))
        FAIL("Some force prevents your magic.");
      if (!tp->kill_ob(tgt))
        FAIL("You may not attack "+tgt->query_cap_name()+".");
    break;
    default:
      FAIL("Your phantasm cannot do that.");
  }

  return 1;
}

int cmd_phantasm(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt, ph;
  int rank, cost;
  string verb, name;
  string *spells;
  mapping info = ([]);
  float ratio;
  mixed tmp;

  if (!spell()) return 0;

  if (sscanf(str, "%s %s", verb, name) == 2)
    tgt=present(name, env);
  else {
    verb=str;
    tgt=tp->query_current_attacker();
  }

  if (!can_cast(tp, tgt, verb)) return 0;

  switch (verb) {
    case "assume":
      info["time"] = time();
      if (!userp(tgt))
        info["file"] = base_name(tgt);
      else {
        info["name"] = tgt->query_name();
        info["short"] = tgt->query_short();
        info["long"] = tgt->query_long();
        info["race"] = tgt->query_race();
        info["class"] = tgt->query_class();
        info["subclass"] = tgt->query_subclass();
        info["level"] = tgt->query_level();
        info["stats"] = tgt->query_base_stats();
        info["skills"] = tgt->query_skills();
        info["spells"] = tgt->query_spells();
        info["wielded"] = ({});
        foreach (object wep in tgt->query_wielded())
          info["wielded"] += ({base_name(wep)});
      }
      tp->set(PHANTASM_PROP_INFO, info);
      tp->set_magic_round(1);
      tp->add_mp(-(10+random(5)));
      message("magic", "You study "+tgt->query_cap_name()+
                       " intently for a moment.", tp);
    break;

    case "attack":
      info = copy(tp->query(PHANTASM_PROP_INFO));
    
      cost = 100+info["level"]*3;
      if (tp->query_mp() < cost)
        FAIL("Your magic is too low.");
      tp->set_magic_round(1);
      tp->add_mp(-(cost+random(cost/5)));
      
      // every 10 seconds, your memory of the thing gets 1% worse,
      // so your phantasm is 1% less effective
      ratio = 100.0-(to_float(time() - info["time"])/10.0);
      if (ratio < 5.0) ratio=5.0;
      ratio /= 100.0;

      // create a monster and copy the info
      if (info["file"])
        ph = new(info["file"]);
      else {
        ph = new(MONSTER);
        ph->set_name(info["name"]);
        ph->set_short(info["short"]);
        ph->set_long(info["long"]);
        ph->set_race(info["race"]);
        ph->set_class(info["class"]);
        ph->set_subclass(info["subclass"]);
        ph->set_level(info["level"]);
        ph->set_base_stats(info["stats"]);
        ph->set_skills(info["skills"]);
        foreach (string w in info["wielded"]) {
          object wep=new(w);
          wep->move(ph);
        }
      }
      ph->set_class(info["class"]);
      ph->set_subclass(info["subclass"]);
      ph->set_spells(info["spells"]);

      if (!ph->query_class()) {
        if (!ph->query_subclass() || ph->query_subclass() == "none")
          ph->set_class( ({"fighter", "rogue", "wanderer"})[random(3)] );
        else {
          switch (ph->query_subclass()) {
            case "warrior": case "berserker": case "ranger":
            case "paladin": case "antipaladin":
              ph->set_class("fighter");
            break;
            case "assassin": case "thief": case "thug": case "scout":
              ph->set_class("rogue");
            break;
            case "bard": case "jester": case "gypsy": case "swashbuckler":
              ph->set_class("wanderer");
            break;
            case "monk": case "druid": case "kataan": case "cleric":
              ph->set_class("clergy");
            break;
            case "wizard": case "pyromancer": case "necromancer": case "sorceror":
              ph->set_class("mage");
          }
        }
      }
      // NOT "else if"
      if (ph->query_class() && (!ph->query_subclass() || ph->query_subclass() == "none")) {
        switch (ph->query_class()) {
          case "fighter":
            tmp = ({"warrior","berserker","ranger","paladin","antipaladin"});
          break;
          case "rogue":
            tmp = ({"assassin", "thief", "thug", "scout"});
          break;
          case "wanderer":
            tmp = ({"bard","jester","gypsy","swashbuckler"});
          break;
          case "clergy":
            tmp = ({"monk","druid","kataan","cleric"});
          break;
          case "mage":
            tmp = ({"wizard","pyromancer","necromancer","sorceror"});
          break;
        }
        ph->set_subclass(tmp[random(sizeof(tmp))]);
        // save these for next time so it doesn't become a random sub every cast
        info["class"] = ph->query_class();
        info["subclass"] = ph->query_subclass();
        tmp=0;
      }
      
      // adjust level, stats, and skills according to how long
      // since you used phantasm assume
      ph->set_level(to_int(ph->query_level()*ratio));
      if (ph->query_level() < 1)
        ph->set_level(1);
      
      foreach (string st, int i in ph->query_base_stats()) {
        ph->set_stats(st, to_int(i*ratio));
        if (ph->query_base_stats(st) < 1)
          ph->set_stats(st, 1);
      }
      
      foreach (string sk, mapping m in ph->query_skills()) {
        ph->set_skill(sk, to_int(m["level"]*ratio));
        if (ph->query_skill(sk) < 1)
          ph->set_skill(sk, 1);
      }
      
      // wield all the weapons it has
      foreach (object thing in all_inventory(ph))
        if (thing->is_weapon())
          ph->equip_weapon_to_limb(thing,
            ph->query_wielding_limbs() - ph->query_limbs_wielded() );

      if (!sizeof(spells=ph->query_spells()))
        if (!sizeof(spells=info["spells"]))
          spells = get_spells(info["subclass"]);
      
      ph->move(env);
      ph->kill_ob(tgt);
      ph->set_disable(0);
      ph->set_magic_round(0);
      ph->set_casting(0);

      message("info", ph->query_class()+", "+ph->query_subclass()+", "+
          identify(spells), tp);

      // make it use an ability or spell if possible
      while (sizeof(spells) && ph->force_me(tmp=spells[random(sizeof(spells))]) == 0) {
        ph->set_disable(0);
        ph->set_magic_round(0);
        ph->set_casting(0);
        spells -= ({tmp});
      }
      ph->move(ROOM_VOID);

      // remove unusable spells that were filtered out by the while loop
      info["spells"] = spells;

      // resave any info we had to figure out to save future cycles
      tp->set(PHANTASM_PROP_INFO, info);
      
    break;
  }
  
  return 1;
}

// really need to make some sort of function in livings to grab this info...
string *get_spells(string sub) {
  string *ret;
  
  if (!sub) return 0;

  switch (sub) {
    case "warrior":
      ret = ({"headbutt", "warblade", "gash", });
    break;
    case "berserker":
      ret = ({"headbutt", "rush", "warblade", "hew", });
    break;
    case "ranger":
      ret = ({"headbutt", "rush", "warblade", "spear", });
    break;
    case "paladin":
      ret = ({"headbutt", "warblade", "dispell", "turn", });
    break;
    case "antipaladin":
      ret = ({"headbutt", "warblade", "flog", "shimmer", "shadowburst", });
    break;
    case "assassin":
      ret = ({"slice", "debilitate", "circle", });
    break;
    case "thief":
      ret = ({"headbutt", "slice", "debilitate", "circle", });
    break;
    case "thug":
      ret = ({"headbutt", "clobber", "smash", "slice", "circle", });
    break;
    case "scout":
      ret = ({"slice", "fang", "lionfang", "pincer"});
    break;
    case "bard":
      ret = ({"trip", "strike", });
    break;
    case "jester":
      ret = ({"trip", "headbutt", "strike", "slam", "flip",
              "cartwheel", "mystify", });
    break;
    case "gypsy":
      ret = ({"trip", "strike", "flog", });
    break;
    case "swashbuckler":
      ret = ({"trip", "strike", "disarm", "lunge", "bladedance"});
    break;
    case "monk":
      ret = ({"headbutt", "ironfist", "dispell", "pain", "manaburn",
              "chistrike", "circlekick", "snapkick", "furystrike", "openpalm", });
    break;
    case "kataan":
      ret = ({"daklihn", "dakjal", "skewer", "slice",
              "darkmist", "shadowburst", "torment", "absorb", "drain", "fear", });
    break;
    case "druid":
      ret = ({"headbutt", "eagleblitz", "freeze", "thorns", "vinegrasp",
              "whirlwind", "rootgrasp"});
    break;
    case "cleric":
      ret = ({"dispell","lifewarp","pain","turn","wound","unknit","paralyze"});
    break;
    case "wizard":
      ret = ({"magicmissile", "manablast", "manabolt", "manamissile",
              "pillar", "shockwave", "tremble", "polymorph", "coalesce"});
    break;
    case "necromancer":
      ret = ({"missile", "rot", "shadowburst", "soulburn", "absorb"});
    break;
    case "pyromancer":
      ret = ({"missile", "burn", "fireball", "firebomb", "flamebraid",
              "scorch", "sear", "shroud"});
    break;
    case "sorceror":
      ret = ({"missile", "burn", "disintegrate", "dissolve", "fireball",
              "liquify", "mindshock", "solidify"});
    break;
  }

  if (member_array(sub, ({"red","white","black","blue"})) != -1)
    ret = ({"jab", "bite", "claw", "tailspear", "roar",
            "fireshot", "flameclaw",
            "sunder", "solarflare", "faithwing", "dispell",
            "iceblast", "spire",
            "shadowfang", "annihilate", "darkmist"});
  else
    ret += ({"jab", "cut", "slash", "stab", "puncture",
             "chop", "hack", "pierce", "impale",
             "whip", "lash", "bash", "maul"});

  return ret;
}

        

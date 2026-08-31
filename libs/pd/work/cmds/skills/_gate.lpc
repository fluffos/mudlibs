//      _gate.c
//      Mage ability
//      -- Seeker
//  rewritten by Nulvect 2012-Jan-28

// NOTE!!!
// for some reason the old gate spell didn't care about the "no magic"
// property of rooms, only "no teleport"
// so we are basically forced to do the same since everyone has gates
// marked to squares and such

#include <std.h>
#include <daemons.h>
#include <dirs.h>
#include <damage.h>

#define RES "%^RESET%^"
#define COL "%^BOLD%^%^MAGENTA%^"
#define COL2 "%^BOLD%^%^BLUE%^"

#define FAIL(s) return notify_fail(s+"\n")

#define GATE_PROP "gate_spell_data"
#define GATE_MIN_MARKS 3
#define PORTAL_OB DIR_CLASS_CMDS+"/obj/gate_portal"

inherit DAEMON;

int query_max_marks(object tp);
int gate_manage(object tp, string cmd, string destname);
int gate_to(object tp, string destname);
void gate_open(object tp, object dest);
void gate_close(object *portals);

int spell() {
  object tp = this_player();
  string *allowed = ({
    "wizard", "necromancer", "conjurer", "illusionist",
  });
  if (tp && member_array(tp->query_subclass(), allowed) != -1 &&
      tp->query_skill("conjuring") >= 150)
        return 1;
  return 0;
}

void help() {
  message("help",
    "Syntax: <gate [player]>\n"
    "        <gate [location]>\n"
    "        <gate mark [name]>\n"
    "        <gate unmark [name]>\n"
    "        <gate list>\n\n"
    "Allows the caster to open a portal between himself and another player, "
    "or to a specific location.",
    this_player());
}

string type() { return "conjuring"; }

int query_max_marks(object tp) {
  int marks = 0;

  marks += BALANCE3_D->diminishing_returns(
    (tp->query_base_stats("intelligence") - 30), 0.35
  );

  marks += BALANCE3_D->diminishing_returns(
    (tp->query_base_stats("wisdom") - 50), 0.02
  );

  marks = to_int(marks);

  if (marks < GATE_MIN_MARKS) marks = GATE_MIN_MARKS;
  return marks;
}

int can_cast(object tp) {
  if (!tp) return 0;

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("Your spell fails to manifest.");

  return 1;
}

int cmd_gate(string str) {
  string destname, cmd;
  object tp = this_player();

  if (!spell()) return 0;

  if (!can_cast(tp)) return 0;

  if (!str || str == "")
    FAIL("Gate where?");

  else if (sscanf(str, "to %s", destname) == 1)
    return gate_to(tp, destname);

  else if (sscanf(str, "%s %s", cmd, destname) == 2)
    return gate_manage(tp, cmd, destname);

  else if (str == "list")
    return gate_manage(tp, "list", "");

  else
    return gate_to(tp, str);
}

int gate_manage(object tp, string cmd, string destname) {
  mapping gates = tp->query_property(GATE_PROP) || ([]);
      
  switch (cmd) {
    case "list":
      if (!sizeof(gates))
        FAIL("You have not marked any locations yet.");
      message("info", "You have marked these locations:", tp);
      foreach (string key, string val in gates)
        message("info", "[\"" + key + "\"] : " + val->query_short(), tp);
      return 1;
    break;

    case "mark":
      if (sizeof(gates) >= query_max_marks(tp))
        FAIL("You cannot mark any more locations right now.");
      if (!destname || !strlen(destname))
        FAIL("You must give a name with which to mark this place.");
      if (gates[destname])
        FAIL("You have already used that name.");
      if (environment(tp)->query_property("no teleport"))
        FAIL("Some force prevents you from marking this location.");
      gates[destname] = file_name(environment(tp));
      tp->set_property(GATE_PROP, gates);
      message("info", "You magically mark this location as "+destname+".", tp);
      return 1;
    break;

    case "unmark":
      if (!destname || !strlen(destname))
        FAIL("You must give the name of the mark to remove.");
      if (!gates[destname])
        FAIL("You have not marked any location with that name.");
      map_delete(gates, destname);
      message("info", "You magically remove the mark of "+destname+
                      " from this location.", tp);
      return 1;
    break;

    default:
      FAIL("Gate where?");
  }

  return 1;
}

int gate_to(object tp, string destname) {
  object tpenv;
  object dest;
  mapping gates;

  if (tp->query_mp() < tp->query_max_mp()*90/100)
    FAIL("Too low on magic.");

  tpenv = environment(tp);

  if (tpenv->query_property("no teleport"))
    FAIL("Some force prevents your magic.");

  dest = find_player(destname);

  if (dest)
    dest = environment(dest);
  else {
    gates = tp->query_property(GATE_PROP) || ([]);
    destname = gates[destname];
    if (!destname)
      FAIL("Your spell fizzles.");
    dest = load_object(destname);
    if (!dest)
      FAIL("An error occurred, please contact a staff member.");
    if (dest->query_property("no teleport"))
      FAIL("Some force prevents your magic.");
  }

  tp->add_mp(-(tp->query_max_mp()*90/100));
  tp->set_paralyzed(10, "You are concentrating on your spell!");

  message("magic", COL+"You begin to recite an arcane formula.\n"
    "Reality ripples around you."+RES, tp);
  message("magic", COL+"Reality begins to ripple around "+
    tp->query_cap_name()+" as "+tp->query_subjective()+
    " recites a spell."+RES, tpenv, tp);
  message("magic", COL+"Reality begins to ripple and shudder."+RES, dest);

  call_out("gate_open", 8, tp, dest);

  return 1;
}

void gate_open(object tp, object dest) {
  object p1, p2;
  object env;

  if (!tp) return;
  env = environment(tp);

  // very unlikely that the destination room is no longer there,
  // but let's have some fun...
  if (!dest) {
    message("magic", COL+"Your spell goes terribly awry, "
      "damaging the fabric of reality!"+RES, tp);
    message("magic", COL+tp->query_cap_name()+"'s spell goes terribly awry, "
      "damaging the fabric of reality!"+RES, env, tp);
    message("magic", COL2+"A screeching explosion rocks the area!"+RES, env);
    // nonlethal damage to everyone in the room
    foreach (object pl in filter(all_inventory(env), (: $1->is_living() :))) {
      pl->do_damage("all", 50+random(50), DAMAGE_MAGIC,
        DAMAGE_BYPASS_ARMOUR | DAMAGE_NO_PLAYER_REDUCE |
        DAMAGE_BYPASS_STRENGTHS | DAMAGE_NONLETHAL | DAMAGE_NO_SEVER
      );
    }
    return;
  }

  p1 = new(PORTAL_OB);
  if (!p1) {
    message("info", "An error occurred, please contact a staff member.", tp);
    return;
  }
  p2 = new(PORTAL_OB);

  message("magic", COL2+"A surge of light and sound "
    "coalesces into a portal."+RES, ({ env, dest }) );

  p1->set_destination(dest);
  p1->move(env);
  p2->set_destination(env);
  p2->move(dest);

  call_out("gate_close", 16, ({ p1, p2 }) );
}

void gate_close(object *portals) {
  foreach (object p in portals) {
    if (!p) continue;
    if (environment(p))
      message("magic", COL+"The portal collapses in a stream of colors."+RES,
        environment(p));
    p->remove();
  }
}


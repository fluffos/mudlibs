#include <std.h>
#include <rest.h>

#define FAIL(s) return notify_fail(s+"\n")

#define RES "%^RESET%^"
#define COL "%^BOLD%^%^MAGENTA%^"
#define COL2 "%^YELLOW%^"

#define TELEPORT_PROP "teleport_spell_data"
#define TELEPORT_MAX_MARKS 5
// level at which caster can teleport items
#define TELEPORT_ITEM 15
// level at which caster can teleport himself, 0 to disable
#define TELEPORT_CASTER 30

inherit DAEMON;

int teleport_manage(object tp, string cmd, string destname);
int teleport_item(object tp, string itemname, string destname);
int teleport_self(object tp, string destname);
void finish_teleport(object tp, object what, object dest);

int spell() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "sorceror" &&
      tp->query_skill("psionics") >= TELEPORT_ITEM * 6 &&
      tp->query_skill("conjuring") >= TELEPORT_ITEM * 4)
        return 1;
  return 0;
}

int query_teleport_caster(object tp) {
  if (TELEPORT_CASTER &&
      tp->query_skill("psionics") >= TELEPORT_CASTER * 6 &&
      tp->query_skill("conjuring") >= TELEPORT_CASTER * 4)
        return 1;
  return 0;
}

string type() { return "conjuring"; }

void help() {
  message("help",
    "Syntax: <teleport [item] to [player]>\n"+
    (TELEPORT_CASTER ?
    "        <teleport [player]>\n"
    "        <teleport [location]>\n"
    "        <teleport mark [name]>\n"
    "        <teleport unmark [name]>\n"
    "        <teleport list>\n"
    : "" )+
    "\n"
    "Allows the caster to psionically teleport objects "+
    (TELEPORT_CASTER ? "or even himself " : "")+
    "to another player"+
    (TELEPORT_CASTER ? " or location" : "")+
    ".",
    this_player() );
}

int can_cast(object tp) {

  if (!tp) return 0;

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You cannot harness your powers in your current state.");

  return 1;
}

int cmd_teleport(string str) {
  object tp = this_player();
  string destname, itemname, cmd;

  if (!spell()) return 0;

  if (!can_cast(tp)) return 0;

  if (!str || str == "")
    FAIL("Teleport what to where?");

  if (sscanf(str, "%s to %s", itemname, destname) == 2)
    return teleport_item(tp, itemname, destname);

  else if (sscanf(str, "to %s", destname) == 1)
    return teleport_self(tp, destname);

  else if (sscanf(str, "%s %s", cmd, destname) == 2)
    return teleport_manage(tp, cmd, destname);

  else if (str == "list")
    return teleport_manage(tp, "list", "");

  else
    return teleport_self(tp, str);
}

int teleport_manage(object tp, string cmd, string destname) {
  mapping tele = tp->query_property(TELEPORT_PROP) || ([]);
      
  if (!query_teleport_caster(tp))
    FAIL("Teleport what to where?");

  switch (cmd) {
    case "list":
      if (!sizeof(tele))
        FAIL("You have not imprinted with any locations yet.");
      message("info", "You have imprinted with these locations:", tp);
      foreach (string key, string val in tele)
        message("info", "[\"" + key + "\"] : " + val->query_short(), tp);
      return 1;
    break;

    case "mark":
      if (sizeof(tele) >= TELEPORT_MAX_MARKS)
        FAIL("Your mind cannot imprint with any more locations.");
      if (!destname || !strlen(destname))
        FAIL("You must give a name by which to remember this place.");
      if (tele[destname])
        FAIL("You have already used that name.");
      if (environment(tp)->query_property("no teleport"))
        FAIL("Some force prevents your mind from forming a bond here.");
      tele[destname] = file_name(environment(tp));
      tp->set_property(TELEPORT_PROP, tele);
      message("info", "You imprint this location upon your mind as "+destname+".", tp);
      return 1;
    break;

    case "unmark":
      if (!destname || !strlen(destname))
        FAIL("You must give the name of the location to remove.");
      if (!tele[destname])
        FAIL("You have not imprinted with any location by that name.");
      map_delete(tele, destname);
      message("info", "You wipe the imprint of "+destname+" from your mind.", tp);
      return 1;
    break;

    default:
      FAIL("Teleport what to where?");
  }

  return 1;
}

int teleport_item(object tp, string itemname, string destname) {
  object tpenv, destenv;
  object item, dest;

  if (tp->query_mp() < 250)
    FAIL("Too low on magic.");

  tpenv = environment(tp);
  if (tpenv->query_property("no magic"))
    FAIL("Some force prevents your magic.");

  item = present(itemname, tp);
  if (!item)
    FAIL("You do not have "+indefinite_article(itemname)+".");
  dest = find_player(destname);
  if (!dest)
    FAIL("Your power fails to find any one by that name.");

  tp->add_mp(-(250+random(20)));
  tp->set_paralyzed(6, "You are concentrating on your spell.");

  // recycling variable
  itemname = strip_color(item->query_short());
  itemname = replace_string(itemname, " (wielded)", "");
  itemname = replace_string(itemname, " (worn)", "");

  message("magic", COL+"You focus your power on "+definite_article(itemname)+
    " and it begins to "+COL2+"glow"+COL+"."+RES, tp);
  message("magic", COL+tp->query_cap_name()+" seems to focus on "+
    tp->query_possessive()+" "+remove_article(itemname)+
    " and it begins to "+COL2+"glow"+COL+"."+RES, tpenv, tp);

  call_out("finish_teleport", 4, tp, item, indefinite_article(itemname), dest);

  return 1;
}

int teleport_self(object tp, string destname) {
  object tpenv, destenv;
  object dest;
  mapping tele;

  if (!query_teleport_caster(tp))
    FAIL("Teleport what to where?");

  if (tp->query_mp() < 500)
    FAIL("Too low on magic.");

  tpenv = environment(tp);
  if (tpenv->query_property("no magic"))
    FAIL("Some force prevents your magic.");

  dest = find_player(destname);

  if (dest)
    dest = environment(dest);
  else {
    tele = tp->query_property(TELEPORT_PROP) || ([]);
    destname = tele[destname];
    if (!destname)
      FAIL("Your power fails to find any one or any place by that name.");
    dest = load_object(destname);
    if (!dest)
      FAIL("An error occurred, please contact a staff member.");
  }

  tp->add_mp(-(500+random(35)));
  tp->set_paralyzed(6, "You are concentrating on your spell.");

  message("magic", COL+"You focus your power into yourself.\n"
    "A bright "+COL2+"glow"+COL+" surrounds you."+RES, tp);
  message("magic", COL+"A bright "+COL2+"glow"+COL+" surrounds "+
    tp->query_cap_name()+".", tpenv, tp);

  call_out("finish_teleport", 4, tp, tp, tp->query_cap_name(), dest);

  return 1;
}

void finish_teleport(object tp, object what, string name, object dest) {
  object env = environment(tp);
  object destenv;

  if (!tp) return;
  tp->set_paralyzed(0);

  if (!what) {
    message("magic", capitalize(name)+" is gone!", tp);
    return;
  }
  if (!dest) {
    what->add_hp(-random(50));
    message("magic", COL2+tp->query_cap_name()+"'s power goes awry!"+RES, env, what);
    message("magic", COL2+"Your power goes awry!"+RES, what);
    return;
  }

  destenv = environment(dest);

  // backfire if anyone is in a no teleport room
  if (env->query_property("no teleport") || dest->query_property("no teleport") ||
     (destenv && destenv->query_property("no teleport"))) {
        message("magic", COL2+"The glow increases but finds no path to travel!\n"
          "Suddenly the magic "+COL+"explodes"+COL2+
          ", throwing you to the ground!"+RES, env);
        foreach(object liv in filter(all_inventory(env), (: $1->is_living() :))) {
          liv->set_rest_type(LAY);
          liv->set_paralyzed(4, "You are stunned by the explosion.");
          // always hurt the caster, even if no-attack room
          if (!env->query_property("no attack") || liv == tp)
            liv->add_hp(-(50+random(60)));
          // always show status line
          liv->show_status_line();
        }
  }
  // fail to move into a living thing that's full
  else if (what->move(dest) && dest->is_living()) {
    // try moving into the room it's in
    if (what->move(destenv)) {
      // room is full... should never happen
      if (!what->is_living()) {
        what->remove();
        message("magic", COL2+definite_article(name)+" shakes violently and vanishes."+RES, env);
      }
      else {
        what->add_hp(-random(50));
        message("magic", COL2+tp->query_cap_name()+"'s power goes awry!"+RES, env, what);
        message("magic", COL2+"Your power goes awry!"+RES, what);
      }
      // end of stuff that should never happen
    }
    // successfully moved into the room our target is in
    else {
      message("magic", COL2+"With a sudden pop, "+name+" disappears."+RES, env);
      message("magic", COL2+"With a sudden pop, "+name+" appears."+RES, destenv, what);
      message("magic", COL2+"With a sudden pop, you appear at your destination."+RES, what);
      what->describe_current_room(1);
    }
  }
  // successfully moved into our (non-living) target
  else {
    message("magic", COL2+"With a sudden pop, "+name+" disappears."+RES, env);
    message("magic", COL2+"With a sudden pop, "+name+" appears."+RES, dest, what);
    message("magic", COL2+"With a sudden pop, you appear at your destination."+RES, what);
    what->describe_current_room(1);
  }
}


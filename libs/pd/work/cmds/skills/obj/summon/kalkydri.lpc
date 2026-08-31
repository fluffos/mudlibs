// carrier demon for the summon spell
// a dungeonware.net collaboration with
// -(Inferno)-

#include <std.h>
#include <dirs.h>
#include <rooms.h>

#define DELIVERY_DELAY 10

inherit DIR_CLASS_CMDS+"/obj/summon/kataan_demon";

int do_message(string);
int do_carry(string);
int do_fetch(string);
void drop_off();
void start_back();
void come_back();

int delivertime, returntime, finishtime;
string delivermsg;
int teleportfollow, keephb;
object delivertgt, deliverob;

void create() {
  ::create();
  set_name("kalkydri");
  set_id( query_id() |  ({ "kalkydri", "kalkydri demon" }) );
  set_gender("male");
  set_short("a kalkydri demon");
  set_level(16);
  set_long("This demon's eight sets of black wings, gruesome "
   "horns and wicked claws glint deep purple in the "
   "available light. Despite its fearsome looks, though, "
   "the demon backs away from you, waiting for something.");
  set_body_type("sauran");
  set_race("demon");
  add_limb("first wing", "", 10, 0, 1);
  add_limb("second wing", "", 10, 0, 1);
  add_limb("third wing", "", 10, 0, 1);
  add_limb("fourth wing", "", 10, 0, 1);
  add_limb("fifth wing", "", 10, 0, 1);
  add_limb("sixth wing", "", 10, 0, 1);
  add_limb("seventh wing", "", 10, 0, 1);
  add_limb("eighth wing", "", 10, 0, 1);
  add_limb("ninth wing", "", 10, 0, 1);
  add_limb("tenth wing", "", 10, 0, 1);
  add_limb("eleventh wing", "", 10, 0, 1);
  add_limb("twelfth wing", "", 10, 0, 1);
  add_limb("thirteenth wing", "", 10, 0, 1);
  add_limb("fourteenth wing", "", 10, 0, 1);
  add_limb("fifteenth wing", "", 10, 0, 1);
  add_limb("sixteenth wing", "", 10, 0, 1);
  set_class("mage");
  set_subclass("necromancer");
  set_spell_chance(90);
  set_spells( ({ "missile" }) );
  set_stats("dexterity", 35);
  add_action("do_carry", "carry");
  add_action("do_message", "message");
  //  add_action("do_fetch", "fetch");
  set_reveal(
    "<message [player] [message to send]>\n"
    "<carry [item] to [player]>, after giving me the item"
  );
}

int do_carry(string str) {
  object tp = this_player();
  object to = this_object();
  object env = environment(to);
  object tgt, tgtenv, ob;
  string what, who;

  if (tp != to) return 0;

  if (!str || sscanf(str, "%s to %s", what, who) != 2) return 0;

  ob = present(what, to);
  tgt = find_player(who);

  if (!ob || !tgt) return 0;

  tgtenv = environment(tgt);
  if (tgtenv == env) {
    command("give "+what+" to "+who);
    return 1;
  }

  delivertime = time() + DELIVERY_DELAY;
  teleportfollow = query_property("teleport follow");
  keephb = query_property("keepheartbeat");
  delivertgt = tgt;
  deliverob = ob;

  remove_property("teleport follow");
  to->set_property("keepheartbeat", 1);

  message("mout", to->query_cap_name()+" departs.", env);
  to->move(ROOM_CACHE);

  return 1;
}

int do_message(string str) {
  object tp = this_player();
  object to = this_object();
  object env = environment(to);
  object tgt, tgtenv;
  string who;

  if (tp != to) return 0;

  if (!str || sscanf(str, "%s %s", who, delivermsg) != 2) return 0;

  tgt = find_player(who);

  if (!tgt) return 0;

  if (query_property("gagged")) {
    message("emote", query_cap_name()+" glares.", env);
    return 1;
  }
  tgtenv = environment(tgt);
  if (tgtenv == env) {
    command("whisper "+delivermsg+" to "+who);
    delivermsg = 0;
    return 1;
  }

  delivertime = time() + DELIVERY_DELAY;
  teleportfollow = query_property("teleport follow");
  keephb = query_property("keepheartbeat");
  delivertgt = tgt;

  remove_property("teleport follow");
  to->set_property("keepheartbeat", 1);
  message("mout", to->query_cap_name()+" departs.", env);
  to->move(ROOM_CACHE);

  return 1;
}

void heart_beat() {
  object to = this_object();

  ::heart_beat();

  if (!to) return;

  if (delivertime != 0 && delivertime < time())
    drop_off();

  else if (returntime != 0 && returntime < time())
    start_back();

  else if (finishtime != 0 && finishtime < time())
    come_back();

}

void drop_off() {
  object to = this_object();
  object env;

  delivertime = 0;

  if (!(deliverob || delivermsg) || !delivertgt || !(env = environment(delivertgt))) {
    finishtime = time() + DELIVERY_DELAY/2;
    return;
  }

  returntime = time() + DELIVERY_DELAY/2;

  to->move(env);
  message("min", to->query_cap_name()+" enters.", env);

  if (deliverob) {
    message("emote", to->query_cap_name()+" hands you "+indefinite_article(deliverob->query_name())+".",
     delivertgt);

    if (deliverob->move(delivertgt)) deliverob->move(env);

    deliverob = 0;
  }
  else if (delivermsg) {
    to->force_me("whisper "+delivertgt->query_name()+" "+delivermsg);
    delivermsg = 0;
  }

  delivertgt = 0;
}

void start_back() {
  object to = this_object();

  returntime = 0;
  finishtime = time() + DELIVERY_DELAY;

  message("mout", to->query_cap_name()+" departs quietly.", environment(to));
  to->move(ROOM_CACHE);

}

void come_back() {
  object to = this_object();
  object env;

  finishtime = 0;
  deliverob = 0;
  delivermsg = 0;
  delivertgt = 0;

  to->remove_property("keepheartbeat");
  to->set_property("keepheartbeat", keephb);
  to->set_property("teleport follow", teleportfollow);

  if (!query_owner() || !(env = environment(query_owner()))) return;

  to->move(env);
  message("min", to->query_cap_name()+" returns.", environment(to));

}

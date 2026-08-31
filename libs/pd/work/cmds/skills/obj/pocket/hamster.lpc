#include <std.h>
#include <rooms.h>

#define DELIVERY_DELAY 8

inherit PET;

string note;
int delivertime = 0;
int returntime = 0;
int finishtime = 0;
int teleportfollow;
int keephb;
object delivertgt;

int do_take_note(string);
int do_deliver_note(string);
void drop_off();
void start_back();
void come_back();

void create() {
  ::create();
  set_name("hamster");
  set_id( ({ "fat hamster", }) );
  set_short("fat hamster");
  set_long("A little brown hamster that looks like he's eaten way too much.");
  set_gender("male");
  set_race("hamster");
  set_body_type("quadrupe");
  set_class("rogue");
  set_subclass("scout");
  set_level(10);
  set_stats("dexterity", 30);
  set_stats("strength", 5);
  set_sp(query_max_sp());
  set_skill("stealth", 100);
  add_action("do_take_note", "take");
  add_action("do_deliver_note", "deliver");
  set_reveal(
    "<take note [write a note here]>\n"
    "<deliver note to [player]>"
  );
  set_exp_percent(60);
}

int do_take_note(string str) {
  object tp = this_player();
  object to = this_object();
  object env = environment(to);

  if (!tp || !env || tp != to) return 0;

  if (sscanf(str, "note %s", str) != 1) {
    command("emote squeaks in alarm.");
    return 0;
  }

  note = str;

  command("emote squeaks amiably.");

  return 1;
}

int do_deliver_note(string str) {
  object tp = this_player();
  object to = this_object();
  object env = environment(to);
  object tgt;

  if (!tp || !env || tp != to) return 0;

  if (sscanf(str, "note to %s", str) != 1 ||
      !(tgt = find_player(str)) || !note || !strlen(note) ) {
        command("emote squeaks in alarm.");
        return 0;
  }

  delivertime = time() + DELIVERY_DELAY;
  teleportfollow = query_property("teleport follow");
  keephb = query_property("keepheartbeat");
  delivertgt = tgt;

  remove_property("teleport follow");
  to->set_property("keepheartbeat", 1);

  message("mout", to->query_cap_name()+" squeaks and takes off.", env);
  to->move(ROOM_CACHE);

  return 1;
}

void heart_beat() {
  object to = this_object();
  object env, noteobj;


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
  object env, noteobj;

  delivertime = 0;

  if (!delivertgt || !(env = environment(delivertgt))) {
    finishtime = time() + DELIVERY_DELAY/2;
    return;
  }

  returntime = time() + DELIVERY_DELAY;

  to->move(env);
  message("min", to->query_cap_name()+" runs in.", env);

  message("emote", to->query_cap_name()+" squeaks at you and drops a note.",
    delivertgt);

  noteobj = new(OBJECT);
  noteobj->set_id( ({ "note", "paper", "short note", "piece of paper" }) );
  noteobj->set_short("a note");
  noteobj->set_long("This is a short note scrawled on a small piece of paper. Try reading it.");
  noteobj->set_weight(1);
  noteobj->set_curr_value("gold", 0);
  noteobj->set_read("default", note);
  noteobj->move(env);

  note = 0;
  delivertgt = 0;
}

void start_back() {
  object to = this_object();

  returntime = 0;
  finishtime = time() + DELIVERY_DELAY;

  message("mout", to->query_cap_name()+" runs in a circle and then leaves.", environment(to));
  to->move(ROOM_CACHE);

}

void come_back() {
  object to = this_object();
  object env;

  finishtime = 0;
  note = 0;
  delivertgt = 0;

  to->remove_property("keepheartbeat");
  to->set_property("keepheartbeat", keephb);
  to->set_property("teleport follow", teleportfollow);

  if (!query_owner() || !(env = environment(query_owner()))) return;

  to->move(env);
  message("min", to->query_cap_name()+" runs in.", environment(to));

}



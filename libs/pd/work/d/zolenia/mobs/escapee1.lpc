#include <std.h>
#include <rooms.h>
#include <zolenia.h>
inherit MOUNT;

int check_ride(object);
int cmd_lead(string);
void finish_deed();

int scene = 0;

void create() {
  ::create();
  set_name("dragon");
  set_short("%^RESET%^%^BOLD%^a %^RED%^bloodied %^BLUE%^escapee %^WHITE%^baby dragon%^RESET%^");
  set_long("The blue baby dragon has many bloodied wounds and scars.  He is very powerful looking for his size.  He has a saddle on his back.  He looks determined to solve some sort of quest.");
  set_id(({"zolenia_deed_dragon", "dragon", "bloodied dragon"}));
  set_level(51+random(6));
  set_race("dragon");
  set_body_type("dragon");
  set_gender("male");
  set_class("dragon");
  set_subclass("green");
  add_money("gold", 2000);    
  add_money("platinum", 100);
  set_spell_chance(20);    
  set_spells(({"jab", "swoop", "bite"}));  
  set_max_riders(1);
  scene = 0;
}

void catch_tell(string str) {
  string a, b;
  if(!str) return;
  str=lower_case(strip_colours(str));
  if(sscanf(str, "%s says: %s", a, b)!=2) return;
  if(sscanf(b, "%squest%s", a, str)==2) {
    command("say You'd like a quest?  How about you rescue me.");
  }
  else if(sscanf(b, "%srescue%s", a, str)==2) {
    object tp = this_player();
    if (tp && tp->is_player()) {
      if (tp->query_rideable()) {
        command("say I think the best way for you to rescue me is to lead me out of here!");
      }
      else {
        command("say I think the best way for you to rescue me is to ride me and get a move on out of here!");
      }
    }
  }
}

void init() {
  ::init();
  add_action("cmd_lead", "lead");
}

int cmd_lead(string str) {
  object tp = this_player();
  object to = this_object();
  object env = environment(to);
  object leader = query_rider() || query_following();

  if (!str || present(str, env) != to)
    return notify_fail("Lead who?\n");

  if (leader && present(leader, env))
    command("say Sorry "+tp->query_cap_name()+", but I'm already following "+
            leader->query_cap_name()+".");

  else {
    tp->add_follower(to);
    command("say Ok, I'll follow you, "+tp->query_cap_name()+".");
  }

  return 1;
}

int check_ride(object tp) {
  object env = environment();
  // check if the beginning of the file name of the room is the same
  // as the area this mob is from: "/d/zolenia/rooms/" or whatever
  if (strsrch(ROOMS, file_name(env)) != 0) {
    command("say I don't want to be ridden, I'm free!");
    return 0;
  }
  return 1;
}

void heart_beat() {
  ::heart_beat();
  if (!this_object()) return;

  switch (scene) {
    case 1:
      command("say Hey, a portal! I bet we could get out through that!");
    break;
  }

  if (scene >= 1) scene = 0;
}

void start_scene() { scene = 1; }

void finish_deed() {
  object tp = this_object();
  object who = query_rider() || query_following();
  string *deeds;
  if (!who) return;
  set_rideallow(0);
  dismount_all("You buck everyone off.", "The dragon bucks you off.");
  command("say Thank you for rescuing me!");
  command("emote runs off.");
  deeds = who->query_mini_quests();
  if (!deeds || member_array("zoleniadragon", deeds) == -1) {
    message("info", "You feel more experienced from your good deed.", who);
    who->add_alignment(50);
    who->set_mini_quest("zoleniadragon", 250000,
      "You helped rescue the trapped dragon in Zolenia.\n");
  }
  tp->move(ROOM_VOID);
  tp->remove();
}

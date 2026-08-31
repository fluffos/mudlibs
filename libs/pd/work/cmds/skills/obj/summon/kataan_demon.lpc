#include <std.h>
#include <daemons.h>
#include <rooms.h>
inherit PET;
int skillreq = 50;
string returnmsg = "returns to the Abyss.";
string summonmsg = "enters.";
void set_summoning(int);
void set_return(string);
void set_summon_msg(string);
string query_summon_msg();
int cmd_check(string, string);
int do_return(string);
void create() {
  set_property("no monster", 1);
  ::create();
  set_id( ({ "demon", "abyss demon" }) );
  set_aggressive(0);
  set_body_type("demon");
  set_race("demon");
  set_alignment(-1000);
  set_exp(0);
  set_exp_percent(75);
  set_command_check( (: cmd_check :) );
  add_action("do_return", "return");
}
void set_summoning(int x) { skillreq = x; }
void set_return(string s) { returnmsg = s; }
void set_summon_msg(string str) { summonmsg = str; }
string query_summon_msg() { return capitalize(indefinite_article(query_short()))+" "+summonmsg; }
int cmd_check(string cmd, string arg) {
   int x;
   if (random(skillreq) > (int)query_owner()->query_skill("summoning")) {
      x=random(20);
      switch (x) {
         case 1: case 4: case 15:
            message("info", capitalize(query_name())+" ignores your command!", query_owner());
            return 0;
         case 10: case 19:
            message("info", capitalize(query_name())+" breaks out of your control!", query_owner());
            this_object()->kill_ob(query_owner());
            set_owner(0);
            return 0;
         default:
      }
   }
   return 1;
}
int do_return(string str) {
  object to = this_object();
  object *ai = all_inventory(to);
  message("info", "%^BOLD%^"+capitalize(query_name())+" "+returnmsg+"%^RESET%^",
    environment(to), to);
  if (sizeof(ai)) { ai->set_theft(1); ai->move(environment(to)); ai->set_theft(0); }
  to->remove_property("teleport follow");
  if (to->query_following()) to->query_following()->remove_follower(to);
  to->move(ROOM_CACHE);
  call_out("remove_me", 0);
  return 1;
}

void remove_me() { if (this_object()) this_object()->remove(); }

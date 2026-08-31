
#include <std.h>

#define BUMP_PROP "bump_abil_info"

inherit OBJECT;

object owner;
string who;
int flag;
int start;

void set_owner(object o) { owner = o; }
void set_who(string w) { who = w; }
void set_start(int i) { start = i; }
void ambush_target(object owner, object tp);

void create() {
  ::create();
  set_id( ({"ambush_ob"}) );
  set_weight(0);
  set_prevent_get("Get what?");
  owner = 0;
  who = "";
  flag = 0;
  start = 0;
}

void init() {
  mixed *check = ({ });
  object tp = this_player();
  ::init();
  if (!tp || !start) return;
  if (!owner || flag || environment(owner) != environment(this_object())) {
    "/cmds/skills/_ambush"->ambush_off(owner);
    return;
  }
  if (tp == owner) return;
  if (!strlen(tp->query_long())) return;
  if (sizeof(check = (mixed *)tp->query(BUMP_PROP)) && check[1] == owner && check[0] < time()+20) return;
  if (!strlen(who) || tp->id(who) || tp->query_name() == who) {
    flag = 1;
//    call_out("ambush_target", 0, owner, tp);
    ambush_target(owner, tp);
  }
}

void ambush_target(object owner, object tp) {
  "/cmds/skills/_ambush"->do_ambush(owner, tp);
}

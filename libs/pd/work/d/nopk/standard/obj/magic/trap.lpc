#include <std.h>

inherit OBJECT;

int skill;
object owner;

void create() {
  ::create();
  set_short("");
  set_long("A trap made with sinew and wood...  The work of a ranger.");
  set_id(({"trap", "ranger_trap_id"}));
  set_weight(100);
  set_prevent_get("It would go off if you took it!");
  skill = 1;
  owner = this_player();
}

void set_skill(int x) { skill = x; }

void init() {
  ::init();
  add_action("disarm", "disarm");
  if(query_verb() == "trap") return;
  if(this_player() == owner){
    write("You notice your trap still set.");
    return;
  }
  if(this_player()->query_skill("perception") > random(skill)) {
    write("As you enter, you notice a trap!\nYou can try to disarm it or just leave it.");
    return;
  }
  write("As you enter, you spring a trap!");
  say("As "+this_player()->query_cap_name()+" enters, they spring a trap!");
  if(this_player()->query_stats("dexterity") > random(skill/2)) {
    write("Luckily, you manage to get out of the way.");
    say(this_player()->query_cap_name()+" manages to get out of the way.");
    this_object()->remove();
    return;
  }
  if(owner->kill_ob(this_player()))
    this_player()->damage(random(skill/4) + random(20));
  this_object()->remove();
  return;
}

int disarm(string str) {
  if(!str) return notify_fail("Disarm what?\n");
  if(str != "trap") return notify_fail("You cannot disarm that.\n");
  if(this_player()->query_stats("dexterity") > random(skill/3)) {
    write("You skillfully disarm the trap.");
    say(this_player()->query_cap_name()+" disarms the trap.");
    this_object()->remove();
    return 1;
  }
  if(random(10) > 7) {
    write("You accidently set off the trap at point blank range!");
    say(this_player()->query_cap_name()+" accidently sets off the trap while trying to disarm it!");
    this_player()->damage(random(skill/3) + random(30));
    this_object()->remove();
    return 1;
  }
  write("You fail to disarm the trap.");
  say(this_player()->query_cap_name()+" fails to disarm the trap.");
  return 1;
}

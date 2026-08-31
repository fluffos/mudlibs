// a dungeonware.net production -2:19 PM 8/8/2002-
// coded for Primal Darkness by Stormbringer
#include <std.h>
inherit DAEMON;
mapping waiting;
int spell();
void create()
{
    waiting = ([]);
}
int query_waiting(object ob) { return waiting[ob]; }
int cmd_ironskin(string str) {
    object ob;
    int defense, def;
    int cost, amount, time;
   if (!spell()) {
      write("What?\n");
      return 1;
   }
    ob = this_player();
    if (waiting[ob]){
        write("Your skin is already as hard as iron.\n");
        return 1;
    }
    if(environment(this_player())->query_property("no magic")) {
        notify_fail("A holy force prevents this.\n");
        return 0;
    }
    if((int)this_player()->query_mp() < cost) {
        notify_fail("Too low on magic power.\n");
        return 0;
    }
    if (this_player()->query_disable())
        return notify_fail("You are busy.\n");
    defense = (int)this_player()->query_skill("magic defense");
    cost = defense/2;
    if(defense < 15) {
        write("You concentrate and do not feel the chi.");
        return 1;
    }
    write("%^YELLOW%^You concentrate your chi causing your skin to harden like iron.%^RESET%^");
    if (defense < 50) def = 1; else
    if (defense < 150) def = 2; else
    if (defense < 300) def = 3; else
    if (defense < 500) def = 4; else
    if (defense > 500) def = 4; 
    amount = (def)+(random(def))+(def/2);
    time = (def*15)+random(def*2);
    waiting[ob] = time;
    ob->add_magic_protection( ({ 0, amount , time }));
    call_out("ironskin_off", time, this_player());
    this_player()->set_disable();
    this_player()->add_skill_points("magic defense", random(defense/30));
    this_player()->add_skill_points("faith", random(defense/30));
    this_player()->add_alignment(random(defense/20));
    this_player()->add_exp(random(defense/10));
    this_player()->add_mp(-cost);
    return 1;
}
void ironskin_off(object ob) {
        write("%^YELLOW%^Your skin returns to normal.%^RESET%^\n");
        map_delete(waiting, ob);
     return 1;
}
void help() {
  write("Syntax: <ironskin>\n\n
Monks concentrate their chi energies into making their 
skin as hard as iron.");
}
int spell() {
   object tp;
   tp = this_player();
   if (!tp) return 0;
   if (tp->query_level() < 10) return 0;
   if (tp->query_skill("faith") < 25) return 0;
   if (tp->query_subclass() != "monk") return 0;
   return 1;
}

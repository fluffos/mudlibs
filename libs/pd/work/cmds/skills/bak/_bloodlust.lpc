#include <std.h>
inherit DAEMON;
mapping waiting;
int spell();
string type() { return "faith"; }
void create()
{
    waiting = ([]);
}
int query_waiting(object ob) { return waiting[ob]; }
int cmd_bloodlust(string str) {
    object ob;
    string skill;
    int defense, attack, def, fer;
    int cost, amount, time;
   if (!spell()) {
      return 0;
   }
    this_player()->set_magic_round(1);
    ob = this_player();
    if(str) return notify_fail("You can only bloodlust yourself!.\n");
    
    if (waiting[ob]){
        write("The demons have already granted bloodlust upon you.\n");
        return 1;
    }
    if(environment(this_player())->query_property("no magic")) {
        notify_fail("A holy force prevents this.\n");
        return 0;
    }
    if (this_player()->query_disable())
        return notify_fail("You are too busy to bloodlust.\n");
    
    if(ob->query_mp() < ob->query_max_mp() || 
        ob->query_hp() < ob->query_max_hp())
                return notify_fail("You must be at full strength to bloodlust yourself!\n");
    
    fer = ob->query_skill("ferocity");
    
    write("%^BOLD%^%^RED%^The demons answer your prayer and suddenly you are filled with Bloodlust!%^RESET%^");
    message("info", "%^BOLD%^%^RED%^" +ob->query_cap_name()+" eminates an evil aura and is overwhelmed with Bloodlust!%^RESET%^",
        environment(this_player()), ({ this_player() }) );


    if (fer < 75) def = 1; else
    if (fer < 110) def = 2; else
    if (fer < 170) def = 3; else
    if (fer < 250) def = 4; else
    if (fer < 400) def = 5; 
    else def = 6;
    
    time = (def*150)+random(def*5);
    waiting[ob] = time;

    ob->add_skill_bonus("attack", ob->query_skill("attack")/5, time);
    ob->add_skill_bonus("defense", -ob->query_skill("attack")/8, time);
    ob->add_stat_bonus("strength", (6+random(4)+this_player()->query_faith()/50), time);


    call_out("bloodlust_off", time, this_player());
    this_player()->set_disable();
    this_player()->add_mp(-(ob->query_max_mp() / 2));
    return 1;
}
void bloodlust_off(object ob) {
    if (ob) {
        write("%^BOLD%^%^BLACK%^You feel the evil from the demons leave your body making you feel weaker.%^RESET%^\n");
        ob->add_mp(ob->query_max_sp()/ 8);
    }
        map_delete(waiting, ob);
}
void help() {
  write("Syntax: <bloodlust>\n\n Antipaladins pray to demons for more power.");
}
int spell() {
   object tp;
   tp = this_player();
   if (!tp) return 0;
   if (tp->query_level() < 20) return 0;
   if (tp->query_skill("faith") < 20*4) return 0;
   if (tp->query_subclass() != "antipaladin") return 0;
   return 1;
}



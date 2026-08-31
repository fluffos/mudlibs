// tailspear..  by Nightshade
 
#include <std.h>
inherit DAEMON;
int abil();
 
int cmd_tailspear(string str) { 
    int attack, total;
    object ob;

    if (!abil()) {
        write("What?\n");
        return 1;
    }
    if(!str)
        ob = (object)this_player()->query_current_attacker();
    else {
        ob = present(str, environment(this_player()));
        if(!ob) ob = parse_objects(environment(this_player()), str);
    }
    if(!ob || !living(ob)) {
        notify_fail("You do not see that here.\n");
        return 0;
    }
    if (ob==this_player())
        return notify_fail("You are an idiot.\n");
    if(this_player()->query_ghost()) {
        notify_fail("You are a ghost.");
        return 0;
    }
    if (this_player()->query_disable()){
        write("You are not in a position to gore your opponent.");
        return 1;
    }
 
   
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
    if(environment(this_player())->query_property("no attack")) {
        notify_fail("Greater powers prevent your malice.\n");
        return 0;
    }
    if((int)this_player()->query_sp() < 20) {
        notify_fail("You are too tired.\n");
        return 0;
    }
    this_player()->set_disable();
    attack = this_player()->query_skill("attack")/2;
    attack += this_player()->query_stats("strength"); 
    attack += this_player()->query_skill("tail");
    attack -= ob->query_stats("dexterity")*2/3;
    attack -= ob->query_skill("defense")/3;
    if (attack < 10) {
        write("You try to tailspear your opponent but miss.");
        tell_room(environment(this_player()), this_player()->query_cap_name()+
          "tries to spear "+ob->query_cap_name()+" but misses!", ({ ob, this_player() }));
        return 1;
    }
    write("You spear "+ob->query_cap_name()+" with your tail!\n");
    tell_room(environment(this_player()), this_player()->query_cap_name()+
      " spears "+(string)ob->query_cap_name() + " with their tail!\n", ({ob, this_player()}));
    tell_object(ob, this_player()->query_cap_name()+" spears you with their tail!\n");
    total = random(this_player()->query_level()) + (attack);
    this_player()->add_skill_points("attack", total/40);
    this_player()->add_skill_points("tail", total/20);
    this_player()->add_sp(-total/7);
    ob->damage(total + (random(this_player()->query_level()/2)));
    return 1;
}

void help() {
write("Syntax: <tailspear [living]>\n\n"
"The dragon can lash out with the tip of it's tail, puncturing it's victim badly.");
}

int abil() {
   object r;
   r = this_player();
   if (!r) return 0;
   if (r->query_race() != "dragon") return 0;
   if (r->query_level() < 4) return 0;
   return 1;
}

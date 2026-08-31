//      /cmds/skills/_lunge.c
//      Swashbuckler ability
//      By Nightshade 12-17-01
 
#include <daemons.h>
#include <std.h>
inherit DAEMON;
int abil();

string type() { return "attack"; }
 
int cmd_lunge() {
    object tp, ob;
    int def1;
 
    if (!abil()) {
        return 0;
    }
    tp = this_player();
    if(!sizeof((object *)tp->query_wielded())) {
        notify_fail("You don't have anything to lunge with!\n");
        return 0;
    }
    if(tp->query_ghost()) {
        notify_fail("You are dead and cannot do that.\n");
        return 0;
    }
    if(tp->query_disable()) return 1;
    if (environment(tp)->query_property("no attack")) {
        notify_fail("You cannot lunge here.\n");
        return 0;
    }
    if((int)tp->query_sp() < 20) {
        notify_fail("You are too exhausted to lunge.\n");
        return 0;
    }
    if(!(ob = (object)tp->query_current_attacker())) {
         notify_fail("You are not in battle.\n");
         return 0;
    }
    tp->set_disable();
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
    def1 = BALANCE3_D->get_damage( tp, ob, 1, ({ "attack" }),
                                   ({ "dexterity" }) );
    if(def1 > 0) {
          write("You lunge at "+(string)ob->query_cap_name()+".\n");
         say(tp->query_cap_name() + " lunges at " +
              (string)ob->query_cap_name()+".\n");
         ob->damage(def1);
    }
    else {
        write("You fail in your lunge at "+(string)ob->query_cap_name()+".\n");
         say(tp->query_cap_name()+ " tries to lunge at "+(string)ob->query_cap_name()+", but misses.\n");
         tp->add_sp(-10);
         return 1;
    }
    tp->add_skill_points("attack", def1 / 20 );
    tp->add_sp(-def1 /7);
    return 1; 
}
 
void help() {
    write("Syntax: <lunge>\n\n"
        "Allows you to lunge at your current enemy, piercing them severly.\n"
    );
}
int abil() {
   if (this_player()->query_subclass() == "swashbuckler") return 1;
   return 0;
}

//      /cmds/skills/_disarm.c
//      Swashbuckler ability
//      By Nightshade 12-17-01
 
#include <std.h>
inherit DAEMON;
int abil();

string type() { return "defense"; }
 
int cmd_disarm(string str) {
    object tp, ob;
    int def1, def2;
 
    if (!abil()) {
        return 0;
    }
    tp = this_player();
    if(tp->query_ghost()) {
        notify_fail("You are dead and cannot do that.\n");
        return 0;
    }
    if(tp->query_disable()) return 1;
    if (environment(tp)->query_property("no attack")) {
        notify_fail("You cannot disarm here.\n");
        return 0;
    }
    if((int)tp->query_sp() < 20) {
        notify_fail("You are too exhausted to try and disarm anything.\n");
        return 0;
    }
    if(str)
        if(present(str, environment(tp)))
            tp->kill_ob(present(str, environment(tp)));
        else
            return notify_fail("That is not here to disarm!\n");
    if(!(ob = (object)tp->query_current_attacker())) {
         notify_fail("You are not in battle.\n");
         return 0;
    }
    if(!sizeof((object *)ob->query_wielded())) {
        notify_fail("They are not wielding anything!\n");
        return 0;
    }
    tp->set_disable();
    def1 = (int)tp->query_skill("attack") + (int)tp->query_stats("dexterity");
    def2 = (int)ob->query_skill("defense") + (int)ob->query_stats("dexterity");
    def2 = def2/2 + random(def2/2);
    if(def1 >= def2) {
          write("You disarm "+(string)ob->query_cap_name()+"!\n");
         say(tp->query_cap_name() + " manages to disarm " +
              (string)ob->query_cap_name()+"!\n");
         ob->force_me("unwield "+(string)(ob->query_wielded()[0])->query_id()[0]);
    }
    else {
        write("You fail to disarm "+(string)ob->query_cap_name()+".\n");
         say(tp->query_cap_name()+ " tries to disarm "+(string)ob->query_cap_name()+".\n");
         tp->add_sp(-10);
         return 1;
    }
    def1 = (int)tp->query_skill("attack");
    tp->add_skill_points("attack", def1/20 );
    tp->add_sp(-10 - random(15));
    return 1; 
}
 
void help() {
  write("Syntax: <disarm [living]>\n\n"
        "Allows  you to disarm your opponent.\n"
    );
}

int abil() {
   if (this_player()->query_subclass() == "swashbuckler") return 1;
}

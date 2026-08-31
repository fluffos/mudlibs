// Dragon's attack
// Nightshade

#include <daemons.h>
inherit DAEMON;
int abil();

int cmd_claw(string str) {
    int a;
    object ob;

    if (!abil()) {
        notify_fail("What?\n");
        return 0;
    }
    if ((!str || str=="") && !this_player()->query_current_attacker()) {
        notify_fail("Claw what?");
        return 0;
    }
    if (environment(this_player())->query_property("no attack")) {
        write("Greater powers prevent your malice.");
        return 1;
    }
    if(this_player()->query_disable()) {
        write("You are too busy doing something else!");
        return 1;
    }
    if (this_player()->query_current_attacker()) 
        ob = this_player()->query_current_attacker();
    else {
        ob = present(str, environment(this_player()));
        if (!ob) {
            write("You dont see that.");
            return 1;
        }
        if (ob==this_player()) {
            write("That sure would hurt.");
            return 1;
        }
    }
    if (this_player()->query_sp() < 20) {
        write("You are too tired to claw.");
        return 1;
    }
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
    this_player()->set_disable();
 
    a = this_player()->query_skill("attack")*3/2 -
        ob->query_skill("defense")/2 +
        this_player()->query_skill("claw")*3/4 -
ob ->query_stats("dexterity") * 2/3 + this_player()->query_stats("strength");

    if (a < 0) {
        write("You miss your claw.");
        say( this_player()->query_cap_name()+" swings "+possessive(this_player())+" claw but misses.");
        return 1;
    }
    
    write("You claw "+ob->query_cap_name()+" with your %^BOLD%^razor sharp%^RESET%^ claws!");
    say(this_player()->query_cap_name()+" claws "+ob->query_cap_name()+" with "+possessive(this_player())+" %^BOLD%^razor sharp%^RESET%^ claws!", ob);        
    message("info", this_player()->query_cap_name()+" claws into you with "+possessive(this_player())+" %^BOLD%^razor sharp%^RESET%^ claws!", ob);
    //target_thing = (string)ob->return_target_limb();
    ob->damage(a*2/9 + (random(this_player()->query_level()/2)));
                            
    this_player()->add_sp(-a/7);

    return 1;
}

int abil() {
   object o;
   o = this_player();
   if (!o) return 0;
   if (o->query_class() != "dragon") return 0;
   if (o->query_skill("claw") < 10) return 0;
   return 1;
}
void help() {
   write("Syntax: <claw [(living)]>\n\n"
      "A dragon's ability to use it's claws in \ncombat to injure it's victim.\n"); }

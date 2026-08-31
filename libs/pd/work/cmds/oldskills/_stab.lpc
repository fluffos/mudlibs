#include <daemons.h>
inherit DAEMON;
int abil();
int cmd_stab(string str)
{
    int a,b, i, clear;
    string target_thing;
    object ob;
    object *wield, *knives;
    knives = ({});
    if (!abil()) {
        write("What?\n");
        return 1;
    }
    if ((!str || str=="") && !this_player()->query_current_attacker())
    {
        write("Stab what?");
        return 1;
    }
    if (environment(this_player())->query_property("no attack"))
    {
        write("Greater powers prevent your malice.");
        return 1;
    }
    if(this_player()->query_rest_type()) {
        return notify_fail("You cannot stab while resting.");
    }
    if(!b=sizeof(wield=this_player()->query_wielded())) {
        return notify_fail("You need a knife to stab with!\n");
    }
    i = sizeof(wield);
    while (i--) {
        if(wield[i]->query_type() == "knife")
            knives  += ({ wield[i] });
    }
    b = sizeof(knives);
    if (this_player()->query_current_attacker()) 
        ob = this_player()->query_current_attacker();
    else {
        ob = present(str, environment(this_player()));
        if (!ob)
        {
            write("You dont see that.");
            return 1;
        }
        if (ob==this_player())
        {
            write("Something must be wrong with you.");
            return 1;
        }
    }
    if (this_player()->query_sp() < 50) 
    {
        write("You are too tired to stab.");
        return 1;
    }
    if (this_player()->query_disable())
       return notify_fail("You are busy.\n");
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
        return 1;
    }
    this_player()->set_disable();
    if (b > 1)
        if (this_player()->query_skill("murder") < random(80))
            b = 1;
    while(b--) {
        if(b >= 2) {
            if(random(3) == 0)
                b--;
            if(random(10) == 0)
                b--;
        }
        // Added to prevent arena deaths
        if(this_player()->query_arena())
            if(!present(ob->query_name(), environment(this_player())))
                return 1; 
        a = this_player()->query_skill("murder") -
        ob->query_skill("defense")/2 +
        this_player()->query_stats("strength")*5/2 +
        this_player()->query_stats("dexterity")*5/3 -
        ob->query_stats("dexterity")*2/3 +
        knives[b]->query_wc()*5/4;
        if (a < 0)
        {
            write("You miss your stab.");
            say( this_player()->query_cap_name()+" misses "+possessive(this_player())+" stab.");
            return 1;
        }
        write("You stab "+ob->query_cap_name()+" with your "+knives[b]->query_cap_name()+".");
        message("info", this_player()->query_cap_name()+" stabs "+ob->query_cap_name()+".", environment(this_player()), ({ this_player(), ob }));        
        message("info", this_player()->query_cap_name()+" stabs you.", ob);
        target_thing = (string)ob->return_target_limb();
        ob->do_damage(target_thing, a*2/6);
        ob->check_on_limb(target_thing);
        this_player()->add_sp(-(a/7));
    }
    return 1;
}
int abil() {
    object o;
    o = this_player();
    if (!o) return 0;
    if (o->query_class() != "rogue") return 0;
    if (o->query_level() < 5) return 0;
    if (o->query_skill("knife") < 14) return 0;
    return 1;
}
void help() {
    write("Syntax: <stab [(living)]>\n\n"
      "A rogue command which enables you to use your knife to stab your oponent. If you are wielding more that one knife you have the ability to stab more than once.\n"); }

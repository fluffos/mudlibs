#include <std.h>
#include <daemons.h>
#include <rest.h>

inherit DAEMON;
int abil();
int cmd_smash(string str) {
   int dmg, cost;
   object ob, tp, env;
   object *wield;
   tp = this_player();
   env = environment(tp);
   if (!str) ob = tp->query_current_attacker();
   else ob = present(str, env);
   if(!abil())
     return 0;
   if (!ob) {
    if (str)
      notify_fail("You do not see "+str+" here.\n");
      return 0;
   }
   if (tp->query_class() != "rogue")
      return notify_fail("What?\n");
   if (env->query_property("no attack"))
      return notify_fail("Greater powers prevent your malice.\n");
   if (!living(ob))
      return notify_fail("Syntax: <clobber [living]>\n");
   if (tp->query_disable())
      return notify_fail("You are busy.\n");
   if (ob == tp)
      return notify_fail("You run around in circles.\n");
   if (tp->query_sp() < 10) 
      return notify_fail("You are too tired.\n");
    if(tp->query_rest_type())
       return notify_fail("You cannot do that while on the ground!\n");
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
    if(this_player()->ghost())
        return notify_fail("You appear to be dead.\n");

    if(sizeof(wield=(object *)this_player()->query_wielded())) 
    {
        notify_fail("Your weapons make it impossible to to punch "+ob->query_cap_name()+"!\n");
        return 0;
    }

    tp->set_disable();
    
    if(!ob->query_rest_type())
    {
        if (this_player()->query_level() < 20)
        {
            dmg = BALANCE_D->get_damage( tp, ob, 1, ({ "attack", "melee", "melee"}),
                ({ "strength", "strength", "dexterity" }) );
            cost = (this_player()->query_skill("melee")/16 + 
                random(this_player()->query_skill("melee")/25));       
        }
        else if (this_player()->query_level() < 36)
        {
            dmg = BALANCE_D->get_damage( tp, ob, 2, ({ "attack", "melee", "melee"}),
                ({ "strength", "strength", "dexterity" }));
            cost = (this_player()->query_skill("melee")/16 + 
                random(this_player()->query_skill("melee")/25));      
        }
        else
        {
            dmg = BALANCE_D->get_damage( tp, ob, 3, ({ "attack", "melee", "melee"}),
                ({ "strength", "strength", "dexterity" }), ({ "strength", "dexterity" }) );
            cost = (this_player()->query_skill("melee")/16 + 
                random(this_player()->query_skill("melee")/25));     
        }
        if (dmg < 10) {
            write("You miss!");
            return 1;
        }
        
        if(random(2) == 1)
        {
            write("You punch "+ob->query_cap_name()+" hard in the stomach!");
            tell_object(ob, tp->query_cap_name()+" punches you in the stomach!");
            tell_object(ob, "You cough up some %^RED%^%^BOLD%^blood!");
            message("combat", tp->query_cap_name()+" punches "+ob->query_cap_name()+
                " hard in the stomach!", env, ({ tp, ob }));   
            message("blood", ob->query_cap_name()+ " coughs up some %^RED%^%^BOLD%^blood!",env,ob);
            dmg = dmg * 5 / 4;  
        }
        else
        {
            write("You punch "+ob->query_cap_name()+" hard in the face!");
            tell_object(ob, tp->query_cap_name()+" punches you in the face!");            
            message("combat", tp->query_cap_name()+" punches "+ob->query_cap_name()+
                " hard in the face!", env, ({ tp, ob }));   
            if((tp->query_stats("strength") > (ob->query_stats("constitution")*3/2)) && random(100) > 75)
            {
                message("knockout", ob->query_cap_name()+ "'s eyes roll back and they fall to the ground!", 
                    env, ob);
                tell_object(ob, "You feel light in the head and fall back on to the ground!");
                ob->set_rest_type(LAY);
                ob->set_paralyzed(random(2),"You are dazed from the hit!");

            }
        }
        
        
        tp->add_sp(-(cost));
        ob->damage(dmg);
    }
    else
    {
        return notify_fail(ob->query_cap_name()+" is not in a position to be punched!\n");
    }
    return 1;
   
}
void help() {
write("Syntax: <clobber [victim]> \n"+
        "A thug ability where the thug will punch their opponent as hard as possible, sometimes causing the victim to be knocked to the ground.");
}
int abil() {
    object o;
    o = this_player();
    if (o && o->query_level() < 15) return 0;
    if (o->query_subclass() != "thug") return 0;
    if (o->query_skill("melee") < 90) return 0;
    return 1;
}

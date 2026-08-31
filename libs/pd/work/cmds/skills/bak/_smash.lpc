#include <std.h>
#include <daemons.h>
inherit DAEMON;
int abil();
string type() { return "attack"; }
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
      return notify_fail("Syntax: <rush [living]>\n");
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
        notify_fail("Your weapons make it impossible to to grab "+ob->query_cap_name()+"!\n");
        return 0;
    }

    
    
    if(env->query_property("indoors") || 
        env->query_property("mountain") ||
        env->query_property("forest") ||
        env->query_property("town"))
    {
        if (this_player()->query_level() < 30)
        {
            dmg = BALANCE_D->get_damage( tp, ob, 2, ({ "attack", "melee", "melee"}),
                ({ "strength", "strength", "dexterity" }) );
            cost = (this_player()->query_skill("melee")/5 + 
                random(this_player()->query_skill("melee")/10));       
        }
        else if (this_player()->query_level() < 50)
        {
            dmg = BALANCE_D->get_damage( tp, ob, 3, ({ "attack", "melee", "melee"}),
                ({ "strength", "strength", "dexterity" }), ({ "strength", "dexterity" })  );
            cost = (this_player()->query_skill("melee")/5 + 
                random(this_player()->query_skill("melee")/10));      
        }
        else
        {
            dmg = BALANCE_D->get_damage( tp, ob, 4, ({ "attack", "melee", "melee"}),
                ({ "strength", "strength", "dexterity" }), ({ "strength", "dexterity" }) );
            cost = (this_player()->query_skill("melee")/5 + 
                random(this_player()->query_skill("melee")/10));     
        }
        if (dmg < 10) {
            write("You miss!");
            return 1;
        }
        if(env->query_property("forest"))
        {
            write("You grab "+ob->query_cap_name()+" by the head and slam them into a tree!");
            tell_object(ob, tp->query_cap_name()+" grabs you by the head and slams you into a tree!");
            message("combat", tp->query_cap_name()+" grabs "+ob->query_cap_name()+
                " by the head and slams them into a tree!", env, ({ tp, ob }));
        }
        if(env->query_property("mountain"))
        {
            write("You grab "+ob->query_cap_name()+" by the head and slam them into a nearby cliff face!");
            tell_object(ob, tp->query_cap_name()+" grabs you by the head and slams you into a nearby cliff face!");
            message("combat", tp->query_cap_name()+" grabs "+ob->query_cap_name()+
                " by the head and slams them into a nearby cliff face!", env, ({ tp, ob }));
        }
        if(env->query_property("indoors") || env->query_property("town"))
        {
            write("You grab "+ob->query_cap_name()+" by the head and slam them into a nearby wall!");
            tell_object(ob, tp->query_cap_name()+" grabs you by the head and slams you into a nearby wall!");
            message("combat", tp->query_cap_name()+" grabs "+ob->query_cap_name()+
                " by the head and slams them into a nearby wall!", env, ({ tp, ob }));
        }       
        
        tp->add_sp(-(cost));
        ob->damage(dmg);
    }
    else
    {
        return notify_fail("There is nothing around to smash them into!\n");
    }
    tp->set_disable();
    return 1;

}
void help() {
write("Syntax: <smash [victim]> \n"+
        "The thug will grab the opponent by the head and throw them into the nearest solid object. If no solid object is around, the attack will fail.");
}
int abil() {
    object o;
    o = this_player();
    if (o && o->query_level() < 19) return 0;
    if (o->query_subclass() != "thug") return 0;
    if (o->query_skill("melee") < 120) return 0;
    return 1;
}

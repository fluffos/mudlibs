#include <std.h>
#include <daemons.h>
#include <rest.h>

inherit DAEMON;
int abil();
string type() { return "attack"; }
int cmd_flip(string str) {
   int dmg, cost, b, i, wc, clear;
   float mod = 1;
   object ob, tp, env, wep;
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

   if (env->query_property("no attack"))
      return notify_fail("Greater powers prevent your malice.\n");
   if (!living(ob))
      return notify_fail("Syntax: <flip [living]>\n");
   if (tp->query_disable())
      return notify_fail("You are busy.\n");
   if (ob == tp)
      return notify_fail("You do a little dance.\n");
   if (tp->query_sp() < 5) 
      return notify_fail("You are too tired.\n");
    if(tp->query_rest_type())
       return notify_fail("You cannot do that while on the ground!\n");
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 0;
    }
    if(this_player()->ghost())
        return notify_fail("You appear to be dead.\n");

    if (this_player()->query_level() < 30)
    {
        dmg = BALANCE_D->get_damage( tp, ob, 2, ({ "attack","entertainment","entertainment"}),
            ({ "strength", "dexterity", "dexterity" }) );
        cost = (this_player()->query_skill("entertainment")/5 + 
            random(this_player()->query_skill("entertainment")/10));       
    }
    else
    {
        dmg = BALANCE_D->get_damage( tp, ob, 3, ({ "attack", "entertainment", "entertainment"}),
                ({ "strength", "dexterity", "dexterity" }), ({ "strength", "dexterity" })  );
        cost = (this_player()->query_skill("entertainment")/5 + 
                random(this_player()->query_skill("entertainment")/10));     
    }
    if (dmg < 10) {
        write("You miss!");
        return 1;
    }
        
    write("You flip backwards kicking "+ob->query_cap_name()+ " square in the face!"); 
    
    tell_object(ob, tp->query_cap_name()+" flips head over heels kicking you in the face!");
    
    message("combat", tp->query_cap_name()+" flips head over heels kicking "+ob->query_cap_name()+
        ", square in the face!", env, ({ tp, ob }));   
    
    if(random(100) > 50 && tp->query_stats("dexterity") > ob->query_stats("constitution") && !!ob->query_rest_type())
    {
        message("knockout", ob->query_cap_name()+ "'s eyes roll back and they fall to the ground!", env, ob);
        tell_object(ob, "You feel light in the head and fall back on to the ground!");
        ob->set_rest_type(LAY);
        ob->set_paralyzed(random(3),"You are dazed from the hit!");
    }  
    tp->add_sp(-(cost));
    //1.3 mod it to make up for the fighter extra hp bonus
    ob->damage(dmg);

    tp->set_disable();
    return 1;
    
}
void help() {
write("Syntax: <flip [victim]> \n"+
        "A mid level Jester ability.\nThe Jester flips head over heels, kicking their opponent hard.");
}
int abil() {
    object o;
    o = this_player();
    if (o->query_subclass() != "jester") return 0;
    if (o->query_skill("entertainment") < 90) return 0;
    return 1;
}

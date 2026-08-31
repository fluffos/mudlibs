#include <std.h>
#include <daemons.h>
#include <rest.h>

inherit DAEMON;
int abil();
string type() { return "attack"; }
int cmd_slam(string str) {
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
      return notify_fail("Syntax: <slam [living]>\n");
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

    if(!b=sizeof(wield=(object *)this_player()->query_wielded())) {
        return notify_fail("You need a weapon to slam with!\n");
    } 
    
    i = sizeof(wield);
    clear = 0;
    wep = wield[0];
    while (i--) 
    {
        if (wield[i]->query_type() == "blunt") {
            if(wield[i]->query_wc() > wep->query_wc())
                wep = wield[i];            
            clear = 1;
        }
    }
    
    if (!clear) return notify_fail("You need a blunt to slam with!\n");
    
    wc = wep->query_wc();
    if(wep->query("jester"))
    {
        mod = 1.1;
    }

    if (this_player()->query_level() < 15)
    {
        dmg = BALANCE_D->get_damage( tp, ob, 1, ({ "attack", "blunt", "blunt", "entertainment"}),
            ({ "strength", "dexterity", "dexterity" }) )  + wc*5/3;
        cost = (this_player()->query_skill("blunt")/5 + 
            random(this_player()->query_skill("blunt")/10));       
    }
    else
    {
        dmg = BALANCE_D->get_damage( tp, ob, 2, ({ "attack", "blunt", "blunt", "entertainment"}),
            ({ "strength", "dexterity", "dexterity" }))  + wc*5/3;
        cost = (this_player()->query_skill("blunt")/5 + 
            random(this_player()->query_skill("blunt")/10));     
    }
    if (dmg < 10) {
        write("You miss!");
        return 1;
    }
        
    write("You jump backward onto your hands, push yourself back, land on your feet and jump at " 
        +ob->query_cap_name()+ ", striking them with your "+ wep->query_name()+"!");
    
    tell_object(ob, tp->query_cap_name()+" jumps onto "+ob->query_possessive()+" hands, then pushes off and lands on "
        +ob->query_possessive()+ " feet, then jumps at you, hitting you with their weapon!");
    
    message("combat", tp->query_cap_name()+" jumps onto their hands, pushes off onto their feet, and jumps at "+ob->query_cap_name()+
        ", striking them badly!", env, ({ tp, ob }));   
        
    tp->add_sp(-(cost));
    //1.3 mod it to make up for the fighter extra hp bonus
    ob->damage(dmg*mod);

    tp->set_disable();
    return 1;
    
}
void help() {
write("Syntax: <slam [victim]> \n"+
        "A low level jester ability.\nThe jester performs a simple stunt and strikes their enemy with a blunt weapon.");
}
int abil() {
    object o;
    o = this_player();
    if (o->query_subclass() != "jester") return 0;
    return 1;
}

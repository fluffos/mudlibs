#include <daemons.h>
inherit DAEMON;
int abil();
int cmd_thrust(string str)
{
    int dmg, i, type, randomchance;
    object ob, tp, env;
    object *wield, *projectiles;
    tp = this_player();
    env = environment(tp);
    projectiles = ({});
    if(!abil()) return 0;

    if ((!str || str=="") && !this_player()->query_current_attacker())
    {
        write("Thrust your spear at what?");
        return 1;
    }
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
            write("The projectile is too long to manage that.");
            return 1;
        }
    }

    if (tp->query_subclass() != "scout")
    {
        return notify_fail("Only Scouts may do this.\n");
    }
    wield=this_player()->query_wielded();
    if(!sizeof(wield)) {
        return notify_fail("You need a projectile to thrust with.\n");
    }
    for(i=0;i<sizeof(wield);i++) {
        if(wield[i]->query_type() == "projectile")
        {
            projectiles += ({ wield[i] });
        }
    }
    if (sizeof(projectiles) == 0)
    {
        return notify_fail("You need a projectile to thrust with.\n");
    }
    if (env->query_property("no attack") || env->query_property("no attack"))
        return notify_fail("You may not attack in this place of peace.\n");
    if (!living(ob))
        return notify_fail("Syntax: <thrust [living]>\n");
    if (tp->query_disable())
        return notify_fail("You are busy.\n");
    if (tp->query_sp() < 50) 
        return notify_fail("You are too tired.\n");
    if(tp->query_ghost())
        return notify_fail("You are dead.\n");
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" is too small right now. Leave the newbies alone!");
        return 1;
    }
    if(this_player()->query_level() < 15) {
        type = 1;
    }
    else if(this_player()->query_level() < 25) {
        type = 2;
    }
    else if(this_player()->query_level() < 35) {
        type = 3;
        randomchance=700;
    }
    else 
    {
        type = 4;
        randomchance=500;
    }

    tp->set_disable(2);
    if (type == 1)
    {
        write("You weakly thrust your "+projectiles[0]->query_name()+" towards "+ob->query_cap_name()+".");
        tell_object(ob, tp->query_cap_name()+" weakly thrusts "+this_player()->query_possessive()+" "+projectiles[0]->query_name()+" towards you.");
        tell_room(env, tp->query_cap_name()+" weakly thrusts "+this_player()->query_possessive()+" "+projectiles[0]->query_name()+" towards "+ob->query_cap_name()+".", this_player());
    }
    else if (type == 2)
    {
        write("You awkwardly thrust your "+projectiles[0]->query_name()+" towards "+ob->query_cap_name()+".");
        tell_object(ob, tp->query_cap_name()+" awkwardly thrusts "+this_player()->query_possessive()+" "+projectiles[0]->query_name()+" towards you.");
        tell_room(env, tp->query_cap_name()+" awkwardly thrusts "+this_player()->query_possessive()+" "+projectiles[0]->query_name()+" towards "+ob->query_cap_name()+".", this_player());
    }
    else if (type == 3)
    {
        write("You skillfully thrust your "+projectiles[0]->query_name()+" towards "+ob->query_cap_name()+"!");
        tell_object(ob, tp->query_cap_name()+" skillfully thrusts "+this_player()->query_possessive()+" "+projectiles[0]->query_name()+" towards you!");
        tell_room(env, tp->query_cap_name()+" skillfully thrusts "+this_player()->query_possessive()+" "+projectiles[0]->query_name()+" towards "+ob->query_cap_name()+"!", this_player());
    }
    else if (type == 4)
    {
        write("You masterfully thrust your "+projectiles[0]->query_name()+" towards "+ob->query_cap_name()+"!");
        tell_object(ob, tp->query_cap_name()+" masterfully thrusts "+this_player()->query_possessive()+" "+projectiles[0]->query_name()+" towards you!");
        tell_room(env, tp->query_cap_name()+" masterfully thrusts "+this_player()->query_possessive()+" "+projectiles[0]->query_name()+" towards "+ob->query_cap_name()+"!", this_player());
    }
    dmg = BALANCE_D->get_damage( tp, ob, type, ({ "attack","projectile","attack","attack", }), ({ "strength", "dexterity" }));
    dmg = (dmg + dmg*2/3) * projectiles[0]->query_hands();
    if (dmg < 10) {
        write("You miss!");
        return 1;
    }
    tp->add_sp(-dmg/7);
    ob->damage(dmg);
    tp->set_paralyzed(1, "You are still in mid-thrust!", "You finish thrusting your "+projectiles[0]->query_name()+" towards "+ob->query_cap_name()+".");
    tp->set_disable(2);

    if (type > 2 && random(randomchance) < 7)
    {
        write("%^BOLD%^%^GREEN%^Your powerful thrust slams "+ob->query_cap_name()+" onto "+ob->query_possessive()+" back!%^RESET%^");
        tell_object(ob, "%^BOLD%^%^GREEN%^"+tp->query_cap_name()+"'s thrust slams you onto your back, stunning you!%^RESET%^");
        tell_room(env, "%^BOLD%^%^GREEN%^"+tp->query_cap_name()+"'s thrust slams "+ob->query_cap_name()+" onto "+ob->query_possessive()+" back!%^RESET%^", this_player());
        ob->set_paralyzed(random(3)+1);
    }

    return 1;
}

void help() {
    write("Syntax: <thrust [victim]> \n \n Although scouts do not receive much training with spear weapons, the spear often forms a central part of the average scout's armory do their versitility and initial ease of use. However, correct spearfighting technique takes some time to learn, but some would argue that it becomes one of the best fighting techniques when one has learnt to control the weapon properly. To thrust with a spear is generally slower then swinging with a sword, although it does do more damage. Humans, the creatures which invented the spear, often receive training from birth with this weapon and thus generally display a higher degree of skill with it.");
}

int abil() {
    object o;
    o = this_player();
    if (!o) return 0;
    if (o->query_subclass() != "scout") return 0;
    if (o->query_level() < 5) return 0;
    if (o->query_skill("attack") < 20) return 0;
    return 1;
}

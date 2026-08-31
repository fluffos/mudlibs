#include <daemons.h>
#include <rest.h>
#include <damage_types.h>
#include <damage.h>
inherit DAEMON;
int abil();
string type() { return "attack"; }
int cmd_entangle(string str)
{
    int a,b, i, clear, fl;
    string gen;
    object ob, tp;
    object *wield;
    if (!abil()) {
        return 0;
    }
    tp = this_player();
    if ((!str || str=="") && !tp->query_current_attacker())
    {
        write("Syntax: <entangle [living]>");
        return 1;
    }
    if (this_player()->query_current_attacker())
        return notify_fail("You cannot find an opening to entangle "+str+".\n");

    if (environment(tp)->query_property("no attack"))
    {
        write("Greater powers prevent your malice.");
        return 1;
    }
    if(this_player()->query_ghost()) return notify_fail("You howl pitifully.\n");
    if(!b=sizeof(wield=(object *)tp->query_wielded())) {
        notify_fail("You must be wielding a weapon to do this.\n");
        return 0;
    } 
    i = sizeof(wield);
    clear = 0;
    while (i--) {
        if (wield[i]->query_type() == "flail") {
            clear = 1; fl = i; }
    }
    if (!clear) return notify_fail("You must be wielding a flail type "
          "weapon to entangle your opponent.\n");

    if (tp->query_current_attacker() && str == "") 
        ob = tp->query_current_attacker();
    else {
        ob = present(str, environment(tp));
        if (!ob)
        {
            write("You dont see that here.");
            return 1;
        }
        if (ob==tp)
        {
            write("Attack yourself?");
            return 1;
        }
    }
    if (tp->query_sp() < 50) 
    {
        write("You are too tired.");
        return 1;
    }
    if(!living(ob)) return notify_fail("You wrap it up.\n");
    if(tp->query_disable()) return notify_fail(
          "You're too busy to be entangling people!\n");
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
    tp->set_disable();
    if (ob->query_gender()=="male") gen = "him"; else gen = "her";
    a = tp->query_stats("dexterity");
    a -= (ob->query_stats("dexterity") / 2);
    if (a < 5)
    {
        write("You fail miserably and your "+wield[fl]->query_name()+" gets caught around "
          +ob->query_cap_name()+"'s foot!");
        message("info", tp->query_cap_name()+" fails miserably and "+tp->query_possessive()+" "
          +wield[fl]->query_name()+" gets caught around your foot!", ob);
        message("info", tp->query_cap_name()+" fails miserably and "+tp->query_possessive()+" "
          +wield[fl]->query_name()+" gets caught around "+ob->query_cap_name()+"'s foot!"
          ,environment(ob), ({ tp, ob }));
        tp->force_me("drop "+wield[fl]->query_name());
        return 1;
    }
    else if (a < 15)
    {
        write("You miss your opponent.");
        say( this_player()->query_cap_name()+" misses "+this_player()->query_possessive()+" entangle attempt.");
        return 1;
    }
    a = BALANCE_D->get_damage( tp, ob, 1, ({ "flail" }),
                                   ({ "dexterity" }) );
    write("You entangle "+ob->query_cap_name()+" with your "+wield[fl]->query_name()+" causing "
      +gen+" to fall to the ground!");
    message("info", tp->query_cap_name()+" entangles you with "+tp->query_possessive()+" "
      +wield[fl]->query_name()+" causing you to fall to the ground!", ob);
    message("info", tp->query_cap_name()+" entangles "+ob->query_cap_name()+" with "
      +tp->query_possessive()+" "+wield[fl]->query_name()+" causing "+ob->query_cap_name()+
      " to fall to the ground!",environment(ob), ({ tp, ob }));
    ob->set_rest_type( SIT );
    ob->set_paralyzed(random(2)+1, "You can't concentrate on that.");
    ob->do_damage(ob->return_target_limb(), a, DAMAGE_PHYSICAL | DAMAGE_IMPACT, DAMAGE_NO_SEVER, tp);
    tp->add_sp(-(BALANCE3_D->get_cost(a, 1, "sp")));
    tp->add_skill_points("flail", (a/20));
    return 1;
}
int abil() {
    object o;
    o = this_player();
    if (!o) return 0;
    if (o->query_subclass() != "warrior") return 0;
    if (o->query_skill("flail") >= 10)
        return 1;
}
void help() {
    write("
Syntax: <entangle [living]>
By use of this ability, one uses a flail type weapon to
entangle a living opponent causing them to fall to the ground.
");
}

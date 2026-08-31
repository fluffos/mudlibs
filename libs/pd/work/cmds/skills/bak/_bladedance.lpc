// stormy
#include <std.h>
#include <daemons.h>
inherit DAEMON;
int abil();
string type() { return "attack"; }
int cmd_bladedance(string str) {
    int dmg, hits, i, clear, b;
    object ob, tp, env;
    object *wield;
    tp = this_player();
    env = environment(tp);
    if(!abil())
	return 0;
    if (!str) ob = tp->query_current_attacker();
    else ob = present(str, env);
    if (!ob) {
	if (str)
	    notify_fail("You do not see "+str+" here.\n");
	return 0;
    }
    if (env->query_property("no attack") || env->query_property("no magic"))
	return notify_fail("Greater powers prevent your malice.\n");
    if (!living(ob))
	return notify_fail("Your target is dead.");
    if (tp->query_disable())
	return notify_fail("You are busy.\n");
    if(!b=sizeof(wield=(object *)this_player()->query_wielded())) {
	notify_fail("You need a weapon to bladedance with!\n");
	return 0;
    } 
    i = sizeof(wield);
    clear = 0;
    while (i--) {
	if (wield[i]->query_type() == "blade")
	    clear = 1;
    }
    if (!clear) return notify_fail("You need a blade to dance with!\n");
    if (ob == tp)
	return notify_fail("That is not wise.\n");
    if (tp->query_sp() < 20) 
	return notify_fail("You are too tired.\n");
    if(!this_player()->kill_ob(ob)) {
	write(ob->query_cap_name()+" can't be attacked by you yet.");
	return 1;
    }
    write("%^BOLD%^%^WHITE%^You begin to dance around moving your blades in an intricate pattern!%^RESET%^");
    message("info", "%^BOLD%^%^WHITE%^"+tp->query_cap_name()+" begins to dance around moving "+tp->query_title_gender()+" blades in an intricate pattern!%^RESET%^", environment(tp), ({ tp }));
    tp->set_disable();
    dmg = BALANCE_D->get_damage( tp, ob, 2, ({ "blade", "attack" }), ({ "dexterity" }) );
    dmg = dmg * 2 / 3;
    if (dmg < 10) {
	write("You miss!");
	return 1;
    }
    write("%^BOLD%^%^WHITE%^You cut "+ob->query_cap_name()+" with your blade!%^RESET%^"); 
    tell_object(ob, "%^BOLD%^%^WHITE%^"+tp->query_cap_name()+" cuts you with a blade!%^RESET%^");
    tell_room(env, "%^BOLD%^%^WHITE%^"+tp->query_cap_name()+" cuts "+ob->query_cap_name()+" with a blade!%^RESET%^", ({ob, tp}));
    tp->add_sp(- (10 + random(dmg/13)));
    ob->damage(dmg);   

    if (((tp->query_level()) > 12 && random(18) < 8) || (tp->query_level() > 32)) { // Modification by Venenum
	// Added so that if the 
	// user's level is higher 
	// than 35 auto hits.

	hits = BALANCE_D->get_damage( tp, ob, 2, ({ "blade", "attack" }), ({ "dexterity", "strength" }) );
	hits = hits / 3;
	write("%^BOLD%^%^WHITE%^You sneak in another cut!%^RESET%^");
	tell_object(ob, "%^BOLD%^%^WHITE%^"+tp->query_cap_name()+" cuts you again!%^RESET%^");
	tell_room(env, "%^BOLD%^%^WHITE%^"+tp->query_cap_name()+" cuts "+ob->query_cap_name()+" again!%^RESET%^",({ob,tp}));
	tp->add_sp(-(7 + random(hits/14)));
	ob->damage(hits);
    }

    if (((tp->query_level()) > 20 && random(18) < 8) || (tp->query_level() > 45)) { // Modification by Venenum
	// Added so that if the 
	// user's level is higher 
	// than 45 it auto hits.

	hits = BALANCE_D->get_damage( tp, ob, 2, ({ "blade", "attack" }), ({ "dexterity", "strength" }) );
	hits = hits / 3;
	write("%^BOLD%^%^WHITE%^You sneak in another cut!%^RESET%^");
	tell_object(ob, "%^BOLD%^%^WHITE%^"+tp->query_cap_name()+" cuts you again!%^RESET%^");
	tell_room(env, "%^BOLD%^%^WHITE%^"+tp->query_cap_name()+" cuts "+ob->query_cap_name()+" again!%^RESET%^",
	  ({ob,tp}));
	tp->add_sp(-(6 + random(hits/14)));
	ob->damage(hits);
    }

    if (((tp->query_level()) > 28 && random(18) < 8) || (tp->query_level() > 58)) { // Modification by Venenum
	// Added so that if the 
	// user's level is higher 
	// than 58 it auto hits.
        hits = BALANCE_D->get_damage( tp, ob, 3, ({ "blade", "attack" }),({ "dexterity", "strength" }), ({ "strength", "dexterity" }) );
	hits = hits / 3;
	write("%^BOLD%^%^WHITE%^You sneak in another cut!%^RESET%^");
	tell_object(ob, "%^BOLD%^%^WHITE%^"+tp->query_cap_name()+" cuts you again!%^RESET%^");
	tell_room(env, "%^BOLD%^%^WHITE%^"+tp->query_cap_name()+" cuts "+ob->query_cap_name()+" again!%^RESET%^", ({ob,tp}));
	tp->add_sp(-(5 + random(hits/15)));
	ob->damage(hits);
    }

    if (((tp->query_level()) > 36 && random(18) < 8) || (tp->query_level() > 66)) { // Modification by Venenum
	// Added so that if the 
	// user's level is higher 
	// than 58 it auto hits.
        hits = BALANCE_D->get_damage( tp, ob, 3, ({ "blade", "attack" }),({ "dexterity", "strength" }), ({ "dexterity", "strength" }) );
	hits = hits / 3;
	write("%^BOLD%^%^WHITE%^You sneak in another cut!%^RESET%^");
	tell_object(ob, "%^BOLD%^%^WHITE%^"+tp->query_cap_name()+" cuts you again!%^RESET%^");
	tell_room(env, "%^BOLD%^%^WHITE%^"+tp->query_cap_name()+" cuts "+ob->query_cap_name()+" again!%^RESET%^", ({ob,tp}));
	tp->add_sp(-(4 + random(hits/17)));
	ob->damage(hits);
    }
    if (((tp->query_level()) > 44 && random(18) < 8) || (tp->query_level() > 74)) { // Modification by Venenum
	// Added so that if the 
	// user's level is higher 
	// than 58 it auto hits.
        hits = BALANCE_D->get_damage( tp, ob, 4, ({ "blade", "attack" }),({ "dexterity", "strength" }), ({ "strength", "dexterity" }) );
	hits = hits / 3;
	write("%^BOLD%^%^WHITE%^You cut your opponent on the cheek!%^RESET%^");
	tell_object(ob, "%^BOLD%^%^WHITE%^"+tp->query_cap_name()+" cuts you on the cheek!%^RESET%^");
	tell_room(env, "%^BOLD%^%^WHITE%^"+tp->query_cap_name()+" cuts "+ob->query_cap_name()+" on the cheek!%^RESET%^",({ob,tp}));
	tp->add_sp(-(3 + random(hits/19)));
	ob->damage(hits);
    }
    return 1;
}
void help() {
    write("
Syntax: <bladedance [victim]>
Swashbucklers dance around in an intricate show of swordsmanship. The higher the swashbuckler's level, the more intricate the dance. Although many traditional swordsmen scoff at the artistic style of the Swashbuckler, they do so out of ignorance. The grace and beauty of a skilled Bladedance is only matched by it's lethality.
");
}

int abil() {
   object o;
   o = this_player();
   if (o && o->query_level() >= 5)
   if (o->query_subclass() == "swashbuckler")
     return 1;
}

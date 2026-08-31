#include <std.h>
#include <daemons.h>
inherit DAEMON;
int spell();
string type() { return "attack"; }
int cmd_levin(string str) {
    int dmg;
    object ob, tp, env;
    mixed *passed;
    tp = this_player();
    env = environment(tp);
    if(!spell()) return 0;
    if (!str) ob = tp->query_current_attacker();
    else ob = present(str, env);
    if(!ob) 
	if(!str) return notify_fail("Levin what?\n"); else
	    return notify_fail("You do not see "+str+" here.\n");
    if (tp->query_race() != "archangel")
	return notify_fail("What?\n");
    if (this_player()->query_alignment() < 750){
	notify_fail("You have betrayed your alignment.");
	return 0;
    }
    if(tp->query_ghost())
	return notify_fail("You are dead.\n");
    if (env->query_property("no attack") || env->query_property("no magic"))
	return notify_fail("Greater powers prevent your malice.\n");
    if (!living(ob))
	return notify_fail("You would invoke the fury of the heavens on that? "
	  "How about you get your priorities straight, first?\n");
    if (ob == tp)
	return notify_fail("How are you supposed to defend the heavens if you "
	  "keep trying to kill yourself?!?\n");
    if (tp->query_disable() || tp->query_magic_round())
	return notify_fail("You are busy doing something else.\n");
    if (tp->query_mp() < 230) 
	return notify_fail("Your magic is not strong enough to cast this.\n");
    if (this_player()->query_subclass() == "cleric"){
	dmg = BALANCE_D->get_damage( tp, ob, 3, ({ "belief" }),
	  ({ "wisdom" }), ({ "intelligence", "wisdom"}) );
    }
    else{
	dmg = BALANCE_D->get_damage( tp, ob, 3, ({ "attack" }),
	  ({ "wisdom" }), ({ "intelligence", "wisdom"}) );
    }
    dmg = dmg + dmg/2;
    if (dmg < 10) {
	write("%^BOLD%^%^WHITE%^Y%^YELLOW%^o%^WHITE%^u%^YELLOW%^r "
	  "%^WHITE%^b%^YELLOW%^o%^WHITE%^l%^YELLOW%^t %^WHITE%^o%^YELLOW%^f "
	  "%^WHITE%^h%^YELLOW%^o%^WHITE%^l%^YELLOW%^y "
	  "%^WHITE%^l%^YELLOW%^e%^WHITE%^v%^YELLOW%^i%^WHITE%^n "
	  "%^YELLOW%^d%^WHITE%^e%^YELLOW%^f%^WHITE%^l%^YELLOW%^e%^WHITE%^c%^YELLOW%^t%^WHITE%^s "
	  "%^YELLOW%^o%^WHITE%^f%^YELLOW%^f %^WHITE%^o%^YELLOW%^f %^WHITE%^"
	  +ob->query_cap_name()+"'s "
	  "%^YELLOW%^b%^WHITE%^o%^YELLOW%^d%^WHITE%^y, "
	  "%^YELLOW%^d%^WHITE%^o%^YELLOW%^i%^WHITE%^n%^YELLOW%^g "
	  "%^WHITE%^n%^YELLOW%^o "
	  "%^WHITE%^h%^YELLOW%^a%^WHITE%^r%^YELLOW%^m %^WHITE%^a%^YELLOW%^t "
	  "%^WHITE%^a%^YELLOW%^l%^WHITE%^l%^YELLOW%^!");
	tell_room(env, "%^BOLD%^%^WHITE%^Y%^YELLOW%^o%^WHITE%^u%^YELLOW%^r "
	  "%^WHITE%^b%^YELLOW%^o%^WHITE%^l%^YELLOW%^t %^WHITE%^o%^YELLOW%^f "
	  "%^WHITE%^h%^YELLOW%^o%^WHITE%^l%^YELLOW%^y "
	  "%^WHITE%^l%^YELLOW%^e%^WHITE%^v%^YELLOW%^i%^WHITE%^n " 
	  "%^YELLOW%^d%^WHITE%^e%^YELLOW%^f%^WHITE%^l%^YELLOW%^e%^WHITE%^c%^YELLOW%^t%^WHITE%^s "
	  "%^YELLOW%^o%^WHITE%^f%^YELLOW%^f %^WHITE%^o%^YELLOW%^f %^WHITE%^"
	  +ob->query_cap_name()+"'s "
	  "%^YELLOW%^b%^WHITE%^o%^YELLOW%^d%^WHITE%^y, "
	  "%^YELLOW%^d%^WHITE%^o%^YELLOW%^i%^WHITE%^n%^YELLOW%^g "
	  "%^WHITE%^n%^YELLOW%^o "
	  "%^WHITE%^h%^YELLOW%^a%^WHITE%^r%^YELLOW%^m %^WHITE%^a%^YELLOW%^t "
	  "%^WHITE%^a%^YELLOW%^l%^WHITE%^l%^YELLOW%^!", ({ ob, tp }));
	tell_object(ob, "%^BOLD%^%^WHITE%^Y%^YELLOW%^o%^WHITE%^u%^YELLOW%^r "
	  "%^WHITE%^b%^YELLOW%^o%^WHITE%^l%^YELLOW%^t %^WHITE%^o%^YELLOW%^f "
	  "%^WHITE%^h%^YELLOW%^o%^WHITE%^l%^YELLOW%^y "
	  "%^WHITE%^l%^YELLOW%^e%^WHITE%^v%^YELLOW%^i%^WHITE%^n " 
	  "%^YELLOW%^d%^WHITE%^e%^YELLOW%^f%^WHITE%^l%^YELLOW%^e%^WHITE%^c%^YELLOW%^t%^WHITE%^s "
	  "%^YELLOW%^o%^WHITE%^f%^YELLOW%^f %^WHITE%^o%^YELLOW%^f %^WHITE%^"
	  "your "
	  "%^YELLOW%^b%^WHITE%^o%^YELLOW%^d%^WHITE%^y, "
	  "%^YELLOW%^d%^WHITE%^o%^YELLOW%^i%^WHITE%^n%^YELLOW%^g "
	  "%^WHITE%^n%^YELLOW%^o "
	  "%^WHITE%^h%^YELLOW%^a%^WHITE%^r%^YELLOW%^m %^WHITE%^a%^YELLOW%^t "
	  "%^WHITE%^a%^YELLOW%^l%^WHITE%^l%^YELLOW%^!");
    }
    write("%^BOLD%^%^WHITE%^Y%^YELLOW%^o%^WHITE%^u "
      "%^YELLOW%^c%^WHITE%^o%^YELLOW%^n%^WHITE%^c%^YELLOW%^e%^WHITE%^n%^YELLOW%^t%^WHITE%^r%^YELLOW%^a%^WHITE%^t%^YELLOW%^e "
      "%^WHITE%^%^YELLOW%^a%^WHITE%^l%^YELLOW%^l %^WHITE%^o%^YELLOW%^f "
      "%^WHITE%^y%^YELLOW%^o%^WHITE%^u%^YELLOW%^r "
      "%^WHITE%^e%^YELLOW%^n%^WHITE%^e%^YELLOW%^r%^WHITE%^g%^YELLOW%^y "
      "%^WHITE%^o%^YELLOW%^n "
      "%^WHITE%^g%^YELLOW%^a%^WHITE%^t%^YELLOW%^h%^WHITE%^e%^YELLOW%^r%^WHITE%^i%^YELLOW%^n%^WHITE%^g "
      "%^YELLOW%^p%^WHITE%^o%^YELLOW%^w%^WHITE%^e%^YELLOW%^r "
      "%^WHITE%^w%^YELLOW%^i%^WHITE%^t%^YELLOW%^h%^WHITE%^i%^YELLOW%^n%^WHITE%^.");
    tp->set_paralyzed(2, "You are held still by the gathering power.");
    tp->set_disable(2);
    passed = ({tp, ob, dmg});
    call_out("finish_levin", 2, passed);
    return 1;
}
void finish_levin(mixed *stuff) {
    object env, tp, ob;
    int dmg;
    tp = stuff[0];
    ob = stuff[1];
    dmg = stuff[2];
    env = environment(tp);
    if(!ob) {
	message("info", "The infidel has been vanquished!", tp);
	return;
    }
    if (environment(tp) != environment(ob)) {
	message("info", "The infidel has evaded you!", tp);
	return;
    }
    if(!this_player()->kill_ob(ob)) {
	write(ob->query_cap_name()+" can't be attacked by you yet.");
	return;
    }
    message("attack", "%^BOLD%^%^WHITE%^Y%^YELLOW%^o%^WHITE%^u "
      "%^YELLOW%^c%^WHITE%^a%^YELLOW%^s%^WHITE%^t %^YELLOW%^a "
      "%^WHITE%^d%^YELLOW%^a%^WHITE%^z%^YELLOW%^z%^WHITE%^l%^YELLOW%^i%^WHITE%^n%^YELLOW%^g "
      "%^WHITE%^b%^YELLOW%^o%^WHITE%^l%^YELLOW%^t %^WHITE%^o%^YELLOW%^f "
      "%^WHITE%^h%^YELLOW%^o%^WHITE%^l%^YELLOW%^y "
      "%^WHITE%^l%^YELLOW%^e%^WHITE%^v%^YELLOW%^i%^WHITE%^n %^YELLOW%^a%^WHITE%^t "
      "%^YELLOW%^"+ob->query_cap_name()+"%^WHITE%^!", tp);
    tell_object(ob, "%^BOLD%^%^WHITE%^"+tp->query_cap_name()+" "+
      "%^YELLOW%^c%^WHITE%^a%^YELLOW%^s%^WHITE%^t%^YELLOW%^s a "
      "%^WHITE%^d%^YELLOW%^a%^WHITE%^z%^YELLOW%^z%^WHITE%^l%^YELLOW%^i%^WHITE%^n%^YELLOW%^g "
      "%^WHITE%^b%^YELLOW%^o%^WHITE%^l%^YELLOW%^t %^WHITE%^o%^YELLOW%^f "
      "%^WHITE%^h%^YELLOW%^o%^WHITE%^l%^YELLOW%^y "
      "%^WHITE%^l%^YELLOW%^e%^WHITE%^v%^YELLOW%^i%^WHITE%^n %^YELLOW%^a%^WHITE%^t "
      "%^YELLOW%^y%^WHITE%^o%^YELLOW%^u%^WHITE%^!");
    tell_room(env, "%^BOLD%^%^WHITE%^"+tp->query_cap_name()+" "+
      "%^YELLOW%^c%^WHITE%^a%^YELLOW%^s%^WHITE%^t%^YELLOW%^s a "
      "%^WHITE%^d%^YELLOW%^a%^WHITE%^z%^YELLOW%^z%^WHITE%^l%^YELLOW%^i%^WHITE%^n%^YELLOW%^g "
      "%^WHITE%^b%^YELLOW%^o%^WHITE%^l%^YELLOW%^t %^WHITE%^o%^YELLOW%^f "
      "%^WHITE%^h%^YELLOW%^o%^WHITE%^l%^YELLOW%^y "
      "%^WHITE%^l%^YELLOW%^e%^WHITE%^v%^YELLOW%^i%^WHITE%^n %^YELLOW%^a%^WHITE%^t "
      "%^YELLOW%^"+ob->query_cap_name()+"%^WHITE%^!", ({ ob, tp }));
    tp->add_mp(-dmg/7);
    tp->set_casting(dmg + random(this_player()->query_level()/2));
    return;
}
void help() {
    write(@ANNARI
Syntax: <levin [target]>  or  <levin>
Archangels who have proven their strength by maintaining elite status are able
to summon a dazzling bolt of heavenly lightning to strike their opponent,
(target), or their current attacker if an argument is not used. The own
Archangel's physical health is important to the casting of this attack.
ANNARI);
}
int spell() {
    object o;
    o = this_player();
    if (o && o->query_level() >= 25)
	if (o->query_race() == "archangel") 
	    return 1;
}


// object for the fire dance
// Kaknal 4-16-02
#include <std.h>
inherit OBJECT;
int dancerounds;
int check_fire(string str);
int can_dance(object tp);
void start_dance();
void end_dance();
int no_drop(string str);
void init() {
    ::init();
    add_action("no_drop","give");
    add_action("no_drop","drop");
    add_action("no_drop","put");
}
void create() {
    ::create();
    set_name("fire dance");
    set_short("");
    set_long("");
    set_id(({"gypsy_dance_obj"}));
    set_weight(0);
    set_value(0);
}
int can_dance(object tp) {
    if (tp->query_level() < 10 ||
      tp->query_skill("entertainment") < 38)
	return 0;
    return 1;
}
void start_dance() {
    object tp;
    object *inv;
    int i, fires;
    if (!userp(environment()))
	remove();
    tp=environment();
    inv=all_inventory(tp);
    for (i=0, fires=0; i<sizeof(inv); i++) {
	if (inv[i]->query_lit()) fires++;
    }
    if (!fires) {
	message("info","You cannot perform the fire dance without fire!",tp);
	remove();
	return 0;
    }
    if (!tp->query_current_attacker()) {
	message("info","You are not fighting anything.",tp);
	remove();
	return 0;
    }
    if (environment(tp)->query_property("no attack")) {
	message("info","You cannot perform this dance here.",tp);
	remove();
	return 0;
    }
    dancerounds= tp->query_stats("dexterity")/5;
    dancerounds+= tp->query_stats("constitution")/15;
    dancerounds+= tp->query_skill("entertainment")/25;
    if (dancerounds < 3) dancerounds=3;
    if (dancerounds > 8) dancerounds=9+random(dancerounds-5);
    if (dancerounds > 12) dancerounds=12+random(dancerounds*2/3);
    tp->add_sp(-(10+random(10)));
    tp->set_disable();
    message("dance","You twirl a flame around you as you dance.",tp);
    message("dance",tp->query_cap_name()+" twirls a flame about "+
      possessive(tp)+" body as "+nominative(tp)+" dances.",
      environment(tp), tp);
    call_out("heart_beat",2);
}
void heart_beat() {
    object tp;
    object tgt;
    string part;
    int dam, noatt;
    if (!userp(environment()))
	this_object()->remove();
    tp=environment();
    if (dancerounds < 1) {
	end_dance();
	return;
    }
    if (tp->query_sp() < 30) {
	end_dance();
	return;
    }
    if (!tp->query_current_attacker())
	noatt++;

    if (noatt >= 6+random(2)) {
	end_dance();
	return;
    }
    if (dancerounds % (2+random(3)) &&
      tp->query_current_attacker()) {
	tgt=tp->query_current_attacker();
	message("combat", "%^BOLD%^RED%^You spin the flame quickly around "
	  "your body and burn "+tgt->query_cap_name()+"!", tp);
	message("combat", "%^BOLD%^%^RED%^"+tp->query_cap_name()+
	  " spins "+possessive(tp)+" flame around and burns you!%^RESET%^", tgt, tp);
	message("combat", "%^BOLD%^%^RED%^"+tp->query_cap_name()+
	  " spins "+possessive(tp)+" flame and burns "+tgt->query_cap_name()+
	  "!%^RESET%^", environment(tp), ({tp, tgt}) );
	dam= tp->query_stats("dexterity");
	dam+= tp->query_skill("entertainment")/5;
	dam+= tp->query_skill("attack")/6;
	dam+= random(tp->query_skill("entertainment")/4);
	dam-= tgt->query_skill("defense")/2;
	dam-= tgt->query_stats("constitution")/4;
	tp->add_sp(-(random(7)+3));
	tgt->add_hp(-dam);
    }
    else if (!random(3)) {
	part=({"torso","arm","leg"})[random(3)];
	message("combat","%^RED%^You twist your body, spinning the flame "
	  "deftly around your "+part+".%^RESET%^",tp);
	message("other_combat","%^RED%^"+tp->query_cap_name()+
	  "twists around, spinning a flame around "+possessive(tp)+" "+part+
	  ".%^RESET%^",environment(tp),tp);
	tp->add_sp(-(random(2)+1));
    }
    dancerounds--;
    if (dancerounds % 2)
	call_out("heart_beat",2);
    else
	call_out("heart_beat",3);
}
void end_dance() {
    object tp=environment();
    message("combat","You slowly bring your dance to an end.",tp);
    message("other_combat",tp->query_cap_name()+" ends "+possessive(tp)+
      " dance.", environment(tp), tp);
    remove();
}
int no_drop(string str) {
    string blah, junk;
    object tp=environment();
    object fire;
    if (!str) return 0;
    if (sscanf(str,"%s to %s",blah,junk) != 2)   // give thing to person
	if (sscanf(str,"%s in %s",blah,junk) != 2) // put thing in bag
	    blah=str;                                // drop thing
    if ((fire=present(blah,tp)) == this_object()) return 1;
    if (fire->query_lit()) {
	message("info","You can't discard your flame during the fire dance!",
	  environment());
	return 1;
    }
    return 0;
}

// Missile spell. Mobydick, 10-31-92. In a state of flux.

#include <mudlib.h>

inherit DAEMON ;

void block_attack (int time) ;
object query_attacker() ;
object *query_attackers() ;


varargs int cast (string str, int obj) {

	object target ;
	int sp, cost, skill ;

	if (str=="NONE") {
		target = this_player()->query_current_attacker() ;
	} else {
		target = present(str,environment(this_player())) ;
	}
	if (!target) {
		write ("Cast a magic missile at whom?\n") ;
		return 1 ;
	}
	if (target==this_player()) {
		write ("That seems like a pretty bad idea.\n") ;
		return 1 ;
	}
	if (!living(target)) {
		write("Please don't damage the furniture.\n") ;
		return 1 ;
	}
	if ((int)target->query("no_attack")==1) {
		write ("You are not permitted to attack that.\n") ;
		return 1 ;
	}
// if obj==1, then the call came from an object and we don't want to
// assess the spell point cost.
	if (obj!=1) {
		sp = this_player()->query("spell_points") ;
		skill = this_player()->query_skill("Combat spells") ;
        	cost = 100/(skill+10) ;
        	if (sp<cost) {
                	write ("You haven't got enough spell points to cast it.\n") ;
                	return 1 ;
		}
        	this_player()->set ("spell_points", sp-cost) ;
	}
	if (str!="NONE") {
		write ("You attack "+str+"!\n") ;
	}
	this_player()->kill_ob(target) ;
        call_out( "new_missile_cast(target)", 1, this_player() );
	this_player()->improve_skill("Combat spells", 5) ;
	return 1 ;
}


int new_missile_cast( object target ) {
    target = query_attacker() ;
    block_attack(4) ;
    write ("You begin casting magic missile...\n") ;
    call_out( "new_missile_effect(target)", 4, this_player() );
}


void new_missile_effect( object target ) {

    int hp, damage, skill ;

    if (!present(target,environment(this_player())) || target->query("hit_points")<0) {
      tell_object(this_object(), "Your target is no longer here.\n") ;
      return ;
    }
    skill = this_player()->query_skill ("Combat spells") ;
    damage = random(6+skill/10)+5+skill/5 ;
    if(damage)   target->set("last_attacker", this_player());
    target->receive_damage(damage) ;
    tell_object(target,"Suddenly you are hit by a magic missile spell!\n);
    tell_room(environment(this_player()), this_player()->query("cap_name")+"hits "+target->query("cap_name")+" with a magic missile!\n", ({ this_player(), target }) ) ;
    tell_object(this_player(), "You cast a magic missile at "+target->query("name")+" and hit!\n") ;
    tell_object(this_player(),"You cast magic missile at "+target->query("na
}

// spells.c
// Mobydick, 10-28-92
// Created by splitting the code out of the existing attack.c.

// The following two procedures implement the magic missile spell.
// missile_cast() is called when the player casts the spell. It ducks
// his spell points, sets the target, interrupts attacks during the cast,
// and call_outs missile_effect(). Missile_effect checks to make sure the
// target is still around, and if it is, damages it and prints messages.
// Pallando changed a hardcoded reference to _look.c 93-02-14

#include <commands.h>

// All other spells should follow the same general pattern: one function that
// starts the casting process and a second, call_outed from the first, that
// implements the effects.

// Prototypes: all are in attack.c.

void block_attack (int time) ;
object query_attacker() ;
object *query_attackers() ;


object target ;

// This is here so you can alter the target of a spell if you want to
// do that. Usually you should not. It also lets you circumvent the time lag
// on some spells, so that you can make items that call the spell with
// no delay.

void set_target (object ob) {
	target = ob ;
}

int missile_cast() {
	target = query_attacker() ;
	block_attack(4) ;
        write ("You begin casting magic missile...\n") ;
	call_out("missile_effect",4) ;
}

void missile_effect() {

	int hp, damage, skill ;

	if (!present(target,environment(this_object())) || target->query("hit_points")<0) {
		tell_object(this_object(),"Your target is no longer here.\n") ;
		return ;
	}
	skill = this_object()->query_skill ("Combat spells") ;
	damage = random(6+skill/10)+5+skill/5 ;
	if(damage)   target->set("last_attacker", this_object());
	target->receive_damage(damage) ;
	tell_object(target,"Suddenly you are hit by a magic missile spell!\n") ;
	tell_room(environment(this_object()),this_object()->query("cap_name")+" hits "+target->query("cap_name")+" with a magic missile!\n", ({ this_object(), target }) ) ;
	tell_object(this_object(),"You cast magic missile at "+target->query("name")+" and hit!\n") ;
}

void heal_cast (object patient) {
	target = patient ;
	write ("You begin casting heal...\n") ;
	block_attack(2) ;
	call_out ("heal_effect", 2) ;
}

void heal_effect() {

	int hp, cure, skill ;

	if (!present(target,environment(this_object())) || target->query("hit_points")<0) {
                tell_object(this_object(),"Your target is no longer here.\n") ;
                return ;
	}
	skill = this_object()->query_skill("Healing spells") ;
	cure = random(6+skill/10)+5+skill/5 ;
	target->receive_healing(cure) ;
	if (target==this_object()) {
		tell_object(this_object(),"You heal yourself.\n") ;
		tell_room(environment(this_object()),this_object()->query("cap_name")+" heals "+objective(this_object()->query("gender"))+"self.\n",this_object()) ;
	} else {
		tell_object(this_object(),"You heal "+target->query("name")+".\n") ;
		tell_object(target,this_object()->query("cap_name")+" heals you!\n") ;
		say (this_object()->query("cap_name")+" heals "+target->query("cap_name")+".\n", target) ;
	}
	return ;
}

void fireball_cast() {
	write ("You begin casting fireball...\n") ;
	block_attack(8) ;
	call_out("fireball_effect",8) ;
}

void fireball_effect() {

	int damage, skill, i , hp, flag ;
	object *attackers ;
	object *blocked_obs ;

	attackers = query_attackers() ;
	skill = this_object()->query_skill("Combat spells") ;
	for (i=0;i<sizeof(attackers);i++) {
		if (!present(attackers[i],environment(this_object())) || attackers[i]->query("hit_points")<0) {
			continue ;
		}
		flag = 1 ;
		damage = random(9+skill/6)+8+skill/3 ;
		if(damage) attackers[i]->set("last_attacker");
		attackers[i]->receive_damage(damage) ;
		tell_object(attackers[i],"Suddenly you are hit by a fireball!\n") ;
	}
	blocked_obs = (attackers ? attackers : ({ }) ) + ({ this_object() }) ;
	if (flag==1) {
		tell_object(this_object(),"You cast a fireball!\n") ;
	} else {
		tell_object(this_object(),"You cast a fireball, but it doesn't hit anything.\n") ;
	}
	tell_room(environment(this_object()),this_object()->query("cap_name")+" casts a fireball! But you are outside the effect.\n", blocked_obs) ;
}

// The vision spell lets you see another player's surroundings.

int vision_cast (object name) {

	string desc ;
        object env;

	this_player()->block_attack(2) ;

        env = environment(name);
        if (!env) {
		write("You cast a vision spell, and see only emptiness in the void.\n");
        } else {
		desc = CMD_LOOK->look_in_room(env);
		write (desc) ;
        }
	return 1 ;
}

int invis_cast() {

	int skill, duration ;

	this_player()->block_attack(2) ;
	skill = this_player()->query_skill("Divinations spells") ;
	duration = 27+3*skill ;
	tell_object(this_object(),"You become invisible!\n") ;
	tell_room (environment(this_object()),this_object()->query("cap_name")+ " vanishes from your sight!\n",this_object()) ;
	this_object()->set("invisible",1) ;
	call_out ("invis_effect", duration) ;
	return 1 ;
}

int invis_effect() {
	this_object()->set("invisible",0) ;
	tell_object (this_object(), "You become visible again.\n") ;
	tell_room (environment(this_object()),"Suddenly "+this_object()->query("cap_name")+" appears as if out of thin air.\n", this_object()) ;
	return 1 ;
}

// The message spell lets you send a telepathic message to another player.

int message_cast (object recipient) {
	target = recipient ;
	write ("Enter the message you want to send to "+recipient->query("cap_name")+":\n") ;
	input_to("message_effect") ;
	return 1 ;
}

int message_effect (string str) {
	write ("You enter the mind of "+target->query("cap_name")+" and send the message.\n") ; 
	tell_object (target, "You feel a presence in your mind... Suddenly you hear the voice of "+this_object()->query("cap_name")+"!\n"+"It says: "+str+"\n") ;
	return 1 ;
}

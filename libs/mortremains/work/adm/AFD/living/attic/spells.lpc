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
    int hp, damage, skill;
	target = query_attacker() ;

	if (!present(target,environment(this_object())) || target->query("hit_points")<0) {
		tell_object(this_object(),"Your target is no longer here.\n") ;
             return 1;
	}
	skill = this_object()->query_skill ("Combat spells") ;
	damage = random(6+skill/10)+5+skill/5 ;
	if(damage)   target->set("last_attacker", this_object());
	target->receive_damage(damage) ;
        message("combat", this_object()->query("cap_name") +
           " casts a magic missile at "+target->query("cap_name")+"!\n",
           environment(this_object()), ({ target, this_object() }) );
      tell_object(target, this_object()->query("cap_name") +
           " casts a magic missile at you!\n");
       tell_object(this_object(), "You cast a magic missile at "+
              target->query("cap_name")+"!\n");
}

void heal_cast (object target) {
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
       tell_object(attackers[i], this_object()->query("cap_name") +
        " hits you with an enormous fireball!\n");
	}
	blocked_obs = attackers + ({ this_object() }) ;
	if (flag==1) {
		tell_object(this_object(),"You cast a fireball!\n") ;
	} else {
		tell_object(this_object(),"You cast a fireball, but it doesn't hit anything.\n") ;
	}
       tell_room(environment(this_object()), this_object()->query("cap_name")+
 " casts a fireball, but you are outside the area of effect.\n",
              blocked_obs);
}

// The vision spell lets you see another player's surroundings.

int scry_cast (object name) {
	string desc ;
        object env;

        env = environment(name);
        if (!env) {
             write("You cast scry...and see nothing!\n");
        } else {
		desc = CMD_LOOK->look_in_room(env);
                   write("You cast scry.. and see:\n");
		write (desc) ;
        }
	return 1 ;
}

int invis_cast() {
	int skill, duration ;
	skill = this_player()->query_skill("Divinations spells") ;
	duration = 27+3*skill ;
       tell_object(this_object(), "You cast invisibility on yourself.\n");
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
      write("You enter the mind of "+target->query("cap_name")+
          " and send the message.\n");
     tell_object(target, "You feel another presence in your mind..\n"+
        "The voice of "+this_object()->query("cap_name")+ " says: "+
              str+"\n");
	return 1 ;
}

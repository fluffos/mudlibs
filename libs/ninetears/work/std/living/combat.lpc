/* Ok, this time it's this code I will walk through...
 * Baldrick, april '94
 * Removed the deathstuff and pu tit in death.c.
 * looks a lot better that way.
 */

inherit "/std/unarmed_combat";

/* Hmm, are we using these now ? */
int *weapon_attack_out, *attack_out;                //dk

nosave object attackee;
nosave object *attacker_list,
*call_outed,
protector;

nosave object concentrate;
nosave int dodging;

#define DIV_NUM 6
#include "money.h"

void set_weapon_attack_out(int mess, object *held_ob) { }

int query_dodging() { return dodging; }
int query_my_att_level() { return (int)this_object()->query_level(); }

int set_concentrate(object ob) {
    	if ( member_array(ob, attacker_list) == -1 ) return 0;
    	concentrate = ob;
    	return 1;
	}

object query_concentrate() { return concentrate; }

int query_concentrate_valid() { return 0; }

int remove_protector(object ob) { return(protector = 0); }
object set_protector(object ob) { return (protector = ob); }
object query_protector() { return protector; }

int query_fighting() {
	return sizeof(attacker_list+call_outed-({0}));
	}

int query_protect_valid(object attacker, object protectee) {
    	int hab=random(TO->query_habilidad("proteger"))+TO->query_dex();
    	int base_roll = random(100);
    	if ( member_array( attacker, attacker_list ) == -1 ) hab += 25;
    	return ( base_roll <= hab );
	}

void actual_death();

void create() {
    	attacker_list = ({ });
    	call_outed = ({ });
    	concentrate = 0;
    	unarmed_combat::create();
	}

void combat_commands() {
    	add_action("do_protect", "proteger");
    	add_action("do_unprotect","desproteger");
    	unarmed_combat_commands();
	}

object query_attackee() { return attackee; }

// NEW by Tyrael - Feb '02 - Fns Maskeables por shadows
int weapons_attack(object him, object me, int n, object *weaps) {
	int olav = 0, dam = 0;
	for(; olav < n; olav++) if(!olav||TO->query_habilidad("doble arma")>random(100)) dam += (int)weaps[olav]->weapon_attack(attackee,this_object());
	return dam;
	}

int shields_attack(object him, object me, int n, object *shields) {
	int escudos_hits, olav = 0, dam = 0;

	// ahora golpear con escudos
	if ((escudos_hits = me->query_property("shield_hits"))) {
		if (escudos_hits > n) escudos_hits = n;
		for (; olav < escudos_hits; olav++) if(random(TO->query_habilidad("escudos"))>random(100)) dam += (int)shields[olav]->shield_attack(attackee, TO);
		}
	return dam;
	}

// no mu bonito el nombre pero sirve :P
// ia cambiaremos esto para que pegue tantas veces como manos libres.
// mirar el danyo medio de unarmeds, no vaya a ser q aun sea mejor
// ir sin armas q con ellas.
// considerar incluir flag por si se llamo antes a weapon o shield
// ultimo parm: si se usaron o no armas/escudos antes.
int unarmeds_attack(object him, object me, int n, int ws_used) {
	int dam = 0, olav = 0;
	for (; olav < n; olav++) if((!olav&&!sizeof(TO->query_weapons_wielded()))||TO->query_habilidad("pelea")>random(100)) dam += TO->unarmed_attack(attackee,this_object());
	return dam;
	}

// EDITAR AQUI PARA NO PERMITIR PEGAR A LA VEZ QUE SE FORMULA... - Tyrael
// La pregunta es... por ejemplo al formular un mayor, dejamos que se vea
// lo de "Estas persiguiendo a ..." antes de acabar el hechizo? _:P
void attack() {
    	int i, dam, his_att_lvl, att_level;
    	string his_name;
    	object ob,*ww;
	int armas_usadas = 0;

    	if (!attacker_list) attacker_list = ({ });

// Evitamos formular y pegar si no tenemos la propiedad adecuada
	if (sizeof(TO->query_attacker_list())) if (TO->query_spell_effect("spell") && !TO->query_property("pegar_y_formular")) {
		tell_object(TO, "Estas demasiado concentrado para devolver el golpe.\n");
		return;
    		}

//Actualizamos la lista de atacantes
	while (i<sizeof(attacker_list)) {
		if (!attacker_list[i]) attacker_list = delete(attacker_list,i,1);
		else if (environment(attacker_list[i]) != environment(this_object())) {
	    		tell_object(TO,"Estas persiguiendo a "+capitalize(attacker_list[i]->combat_short())+".\n");
	    		if (!call_outed) call_outed = ({ attacker_list[i] });
	    		else call_outed += ({ attacker_list[i] });
	    		attacker_list = delete(attacker_list,i,1);
			}
		else i++;
    		}

//Actualizamos la lista de perseguidos
    	i = 0;
    	while (i<sizeof(call_outed)) {
		if (!call_outed[i]) call_outed = delete(call_outed,i,1);
		else if (environment(this_object()) == environment(call_outed[i])) {
	    		attacker_list += ({ call_outed[i] });
	    		call_outed = delete(call_outed,i,1);
			}
		else i++;
		}

// No elegimos objetivo si no tenemos enemigos en la lista
	if (!sizeof(attacker_list)) {
		attackee = 0;
		return;
    		}
// Si estamos en la room de la persona contra quien estamos centrando le elegimos como objetivo, si no dejamos de concentrar
// y pegamos a cualquiera.
    	if (concentrate) {
		if ( member_array( concentrate, attacker_list ) == -1 ) {
	    		attackee = attacker_list[random(sizeof(attacker_list))];
	    		concentrate = 0;
			}
		else {
	    		attackee = concentrate;
	    		if ( !this_object()->query_concentrate_valid(concentrate, attacker_list) ) concentrate = 0;
			}
    		}
    	else attackee = attacker_list[random(sizeof(attacker_list))];

// Comprobamos si se ataca a un protegido
	if ((ob = (object) attackee->query_protector()) == TO) {
		attackee->remove_protector(TO);
		tell_object(attackee, TO->QCN + " deja de protegerte.\n");
		tell_room(environment(TO),TO->query_cap_name()+" deja de proteger a "+attackee->QCN+".\n", ({attackee, TO }));
		}

    	if (protector && member_array(protector, attacker_list) != -1) {
		tell_object(this_object(), protector->query_cap_name()+" se vuelve contra ti y te ataca.\n");
		tell_object(protector, "Comienzas a atacar a "+this_object()->query_cap_name()+" y dejas de proteger"+this_object()->query_objective()+".\n");
		say(protector->query_cap_name()+" se vuelve contra "+this_object()->query_cap_name()+" y le ataca.\n",({ protector, this_object() }));
		protector = 0;
    		}

    // error si pasas un array VACIO
    	if (ob && environment(ob) == environment(attackee) && ob->query_protect_valid(this_object(), attackee) && !ob->query_dead()) {
	    	tell_object(attackee, ob->query_cap_name()+" te protege valientemente.\n");
	    	tell_object(ob,"Proteges valientemente a "+attackee->query_cap_name()+".\n");
	    	say(ob->query_cap_name()+" protege valientemente a "+attackee->query_cap_name()+".\n", ({ attackee, ob }));
	    	attackee = ob;
    		}

    	his_att_lvl = maxi(({ (int)attackee->query_level(), 1 }) );
    	his_name = (string)attackee->query_name();

    	attackee->attack_by(this_object());


    // Attack code below by Aragorn / Fully rewritten by Tyrael.
	// QUIEN le ha dicho a este listo que solo tenemos una mano libre?

	// Sistema de ataques con manos/escudos/armas reescrito y mejorado
	// Tyrael - Nov 2001

	// Radix added this_object()-> for shadows

	// NUEVO SISTEMA para permitir shadows de golpeos con armas
	// y escudos (desarmado ya existe :P)
	// Tyrael - Feb '02
	// pasar TO sera necesario? de momento ahi keda
	// el tercer parametro es para no tener q repetir el sizeof



	if ( ( i = sizeof( (ww = TO->query_weapons_wielded()) ) ) ) {
		armas_usadas++;
		dam += TO->weapons_attack(attackee, TO, i, ww);
		}
	if ( ( i = sizeof( (ww = TO->query_shields_held()) ) ) ) dam += TO->shields_attack(attackee, TO, i, ww);

	if ( (i = TO->query_free_hands_left()) ) if(!armas_usadas||TO->query_habilidad("pelea")) dam += TO->unarmeds_attack(attackee, TO, i, armas_usadas);


    	if (!attackee) {
		tell_object(this_object(),"Has matado a "+his_name+"\n");
		say(this_object()->query_cap_name()+" ha matado a "+his_name+"\n");
    		}

    // Fix by Aragorn
    	att_level = (int)this_object()->query_level();
    	att_level = att_level?att_level:1;
    	++att_level;

	// Esto da experiencia por danyo hecho
	TO->adjust_xp(dam*(his_att_lvl/att_level));
    	event(environment(this_object()), "fight_in_progress", attackee);
	}

void attack_by(object ob) {
    	if (ob == this_object()) return ;
    	if(this_object()->query_hidden()) return;
    	if (!attacker_list) attacker_list = ({ });
    	if (!sizeof(attacker_list)) dodging = (int)this_object()->query_level();
    	if (member_array(ob, attacker_list) == -1 && member_array(ob, call_outed) == -1) {
		tell_object(this_object(), "Estas siendo atacad"+((TO->query_gender()-1)?"a":"o")+" por "+ob->combat_short() + ".\n");
		attacker_list += ({ ob });
    		}
    	set_heart_beat(1);
	}

/* Hmm, this is called by the attacker, object ob is the victim */
void attack_ob(object ob) {
    	if (ob == this_object()) return;

    	if (ob->query_dead()) return;

    	if (!attacker_list) attacker_list = ({ });
    	if (!sizeof(attacker_list)) dodging = (int)this_object()->query_level();

    	if (member_array(ob, attacker_list) == -1 && member_array(ob, call_outed) == -1) attacker_list += ({ ob });
    	if (ob) ob->attack_by(this_object());
	}

void check_stop_fight(object ob) {
    	int i;
    	if ((i=member_array(ob,call_outed)) != -1) call_outed = delete(call_outed,i,1);
	}

int stop_fight(object ob) {
    	int i;
    	if ((i=member_array(ob,call_outed)) != -1) {
    		tell_object(this_object(),"Paras de perseguir a "+CAP(call_outed[i]->combat_short(0))+".\n");
		call_outed = delete(call_outed, i, 1);
    		}
    	if ((i=member_array(ob,attacker_list)) != -1) attacker_list = delete(attacker_list,i,1);
	}

mixed *query_attacker_list() {
    	attacker_list -= ({0});
    	return attacker_list;
	}

mixed *query_call_outed() {
    	call_outed -= ({0});
    	return call_outed;
	}

/** added by Raskolnikov Oct 96 **/
mixed *remove_call_outed() {
    	call_outed = ({ });
    	return call_outed;
	}

/** added by Raskolnikov Oct 96 **/
mixed *reset_attacker_list() {
    	attacker_list = ({ });
    	return attacker_list;
	}


//dw   Sets up protection matrixes.
int do_protect(string str) {
    	object *obs, *ok, *enemies; int i;
    	if (!str) return notify_fail("Sintaxis: proteger <persona(s)>\n");

    	obs = find_match(str, environment(this_object()));
    	if (!sizeof(obs)) return notify_fail("Proteger a quien?\n");

    	if (member_array(this_object(), obs)) obs -= ({ this_object() });
    	ok = ({ });
	enemies = TO->query_attacker_list();
    	for (i=0; i<sizeof(obs); i++) {
		if (member_array(obs[i], enemies) != -1) continue;
		if (obs[i] == TO) continue;
		if (obs[i]->set_protector(this_object())) ok += ({ obs[i] });
    		}

  	if (sizeof(obs) != sizeof(ok)) return notify_fail(CAP(query_multiple_short(obs-ok))+ " no quiere" + (sizeof(obs)==1?" ":"n ")+"tu proteccion.\n");

    	write("Proteges a "+query_multiple_short(ok)+".\n");
    	say(this_object()->query_cap_name()+" protege a "+query_multiple_short(ok)+".\n", ok);
    	for (i=0; i<sizeof(ok); i++) tell_object(ok[i], this_object()->query_cap_name()+" protege a "+query_multiple_short(({ "ti" }) + (ok - ok[i..i]))+".\n");
    	return 1;
	}

int do_unprotect(string str) {
    	object tmp;
    	if(!str) return notify_fail("Sintaxis: desproteger <persona(s)>\n");

    	tmp = find_living(str);
    	if(!tmp) return notify_fail("Desproteger a quien?\n");

    	if(tmp->query_protector() != this_object()) {
		write("No estabas protegiendo a "+tmp->query_cap_name()+".\n");
		return(1);
    		}
    	tmp->remove_protector(this_object());

    	if(environment(tmp) == environment(this_object())) {
		tell_object(tmp,this_object()->query_cap_name()+" se aparta y deja de protegerte.\n");
		tell_room(environment(),this_object()->query_cap_name()+" deja de proteger a "+tmp->query_cap_name()+".\n", ({tmp, this_object() }));
    		}
    	write("Te apartas y dejas de proteger a "+tmp->query_cap_name()+".\n");
    	return 1;
	}

mixed stats()
{
    int i; object ob; mixed *ret;
    if (ob=this_object()->query_held_ob(0) && ob->query_weapon())
	ret += ({ ({ "Weapon", ob->short() }) }) + (mixed)ob->weapon_stats();
    if (ob=this_object()->query_held_ob(1) && ob->query_weapon())
	ret += ({ ({ "Secondary weapon", ob->short() }) });
    for (i=0; i<sizeof(attack_out); i+=7)
	ret += ({ ({ "If",    attack_out[i], }),
	  ({ "Rate",  attack_out[i+1], }),
	  ({ "Attack", attack_out[i+2], }),
	  ({ "Tohit", attack_out[i+3], }),
	  ({ "Number of damage dice", attack_out[i+4], }),
	  ({ "Die size", attack_out[i+5], }),
	  ({ "Addend", attack_out[i+6], }),
	});
    return ret;
}

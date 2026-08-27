// Vilat - Dia de los muertos del 2K2


object me;
object plato;

void stop_comida() {
  	if (me) {
    		tell_object(me, "Te acabas tu "+plato->query_short()+".\n");
    		tell_room(environment(me), me->query_cap_name()+" se acaba su "+plato->query_short()+".\n", me);
  		}
	plato->dest_me();
  	destruct(TO);
	}

void init_rutina(object ob, object co) {
  	shadow(ob,1);
  	me = ob;
	plato=co;
	call_out("do_digestion",0,plato->query_curacion());
	}

varargs int move( mixed dest, mixed messout, mixed messin ) {
    	call_out("stop_comida",0);
  	return me->move(dest, messout, messin );
	}

int query_hold_spell() { return 1; }

object* query_weapons_wielded() {
    	call_out("stop_comida",0);
  	return ({ this_object() });
	}

int weapon_attack( object him, object me ) {
  	call_out("stop_comida",0);
  	return 0;
	}

int shield_attack(object him, object me) {
	call_out("stop_comida",0);
	return 0;
	}

void attack_ob(object ob) {
  	call_out("stop_comida",0);
  	return 0;
	}

string extra_look() { return "Esta comiendo.\n"; }

varargs mixed move_player(string dir, string dest, mixed message, object followee, mixed enter) {
  	if ( this_player(1) && this_player(1)->query_creator() ) return me->move_player(dir, dest, message, followee, enter);
    	call_out("stop_comida",0);
  	return 0;
	}

void do_digestion(int curacion) {
	if (!curacion) {
		call_out("stop_comida",0);
		return;
		}
	me->adjust_ep(1);
	curacion--;
	call_out("do_digestion",1,curacion);
	}



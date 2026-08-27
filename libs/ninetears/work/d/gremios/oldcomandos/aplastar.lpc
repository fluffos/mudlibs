// Vilat 24.08.2002
// Aplastar para barbaros caoticos

// Inspirado (muy libremente) en el golpear de Tyrael

#define GPS 10

object envinicio;

int aplastado(object ob, object me);

string help() { return "\nNombre del Comando: Aplastar\nCoste en Pg: "+GPS+"\nSintaxis: Aplastar <objetivo>\nDescripcion: \n    Esta habilidad permite al Barbaro lanzar un poderoso ataque con un arma a dos manos capaz de destrozar a los mas fuertes enemigos.\n"; }

int aplastar(string str,object x) {
  	object* armas;
  	object ob;
	object me;
  	int dosmanos=0;
  	object* presentes;
  	int localizado=0;
  	

	if (!x) x=TP;
	me=x;
	
	if (me->query_dead()) return notify_fail("No estas en condiciones de aplastar a nadie...\n");
	if (me->query_property("aplastando")) return notify_fail("Ya estas preparando un demoledor aplastamiento.\n");
	if (me->query_property("aplastado")) return notify_fail("Espera un poco mientras recuperas tus fuerzas para realizar otro aplastamiento.\n");
	
	armas = me->query_held_ob();
	if (armas[0] && armas[0]->query_twohanded()) dosmanos=1;
  	if (armas[1] && armas[1]->query_twohanded()) dosmanos=1;
  	if (!dosmanos) return notify_fail("El golpe aplastante solo puede realizarse con armas a dos manos.\n");
  	
  	presentes=all_inventory(environment(me));
	for (int i=0;i<sizeof(presentes);i++){
		if (presentes[i]->query_cap_name() == capitalize(str)) localizado=1;
  		continue;
  		}
	if (!localizado) return notify_fail("Aplastando cosas inexistentes otra vez? Deberias pedir ayuda medica...\n");
  	
  	ob=find_match(str,environment(me))[0];
  	if (!ob || ob->query_hidden()) return notify_fail("Aplastando cosas inexistentes otra vez? Deberias pedir ayuda medica...\n");
  	if (ob==me) return notify_fail("Diriges un impresionante golpe aplastante contra ti mismo! Por suerte te apartas justo a tiempo, uf!\n");
  	if (ob->query_dead()) return notify_fail("Tras meditar un rato te das cuenta de que seria inutil aplastar eso.\n");
  	
  	if (me->query_gp() < GPS) return notify_fail("Estas demasiado cansado para efectuar un golpe de ese calibre.\n");
  	me->adjust_gp(-GPS);
  	me->add_timed_property("aplastando",1,11);  
  	envinicio=environment(me);  	
  	tell_object(me,"Te preparas para propinar un potente golpe aplastante a "+ob->query_cap_name()+".\n");
  	tell_room(envinicio,me->query_cap_name()+" prepara un potente golpe.\n");
  	call_out("aplastado",10,ob,me);
  	return 1;
	}
	

int aplastado( object x, object y ) {
	int mychance,itschance,pupa;
	object ob=x;
	object me=y;
	
	me->remove_timed_property("aplastando");
	me->add_timed_property("aplastado",1,13);
	
	if (me->query_dead()) return notify_fail("Tu muerte prematura ha impedido que tu oponente degustase un potente golpe aplastante.\n");
	if (environment(me)!= envinicio) return notify_fail("Detienes tu golpe aplastante al moverte.\n");
	if (me->query_property("noguild")||me->query_pacify_spell()||ob->query_pacify_spell()) return notify_fail("Algo te impide terminar tu magistral golpe aplastante.\n");
	if (!ob||ob->query_dead()) return notify_fail("Tu oponente ha muerto y no podra disfrutar de golpe aplastante.\n");
	if (envinicio!=environment(ob)) {
		tell_room(envinicio,me->query_cap_name()+" realiza un potente movimiento aplastante capaz de destrozar al mas fuerte de los mortales, pero su objetivo ha desaparecido.\n");
		return notify_fail("Realizas el mejor golpe aplastante de tu vida, pero tu objetivo no esta aqui.\n");
		}
	
	mychance=me->query_level()+me->query_str()+20;
	itschance=ob->query_level()+ob->query_dex();
	itschance*=(100-ob->query_total_ac());
  	mychance*=(275-me->query_thac0());

  	if(random(mychance)>random(itschance)) {
		tell_room(environment(me), me->query_cap_name()+" golpea fuertemente a "+ob->query_cap_name()+" reventando sus entranyas y aplastando sus huesos!\n", ({me, ob}));
		tell_object(me, "Aplastas los huesos de "+ob->query_cap_name()+" causandole danyos masivos!\n");
		tell_object(ob, me->query_cap_name()+" aplasta con su arma tu debil cuerpo rompiendo todos tus huesos!\n");

		pupa=me->query_level()*4+me->query_str()*(random(5) + 1)+random(me->query_con());
    		ob->adjust_hp(-pupa, me);
  		}
  	else {
    		tell_room(environment(me),ob->query_cap_name()+" consigue esquivar el movimiento de "+me->query_cap_name()+".\n",({me,ob}));
    		tell_object(me, "No consigues aplastar a tu enemigo!\n");
    		tell_object(ob, "Consigues esquivar el movimiento de "+me->query_cap_name()+".\n");
  		}
  	ob->attack_by(me);
  	return;
	}
	
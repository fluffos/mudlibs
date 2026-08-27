// Vilat 24.08.2002
// Aplastar para barbaros caoticos

inherit "/std/comando";

object me,ob;

void setup() {
	poner_ayuda("\nNombre del Comando: Aplastar\nCoste en Energia: 10\nSintaxis: Aplastar <objetivo>\nDescripcion: \n    Esta habilidad permite al Barbaro lanzar un poderoso ataque con un arma a dos manos capaz de destrozar a los mas fuertes enemigos.\n");
 	gasta_energia(10);
	impedir_movimiento("Detienes tu golpe aplastante al moverte.\n");
	poner_retardo(3);
 	}

int precondiciones() {
  	object* armas;
  	int dosmanos=0;
	me=query_ejecutor();

	::precondiciones();

	if (me->query_static_property("aplastando")) return notify_fail("Ya estas preparando un demoledor aplastamiento.\n");
	if (me->query_timed_property("aplastado")) return notify_fail("Espera un poco mientras recuperas tus fuerzas para realizar otro aplastamiento.\n");

	armas = me->query_held_ob();
	if (armas[0] && armas[0]->query_twohanded()) dosmanos=1;
  	if (armas[1] && armas[1]->query_twohanded()) dosmanos=1;
  	if (!dosmanos) return notify_fail("El golpe aplastante solo puede realizarse con armas a dos manos.\n");

	if(sizeof(find_match(query_argumento(),ENV(me)))) ob=find_match(query_argumento(),ENV(me))[0];
	else return notify_fail("Aplastando cosas inexistentes otra vez? Deberias pedir ayuda medica...\n");
  	if (ob==me) return notify_fail("Diriges un impresionante golpe aplastante contra ti mismo! Por suerte te apartas justo a tiempo, uf!\n");
  	if (ob->query_dead()) return notify_fail("Tras meditar un rato te das cuenta de que seria inutil aplastar eso.\n");
  	me->add_static_property("aplastando",1);
	return 1;
	}

int condiciones() {
	me->remove_static_property("aplastando");
	if (me->query_dead()) return notify_fail("Tu muerte prematura ha impedido que tu oponente degustase un potente golpe aplastante.\n");
	::condiciones();
	if (me->query_property("noguild")||me->query_pacify_spell()||ob->query_pacify_spell()) return notify_fail("Algo te impide terminar tu magistral golpe aplastante.\n");
	if (!ob||ob->query_dead()) return notify_fail("Tu oponente ha muerto y no podra disfrutar de golpe aplastante.\n");
	if (ENV(ob)!=ENV(me)) return notify_fail("Tu oponente ha huido!!!\n");
	return 1;
  	me->add_static_property("aplastando",1);
	}

int efecto( string inutil, object masinutil ) {
	int mychance,itschance,pupa;

	me->remove_static_property("aplastando");
	::efecto(inutil,masinutil);
	mychance=me->query_level()+me->query_str()+20;
	itschance=ob->query_level()+ob->query_dex();
	itschance*=(100-ob->query_total_ac());
  	mychance*=(275-me->query_thac0());

  	if(random(mychance)+random(me->query_habilidad("aplastar"))>random(itschance)) {
		tell_room(environment(me), me->query_cap_name()+" golpea fuertemente a "+ob->query_cap_name()+" reventando sus entranyas y aplastando sus huesos!\n", ({me, ob}));
		tell_object(me, "Aplastas los huesos de "+ob->query_cap_name()+" causandole danyos masivos!\n");
		tell_object(ob, me->query_cap_name()+" aplasta con su arma tu debil cuerpo rompiendo todos tus huesos!\n");
		if(me->query_level()<ob->query_level()) me->adjust_sp(1);
		pupa=me->query_level()*4+me->query_str()*roll(1,5)+random(me->query_con());
    		ob->adjust_hp(-pupa, me);
  		}
  	else {
    		tell_room(environment(me),ob->query_cap_name()+" consigue esquivar el movimiento de "+me->query_cap_name()+".\n",({me,ob}));
    		tell_object(me, "No consigues aplastar a tu enemigo!\n");
    		tell_object(ob, "Consigues esquivar el movimiento de "+me->query_cap_name()+".\n");
  		}
	me->add_timed_property("aplastado",1,100);
  	ob->attack_by(me);
  	return 1;
	}

void mostrar_mensajes(int r) {
	switch(r) {
		case 3:
		tell_object(me,"Levantas tu arma y coges impulso para realizar un potente movimiento aplastante.\n");
		tell_room(ENV(me),me->QCN+" levanta su arma cogiendo impulso.\n",me);
		break;
		case 1:
		tell_object(me,"Diriges un potentisimo golpe aplastante contra "+ob->QCN+"!!!\n");
		tell_object(ob, me->QCN+" diriges un potentisimo golpe aplastante contra ti!!!\n");
		tell_room(ENV(ob),me->QCN+" descarga un fuerte golpe contra "+ob->QCN+".\n",({ob,me}));
		break;
		}
	}


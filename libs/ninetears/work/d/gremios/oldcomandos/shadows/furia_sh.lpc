// Vilat 25.08.2002
// Shadow del furia, en principio para destruir la property al salir y al morir

object me;

void setup_shadow(object ob) {
	if (ob->query_furia_shadow()) return;
  	me = ob;
  	shadow(ob,1);
	}
	
int query_furia_shadow() { return 1; }
	
	
void dest_furia_shadow() {
    	me->adjust_tmp_ac_bon(-(me->query_tmp_ac_bon()));
   	me->adjust_tmp_damage_bon(-(me->query_tmp_damage_bon()));
   	me->adjust_tmp_tohit_bon(-(me->query_tmp_tohit_bon()));
    	if(me->query_tmp_con() > 0) me->adjust_tmp_con(-1);
	me->remove_timed_property("furioso");
	if (me->query_property("exhausto_furia")) {
		me->remove_property("exhausto_furia");
   		tell_object(me,"Tu cuerpo revienta a causa del esfuerzo realizado.\n");
   		tell_room(environment(me),me->query_cap_name()+" cae temblando al suelo, la furia le ha dejado destrozado.\n",me);
   		me->do_death();
   		}
	else {
		tell_object(me,"Tu furia se apaga conforme te vas cansando.\n");
    		tell_room(environment(me),"La furia de "+me->query_cap_name()+" se desvanece.\n",me);
    		}
  	call_out("do_dest_furia_shadow",0);
	}

void do_dest_furia_shadow() {
  	destruct(TO);
	}
	
int do_death(string str) {
	me->remove_property("exhausto_furia");
  	dest_furia_shadow();
  	return me->do_death(str);
	}
	
really_quit() {
   	dest_furia_shadow();
   	return me->really_quit();
	}
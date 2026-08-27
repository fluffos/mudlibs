// Vilat 25.08.2002
// Furia para barbaros caoticos
// Presentando el FuRiA 4 xD

// Tratando de arreglar algunos bug

void attack_all(object ob);
int allow_attack(object who, object me);
void end_furia(object ob); 
int morira=0;
int tiempo=0;
int max_tiempo=0;
int furia_level=0;

int furia(object x) {
   	object me; 
   	int BONUS;
   	int ACBONUS;
   	int COUNT;
   	int TIME;
   	if(!x) x = TP;
   	me = x;

   	furia_level = me->query_static_property("furioso");
   
   	if(me->query_gp() <= 1) return notify_fail("Estas demasiado cansado para desatar tu furia.\n");

   	switch(furia_level) {
   		case 0:
       		BONUS=(me->query_level()/3)+1;
    		ACBONUS = (BONUS - ((me->query_dex())/3));
    		me->adjust_tmp_ac_bon(-(me->query_tmp_ac_bon()));
    		me->adjust_tmp_damage_bon(-(me->query_tmp_damage_bon()));
    		me->adjust_tmp_tohit_bon(-(me->query_tmp_tohit_bon()));
      		me->adjust_tmp_damage_bon(BONUS);
      		me->adjust_tmp_tohit_bon(BONUS*2);
      		me->adjust_tmp_ac_bon(-ACBONUS);
		if(me->query_gp() >= 25) {
   			me->adjust_gp(-25);
   			max_tiempo = 25;
  			}
		else {
  			max_tiempo = me->query_gp();
   			me->adjust_gp(-max_tiempo);
 			}
      		me->add_static_property("furioso",1);
      		tell_object(me,"Te enfureces contra tus enemigos.\n");
      		tell_room(environment(me),me->query_cap_name()+" se enfurece contra sus enemigos.\n",me);
      		attack_all(me);
      		break;
   		
   		case 1:
   		if (me->query_gp() < 50) return notify_fail("Tu cuerpo esta demasiado cansado para incrementar tu furia.\n");
   		if (me->query_level() < 15) return notify_fail("Aun no eres lo suficientemente experimentado como para llevar tu furia mas alla.\n");
   		BONUS=(me->query_level()/2)+2;
    		ACBONUS = (BONUS - ((me->query_dex())/2));
    		me->adjust_tmp_ac_bon(-(me->query_tmp_ac_bon()));
    		me->adjust_tmp_damage_bon(-(me->query_tmp_damage_bon()));
    		me->adjust_tmp_tohit_bon(-(me->query_tmp_tohit_bon()));
       		me->adjust_gp(-50);
       		me->adjust_tmp_damage_bon(BONUS);
       		me->adjust_tmp_tohit_bon((int)BONUS*2);
       		me->adjust_tmp_ac_bon(-ACBONUS);
       		me->add_static_property("furioso",2);
       		tiempo=0;
       		max_tiempo=40;
       		tell_object(me,"Alcanzas una furia moderada.\n");
       		tell_room(environment(me),me->query_cap_name()+" alcanza una furia moderada.\n",me);
    		break;
    		
    		case 2:
    		if (me->query_gp() < 100) return notify_fail("Tu cuerpo esta demasiado cansado para incrementar tu furia.\n");
    		if (me->query_level() < 25) return notify_fail("Deberas aprender un poco mas para desatar una furia mayor.\n");
		BONUS=(me->query_level()/1.75)+5;
		ACBONUS = (BONUS - (me->query_dex()) );
    		me->adjust_tmp_ac_bon(-(me->query_tmp_ac_bon()));
    		me->adjust_tmp_damage_bon(-(me->query_tmp_damage_bon()));
    		me->adjust_tmp_tohit_bon(-(me->query_tmp_tohit_bon()));
        	me->adjust_gp(-100);
        	me->adjust_tmp_damage_bon(BONUS);
        	me->adjust_tmp_tohit_bon(BONUS*2);
        	me->adjust_tmp_ac_bon(-ACBONUS);
        	me->add_static_property("furioso",3);
       		tiempo=0;
       		max_tiempo=100;       
        	tell_object(me,"\n%^RED%^Tu furia te domina y atacas incluso a tus amigos.%^RESET%^\n");
		tell_room(environment(me),"\nLa furia de "+me->query_cap_name()+" es tal que deja de distinguir a amigos de enemigos.  %^BOLD%^%^RED%^Deberias escapar mientras todavia puedas!%^RESET%^\n",me);
    		break;
    		
    		case 3:
		if (me->query_level() < 35) return notify_fail("Solo los mas fuertes pueden alcanzar la Furia Definitiva.\n");
		BONUS=(me->query_level()*2)+5;
		ACBONUS = (BONUS - (me->query_dex()) );
    		me->adjust_tmp_ac_bon(-(me->query_tmp_ac_bon()));
    		me->adjust_tmp_damage_bon(-(me->query_tmp_damage_bon()));
    		me->adjust_tmp_tohit_bon(-(me->query_tmp_tohit_bon()));
		tiempo=0;
		max_tiempo = me->query_gp();
   		me->adjust_gp(-tiempo);
   		morira=1;
        	me->adjust_tmp_damage_bon(BONUS);
        	me->adjust_tmp_tohit_bon(BONUS*1.25);
        	me->adjust_tmp_ac_bon(-ACBONUS);
        	me->add_static_property("furioso",4,100);
        	tell_object(me,"\n%^RED%^Tu furia alcanza su cenit! Pierdes la nocion de la realidad y tus fibras se estremecen mientras golpeas freneticamente..%^RESET%^\n");
		tell_room(environment(me),"\n"+me->query_cap_name()+" %^BOLD%^%^RED%^se ha vuelto loco!%^RESET%^\n",me);
    		break;
    		
    		default:
        	tell_object(me,"Estas golpeando con la fuerza de un dios, ya no puedes enfurecerte mas.\n");
    		break;
    		}
	return 1;
	}

int allow_attack(object who, object me) {
     	if(who == me) return 0;
     	if(!who->query_alive() ) return 0;
     	if(me->query_property("furioso") == 0 ) return 0;
    	if(who->query_pacify_spell()) return 0;
     	if(who->query_invis()) return 0;
     	if( who->query_hide_shadow() > (me->query_level()/2 + me->query_int()) ) return 0;
     	if(me->query_property("furioso") >= 3 ) return 1;
     	if(who->query_protector() == me) return 0;
     	return 1;
	}

void attack_all(object ob) {
  	object *gentuza;
  	int x;

   	if(!ob) return;
	ob->set_wimpy(0);

   	if(environment(ob)->query_property("noguild"));
   	if(ob->query_dead()) return;
 
   	gentuza=all_inventory(environment(ob));
 
   	for(x=0; x <sizeof(gentuza); x++) {
        	if(allow_attack(gentuza[x],ob)) ob->attack_ob(gentuza[x]);
        	continue;
   		}
   	
   	if (tiempo>=max_tiempo) ob->remove_static_property("furioso");
   	if (!(ob->query_property("furioso")==0)) {
   		tiempo+=1;
   		call_out("attack_all",1,ob);
   		return;
   		}
	end_furia(ob);
	return;
	}

void end_furia(object ob) {
   	ob->adjust_tmp_ac_bon(-(ob->query_tmp_ac_bon()));
   	ob->adjust_tmp_damage_bon(-(ob->query_tmp_damage_bon()));
   	ob->adjust_tmp_tohit_bon(-(ob->query_tmp_tohit_bon()));
    	if(ob->query_tmp_con() >= 0) ob->adjust_tmp_con(-1);
   	if (morira) {
   		tell_object(ob,"Tu cuerpo revienta a causa del esfuerzo realizado.\n");
   		tell_room(environment(ob),ob->query_cap_name()+" cae temblando al suelo, la furia le ha dejado destrozado.\n",ob);
   		ob->do_death();
   		return;
   		}
    	tell_object(ob,"Tu furia se apaga conforme te vas cansando.\n");
    	tell_room(environment(ob),"La furia de "+ob->query_cap_name()+" se desvanece.\n",ob);
    	return;
	}
 

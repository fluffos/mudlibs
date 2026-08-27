// Vilat 30.08.2002
// Drenar

// Basado en mi aplastar para barbaros caoticos
// Voy a romper con lo que haba antes, kiero darle un giro a este comando

object envinicio;

string help() 
{
  return
    "\n\n"
    "Nombre del Comando: Drenar\n"
    "Sintaxis: drenar <objetivo>\n"
    "Descripcion: \n"
    "     This ability lets an infernal knight draw from the power of "
    "of the Oaths to Evil that he has sworn, to draw the life force of "
    "an opponent into himself.  A maximum of 2hp per level of the Knight "
    "of Darkness can be drained.  Since the control over the Negative "
    "Material Plane granted by this ability is tenuous at best, not all of the "
    "life force drained shall go to the Anti-Paladin;  indeed the Lord "
    "of Death, Cyric himself, demands half in payment.  This ability will "
    "heal a creature of undeath, but beware, for then the Knight himself "
    "shall have to make Cyric's dread payment.\n\n";  
}
int drenar(string str,object x) {
  	object ob;
	object me;
  	object* presentes;
  	int localizado=0;

	if (!x) x=TP;
	me=x;
	
	if (me->query_dead()) return notify_fail("No estas en condiciones de drenar a nadie...\n");
	if (me->query_property("drenando")) return notify_fail("Ya estas intentando drenar a una victima.\n");
	if (me->query_property("drenado")) return notify_fail("Tu cuerpo aun esta tratando de asimilar la ultima fuerza vital que robaste.\n");
	
	presentes=all_inventory(environment(me));
	for (int i=0;i<sizeof(presentes);i++){
		if (presentes[i]->query_cap_name() == capitalize(str)) localizado=1;
  		continue;
  		}
	if (!localizado) return notify_fail("Jade te ha concedido el poder de drenar la fuerza vital de tus oponentes, pero eso que quieres drenar no esta aqui.\n");
  	
  	ob=find_match(str,environment(me))[0];
  	if (!ob || ob->query_hidden()) return notify_fail("Jade te ha concedido el poder de drenar la fuerza vital de tus oponentes, pero eso que quieres drenar no esta aqui.\n");
  	if (ob==me) return notify_fail("Jade confia en que utilices este poder para destruir a sus enemigos.\n");
  	if (!living(ob)) return notify_fail("Los objetos carecen de fuerza vital.\n");
  	if (ob->query_dead()) return notify_fail("La fuerza vital de los muertos es demasiado escasa como para gastar asi tu poder.\n");
  	if (ob->query_property("nodrenable")) return notify_fail("Una fuerza misteriosa protege a tu objetivo: no podras drenarle.\n");
  	
  	me->add_property("drenando",1);
  	envinicio=environment(me);
  	tell_object(me,"Musitas unas arcanas palabras mientras te concentras en robar la fuerza vital de "+ob->query_cap_name()+".\n");
  	tell_room(envinicio,me->query_cap_name()+" murmura algo ininteligible.\n",me);
  	if (me->query_gender() == ob->query_gender()) call_out("drenandod",5,ob,me);
  	else call_out("drenandop",5,ob,me);
  	return 1;
	}
	

int drenandop( object x, object y ) {
	object ob=x;
	object me=y;
	
	if (!ob) return notify_fail("Tu objetivo ha muerto antes de que pudieses robarle su fuerza vital.\n");
	if (me->query_dead()) return notify_fail("Desgraciadamente, has muerto antes de poder apoderarte de la fuerza vital de tu objetivo.\n");
	if (ob->query_dead()) return notify_fail("Tu objetivo ha muerto antes de que pudieses robarle su fuerza vital.\n");
	if (envinicio != environment(me)) return notify_fail("Al moverte pierdes la concentracion necesaria para drenar a tu objetivo.\n");
	if (envinicio != environment(ob)) return notify_fail("Detienes el ritual ya que tu objetivo se ha marchado.\n");
	
	tell_object(me,"Tratas de seducir a "+ob->query_cap_name()+" para robar su fuerza vital.\n");
	tell_object(ob,me->query_cap_name()+" se acerca a ti sonriendo y te acaricia la cara sensualmente.\n");
	tell_room(envinicio,me->query_cap_name()+" acaricia sensualmente a "+ob->query_cap_name()+" en la mejilla.\n",({me,ob}));
	call_out("drenadop",5,ob,me);
	return 1;
	}
	
int drenandod( object x, object y ) {
	object ob=x;
	object me=y;
	
	if (!ob) return notify_fail("Tu objetivo ha muerto antes de que pudieses robarle su fuerza vital.\n");
	if (me->query_dead()) return notify_fail("Desgraciadamente, has muerto antes de poder apoderarte de la fuerza vital de tu objetivo.\n");
	if (ob->query_dead()) return notify_fail("Tu objetivo ha muerto antes de que pudieses robarle su fuerza vital.\n");
	if (envinicio != environment(me)) return notify_fail("Al moverte pierdes la concentracion necesaria para drenar a tu objetivo.\n");
	if (envinicio != environment(ob)) return notify_fail("Detienes el ritual ya que tu objetivo se ha marchado.\n");
	
	tell_object(me,"Te lanzas contra "+ob->query_cap_name()+" sujetandole fuertemente.\n");
	tell_object(ob,me->query_cap_name()+" se abalanza subitamente encima tuyo mientras rie alocadamente!\n");
	tell_room(envinicio,me->query_cap_name()+" se lanza contra "+ob->query_cap_name()+" y le sujeta mientras rie alocadamente.\n",({me,ob}));
	call_out("drenadod",5,ob,me);
	return 1;
	}
	
int drenadop( object x,object y ) {
	int pupa;
	object ob=x;
	object me=y;
	
	me->remove_property("drenando");
	
	if (!ob) return notify_fail("Tu objetivo ha muerto antes de que pudieses robarle su fuerza vital.\n");
	if (me->query_dead()) return notify_fail("Desgraciadamente, has muerto antes de poder apoderarte de la fuerza vital de tu objetivo.\n");
	if (ob->query_dead()) return notify_fail("Tu objetivo ha muerto antes de que pudieses robarle su fuerza vital.\n");
	if (envinicio != environment(me)) return notify_fail("Al moverte pierdes la concentracion necesaria para drenar a tu objetivo.\n");
	if (envinicio != environment(ob)) return notify_fail("Detienes el ritual ya que tu objetivo se ha marchado.\n");
	
	tell_object(me,"Besas a "+ob->query_cap_name()+" y absorbes su fuerza vital.\n");
	tell_object(ob,me->query_cap_name()+" te besa tiernamente provocandote un dulce extasis.\n");
	tell_room(envinicio,me->query_cap_name()+" besa a "+ob->query_cap_name()+" y una especie de corriente oscura fluye desde "+ob->query_cap_name()+", que parece ausente, hacia "+me->query_cap_name()+", fortaleciendole.\n",({me,ob}));
	
	pupa=me->query_level()*5+me->query_wis();
	ob->adjust_hp(-pupa,me);
	me->adjust_hp(random(pupa/2)+(pupa/2),me);
	
	me->add_timed_property("drenado",1,600);	
  	return 1;
	}
	
int drenadod( object x,object y ) {
	int pupa;
	object ob=x;
	object me=y;
	
	me->remove_property("drenando");
	
	if (!ob) return notify_fail("Tu objetivo ha muerto antes de que pudieses robarle su fuerza vital.\n");
	if (me->query_dead()) return notify_fail("Desgraciadamente, has muerto antes de poder apoderarte de la fuerza vital de tu objetivo.\n");
	if (ob->query_dead()) return notify_fail("Tu objetivo ha muerto antes de que pudieses robarle su fuerza vital.\n");
	if (envinicio != environment(me)) return notify_fail("Al moverte pierdes la concentracion necesaria para drenar a tu objetivo.\n");
	if (envinicio != environment(ob)) return notify_fail("Detienes el ritual ya que tu objetivo se ha marchado.\n");
	
	tell_object(me,"Absorbes la fuerza vital de "+ob->query_cap_name()+" produciendole un dolor extremo.\n");
	tell_object(ob,"Te retuerces de dolor cuando "+me->query_cap_name()+" se lleva tu fuerza vital.\n");
	tell_room(envinicio,ob->query_cap_name()+" se retuerce entre aullidos de verdadero dolor.\n",({me,ob}));
	
	pupa=me->query_level()*5+me->query_wis();
	ob->adjust_hp(-pupa,me);
	me->adjust_hp(random(pupa/2)+(pupa/2),me);
	
  	me->add_timed_property("drenado",1,600);
  	ob->attack_by(me);
  	return 1;
	}
	
inherit "obj/monster";

void setup()
{	set_name("belor");
  	set_short("Belor");
  	set_long("Un viejo humano, aunque alto y robusto, sirviente de Gareth. Aunque parezca viejo y tranquilo, Belor puede adquirir mucha ira si se le enfada.\n");
	set_main_plural("sirvientes");
  	add_alias("sirviente");
  	add_alias("tendero");
  	add_plural("tenderos");
  	set_random_stats(60,80);
  	set_str(100);
  	set_dex(90);
  	set_con(70);
  	set_int(110);
  	set_cha(110);
  	set_wis(120);
  	set_level(90);
  	set_race("humano");
  	set_align(0);
  	set_gender(1);
  	set_join_fight_mess("Belor te senyala con su mandoble retandote!.\n");
  	
  	load_a_chat(80,
({		1, "'Tu osadia sera castigada!",
		1, "'No permitire que perturbes las mazmorras!!",
                1, "'No saldras vivo de esta!!!",
}));
	add_clone("/baseobs/weapons/twohandedsword",1);
	add_clone("/baseobs/armours/completa",1);
	add_clone("/baseobs/armours/helmet",1);  
	init_equip();
}

void event_enter(object ob, string message) {
	if(!ob->query_living()) return ::event_enter(ob,message); 
	if (ob->query_name()=="gareth")
{
	tell_object(ob,"Bienvenido, mi senyor.\n",TO);
	tell_room(environment(TO),"Belor dice: mi senyor Gareth ha llegado.\n",ob);
} else
{
	tell_room(environment(TO),"Belor saluda a "+ob->query_cap_name()+".\n",ob);	
	tell_object(ob,"Belor te da la bienvenida.\n",TP);
	::event_enter(ob,message);
}
} 
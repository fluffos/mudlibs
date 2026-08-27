inherit "/obj/monster"; //  falta ver que tiene ese archivo y si esta..... //

void setup()
{
	set_name("habitante");
  	set_short("Habitante");
  	set_al(0);	   // el alin falta concretar dependiendo de la zona que sea. como mas negativo mas angelico//
   	set_gender(1);
 	set_main_plural("habitantes");
   	add_plural("Habitantes");
  	set_level(10+random(2));	// el nivel esta para testear. pero metemos lvl 20 para que sea facil matarlos//
   	set_random_stats(14,16);
   	set_cha(20);
   	set_race_ob("/std/races/human");
   	set_race("human");
   	set_long("Es un habitante de la fortificacion de Trior."
            	" Es un habitante de la zona pobre. \n\n");
        adjust_money(random(2), "silver");
  	set_xp(200);
	/* add_clone("/baseobs/weapons/bastard_", 1); 
   	add_clone("/baseobs/armours/large_shield", 1);
   	add_clone("/baseobs/armours/chainmail", 1); */
   	this_object()->init_equip();
   	add_move_zone("trior");
 	set_move_after(20+random(10), 20+random(10));
}
/* Este es un guardia de la puerta del poblado del valle del dragon */

inherit "/obj/monster"; //  falta ver que tiene ese archivo y si esta..... //

void setup()
{
	set_name("guardia");
  	set_short("Guardia de Trior");
  	// set_al(1900);	    el alin falta concretar dependiendo de la zona que sea. como mas negativo mas angelico//
   	set_gender(1);
 	set_main_plural("guardias");
   	add_plural("Guardias");
  	set_level(20+random(4));	// el nivel esta para testear. pero metemos lvl 20 para que sea facil matarlos//
   	set_random_stats(14,18);
   	set_str(20);
   	set_dex(23);
   	/* set_guild_ob("/d/gremios/xxx"); el guild */
   	/* set_race_ob("/std/races/xxx"); la raza por determinar */
   	set_long("Es uno de los arqueros que vigilan la fortificacion des de lo alto"
            	" de las murallas. Des de alli divisan los posibles atakes.\n"); 
   	adjust_money(random(2), "gold");
  	// set_xp(400);
	add_clone("/baseobs/weapons/bow", 1); 
   	add_clone("/baseobs/weapons/arrow", 5);
   	add_clone("/baseobs/armours/elfinchain", 1); 
   	add_clone("/baseobs/armours/helmet", 1);
   	add_clone("/baseobs/armours/bracers", 1);
   	this_object()->init_equip();
   	add_move_zone("almenas");
 	set_move_after(1000+random(2), 1000+random(2));
}
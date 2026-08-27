/* Este es un guardia de la puerta del poblado del valle del dragon */

inherit "/obj/monster"; //  falta ver que tiene ese archivo y si esta..... //

void setup()
{
	set_name("guardia");
  	set_short("Guardia de Trior");
  	// set_al(1900);	   // el alin falta concretar dependiendo de la zona que sea. como mas negativo mas angelico//
   	set_gender(1);
 	set_main_plural("guardias");
   	add_plural("Guardias");
  	set_level(30+random(4));	// el nivel esta para testear. pero metemos lvl 20 para que sea facil matarlos//
   	set_random_stats(16,18);
   	set_str(40);
   	set_dex(23);
   	/* set_guild_ob("/d/gremios/xxx"); el guild */
   	/* set_race_ob("/std/races/xxx"); la raza por determinar */
   	set_long("Es un guardia del poblado del Valle del Dragon."
            	"No parece muy temible. Aunque deberias estar atento... "
            	"nunca se sabe. \n");  
   	adjust_money(random(5), "gold");
  	// set_xp(400);
	add_clone("/baseobs/weapons/bastard_sword", 1); 
   	add_clone("/w/jerkat/valle_dragon/item/escudo_trior", 1);
   	add_clone("/baseobs/armours/fullplate", 1); 
   	this_object()->init_equip();
   	add_move_zone("trior"+"mercado_trior");
 	set_move_after(3+random(2), 3+random(2));
}
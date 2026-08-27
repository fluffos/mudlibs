/* Este es un guardia de la puerta del poblado del valle del dragon */

inherit "/obj/monster"; //  falta ver que tiene ese archivo y si esta..... //

void setup()
{
	set_name("guardia");
  	set_short("Guardia");
  	set_al(1900);	   // el alin falta concretar dependiendo de la zona que sea. como mas negativo mas angelico//
   	set_gender(1);
 	set_main_plural("guardias");
   	add_plural("Guardias");
  	set_level(20+random(6));	// el nivel esta para testear. pero metemos lvl 20 para que sea facil matarlos//
   	set_random_stats(14,18);
   	set_str(16);
   	/* set_guild_ob("/d/gremios/xxx"); el guild */
   	/* set_race_ob("/std/races/xxx"); la raza por determinar */
   	set_long("Es un guardia del poblado del Valle del Dragon."
            	"No parece muy temible. Aunque deberias estar atento... "
            	"nunca se sabe. \n");  
   	adjust_money(random(5), "silver");
  	set_xp(400);
	add_clone("/baseobs/weapons/bastard_", 1); 
   	add_clone("/baseobs/armours/large_shield", 1);
   	add_clone("/baseobs/armours/chainmail", 1); 
   	this_object()->init_equip();
}
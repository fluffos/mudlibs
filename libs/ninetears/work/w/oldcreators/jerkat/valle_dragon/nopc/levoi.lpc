inherit "/obj/monster";

 /*  falta ver que tiene ese archivo y si esta..... */

void setup()
{
	set_name("%^ORANGE%^Levoi%^RESET%^");
	add_alias("Levoi");
	add_alias("levoi");
  	set_short("%^ORANGE%^Levoi%^RESET%^");
  	set_al(-100);	   
  	/* el alin falta concretar dependiendo de la zona que sea. como mas negativo mas angelico*/
   	set_gender(1);
 	set_main_plural("%^ORANGE%^Levois%^RESET%^");
 	add_alias("Levois"); 	
  	set_level(14);	
  	/* el nivel esta para testear. pero metemos lvl 20 para que sea facil matarlos */
   	set_random_stats(14,16);
   	set_dex(10);
   	set_wis(100);
   	/* set_guild_ob("/d/gremios/xxx"); el guild */
   	/* set_race_ob("/std/races/xxx"); la raza por determinar */
   	set_long("Es el Gran Anciano del puebo. Su sabiduria es tan grande"
            	"que alcanza todos los confines de todos los reinos. \n");
        adjust_money(random(3), "silver");
  	set_xp(400);
	add_clone("/w/jerkat/valle_dragon/item/manto_levoi", 1); 
      	this_object()->init_equip();
}
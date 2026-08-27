/* Este es un guardia de la puerta del poblado del valle del dragon */

inherit "/obj/monster"; //  falta ver que tiene ese archivo y si esta..... //

void setup()
{
  set_name("habitante");
  set_short("Habitante");
  set_al(0);	  
   /* el alin falta concretar dependiendo de la zona que sea. como mas negativo mas angelico */
  set_gender(random(1));
  set_main_plural("habitantes");
  add_plural("Habitantes");
  set_level(15+random(3));
  /* el nivel esta para testear. pero metemos lvl 20 para que sea facil matarlos */
  set_random_stats(14,18);
  set_str(16);
  set_cha(20);
  /* set_guild_ob("/d/gremios/xxx");  el guild */
  /* set_race_ob("/std/races/xxx");  la raza por determinar */
  set_long("Es un guardia del poblado del Valle del Dragon."
            "No parece muy temible. Aunque deberias estar atento... "
            "nunca se sabe.\n");
  // add_clone("/room/valle_dragon/item/hoz",1); aki hay que akbar la hoz y metersela
  // this_object()->init_equip();
  /* add_clone("/baseobs/armours/xxx",1); meter un escudo, una horca o algo similar y una armadura de cuero */
  adjust_money(random(5)+5,"cooper");
  set_xp(200);
  add_move_zone("poblado_valle");
  set_move_after(20+random(10), 20+random(10));
 
}

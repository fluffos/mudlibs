/* Minero de Minas Zhyrkhom By Shimmer */

      
inherit "/obj/monster";

void setup() {

      set_race("orco"); 
      set_name("minero");
      set_short("minero");
      set_long("Es uno de los mineros orcos que trabajan en las minas de Zhyrkh, "
               "estan constantemente picando la roca para extraer el material.\n");
      add_alias("minero");
      set_main_plural("mineros");
      add_plural("mineros");
      set_gender(1);
      adjust_money(5+random(10), "copper");
      set_level(10);
      add_clone("/d/driade/shimmer/npcs/equipo/pico",1);
      add_clone("/d/driade/shimmer/npcs/equipo/casco_minero",1);
      ::init_equip();

}
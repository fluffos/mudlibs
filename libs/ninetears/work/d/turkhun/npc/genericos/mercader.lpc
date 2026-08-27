#include "/d/turkhun/path.h"
inherit "/obj/monster";
 
void setup()
{
     set_name("mercader");
     set_short("mercader");
     add_alias("mercader");
     set_al(700);
     set_gender(1);
     set_main_plural("Mercaderes");
     add_plural("mercaderes");
     set_level(25+random(6));
     set_random_stats(12,18);
     set_guild("fighter");
     set_guild_ob("/std/guilds/warriors/fighter");
     set_race_ob("/std/races/dwarf");
     set_race("dwarf");
     set_long("Es un traficante de armas venido de lejanas tierras a hacer un buen "
     	      "negocio vendiendo piezas originales para la fabricacion de las armas que "
     	      "cada uno utilizaba en su ciudad de origen.\n");
     load_a_chat(20,
     ({
        1, "'Siempre quise ser un gran guerrero.",
        1, ":se limpia el sudor de la frente.",
     }));
     add_clone(BASEARMOUR+"leather", 1);
     add_clone(BASEWEAPON+"peack", 1);
     add_clone(BASEARMOUR+"cape", 1);
     adjust_money(15+random(5), "gold");
     init_equip();
     add_move_zone("zonaneutral");
     set_move_after(random(5)+1,5+random(15));
     set_kill_xp(10);
}

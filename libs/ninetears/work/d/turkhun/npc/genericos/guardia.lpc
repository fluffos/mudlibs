#include "/d/turkhun/path.h"
inherit "/obj/monster";
#define TIEMPO 5000
 
void setup()
{
     set_name("guardia");
     set_short("Guardia");
     add_alias("enano");
     set_al(0);
     set_gender(1);
     set_main_plural("Guardias");
     add_plural("guardias");
     add_plural("enanos");
     add_plural("guardias");
     set_random_stats(18,20);
     set_str(39);
     set_dex(25);
     set_con(19);
     set_level(40+random(10));
     set_race_ob("/std/races/dwarf");
     set_race("dwarf");
     set_long("Curtido en la batalla, es uno de los pocos supervivientes de la "
     	"gran batalla que asolo dendara en las epocas de paz, salvo la vida de "
     	"milagro y se reunio aqui para esperar un momento de debilidad de Oskuro "
     	"y contraatacar.\n");
     load_a_chat(20,
     ({
        1, "'Como tengo ganas de ponerme a abrir cabezas.",
        1, ":mira a todo el mundo con desconfianza.",
     }));
     add_clone("/baseobs/armours/chainmail",1);
     add_clone(BASEWEAPON+"long_sword", 1);
     add_clone(BASEARMOUR"med_shield",1);
     add_clone(BASEARMOUR+"cape", 1);
     adjust_money(2+random(5), "gold");
     set_aggressive(5);
     init_equip();
     add_move_zone("zonanutral");
     set_move_after(random(5)+1,5+random(15));
     set_kill_xp(10);
}

void attack_by(object atacante)
{
   atacante->add_timed_property("enemigo_turkhun", 1, TIEMPO);
   return ::attack_by(atacante);
}

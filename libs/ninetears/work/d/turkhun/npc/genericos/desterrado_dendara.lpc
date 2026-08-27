#include "/d/turkhun/path.h"
inherit "/obj/monster";
 
void setup()
{
     set_name("caballero");
     set_short("Guardia desterrado de Dendara");
     add_alias("humano");
     add_alias("caballero");
     set_al(0);
     set_gender(1);
     set_main_plural("Guardias desterrados de Dendara");
     add_plural("guardias");
     add_plural("humanos");
     add_plural("caballeros");
     set_random_stats(18,20);
     set_str(39);
     set_dex(25);
     set_con(19);
     set_level(40+random(10));
     set_race_ob("/std/races/human");
     set_race("human");
     set_long("Es un caballero de la guardia de Dendara, su delito fue no ayudar "
     	      "en la defensa de la ciudad, por lo que se le ha declarado persona non-grata "
     	      "en la misma, y expulsado del cuerpo con deshonores.\n");
     load_a_chat(20,
     ({
        1, "'Dadme un escudo y me cargare el mundo!",
        1, ":piensa para si mismo ... sere el mas sangriento para que me reacepten!.",
        1, "berrea: Shakeeesss!!! Necesito mi QuitaPenassss!!!!",
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

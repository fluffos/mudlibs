#include "/d/turkhun/path.h"
inherit "/obj/monster";
 
void setup()
{
     set_name("capitan");
     set_short("Capitan desterrado de Takome");
     add_alias("humano");
     add_alias("capitan");
     set_al(0);
     set_gender(1);
     set_main_plural("Capitanes desterrados de Takome");
     add_plural("guardias");
     add_plural("humano");
     add_plural("capitanes");
     set_random_stats(18,20);
     set_str(39);
     set_dex(25);
     set_con(19);
     set_level(40+random(10));
     set_race_ob("/std/races/human");
     set_race("human");
     set_long("Es un fornido ex-capitan de la guardia de Takome, su delito fue no ayudar "
     	      "en la defensa de la ciudad, por lo que se le ha declarado persona non-grata "
     	      "en la misma, y expulsado del cuerpo con deshonores.\n");
     load_a_chat(20,
     ({
        1, "'Como vea un palata lo abro en canal!!",
        1, ":piensa para si mismo ... Un dia matare a ese Rey que me deshonro!!.",
        1, "'Odio Takome! Odio Takome! Odio Takome! LO ODIOOOOO!!!!!!!.",
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

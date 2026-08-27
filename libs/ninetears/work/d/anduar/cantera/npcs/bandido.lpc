#include "path.h"
inherit "/obj/monster";
int i;

void setup()
{
   set_name("bandido");
   set_short("bandido");
   set_al(900);
   set_gender(1);
   set_main_plural("bandidos");
   add_plural("bandidos");
   set_level(10+random(2));
   set_random_stats(12,17);
   set_cha(10+random(7));
   set_guild_ob("/std/guilds/rogues/assassin");
   set_race_ob("/std/races/human");
   set_long("Es un bandido de los muchos que se pueden encontrar en esta "
            "zona. Se gana la vida asaltando a las personas y robandole "
            "todas sus pertenencias, y si alguien se niega a darselas no "
            "vacilara en matarle.\n");
   load_chat(20,
   ({
      1, "'La bolsa o la vida, decidid vos lo que mas precieis",
      1, ":mira el tamanyo de tu bolsillo.",
   }));
   add_clone("/baseobs/weapons/dagger", 1);
   add_clone("/baseobs/armours/leather", 1);
   add_clone("/baseobs/armours/cloak", 1);
   adjust_money(random(60), "silver");
   init_equip();
}

void init()
{
   add_timed_property("guardias_anduar", 1, 4000000);
   ::init();
}

void event_enter(object quien, string mensaje, object donde)
{
   if (quien->query_corpse()) call_out("coger1", 2);
   ::event_enter(quien, mensaje, donde);
}

void coger1()
{
   i=10;
   do_command("coger todo de cuerpos");
   call_out("coger2", 8);
}

void coger2()
{
   do_command("get all");
   call_out("run_away", 2);
}


// Panadero
// Freezer 11-8-97

inherit "/obj/monster";

void setup()
{
      object objeto;
      set_name("panadero");
      set_short("El panadero");
      set_main_plural("panaderos");
      set_al(60);
      set_gender(1);
      add_alias("elf");
      add_alias("elfo");
      set_race_ob("/std/races/elf");
      set_wimpy(0);
      set_random_stats(14, 18);
      set_cha(14+random(4));
      set_level(10+random(8));
      set_long("Es un elfo panadero. De los pocos elfos que has visto en "
               "la ciudad. Es alto, delgado y lleva un delantal bastante "
               "sucio. Esta esperando que le pidas algo.\n");
      adjust_money(random(100), "silver");
      set_aggressive(0);
      load_chat(30,
         ({
               1, "'Deseais algo, senyor?.",
               1, ":saca del horno unos panes recien hechos.",
               1, ":te mira con desconfianza.",
          }));

}/*setup*/

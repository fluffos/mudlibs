/* Shimmer 2002 */


#define CREATOR "shimmer"

inherit "/obj/monster";

void setup() {
      object objeto;
      set_name("banquero");
      set_short("el banquero");
      set_al(-60);
      set_gender(1);
      set_main_plural("banqueros");
      add_alias("orco");
      set_race_ob("/std/races/orco");
      set_wimpy(10);
      set_random_stats(15, 18);
      set_level(10+random(3));
      set_long("Es un banquero orco, trabaja en el banco atendiendo a los clientes, "
                "esta todo el rato de un lado para otro cubriendo impresos y moviendo el dinero que estos sacan e ingresan.\n");
      adjust_money(random(5), "platinum");
      set_aggressive(0);
      load_chat(30,
         ({
               1, "'De uno en uno, por favor!!",
               1, ":juguetea con una pluma de escribir.",
               1, ":te mira de forma indiferente.",
               1, ":cubre unos impresos..",
               1, ":se asusta al fijarse en ti.",
          }));

      add_clone("/baseobs/weapons/dagger",1);
}

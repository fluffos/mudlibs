/* By Shimmer */

#define CREATOR "shimmer"

#include "../../../path.h"

inherit "/std/object";

void setup()
{
   set_name("pocion azul");
   set_short("Pocion %^BOLD%^BLUE%^Azul%^RESET%^");
   add_alias("pocion azul");
   add_alias("azul");
   add_alias("pocion");
   set_long("Son varias hojas de alguna extranya planta formando una especie de recipiente que contiene un liquido viscoso y azulado.\n");
   set_main_plural("Pociones %^BOLD%^BLUE%^Azules%^RESET%^");
   add_plural("pociones azules");
   add_plural("pociones");
   add_plural("azules");

   set_weight(25);
   set_value(12000);

}

void init()
{
   ::init();
   add_action("do_comer", "com*er");
   add_action("do_comer", "beb*er");
   add_action("do_comer", "tomar");
}

void do_comer(string str)
{
   if (!str) return 0;
   if (str!=this_object()->query_name()) return 0;
   
   write("Coges entre tus manos las hojas y sorbes cuidadosamente el contenido viscoso, notas como tu cuerpo reacciona cuando absorve la pocion "
         "y te son restaurados unos cuantos puntos de guild.\n");
   tell_room(environment(this_player()), this_player()->query_cap_name()+
             " coge entre sus manos unas cuantas hojas y se bebe su contenido.\n",
             ({this_player()}));
   this_player()->adjust_gp(20+random(10));
   this_object()->dest_me();
   return 1;
}

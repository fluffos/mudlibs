/* By Shimmer */

#define CREATOR "shimmer"

#include "../../../path.h"

inherit "/std/object";

void setup()
{
   set_name("pocion roja");
   set_short("Pocion %^BOLD%^RED%^Roja%^RESET%^");
   add_alias("pocion roja");
   add_alias("roja");
   add_alias("pocion");
   set_long("Son varias hojas de alguna extranya planta formando una especie de recipiente que contiene un liquido viscoso y de color morado.\n");
   set_main_plural("Pociones %^BOLD%^RED%^Rojas%^RESET%^");
   add_plural("pociones rojas");
   add_plural("pociones");
   add_plural("rojas");

   set_weight(25);
   set_value(9000);

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
         "curando algunas de tus heridas.\n");
   tell_room(environment(this_player()), this_player()->query_cap_name()+
             " coge entre sus manos unas cuantas hojas y se bebe su contenido.\n",
             ({this_player()}));
   this_player()->adjust_hp(20+random(10));
   this_object()->dest_me();
   return 1;
}

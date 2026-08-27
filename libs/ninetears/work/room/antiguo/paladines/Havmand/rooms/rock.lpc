#include "path.h"
inherit "/std/outside";

create()
{
   ::create();
add_property("no_undead",1);
    set_light(LIGHT);
   set_short("Isla de Havmand: Rocas.");
    set_night_long("\nIsla de Havmand : Rocas\n\n"
    "   Apenas puedes vislumbrar el vago contorno de las rocas, aunque si te "
    "das cuenta que son muy afiladas, por lo que debes moverte con cuidado "
    "en esta zona. "
    "\n\n");
    add_smell("aire","El aire esta cargado del caracteristico olor a sal y a mar.\n");
    add_item(({"roca","rocas"}),"Son rocas de afiladas aristas, su origen es volcanico, "
    "lo que te recuerda que esta isla fue antes un volcan en erupcion.\n");
    add_feel("rocas","Al tocar la roca notas lo cortante y peligrosas que pueden llegar a ser.\n");
   add_item("mar","Miras la inmensidad del mar Sword, el mas grande de todos los "
      "reinos.\n");
    add_item("gotas","Finisimas gotas saltan por el aire cuando las olas se estrellan "
    "contra las rocas.\n");
    add_taste("aire","El aire es muy salado por la proximidad del mar.\n");
    add_property("no_undead",1);

   this_object()->setup();
   ::reset();
}
void dest_me()
{
    ::dest_me();
}

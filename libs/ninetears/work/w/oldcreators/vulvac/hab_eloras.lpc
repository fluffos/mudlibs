// Habitante de Eloras. Gestur'98.
#include "path.h"

inherit "/obj/monster";

void setup()
{
   object objeto;
   set_name("habitante");
   set_short("habitante de Eloras");
   set_al(-100);
   set_gender(random(2)+1);
   set_main_plural("habitantes de Eloras");
   add_plural("habitantes");
   set_race_ob("/std/races/human");
   set_random_stats(10, 14);
   set_cha(10+random(4));
   set_level(2+random(5));     
   set_long("Es uno de los pocos ciudadanos que habitan eloras. Se "
   "trata de un"+(query_gender()==1?" hombre ":"a mujer ")+" de aspecto "
   "fornido y estatura mediana. Lo mas seguro que este cultivando el "
   "campo.\n");
            
   set_aggressive(0);
   load_chat(30,
      ({
            1, "'Me gusta esta paz y tranquilidad",
            1, "'De vez en cuando solemos practicar montanyismo.",
       }));
       
   objeto=new("/baseobs/weapons/quarterstaff");
   objeto->move(this_object());
   objeto=new("/baseobs/armours/cape");
   objeto->move(this_object());
   this_object()->init_equip();
}/*setup*/

#include "emote_quest.h"

inherit CATACUMBAS+"sala";

void setup()
{
   modify_item("lapidas", "Son las tipicas lapidas que suele haber en "
   "las tumbas... a diferencia de una que tiene un aspecto diferente.\n");
   
   add_item("lapida", "Es una lapida hecha de un material diferente a "
   "las demas. Parece metalica, y alrededor suyo hay menos polvo y musgo que "
   "las otras. Ademas en el suelo hay unas marcas que giran en sentido "
   "circular.\n");
}

void init()
{
   ::init();
   add_action("do_mover", "mover");
   add_action("do_mover", "mueve");
   add_action("do_girar", "gira*r");
}

void do_mover(string lapida)
{
   if (!lapida)
   {
      this_player()->notify_fail("Mover que?\n");
      return 0;
   }
   
   if (lapida!="lapida") return 0;
   
   tell_object(this_player(), "Intentas mover la lapida con todas tus "
   "fuerzas, pero no se mueve hacia ningun lado.\n");

   tell_room(this_object(), this_player()->query_cap_name()+ " intenta "
   "mover una lapida, pero desiste.\n", this_player());

   return 1;      
}

void do_girar(string lapida)
{
   if (!lapida)
   {
      notify_fail("Girar que?\n");
      return 0;
   }
   
   if (lapida!="lapida") return 0;
   
   if (!QUEST_HANDLER->puerta_abierta() && !query_property("lapida"))
   {   
      tell_object(this_player(), "Empiezas a girar la lapida y observas "
      "asombrado que sigue girando sola hasta llegar a los 90 grados.\n");
   
      tell_room(this_object(), this_player()->query_cap_name()+ " empieza a "
      "girar una lapida ves como esta sigue girando.\n", this_player());

      call_out("abrir_puerta", 4);
      
      add_timed_property("lapida", 10, 1);
            
      return 1;
   }
   else
   {
      notify_fail("No puedes girar la lapida por mucho que lo "
      "intentas.\n");
      return 0;
   }
}

void abrir_puerta()
{
   QUEST_HANDLER->eco("un gran estruendo.\n");
   call_out("abrir_puerta_2", 4);
}

void abrir_puerta_2()
{
   QUEST_HANDLER->abrir_puerta();
}

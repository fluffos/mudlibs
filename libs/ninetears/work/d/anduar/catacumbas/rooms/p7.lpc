#include "path.h"
#include "emote_quest.h"

inherit CATACUMBAS+"secreto";

void setup()
{
   set_short("%^BLUE%^Pasillo secreto%^RESET%^");
   CATADESC->desc(5, this_object());
   add_exit("norte", CATACUMBAS+"p6", "corridor");
}

void init()
{
   ::init();
   add_action("mover_antorcha", "mover");
   add_action("mover_antorcha", "empuja*r");
   add_action("mover_antorcha", "tira*r");
}

void mover_antorcha(string str)
{
   if (!str)
   {
      notify_fail(capitalize(query_verb())+" que?\n");
      return 0;
   }
   if (str!="antorcha")
   {
      return 0;
   }
   if (!QUEST_HANDLER->puerta_abierta() && !query_property("antorcha"))
   {
      tell_object(TP, "Mueves la antorcha y oyes como si "
      "hubieras activado un resorte.\n");
      tell_room(TO, TP->query_cap_name()+" mueve una antorcha y oyes como si "
      "hubiera activado un resorte.\n", TP);
      QUEST_HANDLER->abrir_puerta();
      add_timed_property("antorcha", 10, 1);
   }
   else
   {
      tell_object(TP, "No puedes mover la antorcha por mucho que lo "
      "intentas.\n");
      tell_room(TO, TP->query_cap_name()+" intenta mover la antorcha sin "
      "mucho exito.\n");
   }
   return 1;
}

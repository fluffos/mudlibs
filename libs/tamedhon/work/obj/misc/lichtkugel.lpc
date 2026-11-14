inherit "std/thing";

#include <properties.h>

void create()
{
   ::create();
   SetProp(P_SHORT, "Eine leuchtende Kugel");
   SetProp(P_LONG, "Eine ziemlich normale Kugel, die magisch leuchtet.\n");
   SetProp(P_NAME, "Lichtkugel");
   SetProp(P_GENDER, 2);
   AddId(({"kugel", "lichtkugel", "leuchtende kugel"}));
   SetProp(P_WEIGHT, 0);
   SetProp(P_VALUE, 0);
   SetProp(P_LIGHT, 1);
}

void start_remove(mixed zeit)
{
   call_out("weg", zeit);
}

void weg()
{
   if (living(environment()))
      tell_object(environment(), "Die Lichtkugel löst sich auf.\n");
   else
      tell_room(environment(), "Die Lichtkugel löst sich auf.\n");
   remove();
}

// Test of adding clients to weather server

#include <nightday.h>
#include <properties.h>

inherit "/std/room";

void my_fisherman_callout()
{
   return;
}

varargs void create()
{
   ::create();
   Set(P_INDOORS, 0);

   SetIntShort("nice room");
   SetIntLong("Just a test of the emergency client notification system.\n");
   NIGHTDAY->AddClient(this_object());
}

mixed FilterWeatherData(object client, mixed *data, int newstate)
{
   if( newstate == ND_NIGHT )
   {
      call_out( "my_fisherman_callout", 20);
      dtell("tune", "got state change\n");
   }

   return ::FilterWeatherData( client, data, newstate);
}

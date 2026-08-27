#include "path.h"

inherit "/std/room.c";

void setup()
{
   set_short("");

   set_long("");

   set_light();

   add_item ("","");
   add_item (({"",""}),"");

   add_sound("","");

   add_clone(NPC+"",1);

   add_exit("",+"","");
   add_exit("",+"","");   

}




void init()
{
   ::init();
   add_action("accion",({"",""}));
}

int accion(string str)
{
   if(str == "" )
   {
      write("");

      say(this_player()->query_cap_name()+" .\n");
      
      add_item("","");

      return(1);
   }
   notify_fail("\n");
   return(0);

}

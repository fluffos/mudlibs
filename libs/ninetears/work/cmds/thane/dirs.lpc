#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;
#define PEOPLER "/obj/handlers/peopler"

void setup()
{

 position = 1;
}



int cmd(string str, object me) {
   if(!this_player()->query_thane() && !this_player()->query_lord() && !this_player()->query_god())
   {
      write("El uso de este comando esta restringido para tu rango.\n");
      return 1;
   }
  return (int)PEOPLER->do_dirs(str);
} /* do_dirs() */


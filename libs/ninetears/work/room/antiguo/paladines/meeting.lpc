inherit "/std/room";
#include "path.h"

void setup() {
  set_short("Habitacion del %^BOLD%^WHITE%^Consejo.%^RESET%^\n\n");
  set_light(60);
   set_long("Habitacion del %^BOLD%^WHITE%^Consejo.%^RESET%^\n\nYou are seated in a Great Hall around the fabled Round Table.\n"+
  "Gathered around you are other mighty heroes from across the"+
    " realms.  At the head of the chamber is a HUGE throne for Timion, God"+
   " of the Fighters.\nThere is a list here.\n\n");
  add_item("lista","Escribe 'leer lista' para leer la lista, y 'anyadir <nombre>' para anyadir un nombre a la lista.\n");
  add_exit("abajo", "/room/paladines/hall","stairs");
}

write_list(arg)
{
 
  if(!(this_player()->query_guild_ob()=="/d/gremios/guerreros/paladin"))
   {
    write("No eres un guerrero! LARGATE!");
    return 1;
   }
 if(!arg)
   {
    write("Sintaxis:  anyadir <pj>");
    return 1;
   }


  if((this_player()->query_level()>=10 || ((string)(this_player()->query_guild_ob()) !=
        "/d/gremios/guerreros/paladin")))
{
    write("Ok, "+arg+" anyadido.\n");
   write_file("/room/paladines/list.txt","%^BOLD%^WHITE%^MATAR A:  %^BOLD%^RED%^"+arg+"\t%^WHITE%^REPUDIADO POR: %^GREEN%^"+this_player()->query_cap_name()+".\n");
}
 else
  write("Eres demasiado pequenyo como para escribir en la lista. Se requiere nivel 11 o superior.\n");
  return 1;
}
 
exa_list(arg)
{
 if(!arg)
  {
    write("Sintaxis:  leer lista\n");
    return 1;
   }
 if(!(arg=="lista"))
  return 0;
 write("\n%^BOLD%^WHITE%^POR CRIMENES CONTRA EL GUILD DE LOS PALADINES: \n"+
	 "%^BOLD%^WHITE%^----------------------------------------------\n"+read_file("/room/paladines/list.txt"));

 return 1;
}
 
void init()
{
 add_action("write_list","anyadir");
 add_action("exa_list","leer");
 ::init();
}

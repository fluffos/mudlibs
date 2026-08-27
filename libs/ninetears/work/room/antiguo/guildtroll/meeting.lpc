inherit "/std/room";
#include "path.h"
#include "config.h"
void setup() {
  set_short(MEETINGTITLE+"\n\n");
  set_light(60);
   set_long(MEETINGTITLE+"\nTe encuentras en la habitacion destinada a los consejeros del guild, aqui entre otras cosas "
	"se matiene una lista de enemigos del mismo.\n\n");
  add_item("lista","Escribe 'leer lista' para leer la lista, y 'anyadir <nombre>' para anyadir un nombre a la lista.\n");
  add_exit("abajo", ROOMS+"hall","stairs");
}

write_list(arg)
{
 
  if(!(this_player()->query_guild_ob()==GUILDOWNER))
   {
    write("No perteneces a este guild! LARGATE!");
    return 1;
   }
 if(!arg)
   {
    write("Sintaxis:  anyadir <pj>");
    return 1;
   }


  if((this_player()->query_level()>=10 || ((string)(this_player()->query_guild_ob()) !=
        GUILDOWNER)))
{
    write("Ok, "+arg+" anyadido.\n");
   write_file(ROOMS+"list.txt","%^BOLD%^WHITE%^MATAR A:  %^BOLD%^RED%^"+arg+"\t%^WHITE%^REPUDIADO POR: %^GREEN%^"+this_player()->query_cap_name()+".\n");
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
 write("\n%^BOLD%^WHITE%^POR CRIMENES CONTRA EL GUILD: \n"+
	 "%^BOLD%^WHITE%^----------------------------------------------\n"+read_file(ROOMS+"list.txt"));

 return 1;
}
 
void init()
{
 add_action("write_list","anyadir");
 add_action("exa_list","leer");
 ::init();
}

inherit "/std/room";
#include "definepage.h"

void setup() {
  	set_short(MEETINGTITLE);
   	set_long(MEETINGTITLE+"Estas en la habitacion destinada a los consejeros del gremio. Aqui entre otras cosas se mantiene una lista negra donde figuran los enemigos del mismo.\n\n");
  	add_item(({"lista","lista negra"}),"Escribe \"leer lista\" para leer la lista negra, \"repudiar <nombre>\" para anyadir un nombre a ella y \"borrar <nombre>\" para borrarle de la misma.\n");
  	add_exit(FU, GUILDDIR"hall","door");
	}
	
void init() {
 	add_action("inscribir","repudiar");
 	add_action("lectura","leer");
 	add_action("borrar","borrar");
 	::init();
	}


int inscribir(string arg) {
 	object repudiado;
 	if(this_player()->query_guild_ob()!=GUILDOWNER) return notify_fail("No perteneces a este gremio! FUERA!");
 	if(!arg) return notify_fail("Sintaxis:  anyadir <nombre>");
   	if(TP->query_level()<10) return notify_fail("Eres demasiado pequenyo como para escribir en la lista. Se requiere nivel 10 o superior.\n");
   	if(!find_living(arg)) return notify_fail(capitalize(arg)+" no esta conectado.\n");
   	repudiado=find_living(arg);
   	if(repudiado->query_guild_ob()==GUILDOWNER) return notify_fail("No puedes repudiar a tus companyeros de gremio.\n");
  	if(repudiado->query_property("repudiado_barbaroscaos")) return notify_fail(capitalize(arg)+" ya esta en la lista negra.\n");
  	
   	repudiado->add_property("repudiado_barbaroscaos",1);
	tell_object(TP,"Ok, "+arg+" anyadido.\n");
   	write_file(GUILDDIR"list.txt","%^BOLD%^WHITE%^MATAR A:  %^BOLD%^RED%^"+capitalize(arg)+"\t%^WHITE%^REPUDIADO POR: %^GREEN%^"+TP->query_cap_name()+".\n");
   	return 1;
	}
	
int borrar(string arg) {
 	object perdonado;
 	if(this_player()->query_guild_ob()!=GUILDOWNER) return notify_fail("No perteneces a este gremio! FUERA!");
 	if(!arg) return notify_fail("Sintaxis:  borrar <nombre>");
   	if(TP->query_level()<10) return notify_fail("Eres demasiado pequenyo como para escribir en la lista. Se requiere nivel 10 o superior.\n");
   	if(!find_living(arg)) return notify_fail(capitalize(arg)+" no esta conectado.\n");
   	perdonado=find_living(arg);
   	if(!perdonado->query_property("repudiado_barbaroscaos")) return notify_fail(capitalize(arg)+" no esta en la lista negra.\n");
  	
   	perdonado->remove_property("repudiado_barbaroscaos");
	tell_object(TP,"Ok, "+arg+" borrado.\n");
   	write_file(GUILDDIR"list.txt","%^BOLD%^RED%^"+capitalize(arg)+"\t%^WHITE%^PERDONADO POR: %^GREEN%^"+TP->query_cap_name()+".\n");
   	return 1;
	}	
 
int lectura(string arg) {
 	if(!arg) return notify_fail("Sintaxis:  leer lista\n");
   	if(arg!="lista") return 0;
 	tell_object(TP,"\n%^BOLD%^WHITE%^POR CRIMENES CONTRA EL GUILD: \n%^BOLD%^WHITE%^----------------------------------------------\n"+read_file(GUILDDIR"list.txt"));
	return 1;
	}
 

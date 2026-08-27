//Gareth 7.12.02

#include "/d/gremios/path.h"
inherit "/std/guildroom";

void setup() {
	set_short("%^RED%^%^BOLD%^Gremio de los Guerreros Turkhun%^RESET%^");
	set_long(query_short()+"\n\n    En esta espaciosa sala los Guerreros Turkhun "
					"mejoran sus tecnicas de combate bajo la "
					"supervision de Darejan el Maestro. Unas "
					"escaleras descienden hacia la Herreria"
					", mientras que al norte se encuentran"
					" el resto de salas del gremio.\n");
	
	set_guild("turkhun");
	set_guildmaster(NPCS+"darejan");
	
    	add_exit("abajo",GUILD_TURKHUN"herreria","corridor");
	add_exit("norte",GUILD_TURKHUN+"tablon","corridor");
	add_exit("sur",GUILD_TURKHUN+"hall","door");
	modify_exit("norte",({"function","chekeo"}));
	modify_exit("abajo",({"function","chekeo"}));
    }
    
int chekeo() {
    if(TP->query_guild()=="turkhun"||!TO->query_guildmaster()) return 1;
    return notify_fail("El Guildmaster no te permite adentrarte en el gremio.\n");
    }

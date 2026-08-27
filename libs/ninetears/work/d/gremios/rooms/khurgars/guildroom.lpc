//Gareth 7.12.02

#include "/d/gremios/path.h"
inherit "/std/guildroom";

void setup() {
	set_short("%^RED%^%^BOLD%^Gremio de los Khurgars%^RESET%^");
	set_long(query_short()+"\n\n    En esta espaciosa sala los Khurgars "
					"mejoran sus tecnicas de combate bajo la "
					"supervision de Tharak el Maestro. Unas "
					"escaleras descienden hacia la Herreria"
					", mientras que al norte se encuentran"
					" el resto de salas del gremio.\n");
	
	set_guild("khurgar");
	set_guildmaster(NPCS+"tharak");
	
	add_sign("Un tablon de madera, con unas letras escritas.\n", 
		 "________________________________\n"
		 "|      GUERREROS KHURGARS      |\n"
		 "|                              |\n"
		 "| -- Si quieres unirte al      |\n"
		 "|    gremio usa 'alistarse'.   |\n"
		 "| -- Para mas informacion del  |\n"
		 "|    gremio usa 'info'.        |\n"
		 "|______________________________|\n","Cartel","cartel");
	
    	add_exit("abajo",GUILD_KHURGARS"herreria","corridor");
	add_exit("norte",GUILD_KHURGARS+"tablon","corridor");
	add_exit("sur",GUILD_KHURGARS+"hall","door");
    }
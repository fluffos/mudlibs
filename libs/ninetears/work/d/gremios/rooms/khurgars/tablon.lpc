//Gareth 7.12.02

#include "/d/gremios/path.h"
inherit "/std/room";
object board;

void setup() {
	set_short("%^RED%^%^BOLD%^Gremio de los Khurgars: %^WHITE%^%^BOLD%^Tablon de Notas%^RESET%^");
	set_long(query_short()+"\n\n    Te encuentras en una habitacion cuadrada "
					"donde los Khurgars informan a los demas"
					" miembros de cualquier cosa referente al gremio. "
					"Dos gruesas puertas de acero al norte conducen a"
					" los baules del gremio, donde los miembros "
					"pueden depositar o adquirir equipo.\n");
	
	add_clone("/obj/misc/board");
	add_exit("noreste",GUILD_KHURGARS+"armeria","door");
	add_exit("noroeste",GUILD_KHURGARS+"newbie","door");
	add_exit("sur",GUILD_KHURGARS+"guildroom","corridor");
}

void reset () {
	if (!board) {
		board=clone_object("/obj/misc/board");
		board->move(TO);
		board->set_datafile("notas_khurgars");
	}	
}
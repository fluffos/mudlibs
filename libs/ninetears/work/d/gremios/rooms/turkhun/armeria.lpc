//Gareth 7.12.02

#include "/d/gremios/path.h"
inherit "/std/vaults/vault_room";

void setup () {
	::setup();
  	set_saqueable(0);
    	set_short("%^RED%^%^BOLD%^Gremio de los Guerreros Turkhun: %^WHITE%^%^BOLD%^Baul%^RESET%^");
  	set_long(query_short()+"\n\n    Te encuentras en una pequenya sala sin muebles ni"
  					" ningun tipo de decoracion, excepto un gran baul"
  					" al final. En este baul los miembros del gremio "
  					"pueden depositar o cojer todo tipo de armas y equipo."
  					" El baul esta protegido por una gruesa puerta de acero.\n\n");
  	
  	add_item("baul","Un gran baul de madera muy lisa y sin imperfecciones, con una gran cerradura de acero.\n");
  	add_item("puerta","Una gruesa puerta de acero que protege la entrada a la sala.\n");
  	
  	add_exit("sudoeste",GUILD_TURKHUN+"tablon","door");
}
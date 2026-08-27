/* domain administration room */
#include "access.h"
#include "path.h"
inherit "/std/room";
#define MASTER "/secure/master"

void setup() {
  
  set_light(100);
  set_short("Habitacion de Creacion de Temas de Ayuda");
  set_long("You float in the empty wastes of the ethereal plane. "
    "In all directions stars twinkle in the black " 
    "curtain of space, just lying there avaiting your creative hand "
    "for being developed.\n" 
"Available commands:\n"
"  crear path fichero           : Crea ayuda a partir de un fichero.\n"
"  crehelp path fichero         : Crea ayuda para Inmortales.\n\n");
  seteuid("Root");
} /* setup() */

void init() {
  ::init();
  add_action("crear", "crear", 10);
  add_action("crehelp", "crehelp", 10);
} /* init() */

int crear(string str) {
	string fich;

	if (!str) {
		notify_fail("Uso : crear path fichero\n");
		return 0;
	}
	if (!TP->query_god() && !TP->query_lord()) {
		notify_fail("No tienes permisos.\n");
		return 0;
	}
	sscanf(str, "%s %s", str, fich);
	if (!fich) {
		notify_fail("Uso : crear path fichero\n");
		return 0;
	}
	write("Creando ayuda "+str+"/"+fich+".\n");
	"/obj/handlers/nroff"->create_help(str,fich);
	return 1;
}

int crehelp(string str) {
	string fich;

	if (!str) {
		notify_fail("Uso : crehelp path fichero\n");
		return 0;
	}
	if (!TP->query_god() && !TP->query_lord()) {
		notify_fail("No tienes permisos.\n");
		return 0;
	}
	sscanf(str, "%s %s", str, fich);
	if (!fich) {
		notify_fail("Uso : crehelp path fichero\n");
		return 0;
	}
	write("Creando ayuda "+str+"/"+fich+".\n");
	"/obj/handlers/nroff"->create_chelp(str,fich);
	return 1;
}


/* domain administration room */
#include "access.h"
inherit "/std/room";
#define MASTER "/secure/master"

void setup() {
  	set_short("Despacho de control de %^MAGENTA%^Patronajes y Regencias%^RESET%^");
  	set_long(query_short()+"\nEn este despacho los Inmortales de alto grado reparten tareas tales como Regencias y Patronajes entre los inmortales que se lo ganen.\n"
		"Comandos:\n"
		"  %^YELLOW%^regente%^RESET%^ORANGE%^ <ciudad>             %^RESET%^: Muestra el regente de una ciudad.\n"
		"  %^YELLOW%^patron%^RESET%^ORANGE%^ <gremio>              %^RESET%^: Muestra el patron de un gremio.\n"
		"  %^YELLOW%^regencia%^RESET%^ORANGE%^ <regente> <ciudad>  %^RESET%^: Asigna una regencia.\n"
		"  %^YELLOW%^patronaje%^RESET%^ORANGE%^ <patron> <gremio>  %^RESET%^: Asigna un patronaje.\n");
	add_exit("arriba","/d/heaven/admin2","stair");
  	seteuid("Root");
	} /* setup() */

void init() {
  	::init();
  	add_action("regente", "regente");
  	add_action("patron", "patron");
	add_action("regencia","regencia");
	add_action("patronaje","patronaje");
	} /* init() */

int regente(string arg) {
	string ret;
  	if(!arg) return notify_fail("Uso:   regente <ciudad>\n");
	ret="/d/ciudades/master"->query_regente(arg);
	if(!ret||ret=="") return notify_fail("No existe esa ciudad.\n");
	tell_object(TP,"El regente de "+CAP(arg)+" es "+CAP(ret)+".\n");
	return 1;
	}

int patron(string arg) {
	string ret;
  	if(!arg) return notify_fail("Uso:   patron <gremio>\n");
	ret="/d/gremios/master"->query_patron(arg);
	if(!ret||ret=="") return notify_fail("No existe ese gremio.\n");
	tell_object(TP,"El patron de "+CAP(arg)+" es "+CAP(ret)+".\n");
	return 1;
	}

int regencia(string arg) {
  	string reg, regt;

  	if (this_player() != this_player(1)) return 0;
  	if(!arg) return notify_fail("Uso:   regencia <regente> <ciudad>\n");

  	if(!((MASTER->high_programmer(geteuid(previous_object()))) && (previous_object()->query_god()))) return notify_fail("Tu no puedes asignar regencias.\n");

  	if(sscanf(arg, "%s %s", regt, reg) != 2) {
    		reg = arg;
    		regt = (string)this_player()->query_name();
  	} else regt = (string)this_player()->expand_nickname(regt);

	"/d/ciudades/master"->add_regencia(regt,reg);

  	tell_object(TP,"Asignas la Regencia de " + capitalize(reg) + " a " + capitalize(regt) + ".\n");
  	return 1;
	}

int patronaje(string arg) {
  	string reg, regt;

  	if (this_player() != this_player(1)) return 0;
  	if(!arg) return notify_fail("Uso:   patronaje <patron> <gremio>\n");

  	if(!((MASTER->high_programmer(geteuid(previous_object()))) && (previous_object()->query_god()))) return notify_fail("Tu no puedes asignar patronajes.\n");

  	if(sscanf(arg, "%s %s", regt, reg) != 2) {
    		reg = arg;
    		regt = (string)this_player()->query_name();
  	} else regt = (string)this_player()->expand_nickname(regt);

	"/d/gremios/master"->add_patronaje(regt,reg);

  	tell_object(TP,"Asignas el Patronaje de " + capitalize(reg) + " a " + capitalize(regt) + ".\n");
  	return 1;
	}


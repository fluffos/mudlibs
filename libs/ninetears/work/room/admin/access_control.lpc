/* domain administration room */
#include "access.h"
inherit "/std/room";
#define MASTER "/secure/master"

object board;

void setup() {
 	set_short("Oficina de %^BLUE%^BOLD%^Permisos%^RESET%^");
  	set_long(query_short()+"\nDesde esta oficina se administran los permisos de lectura/escritura de los Inmortales en los directorios del Mud, mediante una serie de comandos que permiten a aquellos Inmortales autorizados dar o quitar permisos segun crean conveniente.\n"
		"Comandos:\n"
		"  %^YELLOW%^lectura %^RESET%^ORANGE%^<creador> <ruta>         %^RESET%^: Da permiso de lectura.\n"
		"  %^YELLOW%^escritura %^RESET%^ORANGE%^<creador> <ruta>       %^RESET%^: Da permiso de escritura.\n"
		"  %^YELLOW%^administrador %^RESET%^ORANGE%^<creador> <ruta>   %^RESET%^: Permite administrar el directorio.\n"
		"  %^YELLOW%^dlectura %^RESET%^ORANGE%^<creador> <ruta>        %^RESET%^: Quita el permiso de lectura.\n"
		"  %^YELLOW%^descritura %^RESET%^ORANGE%^<creador> <ruta>      %^RESET%^: Quita el permiso de escritura.\n"
		"  %^YELLOW%^dadministrador %^RESET%^ORANGE%^<creador> <ruta>  %^RESET%^: Impide administrar el directorio.\n"
		"  %^YELLOW%^sumario %^RESET%^ORANGE%^[ruta]                   %^RESET%^: Muestra los permisos.\n"
		"Se ha habilitado un tablon por si necesitais un permiso y no hay nadie capaz de daroslo conectado.\n");
	add_exit("fuera","/d/heaven/admin3","door");
  	seteuid("Admin");
	} /* setup() */

void init() {
  	::init();
  	add_action("do_read", "lectura");
  	add_action("do_write", "escritura");
  	add_action("do_grant", "administrador");
  	add_action("do_noread", "dlectura");
  	add_action("do_nowrite", "descritura");
  	add_action("do_nogrant", "dadministrador");
  	add_action("do_summary", "sumario");
	} /* init() */

int do_read(string str) {
  	string euid, path, eu;

  	if (this_player() != this_player(1)) return 0;
  	if (!str||sscanf(str, "%s %s", euid, path) != 2) return notify_fail("Uso: "+query_verb()+" <creador> <ruta>\n");

  	path = (string)this_player()->get_path(path);
  	if (!"/secure/master"->high_programmer((eu = geteuid(previous_object()))) && !"/secure/master"->check_permission(eu, path, 4)) return notify_fail("No tienes los privilegios necesarios para dar permisos de lectura en esa ruta.\n");
	if(!"/secure/master"->add_read_permission(euid, path)) return notify_fail("Algo ha ido mal.\n");
  	return 1;
	} /* do_read() */

int do_write(string str) {
  	string euid, path, eu;

  	if (this_player() != this_player(1)) return 0;
  	if (!str||sscanf(str, "%s %s", euid, path) != 2) return notify_fail("Uso: "+query_verb()+" <creador> <ruta>\n");

  	path = (string)this_player()->get_path(path);
  	if (!"/secure/master"->high_programmer((eu = geteuid(previous_object()))) && !"/secure/master"->check_permission(eu, path, 4)) return notify_fail("No tienes los privilegios necesarios para dar permisos de escritura en esa ruta.\n");

  	notify_fail("Algo ha ido mal.\n");
  	return (int)"/secure/master"->add_write_permission(euid, path);
	} /* do_write() */

int do_grant(string str) {
  	string euid, path, eu;

  	if (this_player() != this_player(1)) return 0;
  	if (!str||sscanf(str, "%s %s", euid, path) != 2) return notify_fail("Uso: "+query_verb()+" <creador> <ruta>\n");

  	path = (string)this_player()->get_path(path);
  	if (!"/secure/master"->high_programmer((eu = geteuid(previous_object()))) && !"/secure/master"->check_permission(eu, path, 4)) return notify_fail("No tienes los privilegios necesarios para dar permisos de administracion en esa ruta.\n");

  	notify_fail("Algo ha ido mal.\n");
  	return (int)"/secure/master"->add_grant_permission(euid, path);
	} /* do_grant() */

int do_noread(string str) {
  	string euid, path, eu;

  	if (this_player() != this_player(1)) return 0;
  	if (!str||sscanf(str, "%s %s", euid, path) != 2) return notify_fail("Uso: "+query_verb()+" <creador> <ruta>\n");

  	path = (string)this_player()->get_path(path);
  	if (!"/secure/master"->high_programmer((eu = geteuid(previous_object()))) && !"/secure/master"->check_permission(eu, path, 4)) return notify_fail("No tienes los privilegios necesarios para quitar permisos de lectura en esa ruta.\n");

	notify_fail("Algo ha ido mal.\n");
  	return (int)"/secure/master"->remove_read_permission(euid, path);
	} /* do_noread() */

int do_nowrite(string str) {
  	string euid, path, eu;

  	if (this_player() != this_player(1)) return 0;
  	if (!str||sscanf(str, "%s %s", euid, path) != 2) return notify_fail("Uso: "+query_verb()+" <creador> <ruta>\n");

  	path = (string)this_player()->get_path(path);
  	if (!"/secure/master"->high_programmer((eu = geteuid(previous_object()))) && !"/secure/master"->check_permission(eu, path, 4)) return notify_fail("No tienes los privilegios necesarios para quitar permisos de escritura en esa ruta.\n");

  	notify_fail("Algo ha ido mal.\n");
  	return (int)"/secure/master"->remove_write_permission(euid, path);
	} /* do_nowrite() */

int do_nogrant(string str) {
  	string euid, path, eu;

  	if (this_player() != this_player(1)) return 0;
  	if (!str||sscanf(str, "%s %s", euid, path) != 2) return notify_fail("Uso: "+query_verb()+" <creador> <ruta>\n");

  	path = (string)this_player()->get_path(path);
  	if (!"/secure/master"->high_programmer((eu = geteuid(previous_object()))) && !"/secure/master"->check_permission(eu, path, 4)) return notify_fail("No tienes los privilegios necesarios para quitar permisos de administracion en esa ruta.\n");

  	notify_fail("Algo ha ido mal.\n");
  	return (int)"/secure/master"->remove_grant_permission(euid, path);
	} /* do_nogrant() */

int do_summary(string str) {
  	mapping perms;
  	string *paths, *euids, ret;
  	int i, j, k;

  	if (this_player() != this_player(1)) return 0;

	perms = (mapping)"/secure/master"->query_permissions();
  	if (str) {
    		if (!perms[str]) {
      		tell_object("No hay informacion de permisos en esa ruta.\n");
      		return 1;
    		}
    	perms = ([ str : perms[str] ]);
  	}

	paths = m_indices(perms);
  	if (!sizeof(paths)) ret = "No hay permisos.\n";
  	else ret = sprintf("%12-s       Ruta\n", "Euid");
  	for (i=0;i<sizeof(paths);i++) {
    		euids = m_indices(perms[paths[i]]);
    		for (j=0;j<sizeof(euids);j++) ret += sprintf("%11-s %c%c%c    %s\n", euids[j],((k=perms[paths[i]][euids[j]])&1?'L':' '),(k&2?'E':' '), (k&4?'A':' '), paths[i]);
  		}
  	this_player()->more_string(ret);
  	return 1;
	} /* do_summary() */

void reset() {
  	if(!board) {
    		board = clone_object("obj/misc/board");
    		board->set_datafile("permisos");
    		board->move(this_object());
  		}
	}

void dest_me() {
  	if (board) board->dest_me();
  	::dest_me();
	}

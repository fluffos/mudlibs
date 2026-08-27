#include "access.h"
inherit "/std/room";
#define MASTER "/secure/master"

void setup() {
  	set_short("Oficina de %^MAGENTA%^Admisiones%^RESET%^");
  	set_long(query_short()+"\nEn esta oficina los Semi-Dioses y Dioses pueden banear a jugadores e incluso a Inmortales problematicos. Incluso se puede banear un tramo de red entero, pero antes de hacer algo asi, asegurate de que cuentas con una buena razon y la aprobacion de un Dios. Las consecuencias pueden ser graves...\n"
		"Comandos:\n\n"
		"Jugadores\n"
		"----------------------------\n"
		" %^YELLOW%^banear %^RESET%^ORANGE%^<player> <razon>       %^RESET%^:  Prohibe un nombre para players.\n"
		" %^YELLOW%^desbanear %^RESET%^ORANGE%^<player>            %^RESET%^:  Readmite un nombre para players.\n"
		" %^YELLOW%^suspender %^RESET%^ORANGE%^<player> <tiempo>   %^RESET%^:  Deja sin acceso a un player durante <tiempo> horas.\n"
		" %^YELLOW%^desuspender %^RESET%^ORANGE%^<player>          %^RESET%^:  Devuelve el acceso a un player.\n\n"
		"IPs\n"
		"----------------------------\n"
		" %^YELLOW%^accesos                       %^RESET%^:  Muestra las IPs baneadas.\n"
		" %^YELLOW%^admitir %^RESET%^ORANGE%^<ip>                  %^RESET%^:  Desbanea una IP.\n"
		" %^YELLOW%^nonew %^RESET%^ORANGE%^<ip> <razon>            %^RESET%^:  Impide crear nuevos personajes desde una IP.\n"
		" %^YELLOW%^noaccess %^RESET%^ORANGE%^<ip> <razon>         %^RESET%^:  Impide el acceso desde una IP.\n"
		" %^YELLOW%^noguest %^RESET%^ORANGE%^<ip> <razon>          %^RESET%^:  Impide crear invitados desde una IP.\n\n");

	add_exit("fuera", "/d/heaven/admin3","door");
  	seteuid("Admin");
	} /* setup() */

void init() {
  	::init();
  	add_action("do_banish","banear");
  	add_action("do_unbanish","desbanear");
  	add_action("do_suspend", "suspender");
  	add_action("do_unsuspend", "desuspender");
  	add_action("do_access", "accesos"); /* Show the current access list. */
       	add_action("do_unsite_banish","admitir");
       	add_action("do_nonew","nonew");
       	add_action("do_noaccess","noaccess");
       	add_action("do_noguest","noguest");
	} /* init() */

int print_access(string bit, mapping bing, int depth, int cols) {
  	mixed *bits;
  	int i;

  	if (this_player() != this_player(1)) return 0;
  	bits = m_indices(bing);
  	if (depth == 4) for (i=0;i<sizeof(bits);i++) {
		switch (bing[bits[i]]) {
        		case NO_NEW :
	          	printf("%s@%-=*s", bits[i], cols - strlen(bits[i]), bit +" tiene prohibida la creacion de personajes.\n");
        	  	break;
        		case NO_ACCESS :
			printf("%s@%-=*s", bits[i], cols - strlen(bits[i]), bit +" tiene prohibido el acceso.\n");
          		break;
        		case ACCESS :
          		printf("%s@%-=*s", bits[i], cols - strlen(bits[i]), bit +" tiene acceso.\n");
          		break;
          		case NO_GUEST :
            		printf("%s@%-=*s", bits[i], cols - strlen(bits[i]), bit +" tiene prohibido el acceso a invitados.\n");
          		break;
          		case NO_IMMORTS :
            		printf("%s@%-=*s", bits[i], cols - strlen(bits[i]), bit +" tiene prohibido el acceso a inmortales.\n");
          		break;
          		case NO_PLAYERS :
            		printf("%s@%-=*s", bits[i], cols - strlen(bits[i]), bit +" tiene prohibido el acceso a jugadores.\n");
          		break;
    			}
    		return 1;
  		}
	for (i=0;i<sizeof(bits);i++) print_access(bit+"."+bits[i], bing[bits[i]], depth+1, cols);
  	return 1;
	} /* print_access() */

int do_access() {
  	mixed bing;

  	if (this_player() != this_player(1)) return 0;
  	bing = (mixed)"/secure/bastards"->query_all_access();
  	if (!m_sizeof(bing)) return notify_fail("No hay IPs baneadas.\n");

  	print_access("", bing, 0, (int)this_player()->query_cols());
  	return 1;
	} /* do_access() */

private int do_site_banish(string str) {
  	string ip, ident, reason;
  	int level;

  	if (this_player() != this_player(1)) return 0;
/*   	notify_fail("Uso:  prohibir  <ip>  <ident>  <grado>  <razon>\n"
                    "Donde el grado puede ser:       0 eliminar
		    				     1 acceso normal\n
		    				     2 Nonew
						     3 Noaccess
						     4 Noguests
						     5 No Inmortales
						     6 No Players
               "                      2 no new players, 3 No access.\n"
               "                      4 no guests,       5 no immorts\n"
                "                      6 no players.\n"); */
  	if (!str) return 0;
  	if (sscanf(str, "%s %s %d %s", ip, ident, level, reason) != 4) return 0;

  	if (!"/secure/bastards"->change_access(explode(ip, "."), ident, level, reason)) return 0;
  	write("Permisos modificados.\n");
  	return 1;
	} /* do_site_banish() */

int do_unsite_banish(string str) {
  	string *junk;
  	string ident;
  	string addr;

  	if (!str) return notify_fail("Uso: admitir <ip>\n");
	if (!"/secure/master"->query_lord(geteuid(previous_object()))) return notify_fail("Has de ser Semi-Dios o superior para poder readmitir IPs.\n");

  	if(sscanf(str,"%s@%s",ident,addr) != 2) {
    		ident = "*";
    		addr = str;
  		}

	ident="*";

  	junk = explode(addr,".");
  	if(sizeof(junk) != 4)  return notify_fail("La IP no es valida.\n");

  	if((junk[0] == "*") || (junk[1] == "*") || (junk[2]=="*") ) {
    		tell_object(this_player(),"Solo el ultimo numero puede ser un *.\n");
          	return 1;
  		}
	notify_fail("Ha ocurrido un error.\n");
	return do_site_banish(addr+" "+ident+" 0 ""No reason");
	}

int do_nonew(string str) {
  	string *junk;
  	string ident;
  	string addr;
  	string reason;

  	if (!"/secure/master"->query_lord(geteuid(previous_object()))) return notify_fail("Has de ser Semi-Dios o superior para impedir la creacion de personajes desde una IP.\n");
	notify_fail("Uso: nonew <ip> <razon>\n");

  	if(!str)  return 0;

  	if(sscanf(str,"%s@%s %s",ident,addr,reason) != 3) {
    		if(sscanf(str,"%s %s",addr,reason) != 2)  return 0;
    		ident = "*";
  		}

   	junk = explode(addr,".");
  	if(sizeof(junk) != 4)  return notify_fail("La IP no es valida.\n");

  	if((junk[0] == "*") || (junk[1] == "*") || (junk[2]=="*")) {
    		tell_object(this_player(),"Solo el ultimo numero puede ser un *.\n");
          	return 1;
  		}
	notify_fail("Ha ocurrido un error.\n");
	return do_site_banish(addr+" "+ident+" 2 "+reason);
	}

int do_noaccess(string str) {
  	string *junk;
  	string ident;
  	string addr;
  	string reason;

  	if (!"/secure/master"->query_lord(geteuid(previous_object()))) return notify_fail("Has de ser Semi-Dios o superior para impedir el acceso desde una IP.\n");
  	notify_fail("Uso: noaccess <ip> <razon>\n");

  	if(!str)  return 0;

  	if(sscanf(str,"%s@%s %s",ident,addr,reason) != 3) {
    		if(sscanf(str,"%s %s",addr,reason) != 2)  return 0;
    		ident = "*";
  		}

  	junk = explode(addr,".");
  	if(sizeof(junk) != 4)  return notify_fail("La IP no es valida.\n");

  	if((junk[0] == "*") || (junk[1] == "*") || (junk[2]=="*")) {
    		tell_object(this_player(),"Solo el ultimo numero puede ser un *.\n");
          	return 1;
  		}
	notify_fail("Ha ocurrido un error.\n");
  	return do_site_banish(addr+" "+ident+" 3 "+reason);
	}

int do_noguest(string str) {
  	string *junk;
  	string ident;
  	string addr;
  	string reason;

  	if (!"/secure/master"->query_lord(geteuid(previous_object()))) return notify_fail("Has de ser Semi-Dios o superior para prohibir invitados desde una IP.\n");
  	notify_fail("Uso: noguest <ip> <razon>\n");

  	if(!str)  return 0;

  	if(sscanf(str,"%s@%s %s",ident,addr,reason) != 3) {
    		if(sscanf(str,"%s %s",addr,reason) != 2)  return 0;
    		ident = "*";
  		}

  	junk = explode(addr,".");
  	if(sizeof(junk) != 4)  return notify_fail("La IP no es valida.\n");

  	if((junk[0] == "*") || (junk[1] == "*") || (junk[2]=="*")) {
    		tell_object(this_player(),"Solo el ultimo numero puede ser un *.\n");
          	return 1;
  		}
	notify_fail("Ha ocurrido un error.\n");
  	return do_site_banish(addr+" "+ident+" 4 "+reason);
	}

int do_banish(string str) {
  	string name;
  	string reason;

  	if (this_player() != this_player(1)) return 0;
  	if (!"/secure/master"->query_lord(geteuid(previous_object()))) return notify_fail("Has de ser Semi-Dios o superior para poder banear nombres.\n");

  	if (!str||sscanf(str, "%s %s", name, reason) != 2) return notify_fail("Uso: banear <nombre> <razon>\n");

  	notify_fail("Ha ocurrido un error.\n");
  	if (!"/secure/bastards"->banish_playername(name, reason)) return 0;
  	write(capitalize(name)+" baneado por: "+reason+"\n");
  	return 1;
	} /* do_banish() */

int do_unbanish(string str) {
  	if (this_player() != this_player(1)) return 0;
  	if (!"/secure/master"->query_lord(geteuid(previous_object()))) return notify_fail("Has de ser Semi-Dios o superior para poder desbanear nombres.\n");

	if (!str) return notify_fail("Uso: desbanear <nombre>\n");
  	notify_fail("Ha ocurrido un error.\n");
  	if (!"/secure/bastards"->unbanish_playername(str)) return 0;
  	write(capitalize(str)+" desbaneado.\n");
  	return 1;
	} /* do_unbanish() */

int do_suspend(string str) {
  	string name;
  	int tim;

  	if (this_player() != this_player(1)) return 0;
	if (!"/secure/master"->query_lord(geteuid(previous_object()))) notify_fail("Has de ser Semi-Dios o superior para poder suspender a un jugador.\n");

  	if (!str||sscanf(str, "%s %d", name, tim) != 2) return notify_fail("Uso: suspender <nombre> <tiempo>\nDonde el tiempo es el numero de horas.\n");
  	notify_fail("Ha ocurrido un error.\n");
  	if (!"/secure/bastards"->suspend_person(name, tim*60*60)) return 0;
  	write(capitalize(name)+" suspendido hasta "+ctime(time()+tim*60*60)+"\n");
  	return 1;
	} /* do_suspend() */

int do_unsuspend(string str) {
  	if (this_player() != this_player(1)) return 0;
  	if (!"/secure/master"->query_lord(geteuid(previous_object()))) return notify_fail("Has de ser Semi-Dios o superior para poder quitar una suspension a un jugador.\n");

	if (!str) return notify_fail("Uso: desuspender <nombre>\n");
  	notify_fail("Ha ocurrido un error.\n");
  	if (!"/secure/bastards"->unsuspend_person(str)) return 0;
  	write("Anulada la suspension de "+capitalize(str)+".\n");
  	return 1;
	} /* do_unsuspend() */

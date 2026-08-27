inherit "/std/room";
#include "mail.h"

void setup() {
  	set_short("Oficina Postal del %^GREEN%^BOLD%^Paraiso%^RESET%^");
  	set_long(query_short()+"\nEsta es la Oficina Postal del Paraiso, desde donde se organizan todas las oficinas de correos del Mud. Aqui se pueden crear listas de correo para enviar un mail a aquellos que esten suscritos a ella.\nLa Oficina funciona con los siguientes comandos:\n%^YELLOW%^crear %^RESET%^ORANGE%^<lista>%^RESET%^              :  Crea una lista de correo nueva.\n%^YELLOW%^anyadir %^RESET%^ORANGE%^<lista> <nombre>%^RESET%^   :  Anyade un miembro a la lista de correo.\n%^YELLOW%^borrar %^RESET%^ORANGE%^<lista>  <nombre>%^RESET%^   :  Elimina a un miembro de la lista de correo.\n%^YELLOW%^listar %^RESET%^ORANGE%^<lista>%^RESET%^             :  Muestra las listas de correo o los miembros de una dada.\n");

  	set_light(100);
	add_exit("fuera","/d/heaven/admin1","door");
	}

void init() {
  	::init();
  	add_action("do_add", "anyadir");
  	add_action("do_list", "listar");
  	add_action("do_remove", "borrar");
  	add_action("do_create", "crear");
	}

int do_add(string str) {
  	string name, list;

  	if (!str) return notify_fail("Sintaxis: anyadir <lista> <nombre>\n");
  	if (sscanf(str, "%s %s", list, name) != 2) return notify_fail("Sintaxis: anyadir <lista> <nombre>\n");
  	if (!MAIL_TRACK->query_list(list)) return notify_fail("La lista de correo \""+list+"\" no existe.\n");

  	if (!name) return notify_fail("Debes especificar a quien quieres anyadir.\n");

  	if (name[0] == '*') {
		name = name[1..strlen(name)-1];
      		if (!"/secure/login"->test_user(name)) write("No existe el jugador "+capitalize(name)+".\n");
      		else if (MAIL_TRACK->add_controller(list, name)) write("Anyadido "+capitalize(name)+" como controlador de la lista de correo \""+list+"\".\n");
      		else write("Se produjo un error al intentar anyadir a "+capitalize(name)+" como controlador de la lista de correo \""+list+"\".\n");
   	} else if (!"/secure/login"->test_user(name) && !MAIL_TRACK->query_list(name)) write("No existe el jugador "+capitalize(name)+".\n");
    	else if (MAIL_TRACK->add_member(list, name)) write("Anyadido "+capitalize(name)+" a la lista de correo.\n");
    	else write("Se produjo un error al intentar anyadir a "+capitalize(name)+" a la lista de correo.\n");
  	return 1;
	}

int do_list(string str) {
  	string *strs, *cont;
  	int i, j;

  	if (!str) {
		strs = MAIL_TRACK->query_mailing_lists();
    		printf("Listas de correo: %-=*s", (int)this_player()->query_cols()-24,implode(strs, ", ")+".\n");
  	} else {
    		strs = MAIL_TRACK->query_members(str) - ({ "" });
    		cont = MAIL_TRACK->query_controllers(str);
    		if (!sizeof(strs)) return notify_fail("La lista de correo \""+str+"\" no existe.\n");

		for (i=0;i<sizeof(cont);i++) if ((j = member_array(cont[i], strs)) != -1) strs[j] = "*"+strs[j];
      		else strs += ({ "*"+cont[i] });

    		printf(str+": %-=*s", (int)this_player()->query_cols()-strlen(str)-3,implode(strs, ", ")+".\n");
		}
  	return 1;
	}

int do_remove(string str) {
  	string name, list;
	
	if (!str) return notify_fail("Sintaxis: borrar <lista> <nombre>\n");
  	if (sscanf(str, "%s %s", list, name) != 2) return notify_fail("Sintaxis: borrar <lista> <nombre>\n");
  	if (!MAIL_TRACK->query_list(list)) return notify_fail("La lista de correo \""+list+"\" no existe.\n");
  	if (!MAIL_TRACK->query_controller(list, this_player()->query_name())&&str!=TP->query_name()) return notify_fail("Tienes que ser Administrador de la lista para poder borrar miembros.\n");

  	if (!name) return notify_fail("Debes especificar a quien quieres borrar.\n");

    	if (name[0] == '*') {
/* They are trying to remove a controller. */
      		name = name[1..1000];
      		if (MAIL_TRACK->remove_controller(list, name)) tell_object(TP,"Eliminado "+capitalize(name)+" como controlador de la lista.\n");
		else tell_object(TP,"Fallo al intentar eliminar un controlador.\n");
		}
        else {
		if (MAIL_TRACK->remove_member(list, name)) tell_object(TP,"Eliminado "+capitalize(name)+" de la lista.\n");
      		else tell_object(TP,"Fallo al intentar eliminar un miembro.\n");
       		}
  	return 1;
	} /* do_remove() */

int do_create(string str) {
	string s1, s2;

  	if (!str) return 0;
  	if (MAIL_TRACK->query_list(str)) return notify_fail("Esa lista ya existe!\n");
  	if (sscanf(str, "%s %s", s1, s2) == 2 || sscanf(str, "%s,%s", s1, s2)) return notify_fail("Nombre incorrecto para la lista, no puede haber espacios ni comas.\n");

  	if (MAIL_TRACK->create_list(str, this_player()->query_name())) {
    		tell_object(TP,"Creada la lista \""+str+"\".\n");
		return 1;
  		}
  	return notify_fail("Fallo al crear la lista de correo.\n");
	} /* do_create() */

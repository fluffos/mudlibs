// Maele 30.10.2002
inherit "/obj/comida";

void setup() {
	set_name("licor de algas");
	set_short("Licor de Algas");
	set_long(query_short()+"\nUn vaso de licor de algas de los pantanos, de color verde oscuro.\n");
	add_alias("alga");
	add_alias("licor");
	set_main_plural("Licores de Algas");
	add_plural("licores");
	add_plural("algas");
	set_value(350);
	set_weight(10);
	set_tipo("alcohol");
	set_curacion(20);
	}
void mostrar_mensajes(object me) {
	tell_object(me,"Te bebes un vaso de licor de algas y notas los aires de los pantanos llenar tus sentidos.\n");
	tell_room(ENV(me),me->query_cap_name()+" se bebe un vaso de licor de algas.\n",me);
	}
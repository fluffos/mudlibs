// Maele 30.10.2002
inherit "/obj/comida";

void setup() {
	set_name("sidra elfica");
	set_short("Sidra Elfica");
	set_long(query_short()+"\nUn vaso de sidra destilada por los elfos, de gran calidad y buena facturacion.\n");
	add_alias("sidra");
	set_main_plural("Sidras Elficas");
	add_plural("sidras");
	set_value(300);
	set_weight(10);
	set_tipo("alcohol");
	set_curacion(17);
	}
void mostrar_mensajes(object me) {
	tell_object(me,"Te bebes un vaso de sidra elfica y notas un calorcillo subir por tu estomago.\n");
	tell_room(ENV(me),me->query_cap_name()+" se bebe un vaso de sidra y sus mejillas se sonrojan levemente.\n",me);
	}
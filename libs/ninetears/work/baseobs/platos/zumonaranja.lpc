// Maele 30.10.2002
inherit "/obj/comida";

void setup() {
	set_name("zumo de naranja");
	set_short("Zumo de Naranja");
	set_long(query_short()+"\nUn vaso un riquisimo zumo de naranjas cultivadas en asgard.\n");
	add_alias("zumo");
	set_main_plural("Zumos de Naranjas");
	add_plural("zumos");
	set_value(175);
	set_weight(10);
	set_tipo("bebida");
	set_curacion(13);
	}
void mostrar_mensajes(object me) {
	tell_object(me,"Te bebes un vaso de zumo de naranja y el sabor te llena el paladar.\n");
	tell_room(ENV(me),me->query_cap_name()+" se bebe un vaso de zumo de naranja.\n",me);
	}
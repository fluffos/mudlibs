// Maele 30.10.2002
inherit "/obj/comida";

void setup() {
	set_name("ron");
	set_short("Ron");
	set_long(query_short()+"\nUn vaso de este ron seguro que sera bien recibido por un paladar sibarita, su color y textura incitan a beberlo.\n");
	add_alias("ron");
	set_main_plural("Rones");
	add_plural("rones");
	set_value(275);
	set_weight(10);
	set_tipo("alcohol");
	set_curacion(29);
	}
void mostrar_mensajes(object me) {
	tell_object(me,"Te bebes un vaso de ron y sientes como tus ojos se abren ante la entrada de alcohol en tu cuerpo.\n");
	tell_room(ENV(me),me->query_cap_name()+" se bebe un vaso de ron de un trago y sus ojos se agrandan bastante.\n",me);
	}
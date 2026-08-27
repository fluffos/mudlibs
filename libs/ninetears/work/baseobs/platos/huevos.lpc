inherit "/obj/comida";

void setup() {
	set_name("huevos");
	set_short("Huevos con Bacon");
	set_long(query_short()+"\nUn par de huevos con 2 cortadas de panceta de cerdo.\n");
	add_alias("huevos");
	set_main_plural("Huevos con bacon");
	add_plural("huevos");
	set_value(320);
	set_weight(10);
	set_curacion(15);
	call_out("corromper",1000);
	}
void mostrar_mensajes(object me) {
	tell_object(me,"Te comes unos huevos con bacon, sucando con algo de pan.\n");
	tell_room(ENV(me),me->query_cap_name()+" se come unos huevos con bacon, como siga asi le va a reventar el pantalon!!!.\n",me);
	}
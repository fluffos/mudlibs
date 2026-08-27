inherit "/obj/comida";

void setup() {
	set_name("arroz");
	set_short("Arroz blanco");
	set_long(query_short()+"\nUn humeante plato de arroz blanco.\n");
	add_alias("arroz");
	set_main_plural("Arroces blancos");
	add_plural("arroces");
	set_value(200);
	set_weight(10);
	set_curacion(10);
	call_out("corromper",1000);
	}
void mostrar_mensajes(object me) {
	tell_object(me,"Te comes un plato de arroz blanco, te sale humo por las orejas.\n");
	tell_room(ENV(me),me->query_cap_name()+" se come un plato de arroz blanco.\n",me);
	}
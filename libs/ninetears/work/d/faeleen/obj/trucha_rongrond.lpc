inherit "/obj/comida";

void setup() {
	set_name("trucha");
	set_short("Trucha");
	set_long(query_short()+"\nUna gran trucha pescada por pescadores de Rongrond.\n");
	add_alias("trucha");
	set_main_plural("truchas");
	add_plural("truchas");
	set_value(250);
	set_weight(10);
	set_curacion(10);
	call_out("corromper",1000);
	}
void mostrar_mensajes(object me) {
	tell_object(me,"Te comes una trucha, parece estar buena.\n");
	tell_room(ENV(me),me->query_cap_name()+" se come una trucha.\n",me);
	}
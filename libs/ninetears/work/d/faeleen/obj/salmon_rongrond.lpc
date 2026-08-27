inherit "/obj/comida";

void setup() {
	set_name("salmon");
	set_short("Salmon");
	set_long(query_short()+"\nUn gran Salmon pescada por pescadores de Rongrond.\n");
	add_alias("salmon");
	set_main_plural("salmones");
	add_plural("salmones");
	set_value(250);
	set_weight(10);
	set_curacion(10);
	call_out("corromper",1000);
	}
void mostrar_mensajes(object me) {
	tell_object(me,"Te comes un salmon, parece estar bueno.\n");
	tell_room(ENV(me),me->query_cap_name()+" se come un salmon.\n",me);
	}
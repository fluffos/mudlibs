inherit "/obj/comida";

void setup() {
	set_name("sesos");
	set_short("Seso de vaca");
	set_long(query_short()+"\nUn sabroso y humeante plato de sesos de algun animal.\n");
	add_alias("seso");
	set_main_plural("Sesos de vaca");
	add_plural("sesos");
	set_value(400);
	set_weight(10);
	set_curacion(20);
	call_out("corromper",1000);
	}
void mostrar_mensajes(object me) {
	tell_object(me,"Te comes un plato de sesitos de vaca.\n");
	tell_room(ENV(me),me->query_cap_name()+" se come un plato de sesos de algun animal.\n",me);
	}
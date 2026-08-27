inherit "/obj/comida";

void setup() {
	set_name("patatas");
	set_short("Patatas a lo pobre");
	set_long(query_short()+"\nUn sabroso plato patatas con cebollas, el plato de los pobres.\n");
	add_alias("patata");
	set_main_plural("Patatas a lo pobre");
	add_plural("Patatas");
	set_value(150);
	set_weight(10);
	set_curacion(6);
	call_out("corromper",1000);
	}
void mostrar_mensajes(object me) {
	tell_object(me,"Te comes un plato de patatas calientes con cebolla.\n");
	tell_room(ENV(me),me->query_cap_name()+" se come un plato de patatas a lo pobre.\n",me);
	}
inherit "/obj/comida";

void setup() {
	set_name("judia");
	set_short("Plato de judias");
	set_long(query_short()+"\nUn sabroso plato de judias con chorizo.\n");
	add_alias("judia");
	set_main_plural("Platos de judias");
	add_plural("judias");
	set_value(650);
	set_weight(10);
	set_curacion(30);
	call_out("corromper",1000);
	}
void mostrar_mensajes(object me) {
	tell_object(me,"Te comes un nutritivo plato de judias con chorizo.\n");
	tell_room(ENV(me),me->query_cap_name()+" se come un plato de judias con chorizo.\n",me);
	}
inherit "/obj/comida";

void setup() {
	set_name("higado");
	set_short("Higado de pollo");
	set_long(query_short()+"\nUnos higaditos de pollo huemantes y con un olor tonificante.\n");
	add_alias("higado");
	set_main_plural("Higados de pollo");
	add_plural("higados");
	set_value(300);
	set_weight(10);
	set_curacion(15);
	call_out("corromper",1000);
	}
void mostrar_mensajes(object me) {
	tell_object(me,"Te comes unos higaditos de pollo con su salsa.\n");
	tell_room(ENV(me),me->query_cap_name()+" se come un plato higados de pollo con salsa.\n",me);
	}
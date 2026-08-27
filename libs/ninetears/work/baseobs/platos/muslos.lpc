inherit "/obj/comida";

void setup() {
	set_name("pollo");
	set_short("Muslos de pollo");
	set_long(query_short()+"\nUnos jugosos muslos de pollo con salsa picante.\n");
	add_alias("pollo");
	add_alias("muslo");
	set_main_plural("Muslos de pollos");
	add_plural("pollos");
	add_plural("muslos");
	set_value(250);
	set_weight(10);
	set_curacion(10);
	call_out("corromper",1000);
	}
void mostrar_mensajes(object me) {
	tell_object(me,"Te comes unos muslitos de pollo con salsa picante.\n");
	tell_room(ENV(me),me->query_cap_name()+" se come unos muslitos de pollo con salsa picante.\n",me);
	}
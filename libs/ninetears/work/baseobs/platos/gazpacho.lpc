inherit "/obj/comida";

void setup() {
	set_name("gazpacho");
	set_short("Gazpacho");
	set_long(query_short()+"\nUn tazon de gazpacho con un buen trozo de pan para comer.\n");
	add_alias("gazpacho");
	set_main_plural("Gazpachos");
	add_plural("gazpachos");
	set_value(200);
	set_weight(10);
	set_curacion(11);
	call_out("corromper",1000);
	}
void mostrar_mensajes(object me) {
	tell_object(me,"Te come un tazon de gazpacho fresquito con pan.\n");
	tell_room(ENV(me),me->query_cap_name()+" se bebe un tazon de gazpacho con pan.\n",me);
	}
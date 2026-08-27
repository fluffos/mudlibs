inherit "/obj/comida";

void setup() {
	set_name("hervido");
	set_short("Hervido");
	set_long(query_short()+"\nUn hervido con legumbres varias.\n");
	add_alias("hervido");
	set_main_plural("Hervidos");
	add_plural("hervidos");
	set_value(250);
	set_weight(10);
	set_curacion(13);
	call_out("corromper",1000);
	}
void mostrar_mensajes(object me) {
	tell_object(me,"Te comes un plato de hervido con su patata y todas sus legumbres.\n");
	tell_room(ENV(me),me->query_cap_name()+" se come un plato de hervido con patatas.\n",me);
	}
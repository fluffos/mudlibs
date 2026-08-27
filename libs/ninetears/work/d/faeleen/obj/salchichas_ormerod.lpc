//Kryger 2002//
inherit "/obj/comida";

void setup() {
	set_name("Salchicha");
	set_short("Salchicha");
	set_long(query_short()+"\n\n"+"Es una Salchichilla, esta grande y generosa, se ve "
	"que la carne es de muy buena calidad.\n");
	add_alias("salchicha");
	set_main_plural("salchichas");
	add_plural("salchichas");
	set_value(200);
	set_weight(10);
	set_curacion(10);
	call_out("corromper",1000);
	}
void mostrar_mensajes(object me) {
	tell_object(me,"Te comes una salchicha, parece estar bueno.\n");
	tell_room(ENV(me),me->query_cap_name()+" se come una salchicha.\n",me);
	}
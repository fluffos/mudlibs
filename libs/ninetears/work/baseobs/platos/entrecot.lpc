inherit "/obj/comida";

void setup() {
	set_name("entrecot");
	set_short("Entrecot a la pimienta");
	set_long(query_short()+"\nUn buen trozo de entrecot.\n");
	add_alias("entrecot");
	set_main_plural("entrecots");
	add_plural("entrecots");
	set_value(1200);
	set_weight(10);
	set_curacion(45);
	call_out("corromper",1000);
	}
void mostrar_mensajes(object me) {
	tell_object(me,"Te zampas el entrecot y sientes tu estomago a reventar.\n");
	tell_room(ENV(me),me->query_cap_name()+" se come un un enorme entrecot con avidez.\n",me);
	}
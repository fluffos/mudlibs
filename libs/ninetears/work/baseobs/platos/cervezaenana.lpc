// Maele 30.10.2002
inherit "/obj/comida";

void setup() {
	set_name("cerveza enana");
	set_short("Jarra de Cerveza Enana");
	set_long(query_short()+"\nUna espumosa jarra de cerveza destilada por los enanos.\n");
	add_alias("cerveza");
	set_main_plural("Jarras de Cerveza");
	add_plural("cervezas");
	set_value(500);
	set_weight(10);
	set_tipo("alcohol");
	set_curacion(45);
	}
void mostrar_mensajes(object me) {
	tell_object(me,"Te bebes una jarra de esta cerveza espumosa, probablemente la mejor cerveza del mundo.\n");
	tell_room(ENV(me),me->query_cap_name()+" se bebe una jarra de cerveza enana y los morros se le quedan manchados de espuma.\n",me);
	}
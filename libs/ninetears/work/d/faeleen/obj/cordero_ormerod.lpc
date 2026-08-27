//Kryger 2002//
inherit "/obj/comida";

void setup() {
	set_name("Chuleta");
	set_short("Chuleta de cordero");
	set_long(query_short()+"\n\n"+"Es una chuleta de cordero, de palo, esta bien cortada, se ve "
	"que la carne es de muy buena calidad.\n");
	add_alias("cordero");
	add_alias("chuletas");
	set_main_plural("corderos");
	add_plural("chuletas");
	set_value(300);
	set_weight(10);
	set_curacion(10);
	call_out("corromper",1000);
	}
void mostrar_mensajes(object me) {
	tell_object(me,"Te comes una chuleta de cordero, parece estar bueno.\n");
	tell_room(ENV(me),me->query_cap_name()+" se come una chuleta de cordero.\n",me);
	}
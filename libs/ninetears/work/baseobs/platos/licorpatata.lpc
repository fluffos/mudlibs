// Maele 30.10.2002
inherit "/obj/comida";

void setup() {
	set_name("licor de patata");
	set_short("Licor de Patata");
	set_long(query_short()+"\nUn chupito de licor de patata.\n");
	add_alias("patata");
	add_alias("licor");
	set_main_plural("Licores de Patata");
	add_plural("patatas");
	add_plural("licores");
	set_value(300);
	set_weight(10);
	set_tipo("alcohol");
	set_curacion(40);
	}
void mostrar_mensajes(object me) {
	tell_object(me,"Te bebes de un trago el vaso de licor de patata como si fuese agua.\n");
	tell_room(ENV(me),me->query_cap_name()+" se retuerce bajo los devastadores efectos que el licor de patata ha causado en su garganta, sus orejas se enrojecen y se colorean sus mofletes rapidamente.\n",me);
	}
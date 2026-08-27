// Maele 30.10.2002
inherit "/obj/comida";

void setup() {
	set_name("leche de lagarta");
	set_short("Leche de Lagarta");
	set_long(query_short()+"\nUn vaso de leche de lagarta de serkesh, una bebida exotica.\n");
	add_alias("leche");
	set_main_plural("Leches de Lagartas");
	add_plural("leches");
	set_value(300);
	set_weight(10);
	set_tipo("bebida");
	set_curacion(20);
	}
void mostrar_mensajes(object me) {
	tell_object(me,"Te bebes un vaso de leche de lagarta y notas un calorcito agradable en tu estomago.\n");
	tell_room(ENV(me),me->query_cap_name()+" se bebe un vaso de leche de lagarta y los morros se le quedan manchados de blanco.\n",me);
	}
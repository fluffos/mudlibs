// Maele 30.10.2002
inherit "/obj/comida";

void setup() {
	set_name("tuttifrutti");
	set_short("Tutti Frutti");
	set_long(query_short()+"\nUn vaso de color raro que contiene una mezcla de varias frutas exprimidas.\n");
	add_alias("zumo");
	add_alias("tuttifrutti");
	set_main_plural("Tutti Fruttis");
	add_plural("zumos");
	add_plural("tuttifrutis");
	set_value(250);
	set_weight(10);
	set_tipo("bebida");
	set_curacion(17);
	}
void mostrar_mensajes(object me) {
	tell_object(me,"Te bebes un vaso de tuttifrutti y el sabor de muchas frutas riquisimas te llena el paladar.\n");
	tell_room(ENV(me),me->query_cap_name()+" se bebe un vaso de tuttifrutti.\n",me);
	}
// Maele 30.10.2002
inherit "/obj/comida";

void setup() {
	set_name("whisky de urghak");
	set_short("Whisky de Urghak");
	set_long(query_short()+"\nUn vaso de whisky destilado en las tierras de urghak, finamente elaborado y algo espeso pero que ofrece una buena vision a la vista, y no digamos al paladar.\n");
	add_alias("whisky");
	set_main_plural("Whiskys de Urghak");
	add_plural("whiskys");
	set_value(400);
	set_weight(10);
	set_tipo("alcohol");
	set_curacion(30);
	}
void mostrar_mensajes(object me) {
	tell_object(me,"Te bebes un vaso de este whisky y experimentas una buena sensacion, aunque algo espeso, es bastante delicioso.\n");
	tell_room(ENV(me),me->query_cap_name()+" se bebe un vaso de whisky y cuando termina se relame los labios.\n",me);
	}
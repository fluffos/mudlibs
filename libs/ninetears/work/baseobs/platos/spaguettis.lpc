inherit "/obj/comida";

void setup() {
	set_name("spaguettis");
	set_short("Plato de spaguettis");
	set_long(query_short()+"\nUn sabroso plato de spaguettis.\n");
	add_alias("plato");
	add_alias("spaguetti");
	set_main_plural("Platos de spaguettis");
	add_plural("platos");
	add_plural("spaguettis");
	set_value(325);
	set_weight(10);
	set_curacion(17);
	call_out("corromper",1000);
	}
void mostrar_mensajes(object me) {
	tell_object(me,"Te comes un delicioso plato de spaguettis. oh mamma mia!!!.\n");
	tell_room(ENV(me),me->query_cap_name()+" se come un plato de spaguettis, sorbiendolos ruidosamente.\n",me);
	}
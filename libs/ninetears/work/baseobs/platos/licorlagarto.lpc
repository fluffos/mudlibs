// Maele 30.10.2002
inherit "/obj/comida";

void setup() {
	set_name("licor de lagarto de serkesh");
	set_short("Licor de Lagarto de Serkesh");
	set_long(query_short()+"\nUna bebida exotica, el recipiente es de color verde y en su interior, en la base, se puede ver un lagarto pequenyo.\n");
	add_alias("licor");
	add_alias("serkesh");
	set_main_plural("Licores de Lagarto de Serkesh");
	add_plural("licores");
	set_value(375);
	set_weight(10);
	set_tipo("alcohol");
	set_curacion(25);
	}
void mostrar_mensajes(object me) {
	tell_object(me,"Bebes este extranyo licor y te da una pequenya arcada cuando llegas al final y el lagarto que hay en su interior roza tus labios.\n");
	tell_room(ENV(me),me->query_cap_name()+" se bebe el licor de lagarto y al llegar al final casi vomita cuando se da cuenta de que habia un lagarto muerto dentro.\n",me);
	}
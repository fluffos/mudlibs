// Vilat 29.10.2002
// Plato de Macarrones

// La comida cura Puntos de Energia, y los platos heredan /obj/comida.c
inherit "/obj/comida";

void setup() {
	// Se hace como un item normal
	set_name("macarrones");
	set_short("Plato de macarrones");
	set_long(query_short()+"\nUn sabroso plato de macarrones.\n");
	add_alias("plato");
	set_main_plural("Platos de macarrones");
	add_plural("platos");
	set_value(300); // Muy importante que si no lo venden gratis xD
	set_weight(10);
	// Ahora lo especifico del plato
	set_curacion(15); // Los puntos de energia que cura al comerse
	call_out("corromper",1000); // Con esto el plato tardara 1000 JB (30 minutos) en ponerse malo. Si no se pone eso el plato no se pondra malo
	}

// Estos son los mensajes al comerselo. me es el player
void mostrar_mensajes(object me) {
	tell_object(me,"Te comes un rico plato de macarrones. Estaba delicioso.\n");
	tell_room(ENV(me),me->query_cap_name()+" se come un plato de macarrones, manchandose toda la cara de tomate.\n",me);
	}
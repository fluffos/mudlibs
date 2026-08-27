// Vilat 30.10.2002
// Remedio AntiRESAKA

// Las bebidas bajan la borrachera, y como los platos heredan /obj/comida.c
inherit "/obj/comida";

void setup() {
	// Se hace como un item normal
	set_name("antiresaca");
	set_short("Remedio Antiresaca");
	set_long(query_short()+"\nUna bebida viscosa y verde que burbujea.\n");
	add_alias("remedio");
	set_main_plural("Remedios Antiresaca");
	add_plural("remedios");
	add_plural("antiresacas");
	set_value(3000); // Muy importante que si no lo venden gratis xD
	set_weight(10);
	// Ahora lo especifico
	set_tipo("bebida"); // Para que baje el alcohol
	set_curacion(1500); // Cuanto te baja la borrachera
	}

// Estos son los mensajes al beberselo. me es el player
void mostrar_mensajes(object me) {
	tell_object(me,"Venciendo tu asco, te bebes el viscoso liquido.\n");
	tell_room(ENV(me),me->query_cap_name()+" se bebe un liquido viscoso y desagradable.\n",me);
	}

// Vilat 30.10.2002
// Chupito de TeKila

// Las bebidas alcoholicas te emborrachan como es logico
inherit "/obj/comida";

void setup() {
	// Se hace como un item normal
	set_name("chupito");
	set_short("Chupito de Tekila");
	set_long(query_short()+"\nUn chupito de tekila.\n");
	add_alias("tekila");
	set_main_plural("Chupitos de Tekila");
	add_plural("chupitos");
	set_value(100); // Muy importante que si no lo venden gratis xD
	set_weight(10);
	// Ahora lo especifico
	set_tipo("alcohol"); // Para que te emborraches
	set_curacion(15); // Cuanto te sube la borrachera
	}

// Estos son los mensajes al beberselo. me es el player
void mostrar_mensajes(object me) {
	tell_object(me,"Te bebes de un trago el chupito como si fuese agua.\n");
	tell_room(ENV(me),me->query_cap_name()+" se retuerce bajo los devastadores efectos que el chupito de tequila ha causado en su garganta.\n",me);
	}

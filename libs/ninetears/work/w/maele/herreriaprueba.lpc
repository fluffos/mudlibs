// Vilat 26.10.2002

// Las nuevas tiendas heredan /std/tienda.c
inherit "/std/tienda";

void setup() {
	set_short("Herreria de Prueba");
	set_long(query_short()+"\nEsta es una herreria de prueba, creada para explicar a los creadores como pueden utilizar el nuevo modelo de tienda en sus zonas.\n");
	set_dependiente("/baseobs/guildmasters/patric");
	// La funcion prohibir_venta() hace que en la tienda no se puedan vender objetos, solo comprar. La usare en la herreria
	prohibir_venta();
	// Como he implemtado el tipo herreria y quiero hacer una herreria pues le pongo el tipo herreria
	set_tipo("herreria");
	add_suministro("/baseobs/armours/helmet",2);
	add_suministro("/baseobs/weapons/long_sword",random(5));
	add_suministro("/baseobs/shields/corporal",roll(1,3));
	add_ajuste("raza","Duergar",80);
	add_ajuste("clase","Bribon",120);
	add_ajuste("gremio","Barbarocaos",100+roll(1,20));
	// Esta vez probaremos los prohibidos
	add_prohibido("raza","enano");
	add_prohibido("alineamiento","legal bueno");
	// Ahora quiero una placa
	add_cartel();
	}

// Pues sabiendo hacer la tienda no es nada complicado hacer la herreria, digo yo

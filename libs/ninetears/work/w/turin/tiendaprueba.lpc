// Vilat 26.10.2002

// Las nuevas tiendas heredan /std/tienda.c
inherit "/std/tienda";

void setup() {
	// Hacemos lo de siempre
	set_short("Tienda de Prueba");
	set_long(query_short()+"\nEsta es una tienda de prueba, creada para explicar a los creadores como pueden utilizar el nuevo modelo de tienda en sus zonas.\n");
	// Funcion set_dependiente(), es igual que add_clone() pero sin numero (solo hay un dependiente)
	set_dependiente("/baseobs/guildmasters/patric");
	// La funcion prohibir_venta() hace que en la tienda no se puedan vender objetos, solo comprar. En este ejemplo no nos interesa pero seria algo asi:
//	prohibir_venta();
	// Cuando haya mas tipos de tienda elegiremos el tipo con la funcion set_tipo(). De momento solo existe el tipo 'standard'
	set_tipo("standard"); // Si hacemos una tienda estandar no es necesario q pongamos esto, pq es el tipo por defecto. Lo he puesto para que veais como se hace
	// Ahora pondremos el suministro. Las tiendas reciben el suministro si al cargarse la room hace mas de una semana (tiempo de Driade) que no recibe suministros. Si vemos que las tiendas se cargan con demasiados objetos podemos bajar la velocidad, eso ya lo decidiremos
	// Se usa la funcion add_suministro() de un modo tal que asi:
	add_suministro("/baseobs/armours/helmet",2);
	add_suministro("/baseobs/weapons/long_sword",random(5)); // Como veis podemos usar aleatorios
	add_suministro("/baseobs/shields/corporal",roll(1,3));
	// Ahora pondremos ajustes a los precios. Los ajustes pueden basarse en raza, clase, gremio, ciudadania o alineamiento. Un ajuste no puede ser mejor del 50% ni peor del 500%
	add_ajuste("raza","Duergar",80); // Los Duergar los objetos al 80%
	add_ajuste("clase","Bribon",120);
	add_ajuste("gremio","Barbarocaos",100+roll(1,20)); // Tb podemos usar funciones aki
	// Ahora llega el momento de decidir como queremos (si es que queremos) restringir la tienda. Podemos hacerlo de dos formas:
	// - Prohibiendo: con add_prohibido()
	// - Permitiendo por exclusion: con add_permitido() y restringir_permitidos()
	// Si quisiesemos hacerlo prohibiendo es tan facil como esto:
/*	add_prohibido("raza","enano");
	add_prohibido("alineamiento","legal bueno"); */
	// Sin embargo lo haremos permitiendo por exclusion, q significa q solo podran usar la tienda los que esten permitidos
	// He elegido este metodo para el ejemplo porque es ligeramente mas dificil, aunq no mucho la verdad
	restringir_permitidos(); // Con eso hacemos que la tienda solo la puedan usar los permitidos. Si no lo ponemos seria estupido anyadir permitidos pq no tendria efecto
	add_permitido("ciudad","Asgard");
	add_permitido("gremio","caballerojade"); // Como veis los tipos de prohibiciones y permisiones son los mismos que de ajustes: raza, clase, gremio, ciudadania y alineamiento
	add_permitido("alineamiento","legal malvado");
	add_permitido("alineamiento","neutral malvado");
	// Por ultimo esta funcion mete en la tienda un cartel con los comandos disponibles. Si le ponemos argumento ese sera el nombre del cartel, y si no por defecto sera una "placa"
	add_cartel("pedestal");
	}

// Y ya tenemos nuestra tienda hecha
// Dificil? Yo creo que no... Ademas esta tienda consume menos recursos y es mas acorde con nuestro sistema de juego
// Las tiendas ya no ajustan precios por carisma, sino por reputacion
// Aun esta en fase de debug asi que los fallos que veais me los comentais y a ver como puedo solucionarlos...
// Tb podeis proponer tipos de tiendas, porque de momento es un poco soso eso de tener solo el estandar...

// Por ultimo decir que falta el ajuste por Impuesto de Ventas, pero eso no se puede meter de momento hasta que se decida como se hara
// De todos modos cuando se meta a vosotros en lo unico que os afectara es en tener que poner algo como set_ciudadania("X"), asi que no
// creo que sea mucha molestia, no? :P

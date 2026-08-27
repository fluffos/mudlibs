// Vilat 24.10.2002
// Arma magica con comandos avanzados para aprendices

#define DANYO 5000 // Os acordais de lo que hace el define no? Si no es asi miraos la workroom basica

inherit "/obj/weapon";

void setup() {
  	set_base_weapon("baston");
  	set_name("baston runico");
  	add_alias("baston");
	add_alias("runico");
  	set_short("Baston %^GREEN%^R%^RESET%^CYAN%^u%^BLUE%^ni%^RESET%^CYAN%^c%^GREEN%^o%^RESET%^");
  	set_long("El poderoso baston de Dorian Hawkmoon, recreado en esta realidad por Vilat para ayudar a los nuevos inmortales"
	     " en su paso de aprendices a creadores. Las runas brillan con un torno verde-azulado de puro poder, condensando"
		" la energia mistica en su interior. Para liberar su poder usa \"descarga <objetivo>\".\n");
  	set_main_plural("imitaciones del Baston %^GREEN%^R%^RESET%^CYAN%^u%^BLUE%^ni%^RESET%^CYAN%^c%^GREEN%^o%^RESET%^");
  	add_plural("bastones");
  	add_plural("runicos");
	add_plural("imitaciones");
	// Esta funcion especifica lo poderosa que es el arma, de modo que su precio es proporcional a la magia que encierra
	// Tb hace que tarde mas en estropearse, y sobre todo especifica que el arma es magica, una cosa muy importante
	// porque algunos monstruos son inmunes a las armas no magicas.
	set_enchant(2);
	// Con esto le damos resistencia 100 contra los ataques de tipo electrico al jugador que lo lleve
	add_timed_property("electrical",100,999999999999999999999);
	// Este arma es solo para inmortales. Impedimos que el arma se pueda dejar con reset_drop()
	reset_drop();
	}

void init() {
  	::init();
   	add_action("relampago", "descarga");
	}


int relampago(string str) {
	// Declaracion de una variable de tipo 'object' llamada 'objetivo' . En ella guardaremos al objetivo de la descarga
	object objetivo;
	// Comprobamos si el baston se esta cargando y en ese caso impedimos el uso del poder del baston, acompanyado con un mensaje de error
	if (TO->query_timed_property("cargando")) return notify_fail("El poder de las runas aun es debil, espera a que se carguen.\n");
	// Vemos si se ha especificado un objetivo o solo se ha puesto "descarga". En este caso paramos con mensaje de error
	if (!str) return notify_fail("Uso: descarga <objetivo>\n");
	// Si hemos llegado aqui es que nos han especificado un objetivo (recordemos que en los return la accion se corta)
	// Pero el objetivo nos lo han pasado en texto (string) y nosotros necesitamos un objeto sobre el que aplicar su poder
	// Para encontrar al objeto cuyo nombre es un texto utilizamos la funcion find_object(), pero en este caso utilizaremos una
	// especializacion llamada find_living() que solo busca entre los objetos vivientes, para evitar que el poder se use con cosas.
	// find_living() necesita el parametro en minuscula, pero el player puede haberlo pasado en mayuscula. Para convertir de mayusculas
	// a minusculas usamos lower_case(), y despues el texto en minusculas se usa para buscar al player.
	// El objeto encontrado se guarda en la variable 'objetivo' que creamos mas arriba
	objetivo=find_living( lower_case(str) );
	// Puede que find_living() no haya encontrado al objetivo porque estuviese mal escrito o no este conectado. En ese caso a la
	// variable 'objetivo' no se le habra asignado nada, por lo que damos mensaje de error
	if (!objetivo) return notify_fail(CAP(str)+" no esta.\n");
	// Ahora miramos que tanto el objetivo como el player esten en la misma room. Para saber en que room esta un objeto usamos
	// environment(), pero al igual que TP y TO se puede reducir como ENV(). Si las rooms no coinciden damos mensaje de error
	if(ENV(objetivo)!=ENV(TP)) return notify_fail(objetivo->query_cap_name()+" esta demasiado lejos como para soltarle una descarga.\n");
	// Si hemos llegado aqui es que todo es correcto, asi que damos los mensajes adecuados
	tell_object(TP,"Apuntas con el "+TO->query_short()+" a "+objetivo->query_cap_name()+" y sueltas una tremenda descarga de poder runico.\n");
	tell_object(objetivo,TP->query_cap_name()+" te senyala con su "+TO->query_short()+" y de el brota una tremenda descarga de poder que te envuelve causandote un gran dolor!!!\n");
	tell_room(ENV(TP),objetivo->query_cap_name()+" grita de agonia mientras el poder del "+TO->query_short()+" de "+TP->query_short()+" le consume.\n",({objetivo,TP}));
	// Hacemos el danyo con la funcion adjust_hp() Sus parametros son:
	// - Ajuste: Si es positivo suben los hp y si es negativo bajan. Como es danyo lo ponemos negativo
	// - Causante: El objeto que ha causado la curacion o el danyo. Es importante por si muere saber quien ha propinado
	objetivo->adjust_hp(-random(DANYO),TP);
	// Generalmente si alguien nos hace danyo no nos quedamos tan tranquilos, asi que un player se pondria a atacar.
	// Desgraciadamente los Npcs no son tan listos asi que tendremos que empezar peleas por nuestra cuenta:
	TP->attack_by(objetivo);
	// Por ultimo le colocamos la propiedad cargando al baston, que impedira usarlo en un rato segun hemos definido al principio
	// Para anyadir propiedades temporales usamos add_timed_property() con los siguientes argumentos:
	// - Nombre de la propiedad
	// - Valor de la propiedad (aqui nos interesa que sea 1, que significa verdadero en los ifs)
	// - Tiempo en JB que dura la propiedad, al cabo de ese tiempo desaparece por si misma.
//        TO->add_timed_property("cargando",1,20); //Valar :P
//   return 1;//Valar :P
}

// Puede que hayais notado que ya no comento tan exhaustivamente como antes. Esto lo hago porque la mayoria de las cosas son comunes y se
// supone que ya las sabeis. Si no es asi, preguntadle a alguien que sepa o miraos los archivos anteriores

// NOTA: El JB es la unidad de tiempo basica del Mud. Es como un reloj interno que determina como ocurren las cosas y lo coordina todo.
// En realidad lo de JB es el nombre que le doy io. Su nombre real es "heart beat" y en Ninetears dura 1.8 segundos. Asi, el baston no
// podria volver a usarse en 20 JB, o lo que es lo mismo 20*1.8 = 36 segundos

// BUG: El baston deja soltar descargas aunque no lo tengamos empunyado.
// Tu tarea como aprendiz es aprender como arreglar ese bug que he dejado intencionadamente.


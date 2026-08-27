inherit "/obj/armour";

void setup() {
	set_base_armour("cuero"); // Pq si no no puedo llevarla por ser barbaro del caos xD
	set_name("armadura");
	add_alias("hielo");
	set_short("Armadura de %^BLACK%^BOLD%^Hielo Negro%^RESET%^");
	set_long(query_short()+"\nUna grotesca armadura fabricada a partir del Hielo Negro del Inframundo. Los brillos que desprende bajo la luz son fascinantes mezclas de belleza y terror.\n");
	set_main_plural("Armaduras de %^BLACK%^BOLD%^Hielo Negro%^RESET%^");
	add_plural("armaduras");
	add_plural("hielos");
	set_enchant(100);
	// Muy importante xD
	reset_drop();
	// Con esto no puede robarse
	add_property("no_steal",1);
	// Resistencia al frio y malus contra el fuego
	add_timed_property("cold",100,999999999999999999);
	add_timed_property("fire",-20,999999999999999999);
	}

void init() {
	::init();
	add_action("do_maniobra","666");
	}

int do_maniobra() {
	// Declaramos la variable 'victimas' que almacena a todos los que van a morir :)
	// El * es porque es un conjunto
	object *victimas;
	// Comprobamos que el que la usa es Vilat, porque solo el puede usarla xDDDD
	if (TP->query_cap_name()!="Kryger") return notify_fail("Solo Kryger, Senyor de Ormerod, puede hacer la fantastica maniobra de la muerte.\n");
	// Comprobamos que la armadura la lleve puesta
	// member_array() comprueba si el primer parametro esta en la lista que se le pasa como segundo parametro. Si no es asi devuelve -1
	// query_worn_ob() devuelve la lista de objetos que se llevan vestidos
	if (member_array(TO,TP->query_worn_ob())==-1) return notify_fail("Tienes que tener puesta la Armadura para poder usar su poder.\n");
	// Pillamos la lista de enemigos:
	victimas=TP->query_attacker_list();
	// sizeof() mira cuantos elementos componen una lista. Aqui nos interesa comprobar si hay alguno
	if (!sizeof(victimas)) return notify_fail("Nadie a quien matar.\n");
	// Comezamos la rutina :)
	// switch() sirve para comprobar los distintos casos
	switch (sizeof(victimas)) {
		case 1: // Si solo hay un elemento en la lista de victimas
		tell_object(TP,"Golpeas en el estomago a "+victimas[0]->query_cap_name()+", quien empieza a sangrar por la boca y muere entre horribles convulsiones.\n"); /* El [0] es el primer elemento de la lista, el segundo seria [1] y asi */
		tell_object(victimas[0],TP->query_cap_name()+" te golpea fuertemente en el estomago. Cuando vas a responder, comprendes que el golpe te ha reventado los organos y caes al suelo entre horribles convulsiones.\n");
		tell_room(ENV(TP),TP->query_cap_name()+" golpea en el estomago a "+victimas[0]->query_cap_name()+", quien se dispone a responder, pero de repente un borboton de sangre surge de su boca... El golpe le ha reventado internamente!\n",({TP,victimas[0]}));
		break; // Importante el break porque si no se seguiria ejecutando lo del siguiente case
		// Este case significa "de 2 hasta "
		case 2..3:
		tell_object(TP,"Echas a correr y con el impulso te lanzas hacia adelante, clavando tu bota en la traquea de "+victimas[0]->query_cap_name()+", quien muere por asfixia.\n");
		tell_object(victimas[0],TP->query_cap_name()+" echa a correr y se impulsa hacia adelante, clavandote su bota en la traquea. Intentas tomar aire pero es inutil y mueres por asfixia.\n");
		tell_room(ENV(TP),TP->query_cap_name()+" echa a correr y se impulsa hacia adelante, para clavar su bota en la traquea de "+victimas[0]->query_cap_name()+", quien empieza a asfixiarse.\n",({TP,victimas[0]}));
		tell_object(TP,"Aprovechando el impulso, realizas un salto mortal sobre la cabeza de "+victimas[1]->query_cap_name()+" y estrechas tus piernas alrededor de su cuello. Apoyas las manos y voleteas tu cuerpo bruscamente, lo que parte su cuello antes de arrojarlo unos metros mas alla.\n");
		tell_object(victimas[1],"Aprovechando el impulso, "+TP->query_cap_name()+" salta por encima de tu cabeza. Sientes como sus piernas aprietan tu cuello y de repente todo ocurre muy deprisa... Lo ultimo de lo que te das cuenta es de que has muerto, tirado sobre el suelo con tu cuerpo descoyuntado.\n");
		tell_room(ENV(TP),"Aprovechando el impulso, "+TP->query_cap_name()+" salta sobre la cabeza de "+victimas[0]->query_cap_name()+" y estrecha las piernas alrededor de su cuello, antes de apoyar las manos en el suelo y girar rapidamente sobre si mismo. El cuerpo sin vida rueda unos metros levantando una nube de polvo, con el cuello doblado en un doloroso angulo.\n",({TP,victimas[1]}));
		// Comprobamos si hay que parar ya
		if (sizeof(victimas)==2) break;
		tell_object(TP,"Desde el suelo, sacudes un terrible taconazo a "+victimas[2]->query_cap_name()+" en la entrepierna, quien cae al suelo de rodillas. Te levantas y de un golpe en la espalda le haces caer de bruces, para despues romper su craneo de un pisoton en la cabeza. Te sientes satisfecho cuando sus sesos se esparcen por ahi.\n");
		tell_object(victimas[2],TP->query_cap_name()+", tendido en el suelo boca abajo delante tuyo, te propina un dolorosisimo taconazo en la entrepierna. Caes de rodillas a causa del dolor, para recibir otro golpe en la espalda que te tira contra el suelo. Por ultimo sientes un fuerte impacto en el craneo y despues... nada mas.\n");
		tell_room(ENV(TP),TP->query_cap_name()+", esta tendido boca abajo delante de "+victimas[2]->query_cap_name()+". Cuando parece que todo esta perdido para el, le sacude a su nueva victima un doloroso taconazo en la entrepierna, haciendo que caiga de rodillas a causa del dolor. Despues se levanta y le golpea en la espalda, haciendole caer de bruces, para por ultimo acabar con su vida con un pisoton en la cabeza que esparce una nube de sesos por la zona.\n",({TP,victimas[2]}));
		// Weno ya me he cansao de escribir, aunque pordria seguir :)
		break;
		default: // default es cualquier caso que no controle ningun case (significa 'por defecto')
		tell_object(TP,"Envuelves la estancia en tu conocido fuego azul, acabando con todos tus enemigos.\n");
		tell_room(ENV(TP),TP->query_cap_name()+" inunda la habitacion en sus conocidas llamas indigo, causando la muerte de sus enemigos.\n");
		break;
		} // Cerramos el switch
	// Se supone que todos los enemigos han muerto segun los textos asi que
	for (int a=0;a<sizeof(victimas);a++) victimas[a]->do_death(TP); // El for viene a ser que ejecuta lo de despues para cada elemento de la lista de victimas, es decir el do_death(), es decir, la muerte
	return 1;
	}

inherit "/std/room";

#define LOGGER "/open/biblioteca/asamblea.txt"

string presi;
int last_say;
int log_souls;
int asamblea;
object x;

void setup() {
  	set_short("Sala de Asambleas del %^GREEN%^BOLD%^Paraiso%^RESET%^");
  	set_long(query_short()+"\nEn esta sala se respira lujo por los cuatro costados: Las paredes estan forradas con roble antiguo y al fondo de la habitacion hay una inmensa estanteria donde se guarda el registro de todas las asambleas realizadas por los Inmortales. Junto a cada asiento -increiblemente comodos todos ellos- hay un dispensador de bebidas al gusto del consumidor, por supuesto completamente gratis. Pero lo que mas destaca es un gran sillon de cuero, con un atril delante. Junto a el hay un joven escribano presto a tomar nota de todo cuanto se diga.\n");
  	add_exit("sur","/w/common","corridor");

  	add_item(({"pared","paredes","techo"}),"Las paredes y el techo son de roble artesonado.\n");
  	add_item("libro","Los estantes estan llenos de pesados volumenes con la pasta de cuero. Algunos parecen realmente antiguos.\n");
  	add_item("dispensador","Un tubo opaco de cristal por el que saldra la bebida que pidas.\n");
  	add_item(({"asiento","asientos","silla","sillas"}),"Los asientos reclinables son muy confortables e incluso tienen un reposapies.\n");
	add_item("sillon","Un lujoso sillon de cuero para el Presidente de la Asamblea. Parece realmente comodo.\n");
  	add_item("reposapies","Es un placer disfrutar de estos esplendidos reposapies, deberias agradecerselo al Inmortal que los puso aqui.\n");
  	add_item("escribano","Un hombre muy joven, elegido por los Inmortales por su agilidad con la pluma para tomar cuidadosamente nota de todo cuanto se habla en la reunion. Nadie recuerda desde cuando lleva aqui, pero se mantiene joven porque los Dioses le concedieron la juventud eterna a cambio de sus servicios.\n");
	}

void init() {
  	string str;
	::init();
  	add_action("log_mode","log");
  	add_action("appoint", "presidir");
    	add_action("bang", "orden");
	add_action("terminar", "fin");
        }

int appoint(string str) {
  	object ob;
	if (!presi&&TP->query_creator()&&(!str||str==TP->query_name())) {
		asamblea=1;
		last_say = time();
		write_file(LOGGER,"\n* * * * * NUEVA ASAMBLEA ("+ctime(time())+") * * * * *\n");
		tell_object(TP,"Ocupas el sillon presidencial.\n");
		tell_room(TO,TP->query_cap_name()+" ocupa el asiento presidencial.\n",TP);
		presi=TP->query_name();
		return 1;
		}

  	if (presi && TP->query_name() != presi) return notify_fail("Ya hay alguien presidiendo la asamblea, que es "+capitalize(presi)+".\n");
	if (!str) return notify_fail("Ya estas presidiendo la asamblea, no te vale con eso?\n");
	ob=find_player(str);
  	if (!ob||environment(ob)!=environment(TP)) return notify_fail(capitalize(str)+" no esta aqui.\n");
	if(!ob->query_creator()) return notify_fail(capitalize(str)+" no esta preparado para presidir una Asamblea de Inmortales.\n");

	presi = str;
	if (!asamblea) write_file(LOGGER,"\n* * * * * NUEVA ASAMBLEA ("+ctime(time())+") * * * * *\n");
	asamblea=1;
	last_say = time();
	tell_room(TO,TP->query_cap_name()+" cede a "+capitalize(str)+" el sillon presidencial.\n", ({ob,TP}));
  	tell_object(ob, TP->query_cap_name()+" te cede el sillon presidencial.\n");
	tell_object(TP, "Cedes a "+capitalize(str)+" el sillon presidencial.\n");
  	return 1;
	}

int bang(string str) {
  	if (TP->query_name() != presi) return notify_fail("Solamente el Presidente de la Asamblea puede usar el mazo.\n");
	tell_room(TO,TP->query_cap_name()+" golpea la mesa con fuerza con su mazo: %^BOLD%^MAGENTA%^Silencio!!!%^RESET%^\n");
  	return 1;
	}

int log_mode(string str) {
	if(TP->query_name()!=presi) return notify_fail("Solo el Presidente de la Asamblea puede decidir sobre eso.\n");
  	log_souls = !log_souls;
	if(log_souls) tell_object(this_player(),"Los souls seran logueados.\n");
  	else tell_object(this_player(),"Los souls no seran logueados.\n");
  	return 1;
	}

void check_expired() {
	if (!asamblea) return;

  	if( (time() - last_say) > 600 ) {
		write_file(LOGGER,"* * * * *  FIN  ASAMBLEA ("+ctime(time())+") * * * * *\n");
		asamblea=0;
		}
	last_say = time();
	}

void event_person_say(object ob, string start, string rest) {
	if(!asamblea) return;
  	check_expired();
  	write_file(LOGGER,start+rest+"\n");
	}

void event_say(object ob, string rest) {
	if(!asamblea) return;
	check_expired();
  	write_file(LOGGER,rest);
	}

void event_soul(object ob, string rest) {
	if(!asamblea) return;
	if(!log_souls) return;
    	check_expired();
    	write_file(LOGGER,rest);
  	}

int terminar(string str) {
	if(TP->query_name()!=presi) return notify_fail("Solo el Presidente de la Asamblea puede dar por terminada la sesion.\n");
	tell_object(TP,"Das por terminada la sesion.\n");
	tell_room(TO,TP->query_cap_name()+" levanta la sesion.\n",TP);
	write_file(LOGGER,"\n* * * * *  FIN  ASAMBLEA ("+ctime(time())+") * * * * *\n");
	asamblea=0;
	return 1;
	}
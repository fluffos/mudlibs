//Gareth 8.12.02

#include "/d/gremios/path.h"
inherit "/std/room";
string presi;
object board;

void setup() {
	set_short("%^RED%^%^BOLD%^Gremio de los Guerreros Turkhun: %^WHITE%^%^BOLD%^Sala de Asambleas%^RESET%^");
	set_long(query_short()+"\n\n    En esta espaciosa sala se reune el Consejo de  Guerreros Turkhun "
					"para tomar las decisiones que afectan al "
					"gremio. La habitacion esta repleta de lujosas sillas"
					" de color rojo, adaptadas a la altura de los Duergars"
					", alrededor de una gran mesa de madera negra. "
					"Presidiendo la mesa hay una silla de color negro, "
					"destinada al Jefe del Consejo.\n");
	
	add_item("mesa","Una gran mesa de madera negra rectangular, que ocupa casi toda la sala.\n");
	add_item("sillas","Lujosas sillas de madera forradas con una tela roja estan colocadas alrededor de la mesa.\n");

	add_clone("/obj/misc/board");
	add_exit("fuera",GUILD_TURKHUN+"guildroom","door");
}

void reset () {
	if (!board) {
		board=clone_object("/obj/misc/board");
		board->move(TO);
		board->set_datafile("consejo_khurgars");
	}	
}

void init() {
  	string str;
	::init();
  	add_action("appoint", "presidir");
    	add_action("bang", "orden");
	add_action("terminar", "fin");
        }

int appoint(string str) {
  	object ob;
	if (!presi&&TP->query_creator()&&(!str||str==TP->query_name())) {
		tell_object(TP,"Ocupas el sillon presidencial.\n");
		tell_room(TO,TP->query_cap_name()+" ocupa el asiento presidencial.\n",TP);
		presi=TP->query_name();
		return 1;
		}

  	if (presi && TP->query_name() != presi) return notify_fail("Ya hay alguien presidiendo la asamblea, que es "+capitalize(presi)+".\n");
	if (!str) return notify_fail("Ya estas presidiendo la asamblea, no te vale con eso?\n");
	ob=find_player(str);
  	if (!ob||environment(ob)!=environment(TP)) return notify_fail(capitalize(str)+" no esta aqui.\n");
	
	presi = str;
	tell_room(TO,TP->query_cap_name()+" cede a "+capitalize(str)+" el sillon presidencial.\n", ({ob,TP}));
  	tell_object(ob, TP->query_cap_name()+" te cede el sillon presidencial.\n");
	tell_object(TP, "Cedes a "+capitalize(str)+" el sillon presidencial.\n");
  	return 1;
	}

int bang(string str) {
  	if (TP->query_name() != presi) return notify_fail("Solamente el Jefe del Consejo puede usar el mazo.\n");
	tell_room(TO,TP->query_cap_name()+" golpea la mesa con fuerza con su mazo: %^BOLD%^MAGENTA%^Silencio!!!%^RESET%^\n");
  	return 1;
	}

int terminar(string str) {
	if(TP->query_name()!=presi) return notify_fail("Solo el Jefe del Consejo puede dar por terminada la sesion.\n");
	tell_object(TP,"Das por terminada la sesion.\n");
	tell_room(TO,TP->query_cap_name()+" levanta la sesion.\n",TP);
	return 1;
	}
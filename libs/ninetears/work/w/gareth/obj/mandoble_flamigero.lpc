#define CREATOR "Gareth"
#define DANYO 650
inherit "/obj/weapon";

void setup() {
  	set_base_weapon("mandoble");
  	set_name("mandoble flamigero");
  	add_alias("mandoble");
	add_alias("flamigero");
  	set_short("Mandoble %^RED%^%^BOLD%^Flamigero%^RESET%^");
  	set_long("Un gran mandoble de empunyadura negra ribeteada en oro."
	     " La hoja parece estar compuesta de un fuego rojo como la sangre, aunque no desprende luz ni calor."
		" El mandoble otorga resistencia al fuego a cualquiera que la empunye, y permite lanzar una bola de fuego a un objetivo. Para lanzar la bola, usa /llamas <objetivo>.\n");
  	set_main_plural("Mandobles %^RED%^%^BOLD%^Flamigeros%^RESET%^");
  	add_plural("mandobles");
  	add_plural("flamigeros");
	add_plural("imitaciones");
	
	set_enchant(2);
	add_timed_property("fire",100,999999999999999999999);
	reset_drop();
	}
	
void init() {
  	::init();
   	add_action("fuego", "llamas");
	}


int fuego(string str) {
	object objetivo;
	if (TP->query_dead()) return notify_fail("Estas muerto, no puedes utilizar la Cota.\n");
	if (TO->query_timed_property("cargando")) return notify_fail("Las llamas no estan lo suficientemente ardientes todavia.\n");
	if (!str) return notify_fail("Uso: llamas <objetivo>\n");
	if (member_array(TO,TP->query_held_ob())==-1) return notify_fail("Tienes que tener empunyado el Mandoble para usar su poder.\n");
	
	objetivo=find_living( lower_case(str) );
	if (!objetivo) return notify_fail(CAP(str)+" no se encuentra aqui.\n");
	if(ENV(objetivo)!=ENV(TP)) return notify_fail(objetivo->query_cap_name()+" esta fuera del radio de accion de la bola.\n");
	
	tell_object(TP,"Alzas el "+TO->query_short()+" hacia el cielo un segundo, para despues senyalar a "+objetivo->query_cap_name()+" y la bola de fuego estalla contra el.\n");
	tell_object(objetivo,TP->query_cap_name()+" te senyala con su "+TO->query_short()+" y una bola de fuego estalla contra ti, produciendote graves quemaduras!!\n");
	tell_room(ENV(TP),objetivo->query_cap_name()+" grita de dolor mientras la bola de fuego del "+TO->query_short()+" estalla contra el.\n",({objetivo,TP}));
	objetivo->adjust_hp(-random(DANYO),TP);
	
	TP->attack_by(objetivo);
	TO->add_timed_property("cargando",1,60);
	return 1;
}

void write_message(string happen, int dam, string w_type, object me, object him)
{
	tell_room(ENV(me), me->QCN + " golpea con su "+w_type+" a "+him->QCN+", produciendole quemaduras por todo el cuerpo.\n", ({me,him}));
	tell_object(me, "Golpeas con tu "+w_type+" a "+him->QCN+" produciendole serias quemaduras.\n");
	tell_object(him, me->QCN+" te golpea con su "+w_type+". Sientes un gran escozor debido a las quemaduras.\n");
		
}	
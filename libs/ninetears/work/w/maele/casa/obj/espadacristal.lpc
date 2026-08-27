#define DANYO 100

inherit "/obj/weapon";

void setup() {
  	set_base_weapon("espada");
  	set_name("espada de cristal");
  	add_alias("espada");
	add_alias("cristal");
  	set_short("Espada de %^BOLD%^CYAN%^Cristal%^RESET%^");
  	set_long("Una espada con el mango metalico, bastante liviano y la hoja hecha de cristal pulido y muy fino, lo que la hace realmente cortante. El material del que esta hecha refleja los objetos que tiene alrededor.\n");
  	set_main_plural("Espadas de %^BOLD%^CYAN%^Cristal%^RESET%^");
  	add_plural("espadas");
  	add_plural("cristales");
	set_enchant(2);
	add_timed_property("cold",100,999999999999999999999);
	reset_drop();
	}

void init() {
  	::init();
   	add_action("llamarada", "quemar");
	}


int llamarada(string str) {
	object objetivo;
	if (member_array(TO,TP->query_held_ob())==-1) return notify_fail("Tienes que estar empunyando la espada para poder usarla.\n");
	if (TO->query_timed_property("cargando")) return notify_fail("El poder de las runas aun es debil, espera a que se carguen.\n");
	if (!str) return notify_fail("Uso: quemar <objetivo>\n");
	objetivo=find_living( lower_case(str) );
	if (!objetivo) return notify_fail(CAP(str)+" no esta.\n");
	if(ENV(objetivo)!=ENV(TP)) return notify_fail(objetivo->query_cap_name()+" esta demasiado lejos como para soltarle una descarga.\n");
	tell_object(TP,"Apuntas con el "+TO->query_short()+" a "+objetivo->query_cap_name()+" y sueltas una tremenda llamarada de fuego.\n");
	tell_object(objetivo,TP->query_cap_name()+" te senyala con su "+TO->query_short()+" y de su punta brota una tremenda llamarada de fuego que te envuelve causandote un gran dolor!!!\n");
	tell_room(ENV(TP),objetivo->query_cap_name()+" grita de de dolor mientras el fuego que brota de la "+TO->query_short()+" de "+TP->query_short()+" le quema.\n",({objetivo,TP}));
	objetivo->adjust_hp(-(DANYO),TP);
	TP->attack_by(objetivo);
	TO->add_timed_property("cargando",1,20);
	return 1;
	}
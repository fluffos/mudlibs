//Vilat 24.08.2002
//Capa base para el curtir

inherit "/obj/armour";

string MI_CAPA = "Bug";

void setup() {
	set_base_armour("piel");
	set_name("capa");
    	set_short("Capa");
    	set_main_plural("Capas");
	add_plural("capas");
    	set_ac(0,5);
    	call_out("query_origen", 0);
   	}

void init() {
	::init();
    	set_long("Una bonita y calida capa hecha con piel de "+CAP(MI_CAPA)+".\n");
    	}

void set_capa_name(string str) {
	MI_CAPA = str;
    	TO->add_property("origen", str);
    	TO->init();
	TO->set_short("Capa de piel de "+CAP(str));
	TO->set_main_plural("Capa de piel de "+CAP(str));
   	}

void query_origen() {
	MI_CAPA = TO->query_property("origen");
    	if(!MI_CAPA) MI_CAPA = "Bug";
	else {
		TO->set_short("Capa de piel de "+CAP(MI_CAPA));
		TO->set_main_plural("Capas de piel de "+CAP(MI_CAPA));
		}
   	}

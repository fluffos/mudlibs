//Vilat 20.08.2002
//Piel base para el despellejar

inherit "/std/item";

string MI_PIEL = "Bug";

int query_piel() { return 1; }

void setup() {
	set_name("piel");
    	set_short("Piel");
    	set_main_plural("Pieles");
	add_plural("pieles");
    	set_weight(100);
    	call_out("query_origen", 0);
   	}

void init() {
	::init();
    	set_long("Una piel de "+CAP(MI_PIEL)+" despellejada y lista para curtir.\n");
    	}

void set_piel_name(string str) {
	MI_PIEL = str;
    	TO->add_property("origen", str);
    	TO->init();
	TO->set_short("Piel de "+CAP(str));
	TO->set_main_plural("Piel de "+CAP(str));
   	}

void query_origen() {
	MI_PIEL = TO->query_property("origen");
    	if(!MI_PIEL) MI_PIEL = "Bug";
	else {
		TO->set_short("Piel de "+CAP(MI_PIEL));
		TO->set_main_plural("Pieles de "+CAP(MI_PIEL));
		}
   	}

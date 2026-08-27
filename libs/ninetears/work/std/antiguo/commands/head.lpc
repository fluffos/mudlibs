inherit "/std/item";

string MY_HEAD = "Unknown";
string query_hair_cut();

// useful'ish - Radix
int query_decapitated_head() { return 1; }

void setup()
   {set_name("cabeza");
    set_short("Cabeza decapitada");
    set_main_plural("Cabezas decapitadas");
	add_plural("cabezas");
    set_weight(50);
    call_out("GET_MY_NAME", 0);
   }

void init()
   {::init();
    set_long("Vomitas por el grima producido al mirar esta salvaje muestra "
        "de barbarie.  Brutalmente arrancada de los hombros, te preguntas "
        "donde estara el resto de "+query_hair_cut()+".\n\n");
    }

string query_hair_cut()
   {if(MY_HEAD == "Unknown") {
	if (!query_property("victim"))
       		return "su cuerpo";
	else
		return query_property("victim");
	}
    return MY_HEAD;
   }

void set_head_name(string str)
   {MY_HEAD = str;
    this_object()->add_property("victim", str);
    this_object()->init();
	TO->set_short("Cabeza de "+CAP(str));
	TO->set_main_plural("Cabezas de "+CAP(str));
   }

void GET_MY_NAME()
   {MY_HEAD = this_object()->query_property("victim");
    if(!MY_HEAD)
       MY_HEAD = "Unknown";
	else {
	TO->set_short("Cabeza de "+CAP(MY_HEAD));
	TO->set_main_plural("Cabezas de "+CAP(MY_HEAD));
	}
   }

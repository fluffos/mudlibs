inherit "/std/item";

string MY_CABELLERA = "Desconocido";
string query_hair_cut();

// useful'ish - Radix
int query_decapitated_head() { return 1; }

void setup()
   {set_name("cabellera");
    set_short("Cabellera");
    set_main_plural("Cabelleras");
    set_weight(50);
    call_out("GET_MY_NAME", 5);
   }

void init()
   {::init();
    set_long("Vomitas tu almuerzo al ver esta muestra de barbarie."
        " Una cabellera chorreando sangre y al verla te das cuenta"
        " que estas eran un resto de %^BOLD%^"+query_hair_cut()+"%^RESET%^"
        " .\n\n");
    }

string query_hair_cut()
   {if(MY_CABELLERA == "desconocido")
       return "el cuerpo";
    return MY_CABELLERA;
   }

void set_head_name(string str)
   {MY_CABELLERA = str;
    this_object()->add_property("victima", str);
    this_object()->init();
   }

void GET_MY_NAME()
   {MY_CABELLERA = this_object()->query_property("victima");
    if(!MY_CABELLERA)
       MY_CABELLERA = "Desconocido";
   }

inherit "/std/item";

string MY_HEAD = "desconocida";
string query_hair_cut();

// useful'ish - Radix
int query_decapitated_head() { return 1; }

void setup()
   {set_name("cabeza");
    set_short("Cabeza decapitada");
    set_main_plural("Cabezas decapitadas");
    set_weight(50);
    call_out("GET_MY_NAME", 5);
   }

void init()
   {::init();
    set_long("Vomitas tu desayuno al mirar esta expresion de barbarie "
        "tan salvaje. Salvajemente cortada de los hombros "
        "te preguntas donde estara el resto de "+query_hair_cut()+".\n\n");
    }

string query_hair_cut()
   {if(MY_HEAD == "desconocida")
       return "el cuerpo";
    return MY_HEAD;
   }

void set_head_name(string str)
   {MY_HEAD = str;
    this_object()->add_property("victim", str);
    this_object()->init();
   }

void GET_MY_NAME()
   {MY_HEAD = this_object()->query_property("victim");
    if(!MY_HEAD)
       MY_HEAD = "desconocida";
   }

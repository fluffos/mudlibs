//Gareth 16.12.02
//Cabeza, para el comando decapitar de los Khurgars

inherit "/std/item";

string MY_HEAD = "Unknown";
string query_hair_cut();

void setup() 
  { 
    set_name("cabeza");
    set_short("Cabeza cortada");
    set_main_plural("Cabezas cortadas");
    add_plural("cabezas");
    set_weight(30);
    call_out("GET_MY_NAME", 0);
  }
  
void init()
  {
    ::init();
    set_long("La repugnante cabeza te produce unas nauseas que te hacen "
             "vomitar. El cuello esta seccionado con un corte limpio. "
             "Parece que la cabeza pertenecia a "+query_hair_cut()+".\n\n");
  }

string query_hair_cut()
  {
    if(MY_HEAD == "Unknown")
  {
    if (!query_property("victim"))
    return "su cuerpo";
    else
    return query_property("victim");
  }
    return MY_HEAD;
  }

void set_head_name(string str)
  {
    MY_HEAD = str;
    this_object()->add_property("victim", str);
    this_object()->init();
    TO->set_short("Cabeza de "+CAP(str));
    TO->set_main_plural("Cabezas de "+CAP(str));
   }

void GET_MY_NAME()
  {
    MY_HEAD = this_object()->query_property("victim");
    if(!MY_HEAD)
    MY_HEAD = "Unknown";
    else
  {
    TO->set_short("Cabeza de "+CAP(MY_HEAD));
    TO->set_main_plural("Cabezas de "+CAP(MY_HEAD));
  }
}

int query_cabeza() {
	return 1;
}
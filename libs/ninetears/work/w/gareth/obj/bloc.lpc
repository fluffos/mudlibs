/*         Gareth 30.01.03
Una especie de libreta para apuntar cosas xD */

inherit "/std/item"; 
#define BLOC "/w/gareth/notas.txt"

void setup()  
{ 
 	set_name("bloc de notas");
	set_short("Bloc de notas");  
	set_long("Una pequenya libreta para apuntar cualquier cosa.\n");
	add_alias("bloc");
	add_alias("notas");
  	set_main_plural("blocs de notas"); 
  	add_plural("blocs");
  	set_weight(5);
 	add_property("no_steal",1);
}

void init() {
  	::init();
   	add_action("escribir", "apuntar");
   	add_action("leer", "leer");
	}

int escribir(string str) {
	write_file(BLOC,"\n- "+str+"");
	tell_object(TP,"Nota escrita correctamente.\n");
	return 1;
}

int leer(string str) {
	if (str=="bloc")
	{
		if (TP->query_cap_name()!="Gareth") return notify_fail("Solo Gareth puede leer el bloc.\n");
		tell_object(TP, read_file(BLOC));
		return 1;
	}
}
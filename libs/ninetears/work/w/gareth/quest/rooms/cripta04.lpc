/* Gareth 01.02.2003
Cripta, quest Khurgar */

inherit "/std/room";
#define ROOMS "/w/gareth/quest/rooms/"

void setup() {
	set_short("%^BLACK%^%^BOLD%^Cripta%^RESET%^");
	set_long(query_short()+"\n\n    Te encuentras en "
		"lo que parece un mausoleo muy antiguo,"
		" repleto de grietas y telaranyas en las paredes. El suelo"
		" esta cubierto por suciedad y cadaveres descompuestos, "
		"algunos cruelmente mutilados. A pesar de su abandono y de"
		" las numeros grietas en paredes y techos, la estructura de"
		" la cripta parece segura, y sientes una curiosidad que te"
		" obliga a seguir adelante. En esta sala el camino se divide"
		" en tres direcciones.\n\n");
   	add_smell(({"cripta","cadaveres","aire"}),"Hay un olor a muerte que "
   		"te produce nauseas.\n");
   	
   	add_exit("norte",ROOMS+"cripta06","corridor");
   	add_exit("noroeste",ROOMS+"cripta05","corridor");
   	add_exit("noreste",ROOMS+"cripta07","corridor");
   	add_exit("sur",ROOMS+"cripta04","corridor");
   	  	
  	add_clone(ROOMS+"tumulario",random(3));
}
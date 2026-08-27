/* Gareth 14.1.2003
Cripta, quest Khurgar */

inherit "/std/room";
#define ROOMS "/w/gareth/quest/rooms/"

void setup() {
	set_short("%^BLACK%^%^BOLD%^Cripta%^RESET%^");
	set_long(query_short()+"\n\n    Atraviesas el oscuro umbral de la "
		"cripta y entras en lo que parece un mausoleo muy antiguo,"
		" repleto de grietas y telaranyas en las paredes. El suelo"
		" esta cubierto por suciedad y cadaveres descompuestos, "
		"algunos cruelmente mutilados. A pesar de su abandono y de"
		" las numeros grietas en paredes y techos, la estructura de"
		" la cripta parece segura, y sientes una curiosidad que te"
		" obliga a seguir adelante.\n\n");
   	add_smell(({"cripta","cadaveres","aire"}),"Hay un olor a muerte que "
   		"te produce nauseas.\n");
   	add_exit("norte",ROOMS+"cripta04","corridor");
   	add_exit("este",ROOMS+"cripta02","door");
   	add_exit("oeste",ROOMS+"cripta03","door");
   	add_exit("fuera",ROOMS+"bosque15","door");
  	
  	add_clone(ROOMS+"tumulario",random(3));
}
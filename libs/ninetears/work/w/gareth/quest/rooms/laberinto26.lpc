/*       Gareth 10.02.2003
Laberinto del Minotauro, quest Khurgar */

inherit "/std/room";
#define ROOMS "/w/gareth/comandos/"

void setup() {
	set_short("%^BLACK%^%^BOLD%^Laberinto del Minotauro%^RESET%^");
	set_long(query_short()+"\n\n    Estas en un laberinto excavado "
		"en la roca, no se sabe por quien. Los corredores que "
		"lo forman estan ligeramente iluminados por la luz que "
		"atraviesa las grietas del techo, y por antorchas que "
		"cuelgan en las paredes. No parece haber ningun ser vivo"
		" por los alrededores y todo esta en silencio.n\ Un oscuro"
		" precicipio se abre a tus pies, impidiendote llegar al "
		"otro lado.\n\n");
   	add_sound(({"laberinto","aire"}),"Todo el laberinto esta sumido en "
   		"el silencio.\n");
   	add_exit("norte",ROOMS+"laberinto27","door");
   	modify_exit("norte",({"function","precicipio"}));
   	add_exit("sudeste",ROOMS+"laberinto24","standard");
}

void init() 
    {
    	::init();
    	add_action("saltar_precipicio","saltar");
    }

int norte()
    {
    	if (query_property("precicipio")==1)
    	    {
    		tell_object(TP,"El precipicio te impide llegar al otro lado.\n");
    		return 1;
    	    }
    	    else
    	    {
    	    	tell_object(TP,"Coges carrerilla, pegas un salto y logras "
    	    		"pasar al otro lado de la abertura.
    	    	TP->move(ROOMS+"laberinto27");
    	    	return 1;
    	    }
    }
    	
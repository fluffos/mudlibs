/*       Gareth 10.02.2003
Laberinto del Minotauro, quest Khurgar */

inherit "/std/room";
#define ROOMS "/w/gareth/comandos/"

void setup() {
	set_short("%^BLACK%^%^BOLD%^Laberinto del Minotauro%^RESET%^");
	set_long(query_short()+"\n\n    Esta sala parece el final del "
		"laberinto. Nada mas entrar, oyes a tus espaldas la "
		"puerta por la que llegaste cerrandose, y un gran "
		"Minotauro de unos dos metros de altura y muy "
		"corpulento aparece de las sombras. El minotauro se "
		"acerca lentamente hacia ti, y no tienes escapatoria.\n\n");
   	add_sound(({"laberinto","aire"}),"Todo el laberinto esta sumido en "
   		"el silencio.\n");
   	add_exit("sur",ROOMS+"laberinto26","standard");
   	modify_exit("sur",{("function","escapa_sur");
   	add_clone(ROOMS+"/npcs/minotauro",1);
   	add_property("cerrado",1);
}

void init()
    {
    	::init();
    }
    
int escapa_sur()
    {
    	if (query_property("cerrado")==1)
    	    {
    	    	tell_object(TP,"La puerta esta atrancada por el otro lado, no "
    	    		"puedes abrirla.\n");
    	    	return 1;
    	    }
    	    else
    	    {
    	    	TP->move(ROOMS+"laberinto26");	
    	    }  
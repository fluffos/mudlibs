// Vilat 18.11.2002 - Probando

inherit "/std/comando";

object *objetivos;

void setup() {
	poner_ayuda("\nSintaxis: enterrar [todo|<objetos>]\n\n"
    		"Este comando entierra todos los cadaveres de un lugar.  Lo que haya "
    		"en los cuerpos se entierra con ellos. Tambien permite enterrar objetos, pero por defecto entierra los cuerpos solo.\n\n");
	}

int precondiciones() {
	int i=0;
	string arg=lower_case(query_argumento());
	if(!arg||arg=="") arg="cuerpos";
	objetivos=all_inventory(ENV(query_ejecutor()));
	while(i<sizeof(objetivos)) {
		if(arg=="cuerpos"||arg=="cuerpo") {
			if(!objetivos[i]->query_corpse()) {
				objetivos-=({objetivos[i]});
				continue;
				}
			}
		else if(arg=="todo"||arg=="all") {
			if(objetivos[i]->get()) {
				objetivos-=({objetivos[i]});
				continue;
				}
			}
		else {
			if((member_array(arg,objetivos[i]->query_plurals()+({objetivos[i]->query_plural()}))==-1&&member_array(arg,objetivos[i]->query_alias()+({objetivos[i]->query_name()}))==-1)||objetivos[i]->get()) {
				objetivos-=({objetivos[i]});
				continue;
				}
			}
		i++;
		}
	if(!sizeof(objetivos)) {
		tell_object(query_ejecutor(),"Nada que enterrar.\n");
		return 0;
		}
	return 1;
	}

int efecto(string str,object x) {
  	int i,counter;
	string enterrado=query_multiple_short(objetivos);
	counter=sizeof(objetivos);
  	for (i=0;i<counter;i++) {
      		objetivos[i]->dest_me();
    		}
  	tell_object(x,"Entierras "+enterrado+" bajo tierra.\n");
	tell_room(ENV(x),x->QCN+" entierra "+enterrado+" bajo tierra.\n",x);
  	return 1;
	}

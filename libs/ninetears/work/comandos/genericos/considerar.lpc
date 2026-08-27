inherit "/std/comando";

void setup(){
	poner_ayuda("\nSintaxis: considerar <objetivo>\n\nEste comando permite conocer aproximadamente el nivel del objetivo, para asi saber si seria buena idea atacarle o mejor dejarle en paz.\n\n");
	}

int efecto(string str, object me){
	int dlvl,i,diff,mult,rate;
	string mess;
	object *objetivos;

	dlvl = me->query_level();
   	if (!dlvl) dlvl=1;
	objetivos=find_match(str,ENV(me));
	if(!sizeof(objetivos)) return notify_fail("Considerar a quien?\n");
	for(i=0;i<sizeof(objetivos);i++) {
		mess = "";
		if(!objetivos[i]->query_alive()) continue;
		if(objetivos[i]==me) continue;
		diff = dlvl - objetivos[i]->query_level();
     		(diff < 0 ? mult = -1 : mult = 1);
     		rate = diff*diff/dlvl + 1;
      		switch (rate*mult) {
       			case -1000..-10:
         		mess += "Seria una locura atacar a "+objetivos[i]->query_cap_name()+".\n";
       			break;
       			case -9..-8:
         		mess += objetivos[i]->query_cap_name()+" es un adversario temible.\n";
       			break;
       			case -7..-6:
         		mess += objetivos[i]->query_cap_name()+" es mucho mas fuerte que tu.\n";
       			break;
       			case -5..-4:
         		mess += objetivos[i]->query_cap_name()+" es mas fuerte que tu.\n";
       			break;
       			case -3..-2:
         		mess += objetivos[i]->query_cap_name()+" es un poco mas fuerte que tu.\n";
       			break;
       			case -1..1:
         		mess += "Podrias enfrentarte a "+objetivos[i]->query_cap_name()+" en igualdad de condiciones.\n";
       			break;
       			case 2..3:
         		mess += objetivos[i]->query_cap_name()+" es un poco mas debil que tu.\n";
       			break;
       			case 4..5:
         		mess += objetivos[i]->query_cap_name()+" es mas debil que tu.\n";
       			break;
       			case 6..7:
         		mess += objetivos[i]->query_cap_name()+" es mucho mas debil que tu.\n";
       			break;
       			case 8..9:
         		mess += "Casi te da pena lo que podrias hacerle a "+objetivos[i]->query_cap_name()+" si le atacases.\n";
         		break;
       			case 10..1000:
         		mess += objetivos[i]->query_cap_name()+" es tan debil que ni siquiera merece la pena el esfuerzo.\n";
       			break;
      			}
   		tell_object(me,mess);
		tell_object(objetivos[i],me->QCN+" te mira como si te estuviese analizando.\n");
		}
   	return 1;
	}


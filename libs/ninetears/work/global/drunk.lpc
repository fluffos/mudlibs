/* Propongo no quitar el black out, en cierto modo es una putada (me lo dice
mi experiencia como jugador en un mud con black out por borrachera xD) pero
creo que le daria mucho juego al intoxicar, ya que a quien se lo tires
corre el riesgo de irsele la pinza con el black out. Xerxes */
#include "player.h"
#include "living.h"

void do_wander(int bing);

nosave int drunkness, missing;

int drunk_heart_beat(int intox) {
  	int lvl,i, con;
  	object *obs;

  	if (intox <= 0) return 1;
  	if (missing) {
    		missing --;
    		return 0;
  		}
  	if (this_object()->query_property(PASSED_OUT_PROP)) return 0;
  	if (--drunkness > 0 && !missing) return 1;
  	con = TO->query_con();
  	if (random((50+con)*10) > intox) return 1;
  	drunkness = 20+random(30);
  	lvl = random(intox)/1500;
  	if (lvl > 3) lvl = 3;
  	switch (lvl) {
    		case 0 :
      		switch (random(5)) {
               		case 0 :
                       	tell_object(TO,"Eructas.\n");
			tell_room(ENV(TO),TO->query_cap_name()+" eructa.\n",TO);
			break;
               		case 1 :
                       	tell_object(TO,"Te pones a cantar.\n");
			tell_room(ENV(TO),TO->query_cap_name()+" balbucea algo incomprensible.\n",TO);
                        break;
               		case 2 :
                       	tell_object(TO,"Escupes.\n");
			tell_room(ENV(TO),TO->query_cap_name()+" te escupe.\n",TO);
                        break;
               		case 3 :
                       	tell_object(TO,"Vomitas.\n");
			tell_room(ENV(TO),TO->query_cap_name()+" echa hasta la primera papilla.\n",TO);
                        break;
               		case 4 :
                       	tell_object(TO,"Te ries.\n");
			tell_room(ENV(TO),TO->query_cap_name()+" se rie bajo los efectos de la borrachera.\n",TO);
                        break;
             		}
             	break;
    		case 1 :
             	switch (random(1)) {
               		case 0 :
                       	tell_object(TO,"Te tambaleas y te caes.\n");
			tell_room(ENV(TO),TO->query_cap_name()+" se tambalea y se cae.\n",TO);
                       	missing = 10+random(10);
                       	return 0;
                       	break;
             		}
             	break;
    		case 2 :
             	switch (random(2)) {
               		case 0 :
                      	obs = all_inventory();
                      	while (sizeof(obs) &&obs[(i=random(sizeof(obs)))]->move(environment())&&!obs[i]->short() && !obs[i]->query_worn()) obs = delete(obs, i, 1);
                      	if (!sizeof(obs)) break;
                       	tell_object(TO,"Ves tirado en el suelo un "+obs[i]->short()+" que se parece mucho a tu propio "+obs[i]->short()+".\n");
			tell_room(ENV(TO),"A "+TO->query_cap_name()+" se le cae su "+obs[i]->short()+".\n",TO);
                      	break;
               		case 1 :
                       	tell_object(TO,"Estas siendo atacado por el suelo.\n");
			tell_room(ENV(TO),TO->query_cap_name()+" cae dolorosamente contra el suelo.\n",TO);
                   	TO->adjust_hp(-random(5),TO);
                   	break;
             		}
             	break;
    		case 3 :
      		switch (random(2)) {
               		case 0 :
                        this_player()->add_property(PASSED_OUT_PROP,1);
                        call_out("remove_property",20+random(30),PASSED_OUT_PROP);
                       	tell_object(TO,"Se te nubla la vista y pierdes la consciencia.\n");
			tell_room(ENV(TO),TO->query_cap_name()+" se desploma inconsciente.\n",TO);
                        return 0;
                        break;
               		case 1 :
                       	do_wander(5+random(10));
                       	break;
             		}
             	break;
  		}
  	return 1;
	}

void do_wander(int num) {
  	string *direcs;
  	int i, bong;

  	if (num > 0) call_out("do_wander", 2+random(5), --num);

  	direcs = (mixed *)environment()->query_dest_dir();
  	while (!bong && sizeof(direcs)) {
    		i = random(sizeof(direcs)/2)*2;
    		this_object()->add_property(UNKNOWN_MOVE_PROP, 1);
    		bong = command(direcs[i]);
    		this_object()->remove_property(UNKNOWN_MOVE_PROP);
    		if (!bong) direcs = delete(direcs, i, 2);
  		}
	TO->look_me();
	}

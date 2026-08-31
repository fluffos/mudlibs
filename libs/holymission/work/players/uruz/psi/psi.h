#include "/players/trout/defs.h"

int check_bleed(){
  int ache, pain;
	ache=RAN(99);
	pain= TP()->query_hp()/2;
	switch(ache){
	    case 0..3:
			write("You go to use your powers, and feel a blood "+
			"vessel burst in your head. Blood pours out through "+
			"your nose!\n");
			TP()->hit_player(pain, 7);
			break;
	    case 4..6: write("You go to use your powers, and feel a massive "+
			"pain course through your head. It feels like someone"+
			" is pounding your head with a hammer!\n");
			MO(CO(PSI+"/obj/headache"), TP());
			break;
	    case 7..99: break;
	    }
	return 1;
	}

int check_cost(int cost){
	if(TP()->query_sp()< cost){
	    write("You are to tired....\n");
	    return 1;
	    }
	}

int check_level(int level){
	if(TPQL< level){
	    write("You are not experienced enough!\n");
	     return 1;
	     }
	}
int check_block(string str){
    object myamulet, amulet;
	myamulet=present("psi-amulet", TP());
	if(myamulet->query_mindblock()=="on"){
		write("You cannot perform any psionics while your mindblock "+
		"is up!\n");
		return 1;
		}
	}

int check_armour(){
    object *ob;
    int i;
  	ob= all_inventory(TP());
	for(i=0; i< sizeof(ob); i++){
	     if(ob[i]->query_worn() && ob[i]->query_weight() > 4){
		write("You cannot concentrate enough to use your psionics "+
		"while wearing your "+CAP(ob[i]->query_name())+".\n");
		return 1;
		}
	     }
	}

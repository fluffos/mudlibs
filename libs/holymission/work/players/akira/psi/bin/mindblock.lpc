#include "/players/akira/defs.h" 

main (string str){
    object amulet;

	amulet= present("psi-amulet", TP());
	    if(str=="on"){
		if(amulet->query_mindblock()=="on"){
		    write("You mindblock is already up!\n");
		    return 1;
		    }
		write("You raise your mind block.\n");
		amulet->set_mindblock("on");
		return 1;
		}
	if(str=="off"){
		if(amulet->query_mindblock()=="off"){
		    write("You mindblock is already off!\n");
		    return 1;
		    }
	    	amulet->set_mindblock("off");
		write("You lower your mindblock.\n");
		return 1;
		}
	}


//Lightning modified for alignment damage -- Redsexy Feb 1998

int preparing,timeslight,lightdam, points;

object *di;

void lightReset();
int lightS();
int lightD();
int lightT();
int light_all();
int light_heart();
int _free(string str);
int do_free(string str);
int spread(string str);
int do_spread(string str);
int _levitate();


void lightReset() {

    remove_call_out("light_heart");
    preparing = 0;
    timeslight = 0;
    lightdam = 0;
    points = 0;
}

  

int lightS() {

    if(TPL<10) return 6;
    if(TPL<20) return 4;
    return 2;
}


int lightD() {

if(this_player()->query_alignment() > 1000)        
    points = 4;
else if ((TP->ALIGN > 200) || (TP->ALIGN < 1000))  
    points = 6;
else if((TP->ALIGN > 40) || (TP->ALIGN < 200))
    points = 8;
else if((TP->ALIGN < 40) || (TP->ALIGN > -40))
    points = 3;
else if((TP->ALIGN < -999))   
    points = 14;
else if((TP->ALIGN < -200) || (TP->ALIGN > -999))
    points = 12;
else if(this_player()->query_alignment() < -40)    
    points = 10;   
else                                               
    points = 3;

    if(TPL<10) return 4*points;                   //  max 56 min 12
    if(TPL<15) return 5*points;			  //  max 70 min 15
    if(TPL<20) return 6*points;                   //  max 84 min 18
    if(TPL<25) return 7*points;                   //  max 98 min 21
    return 8*points;                              //  max 112 min 24
}


//LightT, not a diet aid but in fact all to do with preparing lightning

int lightT() {

    if(TPL<4) return 4;
    if(TPL<10) return 5;
    if(TPL<13) return 7;
    if(TPL<20) return 9;
    return 12;
    
}

int light_all() {

    int i;

    i=0;
    di=deep_inventory(ENV(TP));
    for(i=0;i<sizeof(di);i++)
	if(di[i]->id("can_light"))
	    if(di[i]->out(1)) ;
}

int light_heart() {

    int dam;

    timeslight++;
    if(timeslight+1>=lightT()) {
	write("You'd better free the energy.\n");
    }
    if(timeslight>lightT() && !random(TP->query_wis()/3)) {
	write("You free the energy uncontrolled and hurt yourself.\n");
	TP->hit_player(lightdam/10+5,7,0);
	lightReset();
	return 1;
    }

//dam and LightDam here

    dam += lightD();
    lightdam += lightD();
    if(TP->query_sp()-dam/2<0) {
	write("You are low at mental energy.\n");
	lightdam = 0;
        _free("lightning");
	return 1;
    }

    write("You feel the energy rising.\n");
    call_out("light_heart",lightS());
}

int _prepare(string str) {

    if(str!="lightning") return 1;
    if(preparing) {
	write("You are already preparing a lightning.\n");
	return 1;
  }
    write("You concentrate the Force on your hands.\n");
    preparing=1;
    light_heart();
    return 1;
}



int _free(string str) {

    if(find_call_out("do_free")!=-1) return 1;
    if(find_call_out("do_spread")!=-1) return 1;
    call_out("do_free", 1, str);
    return 1;
}

int do_free(string str) {

    string what,pro,whom;
    object att;
    int i;

    if(ENV(TP)->query_property("no_fight")) {
	write("You are not allowed to fight here!\n");
	lightReset();
	return 1;
    }

    if(str=="lightning") att=TP->query_attack();
    else {
	if(!str || sscanf(str,"%s %s %s",what,pro,whom)!=3) return 1;
	if(what!="lightning" && pro!="at" && pro!="to") return 1;
	att=present(whom,ENV(TP));
    }
    if(!att) {
	if(!preparing) {
	    write("Bolts of electricity swirl around your fingers.\n");
	    say("Bolts of electricity swirl around "+TP->NAME+"'s fingers.\n");
	    return 1;
	}
	write("You free the energy.\n");
	say(TP->NAME+" fills the area with a lightning effect.\n" +
		     "It only lasts for a second," +
		     " but nevertheless it is very strong.\n");
	light_all();
	if(present("corpse",ENV(TP))) {
	    i=0;
	    while(att=present("corpse",ENV(TP))) {
		destruct(att);
		i++;
	    }
	    if(i==1) {
		write("The corpse falls to ashes.\n");
		say("The corpse falls to ashes.\n");
	    }
	    else {
		write(i +" corpses falls to ashes.\n");
		say(i +" corpses falls to ashes.\n");
	    }
	}
	lightReset();
	return 1;
    }
    if(!living(att)) {
	write("That would have no effect.\n");
	return 1;
    }
    if(!preparing) {
	write("You throw a non-harmful lighting at "+att->query_name()+".\n");
	say(TP->NAME+" throws a non-harmful lightning at "+att->query_name()+".\n"+
	    CAP(TP->PRO)+ " glows for a second.\n");
	tell_object(att,TP->NAME+" throws a non-harmful lightning at you.\n"+
		"You glow for a second.\n");
	return 1;
    }
    if(TP->SP < 100) {       
        printf("You feel completely drained.\n");
    }


// Checks to make sure player has enough SP

    if(TP->SP < lightdam/(points/2)) {
        write("You cannot control the energy!!\n");
        write("Your power is too low to target the energy!\n");
        lightdam = 0;
        _free("lightning");
	  return 1;
  }

    write("You stretch forth your hands and a lightning strikes out of them "+
	  "towards "+ att->NAME+".\n");
    say(TP->NAME+" stretches forth "+TP->POS+" hands and strikes "+att->NAME+
	" with a lightning.\n",att);
    TELL(att,TP->NAME+" stretches forth "+TP->POS+" hands and throws a lightning "+
		"at you.\n");

// Calculates the hit for free lightning

    att->hit_player(lightdam); //add in a random 100 after testing
    TP->ADDSP(-(lightdam/(points/2)));
    lightReset();
    return 1;
}



int _spread(string str) {

    if(str == "lightning") {
	if(find_call_out("do_free")!=-1) return 1;
	if(find_call_out("do_spread")!=-1) return 1;
	call_out("do_spread", 1, str);
	return 1;
    }
    return 0;
}

int do_spread(string str) {

    object *ob,*gr;
    int i,j,enemys,dam;

    if(ENV(TP)->query_property("no_fight")) {
	write("You are not allowed to fight here!\n");
        lightReset();
	return 1;
    }
    if(str!="lightning") return 1;
    if(!preparing) {
	write("That would have no effect.\n");
	return 1;
    }

    enemys = 0;
    ob=all_inventory(ENV(TP));
    gr = TP->grmems_in_room();
    for (i=0,j=sizeof(ob); i < j; i++) {
	if ((ob[i]->query_npc() || ob[i]->query_player())
	    && ob[i]->query_guild()!=4 && ob[i]!=TP && member_array(ob[i],gr)==-1) {
	    enemys++;
	} 
    }

    if(!enemys) dam=0;
// Spread damage
    else dam=(timeslight*points*10)/enemys;

// Checks to make sure player has enough SP

    if(TP->SP < (dam/2)) {
        write("You cannot control the energy!!\n");
        write("Your power is too low to target the energy!\n");
        lightdam = 0;
        _free("lightning");
	  return 1;
  }


    write("You quickly turn around spreading the lightning all across the area.\n");
    say(TP->NAME+" turns around a spreads a lightning all across the area.\n");

    for(i=0;i<sizeof(ob);i++)
	if((ob[i]->query_npc()
		     || ob[i]->query_player())
		     && ob[i]->query_guild()!=4
		     && ob[i]!=TP
		     && member_array(ob[i],gr)==-1) {
	    write(ob[i]->query_name()+" has been hit.\n");
	    ob[i]->hit_player(dam,5,0);
	}
    
// Adjust damage to amount of SP left, not the other way around.
    if(TP->SP < dam) {
        printf("That was one hell of a lightning hit!\n");      
        TP->ADDSP(-dam/2);
        lightReset();
    }

else{
    	TP->ADDSP(-dam/2);
      lightReset();

    }

    return 1;
}

    
    

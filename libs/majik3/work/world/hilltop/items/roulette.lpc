// Code by Zimbe

inherit ITEM;

#define JACK(x) if(present("jack")) present("jack")->force_us(x)

int spinning=0; // The state of the wheel(0 not spinning, 1 spinning, 2 slowing down)
int bets_placed=0; // # of bets placed so far

int r; 
private mapping winnings=([]);
private string *result_color=({});
private string *result_state=({});

private object *better=({}); // List of betters
private string *bet_place=({}); // On what is the bet placed
private mapping bet_amount=([]); // The amount bet 

place_bet(int amount,int place); 
wheel();
clean();

create_item() {
    	set_name( ({"roulette","roulette wheel","wheel"}) );
    	set_short("A big and heavy roulette wheel");
    	set_long (
		"You are looking at a big and sturdy roulette wheel. There is a sign "
		+"that gives some information on how to play this game. You can \'bet\' on "
		+"all the numbers from 0 to 39, red and black, odd and even, 1-8 and "	
  		+"19-36, 1-12, 13-24, 25-36 and 00. The minimum bet is 2 gold coins "
		+"and a maximum is 10 gold coins. Type \"bets\" to see placed bets.\n");
	set_no_get();
	set_no_clean_up(1); 
}
                                                  
void init() {
	add_action("cmd_bet","bet");
	add_action("cmd_bets","bets");
}

cmd_bet(string str) {
	int amount;
	string place;
		
	if(present("jack")) {
	 if(str) {
	  if(sscanf(str,"%d coins on %s",amount,place)==2) {
	    if(2<=amount&&amount<=10000) {
	      if(THIS->query_money()>=amount) {
	       if((strlen(place)>=2&&!to_int(place))||strlen(place)>=3) {	
	      	switch(place) {
	      	  case "red":
	      	    place_bet(amount,"red");
	      	    break;
	      	  case "black":
	      	    place_bet(amount,"black");
	      	    break;
	      	  case "odd":
	      	    place_bet(amount,"odd");
	      	    break;
	      	  case "even":
	      	    place_bet(amount,"even");
	      	    break;
	      	  case "00":
	      	    place_bet(amount,"00");
	      	    break;
	      	  case "1-18":
	      	    place_bet(amount,"1-18");
	      	    break;
	      	  case "19-36":
	      	    place_bet(amount,"19-36");
	      	    break;
	      	  case "1-12":
	      	    place_bet(amount,"1-12");
	      	    break;
	      	  case "13-24":
	      	    place_bet(amount,"13-24");
	      	    break;
	      	  case "25-36":
	      	    place_bet(amount,"25-36");
	      	    break;
	      	  default: JACK("say "+THIS->query_cap_name()+", You can't bet on that!");
	        }
	       }
	       else if((strlen(place)<=2&&0<=to_int(place)&&to_int(place)<=36)) place_bet(amount,to_int(place));
	       else JACK("say "+THIS->query_cap_name()+", You can't bet on that!");
	      }
	      else JACK("say You don't have enough money, "+capitalize(THIS->query_name()));
	    }
	    else JACK("say The minimum bet is 2 coins and a maximum of 10000 coins");
	  }
	  else JACK("say :angrily "+THIS->query_cap_name()+", ya better lookie at the sign!");
	 }
	 else JACK("say :angrily "+THIS->query_cap_name()+", ya better lookie at the sign!");
	}
	else message("environment","There seems to be no one to take care of the roulette at the moment.\n",THIS);	
	return 1;
}       

cmd_bets() {
	if(sizeof(better)) {
	  message("environment", THIS->query_cap_name()+" looks at the bets.\n",ENV(THIS),THIS);
	  write("\nPlaced bets:\n");
	  for(int i=0;i<sizeof(better);i++) 
	    message("environment",better[i]->query_cap_name()+", "+bet_amount[i]+" coins on "+bet_place[i]+".\n",THIS);
	}
	else message("environment","There are no bets placed.\n",THIS);  	

	return 1;
}

place_bet(int amount,string place) {
	if(spinning<2) { // If the wheel hasnt started to slow down
	  if(!spinning) wheel(1);
	  message("environment",THIS->query_cap_name()+" places a bet.\n",ENV(THIS),THIS); 
	  message("environment","You place the bet.\n",THIS);	
	  THIS->add_money(-amount);
	  better+=({THIS});
	  bet_place+=({place});
	  bet_amount[bets_placed++]=amount;
	}
	else JACK("say No more bets, wait just a moment!");
}

wheel() {
	switch(spinning) {
	  case 0: // First bet starts the wheel
	    JACK("say Ok, place your bets and let me "+
	         "give the wheel a spin, you've got about one minute");
	    spinning=1;
	    call_out("wheel",30+random(30));
	    break;
	  case 1: // Starting to slow down, closing bets
	    message("environment","The wheel starts to slow down...\n",ENV(THIS));
	    JACK("say No more bets folks");
	    spinning=2;
	    call_out("wheel",15+random(5));
	    break;
	  case 2: // Random result, giving out winnings
	    r=random(37)+1;
	    if(r==37) result_color+=({"00"});
	    else if((r%2)==0) result_state+=({"even"});
	    else result_state+=({"odd"});
	    
	    if(r==1||r==3||r==5||r==7||r==9||r==12||r==14||r==16||r==18||r==19||r==21||r==23||r==25||r==27||r==30||r==32||r==34||r==36) 
	     result_color+=({"red"});
	    else if(r<37&&r>0) result_color+=({"black"});
	
	    message("environment","The ball stops on ",ENV(THIS));
	    if(r<37) message("environment",r+", "+result_color[0]+".\n",ENV(THIS));
	    else message("environment","00.\n",ENV(THIS));
	
	    for(int i=0;i<bets_placed;i++) {
	      if(result_color!="00"&&(result_color[0]==bet_place[i]||result_state[0]==bet_place[i])) 
	        winnings[i]=bet_amount[i]*2; 
	      else if(result_color[0]=="00"&&result_color[0]==bet_place[i])
	        winnings[i]=bet_amount[i]*25;
	      else if(r==bet_place[i]) winnings[i]=bet_amount[i]*25;
	      else winnings[i]=0;
	    }
	    if(present("jack")) {
	     for(int i=0;i<bets_placed;i++) {
	      if(winnings[i]&&present(better[i]->query_name())) {
	        message("environment","You win "+winnings[i]+" coins!\n",better[i]);
	        message("environment",better[i]->query_cap_name()+" wins "+winnings[i]+" coins.\n",ENV(better[i]),better[i]);
	        better[i]->add_money(winnings[i]);
	      }
	     }
	    }
	    clean();
	    break;
	}
}

clean() {
	better=({});
	winnings=([]);
	bet_amount=([]);
	bet_place=({});
	result_color=({});
	result_state=({});
	spinning=0,bets_placed=0;
}
                                                   
/* updated by namhas */

inherit ITEM;

#define JACK(x) present("jack")->force_us(x)

private int i,betsi,running,did_call,result,temppi;
private string *num_color_state=({});
private mapping bet_amount=([]);

private mapping bet_place=([]);
private object *better=({});

int bet(int an,int a);
int toka(string str);
int tellitys(string str);
int tellitys1(string str);
int run_wheel();
int run_wheel_pre();
int stop_wheel();
int winners();
int col_state_win(int mode);
int clean();
int say(string str);

create() {
    ::create();
    set_name("roulette");
    set_short("A big and heavy roulette wheel");
    set_long (
      "You are looking at a big and sturdy roulette wheel. There is a sign "
      +"that gives some information how to play this game. You can \"bet\" on "
      +"all the numbers from 0 to 39, red and black, odd and even, 1-8 and "
      +"19-36, 1-12, 13-24, 25-36 and 00. The minimum bet is 2 gold coins "
      +"and a maximum is 10 gold coins. Type \"bets\" to see placed bets.\n");
    set_no_get();
}

void init() {
    add_action("cmd_bet","bet");
    add_action("cmd_bets","bets");
}

int cmd_bet(string str) {
    string a;
    int an;

    if(str) {
	if(sscanf(str,"%d coins on %s",an,a)&&an!=0&&a!=0&&stringp(a)) {
	    if(an>=2&&an<=10) {
		if(this_player()->query_money()>=an) {
		    if(a=="odd") bet(an,37);
		    else if(a=="even") bet(an,38);
		    else if(a=="red") bet(an,39);
		    else if(a=="black") bet(an,40);
		    else if(a=="00") bet(an,41);
		    else if((string)a=="1-18") bet(an,42);
		    else if((string)a=="19-36") bet(an,43);
		    else if((string)a=="1-12") bet(an,44);
		    else if((string)a=="13-24") bet(an,45);
		    else if((string)a=="25-36") bet(an,46);
		    toka(str);
		}
		else JACK("say "+capitalize(THIS->query_name())+" does not have enough money!");
	    }
	    else JACK("say :proudly Sorry "+capitalize(THIS->query_name())+", minimum bet is 2 gps and maximum is 10 gps.");
	}
        else JACK("whisper "+THIS->query_name()+" Usage: bet <n> coins on <place>");
    }
    else JACK("say :angrily "+capitalize(THIS->query_name())+", ya better look at the sign!");
    return 1;
}

int say(string str) {}
int toka(string str) {
    int an,bn;
    string me = capitalize(THIS->query_name());

    if(sscanf(str,"%d coins on %d",an,bn)&&an!=0&&bn!=0) {
	if(bn<37&&bn>-1) {
	    if(an<=10&&an>=2) {
		if(this_player()->query_money()>=an) {
		    bet(an,bn);
		}
		else JACK("You don't have that much money, "+me+"!");
	    }
	}
	else JACK("You cannot bet on that number, "+me+"!\n");
    }
    return 1;
}

int bet(int amount,int place) {
    if(!running) {
	betsi=1;
	bet_amount[i]=amount;
	bet_place[i]=place;
	better+=({this_player()});
	this_player()->add_money(-amount);
	if(place<37) {
	    write("You place a bet of "+amount+" coins on "+place+".\n");
            tell_room (environment(), capitalize(THIS->query_name()) + " places a bet of "+amount+" coins on "+place+".\n", ({ THIS }));
	}
	else {
	    write("You place "+amount+" coins on ");
	    if(place==37) {write("odd");}
	    else if(place==38) {write("even");}
	    else if(place==39) {write("red");}
	    else if(place==40) {write("black");}
	    else if(place==41) {write("00");}
	    else if(place==42) {write("1-18");}
	    else if(place==43) {write("19-36");}
	    else if(place==44) {say("1-12");write("1-12");}
	    else if(place==45) {say("13-24");write("13-24");}
	    else if(place==46) {say("25-36");write("25-36");}
	    //       say(".\n");
	    write(".\n");
            tell_room (environment(), capitalize(THIS->query_name()) + " places a bet.\n");
	}
	i++;
	if(!did_call) {
	    call_out("run_wheel_pre",6+random(5));
	}
	did_call=1;
    }
    else
      JACK("No more bets, wait just a moment.");
    return 1;
}

int cmd_bets() {
    if(betsi==1) {
	write("\nPlaced bets:\n");
	for(int abu=0;abu<sizeof(better);abu++) {
	    write(capitalize(better[abu]->query_name()));
	    write(", ");
	    write(bet_amount[abu]);
	    write(" coins on ");
	    if(bet_place[abu]<37) write(bet_place[abu]);
	    else {
		if(bet_place[abu]==37) tellitys1("odd");
		else if(bet_place[abu]==38) write("even");
		else if(bet_place[abu]==39) write("red");
		else if(bet_place[abu]==40) write("black");
		else if(bet_place[abu]==41) write("00");
		else if(bet_place[abu]==42) write("1-18");
		else if(bet_place[abu]==43) write("19-36");
		else if(bet_place[abu]==44) write("1-12");
		else if(bet_place[abu]==45) write("13-24");
		else if(bet_place[abu]==46) write("25-36");
	    }
	    write("\n");
	}
    }
    else write("No bets placed.\n");
    return 1;

}
int tellitys(string str) {
    tell_room(environment(this_object()),str);
}

int tellitys1(string str) {
    tell_object(this_player(),str);
}

int stop_wheel() {
    int t;
    t=result=random(37);
    tellitys("The ball stops on ");
    if(result) tell_room(environment(this_object()),result);
    if(t==1||t==3||t==5||t==7||t==9||t==12||t==14||t==16||t==18||t==19||
      t==21||t==23||t==25||t==27||t==30||t==32||t==34||t==36) {
	num_color_state+=({"red"});
    }
    else if(t<37&&t!=0) num_color_state+=({"black"});
    if(t==2||t==4||t==6||t==8||t==10||t==12||t==14||t==16||t==18||t==20||
      t==22||t==24||t==26||t==28||t==30||t==32||t==34||t==36) {
	num_color_state+=({"even"});
    }
    else if(t<37&&t!=0) num_color_state+=({"odd"});
    if(result) {
	tellitys(", ");
	tellitys(num_color_state[0]);
    }
    else if(!result) {tellitys("00");num_color_state+=({"zero"});}
    tellitys(".\n");
    winners();
}

int run_wheel_pre() {
    call_out("run_wheel",30+random(30));
    JACK("Place your bets and let me give the wheel a spin. You've got amount one minute!");
}

int run_wheel() {
    tellitys("The wheel starts to slow down...\n");
    JACK("No more bets!");
    running=1;
    call_out("stop_wheel",15+random(5));
}

int winners() {
    object *ob=({});
    if(result) {
	for(int g=0;g<sizeof(better);g++) {
	    if(bet_place[g]<37) {
		if(bet_place[g]==result) {
		    ob+=({better[g]});
		    better[g]->add_money(bet_amount[g]*26);
		    tell_room(environment(this_object()),better[g]->query_name()+" wins "+bet_amount[g]*25+" coins!\n",ob);
		    tell_object(better[g],"You win "+bet_amount[g]*25+" coins!\n");
		}
	    }
	}
    }
    if(num_color_state[0]=="red") col_state_win(1);
    else if(num_color_state[0]=="black") col_state_win(2);
    else {
	temppi=2;
	col_state_win(5);
    }
}

int col_state_win(int mode) {
    int f;
    object *ob=({});
    if(mode==1) {
	for(f=0;f<sizeof(better);f++) {
	    if(bet_place[f]==39) {
		ob+=({better[f]});
		better[f]->add_money(2*bet_amount[f]);
		tell_room(environment(this_object()),better[f]->query_name()+
		  " wins "+2*bet_amount[f]+".\n",ob);
		tell_object(better[f],"You win "+2*bet_amount[f]+".\n");
	    }
	}
    }
    else if(mode==2) {
	for(f=0;f<sizeof(better);f++) {
	    if(bet_place[f]==40) {
		ob+=({better[f]});
		better[f]->add_money(2*bet_amount[f]);
		tell_room(environment(this_object()),better[f]->query_name()+
		  " wins "+2*bet_amount[f]+".\n",ob);
		tell_object(better[f],"You win "+2*bet_amount[f]+".\n");
	    }
	}
    }
    else if(mode==3) {
	for(f=0;f<sizeof(better);f++) {
	    if(bet_place[f]==38) {
		ob+=({better[f]});
		better[f]->add_money(2*bet_amount[f]);
		tell_room(environment(this_object()),better[f]->query_name()+
		  " wins "+2*bet_amount[f]+".\n",ob);
		tell_object(better[f],"You win "+2*bet_amount[f]+".\n");
	    }
	}
	temppi=1;
    }
    else if(mode==4) {
	for(f=0;f<sizeof(better);f++) {
	    if(bet_place[f]==37) {
		ob+=({better[f]});
		better[f]->add_money(2*bet_amount[f]);
		tell_room(environment(this_object()),better[f]->query_name()+
		  " wins "+2*bet_amount[f]+".\n",ob);
		tell_object(better[f],"You win "+2*bet_amount[f]+".\n");
	    }
	}
	temppi=1;
    }
    else if(mode==5) {
	if(num_color_state[0]=="zero") {
	    for(f=0;f<sizeof(better);f++) {
		if(bet_place[f]==41) {
		    ob+=({better[f]});
		    better[f]->add_money(26*bet_amount[f]);
		    tell_room(environment(this_object()),better[f]->query_name()+"
            wins "+26*bet_amount[f]+".\n",ob);
		    tell_object(better[f],"You win "+26*bet_amount[f]+".\n");
		}
	    }
	}
    }
    if(!temppi&&temppi!=2) {
	if(num_color_state[1]=="even") col_state_win(3);
	else if(num_color_state[1]=="odd") col_state_win(4);
    }
    if(result>=1&&result<=18) {
	for(f=0;f<sizeof(better);f++) {
	    if(bet_place[f]==42) {
		ob+=({better[f]});
		better[f]->add_money(2*bet_amount[f]);
		tell_room(environment(this_object()),better[f]->query_name()+"
           wins "+2*bet_amount[f]+".\n",ob);
		tell_object(better[f],"You win "+2*bet_amount[f]+".\n");
	    }
	}
    }
    else if(result>=19&&result<=36) {
	for(f=0;f<sizeof(better);f++) {
	    if(bet_place[f]==43) {
		ob+=({better[f]});
		better[f]->add_money(2*bet_amount[f]);
		tell_room(environment(this_object()),better[f]->query_name()+"
           wins "+2*bet_amount[f]+".\n",ob);
		tell_object(better[f],"You win "+2*bet_amount[f]+".\n");
	    }
	}
    }
    if(result>=1&&result<=12) {
	for(f=0;f<sizeof(better);f++) {
	    if(bet_place[f]==44) {
		ob+=({better[f]});
		better[f]->add_money(3*bet_amount[f]);
		tell_room(environment(this_object()),better[f]->query_name()+"
           wins "+3*bet_amount[f]+".\n",ob);
		tell_object(better[f],"You win "+3*bet_amount[f]+".\n");
	    }
	}
    }
    else if(result>=13&&result<=24) {
	for(f=0;f<sizeof(better);f++) {
	    if(bet_place[f]==45) {
		ob+=({better[f]});
		better[f]->add_money(3*bet_amount[f]);
		tell_room(environment(this_object()),better[f]->query_name()+"
           wins "+3*bet_amount[f]+".\n",ob);
		tell_object(better[f],"You win "+3*bet_amount[f]+".\n");
	    }
	}
    }
    else if(result>=25&&result<=36) {
	for(f=0;f<sizeof(better);f++) {
	    if(bet_place[f]==46) {
		ob+=({better[f]});
		better[f]->add_money(3*bet_amount[f]);
		tell_room(environment(this_object()),better[f]->query_name()+"
           wins "+3*bet_amount[f]+".\n",ob);
		tell_object(better[f],"You win "+3*bet_amount[f]+".\n");
	    }
	}
    }
    clean();
}

int clean() {
    num_color_state=({});
    better=({});
    bet_amount=([]);
    bet_place=([]);
    running=0;did_call=0;i=0;betsi=0;temppi=0;
}

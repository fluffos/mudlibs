
#include "/u/d/dalceon/mydefines.h"
inherit MONSTER ;

mixed know_base;
int following;
mixed temp_dir;


int my_commands(string);
int size();
int follow_me(string);
int dalceon();
int distance(mixed);
int i_know(string);
void display_tag();
void tired();
void agree();
void confused();
void finalize_know();
int la_tag(string);
string here();


void create () {
    ::create() ;
    seteuid(getuid()) ;
    temp_dir = allocate(50);
    know_base = allocate(5);
    for(int i=0;i<5;i++)
	know_base[i] = allocate(50);
    know_base[0] = ({ "city","east","east","east" });
    set ("short", "Dalceon's Buddy") ;
    set ("long", "Dalceon doesn't know what it is.\n");
    set ("id", ({ "buddy" }) ) ;
    set_size(10);
    set_name ("buddy") ;
    set ("gender", "neuter") ;
    set_align("le");
    enable_commands() ;
    set_living_name("buddy") ;
    set ("base_ac", 2);
    set("prevent_summon", 1);
}

void init() {
    add_action("my_commands", "say");
    add_action("la_tags", "look");
    add_action("follow_me",  "go");

}

int my_commands(string phrase) {

    string destination;
    if(sscanf(phrase,"follow me to %s",destination) && dalceon()) {
	if(i_know(destination)) {
	    confused();
	    return 0;
	}
	agree();
	following = 1;
	return 1;
    }
    if((phrase == "we are here") && dalceon()) {
	if(!following) {
	    confused();
	    return 0;
	}
	else {
	    finalize_know();
	    return 1;
	}
    }
    return 0;
}

int follow_me(string where) {

    if(!following) return 0;
    else{
	if(distance(temp_dir) < 48) {
	    temp_dir += where;
	    tell_object(DALCEON, "I'M GOING "+where+".\n");
	    command(where);
	}
	else {
	    tired();
	    return 0;
	}
    }
}

int distance( mixed d_array ) {
    return(sizeof(d_array));
}

int i_know(string place) {
    int i;
    i = 0;
    while(know_base[i][0] && (i < 48)) {
	if((know_base[i][48] == place) && (know_base[i][49]== here()))
	    return 1;
	i++;
    }
}

string here() {
    return(file_name(OENV));
}

int dalceon() {
    if(NAME == "Dalceon")
	return 1;
}

int la_tags(string item) {
    if(item == "buddy's tags") {
	display_tag();
	return 1;
    }
    return 0;
}

void display_tag() {

    int z;
    z = 0;
    if(size() == 0) {
	write("Buddy doesn't appear to know anything.\n");
	return 1;
    }
    else {
	for(int i=0;i < size();i++) {
	    while((know_base[i][z]!= 0) && (z<48)) {
		tell_object(DALCEON, know_base[i][z]+", ");
		z++;
	    }
	    tell_object(DALCEON, "\n");
	}
    }
}

void confused() {
    tell_room(OENV, "Buddy has a puzzled look on his face.\n");
}

void agree() {
    tell_room(OENV, "Buddy barks once.\n");
}

void disagree() {
    tell_room(OENV, "Buddy barks twice.\n");
}

void finalize_know() {
    know_base[size()] = temp_dir;
    temp_dir = ({});
}

int size() {
    int z;
    z = 0;

    while((know_base[z][0] !=0) && (z < 5))
	z++;
    return z;
}
void tired() {
    say("Buddy lies on the grown, he can't go any futher.\n");
}

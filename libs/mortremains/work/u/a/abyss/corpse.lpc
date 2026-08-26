// corpse.c
// Real old. Probably came with the mudlib.n, and probably took some
// substantial hacking at TMI-1, though no one put a header on saying so.
// Converted to 0.9.0 by Mobydick@TMI-2, 9-22-92, who added this header.

#include <mudlib.h>
inherit CONTAINER ;

#define DECAY_TIME 100000
string query_open_long() ;

string name;
int decay;

void prevent_insert() {
    write("The corpse is too big.\n");
    return ;
}

void create() {

    ::create() ;

    name = "noone";
    decay = 0;

    set ("short", "@@query_short") ;
    set ("capacity", 2000) ;
    set ("volume", 200) ;
    set ("prevent_insert", 1);
    set ("id", ({ "corpse", "remains", "body", "dead body",
      "corpse of " + name }) );
}

void set_name(string str) {

    name = str;

    if(name)  name = capitalize(name);
    set("name", name);
    set_open_long(query_open_long()) ;
    set("id", ({ "corpse", "remains", "body", "dead body",
      "corpse of " + name }) );
    set("cap_name", "@@query_short");
    call_out("decay", DECAY_TIME);
}

void decay() {

    decay -= 1;
    if (environment(TO)) {
	if (decay==0) 
	    tell_object(environment(TO),
	      "Maggots begin wriggling all over "+
	      TO->query_short() 
	      + ".\n") ;
    }
    set_open_long(query_open_long()) ;

    if (decay != -1) {
	call_out("decay", 20);
	return;
    }
    remove() ;
}

int can_put_and_get() { return 1; }

string query_short() {
    switch(decay) {
    case 3: return "fresh corpse of "+name ;
	break ;
    case 2: return "somewhat decayed remains of "+name ;
	break ;
    case 1: return "rotting corpse of "+name ;
	break ;
    default: return "maggot-ridden corpse of "+name ;
    }
}

string query_open_long() {
    switch(decay) {
    case 3: return "This is the fresh corpse of "+name+".\n"; break;
    case 2: return "These are the somewhat decayed remains of "+name+
	".\nA terrible stench is beginning to rise from them.\n"; break ;
    case 1: return "This is the rotting corpse of "+name+
	".\nThe smell from the corpse nearly makes you gag.\n"; break ;
    default: return "This is the badly decomposed corpse of "+name+
	".\nMaggots are wiggling all over the entire body, devouring it.\n";
	break ;
    }
}

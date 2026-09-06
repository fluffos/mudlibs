/*
** gate.c
**
** Large gate can be opened with lots of
** strength -> can't be done alone.
**
** (C) Tron.
**
*/
#include "/sys/configuration.h"

#include <stats.h>

string gate_type();

#define MIN_STRENGTH 45
#define NAME name+" to "+dir
#define CAP ((string)this_player()->query_name())

#define	STR	((int)this_player()->query_stat(ST_STR))
#define OPEN  1
#define CLOSE 0

#define ROUNDS 0
#define TSTR   1
#define O_C    2

int    open;
status hb;
object gate2;
string *names;
mapping pushers;
string name;
string gtype;
string long_desc;
mixed  dir;
int    min_str;
int    tstr;
int    move_speed;

void
set_open(status arg) { open = arg; }

void
set_dir(string str) { dir = str; }

void
set_name(string str) { name = str; }

void
set_other(object ob) { gate2=ob; }

void
set_str(int arg) {

    min_str = arg;
    gtype = gate_type();
}

void
set_long(string str) { long_desc = str; }

string
gate_type() {

    string str;

    switch(min_str) {

    case  0..1: str = "An ordinary ";
	break;
    case  2..5: str = "Quite a big ";
	break;
    case  6..10: str = "A big ";
	break;
    case  11..20:str ="A large ";
	break;
    case  21..35:str ="A very large ";
	break;
    case  36..55:str ="A huge ";
	break;
    case  56..100:str="A massive ";
	break;
    case  101..200:str="A gigantic ";
	break;

    default:str="A strange ";
    }

    return str;
}

void
tell_both(string str) {

    if(!str) return;

    tell_room(environment(), str);
    tell_room(environment(gate2), str);
}

mixed
pname() {
    mixed nam;

    nam=(string)this_player()->query_real_name();
    if(!nam)
	if(nam=(string)this_player()->query_name())
	    nam = lower_case(nam);

    return nam;
}

string
get_f() {
    string a, b;

    if(sscanf(object_name(this_object()), "%s#%s", a, b) == 2)
	return a;

    return object_name(this_object());
}

/*

 ARG: open?#dir1#name#dir2#name2#min_str,
      destination room

*/

varargs void
set_gate(string str, object ob) {
    mixed *args;
    mixed *dirs;
    mixed dest2;

    gate2 = clone_object(get_f());
    args = explode(str, "#");

    sscanf(args[0],"%d", open);
    dir  = args[1];
    name = args[2];
    sscanf(args[5],"%d", min_str);
    if(ob)
	move_object(this_object(), ob);
    else ob = environment();
    dirs = (mixed *)ob->query_dest_dir();
    dest2 = dirs[member(dirs, dir)-1];
    call_out("move_other_gate", 0, ({gate2, dest2}));
    gate2->set_open(open);
    gate2->set_dir(args[3]);
    gate2->set_name(args[4]);
    gate2->set_str(min_str);
    gate2->set_other(this_object());

    gtype = gate_type();
}

void
move_other_gate(mixed *arr) {
    move_object(arr[0], arr[1]);
}

int
abs(int i) {
    if(i<0) i=-i;

    return i;
}

varargs void
do_str(int str, status a) {
    int i;

    if(str==999) {
	pushers = ([]);
	names = ({});
	tstr = 0;
	move_speed = 0;
	gate2->recount_str();
	return;
    }

    tstr += str;
    i = abs(tstr) - min_str;

    move_speed = ((i > 0) ? i/3 + 1 : 0);

    if(tstr < 0) move_speed = -move_speed;

    if(!a)
	if(previous_object() == this_object())
	    gate2->do_str(str);
}

void
recount_str() {
    int i;
    int j;
    object obj;

    tstr = 0;

    for(i=0; i<sizeof(names); i+=3) {
	j = pushers[names[i]][TSTR];
	if (!pushers[names[i]][O_C]) j=-j;
	do_str(j, 1);
    }
}

status
id(string str) {
    return (str == name || str == NAME || str == "gate_ob");
}

string
short() {
    string str;

    if(open==10) str="(open)";
    else if(open) str="(partly open)";
    else str = "(closed)";

    return gtype+NAME+" "+str;
}

string query_name() { return short(); }

string
query_long() {
    if (long_desc) return long_desc + "\nYou might want to open or close it.";
    else return "It's " + gtype + NAME + ".\nYou might want to open or close it.";
}


void
create() {
    if(!name) name = "<no-name>";
    if(!min_str) {
	min_str = MIN_STRENGTH;
	gtype = gate_type();
    }
    if(!dir) dir = "<no-direction>";

    pushers = ([]);
    names = ({});
}

void
del_member(mixed i) {
    int j;

    j=pushers[i][TSTR];
    if(pushers[i][O_C]) j=-j;
    do_str(j);

    names -= ({i});
    pushers = m_delete(pushers, i);
}

void
init() {
    int i;

    if(pushers[pname()]) 
	del_member(pname());

    add_action("open", "open");
    add_action("close", "close");
    add_action("knock", "knock");
    add_action("stop", "stop");

    if(dir)
	add_action("do_dir", dir);

}

status
stop() {
    if(this_player()->query_attack() ||
      !pushers[pname()]) return 0;

    del_member(pname());

    write("You stop.\n");
    say(CAP+" stops moving the "+NAME+".\n");

    return 1;
}


status
do_dir() {
    if(open==10) return 0;
    if(open) write("You can't get yourself through.\n");
    else write("The "+NAME+" is closed!\n");

    return 1;
}

status
open(string str) {
    int i;
    string nam;

    if(!id(str)) return 0;

    if(open==10) {
	write("It's open already.\n");
	return 1;
    }

    nam=pname();
    i = member(names, nam);

    if(i==-1) {
	names += ({ nam });
	pushers+= ([ nam: ({i = STR, i+2, OPEN}) ]);
    }
    else {
	if(pushers[nam][O_C]) {
	    write("You are opening the "+NAME+" already.\n");
	    return 1;
	}
	pushers[nam][O_C] = OPEN;
	do_str(i = STR);// Clear the earlier str.
	write("You change your mind.\n");
    }

    if(!hb) {
	hb=1;
	configure_object(this_object(), OC_HEART_BEAT, 1);
    }

    do_str(i);

    write("You start opening the "+NAME+".\n");
    say(CAP+" starts opening the "+NAME+".\n");

    return 1;
}

status
close(string str) {
    int i;
    string nam;

    if(!id(str)) return 0;

    if(open==0) {
	write("It's closed already.\n");
	return 1;
    }
    nam=pname();
    i = member(names, nam);

    if(i==-1) {
	names += ({ nam });
	pushers+= ([ nam: ({i = STR, i+2, CLOSE}) ]);
    }
    else {
	if(!pushers[nam][O_C]) {
	    write("You are closing the "+NAME+" already.\n");
	    return 1;
	}
	pushers[nam][O_C] = CLOSE;
	do_str(-(i = STR));// Clear the earlier str.
	write("You change your mind.\n");
    }

    if(!hb) {
	hb=1;
	configure_object(this_object(), OC_HEART_BEAT, 1);
    }

    do_str(-i);

    write("You start closing the "+NAME+".\n");
    say(CAP+" starts closing the "+NAME+".\n");

    return 1;
}

status
knock(string str) {
    if(!id(str)) return 0;

    write("You knock the "+NAME+".\n");
    say(CAP+" knocks the "+NAME+".\n");

    tell_room(environment(gate2),
      "Knocking can be heard from the "+NAME+".\n");

    return 1;
}

void
other_move(int op) {

    open = op;
}

void
heart_beat() {
    int i;
    object ob;
    string str;
    string nam;

    for(i=0; i<sizeof(names); i++) {
	nam = names[i];

	if(!(ob=present(nam))) {
	    del_member(nam);
	    i--;
	    continue;
	}

	if(!pushers[nam][ROUNDS] || ob->query_attack()) {
	    tell_object(ob,"You can't continue anymore, you stop.\n");  
	    tell_room(environment(), ob->query_name()+
	      " stops moving the "+NAME+".\n", ({ob}));
	    del_member(nam);
	    i--;
	    continue;
	}
	-- pushers[nam][ROUNDS];
    }

    if(!move_speed) {
	for(i=0; i<sizeof(names); i+=3)
	    if(!random(3))
		tell_object(present(names[i]), "You keep trying...\n");
	    else if(!random(5))
		tell_object(present(names[i]),
		  "This is too heavy...you should stop.\n");
    }

    open += move_speed;

    if(open <= 0 && move_speed) {
	tell_room(environment(),"The "+NAME+" closes.\n");
	hb=0;
	open = 0;
    }
    else if(open >= 10 && move_speed) {
	tell_room(environment(),"The "+NAME+" opens.\n");
	hb=0;
	open = 10;
    }
    else if(move_speed) {
	if(move_speed < 0) str = " closes ";
	else str = " opens ";
	tell_both("Scriiich...the "+NAME+str+"a bit.\n");
    }

    gate2->other_move(open);

    if(!hb) {
	configure_object(this_object(), OC_HEART_BEAT, 0);
	do_str(999);
    }
}

// Mitch the maintainance guy.

#include "macrosoft.h"
#include "/u/c/cyanide/debug.h"

#define CLEAR       0
#define WAITING     1
#define ON_ELEV     2
#define AT_FLOOR    3
#define REFRACTORY  4

#define MIN_FL      1
#define MAX_FL      5

inherit MONSTER;

int flag = CLEAR, desired_floor = 0, timer;

void create() {
    object badge;

    ::create();
    set("short", "Mitch the Maintainance Guy");
    set("long", wrap("This is apparently one of the maintainance "+
	"guys; a fairly important one too, judging by the massive "+
	"ring of keys at his belt."
      ) );
    set("author", "cyanide");
    set("damage", ({ 1, 6 }) );
    set("id", ({ "guy", "mitch" }) );
    set_name("mitch");
    set("attrib1", "short");
    set("attrib2", "greasy");
    set("race", "dwarf");
    set_size(5);
    set("gender", "male");
    set("weapon_name", "fists");
    set_verbs( ({ "swing at" }) );
    credit(random(800));
    set("wimpy", 30);
    badge = clone_object(MS_OBJ("id_badge"));
    badge->set_color(MAX_FL);
    wear(badge);
    set("moving", 1);
    set("speed", 4);           
    set_level(12);
    set("prevent_summon", 1); 
}

void init() {
    string name = TP->query("cap_name");

    ::init();

    if (!TP->query("invisible"))
	if (!userp(TP) || name=="Bomber" || name=="Cyanide") 
	    call_out("force_me", 1, "say Mornin', "+name);
}

void heart_beat() {
    heal_up();
    continue_attack();

    // This is to keep him from wandering back into the elevator.

    switch(flag) {
    case CLEAR :
	move_around(); 
	if (environment() && environment()->button())
	    flag = WAITING;
	break;
    case REFRACTORY : move_around(); break;
    }

    if ((flag==REFRACTORY) && (timer-- < 1)) flag = CLEAR;
}

void receive_message(string Class, string message) {
    int floor;
    string action;

    if (sscanf(message, "The floor indicator changes to %d", floor)==1)  {
	if (floor == desired_floor) flag = AT_FLOOR;
	return ;
    }

    if (message=="The elevator doors slide open.\n") {
	switch (flag) {
	case WAITING : 
	    action = "go west"; 
	    break;
	case AT_FLOOR : 
	    action = "go out"; break;
	default : 
	    action = "whistle quietly"; break;
	}

	call_out("force_me", 1, action);
	return ;
    }

    if (message=="The elevator doors slide closed.\n") {    
	int tmp = desired_floor;

	switch (flag) {
	case WAITING :     
	    while (tmp==desired_floor) 
		tmp = random (MAX_FL - MIN_FL) + MIN_FL;

	    desired_floor = tmp;
	    action = "do swipe card, press button "+desired_floor;
	    flag = ON_ELEV;
	    break;          
	case AT_FLOOR : 
	    action = "go out"; 
	    flag = REFRACTORY;
	    timer = 50;
	    break;
	default : action = "whistle quietly"; break;
	}


	call_out("force_me", 1, action);
	return ;
    }
}

/* EOF */

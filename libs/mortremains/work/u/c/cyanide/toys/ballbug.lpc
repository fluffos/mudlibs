// Cyanide was bored.
// 14 March 2000

#include "/u/c/cyanide/debug.h"

#define ENVTO environment(this_object())

inherit MONSTER;

int flag = 0;

void create() {
    ::create();

    seteuid(getuid());

    set("race", "bug");
    set("author", "cyanide");
    set("short", "stone ball bug");
    set("long", @EndText
This is a small spherical animal, about the size of a basketball
and with a rock solid shell whic has the appearance of stone.
It has six crablike legs evenly distributed along its underside,
and has no apparent sensory organs. It is known in many areas
as a terrible nuisance.
EndText
    );
    set("moving", 1);
    set("speed", 2);
    set("prevent_summon", 1);
    set("id", ({ "bug", "ball bug", "stone ball bug" }) );
    set_name("bug");
    set_size(1);
    set("damage", ({ 2, 8 }) );
    set_verbs( ({ "bite" }) );
    set_level(2);
}

void init() {
    ::init();

    if (TP->query("race") == "bug") return;
    if (TP->query("name")=="alucard") return;

    if (living(TP) && !userp(TP)) kill_ob(TP);
}

void eat_ob( object ob ) {

    message("whatever", wrap("The stone ball bug bagins happily "+
	"munching on "+ob->query("short")+"."), 
      all_inventory(environment(TO)) );
    DEBUG("Bug eating "+ob->query("short")+"\n");

    ob->remove();
    flag = 2;
}

void heart_beat() {
    int i, sz;
    object *obs;
    object ob;

    if (!environment()) return;

    if (flag) {
	if (--flag == 0) {
	    message("whatever", "With a loud *POP*, the bug splits in two!\n",
	      all_inventory(environment(TO)) );

	    ob = clone_object(base_name(TO));
	    if (ob) ob->move(environment(TO));
	}
    } else {
	ob = query_current_attacker();
	if (ob && (int)ob->query("hit_points") < 0) eat_ob(ob);
	else
	    continue_attack();
	move_around();
	obs = all_inventory(environment(TO));
	sz = sizeof(obs);

	for (i=0; i<sz; i++) {
	    if (!living(obs[i])) {
		eat_ob(obs[i]);
		break;
	    }
	}
    }
}

varargs int receive_damage(int i, string t, object o, int w) {
    if (o && userp(o)) {
	::receive_damage(i, t, o, w);
    } else {
	message("combat", "The bug simply ignores the attack.\n", 
	  all_inventory(environment()), ({ TO }) );
	o->receive_damage(10, "wizard", TO, 0);
	tell_object(TO, "You ignore the attack.\n");
	return 0;
    }
}

void receive_message(string Class, string msg) {
    if (sscanf(msg, "%s staggers and falls to the ground ... dead.", msg)==1)
	DEBUG("*Bug just killed "+msg+"\n");
}

void move_around() {
    int k;
    object troom;
    string *myrooms;

    if (move_counter == -1) {
	if (ENVTO->query("exits")) {
	    myrooms = values( ENVTO->query("exits") );
	    for(k=0; k<sizeof(myrooms); k++)
	    {
		troom = find_object_or_load(myrooms[k]);
		if (troom && troom->query("forbidden"))
		    troom->set("forbidden", 0);
	    }
	}
    }

    if (command("enter portal")) {
	DEBUG("** "+file_name(TO)+" entered a portal!\n");
	return ;
    }

    ::move_around();
}

/* EOF */

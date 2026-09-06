/* Official City Janitor */

#include "citymonster.h"

void dump_objects();

/* X and Y coordinates of the dump */
#define X 7
#define Y 10

#define WC 10
#define AC 5

int go_to_dump;

void
create_monster()
{
    go_to_dump=0;
    set_name("janitor");
    set_id("city_janitor");
    set_short("Janitor");
    gender=random(3);
    set_long(capitalize(Pronoun())+" is here to keep the City clean.");
    set_level(5);

    /* Zeus' suggestion:
       Janitors can now carry more, and keep the city cleaner. */
    set_stat(ST_STR, 20);
    set_keep_hb(-300);
    set_wander(30);
    set_hp(125);
    set_alignment(AL_NICE);
    set_wc(WC);
    set_ac(AC);
    set_random_pick(50);
}

pick_any_obj() {
    ::pick_any_obj();
    check_inv();
    check_weight();
}

/* Let's destruct items that are less than 100 gc of value */
check_inv() {
    object ob,next;
    ob=first_inventory(this_object());
    while(ob) {
	next=next_inventory(ob);
	if(ob->query_value()<100 && !ob->drop()) {
	    environment()->tell_here("Janitor crushed "+(string)
	      ob->query_name(0, this_object())+" in "
	      + Possessive()+" hands.", this_object());
	    destruct(ob);
	}
	ob=next;
    }
}

check_weight() {
    recount_weight();
    if(local_weight>11)
	go_to_dump=1;
}

void
init_monster()
{
    if (environment()->is_city_dump())
	dump_objects();
}

dump_objects() {
    object ob,next;
    ob=first_inventory(this_object());
    while(ob) {
	next=next_inventory(ob);
	experience+=random(6); /* *grin* */
	if (ob->is_wielded()) {
	    unwear(ob);
	}
	else if (ob->is_worn()) {
	    unwear(ob);
	}
	set_wc(WC);
	set_ac(AC);
	environment()->tell_here("Janitor throws "+(string)ob->
	  query_name(0, this_object())+" into the dump.", this_object());
	destruct(ob);
	ob=next;
    }
    go_to_dump=0;
}

heart_beat() {
    if (!environment()) return;
    if(go_to_dump)
	goto_dump();
    ::heart_beat();
}

goto_dump() {
    int x,y; /* Our current coordinates */
    string room;
    string tmp;
    if(!environment()) return;
    room=object_name(environment());
    if (sscanf(room, "%s/tristeza/virtual/S%d_%d", tmp, x, y) < 2)
	return;
    if(x<X)
	command("east");
    else if(x>X)
	command("west");
    else if(y<Y)
	command("south");
    else if(y>Y)
	command("north");
}

int
attacked_by(object orig, int to_top, int flags)
{
    int ret;
    if (!(ret = ::attacked_by(orig, to_top, flags)) || to_top <0)
	return ret;
    extra_attacked_by(orig);

    return ret;
}

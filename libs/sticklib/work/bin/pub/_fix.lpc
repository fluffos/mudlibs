#include <cmd.h>
#include <conditions.h>
#include <stats.h>

/* Dwarvish sharpen couldn't be found at all!?!
   Needs a different name, 'fix', though, //Graah */

/* 'sharpen <weapon>' for dwarves 1.2.1993 //Frobozz */
int
fix_cmd(string str) {
    object what;
    int cost;

    if((string)this_player()->query_race()!="dwarf") return 0;
    if(!str) {
	this_player()->tell_me("Fix what?");
	return 1;
    }
    str=lower_case(str);
    what=present(str,this_player());
    str=capitalize(str);
    if(!what) {
	this_player()->tell_me("You don't have "+str+".");
	return 1;
    }
    if(!what->is_weapon()) {
	this_player()->tell_me(str+" is not a weapon.");
	return 1;
    }
    if(what->query_wielded()) {
	this_player()->tell_me("You must remove it first.");
	return 1;
    }
    if(what->query_blunt()) {
	this_player()->tell_me("Cannot sharpen "+str+".");
	return 1;
    }
    if(!what->query_bluntness()) {
	this_player()->tell_me("It is sharp already.");
	return 1;
    }
    cost=((int)what->query_orig_value()-(int)what->query_value())/20+5;
    if((int)this_player()->query_sp()<cost) {
	this_player()->tell_me("You don't have enough spell points.");
	return 1;
    }
    this_player()->add_sp(-cost);
    if(random(101)<what->query_bluntness()) {
	this_player()->tell_me("Oh no! Your weapon broke when sharpened!");
	destruct(what);
	return 1;
    }
    what->set_bluntness(0);
    this_player()->tell_me("Ok. "+capitalize(str)+" is sharpened.");
    environment(this_player())->tell_here((string)this_player()->query_name() +
      " sharpened "+str+".",({this_player()}));
    return 1;
}

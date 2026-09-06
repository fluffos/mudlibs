#define SWEAT_DELAY (6)

#include <conditions.h>
#include "../DEFS.h"

int count;

reset(arg) {
    if (arg) return;

    count = 5;
    call_out("sweat",SWEAT_DELAY);
}

get() { return 1; }
drop() { return 1; }
init() { }
id(str) { return str == "sauna_sweat"; }
short() { return 0; }
long(arg) { write("Aren't you clever! :-D\n"); }

extra_look() {
    return environment()->query_name() + " is sweating a lot";
}

set_count(x) { count = x; }

sweat()
{
    int t;

    if (!environment() || !environment(environment()))
    {
	destruct(this_object());
	return;
    }

    if ("/"+object_name(environment(environment())) != CITY_PATH+"finnclub/sauna")
    {
	count--;

	if (count < 1)
	{
	    environment()->tell_me("You don't sweat any more.");
	    destruct(this_object());
	    return;
	}
    }
    else
    {
	/* Poisoned players will feel sicker in the heat of the sauna
	   //Frobozz */
	if (environment()->query_condition(C_POISONED) ||
	  environment()->query_condition(C_SICK)) {
	    environment()->tell_me("You don't feel so well...");
	    environment()->add_hp(-5, 1);
	}
	else
	{
	    /* New: depends on temperature */
	    /* Latest addition: game balance rule: slow down healing */
	    /* Slower intervals, slightly better //Graah */
	    if (random(100) > 20)
	    {
		t = environment(environment())->query_celcius();
		if (t < 100) environment()->heal_self(4);
		if (t < 140) environment()->heal_self(5);
		else environment()->heal_self(6);
	    }
	}
    }

    /* Don't flood the host with messages */
    if (!random(14))
	environment()->tell_me(
	  ({ "You are sweating a lot!",
	    "Sweat flows everywhere on your body.",
	    "You are soaking with sweat.",
	    "You feel hot, but good.",
	    "You feel relaxed.",
	    "You would feel even better with a genuine finnish vihta."
	  })[random(6)]);

    call_out("sweat",SWEAT_DELAY);
}

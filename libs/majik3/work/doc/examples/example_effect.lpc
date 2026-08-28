/*
 * Example on how to use the effect system
 * 
 * NOTE: Please don't make potions this way, this is just an example.
 *       Potion inheritable will be made someday :)
 * 
 * (c) Dazzt 1997
 * */

inherit ITEM;

// This is nice way to avoid typos 

#define EFFECT "dazzt_str_potion"

// Create the standard item 

create_item()
{
	set_name(({ "potion", "small potion", "red potion", "small red potion" }));
	set_short("A small, red potion");
	set_long("A dark red fluid with blueish sparkles swirls inside this fragile flask. " +
		 "The flask itself is made from very thin glass, creating almost no shadow " +
		 "when placed in sunlight.\n");
}

// Additional functions

init()
{
	add_action("do_drink", "drink");
}

do_drink(string str)
{
	if (!id(str))
	{
		notify_fail("Drink what?\n");
		return 0;
	}
	
	THIS->add_hb_effect(EFFECT,           /* name of the effect, unique */
			5 * 60,               /* five-minute duration       */
			"potion_on",          /* start function             */
			"potion_off");        /* end function               */
	message("0", "You drink the small, red potion.\n", THIS);
	message("0", THIS->query_cap_name() + " drinks a small, red potion.\n", ENV(THIS), THIS);
	destruct(THOB);                       /* destroy the potion         */
	return 1;
}

potion_on()
{
	message("0", "A sudden surge of strength flows through your body!\n", THIS);
	THIS->set_str(THIS->query_str() + 3);
}

potion_off()
{
	message("0", "Your muscles start to tremble as you feel a bit weaker.\n", THIS);
	THIS->set_str(THIS->query_str() - 3);
}


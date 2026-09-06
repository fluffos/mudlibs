#include <stats.h>

status
can_throw(object owner, object item)
{
    object gargie;
    object foo, bar;
    status doing_garg;
    if (!item)
	return 0;

    if ((int)item->query_weight() > (2 + ((int)owner->query_stat(ST_STR) / 13)))
    {
	owner->tell_me((string)item->query_name() +
	  " is too heavy for you to throw.");
	return 0;
    }

    gargie=present("gargamel",environment(owner));

    doing_garg=0;

    if(item->id("slayer") && gargie) doing_garg=1;

    if (item->query_two_handed() &&
      !item->id("spear") &&
      !item->id("hammer") &&
      !item->id("axe") &&
      !doing_garg)
    {
	owner->tell_me("You can't throw two-handed weapons.");
	return 0;
    }

    foo = (object)owner->query_weapon(); 
    bar = (object)owner->query_weapon(1); 

    if (objectp(foo) && objectp(bar) && item != foo && item != bar)
    {
	owner->tell_me("You don't have a free hand to throw that!");
	return 0;
    }


    if (item->drop())
    {
	owner->tell_me("You cannot throw this thing.");
	return 0;
    }

    return 1;
}

/****************************************************************
*								*
* Standard money object.					*
*								*
* Version 1.1 18-aug-95.					*
*								*
* NEW:								*
*								*
* - Now checks if there are other money objects in same room;	*
*   if so, let's combine them!					*
*								*
****************************************************************/

#include "/sys/configuration.h"

inherit "/basic/id";

#include <invis_levels.h>
#include <city_name.h>

int money;

void set_money(int x);

void
create()
{
    set_money(1);
}

// This might change...
int query_weight() { return 0; }

void
init()
{
    object *inv;
    int x, i;

    if (environment() == this_player())
    {
	if (money > 0) this_player() -> add_money(money);
	money = 0;
	// This money is about to disappear, don't show it.
	set_invis(IL_TOTALLY_INVISIBLE);
	configure_object(this_object(), OC_HEART_BEAT, 1);
    }
    else if ((money > 0) && environment())
    {
	inv = all_inventory(environment());
	for (i = sizeof(inv) - 1; i >= 0; i--)
	{
	    if ((inv[i] != this_object())
	      && inv[i]->is_money()
	      && ((x = (int)inv[i]->query_money()) > 0))
	    {
		inv[i]->set_money(x + money);
		money = 0;
		// This money is about to disappear, don't show it.
		set_invis(IL_TOTALLY_INVISIBLE);
		configure_object(this_object(), OC_HEART_BEAT, 1);
		break;
	    }
	}
    }
}

status get() { return money > 0; }

void
set_money(int m)
{
    if (m < 0) return;

    money = m;

    if (!m)
    {
	configure_object(this_object(), OC_HEART_BEAT, 1);
	set_id(0);
    }
    else if (money == 1)
    {
	set_name("gold coin");
	set_id(({ "coin", "money", " money" }));
	// Last one to allow some tricks... :-)
	set_short("one gold coin");
	set_long(
	  "It's a gold coin. You can see text '" CITY_NAME " Treasury gold dublon 60"+
	  random(10)+"' on it.");
    }
    else
    {
	set_name("gold coins");
	set_id(({ "coins", "money", " money" }));
	// Last one to allow "drop"-command to check few things...
	set_short(money + " gold coins");
	set_long("" + money + " gold coins.");
    }
}

int query_money() { return money; }
nomask int is_money() { return 1; }

void
heart_beat()
{
    if (money <= 0) destruct(this_object());
    else configure_object(this_object(), OC_HEART_BEAT, 0);
}

// tianqi.c

#include <ansi.h>

inherit COMBINED_ITEM;

int is_herb() { return 1; }

void setup()
{
        set_amount(1);
        ::setup();
}

string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;

	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}

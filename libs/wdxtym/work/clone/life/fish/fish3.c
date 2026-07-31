// shedan.c

#include <ansi.h>
inherit COMBINED_ITEM;
string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;

	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}

void setup()
{
	set_amount(1);
	::setup();
}
string *fishs=({"青鱼","扁鱼","草鱼"});
int i=random(sizeof(fishs));
void create()
{
	set_name("优质的"+fishs[i], ({"youzhi fish", "yu"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("base_unit", "条");
		set("long", "这是一条钓上来的优质的"+fishs[i]+"。\n");
		set("base_value", 5000);
		set("base_weight", 1);
	}
	setup();
}

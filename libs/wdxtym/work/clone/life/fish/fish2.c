// shedan.c

//inherit ITEM;
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
	set_name("普通的"+fishs[i], ({"puton fish", "yu"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("base_unit", "条");
		set("base_value", 3000);
		set("long", "这是一条钓上来的劣质的"+fishs[i]+"。\n");
		set("base_weight", 1);
	}
	setup();
}

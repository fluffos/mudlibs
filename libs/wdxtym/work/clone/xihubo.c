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
void create()
{
	set_name(HIG"清理互博"NOR, ({"hubo"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);
		set("jifeng", 12);
		set("unit", "个");
		set("base_unit", "个");
		set("base_weight", 10);
		set("base_value", 100);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
      if (me->is_busy())
                return notify_fail("你正忙着呢。\n");

	if (me->is_fighting())
		    return notify_fail("正在战斗中，不能使用"+ name() +"。\n");

	me->set_skill("zuoyou-hubo",0);
	write(YEL"你把互博归零了"NOR"\n");

       
	add_amount(-1);
	return 1;
}
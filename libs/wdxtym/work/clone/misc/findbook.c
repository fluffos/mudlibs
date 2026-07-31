inherit ITEM;
#include <ansi.h>
void init()
{
	add_action("do_find", "findbook");
}
void create()
{
	set_name(HIR"七"+HIC+"彩"+HIY+"向"+HIM+"导"+HIG+"石"NOR, ({"xdshi"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("no_put",1);
		set("no_drop",1);
		set("long", "这是用来测量神书位置的灵石，你可以用(findbook)来测量。\n");
		set("no_pawn",1);
	}
	setup();
}
int do_find(string str)
{
        object me =this_player();
		string output = "";
        if(!str)
			return notify_fail("指令格式: findbook <物品>\n");
		if( me->is_busy() )
			return notify_fail("你正忙着呢！\n");
		output = ("/adm/daemons/questsd")->locate_obj(str);
		write(output);
		me->start_busy(1);
		return 1;
}


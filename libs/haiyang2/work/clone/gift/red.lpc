// 红包

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIY"20W两黄金"NOR, ({"20Wgold"}));
	set_weight(10);
    set("value", 0);
set("no_steal",1);
set("liwu",1);
set("no_beg",1);
    set("no_put",1);
    set("no_get","每个人只有一个，不要这么贪心！\n");
    set("no_drop","这么珍贵的东西你也扔？！\n");
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "一张"+HIY"20万两黄金的支票，"NOR+"似乎可以兑换(duihuan)。\n");
                set("unit", "张");
	}
}
  void init()
{
  add_action("do_open","duihuan");
}
int do_open()
{
object ob;
        this_player()->start_busy(30);
        this_player()->add("combat_exp", 200+random(100));
        this_player()->add("potential",150+random(100));
        message_vision("$N兑换了1张20万两黄金的支票，是假币，$N立刻被押送往官府!\n", this_player());
        this_player()->move("/d/pingan/ymzhengting");
	destruct(this_object());
	return 1;
}

void owner_is_killed()
{
	destruct(this_object());
}

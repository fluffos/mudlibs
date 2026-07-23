// 红包

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIR"红包"NOR, ({"hong bao", "bao", "hong"}));
	set_weight(10);
    set("value", 0);
set("no_steal",1);
set("no_beg",1);
    set("no_put",1);
    set("no_get","每个人只有一个，不要这么贪心！\n");
    set("no_drop","这么珍贵的东西你也扔？！\n");
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个用红纸制作而成的"+HIR"红包，"NOR+"似乎可以撕开(opengift)。\n");
		set("unit", "个");
	}
}
  void init()
{
  add_action("do_open","opengift");
}
int do_open()
{
object ob;
        this_player()->add("combat_exp", 200+random(100));
        this_player()->add("potential",150+random(100));
        ob=new("/clone/money/gold");
        ob->set_amount(500000+random(5000));
        ob->move(this_player());
	message_vision("$N打开了红包，只觉得自己又变利害了一些 !红包里还有一些金子!\n", this_player());
	destruct(this_object());
	return 1;
}

void owner_is_killed()
{
	destruct(this_object());
}

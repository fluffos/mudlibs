// 超级大礼包 /ADDED BY KEINXIN

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIY"超级大礼包"NOR, ({"dalibao", "bao", "libao"}));
	set_weight(10);
set("no_drop", 1);
set("no_put", 1);
    set("no_bug", 1);
    set("no_steal", 1);
    set("no_get", 1);
    set("value", 0);
	if (clonep())
		set_default_object(__FILE__);
	else {
    set("no_give","每个人只有一个，你都这么大方！\n");
set("no_drop", 1);
set("no_put", 1);
    set("no_get", 1);
    set("no_give", 0);
    set("value", 0);
		set("long", "一个用纯金制作成的"+HIY"超级大礼包，"NOR+"似乎可以打开(opengift)。\n");
		set("unit", "个");
	}
}
  void init()
{
  add_action("do_open","opengift");
}
int do_open()
{
	int exp,pot;
	object me = this_player();
object ob;
        exp = 2100+random(5000);
	      pot = exp/3;
	this_player()->add("combat_exp",exp);
	this_player()->add("potential",pot);
        ob=new("/clone/money/gold");
        ob->set_amount(1);
        ob->move(this_player());
	this_player()->start_busy(50);
	message_vision("$N打开了超级大礼包，只觉得自己又变利害了一些 !礼包里还有很多黄金!\n", this_player());
	tell_object(me,HIY"你被奖励了：二百两黄金，但是被一个黑影拿走了\n" +
             chinese_number(exp) + "点实战经验\n"+
             chinese_number(pot) + "点潜能\n"NOR);
	destruct(this_object());
	return 1;
}
void owner_is_killed()
{
	destruct(this_object());
}
// 红包

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIR"红包"NOR, ({"hong bao", "bao", "hong"}));
	set_weight(10);
set("no_drop", 1);
set("no_put", 1);
    set("no_bug", 1);
set("liwu",1);
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
	this_player()->add("combat_exp", 1088);
	this_player()->add("potential",588);
if (this_player()->query("max_neili") < 1000)
	this_player()->add("max_neili",18);
	this_player()->start_busy(50);
	message_vision("$N打开了红包，只觉得自己又变利害了一些 !\n", this_player());
	destruct(this_object());
	return 1;
}
void owner_is_killed()
{
	destruct(this_object());
}
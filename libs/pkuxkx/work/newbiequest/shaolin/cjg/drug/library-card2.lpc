// 经验丹 每颗1万经验
// by seagate@pkuxkx 2011.02.18

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIB"阅览证"NOR, ({"library card"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("long", "进入二楼阅览室的证明。\n");
		set("value", 100);
	}
}
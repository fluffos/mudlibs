// kulou1.c 黑骷髅
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(BLK"黑骷髅"NOR,({"hei kulou","hei"}));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个黑色的五孔骷髅,与别的白骷髅不同。\n");
		set("unit", "个");
             set("value", 10000);
	setup();
	}
}

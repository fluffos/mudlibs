// 花轿

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(MAG "花" NOR HIR"轿" NOR, ({ "hua jiao", "huajiao", "jiaozi", "jiao" }) );
	if ( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一顶精心装饰过的大红花轿，大红的缎子布包着，四角扎着大红花，四根杆子都用彩带绕着。\n");
		set("material", "wood");
		set("no_get", "这样东西不能离开那儿。\n");
		set("no_drop", "这样东西不能离开你。\n");
	}
	setup();
}
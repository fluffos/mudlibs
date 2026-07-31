// yaopai.c
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW "水晶腰牌" NOR, ({ "yao pai"  }) );
	set("unit", "个");
	set("long","这是一个挂在腰间的饰物，由整块水晶雕琢而成，
晶莹剔透，上面刻着一个“福”字。\n");
	set_weight(500);
	set("value", 1000);
    setup();
}
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(RED"拜贴"NOR, ({ "baitie" }));
        set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("unit", "张");
		set("long",
                        "少林派武功，称雄中原西域有年，十天之后，昆仑三圣前来一并领教。\n");
                set("treasure", 1);
                set("value", 0);
                set("material", "paper");
         }
}

#include <ansi.h>
#include "quarry.c"

void create()
{
	set_name(HIR "丹顶鹤" NOR, ({ "danding he", "danding", "he" }));
	set("long", HIR "全身洁白的丹顶鹤，看来是修了翅膀，没法高飞了。\n" NOR);
        set("no_auto_kill", 1);
        set("aves", 1);

	set("age", 1);
	set("str", 5);
	set("dex", 28);
	set("max_qi", 250);
	set("max_jing", 250);
	set("combat_exp", 1000);
set("race", "野兽");
        set("power", 5);

        set_temp("apply/dodge", 60);
        set_temp("apply/defense", 60);

	setup();
}

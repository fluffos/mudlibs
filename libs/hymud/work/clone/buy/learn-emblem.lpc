#include <ansi.h>

inherit ITEM;
inherit F_AUTOLOAD;

void create()
{
        set_name(MAG "学习勋章" NOR, ({ "learn emblem", "emblem" }));
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", MAG "带在身上学习速度可以快倍。\n" NOR);
                set("unit", "块");
                set("no_put",1);
	              set("no_beg",1);
	              set("no_steal",1);
                set("no_clone",1);
                set("value", 10000);
        }
        setup();
}


int query_autoload() { return 1; }


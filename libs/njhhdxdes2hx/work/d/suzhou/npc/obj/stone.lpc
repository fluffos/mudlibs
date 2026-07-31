//OBJECT:/d/suzhou/npc/obj/stone.c
// by dwolf
//97.11.4

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(BLK"大理石"NOR, ({ "dali shi", "shi" }) );
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
		set("long", "一块花纹美丽的大理石，可拿来作装饰用。\n");
	}
        setup();
}


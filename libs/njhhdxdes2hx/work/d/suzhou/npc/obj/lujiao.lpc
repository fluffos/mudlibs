//OBJECT:/d/suzhou/npc/obj/lujiao.c
// by dwolf
//97.11.4

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(YEL"鹿角"NOR, ({ "lu jiao", "jiao" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
		set("long", "两根小小的鹿角。上面还有鲜血。\n");
	}
        setup();
}


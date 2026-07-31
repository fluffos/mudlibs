//OBJECT: /d/suzhou/npc/obj/cloth2.c
//by dwolf
//97.11.6

#include <ansi.h>         
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("绸衣", ({ "cloth", "chou yi" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "silk");
                set("armor_prop/armor", 2);
		set("value", 100);
        }
        setup();
}


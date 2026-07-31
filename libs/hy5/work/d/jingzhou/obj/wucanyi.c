// ITEM: /d/jingzhou/obj/wucanyi.c
// Date: 99/05/31 by Byt

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(CYN "乌蚕衣" NOR, ({ "wucan yi", "yi" }) );
        set_weight(5000); 
        set("unique", 1);        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("no_drop","宝物是扔/卖不了的，也不能给别人。");
                set("value", 50000);
                set("material", "gold");
                set("armor_prop/armor", 200);
        }
        setup();
}


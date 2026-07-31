//开光金丝禅衣   jinsi-chanyi.c
//by junhyun@SK

#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(HIY"金丝"HIW"禅衣"NOR, ({ "jinsi-chanyi", "cloth" }) );
        set("long", "一件用天山冰蚕吐出的金丝织成的禅衣。。\n");
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 50);
                set("armor_prop/spells", 10);
                set("armor_prop/dodge", 10);
                set("armor_prop/intelligence", 5);
                set("value", 200);
                set("no_sell", 1); // mudring.
                set("no_drop", 1); // mudring.
        }
        setup();
}


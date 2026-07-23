//浴血铠甲
#include <armor.h>
#include <ansi.h>

inherit CLOTH;
inherit F_UNIQUE;

void create()
{
        set_name(HIR"浴血铠甲"NOR, ({ "yuxue kaijia", "kaijia" }));
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIR"这是一件当年岳飞曾穿过的铠甲，因为当年岳飞元帅浴血沙场，铠甲被染成了血红色。\n"NOR);
                set("material", "steel");
                set("unit", "件");
                set("unique", 1);
                set("value", 1000000);
                set("wear_msg", HIR "$N霍的一声穿上了浴血铠甲，一股凌云壮气荡漾，浑身似乎充满了斗志！\n" NOR);
                set("remove_msg", HIR "$N脱下浴血铠甲，渐渐散去了浴血将士的风采。\n" NOR);
                set("treasure",1);
                set("armor_prop/armor", 70);
                set("armor_prop/parry", 10);
                set("armor_prop/dodge",-10);
        }
        setup();
}



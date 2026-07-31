#include <ansi.h>
#include <armor.h>


inherit ARMOR;

void create()
{
        set_name(HIR "龙象袈裟" NOR, ({ "longxiang jiasha", "longxiang", "jiasha" }));
        set_weight(8000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", HIR "这是一件陈旧的袈裟，通体血红，印有龙象纹样。着"
                            "手处坚韧\n无比，想必是由金刚丝混及雪蚕丝编织而成。"
                            "更有传闻说密宗\n神功龙象般若功便是记载于这件袈裟之"
                            "上。\n" NOR);
                set("value", 8000);
                set("treasure", 1);
                set("material", "cloth");
                set("wear_msg", HIY "$N" HIY "展开$n" HIY "，霎时金波流转，罡气"
                                "笼罩全身。\n" NOR);
                set("armor_prop/armor", 900);
                set("force", 13);
                set("stable", 100);
        }
        setup();
}



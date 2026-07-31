// XiaoYao 

#include <armor.h>
#include <ansi.h>
inherit CLOTH;
inherit F_UNIQUE;
void create()
{
        set_name(HIY"乌蚕衣"NOR, ({ "wucan yi", "wucan", "yi" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这一件刀枪不入的宝衣，是用大雪山上的乌蚕蚕丝织成的。\n");
                set("material", "silk");
                set("unit", "件");
                set("value", 1000000);
                set("treasure", 1);
                set("wear_msg", HIY"只见$N将两块料子，前一块、后一块的扣在一起穿在了身上。\n" NOR);
                set("armor_prop/armor", 180);
        }
        setup();
}


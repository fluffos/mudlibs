#include <ansi.h>
inherit EQUIP;
void create()
{
        set_name(HIW"白飞飞的面具"NOR, ({ "mask" }) );
        set_weight(1);
        set("long","一个精巧的面具，巧夺天工，毫无瑕疵。\n");
        set("unit", "件");
        set("value", 1);
        set("material", "cloth");
        set("armor_type", "mask");
        set("fakegender", "女性");
        set("armor_prop/id", ({"bai feifei"}) );
        set("armor_prop/name", ({"白飞飞"}) );
}   

// gangdao.c
#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name(WHT"鬼头刀"NOR, ({ "blade" }));
        set_weight(9000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是一柄亮晃晃的鬼头刀,刀头上有鬼头,嘴里镶着一个铁环.");
                 set("value", 100000);
                set("material", "steel");
                set("wield_msg", WHT"$N「唰」的一声抽出一柄鬼头刀握在手中,刀头的铁环花拉作响.\n"NOR);
                set("unwield_msg",WHT"将手中的$n插回刀鞘。\n"NOR);
        }
        init_blade(100);
        setup();
}

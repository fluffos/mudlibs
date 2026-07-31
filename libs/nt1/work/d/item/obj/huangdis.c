// huangdi-stone.c 黄帝石

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(HIY "黄帝石" NOR, ({ "hangdi stone" }) );
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIY "相传黄帝与蚩尤于涿鹿大战，蚩尤施展巫术招来大雾，使黄帝军无法辨认\n"
                                "方向，黄帝以石为盘，以金为针，制成指南车，最终突出雾阵，击败蚩尤。\n" NOR);
                set("value", 50000);
                set("unit", "块");
                set("can_be_enchased", 1);
                set("enchased_armor", 1);
                set("magic/type", "gold");
                set("magic/power", 100);
                set("armor_prop/per", 7);
                set("wear_msg", HIC "$N" HIC "轻轻地把$n"
                    HIC "戴在头上。\n" NOR);
                set("remove_msg", HIC "$N" HIC "轻轻地把$n"
                    HIC "从头上摘了下来。\n" NOR);
        }
        setup();
}

int query_autoload() { return 1; }


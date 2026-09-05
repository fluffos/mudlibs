// weapon: 烁心弹

#include <weapon.h>
#include <ansi.h>
inherit THROWING;

void create()
{
        set_name(HIR"烁心弹" NOR, ({ "shuoxin dan", "dan"}));
        set_weight(15);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "堆");
                set("base_unit", "粒");
                set("base_weight", 15);
                set("long", HIG"这是一枚星宿独门暗器－烁心弹，内里暗藏了大量易燃物质。\n"NOR);
                set("value", 100);
                set("material", "steel");
                
        }
        set_amount(1);
        init_throwing(10);
        setup();
}


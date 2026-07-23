// banyueqiang.c 半月枪

#include <ansi.h>
#include <weapon.h>
inherit SPEAR;

void create()
{
        set_name( "半月枪" , ({ "banyue qiang", "qiang", "dagger","banyueqiang" }));
        set_weight(18000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这柄长枪在紧靠枪缨后面打造了一个弧形月牙，增加了攻击能力和范围。\n");
                set("value", 1500);
                set("material", "iron");
        }
        init_spear(40);
        setup();
}

// weapon: bilinzhen.c 碧磷针

#include <weapon.h>
#include <ansi.h>
inherit THROWING;

void create()
{
        set_name(HIB"无形粉"NOR, ({ "wuxing fen", "fen", "powder" }));
        set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "蓬");
                set("base_unit", "蓬");
                set("long", HIG"这是一蓬星宿独门暗器－无形粉，让人根本避无可避。\n"NOR);
                set("value", 100);
                set("base_weight", 5);
                set("material", "steel");
                set("wield_msg", "$N戴上鹿皮手套，从腰间锦囊中轻轻拈起一蓬$n。\n");
                set("unwield_msg", "$N将手中的$n放回腰间锦囊。\n");
        }
        set_amount(1);
        init_throwing(20);
        setup();
}


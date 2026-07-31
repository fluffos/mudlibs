#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(NOR + CYN "软猬甲" NOR, ({ "ruanwei jia", "ruanwei", "jia" }));
        set_weight(8000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", NOR + CYN "
这是一件黑黝黝的软甲，粗看下毫不起眼。这便是桃花岛至宝
软猬甲，只见整个甲身乌黑亮泽，着手柔软，却又是坚硬胜铁，
宝甲外围还生满了倒刺，尖利无比。\n" NOR);
                set("value",8000);
                set("treasure", 1);
                set("material", "cloth");
                set("armor_prop/armor", 550);
                set("stable", 100);
        }
        setup();
}



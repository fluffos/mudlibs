#include <weapon.h>

#include <ansi.h>
inherit HAMMER;

void create()
{
    set_name(HIY"金轮"NOR, ({ "gold falun", "falun", "lun"}) );
    set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("value", 10000);
                set("dalunsi", 1);
                set("material", "gold");
                set("long", "这是一只金制轮，约有尺半大小，上面铸有密宗伏魔真言，内藏九个小球，是僧人们作法事用的一种法器。\n");
        }
        init_hammer(140);
        setup();
}



#include <weapon.h>

#include <ansi.h>
inherit HAMMER;

void create()
{
    set_name(BLU"铁轮"NOR, ({ "iron falun", "falun", "lun"}) );
    set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("value", 10000);
                set("dalunsi", 1);
                set("material", "iron");
                set("long", "这是一只铁制轮，约有尺半大小，上面铸有密宗伏魔真言，内藏九个小球，是僧人们作法事用的一种法器。\n");
        }
        init_hammer(110);
        setup();
}



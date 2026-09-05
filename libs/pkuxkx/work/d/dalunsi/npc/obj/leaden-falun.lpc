#include <weapon.h>

#include <ansi.h>
inherit HAMMER;

void create()
{
    set_name(WHT"铅轮"NOR, ({ "leaden falun", "falun", "lun"}) );
    set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("value", 10000);
                set("dalunsi", 1);
//                set("no_sell", 1);
//              set("no_drop", "1");
                set("material", "leaden");
                set("long", "这是一只铅制轮，约有尺半大小，上面铸有密宗伏魔真言，内藏九个小球，是僧人们作法事用的一种法器。\n");
//                set("wield_msg","$N双手举出一柄$n，霎那间，风雷之声不绝于耳。\n");
//                set("unwield_msg", "$N双手舞了一个花，往回一收，将$n别在腰带上。\n");
        }
        init_hammer(100);
        setup();
}


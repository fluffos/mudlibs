#include <weapon.h>
inherit STAFF;
#include <ansi.h>

void create()
{
        set_name(HIG"菩提杖"NOR, ({"puti zhang","stick","bang"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else 
        {
                set("long","一把淡绿色的玉棒，入手滑腻，颇有些份量。\n");
                set("unit", "根");
                set("value", 120);
                set("wield_msg",HIW "$N念动心决，菩提杖缓缓从背后升起。\n"NOR);
                set("unwield_msg",HIW "$N念动口诀,菩提杖化为一缕青烟,从手中消失了!\n");
                set("no_sell","你大脑有问题吧？这东西你都敢卖？\n"); 
                set("no_drop","去垃圾堆丢吧，乱扔会污染环境!\n"); 
                set("weapon_prop/courage", 20);
        }
        init_staff(820);
        setup();
}


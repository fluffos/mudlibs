// sw_jian.c 松纹古剑
// by Looklove 2000/8/25 for a quest

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIG"松纹古剑"NOR,({ "songwen jian", "songwen gujian", "jian","sword" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("material", "wood");
                set("rigidity", 1);
                set("weapon_prop/parry", 1);
                set("weapon_prop/sword", 1);
                set("no_drop","师傅给的剑，不能随便丢弃。\n");
                set("no_give","师傅的剑给别人，恐怕不好吧？\n");
                set("wield_msg", HIC"$N自腰间抽一把$n，舞了个剑花。\n"NOR);
                set("unwield_msg", HIC"$N神色自若地将$n斜挂在腰间。\n"NOR);
        }
        init_sword(20);
        setup();
}


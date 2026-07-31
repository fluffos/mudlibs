//混天朝阳剑
//by junhyun@SK

#include <weapon.h>
//  inherit F_UNIQUE;

inherit SWORD;
#include <ansi.h>
void create()
{
        set_name(HIR"混天纯阳剑"NOR, ({"chunyang jian", "sword","jian"}));
        set_weight(5000);
if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","一柄沾满神佛鲜血与灵气的宝剑。散发着令人生畏的寒邪之光！\n");
                set("unit", "柄");
                set("value", 1200);
                set("wield_msg",HIW "$N右手一晃，手中已多了一柄混天纯阳剑！\n"NOR);
                set("unwield_msg", "$N放下手中的混天朝阳剑。\n");
                set("no_sell","你大脑有问题吧？这东西你都敢卖？\n"); 
                set("no_drop","去垃圾堆丢吧，乱扔会污染环境!\n"); 

                set("weapon_prop/courage", 20);
                }
        init_sword(720);
        setup();
}


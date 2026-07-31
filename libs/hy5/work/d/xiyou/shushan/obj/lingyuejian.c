//灵月剑
//by junhyun@SK

#include <weapon.h>
//  inherit F_UNIQUE;

inherit SWORD;
#include <ansi.h>
void create()
{
        set_name(HIG"灵月剑"NOR, ({"lingyue sword","sword","jian"}));
        set_weight(5000);
if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","李逍遥的至宝！\n");
                set("unit", "柄");
                set("value", 120);
                set("wield_msg",HIG "$N从背后抽出一柄寒光四射的宝剑！\n"NOR);
                set("unwield_msg",HIW "$N微微一笑,将宝剑插回背后的剑鞘中.\n");
                set("no_sell","你大脑有问题吧？这东西你都敢卖？\n"); 
                set("no_drop","去垃圾堆丢吧，乱扔会污染环境!\n"); 

                set("weapon_prop/courage", 20);
                }
        init_sword(820);
        setup();
}

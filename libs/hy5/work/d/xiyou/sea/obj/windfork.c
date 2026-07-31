//风音叉
//by wuyou

#include <weapon.h>
//  inherit F_UNIQUE;

inherit STAFF;
#include <ansi.h>
void create()
{
        set_name(HIB"风音叉"NOR, ({"wind fork","fork","cha"}));
        set_weight(5000);
if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","碧波闪闪,风音瑟瑟,让人看去就想起浩瀚无边的大海,似乎它里面隐藏着东海的秘密！\n");
                set("unit", "柄");
                set("value", 120);
                set("wield_msg",HIW "$N仰天一声龙吟,一柄海蓝色的飞叉从天而降,落如手中！\n"NOR);
                set("unwield_msg",HIW "$N随手一甩,手中的风音叉“嗖”的一声脱手而出,飞向天际...\n");
                set("no_sell","你大脑有问题吧？这东西你都敢卖？\n"); 
                set("no_drop","去垃圾堆丢吧，乱扔会污染环境!\n"); 

                set("weapon_prop/courage", 20);
                }
        init_staff(820);
        setup();
}

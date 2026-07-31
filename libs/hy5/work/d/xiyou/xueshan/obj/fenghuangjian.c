//凤凰剑
//by junhyun@SK

#include <weapon.h>
//  inherit F_UNIQUE;

inherit SWORD;
#include <ansi.h>
void create()
{
        set_name(HIY"凤凰剑"NOR, ({"phoenix sword","sword","jian"}));
        set_weight(5000);
if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","相传是一对凤凰化成的宝剑！\n");
                set("unit", "柄");
                set("value", 12000);
                set("wield_msg",HIW "$N一声清啸，凤凰剑如鬼魅般从天而降！\n"NOR);
                set("unwield_msg",HIW "$N手中凤凰剑突然化成一团寒气,消失在空气中.\n");
                set("no_sell","你大脑有问题吧？这东西你都敢卖？\n"); 
                set("no_drop","去垃圾堆丢吧，乱扔会污染环境!\n"); 

                set("weapon_prop/courage", 20);
                }
        init_sword(920);
        setup();
}

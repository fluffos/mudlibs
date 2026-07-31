//青羽魔剑
//by junhyun@SK

#include <weapon.h>
//  inherit F_UNIQUE;

inherit F_UNIQUE;
inherit SWORD;
#include <ansi.h>
void create()
{
        set_name(HIG"青羽魔剑"NOR, ({"qingyu mojian", "sword","jian"}));
        set_weight(5000);
if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","一柄散发着青色妖气的宝剑。\n");
                set("unit", "柄");
                set("value", 120);
               set("unique", 1);
                set("wield_msg", "$N中手聚起一股青色妖气，慢慢盘旋成一柄利剑！\n");
                set("unwield_msg", "$N手中的利剑化作一团青色妖气消失了。\n");
                set("weapon_prop/courage", 20);
                }
        init_sword(820); // so high...mudring
        setup();
}


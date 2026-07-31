//dragon blade 屠龙刀
#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
        set_name(CYN "屠龙刀" NOR,({"dragon blade","dao"}));
        set_weight(50000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "此剑有郭靖黄蓉夫妇打造，是天下神兵。\n");
                set("material", "steel");
                set("no_drop", "如此宝贵的武器再世难求啊。\n");
                set("no_get", "送人？亏你想的出来！\n");
                set("no_put", "珍惜它吧。\n");
                set("no_steal", 1);
                set("value",100);
                set("wield_msg", CYN "屠龙刀跃出刀鞘 ，放射出璀璨的毫光，天地为之变色。\n" NOR);
                set("unwield_msg", CYN "$N手中剑光渐渐暗淡，天幕渐渐焕出光芒。\n" NOR);
       }
       init_blade(600);
       setup();
}
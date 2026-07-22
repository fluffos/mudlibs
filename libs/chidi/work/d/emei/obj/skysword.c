//ytjian.c 倚天剑 
#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name(CYN "倚天剑" NOR,({"sky sword","sword","jian"}));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "此剑有郭靖黄蓉夫妇打造，是天下神兵。\n");
                set("material", "steel");
                set("no_drop", "如此宝贵的武器再世难求啊。\n");
                set("no_get", "送人？亏你想的出来！\n");
                set("no_put", "珍惜它吧。\n");
                set("value",10);
                set("wield_msg", CYN "倚天剑如灵蛇般跃出剑鞘，落在$N手中，放射出
璀璨的毫光，天地为之变色。\n" NOR);
                set("unwield_msg", CYN "$N手中剑光渐渐暗淡，天幕渐渐焕出光芒。\n" NOR);
       }
       init_sword(600);
       setup();
}

void owner_is_killed()
{
       destruct(this_object());
}
int query_autoload()
{
       return 1;
}

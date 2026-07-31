// zhenwu-jian.c 真武剑
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name(HIW"真武剑"NOR, ({"zhenwu jian", "sword", "zhenwu"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一把毫不起眼的古剑,剑身不规则的花纹上似乎还带有些铁锈,剑锋上居然还有几个缺口。\n");
                set("unique", 1);
                set("value", 0);
                set("no_put", 1);
                set("no_give", 1);
                set("no_get", 1);
                set("no_steal", 1);
                set("rigidity", 5);
                set("sharpness", 3);
                set("material", "blacksteel");
                set("weapon_prop/dodge", 2);
                set("weapon_prop/parry", 3);
                set("treasure",1);       
                set("wield_neili", 300);
                set("wield_maxneili", 700);
                set("wield_str", 22);        
                set("skill", ([
                        "name": "sword",
                        "exp_required": 50000,
                        "difficulty": 25,
                        "min_skill":  10,
                             "max_skill": 150,              
                ]) );
                set("wield_msg",HIW"$N[噌]的一声抽出一把真武剑,空气中顿时充满了无边的杀气。\n"NOR);
                set("unwield_msg",HIW"$N把手中的宝剑插入剑鞘。四周的杀气也跟着消失了。\n"NOR);
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

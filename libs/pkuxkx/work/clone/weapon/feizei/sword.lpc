#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIW"冰弦剑"NOR, ({"bingxian jian","jian","sword"}));
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",YEL"殷商七剑之一，剑身细窄，刃薄，舞时劈风有声，音若冰瑟，夺人神魄。\n"NOR);
                set("unit", "把");
                set("no_put",1);
                set("value", 100000);
                set("no_give_user",1);
                set("no_steal",1);
                set("weapon_prop/sword",12+random(12));

        }
        init_sword(120+random(50));
        setup();
}

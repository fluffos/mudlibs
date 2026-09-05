#include <weapon.h>
#include <ansi.h>

inherit DAGGER;

void create()
{
        set_name(HIY"鱼肠剑"NOR, ({"yuchang jian","jian","dagger"}));
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",YEL"一把极小至可藏置于鱼腹中之匕首，据传乃春秋名匠欧冶子用千年海底之紫金锻造，其锋无比。\n"NOR);
                set("unit", "把");
                set("no_put",1);
                set("value", 100000);
                set("no_give_user",1);
                set("no_steal",1);
                set("weapon_prop/dagger",12+random(12));

        }
        init_dagger(120+random(50));
        setup();
}

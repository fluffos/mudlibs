#include <weapon.h>
#include <ansi.h>

inherit STAFF;

void create()
{
        set_name(HIG"胡节"NOR, ({"hu jie","jie","staff"}));
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",YEL"相传乃西汉苏武出使匈奴所持的节杖，因处北国经年，酷寒之气凝入其间，坚韧如铁，寒气逼人。\n"NOR);
                set("unit", "根");
                set("no_put",1);
                set("value", 100000);
                set("no_give_user",1);
                set("no_steal",1);
                set("weapon_prop/staff",12+random(12));

        }
        init_staff(120+random(50));
        setup();
}

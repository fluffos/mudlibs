#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIY"龙鳞"NOR, ({ "long lin","longlin","lin"}));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
          set("long", "一件乌金所造之宝甲，甲片相连相扣如龙鳞，箭不能穿透，坚不可催。\n");
                set("unit", "件");
                set("value", 10000);
                set("no_give",1);
                set("no_zm",1);
                set("no_put",1);
                set("material", "cloth");
                set("armor_prop/armor", 250+random(50));
        }
        setup();
}

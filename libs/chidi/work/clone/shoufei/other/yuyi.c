#include <armor.h>
#include <ansi.h>
#include <mudlib.h>

inherit CLOTH;

void create()
{
        set_name(HIM"风彩羽衣"NOR, ({ "fengcai cloth" }) ); 

        set_weight(600);

        if( clonep() )
                set_default_object(__FILE__);
        else {
                         set("long", HIY"这是一件风彩羽衣，据说充满灵气。下线不会消失。防御+2000\n"NOR);
                set("unit", "件");
              	set("jym_money",4);
//		set("no_put",1);
              	set("no_sell",1);
                 set("no_get", 1);
//             	set("no_give", 1);
              	set("no_drop",1); 
                set("material", "feature");
                set("armor_prop/armor", 2000);
        }
        setup();
}

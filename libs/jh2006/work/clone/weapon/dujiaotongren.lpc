// dujiaotongren.c
#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create()
{
        set_name( "独脚铜人" , ({ "dujiao tongren", "dujiao", "tongren" }));
        set_weight(30000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是一件外家兵器，打造成一个独脚人形，其中一臂高举，手中拿着一只笔。虽然沉重也可以用来点穴。\n");
                set("value", 1000);
                set("material", "bronze");
                set("wield_msg", "$N深吸一口气，用双手托起一根独脚铜人。\n");
                set("unwield_msg"," $N把独脚铜人绑的结结实实背在背后。\n");
        }
        init_staff(40);
        setup();
}

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("灵签", ({ "qian","lingqian" }) );
        set("long", "观音洞的灵签,上面雕刻着精致的花纹,\n");
        set("unit", "根");
        set("weight", 100);
        set("no_get",1);
}

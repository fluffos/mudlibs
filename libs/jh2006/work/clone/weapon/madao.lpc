// madao.c 马刀

#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
        set_name( "马刀" , ({ "ma dao", "dao", "blade","madao" }));
        set_weight(12000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是骑兵非常爱用的兵器，刀背薄身短，刀口锋利，入手轻便。\n");
                set("value", 1500);
                set("material", "iron");
        }
        init_blade(20);
        setup();
}

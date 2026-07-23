// jingangzuan.c 
#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create()
{
        set_name( HIW"龙象法杵"NOR , ({ "jingang zuan", "jingangzuan","zuan","staff"}));
        set_weight(15000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", HIR"这是藏传佛教中的一种法器，约有七八迟长，入手沉重，上面刻满梵文。\n"NOR);
                set("value", 1000);
                set("material", "steel");
        }
        init_staff(30);
        setup();
}

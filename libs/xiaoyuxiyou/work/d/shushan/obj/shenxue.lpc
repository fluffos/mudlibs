//shushan2 by yushu@SHXY 2000.12
#include <armor.h>
inherit F_UNIQUE;
inherit BOOTS;
void create()
{
        set_name("魅影神靴", ({ "meiying shoes", "shoes" }));
        set("level",12);
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
                set("value", 10000);
		  set("no_sell", 1);
		  set("no_drop", 1);
		  set("no_put", 1);
                set("replace_file", "/d/shushan/obj/shoe");
                set("material", "cloth");
                set("armor_prop/armor", 10);
                set("armor_prop/dodge", 60);

        }
        set("is_monitored",1);
        setup();
}


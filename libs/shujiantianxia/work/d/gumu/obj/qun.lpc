// qun.c

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIC"青纱长裙"NOR, ({ "qingsha changqun","qun","cloth" }) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一袭轻纱般的青衣，犹似身在烟中雾里。\n");
                set("unit", "件");
                set("material", "cloth");                
                set("armor_prop/armor", 20);
        }
        setup();
}


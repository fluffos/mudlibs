// qun1.c

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIW"白纱长裙"NOR, ({ "baisha changqun","qun","cloth" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一袭轻纱般的白衣，犹似身在烟中雾里。\n");
                set("unit", "件");
                set("material", "cloth");                
                set("armor_prop/armor", 40);
        }
        setup();
}


#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name( HIY"断掉的黄金项链"NOR, ({ "huangjin neck","huangjin"}) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
               set("neck_type",1);
                set("material", "leather");               
                set("armor_prop/armor", 1);
               set("value", 1000000);
        }
        setup();
}

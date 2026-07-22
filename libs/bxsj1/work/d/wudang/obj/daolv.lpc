// OBJ : /d/wudang/obj/daolv.c 道履
// By lius 99/8

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
        set_name( WHT"道履"NOR, ({ "dao lv", "lv" }) );
        set_weight(1000);
        if( clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "双");
                set("long", "一双白布黑底的道履，武当采药道人靠它翻山跃涧如履平地。");
                set("value", 3000);
                set("material", "boots");
                set("armor_prop/dodge", 2);
                set("wudang",1);
        }
        setup();
}

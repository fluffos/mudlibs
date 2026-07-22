#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(NOR + MAG "长裙" NOR, ({ "chang qun", "qun", }) );
        set("long",NOR + MAG "这是一件款式新颖，做工考究的长裙。\n");
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 600);
        }
        setup();
}


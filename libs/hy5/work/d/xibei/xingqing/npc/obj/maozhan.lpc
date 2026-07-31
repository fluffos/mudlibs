//maozhan.c.毛毡
//date:1997.8.27
//by dan      

#include <armor.h> 
#include <ansi.h>
inherit CLOTH;      

void create()
{
    set_name(MAG"毛毡"NOR, ({ "mao zhan", "zhan" }) );
    set("long","这是一条用细羊毛织成的毛毡。\n");
    set_weight(5000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "条");
        set("material", "cloth");
        set("value",2000);
        set("armor_prop/armor", 5);
    }
    setup();
}


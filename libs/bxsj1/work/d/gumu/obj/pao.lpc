// pao.c

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIC"青丝长袍"NOR, ({ "qingsi changpao","pao","cloth" }) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一件质地轻柔的青丝长袍。\n");
                set("unit", "件");
                set("material", "cloth");                
                set("armor_prop/armor", 20);
        }
        setup();
}

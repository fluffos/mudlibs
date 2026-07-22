// pao1.c

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIW"白丝长袍"NOR, ({ "baisi changpao","pao","cloth" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一件质地轻柔的白丝长袍。\n");
                set("unit", "件");
                set("material", "cloth");                
                set("armor_prop/armor", 40);
        }
        setup();
}

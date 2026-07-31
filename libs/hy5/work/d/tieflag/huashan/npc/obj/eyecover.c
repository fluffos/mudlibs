#include <ansi.h>
#include <armor.h> 
inherit HEAD; 
void create()
{
        set_name( YEL"блеж"NOR, ({ "eye cover", "cover" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Мў");
                set("value", 0);
                set("material", "cloth");
                set("armor_prop/armor", 10);
                set("armor_prop/dodge", 5);
        }
        setup();
}     

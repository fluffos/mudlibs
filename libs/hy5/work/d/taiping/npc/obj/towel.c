#include <ansi.h>
#include <armor.h> 
inherit HEAD; 
void create()
{
        set_name(YEL"»ÆÃ«½í"NOR, ({ "yellow towel","towel" }) );
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ìõ");
        set("long", "Ò»Ìõº¹¼£°ß°ßµÄ»ÆÃ«½í¡£\n");
                set("value", 7000);
                set("material", "cloth");
                set("armor_prop/armor", 5);
        }
    
}     

 // cloth.c
// 
#include <armor.h> 
inherit CLOTH;
#include <ansi.h>
void create()
{
    set_name(HIB"Œ‰ ø≈˚∑Á"NOR, ({ "bluecloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "º˛");
                set("long", "¥©¡À∫Û–ﬁ≥§Õ¶∞Œ£¨”Ò ˜¡Ÿ∑Á£¨æ°œ‘œ¿π«»·≥¶°£\n");
                set("material", "cloth");
                set("value", 1000);
                set("armor_prop/armor", 3);
        }
        
}     

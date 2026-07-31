#include <ansi.h>
#include <armor.h>
inherit ARMOR; 
void create() {
        set_name(BLK"ºÚë«ëª²ØÅÛ"NOR, ({ "tibetan robe", "robe" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼ş");
                set("material", "leather");
                set("value", 400);
                set("armor_prop/armor", 60);
                set("long","Ò»¼şºñÖØ´Ö±¿£¬ÄıÂú·çÉ³ÓÍ¹¸µÄºÚë«ëª²ØÅÛ¡£\n");
        }
        
} 

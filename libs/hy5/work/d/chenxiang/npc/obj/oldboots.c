 // cloth.c
// 
#include <armor.h>
#include <ansi.h> 
inherit BOOTS; 
void create()
{
          set_name(WHT"ÆÆ¾É²¼Ñ¥"NOR, ({ "oldboots" }) );
      set_weight(900);
         if( clonep() )
      set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "Ë«");
        set("long", "Ò»Ë«Ï´µÃ·¢°×µÄÆÆ¾É²¼Ñ¥¡£\n");
                set("value", 1000);
                set("armor_prop/dodge", 2 );
        }
        
}

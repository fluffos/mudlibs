 // shoe.c
#include <armor.h>
#include <ansi.h> 
inherit BOOTS; 
void create()
{
        set_name(YEL"Ä¾åì"NOR, ({ "wood shoes","shoes" }) );
        set_weight(2000);
        if( clonep() )
            set_default_object(__FILE__);
        else {
            set("unit", "Ë«");
            set("material", "wood");
            set("value", 10000);
            set("armor_prop/dodge", 3);
set("armor_prop/armor", 10);
            set("long", "Ò»Ë«¸ß³ÝÎÚÄ¾µÄÄ¾åì¡£\n");
        }
        setup();
}    
 // cloth.c
//
// This is the basic equip for players just login.
#include <ansi.h>
#include <armor.h> 
inherit CLOTH; 
void create()
{
        set_name("»ÆÂÌÉ«¿ã¹Ó", ({ "cloth" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "Ò»Ì×»ÆÂÌÉ«µÄ¿ã¹Ó¡£\n");
                set("unit", "¼þ");
                set("material", "cloth");
                set("armor_prop/armor", 1);
                set("female_only", 1);
                set("value", 100);
        }
        
}    

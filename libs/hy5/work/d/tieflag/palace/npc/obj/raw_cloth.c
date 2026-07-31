#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("ÊÞÆ¤", ({ "hide"}) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("for_create_cloth",1);
                set("material", "cloth");
                set("long", "Ò»¼þÒ°ÊÞÆ¤¡£\n");
                set("value", 1000);
                set("armor_prop/armor", 50);
        }
        
}   

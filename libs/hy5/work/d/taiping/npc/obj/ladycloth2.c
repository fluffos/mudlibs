#include <armor.h>
#include <ansi.h> 
inherit CLOTH; 
void create()
{
        set_name(RED"´óºìÑó¶ÐÕ­°À"NOR, ({ "ao" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("long","Ò»¼þ´óºìÑó¶ÐÕ­°À¡£\n");
                set("material", "cloth");
                set("armor_prop/armor", 5);
                set("value",100);
        }
        
}  

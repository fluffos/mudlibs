 // maple_leaf
#include <weapon.h>
#include <ansi.h> 
inherit ITEM;  
void create()
{
        set_name(HIR"Îå½Ç·ãÒ¶"NOR, ({ "maple leaf", "leaf" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",     "Ò»Æ¬Ñ¤ÀöµÄ·ãÒ¶¡£\n");
                set("unit", "Æ¬");
                set("weight",1);
                set("value", 1);
        }
        set("castable",1);
        setup();
}       

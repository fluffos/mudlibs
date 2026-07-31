 inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("Âé´ü", ({ "big bag", "bag", "Âé´ü"}) );
        set_weight(500);
        set_max_encumbrance(8000000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¸ö");
                set("long", "¹Ä¹ÄÄÒÄÒµÄ´óÂé´ü¡£\n");
                set("value", 1);
                set("prep", "in");
        }
        
} 
int is_container() { return 1; }  

 inherit ITEM;
#include <ansi.h> 
void create()
{
        set_name( "÷È±¶", ({ "zhubao"}) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "“ª¥Û∂—÷È±¶°£\n");
                set("unit", "∂—");
                set("value", 2000);
                set("no_sell",1);
                set("thief_obj",1);
        }
        
}   

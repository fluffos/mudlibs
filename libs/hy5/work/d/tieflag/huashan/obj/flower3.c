#include <ansi.h>
inherit ITEM; 
void create()
{
        set_name("ç³Ò¹Ó£", ({"ye ying", "ye ju"}) );
        set_weight(20);
        if( clonep() )
          set_default_object(__FILE__);
        else {
            set("unit", "¶ä");
            set("long", "Ò»¶äç³Ò¹Ó£¡£\n");
            set("value", 10);
        }
        setup();
}     

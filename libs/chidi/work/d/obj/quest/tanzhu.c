inherit ITEM;
#include <task.h>
void create()
{
        set_name("µ¯Öé", ({"tan zhu", "zhu"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "Å·Ñô¿ËÐ¡Ê±ºòÍæµÄµ¯Öé¡£\n");
                set("unit", "¿Ã");
               set("owner_name","Å·Ñô¿Ë");
               set("owner_id","ouyang ke");
        }
}


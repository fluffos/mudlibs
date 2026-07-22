inherit ITEM;
#include <task.h>
void create()
{
        set_name("Ä¾ÌÒ½£", ({"mutao jian", "jian"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "»ÆÒ©Ê¦Á·½£Ê±ÓÃµÄÄ¾ÌÒ½£¡£\n");
                set("unit", "°Ñ");
               set("owner_name","»ÆÒ©Ê¦");
               set("owner_id","huang yaoshi");
        }
}

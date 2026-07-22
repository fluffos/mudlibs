inherit ITEM;
#include <task.h>
void create()
{
        set_name("¹ÅÌÙ±­", ({"guteng bei", "bei"}));
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "Ò»Ö»¼áÓ²ÈçÌúµÄ¹ÅÌÙ±­¡£\n");
                set("unit", "Á£");
               set("owner_name","×æÇ§Çï");
                 set("owner_id","zu qianqiu");
        }
}


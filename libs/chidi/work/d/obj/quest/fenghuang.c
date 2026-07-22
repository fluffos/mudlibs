inherit ITEM;
#include <task.h>
void create()
{
        set_name("±ÌÓñ·ï»Ë", ({"biyu fenghuang", "fenghuang"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "Ò»×ğÓñµñ¿Ì³ÉµÄ·ï»Ë£¬ÊÇÔ¬×ÏÒÂËÍ¸øºúì³µÄ¡£\n");
                set("unit", "×ğ");
                set("owner_name","ºúì³");
                set("owner_id","hu fei");
        }
}


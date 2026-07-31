
// magic_armor2.c
#include <ansi.h>
#include <armor.h>
inherit ARMOR;
void create()
{       set_name( BLU "½ð¸ÕÕ½¼×" NOR, ({RED "magic armor","armor" NOR}));
        set_weight(1);
        if(clonep())
                set_default_object(__FILE__);
        else{
        set("unit","¼þ");
        set("material","gold");
        set("armor_prop/armor",360);
        set("armor_prop/dodge",40);
            }
        set("no_get",1);
        setup();
}

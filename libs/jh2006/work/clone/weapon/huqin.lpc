// huqin.c
#include <weapon.h>
inherit HAMMER;

void create()
{
        set_name( "胡琴" , ({ "hu qin", "huqin"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一件天山南北常见的乐器，声音苍凉悠扬，弹起来别有韵味。\n");
                set("value", 100);
                set("material", "wood");
        }
        init_hammer(5);
        setup();
}

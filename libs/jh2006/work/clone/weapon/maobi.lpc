// maobi.c 毛笔
// by iceland

#include <weapon.h>
inherit SWORD;

void create()
{
        set_name( "毛笔", ({  "mao bi" , "maobi" , "bi"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "支");
                set("long", "一支用于书写的毛笔，竹制笔杆，三寸来长，入手轻飘飘的。\n");
                set("value", 5);
                set("material", "wood");
              }
        init_sword(1);
        setup();
}
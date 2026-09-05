//made by goodtaste
//date 1998.12.11
#include <ansi.h>
inherit ITEM;

void create()
{        set("no_get",1);
         set("no_give",1);
         set("no_drop",1);
         set_name("苍龙神灯", ({ "lampe"}));
         set_weight(1000);
         if (clonep())
                set_default_object(__FILE__);
         else {
                set("unit", "盏");
                set("long", "一盏上古时代留下的神灯，上面刻画着一些你看不懂符号\n");
                set("value", 100000);
                }
        
        setup();
}


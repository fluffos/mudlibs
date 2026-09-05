//铁精 zine Oct 16 2010
inherit ITEM;
#include <ansi.h>
void create()
{
        string* color=({RED,WHT});
        
        set_name(color[random(sizeof(color))]+"铁精"NOR, ({"tie jing", "jing", "iron essence" }));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一个闪闪发光的铁块，似乎蕴含着某种力量。\n");
                set("unit", "块");
                set("value", 0);
                set("available", 10);
             }
        setup();
        call_out("dest",7200);

}

int dest()
{
    message_vision("$N上的锈斑在空气中迅速扩大，片刻之后，化为无形。\n",this_object());
    destruct(this_object());
    return 1;
}


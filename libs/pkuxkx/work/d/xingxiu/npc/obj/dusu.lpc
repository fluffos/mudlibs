// 毒素 Oct 21 2010

inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIB"毒液"NOR, ({"du ye", "poison"}));
        set_weight(1);
        set("long", "这是一滴毒液，用来制作冰魄杖的材料。\n");
        set("unit", "滴");
        set("value", 0);
         
        setup();
        call_out("dest",60);
}

int dest()
{
    if (environment(this_object()))
    {
    
    tell_object(environment(this_object()),"毒液在空气中渐渐挥发了。\n");
    }
    destruct(this_object());
    return 1;
}


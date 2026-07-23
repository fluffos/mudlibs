// item: /d/xingxiu/npc/obj/fire.c
// Jay 3/17/96
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIR"魔法火焰"NOR, ({"fire", "magicfire"}));
        set_weight(80);
        if (clonep())
                set_default_object(__FILE__);
        else {
         set("long", RED"这是一团魔法火焰，照亮了前放的黑暗。\n"NOR);
                set("unit", "团");
                set("value", 0);
                set("no_drop", 1);
                set("no_get", 1);
                set("no_put", 1);
                set("no_steal", 1);
        }
}

void init()
{
     call_out("dest", 300);   
}

 
void dest()
{
        tell_room(environment(this_object()),HIR"魔法火焰失去了魔力，渐渐地熄灭了。\n"NOR);
        destruct(this_object());
}

inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(WHT"外星水晶"NOR, ({ "shui jing","shuijing"}));
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "粒");
                set("long","这是一根粒通体晶莹剔透的水晶\n雕成的，拿在手中轻若无物，似乎是制造兵器的绝好材料。\n");
                set("value", 0);
		   set("for_create_weapon",1);
                set("material", "brass");
              }
}
void owner_is_killed()
{
        destruct(this_object());
}

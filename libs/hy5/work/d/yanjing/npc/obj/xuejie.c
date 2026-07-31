#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(RED"血竭"NOR,({"xuejie"}));
        set_weight(900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "两");
                set("long", "中药材之一.\n");
                set("value", 100);
        }
}

void init()
{
 add_action("do_eat","eat");
}
int do_eat(string arg)
{
 if (!arg||arg!="xuejie") return notify_fail("你想吃什么?\n");
if (!living(this_player())) return 0;
this_player()->apply_condition("youming",0);
message_vision("$N忙不迭的吃下一段"+this_object()->name()+",全身流出些红色汁液来.\n",this_player());
destruct(this_object());
return 1;
}


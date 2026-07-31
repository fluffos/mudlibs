inherit ITEM;
#include <ansi.h>

void init()
{
        add_action("do_eat", "tun");
}

void create()
{
	set_name("草药", ({"cao yao","cao","yao"}));
        set("unit", "株");
	set("long", "这是一株普通的草药。\n");
        setup();
}

int do_eat(string arg)
{
if (!id(arg))  return notify_fail("你要吃什么？\n");
if(arg=="yao") 
{
tell_object(this_player(), HIG "你只觉一股清香沁入心肺,顿时灵台一片空明,神意清爽！\n" NOR );
this_player()->set_temp("nopoison", 1);
this_player()->set("eff_jingli",this_player()->query("max_jingli"));
this_player()->set("jingli",this_player()->query("max_jingli"));
this_player()->set("eff_qi",this_player()->query("max_qi"));
this_player()->set("qi",this_player()->query("max_qi"));
destruct(this_object());
}
return 1;
}

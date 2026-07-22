// ITEM: /d/huashan/obj/firing.c
// Date: Look 99/03/25

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(RED"火折"NOR, ({"fire"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
	set("long", "这是正在然烧中的火折。\n");
	set("unit", "支");
	set("value", 80);
        }
}

void init()
{
	call_out("dest",120,this_object(),this_player());
}

void dest(object ob,object me)
{
	me->delete_temp("marks/study");
	message_vision("$N的$n已经烧完了，扑闪了几下，就熄灭了。\n",me,ob);
	destruct(ob);
}
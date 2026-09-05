// 秘制养精丹 治疗有效精神的5%
// by seagate@pkuxkx 2011.02.18

#include <ansi.h>
inherit ITEM;
void setup()
{}

void init()
{
  add_action("do_eat", "eat");
  add_action("do_eat", "fu");
}

void create()
{
	set_name(CYN"少林寺秘制养精丹"NOR, ({"yangjing dan", "dan" }));
    set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "粒");
		set("long", "这是一粒少林寺秘制的养精丹。\n相比外界来说能够治疗更多的精神。\n");
		set("value", 2000);
	}
}

int do_eat(string arg)
{
	object me=this_player();
	int maxjing;
  
  if (!id(arg))
  	return 0;
  
  maxjing=me->query("max_jing");
  me->receive_curing("jing", maxjing*5/100);
  message_vision("$N服下一粒"CYN"少林寺秘制养精丹"NOR"，只觉精神恢复了不少。\n", me);
	destruct(this_object());
	return 1;
}
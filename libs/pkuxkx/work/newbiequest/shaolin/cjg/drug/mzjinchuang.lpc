// 秘制金创药 治疗有效气血的5%
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
	set_name(CYN"少林寺秘制金创药"NOR, ({"jinchuang yao", "yao" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "包");
		set("long", "这是一包少林寺秘制的金创药。\n相比外界来说能够治疗更多的气血。\n");
		set("value", 2000);
	}
}

int do_eat(string arg)
{
	object me=this_player();
	int maxqi;
  
  if (!id(arg))
  	return 0;
  
  maxqi=me->query("max_qi");
  me->receive_curing("qi", maxqi*5/100);
  message_vision("$N小心翼翼地把一包"CYN"少林寺秘制金创药"NOR"敷在伤口上，只觉伤势大为好转，气色看起来好多了。\n", me);
	destruct(this_object());
	return 1;
}

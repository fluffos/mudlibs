// 醒神丹 补 有效精神的5% 仅藏经阁副本有效
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
	set_name(YEL"秘制"GRN"祛毒散"NOR, ({"qudu san", "san" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "剂");
		set("long", "这是一剂少林寺秘制的祛毒散。\n对星宿毒掌、冰魄寒毒、腐尸毒有奇效。\n");
		set("value", 1000);
	}
}

int do_eat(string arg)
{
	object me=this_player(), env=environment(me);
	int dur;
  
  if (!id(arg))
  	return 0;

  if ( me->query_condition("xx_poison") >0 )
	{
	  me->apply_condition("xx_poison", 0);
		message_vision("$N服下了一剂祛毒散，发现星宿毒掌已经被解除了。\n", me);
	}
	else if ( me->query_condition("xxx_poison") >0 )
	{
	  me->apply_condition("xxx_poison", 0);
		message_vision("$N服下了一剂祛毒散，发现冰魄寒毒已经被解除了。\n", me);
	}
	else if ( me->query_condition("fs_poison") >0 )
	{
	  me->apply_condition("fs_poison", 0);
		message_vision("$N服下了一剂祛毒散，发现腐尸毒已经被解除了。\n", me);
	}
	else
		message_vision("$N服下了一剂祛毒散，啥效果也没有发生。\n", me);
		
	destruct(this_object());
	return 1;
}
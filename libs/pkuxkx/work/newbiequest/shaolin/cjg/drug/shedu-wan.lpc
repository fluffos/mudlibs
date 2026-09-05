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
	set_name(YEL"秘制"GRN"五毒散"NOR, ({"wudu san", "san" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "剂");
		set("long", "这是一剂少林寺秘制的五毒散。\n对白驼蛇毒、蟾蜍毒、蝎毒、蛇毒、蜈蚣毒有奇效。\n");
		set("value", 1000);
	}
}

int do_eat(string arg)
{
	object me=this_player(), env=environment(me);
	int dur;
  
  if (!id(arg))
  	return 0;

  if ( me->query_condition("bt_poison") >0 )
	{
	  me->apply_condition("bt_poison", 0);
		message_vision("$N服下了一剂五毒散，发现白驼蛇毒已经被解除了。\n", me);
	}
	else if ( me->query_condition("chanchu_poison") >0 )
	{
	  me->apply_condition("chanchu_poison", 0);
		message_vision("$N服下了一剂五毒散，发现蟾蜍毒已经被解除了。\n", me);
	}
	else if ( me->query_condition("scorpion_poison") >0 )
	{
	  me->apply_condition("scorpion_poison", 0);
		message_vision("$N服下了一剂五毒散，发现蝎毒已经被解除了。\n", me);
	}
	else if ( me->query_condition("snake_poison") >0 )
	{
	  me->apply_condition("snake_poison", 0);
		message_vision("$N服下了一剂五毒散，发现蛇毒已经被解除了。\n", me);
	}
	else if ( me->query_condition("wugong_poison") >0 )
	{
	  me->apply_condition("wugong_poison", 0);
		message_vision("$N服下了一剂五毒散，发现蜈蚣毒已经被解除了。\n", me);
	}
	else
		message_vision("$N服下了一剂五毒散，啥效果也没有发生。\n", me);
	destruct(this_object());
	return 1;
}
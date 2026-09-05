// 醒神丹 补 有效精神的5% 仅藏经阁副本有效
// by seagate@pkuxkx 2011.02.18

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
	set_name("解毒丸", ({"jiedu wan", "wan" }));
    set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗少林寺秘制的解毒丸。\n能够解除玄冰毒的效果。\n");
		set("value", 20000);
	}
}

int do_eat(string arg)
{
	object me=this_player(), env=environment(me);
	int dur;
  
  if (!id(arg))
  	return 0;

  dur=me->query_condition("emerald_poison");
	if ( env->query("outdoors")!="shaolin/cjg" )
		return notify_fail("解毒丸只能在藏经阁任务副本中使用。\n");
	else if ( dur<=0 )
		return notify_fail("你现在没有中玄冰毒不需要服用解毒丸。\n");
	else
	{
	  me->apply_condition("emerald_poison", 0);
		message_vision("$N服用了一颗解毒丸，发现玄冰毒已经被解除了。\n", me);
		destruct(this_object());
		return 1;
	}
}
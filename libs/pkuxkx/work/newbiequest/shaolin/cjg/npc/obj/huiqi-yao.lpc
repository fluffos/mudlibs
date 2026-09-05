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
	set_name("回气药", ({"huiqi yao", "yao" }));
    set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗少林寺秘制的回气药。\n能够少量回复内力。\n");
		set("value", 20000);
	}
}

int do_eat(string arg)
{
	object me=this_player(), env=environment(me);
	int mforce, force, addforce;
  
  if (!id(arg))
  	return 0;

	mforce=me->query("max_neili");
	force=me->query("neili");
	addforce=mforce*33/100;
	
	if ( env->query("outdoors")!="shaolin/cjg" )
		return notify_fail("回气药只能在藏经阁任务副本中使用。\n");
	else if ( force>=mforce )
		return notify_fail("你现在内力充足不需要服用回气药。\n");
	else
	{
	  if ( force+addforce>mforce )
	  	me->set("neili", mforce);
	  else
	  	me->add("neili", addforce);

		message_vision("$N服用了一颗回气药，感觉一股热流涌向丹田。\n", me);
		destruct(this_object());
		return 1;
	}
}
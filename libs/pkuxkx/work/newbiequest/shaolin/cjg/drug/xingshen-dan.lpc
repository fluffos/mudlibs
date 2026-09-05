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
	set_name("醒神丹", ({"xingshen dan", "dan" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗少林寺秘制的醒神丹。\n能够少量回复精神。\n");
		set("value", 2000);
	}
}

int do_eat(string arg)
{
	object me=this_player(), env=environment(me);
	int effjing, jing, addjing;
  
  if (!id(arg))
  	return 0;

	effjing=me->query("eff_jing");
	jing=me->query("jing");
	addjing=effjing*5/100;
	
	if ( env->query("outdoors")!="shaolin/cjg" )
		return notify_fail("醒神丹只能在藏经阁任务副本中使用。\n");
	else if ( jing>=effjing )
		return notify_fail("你现在精神充足不需要服用醒神丹。\n");
	else
	{
	  if ( jing+addjing>effjing )
	  	me->set("jing", effjing);
	  else
	  	me->add("jing", addjing);

		message_vision("$N服用了一颗醒神丹，发现精神好了很多。\n", me);
		destruct(this_object());
		return 1;
	}
}
// 行军散 补 有效气血的5% 仅藏经阁副本有效
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
	set_name("行军散", ({"xingjun san", "san" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "包");
		set("long", "这是一包武林人士必备的行军散。\n能够少量回复气血。\n");
		set("value", 2000);
	}
}

int do_eat(string arg)
{
	object me=this_player(), env=environment(me);
	int effqi, qi, addqi;
  
  if (!id(arg))
  	return 0;

	effqi=me->query("eff_qi");
	qi=me->query("qi");
	addqi=effqi*5/100;
	
	if ( env->query("outdoors")!="shaolin/cjg" )
		return notify_fail("行军散只能在藏经阁任务副本中使用。\n");
	else if ( qi>=effqi )
		return notify_fail("你现在气血充足不需要服用行军散。\n");
	else
	{
	  if ( qi+addqi>effqi )
	  	me->set("qi", effqi);
	  else
	  	me->add("qi", addqi);

		message_vision("$N小心翼翼地把一包行军散敷在伤口上，只觉伤势大为好转，气色看起来好多了。\n", me);
		destruct(this_object());
		return 1;
	}
}


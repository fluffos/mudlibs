// 门忠丹 每颗100门忠
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
	set_name("门忠丹", ({"score dan", "dan" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "粒");
		set("long", "门忠丹能够少量增加高级玩家的门忠。\n");
		set("value", 20000);
		set("limit_eat",1);
	}
}

int eat_dan(object me)
{
  me->add("score", 100);
  message_vision("$N服用了一粒门忠丹。\n", me);
	destruct(this_object());
	return 1;
}

int do_eat(string arg)
{
	object me=this_player();
  
  if (!id(arg))
  	return 0;
  else if ( me->query_combatgrade() < 70 )
  	return notify_fail("你的经验太低了服用不了门忠丹。\n");

  return eat_dan(me);
}
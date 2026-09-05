// 声望丹 每颗1万声望
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
	set_name("声望丹", ({"repute dan", "dan" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "粒");
		set("long", "声望丹能够少量增加高级玩家的声望。\n");
		set("value", 20000);
		set("limit_eat",1);
	}
}

int eat_dan(object me)
{
  me->add("repute", 10000);
  message_vision("$N服用了一粒声望丹。\n", me);
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
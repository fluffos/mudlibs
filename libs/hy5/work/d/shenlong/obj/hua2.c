// hua2.c 无名花
inherit ITEM;

//void init()
//{
//	add_action("do_eat", "eat");
//}

void create()
{
	set_name("无名花", ({"hua2", "wuming"}));
	set("unit", "朵");
	set("long", "这是一朵无名小花，花蕊虽小，却十分美丽。\n");
	setup();
}

int do_eat(string arg)
{
	object me=this_player();
	if (!id(arg))  return notify_fail("你要吃什么？\n");
	if(arg=="hua2")
	{
//		me->add("max_neili",5);
//		me->unconcious();
		destruct(this_object());
	}
	return 1;
}

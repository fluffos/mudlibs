
// yuwang.c 鱼网

inherit ITEM;

void create()
{
	object me;
	string new_name;
	me=this_player();
	set_name("鱼网", ({"yu wang","yuwang"}));
//	  new_id = me->query("id")+"_yuwang";
//	  set_name("鱼网", ({new_id}));
	set("long",
		"这是一张鱼网。\n");
	set("unit", "张");
	set("weight", 1000);

		new_name = me->query("name")+"的鱼网";
		set("long",
		"这是"+new_name+"。\n"
		"这种鱼网是逍遥派为了捕捉寒冰池里的娃娃鱼而特别制造的。\n");
	setup();
}

void init()
{
	add_action("do_wang", "wang");
}

int do_wang(string arg)
{	  int i;
	   object me,ob;
	   me=this_player();
	   
	   if (!arg || (arg != "wawa yu"))
		   return notify_fail("你要网什么？\n");

	   i = random(3);
	if (ob = present("wawa yu",environment(me)))
	   if(this_player()->query_temp("wang/网鱼")==1) 
	   if(i == 0)
	 {
	 me->start_busy(random(2));
	 message_vision(
	  "只见$N挥动着鱼网把娃娃鱼网进了网中。 \n"
	  "娃娃鱼被鱼网牢牢的网住了! \n" , this_player());

	ob = new(__DIR__"wawayu1");
	ob->move(environment(this_player()));
	 
	destruct(present("wawa yu",environment(me)));
	this_player()->set_temp("wang/网鱼",0);
	this_player()->set_temp("wang/鱼",1);
	return 1;
	 }

	else
	 {
	  me->start_busy(random(2));
	  message_vision(
	   "只见$N挥动着鱼网准备网娃娃鱼, 可是娃娃鱼确从你身边遛了过去。 \n", this_player());
	  return 1;
	 }
	
	   else 
	{
	message_vision(
	 "娃娃鱼是$N能捕的吗? \n", this_player());
	return 1;
	}
   else
	 {
	 message_vision(
	 "你要网什么？ \n", this_player());
	 return 1;
	 }
}

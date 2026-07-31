// zhulin2.c
//by dicky

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "竹林小道");
	set("long", @LONG
四周都是密密的竹林，一踏进这里你就迷了路。这里人迹罕至，
惟闻足踏草坪之声。偶尔有微风轻拂竹叶，又如簌簌禅唱，令人尘
心为之一涤，真是绝佳的清修所在。由于这里的竹子(zhuzi)长得特
别的结实粗壮，所以偶尔也有人来这里砍伐(chop)竹子做成器具。
LONG);

        set("outdoors", "houjizhen");

	set("exits", ([
		"south" :  __DIR__"zhulin1",
		"north" :  __DIR__"zhulin3",
	]));

	set("item_desc",([
		"zhuzi" : "这是一片茂盛的竹林，竹子长得非常粗壮。\n", 
	]));

	setup();
//	replace_program(ROOM);
}

int init()
{
	add_action("do_kan","fa");
	add_action("do_kan","chop");
	add_action("do_make","make");
}

int do_kan(string arg)
	{
	object me;
	me = this_player();
	if ( !living(this_player()) || arg != "zhuzi" )
	return 0;

        if (!present("pozhu fu", me))
	return notify_fail("你还是先去弄把破竹斧再说吧！\n");

	if ((int)me->query_skill("unarmed", 1) < 200)
	return notify_fail("看这里的环境多么幽雅，你忍心破坏这里的自然环境么？\n");

	if ((int)me->query_temp("taxue/zhuzi") >=4 )
	return notify_fail("竹子已经够用了，你还是回去吧！\n");

        if ( (int)me->query("qi") < 200) 
	{
		me->receive_damage("qi", 10 ,"tire");
		write("你太累了，还是休息一下再砍吧！\n");              
        return 1;
	}

	if (!(int)me->query_temp("taxue/zhuzi"))
	{
		me->receive_damage("qi", 100,"tire");
		message_vision("$N挥动破竹斧用力朝竹子砍去，一会就砍倒一棵粗壮的竹子，真是干净利落。\n", me); 
		me->set_temp("taxue/zhuzi",1); 
	return 1;
	}		

	me->receive_damage("qi", 100,"tire");
	message_vision("$N挥动破竹斧用力朝竹子砍去，一会就砍倒一棵粗壮的竹子，真是干净利落。\n", me);  
	me->add_temp("taxue/zhuzi",1);       
	return 1;
} 

int do_make(string arg)
	{
	object me,ob,ob1;
	me = this_player();
	if ( !living(this_player()) || arg != "fengzheng" )
	return 0;

	if (!(int)me->query_temp("taxue/zhuzi"))
	return notify_fail("你没有竹子，怎么做风筝？\n");

	if ((int)me->query_temp("taxue/zhuzi") < 4 )
	return notify_fail("这么点竹子，做什么风筝？你还是再砍点吧！\n");

        if (!present("bu pi", me) && !present("sheng zi", me))
	return notify_fail("做风筝？好象还缺少点什么吧！\n");

        if ( !me->query_temp("taxue/ask_master"))
		return notify_fail("嘿嘿，你做风筝干什么呢？给我一个理由先！\n");

        message_vision(HIC"$N挥动破竹斧，把竹子劈开，然后用绳子把竹片和布匹连接起来，不一会就做成了一个大风筝。\n"NOR, me); 
	ob1 = present("sheng zi", me);
	destruct(ob1);
	ob1 = present("bu pi", me);
	destruct(ob1);
	ob=new(__DIR__"obj/fengzheng");
	ob->move(me);
	me->delete_temp("taxue/master_ask");
	me->delete_temp("taxue/zhuzi");   
	return 1;
} 
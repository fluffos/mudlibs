// Room: jingtang.c

inherit ROOM;

void create()
{
        set("short", "大经堂");
        set("long", @LONG
殿为十字歇山顶，形制峻瑰，殿堂规模宏大，内有大柱上千根，可同时容纳
几百名僧人同时诵经。殿前有跃马、伏虎、卧牛、怪兽、等许多石雕像。殿内大
柱和四面墙壁上刻满经文，有几个僧人正在柱下禅定(chanding)，还有些僧人对
着墙壁上的经文冥思苦想(mingxiang)。
LONG
        );

        set("exits", ([
                "west" : __DIR__"fanyinge",
                "south" : __DIR__"jingjinzhacang",
        ]));

        setup();
}

void init()
{
        add_action("do_chanding", "chanding");
        add_action("do_mingxiang", "mingxiang");
        add_action("do_write","write");
}

int do_chanding()
{
	object me;
	me = this_player();

	if (me->is_fighting())
		return notify_fail("你无法在战斗中禅定。\n");

	if (me->is_busy())
		return notify_fail("你正忙着呢。\n");

	if (me->query_skill("literate",1) < 10)
		return notify_fail("经文深奥玄妙，你识字不多，无法领悟。\n");

	if (me->query_skill("huanxi-chan",1) > 30)
		return notify_fail("石柱上的经文你已经领悟透彻了，禅定对你没什么帮助了。\n");

	if((int)me->query("jing") < 20) 
		return notify_fail("你刚要冥想，只觉得天旋地转，原来你太疲劳了......\n");

	me->add("jing", -10+random(5));
	me->improve_skill("huanxi-chan", me->query("int"));
	write("你对着大柱禅定，仿佛对大柱上的经文有所领悟。\n");
	return 1;
}

int do_mingxiang()
{
	object me;
	me = this_player();
	
	if (me->is_fighting())
		return notify_fail("你无法在战斗中冥想。\n");

	if (me->is_busy())
		return notify_fail("你正忙着呢。\n");

	if (me->query_skill("literate",1) < 10)
		return notify_fail("经文深奥玄妙，你识字不多，无法领悟。\n");

	if (me->query_skill("huanxi-chan",1) < 30)
		return notify_fail("你屏息静气，闭目冥想。脑中却一片空白，原来你的基础太差了。\n");

	if (me->query_skill("huanxi-chan",1) > 100)
		return notify_fail("石壁上的经文你已经领悟透彻了，冥想对你没什么帮助了。\n");

	if((int)me->query("jing") < 50)
		return notify_fail("你刚要冥想，只觉得天旋地转，原来你太疲劳了......\n");

	me->add("jing", -(20+random(10)));
	me->improve_skill("huanxi-chan", me->query("int"));   
	write("你屏息静气，闭目冥想，似乎对墙壁上的经文有所领悟。\n");
	return 1;
}

int do_write(string arg)
{
	object me ;
	int lite;

	me = this_player();
	lite = me->query_skill("literate");

	if ( arg != "jingshu" || !arg) 
		return notify_fail("你要写什么？\n");

	if (me->is_fighting())
		return notify_fail("你无法在战斗中写经书。\n");

	if (me->is_busy())
		return notify_fail("你正忙着呢。\n");

	if (me->query_skill("literate",1) < 10)
		return notify_fail("你大字不识几个，也想写经书？\n");

	if (me->query_skill("huanxi-chan",1) < 30)
		return notify_fail("你看着满墙密密麻麻的文字，只觉头脑发涨，没有头绪。原来你的基础太差了。\n");

	if ((!present("bo juan", this_player())) || (!present("mao bi", this_player()))) 
		return notify_fail("现在你书写所用的器具不够，无法写经书。\n");
 
        if( me->query_temp("fojing"))
                return notify_fail("你已经抄好经文了。\n");

	if ((me->query_temp("write") == 20 ) && (lite < 30)) {
		new("/clone/misc/fojing3")->move(me);
		me->set_temp("fojing", 1);
		message_vision("你将写好的帛绢按次序理顺，伸了个懒腰，终于抄完了。\n",me);
		return 1;
	}
	if ((me->query_temp("write") == 35 ) && (lite < 100) && (lite >= 30)) {
		me->set_temp("fojing", 1);
		new("/clone/misc/fojing1")->move(me);
		message_vision("你将写好的帛绢按次序理顺，伸了个懒腰，终于抄完了。\n",me);
		return 1;
	}
	if ((me->query_temp("write") == 50 ) && (lite >= 100)) {
		new("/clone/misc/fojing2")->move(me);
		me->set_temp("fojing", 1);
		message_vision("你将写好的帛绢按次序理顺，伸了个懒腰，终于抄完了。\n",me);
		return 1;
	}
	me->add_temp("write", 1);
	message_vision("$N展开铺平帛绢，用毛笔将墙壁上的经文工工整整的录了下来。\n", me);
	return 1;
}

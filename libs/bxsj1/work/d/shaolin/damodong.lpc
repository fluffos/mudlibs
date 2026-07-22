// Room: /d/shaolin/damodong.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "达摩洞");
	set("long", @LONG
这里是达摩古洞。五百年前南天竺僧人菩提达摩来到少林寺，见此风水
宝地，就住下来广罗弟子，传授禅宗，开创少林寺佛教禅宗千年不败之基。
达摩祖师常在此面壁悟道，一坐十年，壁间隐隐似仍可看到他面壁时的打坐
姿态。除地上的几块竹片外，洞中空无一物。
LONG
	);

	set("exits", ([
		"out" : __DIR__"bamboo1",
	]));

	set("coor/x",40);
	set("coor/y",520);
	set("coor/z",150);
	setup();
}

void init()
{
	object me = this_player();

	if ((int)me->query_temp("bamboo/count") == 14 
	&&  (int)me->query_skill("dodge", 1) >= 30 
	&&  (int)me->query_skill("dodge", 1) <= 100 
	&&  present("bamboo", me) )
	{
		me->receive_damage("jing", 20);
		me->improve_skill("dodge", me->query("int"));
	}

	add_action("do_mianbi","mianbi");	
}

int do_mianbi()
{
	int i,j,x,y;
	object me = this_player();
	i = (int)me->query("shen");
	j = me->query("combat_exp");
	y = me->query_skill("yijin-jing",1);
	x = me->query_skill("buddhism",1);

	if ( me->is_busy() ) return notify_fail("你正忙着呢,心情静不下来。\n");

	me->start_busy(random(2));
	if (me->query("jing") < 100)
		return notify_fail("你精神恍惚，需要休息了。\n");
	me->receive_damage("jing", 50+random(50));
	if (x >= 200)
		if (i < 0) {
			me->add("shen",1000+random(5000));
			message_vision("$N面对着达摩洞后半边的石壁跌坐静思，良久，似有所悟。\n", me);
			me->set_temp("sl_mianbi",1);
			return 1;
		} else if ( i > 0) {
			me->add("shen",-1000-random(5000));
			me->set_temp("sl_mianbi",2);
			message_vision("$N面对着达摩洞后半边的石壁静坐沉思良久，似有所悟。\n", me);
			return 1;
		}
	message_vision("$N面对着达摩洞后半边的石壁沉思了一会，结果心情越想越乱，不由地站了起来。\n", me);
	return 1;
}

// Room: /d/emei/jiulaodong.c 峨嵋派 九老洞

inherit ROOM;

void create()
{
	set("short", "华藏庵广场");
	set("long", @LONG
这里是峨嵋华藏庵的广场，地上铺着青砖。正前方有一道台阶，通往大
雄宝殿。殿前有个丈许高的大香炉，香炉前的香台上，红烛高烧，香烟飘绕。
广场上有几个小师太正在练功。自此左右各有一条走廊通向后殿。
LONG
	);

	set("exits", ([
//		"northeast" : __DIR__"jiudaoguai4",
//		"northwest" : __DIR__"lianhuashi",
	]));

	set("objects",([
		"/d/shaolin/obj/book-bamboo" : 1,
	]));
	setup();
}
/*
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

        add_action("do_mianbi","面壁");	
        add_action("do_mianbi","mianbi");	
}

int do_mianbi()
{
	object me = this_player();

	message_vision("$N面对着达摩洞後半边的石壁跌坐静思，良久，似有所悟。\n", me);
	
	me->set_busy(10);
	me->set("shen",0);

	return 1;
}
*/

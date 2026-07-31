// Room: /u/qingyun/jyzj/shanbi.c
// Updated by jpei

inherit ROOM;

int do_findbook();
void create()
{
	set("short", "山壁");
	set("long", @LONG
陡峭的山壁，全为极为坚硬的岩石，滑不溜脚，稍微不小心就会滑倒。往
西而下是一片翠谷，往东而下是一山沟。
LONG	);
	set("exits", ([
		"westdown" : __DIR__"cuigu",
		"eastdown" : __DIR__"shangou",
	]));
	set("objects",([
		__DIR__"obj/monkey-rock" : 1,
	]));

//if ( random(2) == 0 )
//{
	set("objects",([
		__DIR__"npc/xiaohou" : 1,
		__DIR__"obj/monkey-rock" : 1,
	]));
//}
	set("outdoors", "kunlun");
	set("no_clean_up", 0);

	setup();
}

void init()
{
	add_action("do_bind", ({"bind", "baoza", "xugu", "bandage", "heal", "zhi", "yizhi", "zhiliao"}));
	add_action("do_findbook", ({"findbook"}));
}

int do_bind(string arg)
{
	object monkey, plywood1, plywood2, yaocao, thread;
	object me = this_player();

	if (arg == "xiao hou" || arg == "hou" || arg == "monkey") {
		if (!(monkey = present("xiao hou", this_object())))
			return notify_fail("再仔细瞅瞅，这里没有猴子！\n");
		if (!monkey->query("get_wound"))
			return notify_fail("它并没有受伤！\n");
		if (!monkey->query("rock_moved"))
			return notify_fail("它被压在岩石下面哪！\n");
		if (!(plywood1 = present("zhi tiao 1", me)) || !(plywood2 = present("zhi tiao 2", me)))
			return notify_fail("可惜你手头没有足够的固定断骨的工具。\n");
		if (!(thread = present("xi si", me)))
			return notify_fail("可惜你手头没有捆扎用的线。\n");
		if (!(yaocao = present("yao cao", me)))
			return notify_fail("可惜你手头没有草药。\n");
		destruct(plywood1);
		destruct(plywood2);
		destruct(thread);
		destruct(yaocao);
		monkey->delete("get_wound");
		monkey->delete("rock_moved");
		me->set_temp("help_monkey", 1);
		new(__DIR__"obj/xianguo")->move(me);
		new(__DIR__"obj/xianguo")->move(me);
		write("你用两根枝条作为夹板，替小猴子续上断骨，把草药嚼烂了给它敷在伤处。\n");
		write("那猴儿居然也知感恩图报，给你摘了些鲜果来，然后就去寻别的猴子玩耍去了。\n");
if (!me->query("jiuyangget") || me->query("jinyong/book12")==2 )
{
	        if (me->query_temp("help_monkey") && !present("jiuyang zhenjing", me) && !query("get_wound") ) {
		tell_object(me, "那只你救过的小猴忽然跑了过来，吱吱喳喳，叫个不停。\n");
		tell_object(me, "顺着它的手指看去，只见一个白色大猿蹲在那里，神情痛苦。\n");
		new("/d/fairyland/npc/dabaiyuan")->move(environment(me));
		me->delete_temp("help_monkey");
          	}
}
//                destruct(monkey);
//		monkey->random_move();
                call_out("dis", 1);
	}
	return 0;
}

void dis(object monkey)
{
	monkey = present("xiao hou", this_object());
	destruct(monkey);
}

int do_findbook()
{
	object thread, yaocao;
	object me = this_player();

if (me->query("jiuyangok")  && !present("jiuyang zhenjing", me))
{
		new("/d/fairyland/obj/jiuyang-zhenjing")->move(me);
		write("你找油布包裹，打开一看，是一套经书。\n");
me->start_busy(60);
	return 1;
 }
      		

	return 0;
}

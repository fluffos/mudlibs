//      chufang.c 厨房
inherit ROOM;
void init();
int work();

void create()
{
	set("short", "厨房");
	set("long", @LONG
这里是雪山寺的厨房，新来的僧人可以在此打杂。房
中醒目的位置有一块牌子。
LONG );
	set("item_desc", ([
		"【牌子】" : "本厨房招收杂工。工作(work)一次付银十两。\n"
		ZJOBACTS2"打工:work\n",
	]));
	set("no_fight",1);
	set("no_steal",1);
	set("exits", ([
		"south" : __DIR__"xiaoyuan",
	]));

	set("objects", ([
		__DIR__"obj/cha" : 2 + random(2),
		__DIR__"obj/nailao" : 2 + random(2),
	]));

	set("resource/water", 1);

	set_temp("times" , 5);
	setup();
}

void init()
{
	add_action("do_work","work");
}

int do_work()
{
	object me = this_player();
	object ob;

	if (me->is_busy())
		return notify_fail("你正忙着呢！\n");
	if (query_temp("times")==0)
		return notify_fail("今天的活干完了，明天再来吧！\n");
	if(me->query("qi")<20)
		return notify_fail("你的气太虚弱，不能工作！\n");
	me->add("qi",-20);
	message_vision("$N干了一些杂活，累得够呛，好在拿到了10两银子的工钱。\n" , me);
	add_temp("times",-1);

	ob=new("/clone/money/silver");
	ob->set_amount(10);
	ob->move(me);
	me->start_busy(6);
	return 1;
}

void reset()
{
	::reset();
	set_temp("times", 5);
}


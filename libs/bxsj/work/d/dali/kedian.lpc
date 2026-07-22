// Room: /dali/kedian.c
// bbb 1997/06/11
// Modify By River 98/12

inherit ROOM;
string look_sign(object me);

void create()
{
        set("short", "迎宾馆");
	set("long", @LONG
你现在正站在大理城北边的一家客店里，这家客店是大理城最负盛名的一
家，来自中原的旅人都喜欢聚集在这里交换旅途上的见闻，你也可以在这里打
听到许多有趣的消息。靠近门口的地方有一块乌木雕成的招牌(sign)。
LONG
	);

	set("valid_startroom", 1);

	set("item_desc", ([
		"sign": (: look_sign :),
	]) );

	set("exits", ([
		"enter" : __DIR__"kedian2",
		"north" : __DIR__"qsjie1",
	]));

	set("objects", ([
	__DIR__"npc/xiaoer" : 1 ])
        );
	setup();
}

void init()
{
	object me = this_player();

	if(me->query_temp("xuncheng")){
		me->set_temp("dali_xc/kedian",1);
	}
}

string look_sign(object me)
{
	if (wizardp(me))
		return "招牌写着：猛鬼客栈。\n";
	return "招牌写着：内设雅房，每夜五两白银。\n";
}

int valid_leave(object me, string dir)
{
	if ((string)me->query_temp("rent_paid")!="大理迎宾馆" && dir == "enter" )
		return notify_fail("怎么着，想白住啊！\n");
	if ((string)me->query_temp("rent_paid")=="大理迎宾馆" && dir == "east" )
		return notify_fail("客官已经付了银子，怎么不住店就走了呢！旁人还以为小店伺候不周呢！\n");
	return ::valid_leave(me, dir);
}

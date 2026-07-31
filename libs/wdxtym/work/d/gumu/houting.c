// houting.c 后厅
#include <ansi.h>
inherit ROOM;

int do_tang(string arg);
int do_niu(string arg);

void create()
{
	set("short", "后厅");
	set("long", @LONG
这里是古墓的后厅，密封得严严实实，没有一丝的缝隙。在昏暗
的灯光下，你发现墙上悬挂着一幅画 (picture)，似乎是一幅人物的
肖像。在厅的中央，摆放着几具棺材(coffin)，其中只有一具棺材的
棺板没有合上，棺材中好象空空如也。
LONG
	);

	set("exits", ([
		"north" : __DIR__"zhengting",
	]));

	set("item_desc", ([
		"【画卷】": "画中是一个中年道士的背影，看不出什么相貌，画中人一手指天，画角题着‘" + MAG "活死人像" NOR + "’几个大字。\n",
		"【棺材】": "用厚厚的石板做成的棺材，棺板合上后，就没有一丝的缝隙了。\n"
			ZJOBACTS2"躺进去:tang coffin\n",
	]) );

	set("getbook", 1);
	set("valid_startroom",1);

	setup();
}

void init()
{
	add_action("do_tang", "tang");
	add_action("do_niu", "niu");
}

int do_tang(string arg)
{
	object me = this_player();
	object ob;

	if (! arg || arg != "coffin")
	{
		return notify_fail("你要躺在哪儿？\n");
	}

	if (query("getbook") > 0)
	{
		tell_object(me,"你躺进棺材中，把棺板合上，顿时一片黑暗，似乎与红尘隔绝了，摸索中你似乎发觉棺板内壁题着有字，细细摸来，好象一头写着【"
					+HIY"玉女心经，技压全真；重阳一生，不输与人"NOR+"】这样十六个大字，另一头好象是一些图形之类的符号。你不知所以，心想管他的先"
				"拓下来再说，于是脱下身上布衫，细细地将板上文字全部拓了下来。\n");
		tell_object(me,"正在拓字之间，你似乎摸到棺角上有一块凸起的机关(lock)。\n");
		tell_object(me,"你可以试着"ZJURL("cmds:niu lock")+ZJSIZE(15)"扭一下"NOR"(niu)机关。\n");

		ob = new("/clone/book/jiuyin3");
		ob->move(me, 1);
		add("getbook", -1);
	} else
	{
		tell_object(me,"你躺进棺材中，把棺板合上，顿时一片黑暗，似乎与红尘隔绝，摸索中你似乎发觉棺板内壁以前刻着有字，不过这字迹已经被人故意刮掉了。\n");
		tell_object(me,"突然间，似乎摸到棺角上有一块凸起\n的机关(lock)。\n");
		tell_object(me,"你可以试着"ZJURL("cmds:niu lock")+ZJSIZE(15)"扭一下"NOR"(niu)机关。\n");
	}

	me->set_temp("tmarks/棺", 1);
	return 1;
}

int do_niu(string arg)
{
	object me=this_player();

	if (! arg || arg != "lock" || me->query_temp("tmarks/棺", 1) < 1)
		return notify_fail("你要扭动什么？\n");

	message_vision("$N手握机关，轻轻向下扭动，忽然间棺底吱吱作响，裂开了一个大洞，$N向洞中落了下去。\n", this_player());
	me->move(__DIR__"mishi2");

	me->set_temp("tmarks/棺",0);
	return 1;
}
void reset()
{
	set("getbook", 1);
}


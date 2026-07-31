// Room: /d/xiangyang/maoshe.c  茅舍
// Date: Feb . 2 2002 by Pound

#include "room.h"

inherit ROOM;

int do_find(string);
int do_fang(string);

void create()
{
	set("short", "茅舍");
	set("long", @LONG
这是一间茅舍，屋中木桌木凳，屋角有个放日常用具的木架，陈设跟
寻常农家无异，只是纤尘不染，干净得过了份，甚至连墙脚之下，板壁缝
中，也冲洗得没留下半点灰土，令人心中隐隐不安。木桌的抽屉是打开着
的，好象刚刚有人在里面寻找（find）过什么。北面是里屋，有一扇小木
门（door）隔着。
LONG);
	set("item_desc", ([
	    "door" : "这是一扇木门。\n",
	]));    

	set("exits", ([
	    "north" : __DIR__"liwu",
	    "west"  : __DIR__"huapu",
	    "south" : __DIR__"huafang",
	]));
	create_door("north", "木门", "south", DOOR_CLOSED);
	set("no_sleep_room", 1);
	setup();
}

// 七心海棠乃极其珍贵之物，毒性和功效巨大。理应加大其获得难度。
// 所以设计该房间为no_refresh，从而使每次启动后只有9粒种子可以提供给玩家培植。
void reset()
{
	::reset();
	set("no_clean_up", 1);
}

void init()
{
	add_action("do_find", "find");
	add_action("do_fang", "fang");
}

int do_find(string arg)
{
	mapping log; 
	object ob, me, room;
	me = this_player();
	room = find_object("/d/xiangyang/maoshe.c");

	if (me->is_busy())
	    return notify_fail("你正忙着呢。\n");
	if (! arg || (arg != "zhongzi" && arg != "shuipiao"))
	    return notify_fail("你想找什么东西？\n");

	if (me->query("family/family_name") != "关外胡家" ||  
	    me->query_skill("yaowang-miaoshu", 1) < 200)
	    return notify_fail("慑于药王的威名，你担心上面有毒，而将手缩了回来。\n");

	if (arg == "zhongzi" && me->query_skill("yaowang-miaoshu", 1) < 200)
	    return notify_fail("这里整齐摆放着很多种子，但你却都不认识，不知道从何找起。\n");

	if (ob = present(arg, me))
	    return notify_fail("你现在身上不是有这件东西吗，怎麽还想拿？\n");

	if (arg == "zhongzi")
	{
	    log = room->query_temp("zhongzi");
	    if (mapp(log) && log[me->query("id")])
		return notify_fail("你刚才不是来取过种子了吗，怎麽还想拿？\n");
	    if (query("zhongzi_count") >= 9)
		return notify_fail("你找了半天，始终找不到需要的种子。\n");
	    room->set_temp("zhongzi/" + me->query("id"), 1);
	    ob = new(__DIR__"obj/" + arg);
	    tell_object(me, "你左右翻看，终于找到了你需要的" + ob->name() + "。\n");
	    ob->move(me);
	    add("zhongzi_count", 1);
	    me->start_busy(2 + random(2));
	    return 1;
	}

	if (arg == "shuipiao")
	{
	    log = room->query_temp("shuipiao");
	    if (mapp(log) && log[me->query("id")])
		return notify_fail("你刚才不是刚拿了一个水瓢么，怎麽又来拿了？\n");
	    if (query("piao_count") >= 15)
		return notify_fail("你找了半天，始终找不到水瓢。\n");
	    room->set_temp("shuipiao/" + me->query("id"), 1);
	    ob = new(__DIR__"obj/" + arg);
	    tell_object(me, "你从屋角木架上找到了一个" + ob->name() + "。\n");
	    ob->move(me);
	    add("piao_count", 1);
	    me->start_busy(2 + random(2));
	    return 1;
	}
	return 0;
}

int do_fang(string arg)
{
	object ob, me, room;
	me = this_player();
	room = find_object("/d/xiangyang/maoshe.c");

	if (me->query("family/family_name") != "关外胡家" || ! arg || ! ob = present(arg, me))
	    return 0;
	if (arg == "zhongzi")
	{
	    tell_object(me, "你把七心海棠" + ob->query("name") + "又放回到抽屉里。\n");
	    destruct(ob);
	    room->delete_temp("zhongzi/" + me->query("id"));
	    add("zhongzi_count", -1);
	    tell_object(me, "但愿其他弟子能够有机会把七心海棠培植成功。\n");
	    return 1;
	}
	if (arg == "shuipiao")
	{
	    tell_object(me, "你把" + ob->query("name") + "放回到木架上。\n");
	    destruct(ob);
	    room->delete_temp("shuipiao/" + me->query("id"));
	    add("piao_count", -1);
	    return 1;
	}
	return 0;
}

int valid_leave(object me, string dir)
{
	object *inv;
	int i;
	inv = all_inventory(me);

	if (dir == "south") 
	{
	    for (i = 0; i < sizeof(inv); i++)
	    {
		if (inv[i]->is_character())
		    return notify_fail("请你先把扛着的东西放下再进去。\n");
	    }
	}

	if (! wizardp(me) && me->query("family/family_name") != "关外胡家" && dir == "south")
	    return notify_fail("慑于药王的威名，你迈了一步又退了回来。\n");

	return ::valid_leave(me, dir);
}

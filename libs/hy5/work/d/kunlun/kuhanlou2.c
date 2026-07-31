// kuhanlou2.c
// Date: cck 6/6/97

#include <ansi.h>
#include <room.h>

inherit ROOM;

void init();
int do_duanmo(string arg);

void create()
{
	set("short", "苦寒楼二层");
	set("long", @LONG
每个楼层上都铺设了结实的木楼板，八角形的墙身上则开了四扇大窗。
四周墙壁贴着昆仑派历代掌门和高手的画像，并有专门的文字记载着他们
的事迹。从这里往外眺望，只能看到围绕塔周的密密匝匝的云杉林，正是
通过这种忍饥耐寒，清心寡欲的办法以求得对武学孜孜不倦的追求。
LONG
	);

	set("exits", ([
		"up" : __DIR__"kuhanlou3",
		"down" : __DIR__"kuhanlou1",
	]));

	setup();
}

void init()
{
		set("times", random(20));
		set("item_count", 2);

		add_action("do_duanmo", "duanmo");
                add_action("do_duanmo", "see");
}

int do_duanmo(string arg)
{
		object ob, me = this_player();

		if ( (int)me->query("kar") < 20 )
		return notify_fail("你要干什么？\n");

               if ( !arg && (arg != "huaxiang") && (arg != "wall") )
		return notify_fail("你想要端摩什么东西？\n");

		if ( query("item_count") < 1 || me->query_temp("count", 1) <= query("times",1) )
		{
			me->add_temp("count", 1);
			me->receive_damage("jing", 10);
			me->receive_damage("qi", 10);
			return notify_fail("你仔细端摩昆仑派前辈高人的画像，想象他们当年纵横江湖，快意恩仇，不由心中生出许多感慨。\n");
		}

		if ( query("item_count") > 0)
		switch( random(2) )
		{
			case 0:
			add("item_count", -1);
			ob = new("/d/kunlun/obj/weiqi.c");
			ob->move(me);
			ob->delete_temp("count");
return notify_fail("你仔细端摩昆仑派前辈高人的画像，在画像后你找到了一副围棋\n");
			break;

			case 1:
			add("item_count", -1);
			ob = new("/d/kunlun/obj/guzheng.c");
			ob->move(me);
			ob->delete_temp("count");
return notify_fail("你仔细端摩昆仑派前辈高人的画像，在画像后你找到了一张古筝\n");
			break;
		}

		return 1;
}


int valid_leave(object me, string dir)
{

	if (dir == "up" ) me->add_temp("count", 1);
	else 			 me->add_temp("count", -1);

	return ::valid_leave(me, dir);
}




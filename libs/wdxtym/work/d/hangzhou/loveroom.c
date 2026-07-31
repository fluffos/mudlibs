// loveroom.c 相约轩

#include <ansi.h>
#include <room.h>

inherit ROOM;

varargs static void create_food(string nmstr, string* idlist, string longstr)
{
	object obj;

	obj = new("/d/city/obj/food");
	obj->set_name(nmstr, idlist);
	if (longstr)
	      obj->set("long", longstr);
	else
	      obj->set("long", "一盘热气腾腾, 香喷喷的"+nmstr+"。\n");
	obj->move(this_object());
}

varargs static void create_water(string nmstr, string* idlist, string cup, string longstr)
{
	object obj;

	obj = new("/d/city/obj/water");
	obj->set_name(cup, idlist);
	if (longstr)
	      obj->set("long", longstr);
	else
	      obj->set("long", "一杯可口的" + nmstr + "。\n");
	obj->set("liquid/name", nmstr);
	obj->move(this_object());
}

varargs static void create_wine(string nmstr, string* idlist, string cup, string longstr)
{
	object obj;

	obj = new("/d/city/obj/wine");
	obj->set_name(cup, idlist);
	if (longstr)
		obj->set("long", longstr);
	else
		obj->set("long", "一杯醇正的" + nmstr + "。\n");
	obj->set("liquid/name", nmstr);
	obj->move(this_object());
}

void create()
{
	set("short", "相约轩");
	set("long", @LONG
楼外楼的相约轩，四面通窗。湖风拂面，淡淡生暖。远望苏堤一
线，映波，锁澜，望山，压堤，东浦，跨虹六桥断续连沿，烟柳笼纱，
流莺娇啼。近处白堤横亘湖上，堤上杨柳覆地，芳草寒茵如一段碧绸
飘然湖面。室内一张精巧的小桌。桌上一纸精致的菜单(menu)。
LONG);
	set("exits", ([
	    "down" : __DIR__"jiulou",
	]));
	set("sleep_room", 1);
	set("item_desc", ([
	    "menu": @TEXT
	order party :   浓情幽会    (200两银子)

	order end   :   结束狂欢

	close door  :   关闭房门

	open door   :   打开房门
TEXT
	]) );
	set("no_clean_up", 0);
	setup();
	set("no_user", 1);
}

void init()
{
	object me;

	add_action("do_order", "order");
	add_action("do_close","close");
	add_action("do_open","open");
	if (query("order_owner"))
	{
		me = this_player();
		me->set("food", me->query("food") / 2);
		me->set("water", me->query("water") / 2);
	}
}

int do_order(string arg)
{
	object me, env;
	object* oblist;
	string mesg;
	int idx;

	me = this_player();
	env = this_object();
	mesg = query("order_owner");

	if (mesg && (arg == "end") && (mesg == me->query("id")))
	{
		delete_temp("plugin");
		delete("order_owner");
		delete("order_type");
		oblist = all_inventory(env);
		for(idx = 0; idx < sizeof(oblist); idx++)
		{
			if (! objectp(oblist[idx]))
				continue;
			if (userp(oblist[idx]))
				continue;
			destruct(oblist[idx]);
		}
		message_vision("$N" NOR "皱了皱眉头，把酒宴撤去了。\n", me);
		CHANNEL_D->do_channel(this_object(), "rumor",
			   me->name() + "的幽会终于结束了。");
		return 1;
	}

	if (mesg)
		return notify_fail("这里已经被人包租了。\n");

	if (arg == "party")
	{
		mesg = "听说" + me->name() + "在杭州楼外楼与人幽会。";
		if (! me->can_afford(20000))
			return notify_fail("你没有足够的钱或零钱不够。\n");;

		me->pay_money(20000);
		create_water(CYN "龙井茶" NOR, ({ "tea" }), MAG "紫砂茶盅" NOR);
		create_water(HIG "碧螺春" NOR, ({ "tea" }), MAG "紫砂盏" NOR);
		create_wine(HIY "绍兴黄酒" NOR, ({ "wine" }), HIW "象牙杯"NOR);
		create_wine(GRN "竹叶青" NOR, ({ "wine" }), HIG "翡翠杯"NOR);
		create_wine(RED "女儿红" NOR, ({ "wine" }), MAG "紫檀杯"NOR);
		create_food(RED "东坡肉" NOR, ({ "pork" }));
		create_food(HIB "西湖醋鱼" NOR, ({ "fish" }));
		create_food(HIR "龙井虾仁" NOR, ({ "shrimp" }));
		create_food(YEL "叫化童鸡" NOR, ({ "chicken" }));
		create_food(HIR "桂花鲜栗羹" NOR, ({ "guihua geng" }));
		create_food(HIY "百果油包" NOR, ({ "baozi" }));

		message_vision("$N" NOR "微微一笑，摆出了一席酒宴。\n", me);
		CHANNEL_D->do_channel(this_object(), "rumor", mesg);
		set("order_owner", me->query("id"));
		set("order_type", arg);
		return 1;
	}
	else
		return notify_fail("这儿只承办幽会小宴。\n");
}

int do_close(string arg)
{
	object me = this_player();
	object room;

	if (arg != "door")
		return notify_fail("你要干什么？\n");

	if (! query("exits/down"))
		return notify_fail("门不是关着的么？\n");

	me->set_temp("plugin", 1);

	room = get_object(query("exits/down"));
	message_vision("$N嘿嘿傻笑两声，悄悄把门给关上了。\n", me);
	tell_room(room, "只听上面格拉一声，把门从里面反锁了。\n");

	delete("exits/down");
	room->delete("exits/up");
	return 1;
}

int do_open(string arg)
{
	object me = this_player();
	object room;

	if (arg != "door")
		return notify_fail("你要干什么？\n");

	if (query("exits/down"))
		return notify_fail("门不是开着的么？\n");
	
	set("exits/down", __DIR__ "jiulou");
	room = get_object(query("exits/down"));
	room->set("exits/up", __FILE__);

	message_vision("$N叹了口气，轻轻把门给打开了。\n", me);
	tell_room(room, "只听上面又是格拉一声，门开了。\n");

	me->delete_temp("plugin", 1);
	return 1;
}

int valid_leave(object me, string dir)
{
	if (me->query("id") != query("order_owner"))
		return 1;

	return notify_fail("请先用 order end 结束后再走。\n");
}


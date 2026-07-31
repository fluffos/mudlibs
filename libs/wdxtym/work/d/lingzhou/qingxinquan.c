// Room: /lingzhou/qingxinquan.c

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "清新泉");
	set("long", @LONG
这是山中的一口清泉，位于林场北面的山坡上，周围是翠绿的松树，
潺潺的山泉水从泉眼缓缓的涌出，聚成一个小潭，小潭水又溢出流向山
下，旁边一条小路通向山下。
LONG );
	set("exits", ([
		"south" : __DIR__"kongdi",
		"north" : __DIR__"wangling",
	]));
	set("objects", ([
	]));
	set("action_list", ([
		"王陵争霸":"wlzb",
	]));
	set("resource/water", 1);
	set("no_clean_up", 0);
	set("outdoors", "lingzhou");
	setup();
}

void init()
{
	add_action("zhengba","wlzb");
}

int zhengba()
{
	string banghui;
	object wushi,room,me = this_player();

	if(!mapp(me->query("banghui")))
		return notify_fail("你人单势孤，请先加入一个帮会再来吧！\n");
	if(me->query("last_wlzb")/86400==time()/86400)
		return notify_fail("你今天已经参加过王陵争霸赛了！\n");

	banghui = me->query("banghui/name");

	if(WARS_D->query_data("wangling/"+banghui+"/users/"+me->query("id")))
		return notify_fail("你今天已经代表帮会参加过王陵争霸了，明天再来吧！\n");

	WARS_D->set_data("wangling/"+banghui+"/users/"+me->query("id"),1);
	WARS_D->set_data("wangling/"+banghui+"/pot",WARS_D->query_data("wangling/"+banghui+"/pot")+1);

	room = new(__DIR__"wlroad");
	wushi = new(__DIR__"npc/shiwushi");
	wushi->move(room);
	room->set("start_time",time());
	me->move(room);
	wushi->kill_ob(me);
	me->kill_ob(wushi);
	me->set("last_wlzb",time());
	tell_object(me,"你进入了西夏王陵内的通道，眼前一个石人守卫拦住了你的去路，为了帮会的荣誉尝试全力击败他吧，为帮会荣誉而战，死亡不会受到惩罚。\n");
	room->set_heart_beat(1);

	return 1;
}

int valid_leave(object me, string dir)
{
	if(dir=="north")
	{
		tell_object(me,"西夏王陵争霸战暂未开放！");
		return 0;
	}
	return ::valid_leave(me, dir);
}

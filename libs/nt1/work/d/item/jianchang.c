// jianchang.c 剑场，干将莫邪在此炼制各种道具
// Written by Doing Lu 1998/11/3

#include <ansi.h>
inherit ROOM;


void create()
{
	set("short", HIR "剑场" NOR);
	set("long",
"这里是干将莫邪练剑的地方，当然了，除了剑也炼制其它道具。屋子\n"
"里有一个烧得通红的火炉，闪动着鲜艳的火苗，火炉边坐着一位赤着上身\n"
"的大汉，盯着火炉不言不语，门口则站着一位清雅的女子，似乎很年轻，\n"
"她看见你进来，对你微微一笑。墙上挂着一个牌子(paizi)。四周通向一\n"
"些小屋子。\n"
);

	set("no_fight", 1);
        set("no_sleep_room",1);

	set("item_desc", ([
		"paizi" : "精制各种武器装备，有意者请面谈。\n",
	]));

/*
        set("objects", ([
                "/adm/npc/moye" : 1,
                "/adm/npc/ganjiang" : 1,
	]));
*/

	set("exits", ([
                "south" : "/d/room/playtown/guandao4",
		"west"      : __DIR__"lianjianshi",	// 炼剑室
		"east"      : __DIR__"armorroom",	// 炼甲室
		"north"     : __DIR__"lianbianshi",	// 炼鞭室
		"southeast" : __DIR__"lianchuishi",	// 炼锤室
		"southwest" : __DIR__"lianzhangshi",	// 炼杖室
		"northeast" : __DIR__"liangunshi",	// 炼棍室
		"northwest" : __DIR__"liandaoshi",	// 炼刀室
	]));

	setup();
        "/adm/npc/moye.c"->come_here();
        "/adm/npc/ganjiang.c"->come_here();
}

int valid_leave(object me, string dir)
{
	object ob;
	object moye;
	// 清除询问过莫邪的标志
	this_player()->delete_temp("query_moye");

	if (! objectp(moye = present("moye", environment(me))))
	{
		return ::valid_leave(me, dir);
	}
	if ((int) me->query_temp("item/交付粗坯") == 1 &&
	    moye->query_temp("item/交付人ID") == me->query("id"))
	{
		message_vision("莫邪一把把$N抓住，说道：你干什么，慌慌张张的，东西都不要了？\n", me);
		if (objectp(ob = present(moye->query_temp("item/粗坯"), moye)))
		{
			// 交还粗坯
			ob->move(me);
			message_vision("莫邪把粗坯交还给$N。\n", me);
		}
		moye->delete_temp("item");
		me->delete_temp("item");
	} else
	if (objectp(present("item permit", me)))
	{
		message_vision("莫邪对$N笑道：把信件收好了，快点回来哦。\n", me);
		
	} else
	if (me->query_temp("item"))
	{
		message_vision("莫邪对$N喊道：不要到处乱走，要是你不回来，道具弄丢了我们可不负责啊。\n", me);
	}

	return ::valid_leave(me, dir);
}

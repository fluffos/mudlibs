// jingxiushi.c 静修室
inherit ROOM;

void create()
{
	set("short", "静修室");
	set("long", @LONG
这里是全真教弟子静修参悟道情的房间，房间很小，但收拾的干
干净净，桌椅都摆放得整整齐齐，让人一看就心无杂念。
LONG
	);
	set("exits", ([
		"east" : __DIR__"houshan",
		"south" : __DIR__"diziju",
		"west" : __DIR__"houtang3",
	]));
	set("objects", ([
		CLASS_D("quanzhen") + "/liu" : 1,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	mapping fam;
	object ob;

	if (dir == "east" )
	{
		if (!(fam = me->query("family")) || fam["family_name"] != "全真教")
		{
			if((ob = present("liu chuxuan", environment(me))) && living(ob))
			{
				message_vision("$N伸手拦住$n道：“后面是本教祖师清修之地，" + RANK_D->query_respect(me) + "请止步。”\n", ob, me);
				return 0;
			}
		}
	}

	return ::valid_leave(me, dir);
}

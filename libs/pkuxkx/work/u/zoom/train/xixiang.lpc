//dongxiang.c
//by zoom
//2004.3.29

inherit ROOM;

void create()
{
    set("short", "西厢房");
    set("long", @LONG
这里是新手学堂的西厢房。几名青衣小僮走来走去，给宾客
奉上清茶和点心。
LONG
    );

    set("exits", ([
                "south" : __DIR__"xiceting",
                "east" : __DIR__"yuan2",
    ]));
    
	set("objects", ([
		__DIR__"npc/xiaotong" : 1,
		]));

        set("indoors", "train");

	set("food_count", 5);
	setup();
}

void init()
{
	add_action("do_serve", "serve");
}

int do_serve()
{	object xiaotong, curfood, newtea, newfood;
	object me = this_player(), room;
	int i, total, flag;

	room = environment(me);
	if( !objectp(xiaotong = present("xiao tong", room)) )
	 	return notify_fail("你四处张望，不知小僮都跑哪去了。\n");

	if (objectp(curfood = present("wan", room)))
	{	message_vision("小僮把剩茶端走，再端上一碗茶放在$N的桌上\n", me);
		destruct(curfood);
	}
	else
		message_vision("小僮端上一碗茶放在$N的桌上。\n", me);

	newtea = new("d/wudang/obj/dawancha");
	newtea->move(room);

	if (objectp(curfood = present("baozi", room)))
	{
		message_vision("小僮对$N笑了笑说道：先吃完再要吧。\n", me);
	}
	else
	{
		newfood = new("d/city/obj/baozi");
		newfood->move(room);
		message_vision("小僮端上一" + newfood->query("unit") + newfood->query("name") 
					+ "，放在$N的桌上。\n", me);
	}
	return 1;
}

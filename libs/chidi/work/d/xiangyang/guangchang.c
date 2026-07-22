// Room: /d/xiangyang/guangchang.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "中央广场");
	set("long", @LONG
这里是襄阳的中央广场，铺着青石地面。东面通向青龙门，
西面通向白虎门，南面直达朱雀门，远远地你可看到北面是襄
阳安抚使衙门。近年来蒙古大军屡次攻打襄阳，官府为防止蒙
古奸细混杂进来，已经不允许人们在此聚集。只见一队官兵在
此往来巡逻，你还是快离开吧。
LONG );
        set("outdoors", "xiangyang");
	set("item_desc", ([
		"dong" : "\n",
	]));

	set("exits", ([
		"east"  : __DIR__"eastjie1",
		"west"  : __DIR__"westjie1",
		"south" : __DIR__"southjie1",
		"north" : __DIR__"anfupailou",
        "up" : __DIR__"gongzuoshi",
	]));
	set("objects", ([
	//	__DIR__"npc/pian" : 1,
	//	__DIR__"npc/bing" : 1,
		]));
	setup();
	//replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	object tagob,thisob;

	thisob = this_object();

	if (wizardp(me))
		return 1;

	if (dir == "up")
	{
		if(!objectp( tagob = find_object( query("exits/"+dir) ) ))
		{
			tagob = load_object( query("exits/"+dir) );
		}

		if( sizeof(all_inventory(tagob)) > 25 )
		{
			return notify_fail("那边已经人满了！！\n");
		}
	}

	return ::valid_leave(me, dir);
}


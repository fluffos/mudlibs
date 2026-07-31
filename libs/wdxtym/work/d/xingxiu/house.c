// /d/xingxiu/house.c
// Jay 3/26/96

inherit ROOM;

void create()
{
	set("short", "巴依家院");
	set("long", @LONG
这是一个巴依家的庭院。门口大树的树荫投到院子里，让人觉得很凉快。
院子东面是巴依的客厅，西边就是小镇大街。
LONG
	);
	set("exits", ([ 
	    "west" : __DIR__"beijiang",
	    "east" : __DIR__"house1",
	]));
	set("objects", ([
		__DIR__"npc/kid": 1,
		__DIR__"npc/bayi": 1
	]) );
	set("outdoors", "xingxiu");

	setup();
}

int valid_leave(object me, string dir)
{
	object bayi;

	if (objectp(bayi = present("ba yi", this_object())) && 
	    dir == "east" &&
	    ! me->query_temp("permit_pass/bayi"))
	{
		
		message_vision("$N说：我把阿凡提关在我的客厅里了，谁"
			       "也不许进去。\n", bayi);
		return 0;
	}

	return ::valid_leave(me, dir);
}


// Room: /d/wiz/system.c

inherit ROOM;

void create()
{
	set("short", "系统公告室");
	set("long", @LONG

这是一间很普通的房间，房内贴着一些有关这个世界的资讯。

LONG
	);
	set("item_desc" , ([ 
		"east": "房子里云雾缭绕，什么也看不清楚。\n",
	]));
	set("exits", ([ 
  		"east" : "/d/wiz/wizroom",
  		"west" : "/d/city/entrance",
	]));
	set("no_clean_up", 0);
  	set("no_time",1);
	set("no_fight", 1);
	set("no_magic", 1);
	set("post_limit", 1);
	setup();
	call_other("/obj/board/system_b", "???");
}

int valid_leave(object me, string dir)
{
		if( dir=="east" && !wizardp(me) )
			return notify_fail("那里只有巫师才能进去。\n");
		return ::valid_leave(me, dir);
}
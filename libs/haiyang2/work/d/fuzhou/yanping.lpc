// Room: /d/fuzhou/yanping.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "黄岩县");
	set("long", @LONG
黄岩县在武夷山边,占溪山之雄,当水陆之会，向为入闽之咽
喉。周遭山势壁立，深湍饶郭，易守难攻，为省城屏障，故关防
严密不轻怠。
LONG );
	set("exits", ([
		"northup"   : __DIR__"fzroad3",
		"southeast" : __DIR__"fzroad8",
		"southwest" : __DIR__"fzroad4",
	]));
        set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing"    : 2,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}


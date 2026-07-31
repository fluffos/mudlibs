// Room: /u/star/cun8.c
// star 1998/12/04 亮晶晶版权所有，请勿随意修改传播


inherit ROOM;

void create()
{
	set("short", "村东口");
	set("long", @LONG
这里是小村的东头。因为暴雨刚过，地上一片泥泞，路非常不好走。顺
着这条路一直向东走一两个时辰就可到武夷山了。
LONG
	);
        set("outdoors", "wudujiao");
        set("no_npc",1);
	set("exits", ([
		"northwest" : __DIR__"cun7",
//		"northeast" : __DIR__"cun7",
//		"southwest" : __DIR__"cun6",
		"east" : "/d/wuyi/path5",
	]));
        set("objects", ([
//                "/d/npc/guojing": 1,
	]));
    

	setup();
	replace_program(ROOM);
}


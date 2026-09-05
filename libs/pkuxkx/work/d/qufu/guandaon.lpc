// Room: /d/suzhou/road1.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
你走在一条青石大道上，人来人往非常繁忙，不时地有人
骑着马匆匆而过。南面是孔子的故里曲阜，东北通向泰山，西
北面不远就是黄河渡口了。
LONG );
	set("outdoors", "zhongyuan");
	set("no_clean_up", 0);
	set("exits", ([
		"south"     : __DIR__"northgate",
		"northwest" : __DIR__"guandaonw1",
        "northeast" : "/d/taishan/yidao",
	]));
	setup();
	
}


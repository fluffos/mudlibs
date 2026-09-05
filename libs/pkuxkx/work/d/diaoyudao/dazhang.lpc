// Room: /d/diaoyudao/dazhang.c 大帐
// hongdou 98.09.20

inherit ROOM;

void create()
{
	set("short", "大帐");
	set("long", @LONG
你走进大帐，居中是一张帅椅及案桌，旁边两侧也摆放着几张椅子，
帐中整洁明亮，显然曾经有人打扫过。左边传来叽里咕噜的东洋话，右边
飘来一阵香气，使你垂涎欲滴，看来有人在那里做饭。
LONG
	);
	
	set("exits", ([
		 "out" : __DIR__"zhangqian",
                 "west" : __DIR__"zuozhang",
		 "east": __DIR__"youzhang",
         "north" : __DIR__"neizhang",
	]));

//	set("outdoors", "diaoyudao");
	setup();
	replace_program(ROOM);
}


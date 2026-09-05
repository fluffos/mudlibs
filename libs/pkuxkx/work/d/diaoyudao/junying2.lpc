// Room: /d/diaoyudao/junying2.c 军营
// hongdou 98.09.20

inherit ROOM;

void create()
{
	set("short", "军营");
	set("long", @LONG
你的胆子越来越大，感觉到这只是一座空营。想是大军早已撤走，否则
怎么能容忍倭寇侵占此岛，在此耀武扬威呢。前方不远有一座大帐，里面也
许能找到一些值钱的东西。
LONG
	);

	set("exits", ([
                 "east" : __DIR__"zhang4",
                 "west" : __DIR__"zhang3",
                  "north" : __DIR__"zhangqian",
                   "south" : __DIR__"junying1",
	]));

	set("outdoors", "diaoyudao");
	setup();
	replace_program(ROOM);
}


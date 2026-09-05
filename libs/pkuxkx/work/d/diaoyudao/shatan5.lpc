// Room: /d/diaoyudao/shatan4.c 沙滩
// hongdou 98.09.20

inherit ROOM;

void create()
{
	set("short", "沙滩");
	set("long", @LONG
这里是南沙滩，再往东走已经没有什么意义了，你想绕岛走
一圈吗？还是回头吧！
LONG
	);
	
	set("exits", ([
         "northwest" : __DIR__"shatan4",
	]));
    set("objects",([
       __DIR__"npc/hainiao" : 1,
     ]));
	set("outdoors", "diaoyudao");
	setup();
	replace_program(ROOM);
}


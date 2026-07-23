// /d/zhuojun/beidajie2.c
// Room in 涿郡
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "南大街");
	set("long", @LONG
你走在青石铺成的道路上，道路足有两辆马车并行那么宽，这里是
长沙北大街中段这里人来人往，车水马龙，显示出一片生机勃勃，华的
景象，西面飘来一股花香，原来那是一个花店，东面是一家价格便宜的
小吃店。
LONG
	);
set("outdoors", "changsha");
set("exits", ([
		"north" :__DIR__"guangchang",
                "south"  :__DIR__"nandajie1",
                "west"  :__DIR__"huadian",
                 "east"  :__DIR__"xiaochidian",
	]));
set("objects",([
 __DIR__"npc/liumang":1,
 ]));
       setup();
	replace_program(ROOM);
}	

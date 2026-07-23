// /d/zhuojun/dongdajie3.c
// Room in 涿郡
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "东大街");
	set("long", @LONG
脚下由青石铺成的马路足有两辆马车并行那么宽，再西走就是长沙
城的中心广场了，北面是一家皮货行，南面是一家金楼。
LONG
	);
set("outdoors", "changsha");
set("exits", ([
		"north" :__DIR__"pihuohang",
                "south"  :__DIR__"jinlou",
                "east"  :__DIR__"dongdajie1",
                 "west"  :__DIR__"guangchang",
	]));
	set("objects",([
	__DIR__"npc/shusheng":1,
	]));
       setup();
	replace_program(ROOM);
}	

// /d/suiye/dongdajie1.c
// Room in 涿郡
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "东大街");
	set("long", @LONG
脚下由青石铺成的马路足有两辆马车并行那么宽，东面就是长沙的
东城门了，向西望去，可以看见位于中心广场的钟楼，北面是一家乐器
店，传来音乐声，南面是一家杂货店。
LONG
	);
set("outdoors", "changsha");
set("exits", ([
		"north" :__DIR__"yueqidian",
                "south"  :__DIR__"zhahuopu",
                "west"  :__DIR__"dongdajie2",
                 "east"  :__DIR__"dongmen",
	]));
       setup();
	replace_program(ROOM);
}	

// /d/zhuojun/xidajie2.c
// Room in 涿郡
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "西大街");
	set("long", @LONG
脚下由青石铺成的马路足有两辆马车并行那么宽，这是西大街的中
段，北面传来了讨价还价之声，进出的人有喜有忧，南面是一家茶馆，
是人们闲聊的好地方。
LONG
	);
set("outdoors", "changsha");
set("exits", ([
		"north" :__DIR__"dangpu",
                "south"  :__DIR__"chaguan",
                "west"  :__DIR__"xidajie1",
                 "east"  :__DIR__"beidajie2",
	]));
       setup();
	replace_program(ROOM);
}	

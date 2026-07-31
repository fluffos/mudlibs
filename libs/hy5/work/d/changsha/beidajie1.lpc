// /d/zhuojun/beidajie1.c
// Room in 涿郡
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "北大街");
	set("long", @LONG
脚下由青石铺成的马路足有两辆马车并行那么宽，北面是长沙的北
城门，再向南走不远就是长沙的中心广场，东面传来叮叮铛铛的打铁声，
西面是一条小巷不知通向何处。
LONG
	);
set("outdoors", "changsha");
set("exits", ([
		"north" :__DIR__"beimen",
                "south"  :__DIR__"beidajie2",
                "west"  :__DIR__"tiejiangpu",
                 "east"  :__DIR__"xiaoxiang",
                
	]));
       setup();
	replace_program(ROOM);
}	

// /d/zhuojun/xidajie1.c
// Room in 涿郡
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "西大街");
	set("long", @LONG
脚下由青石铺成的马路足有两辆马车并行那么宽，西面就是长沙的
西城门，向东望去人来人往，车水马龙好不热闹。北面是旧隋朝的一个
驿站，南面是一家酒楼。
LONG
	);
set("outdoors", "changsha");
set("exits", ([
		"north" :__DIR__"yizhan",
                "south"  :__DIR__"tianwaitian",
                "west"  :__DIR__"ximen",
                 "east"  :__DIR__"xidajie2",
	]));
       setup();
	replace_program(ROOM);
}	

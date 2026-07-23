// /d/taiyuan/beidajie2.c
// Room in 太原
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "北大街");
	set("long", @LONG
北大街的人流已经减少了，南面是中心广场，人来人往，车水马龙，
东面就是太原行宫了，人们都是匆匆而过,不在这逗留。
LONG
	);
set("outdoors", "taiyuan");
set("exits", ([
                "north" : __DIR__"beidajie1", 
                "south" : __DIR__"center", 
                "east" : __DIR__"xinggong", 
	]));
       setup();
	replace_program(ROOM);
}	

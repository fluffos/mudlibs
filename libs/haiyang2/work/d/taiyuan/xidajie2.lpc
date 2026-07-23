// /d/taiyuan/xidajie2.c
// Room in 太原
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "西大街");
	set("long", @LONG
大街有两辆马车并行，那么宽身西隐隐约约能看见西城门，东面是
中心广场，北面是一家茶馆，南面是太原盐司的所在地了。
LONG
	);
set("outdoors", "taiyuan");
set("exits", ([
                "north" : __DIR__"chaguan", 
                "south" : __DIR__"yansi", 
                "west" : __DIR__"xidajie1", 
                "east" : __DIR__"center",       
	]));
       setup();
	replace_program(ROOM);
}	

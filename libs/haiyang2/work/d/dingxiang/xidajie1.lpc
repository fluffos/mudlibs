// /d/yazhang/xidajie1.c
// Room in 牙帐
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "西大街");
	set("long", @LONG
这里的路相当的宽，能容好几匹马车并行，长长的道路贯穿东西。
北面是杂货铺，南面是一家客栈。
LONG
	);
set("outdoors", "dingxiang");
set("exits", ([
                   "north" : __DIR__"zahuopu",  
                   "south" : __DIR__"yanfuge",  
                  "east" : __DIR__"xidajie2",  
                  "west" : __DIR__"ximen",    
	]));
	set("objects",([
	  __DIR__"npc/tuli":1,
	  ]));
       setup();
	replace_program(ROOM);
}	

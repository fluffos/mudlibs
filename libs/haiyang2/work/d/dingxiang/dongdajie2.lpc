// /d/yazhang/dongdajie2.c
// Room in 牙帐
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "东大街");
	set("long", @LONG
这里的路相当的宽，能容好几匹马车并行，长长的道路贯穿东西。
北面是一家花店。南边是牙帐的盐司，西是中心广场，往东可以看到东
城门。
LONG
	);
set("outdoors", "dingxiang");
set("exits", ([
                 "north" : __DIR__"huadian",  
                  "south" : __DIR__"yansi",  
                  "east" : __DIR__"dongdajie1",  
                  "west" : __DIR__"guangchang",    
	]));
	set("objects",([
	__DIR__"npc/ke":1,
	]));
       setup();
	replace_program(ROOM);
}	

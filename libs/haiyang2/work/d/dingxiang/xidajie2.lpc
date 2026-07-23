// /d/yazhang/xidajie2.c
// Room in 牙帐
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "西大街");
	set("long", @LONG
这里的路相当的宽，能容好几匹马车并行，长长的道路贯穿东西。
北面是国师府，南面是牙帐的当铺，里面全是讨还价的声音，你发现不
少武林人士出入这个当铺。
LONG
	);
set("outdoors", "dingxiang");
set("exits", ([
                   "north" : __DIR__"guoshifu",  
                   "south" : __DIR__"dangpu",  
                  "east" : __DIR__"guangchang",  
                  "west" : __DIR__"xidajie1",    
	]));
set("objects",(["/clone/npc/man":2,]));	

       setup();
	replace_program(ROOM);
}	

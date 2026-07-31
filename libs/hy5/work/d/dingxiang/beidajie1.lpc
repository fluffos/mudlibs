// /d/yazhang/nandajie1.c
// Room in 牙帐
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "北大街");
	set("long", @LONG
青石铺成的道路，平坦宽阔，从西面传来一股药味原来是一家老字
号的药铺，东面是牙帐唯一家大客栈，此地的客商大多在那里住宿。
LONG
	);
set("outdoors", "dingxiang");
set("exits", ([
                 "south" : __DIR__"beidajie2",  
                  "north" : __DIR__"huanggong",  
                  "east" : __DIR__"kezhan",  
                  "west" : __DIR__"yaopu",    
	]));
set("objects",([
"/clone/npc/man":1,
"/clone/misc/dache":1,	
	]));		
       setup();
	replace_program(ROOM);
}	

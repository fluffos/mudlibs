// Room: /city/bocai.c 
#include <room.h> 
inherit CREATE_CHAT_ROOM; 
	
int is_chat_room() { return 1; } 
	
void create() 
{ 
	set("short", "地下屋"); 
	set("long", @LONG 
这是一个秘密的地下屋 。
LONG 
	); 
	set("no_fight", 1); 
	set("no_sleep_room", 1); 

	set("exits", ([ 
		"up" : __DIR__"chaguan", 
	])); 
	setup(); 
} 

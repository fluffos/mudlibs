// Room: /city/bocai.c 
#include <room.h> 
inherit CREATE_CHAT_ROOM; 
	
int is_chat_room() { return 1; } 
	
void create() 
{ 
	set("short", "地下博彩屋"); 
	set("long", @LONG 
这是一个秘密的地下博彩屋，对当前的各种热门比赛都开设赔
率。欢迎各方人士来此一试运气。墙上挂着一个牌子(paizi)。 
LONG 
	); 
	set("no_fight", 1); 
	set("no_sleep_room", 1); 

	set("item_desc", ([ 
		"paizi" : "请注意(news)中当前各项比赛的赔率，然后于"
			  "当值巫师联系，由当值巫师收下钱后在留言版"
			  "上注明下注球队或者选手，以及下注金额。赔"
			  "金请联系当值巫师，查明后即发放。\n", 
	])); 
	set("exits", ([ 
		"up" : __DIR__"chaguan", 
	])); 
	setup(); 
} 

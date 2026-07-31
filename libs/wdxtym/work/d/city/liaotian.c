// liaotian.c

#include <ansi.h>
#include <localtime.h>
inherit ROOM;

int is_chat_room() { return 1; }

void create()
{
	set("short", "客店茶房");
	set("long", @LONG
这里是扬州客栈的茶楼，许多无所事事的人在这里聊天，店小二
穿梭在众多客人中间，忙个不停。旁边有一个小门，隐隐有一些花香
传进来，沁人心肺。
LONG );
	set("no_fight", 1);
	set("no_sleep_room", 1);
	set("exits", ([
		"south" : __DIR__"kedian",
		"west"   : __DIR__"xiaohuayuan",
		"east" : __DIR__"mingrt",
	]));
	set("objects", ([
	     __DIR__"npc/qi"     : 1,
	     "/adm/npc/bao"    : 1,
		
	]));
set("zhong",1);	
	setup();
}

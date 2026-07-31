//ROOM: d/suzhou/zhpu.c
// by dwolf
//97.11.4

#include <ansi.h>
inherit ROOM;    

string look_zhaopai();

void create()
{
	set("short", MAG"杂货铺"NOR);
	set("long", @LONG
	    这是一家小小的杂货铺，大箱小箱堆满了一地，都是一些日常用品。梁掌
柜懒洋洋地躺在一只躺椅上，招呼着过往行人。摊上立着一块招牌(zhaopai)。
LONG
	);
	set("no_sleep_room",0);
	set("outdoors","suzhou"); 
	set("exits", ([
		"north" : __DIR__"wroad4",
	]));
	set("objects", ([
		__DIR__"npc/lwliang" : 1,
]));                  
	set("item_desc", ([
		"zhaopai" : (: look_zhaopai :),
]));
	setup();
}      

string look_zhaopai()
{
	return "欢迎光临。本铺诚实买卖。";
}






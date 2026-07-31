// Room: /guiyun/duchuan.c
// Date: Nov.18 1998 by Winder

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "山坡");
	set("long", @LONG
小山坡上灌木丛生,偶有小动物,窜来窜去.
不知名的小花,缀生其中.
LONG );
set("exits", ([
	        //  "south" : __DIR__"aroad3",
	         // "north" : __DIR__"aroad4",	
          	"east" : __DIR__"aroad3",
	        //"west"  : __DIR__"road3",
	]));
set("objects", ([
		__DIR__"npc/baitu" : 3,
			]));
        set("outdoors", "binghuodao");
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

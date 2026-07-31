// Room: /guiyun/duchuan.c
// Date: Nov.18 1998 by Winder

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "小路");
	set("long", @LONG
一条草丛中,踏出的小路.沿着路走,地势渐高.
逐渐到了小山坡.坡上灌木丛生,偶有小动物,窜来窜去.
LONG );
set("exits", ([
	          "south" : __DIR__"aroad2",
	          "north" : __DIR__"aroad4",	
          	 "east" : __DIR__"aroad5",
"west"  : __DIR__"aroad6",
	]));

        set("outdoors", "binghuodao");
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

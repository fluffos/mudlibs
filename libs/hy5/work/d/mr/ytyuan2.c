// /u/beyond/mr/ytyuan.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIM"樱桃园"NOR);
         set("long",@long
这是一片樱桃园，树上开满了樱桃花。
long);
         set("exits",([
"north" : __FILE__,
"south" : __FILE__,
"west" : __FILE__,
"east" : __DIR__"ytyuan",
             "south" : __DIR__"huandong",
]));
	setup();
	replace_program(ROOM);
}

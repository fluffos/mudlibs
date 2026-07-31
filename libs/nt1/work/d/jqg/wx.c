// Room: /u/dubei/u/gumu/jqg/wx
// by dubei
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "浯溪");
	set("long", @LONG
突然一阵清香涌至，眼前无边无际的全是水仙花。原来地下
是浅浅的一片水塘，深不逾尺，种满了水仙。前面好象是一
片遍野的花丛，很难变清道路。一种迥异的香味在空气中弥
漫着。
LONG
	);

	set("exits", ([
                "east" : __DIR__"fyy",
                "enter" : __DIR__"hc1",
	]));

    set("outdoors", "襄阳");
	setup();
	replace_program(ROOM); 
}


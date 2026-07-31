// Room: /u/qingyun/jyzj/houyuan.c
// Written by qingyun
// Updated by jpei

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"后院"NOR);
	set("long", @LONG
这里是山庄的后院。此庄号称“红梅”，当有其根源。院子里就长着许多
梅树。每逢春天梅花盛开之时，到处一片火红，分外美丽，梅花飘香更是令人
心旷神怡。北边是“灵獒宫”。
LONG	);
	set("exits", ([
		"north" : __DIR__"lingaogong",
		"west" : __DIR__"dating",
	]));
	set("outdoors", "kunlun");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

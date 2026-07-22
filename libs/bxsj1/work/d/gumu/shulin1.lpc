// Room: /u/xdd/gumu/shulin1.c
// Modify By River 98/09
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIB"树林"NOR);
	set("long", @LONG
黑压压的一座大树林，一条小径绵延通幽。林中一片寂静，更无半点声息，
朦胧中见地下立着一块石碑(bei)。
LONG        );

	set("exits", ([
		"east" : __DIR__"sl1",
		"west" : __DIR__"lyy",
	]));    

	set("outdoors","古墓");

	set("item_desc", ([
		"bei" :HIR"\n\t\t※※※※※※※※※※※※※※※※※※※\n"+
			"\t\t※※※※　                    ※※※※\n"+
			"\t\t※※※※    古  墓  幽  居    ※※※※\n"+
			"\t\t※※※※                      ※※※※\n"+
			"\t\t※※※※※※※※※※※※※※※※※※※\n\n"NOR,
	]));
	setup();
}

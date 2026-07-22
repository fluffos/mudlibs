// Room: /d/yandang/luoyan1.c

inherit ROOM;

void create()
{
	set("short", "玉台径");
	set("long", @LONG
这是一块巨大的岩石,通体呈玛瑙色,十分罕见,据说这种玉石只产
雁荡此处,在岩石的四方,分别有四条宽约一米的小径通向四方,向东就
是雁湖,北面是江湖中有名的落雁山庄.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/yandang");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"shimeng",
  "north" : __DIR__"luoyan2",
]));

	setup();
	replace_program(ROOM);
}

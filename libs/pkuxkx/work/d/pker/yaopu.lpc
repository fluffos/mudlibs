
inherit ROOM;

void create()
{
	set("short", "药铺");
	set("long", @LONG
做杀手吃的是刀刃上的饭，平时大伤小创总是难免，故而这药铺就显的格外重要了.
门上贴着张纸(paper)
LONG
	);
	set("item_desc", ([
		"paper" : "医活不谢，医死不管\n"


	]));

       set("objects", ([
		__DIR__"npc/miaohuicun": 1,
		
	]));

	set("exits", ([
		"north" : __DIR__"dadao21",
	]));

	setup();
	replace_program(ROOM);
}


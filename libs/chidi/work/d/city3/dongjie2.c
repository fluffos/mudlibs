// Room: /chengdu/dongjie2.c
// oooc: 1998/06/20 

inherit ROOM;

void create()
{
        set("short", "东大街");
	set("long", @LONG
你刚走到这，就听到北边隐隐传来钟声，其中似乎还渗杂着
“咚咚”的木鱼之声。你顺着响声望去，但见眼前一座老高的寺
门，门匾上三个金光大字“昭觉寺”。你往南边看去，只见到一
条小街。
LONG
	);

	set("exits", ([
                "west" : __DIR__"dongjie1",
                "north" : __DIR__"shimiao",
                "east" : __DIR__"dongjie3",
                "south" : __DIR__"xiaojie",
	]));
        set("objects", ([
            __DIR__"npc/seng-ren" : 1,
        ]));


	setup();
	replace_program(ROOM);
}


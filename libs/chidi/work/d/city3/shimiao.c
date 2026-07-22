// Room: /chengdu/shimiao.c
// oooc: 1998/06/20 

inherit ROOM;

void create()
{
        set("short", "昭觉寺");
	set("long", @LONG
昭觉寺素有川西“第一禅林”之称，始建于唐贞观年。只见
寺内殿宇宏丽，庭院幽深，古木参天。正殿供奉着我佛如来，大
佛两旁有弟子菩萨，力士、天王、罗汉等，个个慈眉善目。
LONG
	);

	set("exits", ([
                "south" : __DIR__"dongjie2",
                "north" : __DIR__"shimiao2",
	]));
        set("objects", ([
             __DIR__"npc/zike" : 1,
             __DIR__"npc/xiaoheshang1" : 1,
        ]));


	setup();
}


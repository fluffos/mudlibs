//ROOM lianchuishi.c
inherit ROOM;

void create()
{
        set("short", "打锤坪");
        set("long",
	"这里是玄兵古洞的打造钢锤的地方。处在荒芜人烟的大雪山上。大雪山长年\n"
	"积雪，这里却是一坪长草扶地的山谷。四周摆了很多铜铁五金，一个腼腆少年手\n"
	"执大锤，看着你走近身来。\n"
        );
        set("exits", ([
                "eastdown" : "/d/xuedao/nroad5",
        ]));

	set("objects",([__DIR__"npc/shichui" :1,]));

        setup();
	replace_program(ROOM);
}

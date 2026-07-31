// yuanlin.c - 侠客园林
// 编程：中山大学  张三丰（Micro）----Micro_Liang@Hotmail.Com		1997.6

inherit ROOM;

void create()
{
        set("short", "侠客园林");
        set("long", @LONG

    这里是侠客城侠客园林。这是远离凡尘的另一个世界，景色优美，林
木葱绿，碧水环绕，鸟语花香，宛如仙境一般。来到这里，你就忘却了一
切江湖恩怨，许多大侠就常常隐居在这里，享受田园之乐。
LONG
	);

        set("outdoors", "center");

        set("exits", ([
                "north" : __DIR__"roadw2",
                "south" : "/d/yuanlin-shanzhuang/yl-xqls",
        ]));

        setup();

	replace_program(ROOM);
}

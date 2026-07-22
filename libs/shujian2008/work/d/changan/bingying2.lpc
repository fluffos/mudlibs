// Write By Yanyang@SJ 2001.9.28
// ROOM : /d/changan/bingying2.c

inherit ROOM;

void create()
{
        set("short", "兵营");
        set("long", @LONG
这里就是长安城的兵营了。这里密密麻麻到处都是官兵，有的在武将的指
挥下进行操练，有的独自在练功，还有的坐着、躺着正在休息。
LONG
        );

        set("exits", ([
                "north" : __DIR__"bingying",
        ]));

        set("objects", ([
        __DIR__"npc/bing" : 4,
        __DIR__"npc/wujiang" : 2,
        ]));

        set("incity",1);
	setup();
}

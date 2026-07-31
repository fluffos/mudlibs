// Room: /d/snow/tree.c
inherit ROOM;
void create()
{
        set("short", "榕树上");
        set("long", @LONG
你现在正在一株巨大的榕树上，茂密的枝叶搔得你有些发痒，
前面一根粗大的树枝上有人放著一块垫子。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                "down" : __DIR__"guangchang",
]));
        set("objects", ([
                __DIR__"npc/abao": 1
        ]) );
        setup();
        replace_program(ROOM);
}

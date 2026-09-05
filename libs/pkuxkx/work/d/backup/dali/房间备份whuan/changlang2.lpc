// changlang2.c

inherit ROOM;

void create()
{
    set("short", "长廊");
    set("long", @LONG
天龙寺后殿的长廊，这里相当的幽静。长廊边上有一些简陋的
木头椅子，上边还有一层薄薄的灰尘，显然很少有人来坐。
LONG
       );
    set("outdoors", "dali");

    set("exits", ([
                "west" : __DIR__"muwu",
                "south" : __DIR__"yuan",
                ]));
    set("objects", ([
                __DIR__"npc/bencan" : 1,

                __DIR__"npc/shami" : 2 ]) );
    set("no_clean_up", 0);
    setup();
    replace_program(ROOM);
}

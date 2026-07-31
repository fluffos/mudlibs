// This is a room made by wsl.
inherit ROOM;
void create()
{
    set("short", "长安城大街");
    set("long",@LONG
你走在长安城的大街上，这里的行人络绎不绝，大多是去西边土
地庙朝拜的善男信女。听说那里有个神算子，算命很准的，你也买把
香，进去扣个头，找神算子算上一卦如何。
LONG
);
        set("outdoors","changan");
    set("exits", ([
        "south" :__DIR__"ca7",
        "west" :__DIR__"ca10",
       "north":__DIR__"ca21",
        "east" :__DIR__"ca11",
]));
    setup();
    replace_program(ROOM);
}

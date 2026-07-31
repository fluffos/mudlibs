
// This is a room made by wsl.
inherit ROOM;
void create()
{
    set("short", "长安城大街");
    set("long", @LONG
你走在长安城的大街上，行人南来北往。西边是长安城里最出名
的药铺，东面
LONG
);
        set("outdoors","changan");
    set("exits", ([
       "south" :__DIR__"ca13",
       "west" :__DIR__"ca14",
       "east" :__DIR__"ca15",
       "north" :__DIR__"ca",
]));
    setup();
    replace_program(ROOM);
}

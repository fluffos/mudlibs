// This is a room made by Wsl.
inherit ROOM;
void create()
{
        set("short", "长安城大街");
        set("long", @LONG
过往商客络绎不绝人山人海，到处都是一片繁华的景象，北边竖
着一个找大的“酒”字招牌，那里就是就是长安城最有名的万福就楼
。往南是一条小巷，不知可以去到那里。
LONG
);
        set("outdoors","changan");
        set("exits", ([
       "east":__DIR__"ca",
       "west":__DIR__"ximen",
       "south":__DIR__"ca23",
      "north" :__DIR__"ca2",
]));

        setup();
        replace_program(ROOM);
}


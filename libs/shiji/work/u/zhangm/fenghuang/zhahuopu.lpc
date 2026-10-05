inherit ROOM;
void create()
{
        set("short", "杂货铺");
        set("long", @LONG
这是一间杂货铺，卖一些日常用品。
是星系中常见的店铺。老板是一个很和善的人。
左边墙上有一个招牌(zhaopai)。
LONG );
        set("item_desc", ([
                "zhaopai": "请用 \"list\" 列出货物表，\"buy\" 向老板购物。\n",
        ]));
        set("objects", ([
                __DIR__"npc/jiaxin" : 1,
        ]));
//      set("no_clean_up", 0);
        set("exits", ([
            "north" : __DIR__"shangjie1",
        ]));

        setup();
        replace_program(ROOM);
}



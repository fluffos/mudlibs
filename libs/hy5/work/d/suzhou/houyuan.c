inherit ROOM;

void create()
{
        set("short", "后院");
        set("long", @LONG
这里是翰林府的后院。院子里种了不少的各种奇花异草，尤以
各色菊花为多。北面有一扇门(men)。
LONG
        );
        set("item_desc", ([
                "men" : "这扇门后便是凌小姐的闺房。\n",
        ]));

        set("exits", ([
                "north" : __DIR__"dongxiang",
                "south" : __DIR__"dayuan1",
        ]));
        set("objects", ([
                __DIR__"npc/lintuisi" : 1,
        ]));

        set("cost", 0);
        setup();
}

void init()
{
        add_action("do_kai", "kai");
        if (present("ling tuisi", environment(this_player())))
                delete("exits/north");
}
int do_kai(string arg)
{
        object ob;
        if (query("exits/north"))
                return notify_fail("这扇门已经是打开的。\n");
        if (!arg || (arg != "men" && arg != "north"))
                return notify_fail("你要打开什么？\n");
        if (!(ob = present("tong yaoshi", this_player())))
                return notify_fail("你用钥匙在门里转了几下,无奈怎么也打不开。\n");
        set("exits/north", __DIR__"dongxiang");
        message_vision("$N那起铜钥匙打开房门，可是钥匙却断了。\n", this_player());
        destruct(ob);
        return 1;
}

int valid_leave(object me, string dir)
{
        if (!wizardp(me) && objectp(present("ling tuizi", environment(me))) && 
                (dir == "north"))
                return notify_fail("凌退之挡住了你：你想入内宅干什么? \n");
        return ::valid_leave(me, dir);
}


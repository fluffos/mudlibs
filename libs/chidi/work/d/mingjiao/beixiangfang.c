inherit ROOM;

void create()
{
        set("short", "北厢房");
        set("long", @LONG
一个小小的厢房，但是布置的十分雅致，到处都是女孩子的物品，
看起来是一个15、6岁的女孩子住的卧室。墙上挂着一副画(picture).
LONG
        );

        set("exits", ([
                "south" : __DIR__"houyuan",
        ]));

        set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/yangbuhui" : 1,
]));
        set("item_desc", ([
                "picture" : "一张普通的不能再普通的风景画。\n",
        ]));
        setup();
}

void init()
{
        add_action("do_pull", "pull");
}


int do_pull(string arg)
{
        object me;

        me = this_player();

        if ( !arg || ( arg != "picture" ) )
       return notify_fail("什么？\n");
    if(this_player()->query_temp("qkdny/admmited")!=1)
        return notify_fail("大胆！没有教主的许可，竟敢私入明教重地？\n");

       message_vision("$N轻轻的拉了一下画的底轴，只听见机关轰隆一响，出现了一个洞口。\n", me);
         { me->move(__DIR__"ymdrk");
         }

      return 1;
}


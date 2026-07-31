inherit ROOM;
int do_climb(string arg);
void create()
{
        set("short", "内堂");
        set("long", @LONG
这是一间不大的房间，房间里摆着一排排的书架(shu jia)
和很多书(book)，在书架的两旁靠着几具死人的骸骨，有一具
的胸骨之中还插着一柄剑。。
LONG
);
        set("exits", ([ 
   "north" : __DIR__"qipo",
  "south" : __DIR__"zoulang2",
]));
        set("item_desc", ([
        "shu jia" : "书架上摆着各种各样的书。。\n",
        ]));
        setup();
}
void init()
{
        add_action("do_climb", "climb");
}
int do_climb(string arg)
{
    object me;
    me = this_player();
    if( !arg || arg!="shu jia") return notify_fail("你要爬什么？\n");
            message("vision", me->name() + "纵身跃上了书架顶端。。\n",
                    environment(me), ({me}) );
        me->move(__DIR__"dingduan");
            message_vision("$N从下面跃了上来。。\n", me);
        return 1;
}

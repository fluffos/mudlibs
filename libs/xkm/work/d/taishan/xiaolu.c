inherit ROOM;

void create()
{
        set("short", "小路");
        set("long", @LONG
小路蜿蜒向前延伸，不知道有多远,就近处有个的小潭，发出震耳欲聋的响声。
小潭旁有一棵古老的大树(tree),你看了一眼感觉有些古怪。
LONG );

      set("exits", ([
                     "west" : __DIR__"yidao1",
      ]));

        set("item_desc",([
            "tree" : "这是一株百年老松，树上有一些你从来没见过的果子。
可惜太高你拿不着。\n",
        ]));
        set("objects", ([ 
            "/d/xingxiu/npc/jumang" : 2,
      ]));

        set("cost", 2);
        setup();
}
void init()
{
        add_action("do_climb", "climb");
}
int do_climb(string arg)
{       object me = this_player();

        if ( (!arg ) || (arg != "tree") )
                return notify_fail("你要爬什么？\n");

        else
            me->move("/d/taishan/shushang");

        return 1;
}

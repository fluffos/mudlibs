// room: /d/xingxiu/cave1.c

inherit ROOM;

void create()
{
        set("short", "山洞");
        set("long", @LONG
黑黝黝的山洞里，有一股腥臭味。等眼睛适应了这里的弱光后，才发现
地上到处都是毒蛇，毒蛇旁有许多白惨惨的骨骇，令人胆寒。想必
都是探险之人，误入山洞，为毒蛇所害。
LONG
        );
        set("exits", ([
            "out" : __DIR__"shanshi",
        ]));

        set("objects", ([
               __DIR__"npc/snake" : 1,
               __DIR__"npc/snake" : 1,
        ]));

        set("no_task",1);
        setup();
}

void init()
{
        add_action("do_use", "use");
        add_action("do_use", "usefire");
        add_action("do_zuan", "zuan");
}

int do_use(string arg)
{
    object me = this_player();

    if( !arg || arg=="" ) return 0;
    if (!present("fire", me))  return 0;
    if(arg=="fire") {
      write("你点燃了火折，发现西面石壁上有一道裂缝，似乎可以钻(zuan)出去。\n");
      this_player()->set_temp("marks/钻", 1);
      this_player()->start_busy(2);
      return 1;
      }
}

int do_zuan(string arg)
{
    object me = this_player();

    if(me->query_temp("marks/钻") ) {
      message("vision", me->name() + "滋溜一下不知从什么地方钻出去了。\n", environment(me), ({me}) );
      me->move(__DIR__"cave2");
      message("vision", me->name() + "从石缝里钻了进来。\n", environment(me), ({me}) );
      this_player()->set_temp("marks/钻", 0);
      return 1;
      }
    else {
      write("你想往哪儿钻?!\n");
      return 1;
      }
}


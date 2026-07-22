// Room: /u/swl/songshan/dtlxia.c

inherit ROOM;

void create()
{
        set("short", "大铁梁峡");
        set("long", @LONG
这里的道路十分限险，向道路之右望去，铁梁峡之右尽是怪石，道
路左侧却是万仞深壑，渺不见底。不禁让人胆颤心惊。
LONG);
        set("exits", ([
            "southdown" : __DIR__"qgping",
            "northup" : __DIR__"xtlxia",
        ]));
        set("objects", ([ 
            CLASS_D("songshan") + "/le" : 1,
            __DIR__"npc/ssdizi" : 1,
        ]));
        set("jingli_cost/northup", 10);
        set("outdoors", "嵩山");
        set("coor/x",50);
  set("coor/y",200);
   set("coor/z",90);
   setup();
}

void init()
{
        object me = this_player();
        
        if (me->query_temp("ss/zsb_4")
         || me->query_temp("ss/hb_1"))
        {
                add_action("do_tie",({"ji","tie"}));
                add_action("do_down","pa");
                add_action("do_down","climb");
        }
}

int do_tie(string arg)
{
        object me = this_player();
        object ob;
        
        if (!arg || arg != "sheng")
                return notify_fail("你要系什么？\n");
        if (!(ob = present("song sheng",me)))
                return notify_fail("连绳子都没有怎么系呀！！\n");

        if (me->query_temp("tie_sheng"))
        {
                message_vision("$N又将绳子在石头上面系了一个结。\n",me);
                if (random(3)>1)
                {
                        message_vision("结果一不小心，没系好，绳子脱落了，掉进了峡谷。\n",me);
                        destruct(ob);
                }
                return 1;
        }
        message_vision("$N将手中松绳结结实实的系在了石头一角上。\n",me);
        me->set_temp("tie_sheng",1);
        return 1;
}
int do_down(string arg)
{
        object me = this_player();
        
        if (!arg || arg != "down")
                return notify_fail("你要往哪里爬？\n");
        if (!present("song sheng",me))
                return notify_fail("你找死呀?这么高,怎么跳的下去，去找根绳子再下去吧！！\n");
        if (!me->query_temp("tie_sheng"))
                return notify_fail("不绑好绳子，你是找死呀！\n");

        message_vision("$N将手中松绳向谷下一撂，顺着绳子爬了下去。\n",me);
        me->delete_temp("tie_sheng");
        me->move(__DIR__"yanbi");
        return 1;
}
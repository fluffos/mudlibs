 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","半山一石洞");
  set("long",@LONG
一个一人半高,很深的洞穴。洞壁上布满了枯藤。洞口坐着一个
面如冠玉、满身白衣的年轻人，
LONG
  );
        set("coor/x",330);
        set("coor/y",2380);
        set("coor/z",5);
        set("objects", ([
                __DIR__"npc/yunzheng" : 1,
        ]) );  
        
        setup();
} 
void init()
{
        add_action("climbing", "climb");
} 
int climbing(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("你要爬什么？\n");
                return 1;
        }
        if( arg == "枯藤" || arg == "up" || arg == "vine")
        {
        me = this_player();
        message_vision("$N抓着突出的枯藤，慢慢的顺着谷壁爬了上去。\n", me);
        me->start_busy(2);
        call_out("fliping",2,me);
//        me->stop_busy();
        return 1;
        }
        else
        {
                write("你不可以爬"+arg+"\n");
                return 1;
        }
}
int fliping(object me)
{
        if( !me->is_ghost()) {
        me->move(__DIR__"pingfeng");
        message_vision("$N顺着枯藤爬了上来。\n", me);
        }
        return 1;
}     

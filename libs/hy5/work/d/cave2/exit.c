 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "洞口");
        set("long", @LONG
转过一块大石，眼前忽然一亮，水柱便如倾盆大雨般劈头盖脸地打下来，
这个岩洞口竟然是在一个大瀑布中。向下望去便是三叠泉，足有十多丈高，除
此之外，别无出路。
LONG
        );
        set("exits", ([ 
                "northdown" : __DIR__"exit3",
                        ]));
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
} 
void init()
{
        add_action("do_dive", "dive");
        add_action("do_climb", "climb");
} 
int do_dive(string arg)
{
        object room;
        object me;
        me = this_player();
        room = load_object("/d/eren/waterfall.c");
        message_vision("$N长长吸了口气，一闭眼，向瀑布下跳去。\n",me);
        tell_object(me,"你越坠越快．．．．你似乎听见了一声惨叫，不禁毛骨悚然。\n");
        me->move(room);
        return 1;
}  
int do_climb(string arg)
{
        object obj;
        object me, room;
        if(!arg || arg=="")
        {
                write("你要爬什么？\n");
                return 1;
        }
        if( arg == "山" || arg == "mountain" || arg == "down")
        {
                write("这个地方太险，大概爬不下去。\n");
                return 1;
        }
        else
        {
                write("你不可以爬"+arg+"\n");
                return 1;
        }
}       

 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "地狱谷底");
        set("long", @LONG
这地狱谷原来真是个山谷，而且是个离崖不到叁丈的山谷！谷地的樽、菇、苔、
草、藤、叶、树冒出的瘴气，聚集于顶上，形成了如同云雾一般的烟气，遮住了谷
底的虚实。更由于这瘴气含有毒性，寻常的飞鸟走兽沾着一点就会栽倒下去，附近
的居民都远远避开，使得这地狱谷有了最佳的天然保护障体。。
LONG
        );
        set("exits", ([ 
     //           "east":  __DIR__"diyugu",
        ]));
        set("objects", ([
                __DIR__"npc/xie":       1,
                __DIR__"npc/tianmei":   1,
        ]) );
        set("outdoors", "zangbei");
            set("coor/x",-1000);
        set("coor/y",2150);
        set("coor/z",30);
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
        if( arg == "valley" || arg == "up" || arg == "山谷")
        {
        me = this_player();
        if (me->query_temp("climbup")) {
                        write("你已经在爬了。\n");
                        return 1;
                        }
        message_vision("$N抓着突出的石角，慢慢的顺着谷壁爬了上去。\n", me);
        me->start_busy(5);
        call_out("fliping",2,me);
//      me->stop_busy();
        me->set_temp("climbup",1);
        return 1;
        }
        else
        {
                write("你不可以爬"+arg+"\n");
                return 1;
        }
}
void fliping(object me)
{
        object room;
        if( !me->is_ghost()) {
        room = find_object(__DIR__"cliff");
        if(!objectp(room)) room= load_object(__DIR__"hellvalley3.c");
        me->move(room);     
        message_vision("$N顺着谷壁爬了上来。\n", me);  
        }
        me->delete_temp("climbup");
        return;
}        

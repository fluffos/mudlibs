inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "直共寺");
        set("long", @LONG
直共寺为“藏地三宝”之一的帕木竹巴建造，寺内存有口含帕竹亲身牙齿的自
塑雕像一尊。该寺古木参天，环境幽雅，到处鸟语花香。成群结队的藏马鸡随处可
见，犹如家养。寺内终年香火不断，前来朝圣者络驿不绝。
LONG
        );
        set("exits", ([ 
                "south" : __DIR__"wild6",
                
        ]));
       /* set("item_desc", ([
                "tree": "直共寺古木参天，每棵都有上百年的历史。\n",
                "古木": "直共寺古木参天，每棵都有上百年的历史。\n",
                "pine": "这棵松树怕是在建寺的那年栽下的，盘曲的丫枝，扇形的簇叶，遮住了半个天空。\n",
                "松树": "这棵松树怕是在建寺的那年栽下的，盘曲的丫枝，扇形的簇叶，遮住了半个天空。\n",
        ]));*/
        
        set("objects", ([
                __DIR__"npc/chicken":   2,
                __DIR__"obj/statue5":   1,
                __DIR__"npc/monk5":     1,
        ]) );
        set("coor/x",-1080);
        set("coor/y",170);
        set("coor/z",0);
        setup(); 
} 
/*void init(){ 
        add_action("do_climb","climb");
} */
void reset()
{
        object statue,incense;
               
        ::reset();
        statue = present("statue", this_object());
        if (!present("incense",statue)) {
                incense=new(__DIR__"obj/incense");
                incense->move(statue);
        }
}  
/*int do_climb(string arg){ 
        object me,room;
        me=this_player();
        if (!arg || (arg!="pine" && arg!="松树")) 
                return 0;
        if (!me->query_temp("zangbei/马鸡上树")) 
                return notify_fail("无缘无故爬什么树？\n");
        room=find_object(__DIR__"pine1");
        if (!objectp(room)) room=load_object(__DIR__"pine1");
        message_vision("$N手脚并用，敏捷地爬上了松树。\n",me);
        tell_room(room, this_player()->name() + "从树下爬了上来。\n");
        this_player()->move(room);
}    
*/
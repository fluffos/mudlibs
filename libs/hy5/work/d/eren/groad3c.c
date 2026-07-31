inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "小径");
        set("long", @LONG
一条弯弯曲曲的小路，两旁有几棵很高大的杉树，银白色的树干上，能看到凸
起的象伤疤一样和凹下去的象眼睛一样的树节，枝叶茂盛，甚至垂到了附近的院子
中。几只松鼠“吱溜溜”地在树枝上蹿着，一晃就不见了。小路尽头是竹林。 
LONG
        );
        set("exits", ([ 
        "west" : __DIR__"groad3b",
        "east" : __DIR__"groad4",
        ]));
        set("objects", ([
                __DIR__"npc/boy1": 1,
        ]) );
        set("item_desc", ([
                "杉树": "很高大的杉树，枝叶茂盛，甚至垂到了附近的院子中。\n",
        ]) );
        set("outdoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}  
void init()
{
        add_action("do_climb", "climb");
        if( this_player() ) {
                tell_room(__DIR__"tree", this_player()->name() + "往树下走了过来。\n");
        }
} 
int do_climb(string arg)
{
        if( arg!="tree" && arg!="杉树") {
                tell_object(this_player(),"你要爬什么。\n");
                return 1;
        } 
        if (this_player()->query_skill("move",1)<50
                || this_player()->query_skill("dodge",1)<50)
                return notify_fail("你试了试，没可能爬上去。\n");
        
        message_vision("$N手脚并用，敏捷地爬上了路旁的杉树。\n",
                this_player()); 
        tell_room(__DIR__"tree", this_player()->name() + "从树下爬了上来。\n");
        this_player()->move(__DIR__"tree");
        return 1;
} 
int valid_leave(object me, string dir)
{
        tell_room(__DIR__"tree",
                "树下的" + me->name() + "往" + to_chinese(dir) + "离开了。\n");
        return 1;
}    

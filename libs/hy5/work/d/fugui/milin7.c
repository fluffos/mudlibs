#include <ansi.h>
inherit ROOM;
#include "milin.h" 
void create()
{
        set("short", HIR"密林"NOR); 
        set("long", @LONG
这是一片密林，周围树木参天而立，遮云蔽日，四周昏昏暗暗，间杂着一些说
不出名字的红色野花，但见落叶铺地，踩上去沙沙做响，你高一脚低一脚地向前摸
索，隐隐有些担心，别该是迷路了吧。
LONG); 
        set("type","forest");
        set("outdoors", "fugui");
        set("attribute","huo");
        set("exits",([
                "east":__DIR__"milin8",
                "south":__DIR__"milin12",
                "west":__DIR__"milin6",
                "north":__DIR__"milin2",
        ]) ); 
        set("coor/x",-610);
        set("coor/y",170);
        set("coor/z",0);
        setup();
} 
void init()
{
        add_action("do_leave","leave");
} 
int do_leave(string arg)
{
        object room;
        this_player()->add("milin_walk",1);
        if(random(this_player()->query("milin_walk"))>30) 
        {
                if(random(100)>99)
                {
                        room=find_object(__DIR__"tomb");
                        if(!room) room=load_object(__DIR__"tomb");
                        tell_object(environment(this_player()),"人影一闪，$N不见了。\n",this_player());
                   this_player()->move(room);
                        return 1;
                }
                else 
                {
                        room=find_object(__DIR__"shandao3");
                        if(!room) room=load_object(__DIR__"shandao3");
                        tell_object(environment(this_player()),"人影一闪，$N不见了。\n",this_player());
                        tell_object(room,"$N满面疑惑的从密林里走了出来，一脸白痴的样子。");
                        this_player()->move(room);
                        return 1;
                }
        }
        return 0;
} 

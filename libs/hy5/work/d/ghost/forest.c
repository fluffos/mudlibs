#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "原始丛林");
        set("long", @LONG
丛林中一片黑暗，黑暗中充满了各式各样的危险，每一种都可以
致命。若是在丛林中迷失了方向，饥渴就足以致命。
LONG
        );
        set("exits", ([
                "north" : __DIR__"forest2",
                "south" : __DIR__"forest1",
                "east" : __DIR__"forest5",
                "west" : __DIR__"forest6",
        ]));
        set("outdoors", "ghost");
        set("NONPC",1);
        set("coor/x",-1190);
        set("coor/y",-50);
        set("coor/z",-10);
        setup();
} 
void init(){
        object me;
        me = this_player();
        if(me->query("family/family_name")=="幽灵山庄" || me->query_temp("marks/know_ghost")){
                tell_object(me, HIG"眼前景色似乎有些熟悉，你依稀记得往南方的高处走有座山崖。\n\n"NOR);
                set("exits/southup",__DIR__"forest9");
        }
} 
int valid_leave(object obj, string dir){
        object room;
        if(dir == "southup" && (obj->query("family/family_name")=="幽灵山庄" ||
                        obj->query_temp("marks/know_ghost"))){
                message_vision("$N凝神仔细辨别方向，继续在丛林之中前行。\n", obj);
                tell_object(obj, HIG"\n眼前猛然一亮，一道山崖出现在眼前。\n"NOR);
                delete("exits/southup"); 
                room = find_object(__DIR__"forest9");
                if(!objectp(room)){
                   room = load_object(__DIR__"forest9");
                }
                obj->move(room);
                return notify_fail("");
        }
        else {delete("exits/southup"); }
        return 1;
} 
void reset()
{
        ::reset();
        if(query("exits/southup"))
                delete("exits/southup");
        set("exits", ([
                "north" : __DIR__"forest2",
                "south" : __DIR__"forest1",
                "east" : __DIR__"forest5",
                "west" : __DIR__"forest6",
        ]));
}     

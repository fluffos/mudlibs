 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "漆黑暗道");
        set("long", @LONG 
至此已是伸手不见五指，你什么也看不出来，只是隐隐约约觉得前面有粗重的呼吸声。 
LONG
        );
        set("exits", ([ 
                "south":        __DIR__"tunnel3",
        ]));
        set("no_fly",1);
        set("item_desc", ([
                
        ]));
        set("objects", ([
                __DIR__"npc/sunju":     1,
        ]) ); 
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}  
int valid_leave(object obj, string dir){
        if (userp(obj) && dir=="south") {
                obj->delete_temp("block_msg/all",1);
                tell_object(obj,HIG"你终于走出了那漆黑的尽头，可以依稀辨认出周围的情况。\n"NOR);
                return 1;
                }
        return 1;
} 

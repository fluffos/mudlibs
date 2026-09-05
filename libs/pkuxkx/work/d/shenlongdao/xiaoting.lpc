// xiaoting.c 
// kiden 06-08-26


#include <room.h>
inherit ROOM;   

void create()
{
        set("short", "小厅");
        set("long", @LONG
        打开一扇小门，你来到一个小厅，一些弟子在这里忙碌这。
        北边是练功房，南边是饭厅，西侧是休息室。
LONG
        );

        
        set("exits", ([
        
                "north" : __DIR__"liangongfang",
                "west" : __DIR__"xiuxishi",
                "south" : __DIR__"fanting",             
                "east" : __DIR__"lianwuchang",    
        ]));
        setup();
}                


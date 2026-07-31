#include <ansi.h>
#include <room.h> 
inherit ROOM; 
void create()
{
        set("short", "沙穴洞底");
        set("long", @LONG
这里是一个地下溶洞，四周黑黑的，隐约可以看见周围怪石密布，地上有一黑
洞，似有一条暗河从中流过，隐约可以听到水声。
LONG
        );
        set("exits", ([ 
//              "down" : __DIR__"sandriver1",
                "eastup" : __DIR__"dongd2",
        ])); 
        set("indoors", "quicksand"); 
        set("coor/x",-1100);
        set("coor/y",-10);
        set("coor/z",0);
        setup();
} 

#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "九曲桥"); 
        set("long", @long
九曲桥是是通往金阁的唯一过道，也是观赏荷花最佳之处。清晨可观
高河日出，在夏天可远眺山林楼阁、雨后彩虹，望西面则可观“接天莲叶
无穷碧，映日荷花别样红”的景色。
long); 
       // set("type","waterbody");
        set("exits",([
                //"west":__DIR__"shulin4",
                "north":__DIR__"yuan4",
                "south":__DIR__"zhubaoge",
        ]) );
       set("outdoors", "shanxi");
        
        set("coor/x",-500);
        set("coor/y",-350);
        set("coor/z",100);
        setup();
} 

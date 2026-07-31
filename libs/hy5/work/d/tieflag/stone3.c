 inherit ROOM;
#include <room.h>
void create()
{
        set("short", "秘道");
        set("long", @LONG
这里是个圆形石洞，四面满悬长缀之锦帐，珍贵之毛皮。洞中一桌一椅，俱是
青石雕刻而成，花色不同，各具匠心。鼻端飘着一阵淡淡的香气，令人心神俱醉。
锦帐下，石桌旁，低几前，竟站着十余个绝美的少女。她们有的身披轻纱，有的
穿着锦袍，有的正在谈笑，有的正在下棋，也有的正在梳妆，还有的正在作图。
LONG
        );
        set("exits",([
        
                "east" : __DIR__"stone2",
        
        ]) ); 
        set("objects",([
                __DIR__"obj/tieflag2" : 2,
                __DIR__"npc/o_girl" : 1,
                __DIR__"npc/b_girl" : 1,
                __DIR__"npc/r_girl" : 1,
        ]) );   
        create_door("east","月牙石门","west",DOOR_CLOSED); 
        set("coor/x",2080);
        set("coor/y",-220);
        set("coor/z",-20);
        setup();
} 

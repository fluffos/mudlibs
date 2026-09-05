//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "南大街");
        set("long", @LONG
这里位于洛阳城里的南面，是洛阳最繁华地段，青石板铺成的街
面，宽阔而整洁，一到晚上，一派灯红酒绿，尤为热闹。笑声、歌声、琴
声、箫声，汇成一片送入了你的耳朵，你不禁心猿意马，很想就此停步享
受一番。东边是洛阳城赫赫有名的壶记茶楼。西边则是一家老字号的药店
-同仁堂。
LONG
        );
        set("item_desc", ([
        ]) );

        set("exits", ([
               "north" : __DIR__"nandajie1",
               "south" : __DIR__"nandajie3",  
               "west" : __DIR__"tongrentang",  
               "east" : __DIR__"chalou",               
        ]));
        set("objects", ([
//                __DIR__"npc/chanpuhuoji" : 4,
        ]));

        set("outdoors", "luoyang");
        setup();
        replace_program(ROOM);
}


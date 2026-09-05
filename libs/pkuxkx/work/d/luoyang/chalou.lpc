//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"壶记茶楼"NOR);
        set("long", @LONG
你一走进来，就闻到一股茶香沁入心脾，精神为之一爽。几张八仙桌
一字排开，坐满了客人，或高声谈笑，或交头接耳。你要想打听江湖掌故
和谣言，这里是个好所在。
LONG
        );
        set("item_desc", ([
        ]) );

        set("exits", ([
               "west" : __DIR__"nandajie2",             
        ]));
        set("objects", ([
                __DIR__"npc/chaguanhuoji" : 1,
        ]));

//        set("outdoors", "luoyang");
        setup();
        replace_program(ROOM);
}


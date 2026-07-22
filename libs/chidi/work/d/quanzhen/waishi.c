// waishi.c 外室 

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "外室");
        set("long", @LONG
这里的地上整整齐齐的排放着数十个黄布蒲团，南首有一个
红木讲坛，讲坛上放的墙上挂着一幅道士像。东西边各放着一对
美轮美奂的大花瓶，上插檀香数枝，香烟缭绕，氤氲芬芳，室内
一片祥和之气。看来这里是掌教对门下讲经说法的地方。
LONG
        );
        

        set("exits", ([
                "west" : __DIR__"zhongtang",
                "north" : __DIR__"neiyuan",
        ]));
/*
        set("objects", ([
                __DIR__"npc/mayu" : 1, 
   ]));
*/
 
        setup();
        replace_program(ROOM);
}



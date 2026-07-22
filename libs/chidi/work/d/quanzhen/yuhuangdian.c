// yuhuangdian.c 玉皇殿

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "玉皇殿");
        set("long", @LONG
这里是玉皇殿，殿中供奉着帝王模样的玉皇大帝，他是中国民间信
仰中的最高神，总领神仙世界。往北是三清殿。殿中放了红木大香案，
香案上供品齐备，香火十分旺盛。
LONG
        );
       

        set("exits", ([
                "north" : __DIR__"sanqingdian",
                "south" : __DIR__"guangchang",
        ]));
        set("objects", ([
                __DIR__"npc/lizhichang" : 1, 
   ]));

        setup();
        replace_program(ROOM);
}



// /dali/shufang.c 书房
// bbb 1997/06/11
// Modify By River 98/12 
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "书房");
        set("long", @LONG
这是书房，整个房间弥漫着浓浓的墨香。整个房间全部都是书，其中不少
是武林密芨。段王爷每天都要在此处理朝廷要事，闲暇时吟诗诵词，家人卫士
等，不经许可，决不敢贸然闯进。
LONG
        );

        set("exits", ([
                "west" : __DIR__"lang5",
        ]));
        set("objects", ([
                __DIR__"obj/tl01" : 1,
        ]) );
        set("coor/x",-300);
  set("coor/y",-460);
   set("coor/z",-20);
   setup();

}

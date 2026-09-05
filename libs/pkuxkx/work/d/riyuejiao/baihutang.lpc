//baihutang.c   白虎堂
//by bing

#include <room.h>
inherit ROOM;

void create()
{
        set("short","白虎堂");
        set("long",@LONG 
这是日月神教所属的白虎堂。堂中摆着几张太师椅，供桌
上供着历代日月神教教主和白虎堂堂主的牌位。白虎堂是日月
神教的大堂，地位仅在青龙堂之下。
LONG
        );

        set("exits", ([
                "west" : __DIR__"cunlu3",
                "north" : __DIR__"neiting",
                "east" : __DIR__"shuyuan",
        ]));
          set("objects", ([
               CLASS_D("riyuejiao") + "/shangguan" : 1,
                __DIR__"npc/jiaozhong3" : 4,
                ]));

        setup();

}







